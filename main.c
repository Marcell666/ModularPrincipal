/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Main
*
*  Arquivo gerado:              main.c
*  Letras identificadoras:      MAI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 1 / Grupo 2 / Grupo 5
*  Autores:   Bruce Marcellino (Grupo 1)
*			  Bruno Miranda Marinho (Grupo 2)
*             Cristiane Ramalho Guimarães (Grupo 5)
*             Flávio Thiago Franco Vaz (Grupo 2)
*             João Victor Cerqueira (Grupo 2)
*             Matheus Henrique Branco Zeitune (Grupo 2)
*             Vinícius Cortat (Grupo 2)
*
*  $HA Histórico de evolução:
*     Versão  Autor         Data		Observações
*     1.03    Bruce/Cris 25/11/2017     Revisão/finalização
*     1.02    Cristiane  15/11/2017     Revisão/Reestruturação
*     1.01    Bruce	     07/10/2017	    Reestruturação
*     1.00    Bruce	     06/10/2017     Revisão/finalização
*     0.05    Bruce	     05/10/2017	    Modulo professor
*     0.04    Matheus    04/10/2017  	Revisão menu
*     0.03    Bruno      02/10/2017	    Menu professor
*     0.02    Flávio	 02/10/2017  	Revisão
*     0.01    Matheus	 01/10/2017	    Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa o Menu do Sistema Acadêmico a ser desenvolvido.
*     O Principal é a chamada dos modulos.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#ifdef __linux__
	#include "conio.h"
#else
	#include <conio.h>
#endif

