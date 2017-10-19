/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Menu
*
*  Arquivo gerado:              menu.c
*  Letras identificadoras:      MEN
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 2/ Grupo 1
*  Autores:   Bruce Marcellino
*	      Bruno Miranda Marinho
*             Flávio Thiago Franco Vaz
*             João Victor Cerqueira
*             Matheus Henrique Branco Zeitune
*             Vinícius Cortat
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data			Observações
*     1.01    Bruce	07/10/2017	Reestruturação
*     1.00    Bruce	06/10/2017	Revisão/finalização
*     0.05    Bruce	05/10/2017	Modulo professor
*     0.04    Matheus   04/10/2017  	Revisão menu
*     0.03    Bruno	02/10/2017	Menu professor
*     0.02    Flávio	02/10/2017  	Revisão
*     0.01    Matheus	01/10/2017	Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa o Menu do Sistema Acadêmico a ser desenvolvido.
*     O meu é a chamada dos modulos por interface.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"
#include "corpodiscente.h"
#include "aluno.h"
#include "corpoDocente.h"
#include "gradeCurricular.h"


/***** Declarações encapsuladas pelo módulo *****/

#define MEN_TAM_STRING 80

/***********************************************************************
*
*  $FC Função: MEN_loginAdministrativo
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

int MEN_loginAdministrativo()
{
	char user[81];
	char senha[81];
	printf("\nLogin Administrador\n");

	printf("\t\t Dica: use \"admin\", \"admin\".\n");// TODO retirar isto

	printf("\nDigite a user: ");
	scanf(" %s", user);

	printf("\nDigite a senha: ");
	scanf(" %s", senha);
	
	if(strcmp("admin", user) == 0 && strcmp("admin", senha) == 0 )
	{
		system("cls");
		return 1;
	}

	system("cls");
	return 0;
}

/***********************************************************************
*
*  $FC Função: MEN_loginProfessor.
*
*  $ED Descrição da função
*		Realiza a busca no corpo docente, se a matricula.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retorna 1, caso econtre e 0, senao.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/
int MEN_loginProfessor()
{
	int mat;

	printf("\nLogin Professor\n");

	printf("\nDigite a matricula: ");
	scanf("%d", &mat);
	if(CDO_buscaPorMatricula(mat) == CDO_CondRetOk)
	{
		system("cls");
		return 1;
	}

	return 0;
}

/***********************************************************************
*
*  $FC Função: MEN_loginAluno
*
*  $ED Descrição da função
*		Realiza a busca da matricula do aluno. (não implementado)
*
***********************************************************************/
/*Assertivas: Retorno da função: Rertona 1, se foi encontrado a matricula.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/
int MEN_loginAluno()
{
	int mat;

	printf("\nLogin Aluno\n");

	printf("\nDigite a matricula: ");
	scanf("%d", &mat);
	
	system("cls");
	return 1;
}

/***********************************************************************
*
*  $FC Função: MEN_adicionaAluno
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_adicionaAluno()
{
	char nome[81];
	unsigned int mat, telefone;
	Data nasc; 
	Endereco end;
	CPF cpf;

	//adiciona aluno
	system("cls");
	printf("\nDigite o nome do aluno: \n");
	scanf(" %s", nome);
	printf("\nDigite a matricula: \n");
	scanf("%d", &mat);
	printf("\nDigite a telefone: \n");
	scanf("%d", &telefone);
	printf("\nDigite a data de nacimento: \n");
		printf("\ndia"); 
		printf("\nmes"); 
		printf("\nano\n");
	scanf("%d", &nasc.dia);
	scanf("%d", &nasc.mes);
	scanf("%d", &nasc.ano);
	while(!(nasc.dia > 0 && nasc.dia < 31 && nasc.mes > 0 && nasc.mes < 13 && nasc.ano > 1900 && nasc.ano < 2010))
	{
		printf("\nDigite a data de nacimento: \n");
		printf("\ndia"); 
		printf("\nmes"); 
		printf("\nano\n");
		scanf("%d", &nasc.dia);
		scanf("%d", &nasc.mes);
		scanf("%d", &nasc.ano);
	}
	printf("\nDigite o cpf: \n");
	scanf("%d", &cpf.dig1);
	scanf("%d", &cpf.dig2);
	scanf("%d", &cpf.dig3);
	scanf("%d", &cpf.cod);
	while(!(cpf.dig1 > 0 && cpf.dig1 < 1000 && cpf.dig2 > 0 && cpf.dig2 < 1000 && cpf.dig3 > 0 && cpf.dig3 < 1000 && cpf.cod > 0 && cpf.cod < 100))
	{
		printf("\nDigite o cpf: \n");
		scanf("%d", &cpf.dig1);
		scanf("%d", &cpf.dig2);
		scanf("%d", &cpf.dig3);
		scanf("%d", &cpf.cod);
	}
	printf("\nDigite o estado\n");
	scanf(" %s", end.estado);
	printf("\nDigite a cidade\n");
	scanf(" %s", end.cidade);
	printf("\nDigite o bairro\n");
	scanf(" %s", end.bairro);
	printf("\nDigite a rua\n");
	scanf(" %s", end.rua);
	printf("\nDigite o comp\n");
	scanf(" %s", end.comp);
	CDI_insere(nome, mat, &cpf, telefone, &nasc, &end);
}


/***********************************************************************
*
*  $FC Função: MEN_modificaAluno
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_modificaAluno()
{
	char nome[81];
	unsigned int mat, telefone;
	Data nasc; 
	Endereco end;
	CPF cpf;

	system("cls");
	printf("\nDigite o nome do aluno: \n");
	scanf(" %s", nome);
	printf("\nDigite a matricula: \n");
	scanf("%d", &mat);
	printf("\nDigite a telefone: \n");
	scanf("%d", &telefone);
	printf("\nDigite a data de nacimento: \n");
	scanf("%d", &nasc.dia);
	scanf("%d", &nasc.mes);
	scanf("%d", &nasc.ano);
	while(!(nasc.dia > 0 && nasc.dia < 31 && nasc.mes > 0 && nasc.mes < 13 && nasc.ano > 1900 && nasc.ano < 2010))
	{
		printf("\nDigite a data de nascimento: \n");
		printf("\ndia"); 
		printf("\nmes"); 
		printf("\nano\n");
		scanf("%d", &nasc.dia);
		scanf("%d", &nasc.mes);
		scanf("%d", &nasc.ano);
	}
	printf("\nDigite o cpf: \n");
	scanf("%d", &cpf.dig1);
	scanf("%d", &cpf.dig2);
	scanf("%d", &cpf.dig3);
	scanf("%d", &cpf.cod);
	while(!(cpf.dig1 > 0 && cpf.dig1 < 1000 && cpf.dig2 > 0 && cpf.dig2 < 1000 && cpf.dig3 > 0 && cpf.dig3 < 1000 && cpf.cod > 0 && cpf.cod < 100))
	{
		printf("\nDigite o cpf: \n");
		scanf("%d", &cpf.dig1);
		scanf("%d", &cpf.dig2);
		scanf("%d", &cpf.dig3);
		scanf("%d", &cpf.cod);
	}
	printf("\nDigite o estado\n");
	scanf(" %s", end.estado);
	printf("\nDigite a cidade\n");
	scanf(" %s", end.cidade);
	printf("\nDigite o bairro\n");
	scanf(" %s", end.bairro);
	printf("\nDigite a rua\n");
	scanf(" %s", end.rua);
	printf("\nDigite o comp\n");
	scanf(" %s", end.comp);
	CDI_altera(mat, nome, mat, &cpf, telefone, &nasc, &end);
}

/***********************************************************************
*
*  $FC Função: MEN_adicionaProfessor
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_adicionaProfessor()
{
	int rg, matricula, telefone;
	int dia, mes, ano;
	char nome[MEN_TAM_STRING], cpf[MEN_TAM_STRING], email[MEN_TAM_STRING];
	char pais[MEN_TAM_STRING], uf[MEN_TAM_STRING], cidade[MEN_TAM_STRING], bairro[MEN_TAM_STRING], rua[MEN_TAM_STRING], complemento[MEN_TAM_STRING];
	int numero;
	CDO_tpCondRet ret;

	printf("\nAdicionando Professor\n");

	//Adiciona professor
	printf("Digite o nome: \n");
	scanf(" %s", nome);
	printf("Digite o rg: \n");
	scanf("%d", &rg);
	printf("Digite o cpf: \n");
	scanf(" %s", cpf);
	printf("Digite a matricula: \n");
	scanf("%d", &matricula);
	printf("Digite o telefone: \n");
	scanf("%d", &telefone);
	printf("Digite a data de nascimento: \n");
	printf("Dia: \n");
	scanf("%d", &dia);
	printf("Mes: \n");
	scanf("%d", &mes);
	printf("Ano: \n");
	scanf("%d", &ano);
	printf("Digite o pais: \n");
	scanf(" %s", pais);
	printf("Digite o email: \n");
	scanf(" %s", email);
	printf("Digite o estado\n");
	scanf(" %s", uf);
	printf("Digite a cidade\n");
	scanf(" %s", cidade);
	printf("Digite o bairro\n");
	scanf(" %s", bairro);
	printf("Digite a rua\n");
	scanf(" %s", rua);
	printf("Digite a numero\n");
	scanf("%d", &numero);
	printf("Digite o comp\n");
	scanf(" %s", complemento);
	ret = CDO_cadastra(nome, rg, cpf, matricula, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, complemento);
	if(ret == CDO_CondRetOk)
		printf("Alteracao realizada com sucesso!\n");
	else if(ret == CDO_CondRetFormatoInvalido)
		printf("ERRO. Formato de dados invalido.\n");
	else if(ret == CDO_CondRetIdJaCriado)
		printf("ERRO. Ja existe um professor com este valor de identificacao.\n");
	CDO_mostraAtual();
}

/***********************************************************************
*
*  $FC Função: MEN_modificaProfessor
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void MEN_modificaProfessor()
{
	char nomeFunc[][20] ={"sair",  "alterar o Nome", "alterar o RG","alterar o CPF","alterar a Matricula", "alterar o email", "alterar o Telefone", "alterar a Data", "alterar o Endereco"};
	int nAlteras = 9, i;
	CDO_alteraInt funcInt[] = {NULL, NULL, CDO_alteraRg, NULL, CDO_alteraMatricula, NULL,CDO_alteraTelefone, NULL, NULL};
	CDO_alteraString funcString[] = {NULL, CDO_alteraNome, NULL, CDO_alteraCpf, NULL, CDO_alteraEmail, NULL,NULL,NULL};
	int paramInt, dia, mes, ano;
	char paramString[MEN_TAM_STRING];
	char pais[MEN_TAM_STRING], uf[MEN_TAM_STRING], cidade[MEN_TAM_STRING], bairro[MEN_TAM_STRING], rua[MEN_TAM_STRING], complemento[MEN_TAM_STRING];
	int numero;
	CDO_tpCondRet ret;
	int opcao;

	printf("\nModificando Professor\n");

	printf("Digite a matrícula do professor que deseja modificar:\n");
	scanf("%d", &paramInt);
	if(CDO_buscaPorMatricula(paramInt)!=CDO_CondRetOk){
		printf("Não existe professor cadastrado com este numero de matricula %d, por favor tente novamente\n", paramInt);
		return;
	}
	CDO_mostraAtual();
	do{
		for(i=0;i<nAlteras;i++)
			printf("Digite %d: %s.\n", i, nomeFunc[i]);
		scanf("%d", &opcao);
		if(opcao>=nAlteras || opcao<1) return;
		else if( opcao==nAlteras-2){//data
			printf("\nDigite a data de nascimento: \n");
			printf("Dia: \n");
			scanf("%d", &dia);
			printf("Mes: \n");
			scanf("%d", &mes);
			printf("Ano: \n");
			scanf("%d", &ano);
			ret = CDO_alteraDataNascimento(dia, mes, ano);
		} else if( opcao==nAlteras-1){//endereco
			printf("\nDigite o novo pais:\n");
			scanf(" %s", pais);
			printf("\nDigite o novo estado:\n");
			scanf(" %s", uf);
			printf("\nDigite a nova cidade:\n");
			scanf(" %s", cidade);
			printf("\nDigite o novo bairro:\n");
			scanf(" %s", bairro);
			printf("\nDigite a nova rua:\n");
			scanf(" %s", rua);
			printf("\nDigite o novo numero:\n");
			scanf("%d", &numero);
			printf("\nDigite o novo complemento:\n");
			scanf(" %s", complemento);
			ret = CDO_alteraEndereco(pais, uf, cidade, bairro, rua, numero, complemento);
		}
		else{
			printf("Digite o novo valor para %s.\n", nomeFunc[opcao]);
			if(funcInt[opcao]!= NULL){
				scanf("%d", &paramInt);
				ret = funcInt[opcao](paramInt);
			} else if (funcString[opcao]!= NULL){
				scanf(" %s", paramString);
				ret = funcString[opcao](paramString);
			} else break;
		}
		if(ret == CDO_CondRetOk)
			printf("Alteracao realizada com sucesso!\n");
		else if(ret == CDO_CondRetFormatoInvalido)
			printf("ERRO. Formato de dados invalido.\n");
		else if(ret == CDO_CondRetIdJaCriado)
			printf("ERRO. Ja existe um professor com este valor de identificacao.\n");
		CDO_mostraAtual();
	}while(opcao);
}

void MEN_menuGradeCurricular()
{
	char nomeFunc[][40] ={"sair", "adicionar disciplina" , "mostrar a disciplina atual", "buscar outra disciplina", "mostrar todas as disciplinas", "inserir um Pre-Requisito", "remover todos os Pre-Requisitos", "Limpar a grade Curricular"};
	int nItens = 8, i;
	int creditos;
	char nome[MEN_TAM_STRING], codigo[MEN_TAM_STRING], bibliografia[MEN_TAM_STRING], ementa[MEN_TAM_STRING];
	GRC_tpCondRet ret;
	int opcao;

	printf("\nMenu Disciplina\n");
	do{
		for(i=0;i<nItens;i++)
			printf("Digite %d: %s.\n", i, nomeFunc[i]);
		scanf("%d", &opcao);

		switch(opcao){
			case 1:

				printf("\nDigite o nome:\n");
				scanf(" %s", nome);
				printf("\nDigite o codigo:\n");
				scanf(" %s", codigo);
				printf("\nDigite o numero de creditos:\n");
				scanf(" %d", &creditos);
				printf("\nDigite a bibliografia:\n");
				scanf(" %s", bibliografia);
				printf("\nDigite a ementa:\n");
				scanf(" %s", ementa);
				ret = GRC_cadastra(nome, codigo, creditos, bibliografia, ementa);
				break;
			case 2:
				GRC_mostraAtual();
				break;
			case 3:
				printf("Digite o código da disciplina que deseja buscar:\n");
				scanf(" %s", codigo);
				ret = GRC_buscaPorCodigo(codigo);
				GRC_mostraAtual();
				break;
			case 4:
				GRC_mostraTodas();
				break;
			case 5:
				printf("Digite o código da disciplina que deseja configurar como pre-requisito:\n");
				scanf(" %s", codigo);
				ret = GRC_inserePreRequisito(codigo);
				break;
			case 6:
				GRC_removePreRequisitos();
				break;
			case 7:
				GRC_limpa();
				break;
			default:
				if(opcao)
					printf("Opcao inválida!\n");
				break;
		}
		if(ret == GRC_CondRetOk)
			printf("Operacao realizada com sucesso!\n");
		else if(ret == GRC_CondRetNaoHaMemoria)
			printf("ERRO. Nao ha memoria suficiente.\n");
		else if(ret == GRC_CondRetGradeCurricularVazia)
			printf("Ainda nao existe nenhuma disciplina cadastrada.\n");
		else if(ret == GRC_CondRetDisciplinaNaoEncontrada)
			printf("A disciplina solicitada nao foi encontrada.\n");
		else if(ret == GRC_CondRetIdJaCriado)
			printf("ERRO.Ja existe uma Disciplina com este codigo.\n");
		else if(ret == GRC_CondRetFormatoInvalido)
			printf("ERRO. Formato de dados invalido.\n");
		GRC_mostraAtual();
	}while(opcao);
}
