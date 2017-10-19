/***************************************************************************
*  $MCI Módulo de implementação: Módulo professor
*
*  Arquivo gerado:              professor.C
*  Letras identificadoras:      PRF
*
*  Nome da base de software:    Fonte do módulo professor
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
*     Versão  Autor    			  Data     Observações
*       1.00   BM,FA,NP,MR,RP   11/09/2017 Desenvolvimento para T1 
*
*  $ED Descrição do módulo
*     Este modulo contém as funções específicas para criar, alterar e consultar uma
*     instância de um professor.
***************************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

/***********************************************************************
*
*  $TC Tipo de dados: Data
*
*
*  $ED Descrição do tipo
*     Estrutura que armazena os dados com dia, mes e ano.
*	  Usado na estrutura Professor para armazenar a data de nascimento.
*
***********************************************************************/
	typedef struct data{
		int dia;
		int mes;
		int ano;
	} Data;

/***********************************************************************
*
*  $TC Tipo de dados: Endereço
*
*
*  $ED Descrição do tipo
*     Estrutura que armazena dos dados um local.
*	  Usado na estrutura Professor para armazenar o local de sua residência.
*
***********************************************************************/

	typedef struct endereco{
		char pais[PRF_TAM_STRING];
		char uf[PRF_TAM_STRING]; 
			/* Unidade Federativa - Estados */
		char cidade[PRF_TAM_STRING];
		char bairro[PRF_TAM_STRING];
		char rua[PRF_TAM_STRING];
		int numero;
			/* numero do predio */
		char complemento[PRF_TAM_STRING];
			/*apartamento ou casa com numero //ex: apt 101 */
	} Endereco;
/***********************************************************************
*
*  $TC Tipo de dados: prof
*
*
*  $ED Descrição do tipo
*     Estrutura principal que armazena os dados de um professor ao qual este módulo se dedica.
*
***********************************************************************/

	struct prof{
		char nome[PRF_TAM_STRING];
		char cpf[PRF_TAM_STRING]; //Numero do Cadastro de Pessoas Físicas
		int matricula; //Numero identificador na Universidade
		char email[PRF_TAM_STRING];
		int telefone;
		Data* dataNascimento;
		Endereco* endereco;
		int rg; // Numero da indentidade - Registro Geral
	};

/*****  Dados encapsulados no módulo  *****/
	
static int maxDias[] = {31,29,31,30,31,30,31,31,30,31,30,31};
		/* vetor contendo o máximo de dias válidos em cada mês. Usado na função verificaData */

/***** Protótipos das funções encapsuladas no módulo *****/

	PRF_tpCondRet mostraEndereco(Endereco* end);
	PRF_tpCondRet mostraData(Data* d);

	int verificaRg(int rg);
	int verificaTelefone(int telefone);
	int verificaEmail(char* email);
	int verificaMatricula(int matricula);
	int verificaCpf(char* cpf);
	int verificaNome(char* nome);
	int verificaPais(char* pais);
	int verificaUf(char* uf);
	int verificaCidade(char* cidade);
	int verificaBairro(char* bairro);
	int verificaComplemento(char* complemento);
	int verificaNumero(int numero);
	int verificaRua(char* rua);
	int verificaData(int dia, int mes, int ano);

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: PRF Criar professor
*  ****/

