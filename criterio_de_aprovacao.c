/***************************************************************************
*
*  $MCI Módulo de definição: Módulo Criterio de Aprovação
*
*  Arquivo gerado:              criterio_de_aprovacao.c
*  Letras identificadoras:      CRI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: 	pg - Pedro Gabriel Serodio Sales
*         SaintL - Leonardo Abreu Santos
*	      	    LL - Clayton Lucas Mendes Lima
*						mrol - Matheus Rodrigues de Oliveira Leal
*
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data      Observações
*     0.01    pg    29/09/2017  Início do desenvolvimento
*     0.02 pg/SaintL/LL  30/09/2017 Merge dos três integrantes
*     0.03    mrol  01/10/2017  Uniformização da interface das funções e
*                               de todas as condições de retorno.
*	  0.04 ngtgmp 28/10/2017  Integração com o modulo Disciplina
*
***************************************************************************/
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "criterio_de_aprovacao.h"
/***** Protótipos das funções encapuladas no módulo *****/
/*
*				A Completar
*
*****  Código das funções exportadas pelo módulo  *****/
/***************************************************************************
*
*  Função: CRI criterio 1
*  ****/
CRI_tpCondRet CRI_Criterio01(float G1, float G2, float G3, float G4, float* media, int* situacao)
{
	if(media !=NULL && situacao != NULL){

		float NF;

		NF = (G1 + G2)/2;
		*media = NF;

		if (G1 >= 3.0 && G2 >= 3.0 && NF >= 6.0)
		{
			*situacao = 1; /* Aprovado */
			return CRI_CondRetOK;
		}
		else
		{
			NF = (G1 + G2 + (G3*2))/4;
			*media = NF;

			if (NF >= 5.0)
			{
				*situacao = 1; /* Aprovado */
				return CRI_CondRetOK;
			}
			else
			{
				*situacao = 0; /* Reprovado */
				return CRI_CondRetOK;
			}
		}
	}
	return CRI_CondRetErroParametro;
}
/* Fim função: CRI criterio 1 */
/***************************************************************************
*
*  Função: CRI criterio 2
*  ****/
CRI_tpCondRet CRI_Criterio02(float G1, float G2, float G3, float G4, float* media, int* situacao)
{
	if(media !=NULL && situacao != NULL){
		float NF, Gm, Gn, temp;

		NF = (G1 + G2 + G3)/3;

		if (( G1 >= 5.0 && G2 >= 5.0 && G3 >=5.0 ) || NF >= 6.0)
		{
			*media = NF;
			*situacao = 1; /* Aprovado */
			return CRI_CondRetOK;
		}
		else
		{
			if (G4 < 3.0)
			{
				NF = (G1 + G2 + G3 + (G4 * 3))/6;
				*media = NF;

				if (NF >= 5.0)
				{
					*situacao = 1; /* Aprovado */
					return CRI_CondRetOK;
				}
				else
				{
					*situacao = 0; /* Reprovado */
					return CRI_CondRetOK;
				}
			}
			else
			{
				if (G2 > G1)        /* Essa sequência de if ordena as notas de forma decrescente */
				{					/* Para o calculo da média */
					temp = G2;		/* Que utiliza as duas maiores notas e a G4 */
					G2 = G1;
					G1 = temp;
				}
					if (G3 > G2)
				{
					temp = G3;
					G3 = G2;
					G2 = temp;
				}
				if (G2 > G1)
				{
					temp = G2;
					G2 = G1;
					G1 = temp;
				}

				Gm = G1; /* Gm = Maior nota */
				Gn = G2; /* Gn = Segunda maior nota */

				NF = (Gm + Gn + G4)/3;
				*media = NF;

				if (NF >= 5.0)
				{
					*situacao = 1; /* Aprovado */
					return CRI_CondRetOK;
				}
				else
				{
					*situacao = 0; /* Reprovado */
					return CRI_CondRetOK;
				}
			}
		}
	}
	return CRI_CondRetErroParametro;

}
/* Fim função: CRI criterio 2 */
/***************************************************************************
*
*  Função: CRI criterio 3
*  ****/
CRI_tpCondRet CRI_Criterio03 (float G1, float G2, float G3, float G4, float *media,int *situacao){
	if(media !=NULL && situacao != NULL){
		float maior1 = G1, maior2 = G2; 
		*media =(G1 + G2 + G3)/3;
	

			if(maior1 < maior2 ){                             //Essa parte calcula os dois maiores valores entre G1 e G3
			maior1 = G2;
			maior2 = G1;
			}
			if(maior2 < G3){
				maior2 = G3;
			}
			if(maior1 < G3){
				maior2 = maior1;
				maior1 = G3;
			}                                              //Essa parte calcula e retorna a media final do aluno
		if (G1 >= 3.0 && G2 >= 3.0 && G3 >= 3.0 && *media >= 5.0){
			*situacao = 1;
			return CRI_CondRetOK;
		}
		else  if( G4 >= 3.0){

			*media = (maior1 + maior2 + G4)/3;



		}else if(G4 < 3.0){
			*media = ((G1 + G2 + G3 + (G4 *3)))/6;

		}
			if(*media >=5){
			*situacao = 1;
			return  CRI_CondRetOK;
			}
			else{
				*situacao = 0;
			return CRI_CondRetOK;
			}
	}
    return CRI_CondRetErroParametro;
}/* Fim função: CRI criterio 3 */
/***************************************************************************
*
*  Função: CRI criterio 4
*  ****/
CRI_tpCondRet CRI_Criterio04(float G1, float G2, float G3, float G4, float *media, int *situacao){
	if(media !=NULL && situacao != NULL){
		float maior1 = G1, maior2 = G2; 
		*media = (G1 + G2)/2;


			if(maior1 < maior2 ){                             //Essa parte calcula os dois maiores valores entre G1 e G3
			maior1 = G2;
			maior2 = G1;
			}
			if(maior2 < G3){
				maior2 = G3;
			}
			if(maior1 < G3){
				maior2 = maior1;
				maior1 = G3;
			}



		if(G1 >= 3.0 && G2 >= 3.0 && *media >=5.0) {                            //Essa parte calcula a media e indica a situaçao do aluno
			*situacao = 1;
			return CRI_CondRetOK;
		}
				else if(G1 >= 3.0 && G2>= 3.0 || ((G1 < 3.0 || G2 < 3.0) && G3 >=3.0)){

					*media = (maior1 + maior2)/2;

		}else

		if(G1 < 3.0 || G2 < 3.0 && G3 < 3.0)
		*media = (G1 + G2 + (G3*2))/4;


		if(*media >=5){
			*situacao = 1;
			return CRI_CondRetOK;
			}
			else{
				*situacao = 0;
			return CRI_CondRetOK;
			}
	}
    return CRI_CondRetErroParametro;

}/* Fim função: CRI criterio 4 */
/***************************************************************************
*
*  Inicio Função: CRI_Criterio05
*		Função aplica o critério 1 da PUC-RIO de acordo com Graus recebidos do Aluno.
*		
*
*  ****/
CRI_tpCondRet CRI_Criterio05 (float G1, float G2, float G3, float G4, float *media, int *situacao ){
	if(media !=NULL && situacao != NULL){
		if(G2<3){
			*media= (G1+(G2*3))/4;
		}
		else{
			*media= ((G1*2)+(G2*3))/5;
		}
		if((*media)>=6.0){
			*situacao=1;
			return CRI_CondRetOK;
		}
		else {
			*situacao=0;
			return CRI_CondRetOK;
		}
	}
	return CRI_CondRetErroParametro;
} /* Fim função: CRI_Criterio05
*
*		Retorna se o aluno foi aprovado ou não, e
*		qual foi a média final dele para o critério 1.
*/
