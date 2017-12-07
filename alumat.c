/***************************************************************************
*
*  $MCI M�dulo de Implementa��o: M�dulo AlunoMat
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
*	  0.02    Bruno    03/11/2017   Atualiza��o do M�dulo
*	  0.02    Bruno    03/11/2017   Desenvolvimento de algumas fun��es
*	  1.0	  Fl�vio   06/11/2017	Produto final para entrega	
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa e manipula a struct AluMat do Sistema Acad�mico a ser *desenvolvido.
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "alumat.h"
#include "corpodiscente.h"

#define LIMT_CRED 30

/***********************************************************************
*
*  $TC Tipo de dados: Aluno Matriculado
*
*
*  $ED Descri��o do tipo
*     Estrutura principal que armazena os dados de um aluno matriculado ao qual este m�dulo se dedica.
*
***********************************************************************/

struct ParAluGrad {
	Aluno* aluno;
	GradeHorario* grade; //Checar nome da struct da grade de hor�rio
};

struct aluMat {
	List* AMT;
};

static AluMat *AluMatr;

/*In�cio da fun��o cria*/
/* Cria a lista de Alunos matriculados, onde ser�o inseridos os alunos que se matricularem em
pelo menos uma disciplina. */
AMT_tpCondRet AMT_cria(void) {

	// Aloco espa�o para a lista de alunos matriculados.
	AluMatr = (AluMat*)malloc(sizeof(AluMat));
	// Se a lista n�o for criada com sucesso, retorno falha de mem�ria.
	if (createList(&AluMatr->AMT) != LIS_CondRetOK) {
		return AMT_CondRetFaltouMemoria;
	}
	// Se tudo deu certo, retorno OK.
	return AMT_CondRetOK;
}
/*Fim da fun��o*/

/*In�cio da fun��o matriculaNaDisc*/
/*Recebe a matr�cula de um aluno, busca essa matr�cula nos alunos matriculados, se ele
n�o estiver matriculado em nenhuma disciplina, aloca mem�ria e o insere na lista, e ent�o
adiciona a disciplina � sua grade de hor�rio na turma desejada. */
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

	if (retBuscaCDI == CDI_CondRetAlunoNaoCadastrado){ // Se o aluno n�o for encontrado
		return AMT_CondRetAlunoNaoExiste;
	}

	retBuscaGRC = GRC_buscaPorCodigo(codDisciplina);
	GRC_devolveDisc((void**)&Disc); // Busco a disciplina, para pegar suas informa��es.
	if (retBuscaGRC == GRC_CondRetDisciplinaNaoEncontrada){
		return AMT_CondRetDisciplinaNaoEncontrada;
	}

	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad);
	if (retBuscaAMT == AMT_CondRetAlunoNaoExiste) { // se o aluno ainda n�o existir no AMT, eu o insiro
		AluGrad = (parAluGrad*)malloc(sizeof(parAluGrad));
		AluGrad->aluno = aln;	// Refer�ncia a um aluno existente
		GRA_CriaGradeHorario(&(AluGrad->grade)); // Crio a grade de hor�rio do aluno
		push_back(AluMatr->AMT, (void**)AluGrad); // Inserindo na lista
	}
	GRA_ConsultaCred(AluGrad->grade, &creditGRA);
	DIS_get_creditos(Disc, &creditDIS);
	if (creditGRA + creditDIS > LIMT_CRED) {	// Verifico se somando os cr�ditos da disc a ser inserida, o aluno ultrapassa o limite de cr�ditos
		return AMT_CondRetLimiteDeCredUlt;
	}

	retBuscaDIS = DIS_buscaTurma(Disc, codTurma, &tur);
	if (retBuscaDIS == DIS_CondRetTurmaNaoExiste) {
		return AMT_CondRetTurmaNaoExiste;
	}
	
	GRA_InsereGradeHorario(i, Disc, tur, AluGrad->grade); // Inserindo na grade de hor�rio.

	return AMT_CondRetOK;
}
/*Fim da fun��o*/

/*In�cio da fun��o BuscaAluno*/
/*Recebe a matr�cula de um aluno, busca essa matr�cula nos alunos matriculados, e devolve
por refer�ncia o par Aluno-GradeHorario do referido aluno. */
AMT_tpCondRet AMT_BuscaAluno(unsigned int matbusca, parAluGrad** parAluGradeBuscado) {
	unsigned int mat2 = 0, i, size;
	parAluGrad* parAluGrade = NULL;
	list_size(AluMatr->AMT, &size);	// Pego o tamanho da lista
	first(AluMatr->AMT);	// Seto a lista para o primeiro n�
	for (i = 0;i < size; i++) {
		get_val_cursor(AluMatr->AMT, (void**)&parAluGrade);	// Pego o par aluno-grade atual
		ALU_GetMat(parAluGrade->aluno, &mat2);	// Pego a matr�cula do aluno
		if (matbusca == mat2) {	// Vejo se a matr�cula � igual � de busca
			*parAluGradeBuscado = parAluGrade;
			return AMT_CondRetAlunoJaCadastrado;	// se for, retorno ele.
		}
		next(AluMatr->AMT); // caso n�o seja, vou para o pr�ximo
	}
	return AMT_CondRetAlunoNaoExiste;	// N�o encontrei
}
/*Fim da fun��o*/

