/*+−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
|
|	UNIFAL − Universidade Federal de Alfenas.
|	  BACHARELADO EM CIENCIA DA COMPUTACAO.
| Trabalho: PARTE 1 − Construcao Arvore Sintatica
| Disciplina: Compiladores I
| Professor: Luiz Eduardo da Silva
| Aluno: Gustavo Alves Miguel
| Data: 04/02/2018
+−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

/*----------------------------------------------------------------
 *					Limites das estruturas
 *--------------------------------------------------------------*/
#define TAM_TSIMB 100 /* Tamanho da tabela de simbolos */
#define TAM_PSEMA 100 /* Tamanho da pilha semantica	*/

#define TRUE 1
#define FALSE 0

/*----------------------------------------------------------------
 *						Variaveis globais
 *--------------------------------------------------------------*/
int TOPO_TSIMB = 0; /* Topo da tabela de simbolos */
int TOPO_PSEMA = 0; /* Topo da pilha semantica */
int ROTULO = 0; /* Proximo numero de rotulo	*/
int CONTA_VARS = 0; /* Numero de variaveis	globais	*/
int POS_SIMB; /* Posicao na tabela de simbolos	*/
int aux; /* Variavel auxiliar */
int numLinha = 1; /* Numero da linha no programa */
char atomo[30]; /* Nome de um identificador ou numero */


/*----------------------------------------------------------------
 *				Variaveis para controle de PROC e FUNC
 *--------------------------------------------------------------*/
int CONTA_VARS_locais = 0; /* Numero de variaveis locais */
char ESCOPO_ATUAL; /* Escopo atual da MVS */
char CATEGORIA[4]; /* Categoria */
char TIPO[4]; /* Tipo */
char MECANISMO[4]; /* Mecanismo de parâmetros */
int POS_PROC;
int CONTA_PAR = -3; /* Numero de parametros */
int amz = 0;
int aux_soma = FALSE; /* auxiliar para verificar soma */
int aux_arg = FALSE; /* auxiliar para verificar argumentos */
int aux_var = FALSE; /* auxiliar para verificar se eh IDN ou VAR */	

/*----------------------------------------------------------------
 *						ENUM para árvore sintática
 *--------------------------------------------------------------*/
enum {
	PRG = 10, /*programa*/
	DVR, /*declaracao de variaveis*/
	TIP, /*tipo*/
	LVR, /*lista variaveis*/
	LCM, /*lista comandos*/
	LEI, /*leitura*/
	ESC, /*escrita*/
	REP, /*repeticao*/
	SEL, /*selecao*/
	ATR, /*atribuicao*/
	MUL, /*multiplicacao*/
	DIV, /*divisao*/
	SOM, /*soma*/
	SUB, /*subtracao*/
	MAI, /*maior*/
	MEN, /*menor*/
	IGU, /*igual*/
	CON, /*conjuncao*/
	DIS, /*disjuncao*/
	IDN, /*identificador*/
	VAR, /*variavel*/
	NUM, /*numero*/
	VER, /*verdade*/
	FAL, /*falso*/
	NAO,  /*negacao*/
	LRT, /*lista rotinas*/
	PRO, /*procedimento*/
	FUN, /*funcao*/
	LPA, /*lista de parametros*/
	PAR, /*parametro*/
	REF, /*referencia*/
	VAL, /*valor*/
	CHP, /*chamada de procedimento*/
	CHF, /*chamada de funcao*/
	LAR  /*lista argumentos*/
};


/*----------------------------------------------------------------
 *				Rotina geral de tratamento de erro
 *--------------------------------------------------------------*/
void ERRO(char *msg, ...) {
    char formato [255];
    va_list arg;
    va_start(arg, msg);
    sprintf(formato, "\n%d: ", numLinha);
    strcat(formato, msg);
    strcat(formato, "\n\n");
    printf("\nERRO no programa");
    vprintf(formato, arg);
    va_end(arg);
    exit(1);
}

/*----------------------------------------------------------------
 *						Lista de Parametros
 *--------------------------------------------------------------*/
typedef struct elem_lista_parametros {
    char *tipo;
    char *mecanismo;
    struct elem_lista_parametros *prox;
} *par;

/*----------------------------------------------------------------
 *						Tabela de Simbolos
 *--------------------------------------------------------------*/
