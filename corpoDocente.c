/***************************************************************************
*  $MCI Módulo de implementação: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.C
*  Letras identificadoras:      CDO
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
*       0.52   BM/RP	04/10/2017	Revisão
*       0.51   BM   	04/10/2017	Revisão
*       0.50   RP   	03/10/2017	Documentação
	0.40   FA	03/10/2017	Funções busca adicionadas
*       0.30   MR   	03/10/2017	Funções de consulta/altera adicionadas 
*       0.20   BM   	02/10/2017	Funcoes modelo adicionadas 
*       0.10   BM	01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para manipular os professores na lista de corpo docente.
*     Este módulo utiliza funcões de interface do modulo professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "corpoDocente.h"
#include "professor.h"
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

typedef struct corpoDocente{
	List *professores;
} CorpoDocente;


/*****  Dados encapsulados no módulo  *****/
	
static CorpoDocente *doc;
	/* instância de corpo docente armazenada por este módulo */

/***** Protótipos das funções encapsuladas no módulo *****/

CDO_tpCondRet buscaIdentificacao(int rgChave, char *cpfChave, int matriculaChave, char *emailChave);


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: CDO Criar Lista de Corpo Docente
*  ****/

CDO_tpCondRet CDO_cria(){
	doc = (CorpoDocente*) malloc(sizeof(CorpoDocente));
	createList(&doc->professores);
	return CDO_CondRetOk;
}/* Fim função: CDO Criar Lista de Corpo Docente */

/***************************************************************************
*
*  Função: CDO Cadastrar Professor
*  ****/

CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	PRF_tpCondRet ret;
	if(buscaIdentificacao(rg, cpf, matricula, email) != CDO_CondRetOk)
		return CDO_CondRetIdJaCriado;
	ret = PRF_cria(&prof, nome, rg, cpf, matricula, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, complemento);
	if(ret == PRF_CondRetNaoHaMemoria) return CDO_CondRetNaoHaMemoria;
	if(ret == PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	push_back(doc->professores, prof);
	return CDO_CondRetOk;
}/* Fim função: CDO Cadastrar Professor */

/***********************************************************************
*
*  $FC Função: CDO Busca Identificacao
*
*  $FV Valor retornado
*     Retorna CDO_CondRetIdJaCriado caso um professor com o mesmo valor de uma das chaves seja encontrado.
*     Retorna PRF_CondRetOk caso contrário.
*
***********************************************************************/
CDO_tpCondRet buscaIdentificacao(int rgChave, char *cpfChave, int matriculaChave, char *emailChave){
	PRF_ptProfessor prof = NULL;
	char cpf[PRF_TAM_STRING];
	char email[PRF_TAM_STRING];
	int matricula;
	int rg;
	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetOk;

		PRF_consultaCpf(prof, cpf);
		PRF_consultaRg(prof, &rg);
		PRF_consultaEmail(prof, email);
		PRF_consultaMatricula(prof, &matricula);
		if(strcmp(cpfChave, cpf)==0 || strcmp(emailChave, email)==0 || rgChave == rg || matriculaChave == matricula) return CDO_CondRetIdJaCriado;
	}while(next(doc->professores)==LIS_CondRetOK);

	/* Não encontrou */
	return CDO_CondRetOk;
}/* Fim função: CDO Busca Atual */

/***************************************************************************
*
*  Função: CDO Mostra Atual
*  ****/

CDO_tpCondRet CDO_mostraAtual(){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof)== LIS_CondRetListaVazia) return CDO_CondRetCorpoDocenteVazio;
	PRF_mostra(prof);
	return CDO_CondRetOk;
}/* Fim função: CDO Mostra Atual */

 /***************************************************************************
 *
 *  Função: CDO Mostra Todos Professores
 *  ****/

