/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Aluno
*
*  Arquivo gerado:              Aluno.h
*  Letras identificadoras:      ALU
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 2
*  Autores:   Flávio Thiago Franco Vaz
*             Bruno Miranda Marinho
*             Matheus Henrique Branco Zeitune
*             João Victor Cerqueira
*             Vinícius Cortat
*  $HA Histórico de evolução:
*     Versão  Autor    Data			Observações
*     0.01    Flávio   01/10/2017	Início do desenvolvimento
*	  0.0
*
*  $ED Descrição do módulo
*     Este módulo implementa e manipula a struct Aluno do Sistema Acadêmico a ser desenvolvido.
***************************************************************************/

#ifndef ALUNO_H
#define ALUNO_H

/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros módulos conheçam a existencia da struct.
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
*			Para que outros módulos conheçam a existencia da struct.
*
***********************************************************************/
typedef struct endereco {
	char estado[51];
	char cidade[51];
	char bairro[32];
	char rua[81];
	char comp[32];
} Endereco;
/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros módulos conheçam a existencia da struct.
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
*  $TC Tipo de dados: ALU Condições de retorno
*
*
***********************************************************************/
typedef enum {
	ALN_CondRetOK,	// Executou corretamente
	ALN_CondRetAlunoNaoExiste,	// O aluno não existe
	ALN_CondRetFaltouMemoria	// Faltou memória ao alocar um aluno
} ALN_tpCondRet;
/***********************************************************************
*
*  $TD	Typedef 
*			Para que outros módulos conheçam a existencia da struct.
*
***********************************************************************/
typedef struct aluno Aluno;
/***********************************************************************
*
*  $FC Função: ALU cria
*
*  $ED Descrição da função
*		Cria um Aluno.
*
**********************************************************************************************************************************************/
/*Assertivas: Retorno da função: ALN_CondRetFaltouMemoria caso não haja memória para criar um Aluno e ALN_CondRetOK caso contrário. Retorna, por referência,
/								 um ponteiro para o Aluno criado.
/			 Parâmentros: O endereço de um ponteiro para Aluno(struct), uma string para nome, um ponteiro para CPF(struct) para cpf, um inteiro 
/                         para telefone,um ponteiro para Data(struct) para data de nascimento, e um ponteiro para Endereco(struct) para endereço.
************************************************************************************************************************************************/
ALN_tpCondRet ALU_CriaAluno(Aluno **a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);
/***********************************************************************
*
*  $FC Função: ALU deleta
*
*  $ED Descrição da função
*		Deleta um Aluno.
*
***************************************************************************************************/
/*Assertivas: Retorno da função: ALN_CondRetAlunoNaoExiste caso o endereço passado como parâmetro não
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contrário.
/			 Parâmentros: O endereço de um ponteiro para Aluno (struct).
****************************************************************************************************/
ALN_tpCondRet ALU_deletaAluno(Aluno** a);
/***********************************************************************
*
*  $FC Função: ALU altera
*
*  $ED Descrição da função
*		Altera dados de um Aluno.
*
***********************************************************************/
/*Assertivas: Retorno da função: ALN_CondRetAlunoNaoExiste caso o endereço passado como parâmetro não contenha um Aluno
/                              , ou seja NULL, e ALN_CondRetOK caso contrário.
/			 Parâmentros: Um ponteiro para Aluno(struct), uma string para nome, um ponteiro para CPF(struct) para cpf, um inteiro 
/                         para telefone,um ponteiro para Data(struct) para data de nascimento, e um ponteiro para Endereco(struct) para endereço.
************************************************************************************************************************************************/
ALN_tpCondRet ALU_AlteraDados(Aluno *a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);
/***********************************************************************
*
*  $FC Função: ALU GetMat
*
*  $ED Descrição da função
*		Retorna, por referência, a matrícula de um Aluno na variável mat.
*
***********************************************************************/
/*Assertivas: Retorno da função: ALN_CondRetAlunoNaoExiste caso o endereço passado como parâmetro não
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contrário. A função
/                                também retorna, por referência, o número de matrícula do Aluno apontado pelo
/								 ponteiro passado.
/			 Parâmentros: Um ponteiro para Aluno (struct) e o endereço de memória de um inteiro mat.
****************************************************************************************************/
ALN_tpCondRet ALU_GetMat(Aluno *a, unsigned int *mat);
/***********************************************************************
*
*  $FC Função: ALU GetNome
*
*  $ED Descrição da função
*		Retorna, por referência, o nome de um Aluno na variável nome.
*
***********************************************************************/
/*Assertivas: Retorno da função: ALN_CondRetAlunoNaoExiste caso o endereço passado como parâmetro não
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contrário. A função
/                                também retorna, por referência, a string nome do Aluno apontado pelo
/								 ponteiro passado.
/			 Parâmentros: Um ponteiro para Aluno (struct) e o endereço de memória de um inteiro mat.
****************************************************************************************************/
ALN_tpCondRet ALU_GetNome(Aluno *a, char* nome);
/***********************************************************************
*
*  $FC Função: ALU GetAll
*
*  $ED Descrição da função
*		Retorna, por referência, todos os dados de um Aluno nas variáveis passadas.
*
***********************************************************************/
/*Assertivas: Retorno da função: ALN_CondRetAlunoNaoExiste caso o endereço passado como parâmetro não
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contrário. A função
/                                também retorna, por referência, a string nome, o inteiro matrícula, a struct CPF, o inteiro telefone, a struct Data e Endereco, do Aluno apontado pelo
/								 ponteiro passado.
/			 Parâmentros: Um ponteiro para Aluno(struct), uma string para nome, um ponteiro para CPF(struct) para cpf, um inteiro 
/                         para telefone,um ponteiro para Data(struct) para data de nascimento, e um ponteiro para Endereco(struct) para endereço.
************************************************************************************************************************************************/
ALN_tpCondRet ALU_GetAll(Aluno *a, char *nome, unsigned int *mat, CPF *cpf, unsigned int *tel, Data *nasc, Endereco *endereco);
/***********************************************************************
*
*  $FC Função: ALU imprime
*
*  $ED Descrição da função
*		Imprime na tela todos os dados de um Aluno.
*
***********************************************************************/
/*Assertivas: Retorno da função: ALN_CondRetAlunoNaoExiste caso o endereço passado como parâmetro não
/                                contenha um Aluno, ou seja NULL, e ALN_CondRetOK caso contrário.
/			 Parâmentros: Um ponteiro para Aluno (struct).
****************************************************************************************************/
ALN_tpCondRet ALU_imprimeAluno(Aluno *a);
#endif
