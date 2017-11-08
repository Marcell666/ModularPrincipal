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
*     O Principal é a chamada dos modulos.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "aluno.h"
#include "corpodiscente.h"
#include "corpoDocente.h"
#include "gradeCurricular.h"
#include "HISTORICO.h"
#include "menu.h"




/***********************************************************************
*
*  $FC Função: MEN_menuAluno.
*
*  $ED Descrição da função
*		Mostra o menu para o aluno.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void menuAluno()
{
	int opcao = 0;
	unsigned int matricula;
	if(MEN_loginAluno(&matricula) == 1) // Se volta 1, ok.

	do{
		printf("\nMenu Aluno - Matricula: %d\n", matricula);
		printf("\nDigite 0: sair");
		printf("\nDigite 1: ver grade curricular");
		//printf("\nDigite 2: ver horarios");
		//printf("\nDigite 3: ver nota");
		
		printf("\nDigite 2: modificar dados pessoais");
		//printf("\nDigite 6: cancelar disciplina");
		//printf("\nDigite 7: trancar a faculdade");
		printf("\nDigite 3: ver historico\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				system("cls");
				GRC_mostraTodas();
				break;
			case 2:
				system("cls");
				MEN_modificaAluno();
				break;

			case 3:
				system("cls");
				HIS_printHistoricoCompleto(matricula);
				break;
			default:
				if(opcao)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}while(opcao);
}

/***********************************************************************
*
*  $FC Função: MEN_menuProfessor
*
*  $ED Descrição da função
*		Mostra o menu Professor.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void menuProfessor()
{
	int opcao = 0;

	if(MEN_loginProfessor() == 1) // Se volta 1, ok.

	do{
		printf("\nMenu Professor\n");
		printf("\nDigite 0: sair\n");
		printf("\nDigite 1: ver grade curricular");
		//printf("\nDigite X: ver nota");
		//printf("\nDigite X: ver turmas");
		printf("\nDigite 5: modificar dados pessoais");
		scanf("%d", &opcao);

		switch(opcao)
		{	
			case 1:
				system("cls");
				MEN_menuGradeCurricular();
				break;
			case 2:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 3:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 4:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				break;
			case 5:
				system("cls");
				MEN_modificaProfessor();
				break;
			default:
				if(opcao)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}while(opcao);

}


/***********************************************************************
*
*  $FC Função: MEN_menuPAdministrativo
*
*  $ED Descrição da função
*		Mostra o menu Administrativo.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

void menuPAdministrativo()
{
	int opcao = 0, mat;

	if(!MEN_loginAdministrativo()){
		printf("\nErro no login\n");
		return;
	}
	do{
		printf("\nMenu Administrativo\n");
		printf("\nDigite 0: sair");
		printf("\nDigite 1: ver corpo discente");
		printf("\nDigite 2: ver corpo docente");
		//printf("\nDigite 4: ver criterio de aprovacao");
		printf("\nDigite 3: adicionar aluno");
		printf("\nDigite 4: deletar aluno");
		printf("\nDigite 5: adicionar professor");
		printf("\nDigite 6: deletar professor");
		//printf("\nDigite 9: deletar sala");
		//printf("\nDigite 10: adicionar sala");
		//printf("\nDigite 11: deletar turma");
		//printf("\nDigite 12: adicionar turma");
		//printf("\nDigite 13: modificar grade");
		printf("\nDigite 7: modificar dados pessoais de um aluno");
		printf("\nDigite 8: modificar dados pessoais de um professor");
		printf("\nDigite 9: limpa corpo discente");
		printf("\nDigite 10: limpa corpo docente");
		printf("\nDigite 11: MENU grade curricular");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
				//mostra alunos
				system("cls");
				CDI_imprime();
				break;
			case 2:
				//mostra professores
				system("cls");
				if(CDO_mostraTodos()!=CDO_CondRetOk) printf("Nenhum professor cadastrado!\n");
				break;
			case 3:
				MEN_adicionaAluno();
				break;
			case 4:
				//remove aluno
				system("cls");
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				CDI_remove(mat);
				break;
			case 5:
				MEN_adicionaProfessor();
				break;
			case 6:
				//retira professor
				system("cls");
				printf("\nDigite a matricula: \n");
				scanf("%d", &mat);
				if(CDO_buscaPorMatricula(mat)!=CDO_CondRetOk){
					printf("Professor nao encontrado, nao ha professor com esta matricula.");
					break;
				}
				CDO_mostraAtual();
				CDO_retira();
				break;
			case 7:
				//Altera aluno
				MEN_modificaAluno();
				break;
			case 8:
				//Altera professor
				MEN_modificaProfessor();
				break;
			case 9:
				CDI_limpa();
				break;
			case 10:
				CDO_limpa();
				break;
			case 11:
				MEN_menuGradeCurricular();
				break;
			default:
				if(opcao)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}while(opcao);
	system("cls");
}


int main(void){
	int opcao = 0;
	CDO_cria();
	CDI_cria();
	GRC_cria();
	do{
		printf("\nMenu SAU\n");
		printf("\nDigite 0: para sair");
		printf("\nDigite 1: ir menu Aluno");
		printf("\nDigite 2: ir menu Professor");
		printf("\nDigite 3: ir menu Administrativo\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 0:
				system("cls");
				printf("\n\nFechando programa...\n\n");
				CDO_libera();
				GRC_libera();
				exit(0);
				break;
			case 1:
				system("cls");
				// Ir menu Aluno. Area onde o aluno realizar o menu
				menuAluno();
				break;
			case 2:
				system("cls");
				menuProfessor();
				// Ir menu Professor. Area onde o professor realizar o menu
				break;
			case 3:
				system("cls");
				menuPAdministrativo();
				// Ir menu Administrado. Area onde o administrador realizar o menu
				break;
			default:
				if(opcao)
				{
					system("cls");
					printf("\n\nOPCAO INVALIDA!!!!!\n\n");
				}
				break;
		}
	}while(opcao);
	return 0;
}

