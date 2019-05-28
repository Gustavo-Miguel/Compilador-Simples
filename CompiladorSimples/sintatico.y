/*+−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−
|
| UNIFAL − Universidade Federal de Alfenas.
|   BACHARELADO EM CIENCIA DA COMPUTACAO.
| Trabalho: PARTE 1 − Construcao Arvore Sintatica
| Disciplina: Compiladores I
| Professor: Luiz Eduardo da Silva
| Aluno: Gustavo Alves Miguel
| Data: 04/02/2018
+−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−−*/

%{
	#include <stdio.h>	
	#include <string.h>
	#include <stdlib.h>
	#include <stdarg.h>
    
  #include "utils.c"
	#include "lexico.c"

  int yylex();
  void yyerror (char *s){
    ERRO("ERRO SINTATICO");
  }
%}

//Símbolo de partida
%start programa

//Símbolos terminais
%token T_PROGRAMA
%token T_INICIO
%token T_FIM
%token T_IDENTIF
%token T_LEIA
%token T_ESCREVA
%token T_ENQTO
%token T_FACA
%token T_FIMENQTO
%token T_SE
%token T_ENTAO
%token T_SENAO
%token T_FIMSE
%token T_ATRIB
%token T_VEZES
%token T_DIV
%token T_MAIS
%token T_MENOS
%token T_MAIOR
%token T_MENOR
%token T_IGUAL
%token T_E
%token T_OU
%token T_V
%token T_F
%token T_NUMERO
%token T_NAO
%token T_ABRE
%token T_FECHA
%token T_LOGICO
%token T_INTEIRO

%token T_FUNC
%token T_FIMFUNC
%token T_PROC
%token T_FIMPROC
%token T_REF

%left T_E T_OU
%left T_IGUAL
%left T_MAIOR T_MENOR
%left T_MAIS T_MENOS
%left T_VEZES T_DIV

%%

// Inicio de programa e inicio da recursividade da arvore
programa //possui 4 nos filhos contem (cabecalho, variaveis, subprogramas e lista de comandos)
    : { 
        raiz = criaNo(PRG, ""); 
        no_aux = raiz; 					// no auxiliar para nao perder o contexto do programa
      } cabecalho // chamada do cabecalho do programa
      {
        no_aux_declaracao = raiz; 		// referencia o no de declaracao de variaveis
      } variaveis // variaveis do programa 
      { 
        no_aux_rotinas = raiz;  		// referencia o no de lista de rotinas
      } subprogramas // corpo das rotinas, se houver
      T_INICIO 
      { 
        no_aux_comandos = raiz; 		// referencia o no de lista de comandos
      } lista_comandos // comandos do programa como atrib leitura etc
      T_FIM
    ;

// Cabecalho do programa (nome do programa)
cabecalho
    : T_PROGRAMA T_IDENTIF 
    { 
      adicionaFilho(raiz, criaNo(IDN, atomo)); // cria identificador do programa
    }
    ;

// Variaveis dentro de funcao ou procedimento ou do programa
variaveis
    : /* Não possui variaveis */
    | {
        no_aux = criaNo(DVR, ""); 					// cria no de declaracao de variaveis
        adicionaFilho(no_aux_declaracao, no_aux); 	// adiciona como filho (pode ser filho do programa ou de uma rotina)
      } declaracao_variaveis 						// para declarar as variaveis e os tipo
    ;

// Declaracao dos tipos e da lista de variaveis
declaracao_variaveis    
    : declaracao_variaveis tipo lista_variaveis
    | tipo lista_variaveis
    ;

// Tipo das varivaies 
tipo // cria no com o tipo da variavel e seu valor
    : T_INTEIRO 
    { 
      adicionaFilho(no_aux, criaNo(TIP, "inteiro")); 
    }
    | T_LOGICO 
    { 
      adicionaFilho(no_aux, criaNo(TIP, "logico")); 
    }
    ;