struct elem_tab_simbolos {
    char id[30];
    char escopo;
    int desloca;
    int rotulo;
    char categoria[4];
    char tipo[4];
    char mecanismo[4];
    par parametros;

} TSIMB [TAM_TSIMB], elem_tab;

/*----------------------------------------------------------------
 *						Pilha Semantica
 *--------------------------------------------------------------*/
int PSEMA[TAM_PSEMA];

/*----------------------------------------------------------------
 * Funcao que BUSCA um simbolo na tabela de simbolos.
 *	Retorna -1 se o simbolo nao esta' na tabela
 *	Retorna i, onde i e' o indice do simbolo na tabela
 *		   se o simbolo esta' na tabela
 *--------------------------------------------------------------*/
int busca_simbolo(char *ident) {
    int i = TOPO_TSIMB - 1;
    for (; strcmp(TSIMB[i].id, ident) && i >= 0; i--);
    return i;
}

/*----------------------------------------------------------------
 * Funcao que INSERE um simbolo na tabela de simbolos.
 *	Se ja' existe um simbolos com o mesmo nome e mesmo nivel
 *	uma mensagem de erro e' apresentada e o programa e'
 *	interrompido.
 *--------------------------------------------------------------*/
void insere_simbolo(struct elem_tab_simbolos *elem) {
    if (TOPO_TSIMB == TAM_TSIMB) {
        ERRO("OVERFLOW - tabela de simbolos");
    } else {
        POS_SIMB = busca_simbolo(elem->id);
        if (POS_SIMB != -1) {
            ERRO("Identificador [%s] duplicado", elem->id);
        }
        TSIMB [TOPO_TSIMB] = *elem;
        TOPO_TSIMB++;
    }
}

/*----------------------------------------------------------------
 *				Variáveis para construção da árvore
 *--------------------------------------------------------------*/
par PARAMETROS;
par mecanismo_par;

/*----------------------------------------------------------------
 *	Funcao de Insercao de uma variavel na tabela de simbolos
 *--------------------------------------------------------------*/
void insere_variavel(char *ident) {
    strcpy(elem_tab.id, ident);
    elem_tab.escopo = ESCOPO_ATUAL;
    elem_tab.desloca = CONTA_VARS;
    strcpy(elem_tab.categoria, CATEGORIA);
    strcpy(elem_tab.tipo, TIPO);
    insere_simbolo(&elem_tab);
}

/*----------------------------------------------------------------
 *	Funcao de Insercao de parametros na tabela de simbolos
 *--------------------------------------------------------------*/
void insere_parametro(char *ident) {
    strcpy(elem_tab.id, ident);
    elem_tab.escopo = ESCOPO_ATUAL;
    elem_tab.desloca = CONTA_PAR;
    strcpy(elem_tab.categoria, CATEGORIA);
    strcpy(elem_tab.tipo, TIPO);
    strcpy(elem_tab.mecanismo, MECANISMO);
    insere_simbolo(&elem_tab);
}

/*----------------------------------------------------------------
 *	Funcao de Insercao de procedimento na tabela de simbolos
 *--------------------------------------------------------------*/
void insere_procedimento(char *ident) {
    strcpy(elem_tab.id, ident);
    elem_tab.escopo = ESCOPO_ATUAL;
    elem_tab.rotulo = ROTULO;
    strcpy(elem_tab.categoria, CATEGORIA);
    strcpy(elem_tab.mecanismo, MECANISMO);
    elem_tab.parametros = PARAMETROS;
    insere_simbolo(&elem_tab);
}

/*----------------------------------------------------------------
 *	Funcao de Insercao de funcao na tabela de simbolos
 *--------------------------------------------------------------*/
void insere_funcao(char *ident) {
    strcpy(elem_tab.id, ident);
    elem_tab.escopo = ESCOPO_ATUAL;
    elem_tab.rotulo = ROTULO;
    elem_tab.desloca = CONTA_PAR;
    strcpy(elem_tab.categoria, CATEGORIA);
    strcpy(elem_tab.tipo, TIPO);
    strcpy(elem_tab.mecanismo, MECANISMO);
    elem_tab.parametros = PARAMETROS;
    insere_simbolo(&elem_tab);
}

/*----------------------------------------------------------------
 *			Rotinas para manutencao da PILHA SEMANTICA
 *--------------------------------------------------------------*/
void empilha(int n) {
    if (TOPO_PSEMA == TAM_PSEMA) {
        ERRO("OVERFLOW - Pilha Semantica");
    }
    PSEMA[TOPO_PSEMA++] = n;
}