#include "aluno.h"
#include "corpodiscente.h"
#include "corpoDocente.h"
#include "gradeCurricular.h"
#include "HISTORICO.h"
#include "menu.h"
#include "leitura.h"


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

	void menuAluno ( void )
	{
		int opcao = 0 ;
		unsigned int matricula ; 
		
		if ( MEN_loginAluno(&matricula) == 1 ) // Se retornar 1 o aluno esta cadastrado.
		{ 
			do 
			{
				printf( "\n*********** MENU ALUNO - MATRICULA: %d ***********\n", matricula ) ;
			
				printf( "\nDigite 1: Para alterar seus dados pessoais." ) ;
				printf( "\nDigite 2: Para a ver grade curricular." ) ;
				//printf("\nDigite 2: ver horarios");
				//printf("\nDigite 3: ver nota");
		
				//printf("\nDigite 6: cancelar disciplina");
				//printf("\nDigite 7: trancar a faculdade");
				printf( "\nDigite 3: Para ver historico.\n" ) ;
				printf( "\n\nDigite 0: Para sair do Menu Aluno.\n\n" ) ; 

				LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

				switch ( opcao )
				{
					case 1:
						system( "cls" ) ;
						MEN_modificaAluno();
						break;
					case 2:
						system( "cls" ) ;
						GRC_mostraTodas();
						break ;
					case 3:
						system( "cls" ) ;
						HIS_printHistoricoCompleto(matricula) ;
						break ;
					default:
						if ( opcao )
						{
							system( "cls" ) ;
							printf( "\n\nOPCAO INVALIDA!!!!!\n\n" ) ;
						}
						break ;
				}
			} while ( opcao ) ;
		}
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

	void menuProfessor ( void )
	{
		int opcao = 0, matricula ;

		if ( !MEN_loginProfessor(&matricula)){ // Se volta 0, não ok.
			printf( "Nao existe professor cadastrado com este numero de matricula %d, por favor tente novamente\n", matricula ) ;
			MEN_menuAnterior();
			return;
		}

		do
		{
			printf( "\n*********** MENU PROFESSOR - MATRICULA: %d ***********\n", matricula ) ;
			
			printf( "\nDigite 1: Para alterar seus dados pessoais." ) ;
			printf( "\nDigite 2: Para ver a grade curricular" ) ;
			//printf("\nDigite X: ver nota");
			//printf("\nDigite X: ver turmas");
			//printf("\nDigite 5: modificar dados pessoais");
			printf( "\n\nDigite 0: Para sair do Menu Professor.\n\n" ) ; 

			LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

			switch(opcao)
			{	
				case 1:
					system("cls");
					MEN_modificaProfessor();
					break; 
				case 2:
					system("cls");
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
		int opcao = 0, mat ;
		unsigned int uMat;

		if ( !MEN_loginAdministrativo() )
		{
			printf( "\nErro no login\n" ) ;
			return ;
		} /* if */

		do
		{
			printf( "\n*********** MENU ADMINISTRATIVO ***********\n" ) ;
			
			printf( "\nALUNO" ) ;
			printf( "\nDigite 1: Para exibir a relacao de alunos." ) ;
			printf( "\nDigite 2: Para cadastrar um aluno." ) ;
			printf( "\nDigite 3: Para modificar os dados pessoais de um aluno." ) ;
			printf( "\nDigite 4: Para deletar um aluno." ) ;
			printf( "\nDigite 5: Para apagar os dados de todos os alunos." ) ;
			
			printf( "\n\nPROFESSOR" ) ;
			printf( "\nDigite 6: Para exibir a relacao de professores." ) ;
			printf( "\nDigite 7: Para cadastrar um professor." ) ;
			printf( "\nDigite 8: Para modificar os dados pessoais de um professor." ) ;
			printf( "\nDigite 9: Para deletar um professor." ) ;
			printf( "\nDigite 10: Para apagar os dados de todos os professores." ) ;

			printf( "\n\nGRADE CURRICULAR" ) ;
//			printf( "\nDigite 11: Para acessar o menu da Grade Curricular." ) ;
			printf( "\nDigite 11: Para exibir a relacao de disciplinas." ) ;
			printf( "\nDigite 12: Para cadastrar uma disciplina." ) ;
			printf( "\nDigite 13: Para modificar uma disciplina." ) ;
			printf( "\nDigite 14: Para remover uma disciplina." ) ;
			printf( "\nDigite 15: Para apagar os dados de todas as disciplinas." ) ;

			//printf("\nDigite 9: deletar sala");
			//printf("\nDigite 10: adicionar sala");
			//printf("\nDigite 12: adicionar turma");
			//printf("\nDigite 4: ver criterio de aprovacao");

			printf( "\n\nDigite 0: Para sair do Menu Administrativo.\n\n" ) ;

			LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;
			
			system( "cls" ) ;

			switch( opcao )
			{
				case 1:
					//mostra relação de alunos
					printf( "*********** RELACAO DE ALUNOS CADASTRADOS ***********\n\n" ) ;
					CDI_imprime() ;
					MEN_menuAnterior() ;
					break ;
				case 2:
					//adiciona um aluno
					MEN_adicionaAluno() ;
					break ;
				case 3:
					//altera os dados de um aluno

					if(MEN_loginAluno(&uMat))
						MEN_modificaAluno() ; 
					else
						printf( "Nao existe aluno cadastrado com este numero de matricula %d, por favor tente novamente\n", mat) ;
					break ;

					break ;
				case 4:
					//remove um aluno
					printf( "\nDigite a matricula: \n" ) ;
					LER_leInteiro( &mat, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;
					CDI_remove( mat ) ;
					MEN_menuAnterior() ;
					break;
				case 5:
					//remove todos os alunos
					CDI_limpa() ;
					break ;
				case 6:
					//mostra relação de professores
					printf( "*********** RELACAO DE PROFESSORES CADASTRADOS ***********\n\n" ) ;
					if ( CDO_mostraTodos() != CDO_CondRetOk ) 
					{
						printf( "Nenhum professor cadastrado!\n\n" ) ; 
					} /* if */
					MEN_menuAnterior() ;
					break ;
				case 7:
					//adiciona um professor
					MEN_adicionaProfessor() ;
					break ;
				case 8:
					//altera os dados de um professor

					if(MEN_loginProfessor(&mat))
						MEN_modificaProfessor() ;
					else
						printf( "Nao existe professor cadastrado com este numero de matricula %d, por favor tente novamente\n", mat ) ;
					break ;
				case 9:
					//remove um professor
					MEN_removeProfessor() ;
					break ;
				case 10:
					//remove todos os professores
					MEN_removeTodosProfessores() ;
					break ;
				case 11:
					printf( "*********** RELACAO DE DISCIPLINAS CADASTRADAS ***********\n\n" ) ;
					if ( GRC_mostraTodas() != GRC_CondRetOk ) 
					{
						printf( "Nenhuma disciplina cadastrada!\n\n" ) ; 
					} /* if */
					MEN_menuAnterior() ;
					break ;				
				case 12:
					MEN_adicionaDisciplina();
					//GRC_cadastraCMD();
					break ;
				case 13:
					MEN_modificaDisciplina();
					break ;
				case 14:
					MEN_removeDisciplina();
					break ;
				case 15:
					MEN_removeTodasDisciplinas();
					break ;			
				default:
					if ( opcao )
					{
						system( "cls" ) ;
						printf( "\n\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
					} /* if */
					break ;
			}

		} while ( opcao ) ;

		system ( "cls" ) ; 
	}

/***********************************************************************
*
*  $FC Função: exibeTelaInicial
*
*  $ED Descrição da função
*		Mostra o menu Administrativo.
*
***********************************************************************/
/*Assertivas: Retorno da função: não há retorno.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void exibeTelaInicial() 
	{
		printf("**************************************************\n");
		printf("**                                              **\n");
		printf("**                                              **\n");
		printf("**                                              **\n");
		printf("**     SEJA BEM VINDO AO SISTEMA ACADEMICO      **\n");
		printf("**                DA TURMA 3WB                  **\n");
		printf("**           DE PROGRAMACAO MODULAR             **\n");
		printf("**                                              **\n");
		printf("**                                              **\n");
		printf("**                                              **\n");
		printf("**************************************************\n");
		printf("\n\n Pressione qualquer tecla para acessar o sistema\n");
		getch();
		system("cls");
	}



	int main ( void )
	{
		int opcao = 0 ;
		
		CDO_cria() ;
		CDI_cria() ;
		GRC_cria() ;

		exibeTelaInicial() ;

		do
		{
			printf( "\n*********** SISTEMA ACADEMICO ***********\n" ) ;
			printf( "\nDigite 1: Para acessar Menu do Aluno" ) ;
			printf("\nDigite 2: Para acessar Menu do Professor" ) ;
			printf( "\nDigite 3: Para acessar Menu Administrativo" ) ;
			printf( "\n\nDigite 0: Para sair\n\n" ) ;
			
			LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

			switch ( opcao )
			{
				case 0:
					system( "cls" ) ;
					printf( "\n\nFechando programa...\n\n" ) ;
					CDO_libera() ;
					GRC_libera() ;
					exit(0) ;
					break ;
				case 1:
					system( "cls" ) ;
					// Ir menu Aluno. Area onde o aluno realizar o menu
					menuAluno() ;
					break ;
				case 2:
					system( "cls" ) ;
					menuProfessor() ;
					// Ir menu Professor. Area onde o professor realizar o menu
					break ;
				case 3:
					system( "cls" ) ;
					menuPAdministrativo() ;
					// Ir menu Administrado. Area onde o administrador realizar o menu
					break ;
				default:
					if( opcao )
					{
						system( "cls" ) ;
						printf( "\n\nOPCAO INVALIDA!!!!!\n\n" ) ;
					} /* if */
					break ;
			}
		} while ( opcao ) ;
		
		return 0 ;
}