// Lista das variaveis do programa, procedimetno ou funcao
lista_variaveis
    : lista_variaveis 
    { 
      adicionaFilho(no_aux, criaNo(LVR, "")); 		// cria no para lista de variaveis
      no_aux = no_aux->filho->irmao; 				// contexto recebe no nivel abaixo para criar identificador da variavel
    } T_IDENTIF
    { 
      adicionaFilho(no_aux, criaNo(IDN, atomo)); 	// variavel declarada e seu valor
    }
    | { // se nao houver mais variaveis
      adicionaFilho(no_aux, criaNo(LVR, "")); 
      no_aux = no_aux->filho->irmao; 
    } T_IDENTIF
    { 
      adicionaFilho(no_aux, criaNo(IDN, atomo)); 
    }
    ;

// Lista de comandos do corpo do programa
lista_comandos
    : /* Não possui comandos */
    | { // criacao de uma estrutura de vetor para referenciar os nos passados (simula uma pilha)
        conta_exp = 0;										// contador de expressoes
        if(TOPO_selecao > -1){ 								// se houver elementos na vetor
          no_aux = criaNo(LCM, ""); 						// cria no de lista de comandos          
          adicionaFilho(pilha_selecao[TOPO_selecao], no_aux); 	// adiciona no topo da vetor de nos de selecao
          TOPO_selecao++; 									// incrementa topo da pilha         
          pilha_selecao[TOPO_selecao] = no_aux;         
        } else if(TOPO_repeticao > -1){ 						// estrutura para comando de repeticao          
          no_aux = criaNo(LCM, "");          
          adicionaFilho(pilha_selecao[TOPO_repeticao], no_aux);          
          pilha_selecao[TOPO_repeticao] = no_aux;
        } else { 											// senao acrescenta no lista de comando 
          no_aux = criaNo(LCM, "");          
          adicionaFilho(no_aux_comandos, no_aux);           
          no_aux_comandos = no_aux;
        } 
      } comando lista_comandos
    ;

comando
    : entrada_saida
    | repeticao
    | selecao
    | atribuicao
    | chamada_procedimento
    ;

entrada_saida
    : leitura
    | escrita
    ;

leitura 
    : T_LEIA T_IDENTIF
      {
        adicionaFilho(no_aux, criaNo(LEI, ""));
        adicionaFilho(no_aux->filho, criaNo(IDN, atomo));
      }
    ;

escrita
    : T_ESCREVA 
    { 
      adicionaFilho(no_aux, criaNo(ESC, "")); 
      no_aux = no_aux->filho;
    } expressao										// escreve uma expressa como identificador ou pode ser uma soma por exemplo
    ;

// Estrutura de repeticao como while 
repeticao
    : T_ENQTO 
      { 
      	aux_var = 1;
        adicionaFilho(no_aux, criaNo(REP, "")); 
        no_aux = no_aux->filho; 
        TOPO_repeticao++;								// adiciona ao vetor um novo no
        pilha_selecao[TOPO_repeticao] = no_aux;
      } expressao
      T_FACA lista_comandos T_FIMENQTO
      {
        TOPO_repeticao--;								// desempilha (vetor) uma referencia de no de repeticao
      }
      ;

// Estrutura de selecao como if
selecao												// mesmo funcionamento que o no de repeticao
    : T_SE 
      { 
      	aux_var = 1;     
        adicionaFilho(no_aux, criaNo(SEL, ""));         
        no_aux = no_aux->filho;         
        TOPO_selecao++;               
        pilha_selecao[TOPO_selecao] = no_aux; 
      } expressao
      T_ENTAO lista_comandos
      {      	
        TOPO_selecao--;
      }
      T_SENAO lista_comandos
      T_FIMSE
      {      	      	
        TOPO_selecao = TOPO_selecao - 2;
      }
      ;

// Estrutura de atribuicao
atribuicao
    : T_IDENTIF
      {
        no_aux_atribuicao = criaNo(IDN, atomo);		// cria no de destino (identificador do destino)
      } T_ATRIB 
      { 
        adicionaFilho(no_aux, criaNo(ATR, "")); 	
        no_aux = no_aux->filho; 			
        no_aux->filho = no_aux_atribuicao;					
      } expressao									// atribui uma expressao
    ;

