/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Main
*
*  Arquivo gerado:              main.c
*  Letras identificadoras:      MAI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acad�mico da turma 3WB
*  Gestor:  Grupo 1 / Grupo 2 / Grupo 5
*  Autores:   Bruce Marcellino (Grupo 1)
*			  Bruno Miranda Marinho (Grupo 2)
*             Cristiane Ramalho Guimar�es (Grupo 5)
*             Fl�vio Thiago Franco Vaz (Grupo 2)
*             Jo�o Victor Cerqueira (Grupo 2)
*             Matheus Henrique Branco Zeitune (Grupo 2)
*             Vin�cius Cortat (Grupo 2)
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor         Data		Observa��es
*     1.02    Cristiane  15/11/2017     Revis�o/Reestrutura��o
*     1.01    Bruce	     07/10/2017	    Reestrutura��o
*     1.00    Bruce	     06/10/2017     Revis�o/finaliza��o
*     0.05    Bruce	     05/10/2017	    Modulo professor
*     0.04    Matheus    04/10/2017  	Revis�o menu
*     0.03    Bruno      02/10/2017	    Menu professor
*     0.02    Fl�vio	 02/10/2017  	Revis�o
*     0.01    Matheus	 01/10/2017	    In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa o Menu do Sistema Acad�mico a ser desenvolvido.
*     O Principal � a chamada dos modulos.
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
*  $FC Fun��o: menuAnterior
*
*  $ED Descri��o da fun��o
*		Mostra o menu Administrativo.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void menuAnterior (void) 
	{
		printf("\nPressione qualquer tecla para voltar para o menu anterior.\n") ;
		getch() ;
		system("cls") ;
	}


/***********************************************************************
*
*  $FC Fun��o: MEN_menuAluno.
*
*  $ED Descri��o da fun��o
*		Mostra o menu para o aluno.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void menuAluno ( void )
	{
		int opcao = 0 ;
		unsigned int matricula ;
		if ( MEN_loginAluno(&matricula) == 1 ) // Se volta 1, ok.

		do 
		{
			printf( "\nMenu Aluno - Matricula: %d\n", matricula ) ;
			printf( "\nDigite 0: sair" ) ; 
			printf( "\nDigite 1: ver grade curricular" ) ;
			//printf("\nDigite 2: ver horarios");
			//printf("\nDigite 3: ver nota");
		
			printf( "\nDigite 2: modificar dados pessoais" ) ;
			//printf("\nDigite 6: cancelar disciplina");
			//printf("\nDigite 7: trancar a faculdade");
			printf( "\nDigite 3: ver historico\n" ) ;
			//opcao = MEN_leNumero() ;

			switch ( opcao )
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
*  $FC Fun��o: MEN_menuProfessor
*
*  $ED Descri��o da fun��o
*		Mostra o menu Professor.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
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
			
			//opcao = MEN_leNumero() ;

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
*  $FC Fun��o: MEN_menuPAdministrativo
*
*  $ED Descri��o da fun��o
*		Mostra o menu Administrativo.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
***********************************************************************/

	void menuPAdministrativo()
	{
		int opcao = 0, mat ;

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
			//printf("\nDigite 13: modificar grade");
			//printf("\nDigite 4: ver criterio de aprovacao");
			//printf("\nDigite 11: Para ver a ver grade curricular\n\n");

			printf( "\n\nDigite 0: Para sair do Menu Administrativo.\n\n" ) ;

			LER_leInteiro(&opcao, 1, 2, LER_comparaLeSoNumero) ;
			system( "cls" ) ;

			switch( opcao )
			{
				case 1:
					//mostra rela��o de alunos
					printf( "*********** RELACAO DE ALUNOS CADASTRADOS ***********\n\n" ) ;
					if ( CDI_imprime() != CDI_CondRetOK ) 
					{
						printf( "Nenhum aluno cadastrado!\n\n" ) ; 
					} /* if */
					menuAnterior() ;
					break ;
				case 2:
					//adiciona um aluno
					MEN_adicionaAluno() ;
					break ;
				case 3:
					//altera os dados de um aluno
					MEN_modificaAluno() ; 
					break ;
				case 4:
					//remove um aluno
					printf( "\nDigite a matricula: \n" ) ;
					LER_leInteiro(&mat, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero) ;
					CDI_remove( mat ) ;
					menuAnterior() ;
					break;
				case 5:
					//remove todos os alunos
					CDI_limpa() ;
					break ;
				case 6:
					//mostra rela��o de professores
					printf( "*********** RELACAO DE PROFESSORES CADASTRADOS ***********\n\n" ) ;
					if ( CDO_mostraTodos() != CDO_CondRetOk ) 
					{
						printf( "Nenhum professor cadastrado!\n\n" ) ; 
					} /* if */
					menuAnterior() ;
					break ;
				case 7:
					//adiciona um professor
					MEN_adicionaProfessor() ;
					break ;
				case 8:
					//altera os dados de um professor
					MEN_modificaProfessor() ;
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
					menuAnterior() ;
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
*  $FC Fun��o: exibeTelaInicial
*
*  $ED Descri��o da fun��o
*		Mostra o menu Administrativo.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: n�o h� retorno.
/			 Par�mentros: Estruturas de ponteiros.
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
			
			LER_leInteiro(&opcao, 1, 2, LER_comparaLeSoNumero);

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

