/***************************************************************************
*
*  $MCD Módulo de definição: Módulo AlunoMat
*
*  Arquivo gerado:              AluMat.h
*  Letras identificadoras:      AMT
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
*     0.01    Flávio   23/10/2017	Início do desenvolvimento
*	  1.0     Flávio   07/11/2017	Produto final para entrega	
*
*  $ED Descrição do módulo
*     Este módulo implementa e manipula a struct AluMat do Sistema Acadêmico a ser *desenvolvido.
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
*			Para que outros módulos conheçam a existencia da struct.
*
***********************************************************************/
typedef struct ParAluGrad parAluGrad;
typedef struct aluMat AluMat;



/***********************************************************************
*
*  $TC Tipo de dados: ALU Condições de retorno
*
*
***********************************************************************/
typedef enum {
	AMT_CondRetOK,	// Executou corretamente
	AMT_CondRetAlunoNaoExiste,	// O aluno não existe
	AMT_CondRetTurmaNaoExiste,	// A turma não existe
	AMT_CondRetDisciplinaNaoEncontrada,// A disciplina não foi encontrada na grade do aluno
	AMT_CondRetDisciplinaJaCursada, //A disciplina já foi cursada
	AMT_CondRetPreRequisitosPendentes, //Pré-requisitos não cumpridos
	AMT_CondRetFaltouMemoria, //Faltou memória ao alocar.
	AMT_CondRetAlunoJaCadastrado, // Aluno já está cadastrado
	AMT_CondRetLimiteDeCredUlt, // Limite de 30 créditos foi ultrapassado.
	AMT_CondRetErro, //Erro. 
} AMT_tpCondRet;

/***********************************************************************
*
*  $FC Função: AMT cria
*
*  $ED Descrição da função
*		Cria a lista de alunos matriculados.
*
*	$EP Parâmetros
*	  $P Não há
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetNaoHaMemoria
*
*  Assertiva de Entrada:
*		-Não há assertivas de entrada.
*  Assertiva de Saída:
*		-Lista de alunos matrículados vazia
*		-Lista não é criada caso não haja espaço suficiente em memória, e retorna condição de erro.
*
*************************************************************************/
AMT_tpCondRet AMT_cria(void);
/***********************************************************************
*
*  $FC Função: AMT matricula
*
*  $ED Descrição da função
*		Matricula um Aluno em uma turma de uma disciplina.
*
*  $EP Parâmetros
*	  $P mat			-matrícula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-código da disciplina em que o aluno deve ser matriculado.
*	  $P codTurma		-código da turma da disciplina em que o aluno deve ser matriculado.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*	  AMT_CondRetLimiteDeCredUlt
*	  AMT_CondRetTurmaNaoExiste
*
*  Assertiva de Entrada:
*		-As assertivas de entrada são os dados de matrícula do aluno, código da disciplina e turma em que o mesmo deve ser matriculado.
*  Assertiva de Saída:
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro não exista.
*		-Retorna erro caso a disciplina cujo código foi passado como parâmetro não exista.
*		-Retorna erro caso a turma cujo código foi passado como parâmetro não exista.
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro já tenha excedido seu limite de créditos no período.
*		-Aluno é matriculado na turma da disciplina em questão, tendo sua grade alterada.
*************************************************************************/
AMT_tpCondRet AMT_matriculaNaDisc(unsigned int mat, char* codDisciplina, char* codTurma);
/***********************************************************************
*
*  $FC Função: AMT altera faltas
*
*  $ED Descrição da função
*		Altera as faltas de um aluno em uma disciplina dado o código dela.
*
*  $EP Parâmetros
*	  $P mat			-matrícula do aluno que deve ser matriculado na disciplina.
*	  $P faltas			-número de faltas que deve ser atríbuido ao aluno.
*	  $P codDisciplina	-código da disciplina em que deve ser alteradas as faltas do aluno.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetDisciplinaNaoEncontrada
*
*  Assertiva de Entrada:
*		-As assertivas de entrada são os dados de matrícula do aluno, código da disciplina e número de faltas do aluno.
*  Assertiva de Saída:
*		-Retorna erro caso a disciplina cujo código foi passado como parâmetro não exista.
*		-Aluno tem suas faltas alteradas na disciplina em questão.
*
*************************************************************************/
AMT_tpCondRet AMT_alteraFaltas(unsigned int mat, int faltas, char* codDisciplina);
/***********************************************************************
*
*  $FC Função: AMT retira disciplina
*
*  $ED Descrição da função
*		Remove uma disciplina da grade de horario de um aluno.
*
*  $EP Parâmetros
*	  $P mat			-matrícula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-código da disciplina em que o aluno deve ser matriculado.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*
*  Assertiva de Entrada:
*		-As assertivas de entrada são os dados de matrícula do aluno e código da disciplina a ser removida.
*  Assertiva de Saída:
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro não exista.
*		-Retorna erro caso a disciplina cujo código foi passado como parâmetro não exista.
*		-Aluno é removido da disciplina em questão.
*
*************************************************************************/
AMT_tpCondRet AMT_retiraDisc(unsigned int mat, char* codDisciplina);

