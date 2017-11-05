/***************************************************************************
*
*  $MCI Módulo de Implementação: Módulo AlunoMat
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
*	  0.02    Bruno    03/11/2017   Atualização do Módulo
*	  0.02    Bruno    03/11/2017   Desenvolvimento de algumas funções
*
*  $ED Descrição do módulo
*     Este módulo implementa e manipula a struct AluMat do Sistema Acadêmico a ser *desenvolvido.
***************************************************************************/
#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996 ) 

#include <stdlib.h>
#include <stdio.h>
#include "AluMat.h"
#include "corpodiscente.h"
#include "Turma.h"
#include "GradeHorario.h"

#define LIMT_CRED 30

/*Início da função cria*/
/* Cria a lista de Alunos matriculados, onde serão inseridos os alunos que se matricularem em
pelo menos uma disciplina. */
AMT_tpCondRet AMT_cria(void) {

	// Aloco espaço para a lista de alunos matriculados.
	AluMatr = (AluMat*)malloc(sizeof(AluMat));
	// Se a lista não for criada com sucesso, retorno falha de memória.
	if (createList(&(AluMatr->AMT)) != LIS_CondRetOK) {
		return AMT_CondRetFaltouMemoria;
	}
	// Se tudo deu certo, retorno OK.
	return AMT_CondRetOK;
}
/*Fim da função*/

/*Início da função matriculaNaDisc*/
/*Recebe a matrícula de um aluno, busca essa matrícula nos alunos matriculados, se ele
não estiver matriculado em nenhuma disciplina, aloca memória e o insere na lista, e então
adiciona a disciplina à sua grade de horário na turma desejada. */
AMT_tpCondRet AMT_matriculaNaDisc(unsigned int mat, char* codDisciplina, char* codTurma) {

	Aluno* aln = NULL;
	CDI_tpCondRet retBuscaCDI;
	GRC_tpCondRet retBuscaGRC;
	AMT_tpCondRet retBuscaAMT;
	DIS_tpCondRet retBuscaDIS;
	parAluGrad* AluGrad;
	Disciplina* Disc;
	InfoGradeHorario* i = NULL;
	Turma* tur;
	int creditGRA, creditDIS;

	retBuscaCDI = CDI_busca(mat, &aln);		// Busco o aluno no corpo discente

	if (retBuscaCDI == CDI_CondRetAlunoNaoCadastrado) // Se o aluno não for encontrado
		return AMT_CondRetAlunoNaoExiste;

	retBuscaGRC = GRC_buscaPorCodigo(codDisciplina);
	GRC_devolveDisc((void**)&Disc); // Busco a disciplina, para pegar suas informações.
	if (retBuscaGRC == GRC_CondRetDisciplinaNaoEncontrada)
		return AMT_CondRetDisciplinaNaoEncontrada;

	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad);
	if (retBuscaAMT == AMT_CondRetAlunoNaoExiste) { // se o aluno ainda não existir no AMT, eu o insiro
		AluGrad = (parAluGrad*)malloc(sizeof(parAluGrad));
		AluGrad->aluno = aln;	// Referência a um aluno existente
		GRA_CriaGradeHorario(&(AluGrad->grade)); // Crio a grade de horário do aluno
		push_back(AluMatr->AMT, (void**)AluGrad); // Inserindo na lista
	}
	GRA_ConsultaCred(AluGrad->grade, &creditGRA);
	DIS_get_creditos(Disc, &creditDIS);
	if (creditGRA + creditDIS > LIMT_CRED) {	// Verifico se somando os créditos da disc a ser inserida, o aluno ultrapassa o limite de créditos
		return AMT_CondRetLimiteDeCredUlt;
	}

	retBuscaDIS = DIS_buscaTurma(Disc, codTurma, &tur);
	if (retBuscaDIS == DIS_CondRetTurmaNaoExiste) {
		return AMT_CondRetTurmaNaoExiste;
	}

	GRA_InsereGradeHorario(i, Disc, tur, AluGrad->grade); // Inserindo na grade de horário.

	return AMT_CondRetOK;
}
/*Fim da função*/

/*Início da função BuscaAluno*/
/*Recebe a matrícula de um aluno, busca essa matrícula nos alunos matriculados, e devolve
por referência o par Aluno-GradeHorario do referido aluno. */
AMT_tpCondRet AMT_BuscaAluno(unsigned int matbusca, parAluGrad** parAluGradeBuscado) {
	unsigned int mat2 = 0, i, size;
	parAluGrad* parAluGrade = NULL;
	list_size(AluMatr->AMT, &size);	// Pego o tamanho da lista
	first(AluMatr->AMT);	// Seto a lista para o primeiro nó
	for (i = 0;i < size; i++) {
		get_val_cursor(AluMatr->AMT, (void**)&parAluGrade);	// Pego o par aluno-grade atual
		ALU_GetMat(parAluGrade->aluno, &mat2);	// Pego a matrícula do aluno
		if (matbusca == mat2) {	// Vejo se a matrícula é igual à de busca
			*parAluGradeBuscado = parAluGrade;
			return AMT_CondRetAlunoJaCadastrado;	// se for, retorno ele.
		}
		next(AluMatr->AMT); // caso não seja, vou para o próximo
	}
	return AMT_CondRetAlunoNaoExiste;	// Não encontrei
}
/*Fim da função*/

