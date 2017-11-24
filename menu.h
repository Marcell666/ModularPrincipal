/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Menu
*
*  Arquivo gerado:              menu.c
*  Letras identificadoras:      MEN
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 1 / Grupo 2 / Grupo 5
*  Autores:   Bruce Marcellino (Grupo 1)
*			  Bruno Miranda Marinho (Grupo 2)
*             Cristiane Ramalho Guimarães (Grupo 5)
*             Flávio Thiago Franco Vaz (Grupo 2)
*             João Victor Cerqueira (Grupo 2)
*             Matheus Henrique Branco Zeitune (Grupo 2)
*             Vinícius Cortat (Grupo 2)
*
*  $HA Histórico de evolução:
*     Versão  Autor         Data		Observações
*     1.02    Cristiane  15/11/2017	    Revisão                                        
*     1.01    Bruce	     07/10/2017	    Reestruturação
*     1.00    Bruce	     06/10/2017	    Revisão/finalização
*     0.05    Bruce	     05/10/2017	    Modulo professor
*     0.04    Matheus    04/10/2017  	Revisão menu
*     0.03    Bruno	     02/10/2017	    Menu professor
*     0.02    Flávio	 02/10/2017  	Revisão
*     0.01    Matheus	 01/10/2017	    Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa o Menu do Sistema Acadêmico a ser desenvolvido.
*     O menu é a chamada dos modulos por interface.
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

#define  MEN_MIN_ANO  1850
#define  MEN_TAM_STRING  81
#define  MEN_TAM_UF 3
#define  MEN_TAM_CPF 12
#define  MEN_TAM_MAT 9
#define  MEN_TAM_TEL 10
#define  MEN_QTD_EST 27
#define  MEN_TAM_RG 10

#define MEN_MAX_NOME 25
#define MEN_MAX_CODIGO 8
#define MEN_MAX_BIBLIOGRAFIA 300
#define MEN_MAX_EMENTA 300
#define MEN_MIN_CREDITOS 1
#define MEN_MAX_CRITERIO 25
#define MEN_COD_TUR 4
#define MEN_DIA_SEMANA 28

/***********************************************************************
*
*  $FC Função: MEN_loginAdministrativo
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Rertona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/
	
	int MEN_loginAdministrativo ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_loginProfessor.
*
*  $ED Descrição da função
*		Realiza a busca no corpo docente, se a matricula.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retorna 1, caso econtre e 0, senao.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	int MEN_loginProfessor ( void ) ;
	
/***********************************************************************
*
*  $FC Função: MEN_loginAluno
*
*  $ED Descrição da função
*		Realiza a busca da matricula do aluno. (não implementado)
*
***********************************************************************/
/*Assertivas: Retorno da função: Rertona 1, se foi encontrado a matricula.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	int MEN_loginAluno ( unsigned int * matricula ) ;

/***********************************************************************
*
*  $FC Função: MEN_adicionaAluno
*
*  $ED Descrição da função
*		
*Parâmentros: endereço da matricula que será recebida pelo usuario.
***********************************************************************/

	void MEN_adicionaAluno ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_modificaAluno
*
*  $ED Descrição da função
*		
*
***********************************************************************/

	void MEN_modificaAluno ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_adiocionaProfessor
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_adicionaProfessor ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_modificaProfessor
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_modificaProfessor ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_removeProfessor
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeProfessor ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_removeProfessor
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeTodosProfessores ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_menuGradeCurricular
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_menuGradeCurricular ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_leNumero
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	int MEN_leNumero ( void ) ;

/***********************************************************************
*
*  $FC Função: MEN_leMatricula 
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	int MEN_leMatricula ( void ) ;