int desempilha() {
    if (TOPO_PSEMA == 0) {
        ERRO("UNDERFLOW - Pilha Semantica");
    }
    return PSEMA[--TOPO_PSEMA];
}

/*----------------------------------------------------------------
 *					Estrutura da árvore semântica
 *--------------------------------------------------------------*/
typedef struct no *ptno;

struct no {
	int tipo;
	char *valor;
	ptno filho, irmao;
};

/*----------------------------------------------------------------
 *			Variaveis auxiliares para percurso na arvore
 *--------------------------------------------------------------*/
ptno raiz;
ptno no_aux;
ptno no_aux_expressao;
ptno no_aux_declaracao;
ptno no_aux_comandos;
ptno no_aux_rotinas;
ptno no_aux_parametros;
ptno no_aux_argumentos;
ptno no_aux_atribuicao;

ptno pilha_selecao[TAM_PSEMA];
int TOPO_selecao = -1;

ptno pilha_repeticao[TAM_PSEMA];
int TOPO_repeticao = -1;

int conta_exp = 0;
char arg;

/*----------------------------------------------------------------
 *					Rotinas para árvore semântica
 *--------------------------------------------------------------*/
ptno criaNo (int tipo, char *valor) {
	ptno n = (ptno) malloc (sizeof (struct no));
	n->valor = (char *) malloc (strlen (valor)*sizeof(char)+1);
	n->tipo = tipo;
	strcpy (n->valor, valor);
	n->filho = NULL;
	n->irmao = NULL;
	return n;
}

void adicionaFilho (ptno pai, ptno filho){
	ptno aux = pai->filho;
	if(!aux){
		filho->irmao = pai->filho;
		pai->filho = filho;
	} else {
		while(aux->irmao != NULL){
			aux = aux->irmao;
		}
		aux->irmao = filho;
	}
}

par criaParametro (char *tipo, char *mecanismo) {
	par n = (par) malloc (sizeof (struct elem_lista_parametros));
	n->mecanismo = (char *) malloc (strlen (mecanismo)*sizeof(char)+1);
	n->tipo = (char *) malloc (strlen (tipo)*sizeof(char)+1);
	strcpy (n->mecanismo, mecanismo);
	strcpy (n->tipo, tipo);
	n->prox = NULL;
	return n;
}

/*----------------------------------------------------------------
 *				Rotina para geração do arquivo (tree)
 *--------------------------------------------------------------*/
void geraarv(ptno no){
	ptno p;

	//Printa Nó da arvore, referente ao ENUM
	printf("%d ", no->tipo);

	//Se houver valor no nó como IDN e TIP é printado
	if(strcmp(no->valor, "")){
		printf("%s ", no->valor);		
	}
	p = no->filho;
	while(p){
		geraarv(p);
		p = p->irmao;
	}
	//Printa 0 para reconhecer os fim de ramos
	printf("0 ");
}

/*----------------------------------------------------------------
 *				Rotina para geração do arquivo (mvs)
 *--------------------------------------------------------------*/