// Expressoes aritmeticas para execucao do programa
expressao
    : expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(MUL, ""); 				//	cria no multiplicacao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 										
        no_aux_expressao = criaNo(MUL, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    } T_VEZES expressao								// se for multiplicacao 
    
    | expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao 
        no_aux_expressao = criaNo(DIV, ""); 				//	cria no divisao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(DIV, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    } T_DIV expressao								//se for divisao
    
    | expressao
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao 
        no_aux_expressao = criaNo(SOM, ""); 				//	cria no soma e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(SOM, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    } T_MAIS expressao								//se for soma
    
    | expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(SUB, ""); 				//	cria no soma e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(SUB, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    } T_MENOS expressao								//se for subtracao
    
    | expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(MEN, ""); 				//	cria no menor e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(MEN, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    } T_MENOR expressao							//comparacao com menor
    
    | expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){  			// se ja houver outra expressao adiciona no irmao 
      	aux_var = 1;    	   								//	cria no maior e adiciona no auxiliar de expressao
        no_aux_expressao = criaNo(MAI, ""); 
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
      	aux_var = 1;
        no_aux_expressao = criaNo(MAI, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao;
        no_aux = no_aux_expressao; 
      } 
    } T_MAIOR expressao							//comparacao maior
    
    | expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(IGU, ""); 				//	cria no igual e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(IGU, "");
        no_aux_expressao->filho = no_aux->filho;
        no_aux->filho = no_aux_expressao;
        no_aux = no_aux_expressao;
      } 
    } T_IGUAL expressao							//comparacao igual
    
    | expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(CON, ""); 				//	cria no conjuncao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao;
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(CON, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    } T_E expressao								// conjuncao
    
    | expressao 
    { 
      conta_exp++;											// incrementa quantidade de expressoes
      if (conta_exp > 1 || no_aux->tipo == ATR){ 			// se ja houver outra expressao adiciona no irmao
        no_aux_expressao = criaNo(DIS, ""); 				//	cria no disjuncao e adiciona no auxiliar de expressao
        no_aux_expressao->filho = no_aux->filho->irmao; 
        no_aux->filho->irmao = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } else { 
        no_aux_expressao = criaNo(DIS, ""); 
        no_aux_expressao->filho = no_aux->filho; 
        no_aux->filho = no_aux_expressao; 
        no_aux = no_aux_expressao; 
      } 
    } T_OU expressao							// disjuncao
    | termo 
    ;

termo
    : T_IDENTIF
      {	
      	if(aux_var == 1){									// verifica se eh no de valor ou identificador 
      		if (no_aux->tipo == LAR){
          		adicionaFilho(no_aux, criaNo(VAR, &arg));	// se estiver em lista de argumentos cria com valor de argumento
       		} else {
          		adicionaFilho(no_aux, criaNo(VAR, atomo));
        	}
      	} else {
	        if (no_aux->tipo == LAR){
	          adicionaFilho(no_aux, criaNo(IDN, &arg));
	        } else {
	          adicionaFilho(no_aux, criaNo(IDN, atomo));
	        }
	    }
      }
    | T_NUMERO
      { 
        adicionaFilho(no_aux, criaNo(NUM, atomo)); 
      }
    | T_V
      { 
        adicionaFilho(no_aux, criaNo(VER, "")); 
      }
    | T_F
      { 
        adicionaFilho(no_aux, criaNo(FAL, "")); 
      }
    | T_NAO termo
      { 
        adicionaFilho(no_aux, criaNo(NAO, "")); 
      }
    | T_ABRE expressao T_FECHA
    | chamada_funcao									 
    ; 

subprogramas
  : /* Nao possui subprogramas */
  | lista_subprogramas 
  ;
  
