/***************************************************************************
*  $MCI Módulo de implementação: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.C
*  Letras identificadoras:      GRC
*
*  Nome da base de software:    Fonte do módulo Corpo Docente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.  
*
*  $HA Histórico de evolução:
*     Versão  Autor 	Data     	Observações
*       0.10   BM	07/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para manipular os professores na lista de corpo docente.
*     Este módulo utiliza funcões de interface do modulo professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gradeCurricular.h"
#include "disciplina.h"
#include "listas.h"

/***********************************************************************
*
*  $TC Tipo de dados: corpoDocente
*
*
*  $ED Descrição do tipo
*     Estrutura principal que armazena os dados de um corpo docente ao qual este módulo se dedica.
*
***********************************************************************/

typedef struct parDisciplina{
	Disciplina *disciplina;
	List *preRequisitos;
} ParDisciplina;

typedef struct gradeCurricular{
	List *parDisciplinas;
} GradeCurricular;


/*****  Dados encapsulados no módulo  *****/
	
static GradeCurricular *grc;
	/* instância de corpo docente armazenada por este módulo */

/***** Protótipos das funções encapsuladas no módulo *****/
// TODO retirar isto caso nao faça nenhuma funcao


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: GRC Criar Lista de Corpo Docente
*  ****/

GRC_tpCondRet GRC_cria(){
	grc = (GradeCurricular*) malloc(sizeof(GradeCurricular));
	createList(&grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim função: GRC Criar Lista de Corpo Docente */

/***************************************************************************
*
*  Função: GRC Cadastrar Professor
*  ****/

GRC_tpCondRet GRC_cadastra(char* nome, char* codigo, int creditos, char* bibliografia, char* ementa){
	ParDisciplina *parD = NULL;
	Disciplina *disc = NULL;
	DIS_tpCondRet ret;
	if(GRC_buscaPorCodigo(codigo) == GRC_CondRetOk)
		return GRC_CondRetIdJaCriado;
	ret = DIS_gera_param(&disc, nome, codigo, creditos, bibliografia, ementa);
	if(ret == DIS_CondRetFaltouMemoria) return GRC_CondRetNaoHaMemoria;
	if(ret == DIS_CondRetParametroInvalido) return GRC_CondRetFormatoInvalido;
	parD = (ParDisciplina*) malloc(sizeof(ParDisciplina));
	parD->disciplina = disc;
	createList(&parD->preRequisitos);
	push_back(grc->parDisciplinas, parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Cadastrar Professor */

/***************************************************************************
*
*  Função: GRC Mostra Pre-Requisitos
*  ****/

/* Funcao interna */

GRC_tpCondRet GRC_mostraPreRequisitos(ParDisciplina *parD){
	Disciplina *disc = NULL;
	char buffer[80] = "";
	char *codigo = NULL;
	int tam=0;
	first(parD->preRequisitos);
	printf("Pre-Requisitos: ");
	do{
		if(get_val_cursor(parD->preRequisitos, (void**) &disc)== LIS_CondRetListaVazia) break;
		DIS_get_codigo(disc, &codigo);
		printf(" %s", buffer);
		strcpy(buffer, codigo);
		strcat(buffer, ",");
		free(codigo);
	}while(next(parD->preRequisitos)==LIS_CondRetOK);
	if(strcmp(buffer,"")==0)
		printf("--//--");
	else{
		tam = strlen(buffer);
		/* Tam não é igual a zero, pois se fosse, nao estariamos neste if */
		buffer[tam-1] = '.';
		printf("%s", buffer);
	}
	printf("\n");
	return GRC_CondRetOk;
}/* Fim função: GRC Mostra Pre-Requisitos */

/***************************************************************************
*
*  Função: GRC Mostra Atual
*  ****/

GRC_tpCondRet GRC_mostraAtual(){
	ParDisciplina *parD = NULL;
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_exibe(parD->disciplina);
	GRC_mostraPreRequisitos(parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Mostra Atual */

 /***************************************************************************
 *
 *  Função: GRC Mostra Todos Professores
 *  ****/

GRC_tpCondRet GRC_mostraTodas(){
	ParDisciplina *parD = NULL;
	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
		DIS_exibe(parD->disciplina);
		GRC_mostraPreRequisitos(parD);
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);
	return GRC_CondRetOk;
}/* Fim função: GRC Mosta Todos Professores */

 /***************************************************************************
 *
 *  Função: GRC Limpa Lista
 *  ****/

GRC_tpCondRet GRC_limpa(){
	ParDisciplina *parD = NULL;
	while(pop_back(grc->parDisciplinas, (void**) &parD)==LIS_CondRetOK){
		DIS_deleta_Disciplina(&parD->disciplina);
		del(parD->preRequisitos);
		free(parD);	
	};
	return GRC_CondRetOk;
}/* Fim função: GRC Limpa Lista */

 /***************************************************************************
 *
 *  Função: GRC Retira da Lista
 *  ****/

GRC_tpCondRet GRC_retira(){
	ParDisciplina *parD = NULL;
	if(pop_cursor(grc->parDisciplinas, (void**) &parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_deleta_Disciplina(&parD->disciplina);
	del(parD->preRequisitos);
	free(parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Retira da Lista */

 /***************************************************************************
 *
 *  Função: GRC Libera
 *  ****/

GRC_tpCondRet GRC_libera(){
	GRC_limpa();
	del(grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim função: GRC Libera */

 /***************************************************************************
 *
 *  Função: GRC Busca Por RG
 *  ****/

GRC_tpCondRet GRC_buscaPorCodigo(char *chave){
	ParDisciplina *parD = NULL;
	char *codigo = NULL;	
	char *inicioCod = NULL;
	int ret;
	
	get_val_cursor(grc->parDisciplinas, (void**) &parD);
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD) == LIS_CondRetListaVazia)
		return GRC_CondRetGradeCurricularVazia;
	DIS_get_codigo(parD->disciplina, &inicioCod);

	first(grc->parDisciplinas);
	do{
		if(get_val_cursor(grc->parDisciplinas, (void**) &parD) == LIS_CondRetListaVazia){
			free(inicioCod);
			return GRC_CondRetGradeCurricularVazia;
		}

		DIS_get_codigo(parD->disciplina, &codigo);
		ret = strcmp(chave, codigo);
		free(codigo);
		if(ret==0){
			free(inicioCod);
			return GRC_CondRetOk;
		}
	}while(next(grc->parDisciplinas)==LIS_CondRetOK);
	GRC_buscaPorCodigo(inicioCod);
	free(inicioCod);
	return GRC_CondRetDisciplinaNaoEncontrada;
}/* Fim função: GRC Busca Por RG */

 /***************************************************************************
 *
 *  Função: GRC Busca Por RG
 *  ****/

/*
	TODO formalizar este comentário
	Note que o codigo passado como argumento é o codigo do pre-requisito. E NÃO o código da disciplina a qual vamos adicionar um preRequisito.
	A disciplina a qual vamos adicionar é a disciplina selecionada (cursor).
*/
GRC_tpCondRet GRC_inserePreRequisito(char *codigoPre){
	ParDisciplina *parD = NULL;
	ParDisciplina *parDPre = NULL;
	char *codigo = NULL;
	/* Recuperando disciplina atual da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	/* Recuperando o código dela */
	DIS_get_codigo(parD->disciplina, &codigo);	
	/* Procurando o pre requisito */
	if(GRC_buscaPorCodigo(codigoPre)!=GRC_CondRetOk){
		/* Se não encontrei retorno o cursor para onde comecei e retorno */
		GRC_buscaPorCodigo(codigo);
		free(codigo);
		return GRC_CondRetDisciplinaNaoEncontrada;
	}
	/* 
		Recuperando a disciplina Pre-Requisito
		Ja sei que a lista não esta vazia, não preciso verificar de novo
	*/
	get_val_cursor(grc->parDisciplinas, (void**) &parDPre);
	/* Guardo o endereco do pre-requisito (disciplina, nao par) na lista do par (e nao disciplina) que recuperei no inicio */
	push_back(parD->preRequisitos, parDPre->disciplina);
	/* Retorno o cursor para onde comecei e retorno */
	GRC_buscaPorCodigo(codigo);
	free(codigo);
	return GRC_CondRetOk;
}/* Fim função: GRC Busca Por RG */

GRC_tpCondRet GRC_removePreRequisitos(){
	ParDisciplina *parD = NULL;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	clear(parD->preRequisitos);
	return GRC_CondRetOk;
}/* Fim função: GRC Busca Por RG */


 /***************************************************************************
 *
 *  Função: GRC Consulta RG
 *  ****/
GRC_tpCondRet GRC_consultaNome(char *nome){
	ParDisciplina *parD = NULL;
	char *nomeTemp = NULL;
	/* Recuperando disciplina da lista */
	if(get_val_cursor(grc->parDisciplinas, (void**) &parD)== LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_nome(parD->disciplina, &nomeTemp);
	strcpy(nome, nomeTemp);
	free(nomeTemp);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta RG */

 /***************************************************************************
 *
 *  Função: GRC Consulta CPF
 *  ****/
GRC_tpCondRet GRC_consultaCodigo(char *cpf){
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta CPF*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Matricula
 *  ****/
GRC_tpCondRet GRC_consultaCreditos(int *creditos){
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Matricula*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Email
 *  ****/
GRC_tpCondRet GRC_consultaBibliografia(char *bibliografia){
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Email*/


 /***************************************************************************
 *
 *  Função: GRC Consulta Telefone
 *  ****/
GRC_tpCondRet GRC_consultaEmenta(char *ementa){
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Telefone*/

