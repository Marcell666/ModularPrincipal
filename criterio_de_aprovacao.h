/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Critério de Avaliação
*
*  Arquivo gerado:              criterio_de_aprovacao.h
*  Letras identificadoras:      CRI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: SaintL - Leonardo Abreu Santos
*               LL - Clayton Lucas
*               pg - Pedro Gabriel Serodio Sales
*						  mrol - Matheus Rodrigues de Oliveira Leal
*
*
*  $HA Histórico de evolução:
*     Versão   Autor    Data        Observações
*       0.01	 SaintL  28/09/2017  Início do desenvolvimento
*       0.02   LL      28/09/2017  Critérios 3 e 4
*       0.03   pg      30/09/2017  Aplica critério
*       0.04   mrol    01/10/2017  Uniformização da interface das funções e
*                               	 de todas as condições de retorno.
*  $ED Descrição do módulo:
*	  Este módulo implementa um conjunto de funções aritméticas
*	  para calcular a média de um aluno e dizer se o mesmo foi
*	  aprovado ou não.
*
***************************************************************************/
/***********************************************************************
*
*  $TC Tipo de dados: CRI Condições de retorno
*
*
***********************************************************************/
#ifndef CRITERIO_DE_APROVACAO_H
#define CRITERIO_DE_APROVACAO_H
typedef enum
{
	CRI_CondRetOK = 0 ,
		/* Executou correto */
	CRI_CondRetErroParametro = 1
		/* Estrutura do Critério está errada */

}CRI_tpCondRet;

typedef CRI_tpCondRet (*CRI_funcCriterio)(float, float, float, float, float*, int*);
/***********************************************************************
*
*  $FC Função: CRI criterio 1
*
*  $ED Descrição da função
*	 Aplica o critério de avaliação 1
*	 sobre as notas de um aluno.
*	 Baseado no Criterio 7 da PUC-RIO
*
*  $Acertiva de Entrada: Recebe 3 Notas (G1, G2, G3)
*
*  $Acertiva de Saída: Retorna situação e média do Aluno
*
***********************************************************************/
CRI_tpCondRet CRI_Criterio01(float G1, float G2, float G3, float G4, float* media, int* situacao);
/***********************************************************************
*
*  $FC Função: CRI criterio 2
*
*  $ED Descrição da função
*	 Aplica o critério de avaliação 2
*	 sobre as notas de um aluno.
*	 Baseado no Criterio 5 da PUC-RIO
*
*  $Acertiva de Entrada: Recebe 4 Notas (G1, G2, G3 e G4) e ponteiros para media e situação do aluno
*
*  $Acertiva de Saída: Retorna situação e média do Aluno
*
***********************************************************************/
CRI_tpCondRet CRI_Criterio02(float G1, float G2, float G3, float G4, float* media, int* situacao);
/***********************************************************************
*
*  $FC Função: CRI criterio 3
*
*  $ED Descrição da função
*	 Aplica o critério de avaliação 3
*	 sobre as notas de um aluno.
*	 Baseado no Criterio 4 da PUC-RIO
*
*  $Acertiva de Entrada: Recebe 4 Notas (G1, G2, G3 e G4) e ponteiro para media e situação do aluno
*
*  $Acertiva de Saída: Retorna situação e média do Aluno
*
***********************************************************************/
CRI_tpCondRet CRI_Criterio03 (float G1, float G2, float G3, float G4, float *media,int *situacao);
/***********************************************************************
*
*  $FC Função: CRI criterio 4
*
*  $ED Descrição da função
*	 Aplica o critério de avaliação 4
*	 sobre as notas de um aluno.
*	 Baseado no Criterio 6 da PUC-RIO
*
*  $Acertiva de Entrada: Recebe 3 Notas (G1, G2, G3) e ponteiro para media e situação do aluno
*
*  $Acertiva de Saída: Retorna situação e média do Aluno
*
***********************************************************************/
CRI_tpCondRet CRI_Criterio04(float G1, float G2, float G3, float G4, float *media, int *situacao);
/***********************************************************************
*
*  $FC Função: CRI Verifica_Criterio01
*
*  $ED Descrição da função
*    Aplica o criterio de avaliação 1
*    baseado no criterio 1 da PUC-RIO
*
*    $Assertiva de Entrada: Recebe 2 Notas (G1, G2) e um ponteiro para media e outro para situação do aluno
*
*    $Assertiva de Saída: Retorna a situação e a média do Aluno
*
***********************************************************************/
CRI_tpCondRet CRI_Criterio05(float G1, float G2, float G3, float G4, float *media, int *situacao);
/**********************************************************************/

#endif

/***********************************************************************/