// Cria no de lista de rotinas e chama rotinas
lista_subprogramas
  : 
  | {
    no_aux = criaNo(LRT, ""); 
    adicionaFilho(no_aux_rotinas, no_aux); 
    no_aux_rotinas = no_aux;
  } subprograma lista_subprogramas
  ;
  
subprograma
  : funcao 
  | procedimento
  ;

// Cria no de funcao e realiza percurso para nos de funcao  
funcao
  : T_FUNC
  {
    adicionaFilho(no_aux, criaNo(FUN, ""));
    no_aux = no_aux->filho;
    no_aux_declaracao = no_aux;	// declaracao de variaveis dentro da funcao
  } tipo T_IDENTIF 
  {
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_parametros = no_aux;	// lista de parametros dentro da funcao
    no_aux_comandos = no_aux;	// lista de comandos dentro da funcao
  } T_ABRE lista_parametros T_FECHA variaveis T_INICIO lista_comandos T_FIMFUNC
  ;
  
// Cria no de procedimento e realiza percurso para nos de procediemetno
procedimento
  : T_PROC
  { 
    adicionaFilho(no_aux, criaNo(PRO, ""));
    no_aux = no_aux->filho;
    no_aux_declaracao = no_aux;	// declaracao de variaveis dentro da procedimento
  } T_IDENTIF
  {
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_parametros = no_aux;	// lista de parametros dentro de procedimento
    no_aux_comandos = no_aux;	// lista de comandos dentro de procedimento
  } T_ABRE lista_parametros T_FECHA variaveis T_INICIO lista_comandos T_FIMPROC
  ;
 
// Percurso de lista de parametros
lista_parametros
  : /* Nao possui parametros */
  | lista_parametros
  {
    no_aux = criaNo(LPA, ""); 
    adicionaFilho(no_aux_parametros, no_aux); 
    no_aux_parametros = no_aux;
  } parametro
  ;

// Criacao de parametro  
parametro
  :
  {
    adicionaFilho(no_aux, criaNo(PAR, ""));
    no_aux = no_aux->filho;
  } forma_passagem tipo T_IDENTIF
  {
    adicionaFilho(no_aux, criaNo(IDN, atomo));
  }
  ;
 
// Mecanismo do parametros (valor ou referencia)
forma_passagem
  : T_REF
  { 
    adicionaFilho(no_aux, criaNo(REF, "")); 
  }
  | { 
    adicionaFilho(no_aux, criaNo(VAL, ""));
  }
  ;

// Chamada de procedimento e recebimento de argumentos 
chamada_procedimento
  : T_IDENTIF 
  {
    adicionaFilho(no_aux, criaNo(CHP, ""));
    no_aux = no_aux->filho;
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_argumentos = no_aux;		// lista de argumentos na chamada procedimento
  } T_ABRE argumentos T_FECHA
  ;
  
// Chamada de funcao e recebimento de argumentos
chamada_funcao
  : T_IDENTIF T_ABRE
  {
    adicionaFilho(no_aux, criaNo(CHF, ""));
    no_aux = no_aux->filho;
    adicionaFilho(no_aux, criaNo(IDN, atomo));
    no_aux_argumentos = no_aux; 		// lista de argumentos na chamada funcao
  } argumentos T_FECHA
  ;

// Lista de argumetnos
argumentos
  : /* Nao possui argumento */
  | lista_argumentos
  ;
  
lista_argumentos
  : lista_argumentos argumento 
  | argumento
  ;

// Criacao do argumento e adicionada na lista
argumento
  : {
    arg = *atomo;
    no_aux = criaNo(LAR, ""); 
    adicionaFilho(no_aux_argumentos, no_aux); 
    no_aux_argumentos = no_aux;
  } expressao
  ;

%%

int yywrap() {

}

int main (void){
	yyparse();
	
	//Arvore Sintatica
  	geraarv(raiz); //geracao do codigo ENUM para criacao da arvore
  	printf("\n\n");


  	//MVS - Máquina Virtual Simples
  	geracod(raiz); // geracao do codigo para MVS
  	printf("\n");
}