PRF_tpCondRet PRF_cria(Prof** professor, char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento){
	PRF_tpCondRet ret;
	Data *dataNascimento;
	Endereco *endereco;
		
	Prof *p;

	if(*professor != NULL) return PRF_CondRetProfessorJaCriado; /* if */

	*professor = (Prof*) malloc(sizeof(Prof));

	p = *professor;

	if(p == NULL) return PRF_CondRetNaoHaMemoria; /* if */
	
	dataNascimento = (Data*) malloc(sizeof(Data));
	if(dataNascimento == NULL) return PRF_CondRetNaoHaMemoria; /* if */

	endereco = (Endereco*) malloc(sizeof(Endereco));
	if(endereco == NULL) return PRF_CondRetNaoHaMemoria; /* if */
	 
	p->dataNascimento = dataNascimento;
	p->endereco = endereco;
	do{ 

		/* Bloco para checar se os parametros para as alterações foram todos válidos */

		if((ret = PRF_alteraNome(p, nome)) 		!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraRg(p, rg)) 			!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraCpf(p, cpf)) 		!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraMatricula(p, matricula)) 	!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraEmail(p, email)) 		!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraTelefone(p, telefone)) 	!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraDataNascimento(p, dia, mes, ano))	!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraPais(p, pais)) 		!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraUf(p, uf)) 			!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraCidade(p, cidade)) 		!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraBairro(p, bairro)) 		!= PRF_CondRetOk) break; /* if */ 
		if((ret = PRF_alteraRua(p, rua))		!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraNumero(p, numero))		!= PRF_CondRetOk) break; /* if */
		if((ret = PRF_alteraComplemento(p, complemento))!= PRF_CondRetOk) break; /* if */
	}while(0); 

	/* Caso algum parâmetro for inválido libera a memória alocada */
	if(ret != PRF_CondRetOk){
		PRF_libera(professor);
		return ret;
	}

	return PRF_CondRetOk;
} /* Fim função: PRF Criar professor */

/***************************************************************************
*
*  Função: PRF Mostra professor
*  ****/