CDO_tpCondRet CDO_mostraTodos(){
	PRF_ptProfessor prof = NULL;
	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof)== LIS_CondRetListaVazia) return CDO_CondRetCorpoDocenteVazio;
		PRF_mostra(prof);
	}while(next(doc->professores)==LIS_CondRetOK);
	return CDO_CondRetOk;
}/* Fim função: CDO Mostra Todos Professores */

 /***************************************************************************
 *
 *  Função: CDO Limpa Lista
 *  ****/

CDO_tpCondRet CDO_limpa(){
	PRF_ptProfessor prof = NULL;
	while(pop_back(doc->professores, (void**) &prof)==LIS_CondRetOK)
		PRF_libera(&prof);
	return CDO_CondRetOk;
}/* Fim função: CDO Limpa Lista */

 /***************************************************************************
 *
 *  Função: CDO Retira da Lista
 *  ****/

CDO_tpCondRet CDO_retira(){
	PRF_ptProfessor prof = NULL;
	if(pop_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia) return CDO_CondRetCorpoDocenteVazio;
	PRF_libera(&prof);
	return CDO_CondRetOk;
}/* Fim função: CDO Retira da Lista */

 /***************************************************************************
 *
 *  Função: CDO Libera
 *  ****/

CDO_tpCondRet CDO_libera(){
	CDO_limpa();
	del(doc->professores);
	return CDO_CondRetOk;
}/* Fim função: CDO Libera */

 /***************************************************************************
 *
 *  Função: CDO Busca Por RG
 *  ****/

