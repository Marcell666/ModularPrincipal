/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo AlunoMat
*
*  Arquivo gerado:              AluMat.h
*  Letras identificadoras:      AMT
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
*     0.01    Fl�vio   23/10/2017	In�cio do desenvolvimento
*	  1.0     Fl�vio   07/11/2017	Produto final para entrega	
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa e manipula a struct AluMat do Sistema Acad�mico a ser *desenvolvido.
***************************************************************************/

#ifndef ALUMAT_H
#define ALUMAT_H

#include "aluno.h"
#include "listas.h"
#include "gradehorario.h"
#include "gradeCurricular.h"

/***********************************************************************
*
*  $TD	Typedef
*			Para que outros m�dulos conhe�am a existencia da struct.
*
***********************************************************************/
typedef struct ParAluGrad parAluGrad;
typedef struct aluMat AluMat;



/***********************************************************************
*
*  $TC Tipo de dados: ALU Condi��es de retorno
*
*
***********************************************************************/
typedef enum {
	AMT_CondRetOK,	// Executou corretamente
	AMT_CondRetAlunoNaoExiste,	// O aluno n�o existe
	AMT_CondRetTurmaNaoExiste,	// A turma n�o existe
	AMT_CondRetDisciplinaNaoEncontrada,// A disciplina n�o foi encontrada na grade do aluno
	AMT_CondRetDisciplinaJaCursada, //A disciplina j� foi cursada
	AMT_CondRetPreRequisitosPendentes, //Pr�-requisitos n�o cumpridos
	AMT_CondRetFaltouMemoria, //Faltou mem�ria ao alocar.
	AMT_CondRetAlunoJaCadastrado, // Aluno j� est� cadastrado
	AMT_CondRetLimiteDeCredUlt, // Limite de 30 cr�ditos foi ultrapassado.
	AMT_CondRetErro, //Erro. 
} AMT_tpCondRet;

/***********************************************************************
*
*  $FC Fun��o: AMT cria
*
*  $ED Descri��o da fun��o
*		Cria a lista de alunos matriculados.
*
*	$EP Par�metros
*	  $P N�o h�
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetNaoHaMemoria
*
*  Assertiva de Entrada:
*		-N�o h� assertivas de entrada.
*  Assertiva de Sa�da:
*		-Lista de alunos matr�culados vazia
*		-Lista n�o � criada caso n�o haja espa�o suficiente em mem�ria, e retorna condi��o de erro.
*
*************************************************************************/
AMT_tpCondRet AMT_cria(void);
/***********************************************************************
*
*  $FC Fun��o: AMT matricula
*
*  $ED Descri��o da fun��o
*		Matricula um Aluno em uma turma de uma disciplina.
*
*  $EP Par�metros
*	  $P mat			-matr�cula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-c�digo da disciplina em que o aluno deve ser matriculado.
*	  $P codTurma		-c�digo da turma da disciplina em que o aluno deve ser matriculado.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*	  AMT_CondRetLimiteDeCredUlt
*	  AMT_CondRetTurmaNaoExiste
*
*  Assertiva de Entrada:
*		-As assertivas de entrada s�o os dados de matr�cula do aluno, c�digo da disciplina e turma em que o mesmo deve ser matriculado.
*  Assertiva de Sa�da:
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro n�o exista.
*		-Retorna erro caso a disciplina cujo c�digo foi passado como par�metro n�o exista.
*		-Retorna erro caso a turma cujo c�digo foi passado como par�metro n�o exista.
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro j� tenha excedido seu limite de cr�ditos no per�odo.
*		-Aluno � matriculado na turma da disciplina em quest�o, tendo sua grade alterada.
*************************************************************************/
AMT_tpCondRet AMT_matriculaNaDisc(unsigned int mat, char* codDisciplina, char* codTurma);
/***********************************************************************
*
*  $FC Fun��o: AMT altera faltas
*
*  $ED Descri��o da fun��o
*		Altera as faltas de um aluno em uma disciplina dado o c�digo dela.
*
*  $EP Par�metros
*	  $P mat			-matr�cula do aluno que deve ser matriculado na disciplina.
*	  $P faltas			-n�mero de faltas que deve ser atr�buido ao aluno.
*	  $P codDisciplina	-c�digo da disciplina em que deve ser alteradas as faltas do aluno.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetDisciplinaNaoEncontrada
*
*  Assertiva de Entrada:
*		-As assertivas de entrada s�o os dados de matr�cula do aluno, c�digo da disciplina e n�mero de faltas do aluno.
*  Assertiva de Sa�da:
*		-Retorna erro caso a disciplina cujo c�digo foi passado como par�metro n�o exista.
*		-Aluno tem suas faltas alteradas na disciplina em quest�o.
*
*************************************************************************/
AMT_tpCondRet AMT_alteraFaltas(unsigned int mat, int faltas, char* codDisciplina);
/***********************************************************************
*
*  $FC Fun��o: AMT retira disciplina
*
*  $ED Descri��o da fun��o
*		Remove uma disciplina da grade de horario de um aluno.
*
*  $EP Par�metros
*	  $P mat			-matr�cula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-c�digo da disciplina em que o aluno deve ser matriculado.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*
*  Assertiva de Entrada:
*		-As assertivas de entrada s�o os dados de matr�cula do aluno e c�digo da disciplina a ser removida.
*  Assertiva de Sa�da:
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro n�o exista.
*		-Retorna erro caso a disciplina cujo c�digo foi passado como par�metro n�o exista.
*		-Aluno � removido da disciplina em quest�o.
*
*************************************************************************/
AMT_tpCondRet AMT_retiraDisc(unsigned int mat, char* codDisciplina);

