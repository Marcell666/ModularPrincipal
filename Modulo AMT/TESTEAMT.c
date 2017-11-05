/***************************************************************************
*  $MCI Módulo de implementação: Módulo de teste específico
*
*  Arquivo gerado:              TESTEAMT.C
*  Letras identificadoras:      TAMT
*
*  Nome da base de software:    Teste Automatizado para o Módulo Aluno Matriculado
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruno Marinho, BM
*			Matheus Zeitune, MZ
*			Flávio Franco, FF
*			João Cerqueira, JC
*			Vinicius Btechs, VB.
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   FF   04/11/2017 Desenvolvimento para T3 modificando TESTCDISC.C
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para o teste do
*     módulo aluno matriculado. É um interpretador de comandos de teste específicos
*	  utilizando o arcabouço de teste para C.
*
*		CRIAR_AMT_CMD			Cria a lista de alunos matriculados.						"=criar"
*		MATNADISC_AMT_CMD		Matricula um aluno numa turma de uma disciplina.			"=matricular"
*		ALTFALTAS_AMT_CMD		Altera as faltas de um aluno.								"=alterarfalta"
*		RETIRADISC_AMT_CMD		Remove um aluno de uma disciplina.							"=remover"
*		IMPGRAD_AMT_CMD			Imprime a grade de um aluno.								"=imprimir"
*		INSERENOTA_AMT_CMD      Insere nota de um aluno em uma disciplina.					"=inserirnota"
*		ALTTURMA_AMT_CMD		Altera a turma em que um aluno está matriculado.			"=alterarturma"		
*		Comandos de teste específicos para o módulo Corpo Discente:
*
*		"=criar" <int>CondRet
*
*		"=matricular" <int>mat <string>codDisciplina <string>codTurma <int>CondRet
*
*       "=alterarfalta" <int>mat <int>faltas <string>codDisciplina <int>CondRet
*
*		"=remover" <int>mat <string>codDisciplina <int>CondRet
*
*		"=imprimir" <int>mat <int>CondRet
*		
*		"=inserirnota" <float>g1 <float>g2 <float>g3 <float>g4 <int>mat <string>codDisciplina <int>CondRet 
*
*		"=alterarturma" <int>mat <string>codDisciplina <string>codTurma <int>CondRet
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include	<stdlib.h>
#include    "corpodiscente.h"
#include	"aluno.h"
#include    "TST_ESPC.H"
#include	"AluMat.h"
#include    "generico.h"
#include    "lerparm.h"

/* Tabela dos nomes dos comandos de teste específicos */
#define     CRIAR_AMT_CMD			"=criar"
#define     MATNADISC_AMT_CMD		"=matricular"
#define     ALTFALTAS_AMT_CMD		"=alterarfalta"
#define     RETIRADISC_AMT_CMD      "=remover"
#define     IMPGRAD_AMT_CMD			"=imprimir"
#define		INSERENOTA_AMT_CMD		"=inserenota"
#define		ALTTURMA_AMT_CMD		"=alterarturma"

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{

	AMT_tpCondRet CondRetObtido = AMT_CondRetOK;
	AMT_tpCondRet CondRetEsperada = AMT_CondRetFaltouMemoria;
	/* inicializa para qualquer coisa,é só para inicializar as variáveis */
	int mat = 1;
	int faltas = 1;
	char *codDisciplina = "flavio";
	char *codTurma = "lindo";
	int indexparAluGradeBuscado = -1;
	int NumLidos;
	float g1 = -1;
	float g2 = -1;
	float g3 = -1;
	float g4 = -1;
	float nota[4] = {-1, -1, -1, -1};

	/* Testar AMT Criar lista de alunos matriculados*/

	if (strcmp(ComandoTeste, CRIAR_AMT_CMD) == 0)
	{

		NumLidos = LER_LerParametros("i", &CondRetEsperada);
		if (NumLidos != 1)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = AMT_cria();
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao criar lista.");

	}

	/* Testar AMT Matricula aluno em uma turma de uma disciplina*/

	if (strcmp(ComandoTeste, MATNADISC_AMT_CMD) == 0)
	{

		NumLidos = LER_LerParametros("issi", &mat, &codDisciplina, &codTurma, &CondRetEsperada);
		if (NumLidos != 4)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = AMT_matriculaNaDisc(mat, codDisciplina, codTurma);
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao inserir aluno na lista.");
	}


	/* Testar AMT Altera faltas de um aluno em uma disciplina*/

	if (strcmp(ComandoTeste, ALTFALTAS_AMT_CMD) == 0)
	{

		NumLidos = LER_LerParametros("iisi", &mat, &faltas, &codDisciplina, &CondRetEsperada);
		if (NumLidos != 4)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = AMT_alteraFaltas(mat, faltas, codDisciplina);
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Retorno errado ao alterar dados do Aluno.");
	}

	/* Testar AMT retira aluno de uma disciplina */

	else if (strcmp(ComandoTeste, RETIRADISC_AMT_CMD) == 0)
	{
		NumLidos = LER_LerParametros("isi", &mat, &codDisciplina, &CondRetEsperada);
		if (NumLidos != 3)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = AMT_retiraDisc(mat, codDisciplina);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno errado");
	}

	/* Testar AMT Imprimir grade de um aluno da lista aluno matriculado */

	else if (strcmp(ComandoTeste, IMPGRAD_AMT_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ii", &mat, &CondRetEsperada);
		if (NumLidos != 2)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = AMT_imprimeGrade(mat);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}
/* Testar AMT Insere nota de um aluno em uma disciplina*/

	else if (strcmp(ComandoTeste, INSERENOTA_AMT_CMD) == 0)
	{
		NumLidos = LER_LerParametros("ffffisi", &g1, &g2, &g3, &g4, &mat, &codDisciplina, &CondRetEsperada);
		if (NumLidos != 7)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = AMT_insereNota(g1, g2, g3, g4, mat, codDisciplina);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}
/* Testar AMT altera turma de um aluno*/

	else if (strcmp(ComandoTeste, ALTTURMA_AMT_CMD) == 0)
	{
		NumLidos = LER_LerParametros("issi", &mat, &codDisciplina, &codTurma, &CondRetEsperada);
		if (NumLidos != 4)
		{
			return TST_CondRetParm;
		}
		CondRetObtido = AMT_alteraTurma(mat, codDisciplina, codTurma);
		return TST_CompararInt(CondRetEsperada, CondRetObtido, "Retorno Errado");
	}
	return TST_CondRetNaoConhec;
}