CDO_tpCondRet CDO_buscaPorRg(int chave){
	PRF_ptProfessor prof = NULL;
	int rg;

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaRg(prof, &rg);
		if(chave == rg) 
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim função: CDO Busca Por RG */

 /***************************************************************************
 *
 *  Função: CDO Busca Por CPF
 *  ****/
CDO_tpCondRet CDO_buscaPorCpf(char *chave){
	PRF_ptProfessor prof = NULL;
	char cpf[PRF_TAM_STRING];

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaCpf(prof, cpf);
		if(strcmp(chave, cpf)==0)
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim função: CDO Busca Por CPF */

 /***************************************************************************
 *
 *  Função: CDO Busca Por Matricula
 *  ****/

CDO_tpCondRet CDO_buscaPorMatricula(int chave){
	PRF_ptProfessor prof = NULL;
	int matricula;

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaMatricula(prof, &matricula);
		if(chave == matricula) 
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim função: CDO Busca Por Matricula */

 /***************************************************************************
 *
 *  Função: CDO Busca Por Email
 *  ****/

CDO_tpCondRet CDO_buscaPorEmail(char *chave){
	PRF_ptProfessor prof = NULL;
	char email[PRF_TAM_STRING];

	first(doc->professores);
	do{
		if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;

		PRF_consultaEmail(prof, email);
		if(strcmp(chave, email)==0)
			return CDO_CondRetOk;
	}while(next(doc->professores)==LIS_CondRetOK);

	return CDO_CondRetProfessorNaoEncontrado;
}/* Fim função: CDO Busca Por Email */

 /***************************************************************************
 *
 *  Função: CDO Consulta Nome
 *  ****/
CDO_tpCondRet CDO_consultaNome(char *nome){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaNome(prof, nome);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta Nome*/

 /***************************************************************************
 *
 *  Função: CDO Consulta RG
 *  ****/
CDO_tpCondRet CDO_consultaRg(int *rg){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaRg(prof,rg);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta RG */

 /***************************************************************************
 *
 *  Função: CDO Consulta CPF
 *  ****/
CDO_tpCondRet CDO_consultaCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaCpf(prof, cpf);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta CPF*/

 /***************************************************************************
 *
 *  Função: CDO Consulta Matricula
 *  ****/
CDO_tpCondRet CDO_consultaMatricula(int *matricula){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof,matricula);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta Matricula*/

 /***************************************************************************
 *
 *  Função: CDO Consulta Email
 *  ****/
CDO_tpCondRet CDO_consultaEmail(char *email){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaEmail(prof, email);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta Email*/

 /***************************************************************************
 *
 *  Função: CDO Consulta Telefone
 *  ****/
CDO_tpCondRet CDO_consultaTelefone(int *tel){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaTelefone(prof, tel);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta Telefone*/

 /***************************************************************************
 *
 *  Função: CDO Consulta Data de Nascimento
 *  ****/
CDO_tpCondRet CDO_consultaDataNascimento(int *dia, int *mes, int *ano){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaDiaNascimento(prof, dia);
	PRF_consultaMesNascimento(prof, mes);
	PRF_consultaAnoNascimento(prof, ano);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta Data de Nascimento*/

 /***************************************************************************
 *
 *  Função: CDO Consulta Endereço
 *  ****/
CDO_tpCondRet CDO_consultaEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int *numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaPais(prof,pais);
	PRF_consultaUf(prof,uf);
	PRF_consultaCidade(prof,cidade);
	PRF_consultaBairro(prof,bairro);
	PRF_consultaRua(prof,rua);
	PRF_consultaNumero(prof,numero);
	PRF_consultaComplemento(prof,complemento);
	return CDO_CondRetOk;
}/* Fim função: CDO Consulta Endereço*/

 /***************************************************************************
 *
 *  Função: CDO Altera Nome
 *  ****/
CDO_tpCondRet CDO_alteraNome(char *nome){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraNome(prof, nome)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera Nome*/

 /***************************************************************************
 *
 *  Função: CDO Altera RG
 *  ****/
CDO_tpCondRet CDO_alteraRg(int rg){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorRg(rg) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraRg(prof,rg)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera RG*/

 /***************************************************************************
 *
 *  Função: CDO Altera CPF
 *  ****/
CDO_tpCondRet CDO_alteraCpf(char *cpf){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorCpf(cpf) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraCpf(prof, cpf)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera CPF*/

 /***************************************************************************
 *
 *  Função: CDO Altera Matricula
 *  ****/
CDO_tpCondRet CDO_alteraMatricula(int matricula){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorMatricula(matricula) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraMatricula(prof, matricula)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera Matricula*/

 /***************************************************************************
 *
 *  Função: CDO Altera Email
 *  ****/
CDO_tpCondRet CDO_alteraEmail(char* email){
	PRF_ptProfessor prof = NULL;
	int id;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	PRF_consultaMatricula(prof, &id);
	if(CDO_buscaPorEmail(email) == CDO_CondRetOk) return CDO_CondRetIdJaCriado;
	/* Retornando cursor para posicao original */
	CDO_buscaPorMatricula(id);
	if(PRF_alteraEmail(prof, email)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera Email*/

 /***************************************************************************
 *
 *  Função: CDO Altera Telefone
 *  ****/
CDO_tpCondRet CDO_alteraTelefone(int tel){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraTelefone(prof, tel)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera Telefone*/

 /***************************************************************************
 *
 *  Função: CDO Altera Data de Nascimento
 *  ****/
CDO_tpCondRet CDO_alteraDataNascimento(int dia, int mes, int ano){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraDataNascimento(prof, dia, mes, ano)==PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera Data de Nascimento*/

 /***************************************************************************
 *
 *  Função: CDO Altera Endereco
 *  ****/
CDO_tpCondRet CDO_alteraEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_ptProfessor prof = NULL;
	if(get_val_cursor(doc->professores, (void**) &prof) == LIS_CondRetListaVazia)
			return CDO_CondRetCorpoDocenteVazio;
	if(PRF_alteraPais(prof,pais)		==	PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraUf(prof,uf)		==	PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraCidade(prof,cidade)	==	PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraBairro(prof,bairro)	==	PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraRua(prof,rua)		==	PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraNumero(prof,numero)	==	PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	if(PRF_alteraComplemento(prof,complemento)==	PRF_CondRetFormatoInvalido) return CDO_CondRetFormatoInvalido;
	return CDO_CondRetOk;
}/* Fim função: CDO Altera Endereco*/


