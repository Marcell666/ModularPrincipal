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
*
*
*  $ED Descrição do módulo
*     Este módulo implementa e manipula a struct AluMat do Sistema Acadêmico a ser *desenvolvido.
***************************************************************************/
#pragma once

#ifndef ALUMAT_H
#define ALUMAT_H

#include "aluno.h"
#include "listas.h"
#include "GradeHorario.h"
#include "GradeCurricular.h"

/***********************************************************************
*
*  $TD	Typedef
*			Para que outros módulos conheçam a existencia da struct.
*
***********************************************************************/
typedef struct ParAluGrad {
	Aluno* aluno;
	GradeHorario* grade; //Checar nome da struct da grade de horário
}parAluGrad;

typedef struct AluMat {
	List* AMT;
}AluMat;

static AluMat *AluMatr;

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
	AMT_CondRetErro //Erro 
} AMT_tpCondRet;

/***********************************************************************
*
*  $FC Função: AMT cria
*
*  $ED Descrição da função
*		Cria a lista de alunos matriculados.
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
*************************************************************************/
AMT_tpCondRet AMT_matriculaNaDisc(unsigned int mat, char* codDisciplina, char* codTurma);
/***********************************************************************
*
*  $FC Função: AMT altera faltas
*
*  $ED Descrição da função
*		Altera as faltas de um aluno em uma disciplina dado o código dela.
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
*************************************************************************/
AMT_tpCondRet AMT_retiraDisc(unsigned int mat, char* codDisciplina);

/***********************************************************************
*
*  $FC Função: AMT Busca Aluno
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade), para ver se este está matriculado em alguma disciplina.
*
*************************************************************************/
AMT_tpCondRet AMT_BuscaAluno(unsigned int matbusca, parAluGrad **parAluGradeBuscado);
/***********************************************************************
*
*  $FC Função: AMT Imprime Grade
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade) e imprime sua grade de horários completa.
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
*************************************************************************/
AMT_tpCondRet AMT_insereNota(float g1, float g2, float g3, float g4, unsigned int mat, char* codDisciplina);
/***********************************************************************
*
*  $FC Função: AMT Altera Turma
*
*  $ED Descrição da função
*		Busca um aluno na lista de pares (aluno-grade), altera turma.
*
*************************************************************************/
AMT_tpCondRet AMT_alteraTurma(unsigned int mat, char* codDisciplina, char* codTurma);
#endif