/*Início da função alteraFaltas*/
/*Recebe uma matricula de aluno, o código de uma disciplina e o número de faltas a alterar
na mesma, busca pelo aluno e altera as faltas na disciplina informada. */
AMT_tpCondRet AMT_alteraFaltas(unsigned int mat, int faltas, char* codDisciplina) {
	InfoGradeHorario* disProcurada;
	parAluGrad *AluGrad;
	AMT_BuscaAluno(mat, &AluGrad);
	disProcurada = GRA_BuscaGradeHorario(AluGrad->grade, codDisciplina);
	if (disProcurada == NULL) {
		return AMT_CondRetDisciplinaNaoEncontrada;
	}
	GRA_AlteraFaltas(AluGrad->grade, codDisciplina, faltas);
	return AMT_CondRetOK;
}
/*Fim da função*/

/*Início da função alteraFaltas*/
/*Recebe uma matricula de um aluno o código de uma disciplina e o código da turma,
busca por ele nos alunos matriculados,e retira a disciplina da grade de horario do aluno,
se ela constar em sua grade. */
AMT_tpCondRet AMT_retiraDisc(unsigned int mat, char* codDisciplina) {
	AMT_tpCondRet retBuscaAMT;
	GRA_tpCondRet retEliminaGRA;
	parAluGrad *AluGrad;

	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad);
	if (retBuscaAMT == AMT_CondRetAlunoNaoExiste)
		return AMT_CondRetAlunoNaoExiste;

	retEliminaGRA = GRA_EliminaNo(AluGrad->grade, codDisciplina);
	if (retEliminaGRA == GRA_CondRetDisciplinaNaoEncontrada)
		return AMT_CondRetDisciplinaNaoEncontrada;
	return AMT_CondRetOK;
}
/*Fim da função*/

/*Início da função imprimeGrade*/
/*Recebe a matrícula de um aluno e imprime a sua grade de horários completa. */
AMT_tpCondRet AMT_imprimeGrade(unsigned int mat) {
	parAluGrad *AluGrad;
	AMT_tpCondRet retBuscaAMT;
	char nome[81];

	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad);
	if (retBuscaAMT == AMT_CondRetAlunoNaoExiste) {
		return AMT_CondRetAlunoNaoExiste;
	}
	ALU_GetNome(AluGrad->aluno, nome);
	printf("Nome do Aluno: %s\n", nome);
	printf("Matricula: %u\n", mat);
	GRA_ExibeGradeHorario(AluGrad->grade);
	return AMT_CondRetOK;
}
/*Fim da função*/

/*Início da função alteraTurma*/
/* Fazer descrição */
AMT_tpCondRet AMT_alteraTurma(unsigned int mat, char* codDisciplina, char* codTurma) {
	parAluGrad* AluGrad;
	Disciplina* Disc;
	Turma *turma;
	InfoGradeHorario *i = NULL;
	AMT_BuscaAluno(mat, &AluGrad); // Busca para saber se aluno está matrículado em alguma disciplina.
	if (GRA_BuscaGradeHorario(AluGrad->grade, codDisciplina) == NULL)// Busca para saber se o aluno está matriculado naquela disciplina.
		return AMT_CondRetDisciplinaNaoEncontrada;
	GRC_buscaPorCodigo(codDisciplina); //Busca Disciplina
	GRC_devolveDisc((void**)&Disc); //Recebe por referência o ponteiro para Disciplina
	if (DIS_buscaTurma(Disc, codTurma, &turma) == DIS_CondRetTurmaNaoExiste)
		return AMT_CondRetTurmaNaoExiste;
	GRA_EliminaNo(AluGrad->grade, codDisciplina); //Removo da turma inicial da disciplina.
	if (GRA_InsereGradeHorario(i, Disc, turma, AluGrad->grade) == GRA_CondRetOk)//
		return AMT_CondRetOK;
	else
		return AMT_CondRetErro;
}
/*Fim da função*/


/*Início da função insereNota*/
/* Fazer descrição */
AMT_tpCondRet AMT_insereNota(float g1, float g2, float g3, float g4, unsigned int mat, char* codDisciplina) {
	parAluGrad* AluGrad;
	AMT_tpCondRet retBuscaAMT;
	float nota[4];
	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad); // Busca para saber se aluno está matrículado em alguma disciplina.
	if (retBuscaAMT == AMT_CondRetAlunoNaoExiste)
		return AMT_CondRetAlunoNaoExiste;
	nota[0] = g1;
	nota[1] = g2;
	nota[2] = g3;
	nota[3] = g4;
	if (GRA_AlteraNota(AluGrad->grade, codDisciplina, nota) == GRA_CondRetDisciplinaNaoEncontrada)
		return AMT_CondRetDisciplinaNaoEncontrada;
	return AMT_CondRetOK;
}
/*Fim da função*/