PRF_tpCondRet PRF_mostra(Prof* professor){
	if(!professor) return PRF_CondRetNaoExisteProf; /* if */
	if(!professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
	if(!professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
	printf("Exibindo Professor...\n"); 
	printf("Nome: %s\n", professor->nome);
	printf("CPF: %s\n", professor->cpf);
	printf("RG: %d\n", professor->rg);
	printf("Matricula: %d\n", professor->matricula);
	printf("Email: %s\n", professor->email);
	printf("Telefone: %d \n", professor->telefone);
	printf("Data de nascimento: ");
	mostraData(professor->dataNascimento);
	printf("Endereco:");
	mostraEndereco(professor->endereco);
	return PRF_CondRetOk;
} /* Fim função: PRF Mostra professor */

/***********************************************************************
*
*  $FC Função: PRF Mostra endereço
*
*  $FV Valor retornado
*     PRF_tpCondRet condição de retorno padrão do módulo
*     Retorna PRF_CondRetOk caso todos os dados tenham sido exibidos.
*
***********************************************************************/

	PRF_tpCondRet mostraEndereco(Endereco* end){
		printf(" %s, ", end->rua);
		printf("%d, ", end->numero);
		printf("%s, ", end->complemento);
		printf("%s, ", end->bairro);
		printf("%s, ", end->cidade);
		printf("%s - ", end->uf);
		printf("%s, \n", end->pais);
		return PRF_CondRetOk;
	} /* Fim função: PRF Mostra professor */

/***********************************************************************
*
*  $FC Função: PRF Mostra data
*
*  $FV Valor retornado
*     PRF_tpCondRet condição de retorno padrão do módulo
*     Retorna PRF_CondRetOk caso todos os dados tenham sido exibidos.
*
***********************************************************************/

	PRF_tpCondRet mostraData(Data* d){
		printf("%d/%d/%d\n", d->dia, d->mes, d->ano);
		return PRF_CondRetOk;
	} /* Fim função: Mostra professor */

/***************************************************************************
*
*  Função: PRF Libera professor
*  ****/	

	PRF_tpCondRet PRF_libera(Prof** professor){
		if(*professor==NULL) return PRF_CondRetNaoExisteProf;
		free((*professor)->dataNascimento);
		free((*professor)->endereco);
		free(*professor);
		*professor=NULL;
		return PRF_CondRetOk;
	} /* Fim função: Libera professor */

/***************************************************************************
*
*  Função: PRF Consulta nome
*  ****/	

	PRF_tpCondRet PRF_consultaNome(Prof* professor, char* nome){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(nome, professor->nome);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta nome */


/***************************************************************************
*
*  Função: PRF Consulta CPF
*  ****/	

	PRF_tpCondRet PRF_consultaCpf(Prof *professor, char *cpf){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(cpf, professor->cpf);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta CPF */


/***************************************************************************
*
*  Função: PRF Consulta matricula
*  ****/	

	PRF_tpCondRet PRF_consultaMatricula(Prof *professor, int *matricula){
		if(!professor) return PRF_CondRetNaoExisteProf; /* if */
		*matricula = professor->matricula;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta matricula */


/***************************************************************************
*
*  Função: PRF Consulta email
*  ****/

	PRF_tpCondRet PRF_consultaEmail(Prof* professor, char* email){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(email, professor->email);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta email */


/***************************************************************************
*
*  Função: PRF Consulta telefone
*  ****/

	PRF_tpCondRet PRF_consultaTelefone(Prof *professor, int *telefone){
		if(!professor) return PRF_CondRetNaoExisteProf; /* if */
		*telefone = professor->telefone;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta telefone */


/***************************************************************************
*
*  Função: PRF Consulta dia de nascimento
*  ****/

	PRF_tpCondRet PRF_consultaDiaNascimento(Prof *professor, int *dia){
		if(!professor || !professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
		*dia = professor->dataNascimento->dia;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta dia de nascimento */


/***************************************************************************
*
*  Função: PRF Consulta mês de nascimento
*  ****/

	PRF_tpCondRet PRF_consultaMesNascimento(Prof *professor, int *mes){
		if(!professor || !professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
		*mes = professor->dataNascimento->mes;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta mês de nascimento */


/***************************************************************************
*
*  Função: PRF Consulta ano de nascimento
*  ****/

	PRF_tpCondRet PRF_consultaAnoNascimento(Prof *professor, int *ano){
		if(!professor || !professor->dataNascimento) return PRF_CondRetNaoExisteProf; /* if */
		*ano = professor->dataNascimento->ano;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta ano de nascimento */


/***************************************************************************
*
*  Função: PRF Consulta país
*  ****/

	PRF_tpCondRet PRF_consultaPais(Prof *professor, char *pais){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(pais, professor->endereco->pais);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta país */


/***************************************************************************
*
*  Função: PRF Consulta uf
*  ****/

	PRF_tpCondRet PRF_consultaUf(Prof *professor, char *uf){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(uf, professor->endereco->uf);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta uf */


/***************************************************************************
*
*  Função: PRF Consulta cidade
*  ****/

	PRF_tpCondRet PRF_consultaCidade(Prof *professor, char *cidade){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(cidade, professor->endereco->cidade);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta cidade */


/***************************************************************************
*
*  Função: PRF Consulta bairro
*  ****/

	PRF_tpCondRet PRF_consultaBairro(Prof *professor, char *bairro){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(bairro, professor->endereco->bairro);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta bairro */


/***************************************************************************
*
*  Função: PRF Consulta rua
*  ****/

	PRF_tpCondRet PRF_consultaRua(Prof *professor, char *rua){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(rua, professor->endereco->rua);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta rua */


/***************************************************************************
*
*  Função: PRF Consulta numero
*  ****/

	PRF_tpCondRet PRF_consultaNumero(Prof *professor, int *numero){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		*numero = professor->endereco->numero;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta numero */


/***************************************************************************
*
*  Função: PRF Consulta complemento
*  ****/

	PRF_tpCondRet PRF_consultaComplemento(Prof *professor, char *complemento){
		if(!professor || !professor->endereco) return PRF_CondRetNaoExisteProf; /* if */
		strcpy(complemento, professor->endereco->complemento);
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta complemento */


/***************************************************************************
*
*  Função: PRF Consulta rg
*  ****/

	PRF_tpCondRet PRF_consultaRg(Prof *professor, int *rg){
		if(!professor) return PRF_CondRetNaoExisteProf; /* if */
		*rg = professor->rg;
		return PRF_CondRetOk;
	} /* Fim função: PRF Consulta rg */

/***************************************************************************
*
*  Função: PRF Altera data de Nascimento
*  ****/

	PRF_tpCondRet PRF_alteraDataNascimento(Prof* professor, int dia, int mes, int ano){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
		if(verificaData(dia, mes, ano) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		professor->dataNascimento->ano = ano;
		professor->dataNascimento->mes = mes;
		professor->dataNascimento->dia = dia;
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera data de Nascimento */


/***************************************************************************
*
*  Função: PRF Altera rua
*  ****/

	PRF_tpCondRet PRF_alteraRua(Prof* professor, char* rua){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaRua(rua) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		// altera dados
		strcpy(professor->endereco->rua,rua);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera rua */


/***************************************************************************
*
*  Função: PRF Altera rua
*  ****/

	PRF_tpCondRet PRF_alteraNumero(Prof* professor, int numero){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaNumero(numero) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		professor->endereco->numero = numero;
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera numero */


/***************************************************************************
*
*  Função: PRF Altera complemento
*  ****/

	PRF_tpCondRet PRF_alteraComplemento(Prof* professor, char* complemento){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaComplemento(complemento) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		strcpy(professor->endereco->complemento, complemento);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera complemento */


/***************************************************************************
*
*  Função: PRF Altera bairro
*  ****/

	PRF_tpCondRet PRF_alteraBairro(Prof* professor, char* bairro){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaBairro(bairro) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		strcpy(professor->endereco->bairro,bairro);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera bairro */


/***************************************************************************
*
*  Função: PRF Altera cidade
*  ****/

	PRF_tpCondRet PRF_alteraCidade(Prof* professor, char* cidade){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaCidade(cidade) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		strcpy(professor->endereco->cidade,cidade);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera cidade */


/***************************************************************************
*
*  Função: PRF Altera UF
*  ****/

	PRF_tpCondRet PRF_alteraUf(Prof* professor, char* uf){
		if(professor == NULL || professor->endereco == NULL)
			return PRF_CondRetNaoExisteProf; /* if */
		if(verificaUf(uf) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
		strcpy(professor->endereco->uf,uf);
		return PRF_CondRetOk;
	} /* Fim função: PRF Altera UF*/


/***************************************************************************
*
*  Função: PRF Altera país
*  ****/

PRF_tpCondRet PRF_alteraPais(Prof* professor, char* pais){
	if(professor == NULL || professor->endereco == NULL)
		return PRF_CondRetNaoExisteProf; /* if */
	if(verificaPais(pais) == 0)
		return PRF_CondRetFormatoInvalido; /* if */
	strcpy(professor->endereco->pais,pais);
	return PRF_CondRetOk;
} /* Fim função: PRF Altera UF*/


/***************************************************************************
*
*  Função: PRF Altera nome
*  ****/
 
	PRF_tpCondRet PRF_alteraNome(Prof* professor, char* nome){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaNome(nome) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    strcpy(professor->nome, nome);
	    return PRF_CondRetOk;
	} /* Fim função: PRF ALtera nome*/


/***************************************************************************
*
*  Função: PRF Altera CPF
*  ****/

	PRF_tpCondRet PRF_alteraCpf(Prof* professor, char* cpf){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaCpf(cpf) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    strcpy(professor->cpf, cpf);
	    return PRF_CondRetOk;
	} /* Fim função: PRF Altera CPF*/


/***************************************************************************
*
*  Função: PRF Altera matricula
*  ****/

	PRF_tpCondRet PRF_alteraMatricula(Prof* professor, int matricula){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaMatricula(matricula) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    professor->matricula = matricula;
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera matricula*/


/***************************************************************************
*
*  Função: PRF Altera email
*  ****/
 
	PRF_tpCondRet PRF_alteraEmail(Prof* professor, char* email){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaEmail(email) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    strcpy(professor->email, email);
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera email*/


/***************************************************************************
*
*  Função: PRF Altera telefone
*  ****/

	PRF_tpCondRet PRF_alteraTelefone(Prof* professor, int telefone){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaTelefone(telefone) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    professor->telefone = telefone;
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera telefone*/


/***************************************************************************
*
*  Função: PRF Altera RG
*  ****/

	PRF_tpCondRet PRF_alteraRg(Prof* professor, int rg){
		if(professor == NULL) return PRF_CondRetNaoExisteProf; /* if */
	    if(verificaRg(rg) == 0)
			return PRF_CondRetFormatoInvalido; /* if */
	    professor->rg = rg;
	    return PRF_CondRetOk;
	} /* Fim função: PRF altera RG*/
 

/***********************************************************************
*
*  $FC Função: PRF Verifica Data
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso a data seja válida, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaData(int dia, int mes, int ano){
		if(dia < 1 || ano < PRF_MIN_ANO || dia > maxDias[mes-1]) return 0;
		return 1;
	} /* Fim função: Verifica data*/


/***********************************************************************
*
*  $FC Função: PRF Verifica rua
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso a rua seja válida, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaRua(char* rua){
		int tamRua = strlen(rua);
		if(rua == NULL || tamRua == 0 || tamRua >= PRF_TAM_STRING)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica rua*/


/***********************************************************************
*
*  $FC Função: PRF Verifica numero
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso o numero seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaNumero(int numero){
		if(numero < 0)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica numero*/


/***********************************************************************
*
*  $FC Função: PRF Verifica Complemento
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso o complemento seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaComplemento(char* complemento){
		int tamComplemento = strlen(complemento);
		if(complemento == NULL || tamComplemento == 0 || tamComplemento >= PRF_TAM_STRING)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica complemento*/

/***********************************************************************
*
*  $FC Função: PRF Verifica bairro
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso bairro seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaBairro(char* bairro){
		int tamBairro = strlen(bairro);
		if(bairro == NULL || tamBairro == 0 || tamBairro >= PRF_TAM_STRING)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica bairro*/

/***********************************************************************
*
*  $FC Função: PRF Verifica cidade
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso cidade seja válida, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaCidade(char* cidade){
		int tamCidade = strlen(cidade);
		if(cidade == NULL || tamCidade == 0 || tamCidade >= PRF_TAM_STRING)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica cidade*/


/***********************************************************************
*
*  $FC Função: PRF Verifica Uf
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso uf seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaUf(char* uf){
		int tamUf = strlen(uf);
		if(uf == NULL || tamUf == 0 || tamUf >= PRF_TAM_UF)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica complemento*/


/***********************************************************************
*
*  $FC Função: PRF Verifica pais
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso o pais seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaPais(char* pais){
		int tamPais =  strlen(pais);
		if(pais == NULL || tamPais == 0 || tamPais >= PRF_TAM_STRING)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica país*/


/***********************************************************************
*
*  $FC Função: PRF Verifica nome
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso nome seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaNome(char* nome){
		int tamNome = strlen(nome);
		if(nome == NULL || tamNome == 0 || tamNome >= PRF_TAM_STRING)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica nome*/


/***********************************************************************
*
*  $FC Função: PRF Verifica cpf
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso o cpf seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaCpf(char* cpf){
		if(cpf == NULL || strlen(cpf) != PRF_TAM_CPF)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica cpf*/


/***********************************************************************
*
*  $FC Função: PRF Verifica matrícula
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso a matrícula seja válida, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaMatricula(int matricula){
		if(matricula < 0)
			return 0; /* if */
		return 1; 
	} /* Fim função: Verifica email*/


/***********************************************************************
*
*  $FC Função: PRF Verifica email
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso o email seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaEmail(char* email){
		int tamMail = strlen(email);
		if(email == NULL || tamMail == 0 || tamMail >= PRF_TAM_STRING)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica email*/

/***********************************************************************
*
*  $FC Função: PRF Verifica telefone
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso o telefone seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaTelefone(int telefone){
		if(telefone < 0)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica telefone*/


/***********************************************************************
*
*  $FC Função: PRF Verifica rg
*
*  $FV Valor retornado
*     Inteiro 0 ou 1.
*     Retorna 1 caso o rg seja válido, retorna 0 caso contrário.
*
***********************************************************************/

	int verificaRg(int rg){
		if(rg < 0)
			return 0; /* if */
		return 1;
	} /* Fim função: Verifica rg*/