/*In�cio da fun��o alteraFaltas*/
/*Recebe uma matricula de aluno, o c�digo de uma disciplina e o n�mero de faltas a alterar
na mesma, busca pelo aluno e altera as faltas na disciplina informada. */
AMT_tpCondRet AMT_alteraFaltas(unsigned int mat, int faltas, char* codDisciplina) {
	InfoGradeHorario* disProcurada;
	parAluGrad *AluGrad;
	AMT_tpCondRet retBuscaAMT;

	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad);
	if(retBuscaAMT != AMT_CondRetAlunoJaCadastrado)
		return AMT_CondRetAlunoNaoExiste;
	disProcurada = GRA_BuscaGradeHorario(AluGrad->grade, codDisciplina);
	if (disProcurada == NULL) {
		return AMT_CondRetDisciplinaNaoEncontrada;
	}
	GRA_AlteraFaltas(AluGrad->grade, codDisciplina, faltas);
	return AMT_CondRetOK;
}
/*Fim da fun��o*/

/*In�cio da fun��o alteraFaltas*/
/*Recebe uma matricula de um aluno o c�digo de uma disciplina e o c�digo da turma,
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
/*Fim da fun��o*/

/*In�cio da fun��o imprimeGrade*/
/*Recebe a matr�cula de um aluno e imprime a sua grade de hor�rios completa. */
AMT_tpCondRet AMT_imprimeGrade(unsigned int mat) {
	parAluGrad *AluGrad;
	AMT_tpCondRet retBuscaAMT;
	char nome[81];

	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad);
	if (retBuscaAMT == AMT_CondRetAlunoNaoExiste) {
		return AMT_CondRetAlunoNaoExiste;
	}
	ALU_GetNome(AluGrad->aluno, nome);
	printf("\nNome do Aluno: %s\n", nome);
	printf("Matricula: %u\n", mat);
	GRA_ExibeGradeHorario(AluGrad->grade);
	return AMT_CondRetOK;
}
/*Fim da fun��o*/

/*In�cio da fun��o alteraTurma*/
/* Fazer descri��o */
AMT_tpCondRet AMT_alteraTurma(unsigned int mat, char* codDisciplina, char* codTurma) {
	parAluGrad* AluGrad;
	Disciplina* Disc;
	Turma *turma;
	InfoGradeHorario *i = NULL;
	if(AMT_BuscaAluno(mat, &AluGrad) != AMT_CondRetAlunoJaCadastrado) // Busca para saber se aluno est� matr�culado em alguma disciplina.
		return AMT_CondRetAlunoNaoExiste;
	if (GRA_BuscaGradeHorario(AluGrad->grade, codDisciplina) == NULL)// Busca para saber se o aluno est� matriculado naquela disciplina.
		return AMT_CondRetDisciplinaNaoEncontrada;
	GRC_buscaPorCodigo(codDisciplina); //Busca Disciplina
	GRC_devolveDisc((void**)&Disc); //Recebe por refer�ncia o ponteiro para Disciplina
	if (DIS_buscaTurma(Disc, codTurma, &turma) == DIS_CondRetTurmaNaoExiste)
		return AMT_CondRetTurmaNaoExiste;
	GRA_EliminaNo(AluGrad->grade, codDisciplina); //Removo da turma inicial da disciplina.
	if (GRA_InsereGradeHorario(i, Disc, turma, AluGrad->grade) == GRA_CondRetOk)//
		return AMT_CondRetOK;
	else
		return AMT_CondRetErro;
}
/*Fim da fun��o*/

/*In�cio da fun��o insereNota*/
/* Fazer descri��o */
AMT_tpCondRet AMT_insereNota(float g1, float g2, float g3, float g4, unsigned int mat, char* codDisciplina) {
	parAluGrad* AluGrad;
	AMT_tpCondRet retBuscaAMT;
	float nota[4];
	retBuscaAMT = AMT_BuscaAluno(mat, &AluGrad); // Busca para saber se aluno est� matr�culado em alguma disciplina.
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
/*Fim da fun��o*/
/*Fun��o que recebe uma matr�cula e remove aquele aluno da lista dos alunos matriculados*/
AMT_tpCondRet AMT_deletaNo(unsigned int mat){
	unsigned int mat2 = 0, i, size;
	parAluGrad* parAluGrade = NULL;
	if (list_size(AluMatr->AMT, &size) == LIS_CondRetListaVazia)// Pego o tamanho da lista
		return AMT_CondRetAlunoNaoExiste;
	first(AluMatr->AMT);	// Seto a lista para o primeiro n�
	for (i = 0;i < size; i++) {
		get_val_cursor(AluMatr->AMT, (void**)&parAluGrade);	// Pego o par aluno-grade atual
		ALU_GetMat(parAluGrade->aluno, &mat2);	// Pego a matr�cula do aluno
		if (mat == mat2) {	// Vejo se a matr�cula � igual � de busca
			pop_cursor(AluMatr->AMT, (void**)&parAluGrade);
			return AMT_CondRetOK;	// se for, retorno ele.
		}
		next(AluMatr->AMT); // caso n�o seja, vou para o pr�ximo
	}
	return AMT_CondRetAlunoNaoExiste;	// N�o encontrei
}
/*Fim da fun��o*/

/*In�cio da fun��o limpa*/
/*Fun��o que remove todos os n�s da lista dos alunos matr�culados e desaloca sua mem�ria*/
AMT_tpCondRet AMT_limpa (void){
	clear (AluMatr->AMT);
	del (AluMatr->AMT);
	return AMT_CondRetOK;
}
/*Fim da fun��o*/
