/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Aluno
*
*  Arquivo gerado:              Aluno.h
*  Letras identificadoras:      ALU
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acad�mico da turma 3WB
*  Gestor:  Grupo 2
*  Autores:   Fl�vio Thiago Franco Vaz
*             Bruno Miranda Marinho
*             Matheus Henrique Branco Zeitune
*             Jo�o Victor Cerqueira
*             Vin�cius Cortat
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data			Observa��es
*     0.01    Fl�vio   01/10/2017	In�cio do desenvolvimento
*	  0.0
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa e manipula a struct Aluno do Sistema Acad�mico a ser desenvolvido.
***************************************************************************/

#ifndef ALUNO_H
#define ALUNO_H

#define  ALN_TAM_STRING  81
#define  ALN_TAM_UF 3

/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros m�dulos conhe�am a existencia da struct.
*
***********************************************************************/
typedef struct data {
	int dia;
	int mes;
	int ano;
} Data;
/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros m�dulos conhe�am a existencia da struct.
*
***********************************************************************/
typedef struct endereco {
	char estado[ALN_TAM_UF];
	char cidade[ALN_TAM_STRING];
	char bairro[ALN_TAM_STRING];
	char rua[ALN_TAM_STRING];
	int numero;
	char comp[ALN_TAM_STRING];
} Endereco;
/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros m�dulos conhe�am a existencia da struct.
*
***********************************************************************/
typedef struct cpf {
	int dig1;
	int dig2;
	int dig3;
	int cod;
} CPF;

/***********************************************************************
*
*  $TC Tipo de dados: ALU Condi��es de retorno
*
*
***********************************************************************/
typedef enum {
	ALN_CondRetOK,	// Executou corretamente
	ALN_CondRetAlunoNaoExiste,	// O aluno n�o existe
	ALN_CondRetFaltouMemoria,	// Faltou mem�ria ao alocar um aluno
	ALN_CondRetErroAbrirArquivo
		/* Condicao de Retorno Erro Abrir Arquivo, usada quando ocorrer erro ao abrir arquivo com os dados pessoais dos alunos. */
} ALN_tpCondRet;
/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros m�dulos conhe�am a existencia da struct.
*
***********************************************************************/
typedef struct aluno Aluno;
/***********************************************************************
*
*  $FC Fun��o: ALU cria
*
*  $ED Descri��o da fun��o
*		Cria um Aluno.
*
**********************************************************************************************************************************************/
/*Assertivas: Retorno da fun��o: ALN_CondRetFaltouMemoria caso n�o haja mem�ria para criar um Aluno e ALN_CondRetOK caso contr�rio. Retorna, por refer�ncia,
/								 um ponteiro para o Aluno criado.
/			 Par�mentros: O endere�o de um ponteiro para Aluno(struct), uma string para nome, um ponteiro para CPF(struct) para cpf, um inteiro 
/                         para telefone,um ponteiro para Data(struct) para data de nascimento, e um ponteiro para Endereco(struct) para endere�o.
************************************************************************************************************************************************/
ALN_tpCondRet ALU_CriaAluno(Aluno **a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);
/***********************************************************************
*
*  $FC Fun��o: ALU deleta
*
*  $ED Descri��o da fun��o
*		Deleta um Aluno.
*
***************************************************************************************************/
/*Assertivas: Retorno da fun��o: ALN_CondRetAlunoNaoExiste caso o endere�o passado como par�metro n�o
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contr�rio.
/			 Par�mentros: O endere�o de um ponteiro para Aluno (struct).
****************************************************************************************************/
ALN_tpCondRet ALU_deletaAluno(Aluno** a);
/***********************************************************************
*
*  $FC Fun��o: ALU altera
*
*  $ED Descri��o da fun��o
*		Altera dados de um Aluno.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: ALN_CondRetAlunoNaoExiste caso o endere�o passado como par�metro n�o contenha um Aluno
/                              , ou seja NULL, e ALN_CondRetOK caso contr�rio.
/			 Par�mentros: Um ponteiro para Aluno(struct), uma string para nome, um ponteiro para CPF(struct) para cpf, um inteiro 
/                         para telefone,um ponteiro para Data(struct) para data de nascimento, e um ponteiro para Endereco(struct) para endere�o.
************************************************************************************************************************************************/
ALN_tpCondRet ALU_AlteraDados(Aluno *a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);
/***********************************************************************
*
*  $FC Fun��o: ALU GetMat
*
*  $ED Descri��o da fun��o
*		Retorna, por refer�ncia, a matr�cula de um Aluno na vari�vel mat.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: ALN_CondRetAlunoNaoExiste caso o endere�o passado como par�metro n�o
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contr�rio. A fun��o
/                                tamb�m retorna, por refer�ncia, o n�mero de matr�cula do Aluno apontado pelo
/								 ponteiro passado.
/			 Par�mentros: Um ponteiro para Aluno (struct) e o endere�o de mem�ria de um inteiro mat.
****************************************************************************************************/
ALN_tpCondRet ALU_GetMat(Aluno *a, unsigned int *mat);
/***********************************************************************
*
*  $FC Fun��o: ALU GetNome
*
*  $ED Descri��o da fun��o
*		Retorna, por refer�ncia, o nome de um Aluno na vari�vel nome.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: ALN_CondRetAlunoNaoExiste caso o endere�o passado como par�metro n�o
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contr�rio. A fun��o
/                                tamb�m retorna, por refer�ncia, a string nome do Aluno apontado pelo
/								 ponteiro passado.
/			 Par�mentros: Um ponteiro para Aluno (struct) e o endere�o de mem�ria de um inteiro mat.
****************************************************************************************************/
ALN_tpCondRet ALU_GetNome(Aluno *a, char* nome);
/***********************************************************************
*
*  $FC Fun��o: ALU GetAll
*
*  $ED Descri��o da fun��o
*		Retorna, por refer�ncia, todos os dados de um Aluno nas vari�veis passadas.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: ALN_CondRetAlunoNaoExiste caso o endere�o passado como par�metro n�o
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contr�rio. A fun��o
/                                tamb�m retorna, por refer�ncia, a string nome, o inteiro matr�cula, a struct CPF, o inteiro telefone, a struct Data e Endereco, do Aluno apontado pelo
/								 ponteiro passado.
/			 Par�mentros: Um ponteiro para Aluno(struct), uma string para nome, um ponteiro para CPF(struct) para cpf, um inteiro 
/                         para telefone,um ponteiro para Data(struct) para data de nascimento, e um ponteiro para Endereco(struct) para endere�o.
************************************************************************************************************************************************/
ALN_tpCondRet ALU_GetAll(Aluno *a, char *nome, unsigned int *mat, CPF *cpf, unsigned int *tel, Data *nasc, Endereco *endereco);
/***********************************************************************
*
*  $FC Fun��o: ALU imprime
*
*  $ED Descri��o da fun��o
*		Imprime na tela todos os dados de um Aluno.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: ALN_CondRetAlunoNaoExiste caso o endere�o passado como par�metro n�o
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contr�rio.
/			 Par�mentros: Um ponteiro para Aluno (struct).
****************************************************************************************************/
ALN_tpCondRet ALU_imprimeAluno(Aluno *a);


	ALN_tpCondRet ALN_salvaDados ( Aluno * alu, FILE *f ) ;


#endif
