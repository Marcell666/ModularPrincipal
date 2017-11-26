/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Menu
*
*  Arquivo gerado:              menu.c
*  Letras identificadoras:      MEN
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acad�mico da turma 3WB
*  Gestor:  Grupo 1 / Grupo 2 / Grupo 5
*  Autores:   Bruce Marcellino (Grupo 1)
*			  Bruno Miranda Marinho (Grupo 2)
*             Cristiane Ramalho Guimar�es (Grupo 5)
*             Fl�vio Thiago Franco Vaz (Grupo 2)
*             Jo�o Victor Cerqueira (Grupo 2)
*             Matheus Henrique Branco Zeitune (Grupo 2)
*             Vin�cius Cortat (Grupo 2)
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor         Data		Observa��es
*     1.03    Bruce/Cris 25/11/2017     Revis�o/finaliza��o
*     1.02    Cristiane  15/11/2017	    Revis�o                                        
*     1.01    Bruce	     07/10/2017	    Reestrutura��o
*     1.00    Bruce	     06/10/2017	    Revis�o/finaliza��o
*     0.05    Bruce	     05/10/2017	    Modulo professor
*     0.04    Matheus    04/10/2017  	Revis�o menu
*     0.03    Bruno	     02/10/2017	    Menu professor
*     0.02    Fl�vio	 02/10/2017  	Revis�o
*     0.01    Matheus	 01/10/2017	    In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa o Menu do Sistema Acad�mico a ser desenvolvido.
*     O menu � a chamada dos modulos por interface.
***************************************************************************/

/***** Declara��es exportadas pelo m�dulo *****/

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
*  $FC Fun��o: MEN_loginAdministrativo
*
*  $ED Descri��o da fun��o
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: Rertona 1, se os dados s�o validos.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/
	
	int MEN_loginAdministrativo ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_loginProfessor.
*
*  $ED Descri��o da fun��o
*		Realiza a busca no corpo docente, se a matricula.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: Retorna 1, caso econtre e 0, senao.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	int MEN_loginProfessor ( int *matricula ) ;
	
/***********************************************************************
*
*  $FC Fun��o: MEN_loginAluno
*
*  $ED Descri��o da fun��o
*		Realiza a busca da matricula do aluno. (n�o implementado)
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: Rertona 1, se foi encontrado a matricula.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	int MEN_loginAluno ( unsigned int * matricula ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_adicionaAluno
*
*  $ED Descri��o da fun��o
*		
*Par�mentros: endere�o da matricula que ser� recebida pelo usuario.
***********************************************************************/

	void MEN_adicionaAluno ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_modificaAluno
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/

	void MEN_modificaAluno ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_adiocionaProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_adicionaProfessor ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_modificaProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_modificaProfessor ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_removeProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeProfessor ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_removeProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeTodosProfessores ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_removeProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_adicionaDisciplina ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_removeProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/
	
	void MEN_modificaDisciplina ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_removeProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeDisciplina ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_removeProfessor
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeTodasDisciplinas ( void ) ;

/***********************************************************************
*
*  $FC Fun��o: MEN_menuGradeCurricular
*
*  $ED Descri��o da fun��o
*		
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_menuGradeCurricular ( void ) ;

/********** Fim do m�dulo de defini��o: M�dulo Menu **********/