/***********************************************************************
*
*  $FC Fun��o: AMT Busca Aluno
*
*  $ED Descri��o da fun��o
*		Busca um aluno na lista de pares (aluno-grade), para ver se este est� matriculado em alguma disciplina.
*
*  $EP Par�metros
*	  $P mat				-matr�cula do aluno que deve ser matriculado na disciplina.
*	  $P parAluGradeBuscado	-Nome do ponteiro em que ser� retornado, por refer�ncia, uma inst�ncia da estrutura parAluGrade.
*
*  $FV Valor retornado
*	  AMT_CondRetJaCadastrado
*	  AMT_CondRetAlunoNaoExiste
*
*  Assertiva de Entrada:
*		-As assertivas de entrada s�o os dados de matr�cula do aluno e o endere�o de mem�ria de um ponteiro para retornar a estrutura parAluGrade.
*  Assertiva de Sa�da:
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro n�o exista.
*		-Retorna a estrutura parAluGrade, por refer�ncia, caso exista um aluno com a matr�cula em quest�o na lista dos alunos matriculados.
*************************************************************************/
AMT_tpCondRet AMT_BuscaAluno(unsigned int matbusca, parAluGrad **parAluGradeBuscado);
/***********************************************************************
*
*  $FC Fun��o: AMT Imprime Grade
*
*  $ED Descri��o da fun��o
*		Busca um aluno na lista de pares (aluno-grade) e imprime sua grade de hor�rios completa.
*
*  $EP Par�metros
*	  $P mat			-matr�cula do aluno que deve ser matriculado na disciplina.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*
*  Assertiva de Entrada:
*		-A assertiva de entrada � a matr�cula do aluno cuja grade deve ser impressa.
*  Assertiva de Sa�da:
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro n�o exista.
*		-Impress�o na tela da grade do aluno com matricula igual a em quest�o.
*
*************************************************************************/
AMT_tpCondRet AMT_imprimeGrade(unsigned int mat);
/***********************************************************************
*
*  $FC Fun��o: AMT insere Nota
*
*  $ED Descri��o da fun��o
*		Busca um aluno na lista de pares (aluno-grade), para inserir a nota.
*
*  $EP Par�metros
*	  $P mat			-matr�cula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-c�digo da disciplina em que o aluno deve ser matriculado.
*	  $P g1				-nota do grau um
*	  $P g2				-nota do grau dois
*	  $P g3				-nota do grau tr�s
*	  $p g4				-nota do grau quatro
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*	  AMT_CondRetNotaErrada
*
*  Assertiva de Entrada:
*		-As assertivas de entrada s�o os graus 1, 2, 3 e 4, n�mero da matr�cula do aluno cujos graus ser�o alterados e c�digo da disciplina
*		 desses graus. Todos os graus s�o inicializados com -1. Caso o usu�rio n�o queira alterar todos os graus, deve passar como par�metro "-1"
para os graus que n�o deseja alterar.
*  Assertiva de Sa�da:
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro n�o exista.
*		-Retorna erro caso a disciplina cujo c�digo foi passado como par�metro n�o exista.
*		-Retorna erro caso algum dos graus passados esteja fora dos padr�es.
*		-Altera os graus do aluno cuja matricula foi passada referentes a disciplina em quest�o.
*
*************************************************************************/
AMT_tpCondRet AMT_insereNota(float g1, float g2, float g3, float g4, unsigned int mat, char* codDisciplina);
/***********************************************************************
*
*  $FC Fun��o: AMT Altera Turma
*
*  $ED Descri��o da fun��o
*		Busca um aluno na lista de pares (aluno-grade), altera turma.
*
*  $EP Par�metros
*	  $P mat			-matr�cula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-c�digo da disciplina em que o aluno deve ser matriculado.
*	  $P codTurma		-c�digo da turma da disciplina em que o aluno deve ser matriculado.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetErro
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*	  AMT_CondRetTurmaNaoExiste
*
*  Assertiva de Entrada:
*		-As assertivas de entrada s�o os dados de matr�cula do aluno, c�digo de disciplina e turma em que o mesmo deve ser matriculado.
*  Assertiva de Sa�da:
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro n�o exista.
*		-Retorna erro caso a disciplina cujo c�digo foi passado como par�metro n�o exista.
*		-Retorna erro caso a turma cujo c�digo foi passado como par�metro n�o exista.
*		-Retorna erro caso n�o seja poss�vel inserir o aluno na nova turma por falta de vagas ou conflito de hor�rios.
*		-Aluno � matriculado na turma da disciplina em quest�o, tendo sua grade alterada.
**************************************************************************/
AMT_tpCondRet AMT_alteraTurma(unsigned int mat, char* codDisciplina, char* codTurma);
/***********************************************************************
*
*  $FC Fun��o: AMT Deleta No
*
*  $ED Descri��o da fun��o
*		Busca um aluno na lista de pares (aluno-grade), e o deleta da lista.
*
*  $EP Par�metros
*	  $P mat			-matr�cula do aluno que deve ser matriculado na disciplina.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*
*  Assertiva de Entrada:
*		-A assertiva de entrada � a matr�cula do aluno a ser removido da lista.
*  Assertiva de Sa�da:
*		-Retorna erro caso o aluno cuja matr�cula foi passada como par�metro n�o exista.
*		-Aluno � removido da lista dos alunos matriculados.
**************************************************************************/
AMT_tpCondRet AMT_deletaNo(unsigned int mat);
/***********************************************************************
*
*  $FC Fun��o: AMT Limpa
*
*  $ED Descri��o da fun��o
*		Remove todos os alunos da lista dos alunos matriculados e a apaga.
*
*  $EP Par�metros
*	  $P N�o h� 
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*
*  Assertiva de Entrada:
*		-A assertiva de entrada � a lista dos alunos matriculados, que � uma lista est�tica do m�dulo.
*  Assertiva de Sa�da:
*		-Todos os n�s s�o removidos da lista e a mesma � desalocada.
**************************************************************************/
AMT_tpCondRet AMT_limpa (void);
#endif