void geracod (ptno p){
	if(p == NULL){
		return;
	} else {
		ptno fil;
		fil = p->filho;

		switch(p->tipo){
			case PRG:				
				//Inicia escopo como global e zera o contador de variaveis globais								
				printf("      INPP\n");			
				ESCOPO_ATUAL = 'G';
				CONTA_VARS = 0;
				
				//nó PRG só pode ter 4 filhos (IDN, DVR, LRT, LCM)
				geracod(fil->irmao); //recursiva do segundo nó mais a esquerda (DVR)
				if (CONTA_VARS){
					printf ("      AMEM    %d\n", CONTA_VARS);
				}
				geracod(fil->irmao->irmao); //recursiva do terceiro nó mais a esquerda (LRT)
				ESCOPO_ATUAL = 'G'; //muda escopo após LRT
				geracod(fil->irmao->irmao->irmao); //recursiva do quarto nó mais a esquerda (LCM)
				if (CONTA_VARS){
					printf ("      DMEM    %d\n", CONTA_VARS);
				}
				printf("      FIMP\n");
				break;
			case DVR:			
				//DVR só pode ter 2 filhos (TIP, LVR)
				geracod(fil); //tipo
				geracod(fil->irmao); //LVR
				break;
			case TIP:
				//TIP só pode retornar se é inteiro ou lógico
				if (p->valor == "inteiro"){
					strcpy(TIPO, "INT");
				} else {
					strcpy(TIPO, "LOG");
				}
				break;
			case LVR:			
				//Lista de variaveis só pode ter 2 filhos (IDN, LVR)
				strcpy(CATEGORIA, "IDN");
				insere_variavel(fil->valor);
				if(ESCOPO_ATUAL == 'G'){
					CONTA_VARS++; 
				} else {
					CONTA_VARS_locais++; //se estiver dentro de uma rotina é acrescentado ao contador de vars locais
				}
				geracod(fil->irmao);
				break;
			case LCM:			
				// Lista de comandos pode conter 2 filhos (Comando, LCM)
				geracod(fil);
				geracod(fil->irmao);
				break;
			case LEI:			
				// Leia verifica na tabela de simbolos ja existe um simbolo igual
				POS_SIMB = busca_simbolo(fil->valor);
	        	if (POS_SIMB == -1){
	            	ERRO("Variavel [%s] nao declarada!", fil->valor);
	        	} else {
	            	printf ("      LEIA\n");
					if (TSIMB[POS_SIMB].escopo == 'G'){ //verifica escopo
						printf ("      ARZG    %d\n", TSIMB[POS_SIMB].desloca);
					} else {
						if (!strcmp(TSIMB[POS_SIMB].mecanismo,"REF")){ //Verifica se eh valor ou referencia
							printf("      ARMI    %d\n", TSIMB[POS_SIMB].desloca);
						} else {
							printf ("      ARZL    %d\n", TSIMB[POS_SIMB].desloca-CONTA_VARS);
						}
					}
	            }
				break;
			case ESC:
				//Escreva pode ter apenas 1 filho (Comando ou IDN)
				geracod(fil);
				printf ("      ESCR\n");
				break;
			case REP:
				//Repeticao pode ter 2 filhos (Expressao, LCM)
				printf("L%d    NADA\n", ++ROTULO); //Rotulo eh referente ao valor do desvio
				empilha(ROTULO); //Empilha o valor do rotulo
				geracod(fil);
				printf("      DSVF    L%d\n", ++ROTULO);
				empilha(ROTULO);
				geracod(fil->irmao);
				aux = desempilha();
				printf("      DSVS    L%d\n", desempilha());
				printf("L%d    NADA\n", aux);
				break;
			case SEL:
				//			
				geracod(fil);
				printf ("      DSVF    L%d\n", ++ROTULO);
	          	empilha (ROTULO);
	          	geracod(fil->irmao);
	          	printf ("      DSVS    L%d\n", ++ROTULO);
	          	printf ("L%d    NADA\n", desempilha());
	          	empilha (ROTULO);
	          	geracod(fil->irmao->irmao);
	          	printf ("L%d    NADA\n", desempilha());
				break;
			case ATR:			
				//Atribuicao só tera 2 filhos (expressao, expressao)
				POS_SIMB = busca_simbolo(fil->valor); //busca simbolo na tabela
				if (POS_SIMB == -1){
	            	ERRO("Variavel [%s] nao declarada!", fil->valor);
	          	} else {
	            	empilha (TSIMB[POS_SIMB].desloca);            
	          	}

				if (!strcmp(TSIMB[POS_SIMB].mecanismo,"REF")){
			  		amz = 2;
			  	} else if (TSIMB[POS_SIMB].escopo == 'L'){
			  		amz = 1;
			  	} else {
			  		amz = 0;
			  	}          
	            geracod(fil->irmao);         
	            if (amz == 0) {
					printf ("      ARZG    %d\n", desempilha());
				} else if (amz == 1){
					printf ("      ARZL    %d\n", desempilha()-CONTA_VARS);
				} else {
					printf("      ARMI    %d\n", desempilha());
				}
				break;
			case MUL:		
				//Multiplica tem 2 filhos (expressao, expressao)	
				geracod(fil);
				geracod(fil->irmao);
				printf ("      MULT\n");				
				break;
			case DIV:
				//Divisao tem 2 filhos (expressao, expressao)						
				geracod(fil);			
				geracod(fil->irmao);
				printf ("      DIVI\n");
				break;
			case SOM:	
				//Soma tem 2 filhos (expressao, expressao)					
				if (aux_soma){
					geracod(fil);
					printf ("      SOMA\n");				
					geracod(fil->irmao);
				} else if (fil->irmao->tipo == SOM){ //Se possui mais de uma soma na expressao
					aux_soma = TRUE;
					geracod(fil);			
					geracod(fil->irmao);
					printf ("      SOMA\n");
					aux_soma = FALSE;
				} else {
					geracod(fil);				
					geracod(fil->irmao);
					printf ("      SOMA\n");
				}
				break;
			case SUB:		
			//Subtracao tem 2 filhos (expressao, expressao)		
				geracod(fil);			
				geracod(fil->irmao);
				printf ("      SUBT\n");
				break;
			case MAI:
			//Maior tem 2 filhos (expressao, expressao)	
				geracod(fil);
				geracod(fil->irmao);
				printf ("      CMMA\n");
				break;
			case MEN:
			//Menor tem 2 filhos (expressao, expressao)				
				geracod(fil);
				geracod(fil->irmao);
				printf ("      CMME\n");
				break;	
			case IGU:
			//Igual tem 2 filhos (expressao, expressao)				
				geracod(fil);
				geracod(fil->irmao);
				printf ("      CMIG\n");
				break;
			case CON:
			//Conjuncao tem 2 filhos (expressao, expressao)				
				geracod(fil);
				geracod(fil->irmao);
				printf ("      CONJ\n");
				break;
			case DIS:	
			//Disjuncao tem 2 filhos (expressao, expressao)			
				geracod(fil);
				geracod(fil->irmao);
				printf ("      DISJ\n");
				break;
			case IDN:
			  	POS_SIMB = busca_simbolo (p->valor); //busca na tabela de simbolo
			  	if (POS_SIMB == -1){
					ERRO ("Variavel [%s] nao declarada!", p->valor); //nao existe na tabela
			  	}
			  	else if (aux_arg){ //Se entrou na LAR e identificou REF eh instrucao de endereco
			  		printf ("      CREG    %d\n", TSIMB[POS_SIMB].desloca);
			  	} else if (TSIMB[POS_SIMB].escopo == 'G'){  //se escopo for global eh instrucao global
					printf ("      CRVG    %d\n", TSIMB[POS_SIMB].desloca);
			  	} else if (!strcmp(TSIMB[POS_SIMB].categoria, "PAR")){ //Se for parametro
			  		printf ("      CRVL    %d\n", TSIMB[POS_SIMB].desloca);
			  	} else {
			  		printf ("      CRVL    %d\n", TSIMB[POS_SIMB].desloca-CONTA_VARS); //se for declarada dentro da rotina
			  	}
				break;
			case VAR:
			  	POS_SIMB = busca_simbolo (p->valor); //busca na tabela de simbolo
			  	if (POS_SIMB == -1){
					ERRO ("Variavel [%s] nao declarada!", p->valor); //nao existe na tabela
			  	}
			  	else if (aux_arg){ //Se entrou na LAR e identificou REF eh instrucao de endereco
			  		printf ("      CREG    %d\n", TSIMB[POS_SIMB].desloca);
			  	} else if (TSIMB[POS_SIMB].escopo == 'G'){  //se escopo for global eh instrucao global
					printf ("      CRVG    %d\n", TSIMB[POS_SIMB].desloca);
			  	} else if (!strcmp(TSIMB[POS_SIMB].categoria, "PAR")){ //Se for parametro
			  		printf ("      CRVL    %d\n", TSIMB[POS_SIMB].desloca);
			  	} else {
			  		printf ("      CRVL    %d\n", TSIMB[POS_SIMB].desloca-CONTA_VARS); //se for declarada dentro da rotina
			  	}
				break;
			case NUM:
				printf ("      CRCT    %s\n", p->valor);
				break;
			case VER:
				printf ("      CRCT    1\n");
				break;
			case FAL:
				printf ("      CRCT    0\n");
				break;
			case NAO:
				printf ("      NEGA\n");
				break;
			case LRT:
			//Lista de rotina tera 2 filhos (Rotina, LRT)
			    ESCOPO_ATUAL = 'L'; //Muda o escopo para local			    
      			printf("      DSVS    L%d\n", ROTULO);
      			empilha(ROTULO);	      	      		
				geracod(fil);				
				geracod(fil->irmao);
				printf("L%d    NADA\n", desempilha());				
				break;
			case PRO:
			//Procedimento pode ter 4 filhos (IDN, LPA, DVR, LCM)												
				printf ("L%d    ENSP    \n", ++ROTULO);
				PARAMETROS = NULL; //inicia lista de parametros
				geracod(fil->irmao);
				strcpy(CATEGORIA, "PRO");				
				insere_procedimento(fil->valor); //insere procedimento na tabela de simbolos
				geracod(fil->irmao->irmao);
				if (CONTA_VARS_locais){
					printf ("      AMEM    %d\n", CONTA_VARS_locais);
				}
				geracod(fil->irmao->irmao->irmao);
				if (CONTA_VARS_locais){
					printf ("      DMEM    %d\n", CONTA_VARS_locais); 
				}
				CONTA_VARS_locais = 0;
				printf ("      RTSP    %d\n", (CONTA_PAR+3)*-1);  //Retorna a quantidade de parametros
				CONTA_PAR=-3; //Inicia valor de endereco de parametro
				break;
			case FUN:
			//Funcao pode ter 5 filhos (IDN, TIP, LPA, DVR, LCM)														
				printf ("L%d    ENSP    \n", ++ROTULO);
				PARAMETROS = NULL; //inicia lista de parametros
				geracod(fil->irmao->irmao);
				strcpy(CATEGORIA, "FUN");
				insere_funcao(fil->irmao->valor); //insere funcao na tabela de simbolos
				geracod(fil->irmao->irmao->irmao);
				if (CONTA_VARS_locais){
					printf ("      AMEM    %d\n", CONTA_VARS_locais);
				}
				geracod(fil->irmao->irmao->irmao->irmao);
				if (CONTA_VARS_locais){
					printf ("      DMEM    %d\n", CONTA_VARS_locais); 
				}
				CONTA_VARS_locais = 0; //inicia o contador pra proxima iteracao
				printf ("      RTSP    %d\n", (CONTA_PAR+3)*-1); //Retorna quantidade de parametros
				CONTA_PAR=-3; //iniciar contador de endereco de parametro para proxima iteracao
				break;
			case LPA:
			//Lista de parametros pode conter 2 filhos (PAR, LPA)						
				geracod(fil->irmao);
				geracod(fil);
				break;
			case PAR:
			//Parametros pode conter 3 filhos (Mecanismo, TIP, IDN)									
				geracod(fil);
				geracod(fil->irmao);
				strcpy(CATEGORIA, "PAR");
				insere_parametro(fil->irmao->irmao->valor); //insere parametro na tabela de simbolos
				if (PARAMETROS == NULL){
					PARAMETROS = criaParametro(TIPO, MECANISMO); //Se lista encadeada for vazia cria um no de parametro
				} else {
					PARAMETROS->prox = criaParametro(TIPO, MECANISMO); //senao cria no no final				
				}
				CONTA_PAR = CONTA_PAR - 1; 
				break;
			//Mecanismo se eh valor ou referencia
			case REF:
				strcpy(MECANISMO, "REF");
				break;
			case VAL:		
				strcpy(MECANISMO, "VAL");
				break;			
			case CHP:
			//Chamada de procedimento so pode ter 2 filhos (IDN, LAR)						
				POS_PROC = busca_simbolo (fil->valor); //busca procedimento na tabela de simbolos
				if (POS_SIMB == -1){
					ERRO ("Procedimento nao declarado!");
				} else {
					mecanismo_par = TSIMB[POS_PROC].parametros; //insere parametros 
					geracod(fil->irmao);
					printf("      SVCP\n");
					printf ("      DSVS    L%d\n", TSIMB[POS_PROC].rotulo);
				}
				break;
			case CHF:
			//Chamada de funcao pode ter 2 filhos ()					
				POS_PROC = busca_simbolo (fil->valor); //busca funcao na tabela de simbolos
				if (POS_SIMB == -1){
					ERRO ("Funcao nao declarada!");
				} else {
					printf("      AMEM    1\n"); //Armazena o retorno
					geracod(fil->irmao);
					printf("      SVCP\n");
					printf ("      DSVS    L%d\n", TSIMB[POS_PROC].rotulo);
				}
				break;
			case LAR:
			//Lista de argumentos pode conter 2 filhos (IDN, LAR)						
				if (mecanismo_par != NULL && !strcmp(mecanismo_par->mecanismo, "REF")){ //se lista encadeada de argumentos de referencia nao for nula e 
					aux_arg = TRUE; //se parametro for referencia seta auxiliar
					mecanismo_par = mecanismo_par->prox;
				}
				geracod(fil);
				aux_arg = FALSE; //seta auxiliar 'par'a valor
				geracod(fil->irmao);
				break;
			}	
	}
}