/***********************************************************************
*
*  $FC Função: AMT Busca Aluno
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade), para ver se este está matriculado em alguma disciplina.
*
*  $EP Parâmetros
*	  $P mat				-matrícula do aluno que deve ser matriculado na disciplina.
*	  $P parAluGradeBuscado	-Nome do ponteiro em que será retornado, por referência, uma instância da estrutura parAluGrade.
*
*  $FV Valor retornado
*	  AMT_CondRetJaCadastrado
*	  AMT_CondRetAlunoNaoExiste
*
*  Assertiva de Entrada:
*		-As assertivas de entrada são os dados de matrícula do aluno e o endereço de memória de um ponteiro para retornar a estrutura parAluGrade.
*  Assertiva de Saída:
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro não exista.
*		-Retorna a estrutura parAluGrade, por referência, caso exista um aluno com a matrícula em questão na lista dos alunos matriculados.
*************************************************************************/
AMT_tpCondRet AMT_BuscaAluno(unsigned int matbusca, parAluGrad **parAluGradeBuscado);
/***********************************************************************
*
*  $FC Função: AMT Imprime Grade
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade) e imprime sua grade de horários completa.
*
*  $EP Parâmetros
*	  $P mat			-matrícula do aluno que deve ser matriculado na disciplina.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*
*  Assertiva de Entrada:
*		-A assertiva de entrada é a matrícula do aluno cuja grade deve ser impressa.
*  Assertiva de Saída:
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro não exista.
*		-Impressão na tela da grade do aluno com matricula igual a em questão.
*
*************************************************************************/
AMT_tpCondRet AMT_imprimeGrade(unsigned int mat);
/***********************************************************************
*
*  $FC Função: AMT insere Nota
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade), para inserir a nota.
*
*  $EP Parâmetros
*	  $P mat			-matrícula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-código da disciplina em que o aluno deve ser matriculado.
*	  $P g1				-nota do grau um
*	  $P g2				-nota do grau dois
*	  $P g3				-nota do grau três
*	  $p g4				-nota do grau quatro
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*	  AMT_CondRetNotaErrada
*
*  Assertiva de Entrada:
*		-As assertivas de entrada são os graus 1, 2, 3 e 4, número da matrícula do aluno cujos graus serão alterados e código da disciplina
*		 desses graus. Todos os graus são inicializados com -1. Caso o usuário não queira alterar todos os graus, deve passar como parâmetro "-1"
para os graus que não deseja alterar.
*  Assertiva de Saída:
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro não exista.
*		-Retorna erro caso a disciplina cujo código foi passado como parâmetro não exista.
*		-Retorna erro caso algum dos graus passados esteja fora dos padrões.
*		-Altera os graus do aluno cuja matricula foi passada referentes a disciplina em questão.
*
*************************************************************************/
AMT_tpCondRet AMT_insereNota(float g1, float g2, float g3, float g4, unsigned int mat, char* codDisciplina);
/***********************************************************************
*
*  $FC Função: AMT Altera Turma
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade), altera turma.
*
*  $EP Parâmetros
*	  $P mat			-matrícula do aluno que deve ser matriculado na disciplina.
*	  $P codDisciplina	-código da disciplina em que o aluno deve ser matriculado.
*	  $P codTurma		-código da turma da disciplina em que o aluno deve ser matriculado.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetErro
*	  AMT_CondRetAlunoNaoExiste
*	  AMT_CondRetDisciplinaNaoEncontrada
*	  AMT_CondRetTurmaNaoExiste
*
*  Assertiva de Entrada:
*		-As assertivas de entrada são os dados de matrícula do aluno, código de disciplina e turma em que o mesmo deve ser matriculado.
*  Assertiva de Saída:
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro não exista.
*		-Retorna erro caso a disciplina cujo código foi passado como parâmetro não exista.
*		-Retorna erro caso a turma cujo código foi passado como parâmetro não exista.
*		-Retorna erro caso não seja possível inserir o aluno na nova turma por falta de vagas ou conflito de horários.
*		-Aluno é matriculado na turma da disciplina em questão, tendo sua grade alterada.
**************************************************************************/
AMT_tpCondRet AMT_alteraTurma(unsigned int mat, char* codDisciplina, char* codTurma);
/***********************************************************************
*
*  $FC Função: AMT Deleta No
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade), e o deleta da lista.
*
*  $EP Parâmetros
*	  $P mat			-matrícula do aluno que deve ser matriculado na disciplina.
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*	  AMT_CondRetAlunoNaoExiste
*
*  Assertiva de Entrada:
*		-A assertiva de entrada é a matrícula do aluno a ser removido da lista.
*  Assertiva de Saída:
*		-Retorna erro caso o aluno cuja matrícula foi passada como parâmetro não exista.
*		-Aluno é removido da lista dos alunos matriculados.
**************************************************************************/
AMT_tpCondRet AMT_deletaNo(unsigned int mat);
/***********************************************************************
*
*  $FC Função: AMT Limpa
*
*  $ED Descrição da função
*		Remove todos os alunos da lista dos alunos matriculados e a apaga.
*
*  $EP Parâmetros
*	  $P Não há 
*
*  $FV Valor retornado
*	  AMT_CondRetOk
*
*  Assertiva de Entrada:
*		-A assertiva de entrada é a lista dos alunos matriculados, que é uma lista estática do módulo.
*  Assertiva de Saída:
*		-Todos os nós são removidos da lista e a mesma é desalocada.
**************************************************************************/
AMT_tpCondRet AMT_limpa (void);
#endif
