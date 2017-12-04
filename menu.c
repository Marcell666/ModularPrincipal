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
*  Gestor:  Grupo 1 / Grupo 2 / Grupo 5
*  Autores:   Bruce Marcellino (Grupo 1)
*	      Bruno Miranda Marinho (Grupo 2)
*             Cristiane Ramalho Guimarães (Grupo 5)
*             Flávio Thiago Franco Vaz (Grupo 2)
*             João Victor Cerqueira (Grupo 2)
*             Matheus Henrique Branco Zeitune (Grupo 2)
*             Vinícius Cortat (Grupo 2)
*
*  $HA Histórico de evolução:
*     Versão  Autor         Data		Observações
*     1.05    Bruce	30/11/2017	Inserção das salas
*     1.04    Bruce/Cris 25/11/2017     Revisão/finalização
*     1.03    Cristiane  14/11/2017     Reestruturação
*     1.02    Cristiane  08/11/2017     Funções de leitura
*     1.01    Bruce	     07/10/2017     Reestruturação
*     1.00    Bruce	     06/10/2017	    Revisão/finalização
*     0.05    Bruce	     05/10/2017	    Modulo professor
*     0.04    Matheus    04/10/2017  	Revisão menu
*     0.03    Bruno	     02/10/2017	    Menu professor
*     0.02    Flávio     02/10/2017  	Revisão
*     0.01    Matheus    01/10/2017	    Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa o Menu do Sistema Acadêmico a ser desenvolvido.
*     O meu é a chamada dos modulos por interface.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#ifdef __linux__
	#include "conio.h"
#else
	#include <conio.h>
#endif	

#include "menu.h"
#include "corpodiscente.h"
#include "aluno.h"
#include "corpoDocente.h"
#include "gradeCurricular.h"
#include "CorpoSala.h"
#include "leitura.h"

#ifdef __linux__
	#define VK_ENTER 10
	#define VK_BACKSPACE 127
#else
	
	#define VK_ENTER 13
	#define VK_BACKSPACE 8
#endif

/*****  Protótipos das funções encapsuladas no módulo  *****/

	int MEN_comparaLeCodigoGRC ( unsigned char c ) ;
	int MEN_comparaLePredioSAL ( unsigned char c ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: MEN  &Login Administrativo
*  ****/

	int MEN_loginAdministrativo ( void )
	{

		char user[MEN_TAM_STRING];
		char senha[MEN_TAM_STRING];
		return 1;	// TODO retirar isto
		printf("\nLogin Administrador\n");

		printf("\t\t Dica: use \"admin\", \"admin\".\n");	// TODO retirar isto

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

	} /* Fim função: MEN  &Login Administrativo */

/***************************************************************************
*
*  Função: MEN  &Login Professor
*  ****/

	int MEN_loginProfessor ( int * matricula )

	{

		printf( "*********** LOGIN PROFESSOR ***********\n\n" ) ;

		printf( "\nDigite a matricula (8 digitos): " ) ;
		LER_leInteiro( matricula, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;
		printf("\n");
		if( CDO_buscaPorMatricula(*matricula) == CDO_CondRetOk )
		{
			system( "cls" ) ;
			return 1 ;
		}

		return 0 ;

	} /* Fim função: MEN  &Login Professor */

/***************************************************************************
*
*  Função: MEN  &Login Aluno
*  ****/

	int MEN_loginAluno ( unsigned int * matricula )
	{
		int mat ;
		Aluno* Al ;

		printf( "*********** LOGIN ALUNO ***********\n\n" ) ;

		printf( "\nDigite a matricula (8 digitos): " ) ;
		LER_leInteiro( &mat, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;
		printf( "\n" ) ;

		if( CDI_busca(mat,&Al) == CDI_CondRetAlunoNaoCadastrado )
		{
			printf("Matricula invalida\n");
			printf("\nPressione qualquer tecla para voltar para o menu anterior.\n") ;
			getch() ;
			system( "cls" ) ;
			return 0;
		}

		* matricula = (unsigned int) mat ;
		system( "cls" ) ;
		return 1 ;

	} /* Fim função: MEN  &Login Aluno */

/***************************************************************************
*
*  Função: MEN  &Adiciona Aluno
*  ****/

	void MEN_adicionaAluno ( void )
	{

		char nome[MEN_TAM_STRING] ;
		int mat, telefone ;
		Data nasc ; 
		Endereco end ;
		char cpf_completo[MEN_TAM_CPF] ;
		CPF cpf ;
		CDI_tpCondRet retBusca ;

		system( "cls" ) ;
		printf( "\n*********** CADASTRO DE ALUNO ***********\n" ) ;
				
		//adiciona aluno
		printf( "\nNome: \n" ) ;
		LER_leString( nome, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;

		printf( "\nNumero da matricula (8 digitos): \n" ) ;
		LER_leInteiro( &mat, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;

		printf( "\nNumero do CPF (11 digitos): \n" ) ;
		LER_leString( cpf_completo, LER_TAM_CPF, LER_TAM_CPF, LER_comparaLeSoNumero) ;
		cpf.cod = atoi( cpf_completo+9 ) ;
		cpf_completo[9] = '\0' ;
		cpf.dig3 = atoi( cpf_completo+6 ) ;
		cpf_completo[6] = '\0' ;
		cpf.dig2 = atoi( cpf_completo+3 ) ;
		cpf_completo[3] = '\0' ; 
		cpf.dig1 = atoi( cpf_completo ) ;

		printf( "\nData de nascimento:\n" ) ;
		LER_leData( &nasc.dia, &nasc.mes, &nasc.ano ) ;

		printf( "\nNumero do telefone (8 ou 9 digitos):\n" ) ;
		LER_leInteiro( &telefone, LER_MIN_TEL, LER_MAX_TEL, LER_comparaLeSoNumero ) ;

		printf( "\nInforme o endereco:" );
		printf( "\nLogradouro:\n" ) ;
		LER_leString( end.rua, 1, LER_TAM_STRING, LER_comparaLeLogradouro) ;

		printf( "\nNumero:\n" ) ;
		LER_leInteiro( &end.numero, LER_MIN_NUM, LER_MAX_NUM, LER_comparaLeSoNumero ) ;
		
		printf( "\nComplemento:\n" ) ;
		LER_leString( end.comp, 0, LER_TAM_STRING, LER_comparaLeComplemento) ;

		printf( "\nBairro:\n" ) ;
		LER_leString( end.bairro, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;

		printf( "\nCidade:\n" ) ;
		LER_leString( end.cidade, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;		

		printf( "\nEstado (sigla):\n") ;
		LER_leUF( end.estado ) ;

		retBusca = CDI_insere( nome, (unsigned int)mat, &cpf, (unsigned int)telefone, &nasc, &end ) ;

		if ( retBusca == CDI_CondRetAlunoJaCadastrado )
		{
			printf( "Aluno ja cadastrado." ) ;
		} else
			if ( retBusca == CDI_CondRetFaltouMemoria )
			{
				printf( "Erro de memoria ao cadastrar." ) ;
			} else
			{
				system( "cls" ) ;
				printf( "\nAluno cadastrado com sucesso!\n\n" ) ;
				CDI_imprimeInfo ( (unsigned int)mat ) ;
			} /* if */
		
		MEN_menuAnterior() ;
		return ;

	} /* Fim função: MEN  &Adiciona Aluno */

/***************************************************************************
*
*  Função: MEN  &Modifica Aluno
*  ****/

	void MEN_modificaAluno ( unsigned int matAnt )
	{

		char nome[MEN_TAM_STRING], cpf_completo[MEN_TAM_CPF] ;
		int mat, telefone ;
		Data nasc ; 
		Endereco end ;
		CPF cpf ;
		int opcao ;
		CDI_tpCondRet ret ;

		printf( "\n*********** EDITAR DADOS DE ALUNO ***********\n\n" ) ;

		do
		{
			printf( "\nALUNO:\n" ) ;
			CDI_imprimeInfo( (unsigned int)matAnt ) ;
			printf( "\n\nEscolha o dado a ser alterado: \n\n" ) ;
			printf( "1: Nome\n" ) ;
			printf( "2: Matricula\n" ) ;
			printf( "3: Telefone\n" ) ;
			printf( "4: Data de nascimento\n" ) ;
			printf( "5: CPF\n" ) ;
			printf( "6: Endereco\n" ) ;
			printf( "\n0: Voltar ao menu anterior\n" ) ;
			
			LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

			system("cls") ;

			switch( opcao )
			{
				case 1: 
					printf( "\nNovo nome: \n" ) ;
					LER_leString( nome, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;
					ret = CDI_altera( matAnt, nome, 0, NULL, 0, NULL, NULL ) ;
					break ;
				case 2:
					printf( "\nNova matricula (8 digitos): \n" ) ;
					LER_leInteiro( &mat, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;
					ret = CDI_altera( matAnt, NULL, (unsigned int)mat, NULL, 0, NULL, NULL ) ;
					break ;
				case 3:
					printf( "\nNovo telefone (8 ou 9 digitos): \n" ) ;
					LER_leInteiro( &telefone, LER_MIN_TEL, LER_MAX_TEL, LER_comparaLeSoNumero ) ;
					ret = CDI_altera( matAnt, NULL, 0, NULL, (unsigned int)telefone, NULL, NULL ) ;
					break ;
				case 4:
					printf( "\nNova data de nascimento: \n" ) ;
					LER_leData( &nasc.dia, &nasc.mes, &nasc.ano ) ;
					ret = CDI_altera( matAnt, NULL, 0, NULL, 0, &nasc, NULL ) ;
					break ;
				case 5:
					printf( "\nNovo CPF (11 digitos): \n" ) ;
					LER_leString( cpf_completo, LER_TAM_CPF, LER_TAM_CPF, LER_comparaLeSoNumero) ;
					cpf.cod = atoi( cpf_completo+9 ) ;
					cpf_completo[9] = '\0' ;
					cpf.dig3 = atoi( cpf_completo+6 ) ;
					cpf_completo[6] = '\0' ;
					cpf.dig2 = atoi( cpf_completo+3 ) ;
					cpf_completo[3] = '\0' ;
					cpf.dig1 = atoi( cpf_completo ) ;
					ret = CDI_altera( matAnt, NULL, 0, &cpf, 0, NULL, NULL ) ;
					break ;
				case 6:
					printf( "\nInforme o novo endereco do aluno:" ) ;
					printf( "\nLogradouro:\n" ) ;
					LER_leString( end.rua, 1, LER_TAM_STRING, LER_comparaLeLogradouro) ;
					printf( "\nNumero:\n" ) ;
					LER_leInteiro( &end.numero, LER_MIN_NUM, LER_MAX_NUM, LER_comparaLeSoNumero ) ;
					printf( "\nComplemento:\n" ) ;
					LER_leString( end.comp, 0, LER_TAM_STRING, LER_comparaLeComplemento) ;
					printf( "\nBairro: \n" ) ;
					LER_leString( end.bairro, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;
					printf( "\nCidade: \n" ) ;
					LER_leString( end.cidade, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;	
					printf( "\nEstado (sigla): \n" ) ;
					LER_leUF( end.estado ) ;
					ret = CDI_altera( matAnt, NULL, 0, NULL, 0 , NULL, &end ) ;
					break ;
				default:
					if ( opcao )
					{
						system( "cls" ) ;
						printf( "\n\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
					} /* if */
					break;
			}

			if ( ret == CDI_CondRetOK )
			{
				printf( "\nDados alterados com sucesso!\n\n" ) ;

				if ( opcao == 2 )
				{
					CDI_imprimeInfo( (unsigned int)mat ) ;
				}
				else
				{
					CDI_imprimeInfo( (unsigned int)matAnt ) ;
				} /* if */

				MEN_menuAnterior() ;
				return ;
			} /* if */

		} while ( opcao ) ;

	} /* Fim função: MEN  &Modifica Aluno */

/***************************************************************************
*
*  Função: MEN  &Adiciona Professor
*  ****/

	void MEN_adicionaProfessor ( void )
	{
		int rg, matricula, telefone ;
		int dia, mes, ano ;
		char nome[MEN_TAM_STRING], cpf[MEN_TAM_CPF], email[MEN_TAM_STRING] ;
		char pais[MEN_TAM_STRING], uf[MEN_TAM_UF], cidade[MEN_TAM_STRING], bairro[MEN_TAM_STRING], rua[MEN_TAM_STRING], complemento[MEN_TAM_STRING] ;
		int numero ;
		CDO_tpCondRet ret ;

		system( "cls" ) ;
		printf( "\n*********** CADASTRO DE PROFESSOR(A) ***********\n\n" ) ;

		//Adiciona professor
		printf( "Nome: \n" ) ;
		LER_leString( nome, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;

		printf( "\nNumero do RG (9 digitos): \n") ;
		LER_leInteiro( &rg, LER_TAM_RG, LER_TAM_RG, LER_comparaLeSoNumero ) ;

		printf( "\nNumero do CPF (11 digitos): \n" ) ;
		LER_leString( cpf, LER_TAM_CPF, LER_TAM_CPF, LER_comparaLeSoNumero) ;

		printf( "\nNumero da matricula (8 digitos): \n" ) ;
		LER_leInteiro( &matricula, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;

		printf( "\nData de nascimento: \n" ) ;
		LER_leData( &dia, &mes, &ano ) ;

		printf("\nNumero do telefone (8 ou 9 digitos): \n") ;
		LER_leInteiro( &telefone, LER_MIN_TEL, LER_MAX_TEL, LER_comparaLeSoNumero ) ;

		printf( "\nEmail: \n" ) ;
		LER_leString( email, 5, LER_TAM_STRING, LER_comparaLeEmail) ;

		printf( "\nInforme o endereco:" ) ;
		printf( "\nLogradouro:\n" ) ;
		LER_leString( rua, 1, LER_TAM_STRING, LER_comparaLeLogradouro) ;

		printf( "\nNumero:\n" ) ;
		LER_leInteiro( &numero, LER_MIN_NUM, LER_MAX_NUM, LER_comparaLeSoNumero ) ;

		printf( "\nComplemento:\n" ) ;
		LER_leString( complemento, 0, LER_TAM_STRING, LER_comparaLeComplemento) ;

		printf( "\nBairro:\n" ) ;
		LER_leString( bairro, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;

		printf( "\nCidade:\n" ) ;
		LER_leString( cidade, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;	

		printf( "\nEstado (sigla):\n" ) ;
		LER_leUF( uf ) ;

		printf( "\nPais: \n" ) ;
		LER_leString( pais, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;	

		ret = CDO_cadastra( nome, rg, cpf, matricula, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, complemento ) ;
		
		if ( ret == CDO_CondRetOk )
		{
			system( "cls" ) ;
			printf( "\nProfessor cadastrado com sucesso!\n\n" ) ;
			CDO_buscaPorMatricula( matricula ) ;
			CDO_mostraAtual() ;
		} else
			if ( ret == CDO_CondRetFormatoInvalido )
			{
				printf( "\nERRO. Formato de dados invalido.\n" ) ;
			} else
				if ( ret == CDO_CondRetIdJaCriado )
				{
					printf( "\nERRO. Ja existe um professor com este valor de identificacao.\n" ) ;
				} /* if */

		MEN_menuAnterior() ;
		return ;

	} /* Fim função: MEN  &Adiciona Professor */

/***************************************************************************
*
*  Função: MEN  &Modifica Professor
*  ****/

	void MEN_modificaProfessor ( void )
	{

		char nomeFunc[][30] = { 
					"Voltar ao menu anterior.", 
					"Nome", 
					"RG", 
					"CPF", 
					"Matricula", 
					"Email", 
					"Telefone", 
					"Data", 
					"Endereco" 
		} ;
		int nAlteras = 9, i ;
		CDO_alteraInt funcInt[] = { NULL, NULL, CDO_alteraRg, NULL, CDO_alteraMatricula, NULL,CDO_alteraTelefone, NULL, NULL } ;
		CDO_alteraString funcString[] = {NULL, CDO_alteraNome, NULL, CDO_alteraCpf, NULL, CDO_alteraEmail, NULL, NULL, NULL } ; 
		int paramInt, dia, mes, ano ; 
		char paramString[MEN_TAM_STRING] ;
		char pais[MEN_TAM_STRING], uf[MEN_TAM_STRING], cidade[MEN_TAM_STRING], bairro[MEN_TAM_STRING], rua[MEN_TAM_STRING], complemento[MEN_TAM_STRING] ;
		int numero ;
		CDO_tpCondRet ret ;
		int opcao ;

		system( "cls" ) ;
		printf( "\n*********** EDITAR DADOS DE PROFESSOR(A) ***********\n" ) ;
				
		do
		{
			printf( "PROFESSOR:\n" ) ;
			CDO_mostraAtual() ;
			printf( "\nEscolha o dado a ser alterado: \n\n" ) ;

			for ( i = 1; i < nAlteras; i++ )
			{
				printf( "%d: %s.\n", i, nomeFunc[i] ) ;
			} /* for */

			printf( "\n0: %s.\n\n", nomeFunc[0] ) ;

			LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;
			
			switch( opcao )
			{
				case 1:
					//Nome
					printf( "\nNovo %s:\n", nomeFunc[opcao] ) ;
					LER_leString( paramString, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;
					ret = funcString[opcao](paramString) ;
					break ;
				case 2: 
					//RG
					printf( "\nNovo %s:\n", nomeFunc[opcao] ) ;
					LER_leInteiro( &paramInt, LER_TAM_RG, LER_TAM_RG, LER_comparaLeSoNumero ) ;
					ret = funcInt[opcao](paramInt) ;
					break ;
				case 3:
					//CPF
					printf( "\nNovo %s:\n", nomeFunc[opcao] ) ;
					LER_leString( paramString, LER_TAM_CPF, LER_TAM_CPF, LER_comparaLeSoNumero) ;
					ret = funcString[opcao](paramString) ;
					break ;
				case 4: 
					//Matricula
					printf( "\nNovo %s:\n", nomeFunc[opcao] ) ;
					LER_leInteiro( &paramInt, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;
					ret = funcInt[opcao](paramInt) ;
					break ;
				case 5: 
					//Email
					printf( "\nNovo %s:\n", nomeFunc[opcao] ) ;
					LER_leString( paramString, 5, LER_TAM_STRING, LER_comparaLeEmail) ;
					ret = funcString[opcao](paramString) ;
					break ;
				case 6: 
					//Telefone
					printf( "\nNovo %s:\n", nomeFunc[opcao] ) ;
					LER_leInteiro( &paramInt, LER_MIN_TEL, LER_MAX_TEL, LER_comparaLeSoNumero ) ;
					ret = funcInt[opcao](paramInt) ;
					break ;
				case 7:
					//Data
					printf( "\nNova data de nascimento: \n" ) ;
					LER_leData( &dia, &mes, &ano ) ;
					ret = CDO_alteraDataNascimento( dia, mes, ano ) ;
					break ;
				case 8:
					//Nascimento
					printf( "\nInforme o novo endereco:" ) ;
					printf("\nLogradouro:\n") ;
					LER_leString( rua, 1, LER_TAM_STRING, LER_comparaLeLogradouro) ;
					printf( "\nNumero:\n" ) ;
					LER_leInteiro( &numero, LER_MIN_NUM, LER_MAX_NUM, LER_comparaLeSoNumero ) ;
					printf( "\nComplemento:\n" ) ;
					LER_leString( complemento, 0, LER_TAM_STRING, LER_comparaLeComplemento) ;
					printf( "\nBairro:\n" ) ;
					LER_leString( bairro, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;
					printf( "\nCidade:\n" ) ;
					LER_leString( cidade, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;	
					printf( "\nEstado (sigla):\n" ) ;
					LER_leUF( uf ) ;
					printf( "\nPais:\n" ) ;
					LER_leString( pais, 1, LER_TAM_STRING, LER_comparaLeSoLetra) ;	
					ret = CDO_alteraEndereco( pais, uf, cidade, bairro, rua, numero, complemento ) ;
					break ;
				default:
					if ( opcao )
					{
						system( "cls" ) ;
						printf( "\n\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
					} /* if */
					break ;
			} /* switch */
					
			if ( ret == CDO_CondRetOk )
			{
				system( "cls" ) ;
				printf( "Alteracao realizada com sucesso!\n\n" ) ;
				CDO_mostraAtual() ;
			} else
				if ( ret == CDO_CondRetFormatoInvalido )
				{
					printf( "ERRO. Formato de dados invalido.\n" ) ;
				} else
					if ( ret == CDO_CondRetIdJaCriado )
					{
						printf( "ERRO. Ja existe um professor com este valor de identificacao.\n" ) ;
					} /* if */

		} while ( opcao ) ;

	}  /* Fim função: MEN  &Modifica Professor */

/***************************************************************************
*
*  Função: MEN  &Remove Professor
*  ****/

	void MEN_removeProfessor ( void )
	{
		int mat, opcao ;
		CDO_tpCondRet ret ;

		printf( "\n*********** REMOVE PROFESSOR(A) ***********\n" ) ;
		
		printf( "\nDigite a matricula do professor que deseja remover permanentemente da relacao de professores: \n" ) ;

		LER_leInteiro( &mat, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero ) ;
	
		if ( CDO_buscaPorMatricula(mat) != CDO_CondRetOk )
		{
			printf( "Nao existe professor cadastrado com este numero de matricula %d.\n", mat ) ;
			MEN_menuAnterior() ;
		} else
		{
			do
			{
				printf ("\nPROFESSOR(A):\n") ;
				CDO_mostraAtual() ;
				printf("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DESTE PROFESSOR?\n\n") ;
				printf( "\nDigite: \n" ) ;
				printf("1: Para SIM.\n") ;
				printf("0: Para NAO.\n\n") ;

				LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

				switch( opcao )
				{
					case 1:
						ret = CDO_retira() ;
						if ( ret == CDO_CondRetOk )
						{
							printf ("\nDados do professor removido com sucesso!\n");
							MEN_menuAnterior() ;
							return ;
						} /* if */
						break ;
					default:
						if ( opcao )
						{
							system( "cls" ) ;
							printf( "\n\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
						} /* if */
						break ;
				} /* switch */

			} while ( opcao ) ;

			MEN_menuAnterior() ;
			return ;

		}/* if */
	
	} /* Fim função: MEN  &Remove Professor */

/***************************************************************************
*
*  Função: MEN  &Remove Todos Professores
*  ****/

	void MEN_removeTodosProfessores ( void )
	{
		int opcao ;

		do
			{
				printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DE TODOS OS PROFESSORES CADASTRADOS?\n\n") ;
				printf( "\nDigite: \n" ) ;
				printf("1: Para SIM.\n") ;
				printf("0: Para NAO.\n\n") ;

				LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

				switch( opcao )
				{
					case 1:
						CDO_limpa() ;
						printf ("\nTodos os dados de todos os professores foram removidos com sucesso!\n");
						MEN_menuAnterior() ;
						return ;
						//break ;
					default:
						if ( opcao )
						{
							system( "cls" ) ;
							printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
						} /* if */
						break ;
				} /* switch */

			} while ( opcao ) ;

		printf ("\nNenhum o dado de nenhum professor foi removido.\n");
		MEN_menuAnterior() ;
		return ;

	} /* Fim função: MEN  &Remove Todos Professores */

/***************************************************************************
*
*  Função: MEN  &Adiciona Disciplina
*  ****/

	void MEN_adicionaDisciplina ( void )
	{

		//TODO trocar isso por define
		char nome[MEN_MAX_NOME] ;
		char codigo[MEN_MAX_CODIGO] ;
		char bibliografia[MEN_MAX_BIBLIOGRAFIA] ;
		char ementa[MEN_MAX_EMENTA] ;
		int creditos ;
		int criterio ;
		GRC_tpCondRet ret ;

		system( "cls" ) ;
		printf( "\n*********** CADASTRO DE DISCIPLINA ***********\n" ) ;
				
		//adiciona aluno
		printf( "\nNome da disciplina: \n" ) ;
		LER_leString( nome, 1, MEN_MAX_NOME, LER_comparaLeSoLetra) ;


		printf( "\nCodigo da disciplina: \n" ) ;
		LER_leStringConverte( codigo, 4, 8, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;

		printf( "\nBibliografia da disciplina: \n" ) ;
		LER_leString( bibliografia, 1, MEN_MAX_BIBLIOGRAFIA, LER_comparaLeComplemento) ;

		printf( "\nEmenta da disciplina: \n" ) ;
		LER_leString( ementa, 1, MEN_MAX_EMENTA, LER_comparaLeLogradouro) ;
	
		printf( "\nQuantidade de creditos da disciplina: \n" ) ;
		LER_leInteiro(&creditos, 1, 2, LER_comparaLeSoNumero) ;

		do
		{
			printf( "\nCriterio da disciplina: \n" ) ;
			LER_leInteiro( &criterio, 1, 1, LER_comparaLeSoNumero ) ;
			if ( criterio < 1 || 5 < criterio )
			{
				printf( "O Criterio deve ser um numero de 1 ate 5.\n" ) ;
			}
		} while( criterio < 1 || 5 < criterio ) ;
		
		ret = GRC_cadastra( nome, codigo, creditos, bibliografia, ementa, criterio ) ;

		if ( ret == GRC_CondRetIdJaCriado )
		{
			printf( "Disciplina ja cadastrada.\n" ) ;
		} else 
		{
			if ( ret == GRC_CondRetNaoHaMemoria )
			{
				printf( "Erro de memoria ao cadastrar disciplina." ) ;
			} else
			{
				system( "cls" ) ;
				printf( "\nDisciplina cadastrada com sucesso!\n\n" ) ;
				GRC_mostraAtual () ;
			} /* if */
		} /* if */

		MEN_menuAnterior() ;

	} /* Fim função: MEN  &Adiciona Disciplina */

/***************************************************************************
*
*  Função: MEN  &Modifica Disciplina
*  ****/

	void MEN_modificaDisciplina ( void )
	{

		char nomeFunc[][40] = {
				"voltar ao menu anterior.",
				"mostrar a disciplina atual",
				"buscar outra disciplina",
				"inserir um Pre-Requisito",
				"remover todos os Pre-Requisitos",
				"inserir uma turma",
				"exibir as turmas de uma disciplina"
		} ;
		char codigo[MEN_MAX_CODIGO], codTur[MEN_COD_TUR], diaSem[MEN_DIA_SEMANA] ;

		int horIni, horTer, qtdVag ;
		int nOpcoes = 7, i ;
		GRC_tpCondRet ret ;
		int opcao ;

		system( "cls" ) ;
		printf( "\n*********** EDITAR DADOS DE DISCIPLINA ***********\n" ) ;
		
		do
		{
			printf( "\nDisciplina:\n" ) ;
			GRC_mostraAtual() ;
			printf( "\n\nEscolha o dado a ser alterado: \n\n" ) ;

			for ( i = 1; i < nOpcoes; i++ )
			{
				printf( "%d: %s.\n", i, nomeFunc[i] ) ;
			} /* for */

			printf( "\n0: %s.\n", nomeFunc[0] ) ;
			LER_leInteiro(&opcao, 1, 1, LER_comparaLeSoNumero) ;
			
			switch( opcao )
			{
				case 1:
					GRC_mostraAtual() ;
					break ;
				case 2: 
					if ( GRC_buscaPorCodigo(codigo) != GRC_CondRetOk )
					{
						printf( "Nao existe disciplina cadastrada com este codigo %s.\n", codigo ) ;
					}
					else
					{
						GRC_mostraAtual() ;
					} /* if */
					break ;
				case 3:
					//inserir um Pre-Requisito
					system( "cls" ) ;
					printf( "Digite o código da disciplina que deseja configurar como pre-requisito:\n" ) ;
					LER_leStringConverte( codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					ret = GRC_inserePreRequisito( codigo ) ;
					if( ret != GRC_CondRetOk )
						printf( "Erro ao cadastrar\n" ) ;
					else
						printf( "Cadastro realizado com sucesso.\n" ) ;
					break ;
				case 4:
					//remover todos os Pre-Requisitos
					system( "cls" ) ;

					printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS PRE-REQUISITOS DESTA DISCIPLINA?\n\n") ;
					while ( 1 )
					{
						printf ("Digite 1: Para SIM.\n") ;
						printf ("Digite 0: Para NAO.\n\n") ;

						LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

						if( opcao == 1 )
						{
							ret = GRC_retira() ;
							ret = GRC_removePreRequisitos() ;
		
							if ( ret == GRC_CondRetOk )
							{
								printf ("\nPre-requisitos da disciplina removidos com sucessos!\n") ;
								MEN_menuAnterior() ;
								return ;
							} /* if */
						} 
						else
							if ( opcao == 0 )
							{
								break;
							} /* if */
						system( "cls" ) ;
						printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
					}
					break ;
				case 5:
					//inserir uma turma
					system( "cls" ) ;
					printf( "Digite o codigo da disciplina em que deseja inserir uma turma:\n" ) ;
					LER_leStringConverte( codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					printf( "Digite o codigo da turma:\n" ) ;				
					LER_leStringConverte( codTur, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					printf( "Digite o dia da semana da aula:\n" ) ;
					// Pode nao parecer coerente pelo nome da funcao usa-la aqui, mas na verdade os caracteres sao quase os mesmos
					// Talvez fosse bom renomear essas funções para que uso delas fosse mais intuitivo
					LER_leStringConverte( diaSem, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					do 
					{
						printf( "Digite a hora de inicio da aula(7 >= HorIni <= 21):\n" ) ;
						LER_leInteiro( &horIni, 1, 2, LER_comparaLeSoNumero ) ;
						//scanf("%d", &horIni);
					} while ( horIni > 21 || horIni < 7 ) ;
					do
					{
						printf( "Digite a hora do termino da aula (9 >= HorTer <= 23):\n" ) ;
						LER_leInteiro( &horTer, 1, 2, LER_comparaLeSoNumero ) ;
						//scanf("%d", &horTer);
					} while ( horTer > 23 || horTer < 9 ) ;
					printf( "Digite a quantidade de vagas:\n" ) ;
					LER_leInteiro( &qtdVag, 0, 2, LER_comparaLeSoNumero ) ;
					ret = GRC_insereTurma( codTur, horIni, horTer, diaSem, qtdVag, codigo ) ;
					break ;
				case 6:
					//exibir as turmas de uma disciplina
					system( "cls" ) ;
					printf( "Digite o codigo da disciplina que deseja checar as turmas:\n" ) ;
					 ret = GRC_exibeTurmas("INF1301");
					LER_leStringConverte( codigo, 1, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					ret = GRC_exibeTurmas( codigo ) ;
					break ;
				default:
					if ( opcao )
					{
						system( "cls" ) ;
						printf( "\n\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
					} /* if */
					break ;
			} /* switch */
					
			if ( ret == GRC_CondRetOk )
			{
				system( "cls" ) ;
				printf( "Alteracao realizada com sucesso!\n\n" ) ;
				MEN_menuAnterior();
			} else
				if ( ret == GRC_CondRetFormatoInvalido )
				{
					printf( "ERRO. Formato de dados invalido.\n" ) ;
				} else
					if( ret == GRC_CondRetIdJaCriado )
					{
						printf( "ERRO. Ja existe uma disciplina com este valor de identificacao.\n" ) ;
					} /* if */

		} while ( opcao ) ;

	} /* Fim função: MEN  &Modifica Disciplina */

/***************************************************************************
*
*  Função: MEN  &Remove Disciplina
*  ****/

	void MEN_removeDisciplina ( void )
	{

		int opcao ;
		char codigo[LER_TAM_STRING+1] ;
		GRC_tpCondRet ret ;

		printf( "\n*********** REMOVE DISCIPLINA ***********\n" ) ;
		
		printf( "\nDigite a codigo da disciplina que deseja remover permanentemente da relacao de disciplinas: \n" ) ;

		LER_leStringConverte(codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER);
	
		if ( GRC_buscaPorCodigo(codigo) != GRC_CondRetOk )
		{
			printf( "Nao existe disciplina cadastrada com este codigo %s.\n", codigo ) ;
			MEN_menuAnterior() ;
		} else
		{
			while ( 1 )
			{
				printf ("\nDISCIPLINA:\n") ;
				GRC_mostraAtual() ;
				printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DESTA DISCIPLINA?\n\n") ;
				printf( "\nDigite: \n" ) ;
				printf("1: Para SIM.\n") ;
				printf("0: Para NAO.\n\n") ;

				LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

				if ( opcao == 1 )
				{
					ret = GRC_retira() ;
		
					if ( ret == GRC_CondRetOk )
					{
						printf ( "\nDados da disciplina removidos com sucessos!\n" ) ;
						MEN_menuAnterior() ;
						return ;
					} /* if */
				} 
				else 
					if ( opcao == 0 )
					{
						break ;
					} /* if */

				system( "cls" ) ;
				printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
			} /* while */
		} /* if */

		MEN_menuAnterior() ;
		return ;

	} /* Fim função: MEN  &Remove Disciplina */

/***************************************************************************
*
*  Função: MEN  &Remove Todas Disciplina
*  ****/

	void MEN_removeTodasDisciplinas ( void )
	{

		int opcao ;
		while ( 1 )
		{
			printf ( "TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DE TODAS AS DISCIPLINAS CADASTRADAS?\n\n" ) ;
			printf( "\nDigite: \n" ) ;
			printf("1: Para SIM.\n") ;
			printf("0: Para NAO.\n\n") ;

			LER_leInteiro(&opcao, 1, 1, LER_comparaLeSoNumero) ;

			if( opcao == 1 )
			{
					GRC_limpa() ;
					printf ( "\nTodos os dados de todas as disciplinas foram removidas com sucesso!\n" ) ;
					MEN_menuAnterior() ;
					return ;
			} 
			else
				if ( opcao == 0 )
				{
					break ;
				} /* if */

			system( "cls" ) ;
			printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
		} /* while */

		printf ( "\nNenhum dado de nenhuma disciplina foi removido.\n" ) ; 
		MEN_menuAnterior() ;

	} /* Fim função: MEN  &Remove Todas Disciplina */

/***************************************************************************
*
*  Função: MEN  &Menu Grade Curricular
*  ****/

/*
		TODO
		Essa função esta redundante com as funções acima.
		As funções de grade acima, são uma forma separada desta função abaixo.
		As opções são
			-deletar as funções acima
			-deletar essa de baixo
			-fazer essa de baixo chamar as de cima
		
		Acho que a melhor é a terceira, mas acreditor que esta função ira se tornar desnecessaria.
*/

	void MEN_menuGradeCurricular ( void )
	{

		char nomeFunc[][40] = { 
				"Sair", 
				"Adicionar disciplina" , 
				"Mostrar a disciplina atual", 
				"Buscar outra disciplina",
				"Mostrar todas as disciplinas", 
				"Inserir um Pre-Requisito", 
				"Remover todos os Pre-Requisitos",
				"Limpar a grade Curricular", 
				"Inserir uma turma", 
				"Exibe as turmas de uma disciplina" } ;
		int nItens = 9, i ;
		char  codigo[MEN_MAX_CODIGO], codTur[MEN_COD_TUR], diaSem[MEN_DIA_SEMANA] ;

		int horIni, horTer, qtdVag ;
		GRC_tpCondRet ret ;
		int opcao ;

		do 
		{
			printf( "\n*********** MENU GRADE CURRICULAR ***********\n" ) ;
			for ( i = 0; i <= nItens; i++ )
			{
				printf("%d: %s.\n", i, nomeFunc[i]) ;
			} /* for */

			LER_leInteiro( &opcao, 1, 2, LER_comparaLeSoNumero ) ;

			switch ( opcao )
			{
				case 1:
					system( "cls" ) ;
					ret = GRC_cadastraCMD() ;
					break ;
				case 2:
					system( "cls" ) ;
					GRC_mostraAtual() ;
					break ;
				case 3:
					system( "cls" ) ;
					printf( "Digite o código da disciplina que deseja buscar:\n" ) ;
					LER_leString( codigo, 0, LER_TAM_STRING, LER_comparaLeSoLetra) ;				
					ret = GRC_buscaPorCodigo( codigo ) ;
					GRC_mostraAtual() ;
					break ;
				case 4:
					system( "cls" ) ;
					GRC_mostraTodas() ;
					printf( "\n\n" ) ;
					break ;
				case 5:
					system( "cls" ) ;
					printf( "Digite o código da disciplina que deseja configurar como pre-requisito:\n" ) ;
					LER_leStringConverte( codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					ret = GRC_inserePreRequisito( codigo ) ;
					break ; 
				case 6:
					system( "cls" ) ;
					GRC_removePreRequisitos() ;
					break ;
				case 7:
					system( "cls" ) ;
					printf( "\nDeseja mesmo apagar toda a grade curricular?\n1:Sim\n2-Nao\n" ) ;				
					LER_leInteiro( &opcao, 0, 1, LER_comparaLeSoNumero ) ;
					if ( opcao == 1 ) 
					{
						system( "cls" ) ;
						CDI_limpa() ;
						printf( "A grade curricular foi completamente apagada.\n" ) ;
					} /* if */
					ret = GRC_limpa() ;//TODO verificar retorno
					MEN_menuAnterior() ;
					break ;
				case 8: 
					system( "cls" ) ;
					printf( "Digite o codigo da disciplina em que deseja inserir uma turma:\n" ) ;
					LER_leStringConverte( codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					printf( "Digite o codigo da turma:\n" ) ;				
					LER_leStringConverte( codTur, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ;
					printf( "Digite o dia da semana da aula:\n" ) ;
					// Pode nao parecer coerente pelo nome da funcao usa-la aqui, mas na verdade os caracteres sao quase os mesmos
					// Talvez fosse bom renomear essas funções para que uso delas fosse mais intuitivo
					LER_leStringConverte( diaSem, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER ) ; 
					do
					{
						printf( "Digite a hora de inicio da aula(7 >= HorIni <= 21):\n" ) ;
						LER_leInteiro( &horIni, 1, 2, LER_comparaLeSoNumero ) ;
						//scanf("%d", &horIni);
					} while ( horIni > 21 || horIni < 7 ) ;
					do {
						printf( "Digite a hora do termino da aula (9 >= HorTer <= 23):\n" ) ;
						LER_leInteiro( &horTer, 1, 2, LER_comparaLeSoNumero ) ;
						//scanf("%d", &horTer);
					} while ( horTer >23 || horTer < 9 ) ; 
					printf( "Digite a quantidade de vagas:\n" ) ;
					LER_leInteiro( &qtdVag, 0, 2, LER_comparaLeSoNumero ) ;
					ret = GRC_insereTurma( codTur, horIni, horTer, diaSem, qtdVag, codigo ) ;
					break ;
				case 9:
					system( "cls" ) ;
					printf( "Digite o codigo da disciplina que deseja checar as turmas:\n" ) ;
					scanf( " %s", codigo ) ;
					ret = GRC_exibeTurmas( codigo ) ;
					break ;
				default:
					if ( opcao )
						printf( "Opcao inválida!\n" ) ;
					break ; 
			} /* switch */ 

			if ( ret == GRC_CondRetOk )
			{
				printf( "Operacao realizada com sucesso!\n" ) ;
			}
			else 
				if ( ret == GRC_CondRetNaoHaMemoria )
				{
					printf( "ERRO. Nao ha memoria suficiente.\n" ) ;
				} else 
					if ( ret == GRC_CondRetGradeCurricularVazia )
					{
						printf( "Ainda nao existe nenhuma disciplina cadastrada.\n" ) ;
					} else
						if ( ret == GRC_CondRetDisciplinaNaoEncontrada )
						{
							printf( "A disciplina solicitada nao foi encontrada.\n" ) ;
						} else
							if ( ret == GRC_CondRetIdJaCriado )
							{
								printf( "ERRO.Ja existe uma Disciplina com este codigo.\n" ) ;
							} else
								if ( ret == GRC_CondRetFormatoInvalido )
								{
									printf( "ERRO. Formato de dados invalido.\n" ) ;
								} /* if */
			MEN_menuAnterior() ;
		} while ( opcao ) ;
	
	} /* Fim função: MEN  &Menu Grade Curricular */


/***************************************************************************
*
*  Função: MEN  &Adiciona Sala
*  ****/

	void MEN_adicionaSala ( void )
	{
		char predio[2];
		char numero[ MEN_TAM_COD_SAL];
		char codigo[ MEN_TAM_COD_SAL] ;
		int maxAlunos;
		int eLaboratorio ;

		CDS_tpCondRet ret ;

		system( "cls" ) ;
		printf( "\n*********** CADASTRO DE SALA ***********\n" ) ;
				
		//adiciona sala
		printf( "\nInicial do predio: \n" ) ;
		printf( "K. Kennedy\n" ) ;
		printf( "L. Leme\n" ) ;
		printf( "I. IAG\n" ) ;
		printf( "R. RDC\n" ) ;
		printf( "F. Frings\n" ) ;
		LER_leStringConverte( predio, 1, 1, MEN_comparaLePredioSAL, LER_TOUPPER) ;

		printf( "\nCodigo da sala: \n" ) ;
		LER_leString( numero, MEN_MIN_COD_SAL ,  MEN_MAX_COD_SAL, LER_comparaLeSoNumero ) ;

		printf( "\nCapacidade de Alunos: \n" ) ;
		LER_leInteiro( &maxAlunos, 1, 2, LER_comparaLeSoNumero ) ;

		do{
			printf( "\nA sala e laboratorio?: \n" ) ;
			printf("1: Sim\n");
			printf("0: Nao\n");
			LER_leInteiro(&eLaboratorio, 1, 1, LER_comparaLeSoNumero) ;
		}while(eLaboratorio != 0 && eLaboratorio != 1);
		
		

		//compoe codigo
		strcpy(codigo, predio);
		strcat(codigo, numero);
		printf("codigo composto %s\n", codigo);

		ret = CDS_insere( codigo, maxAlunos, eLaboratorio ) ;

		if ( ret == CDS_CondRetSalaJaCadastrada )
		{
			printf( "Sala ja cadastrada.\n" ) ;
		}
		else if ( ret == CDS_CondRetFaltouMemoria )
		{
			printf( "Erro de memoria ao cadastrar sala." ) ;
		}
		else 
		{
			system( "cls" ) ;
			printf( "\nSala cadastrada com sucesso!\n\n" ) ;
			CDS_exibeDisponibilidade (codigo) ;
		} /* if */

		MEN_menuAnterior() ;

	} /* Fim função: MEN  &Adiciona Sala */


/***************************************************************************
*
*  Função: MEN  &Remove Sala
*  ****/

	void MEN_removeSala ( void )
	{

		int opcao ;
		char codigo[MEN_TAM_COD_SAL] ;

		printf( "\n*********** REMOVE SALA ***********\n" ) ;
		
		printf( "\nDigite a codigo da sala que deseja remover permanentemente da relacao de salas: \n" ) ;

		LER_leStringConverte(codigo, 1, LER_TAM_STRING, MEN_comparaLeCodigoGRC, LER_TOUPPER);
	
		
		while ( 1 )
		{
			printf ("\nSALA:\n") ;
			CDS_exibeDisponibilidade ( codigo ) ;
			printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DESTA SALA?\n\n") ;
			printf( "\nDigite: \n" ) ;
			printf("1: Para SIM.\n") ;
			printf("0: Para NAO.\n\n") ;

			LER_leInteiro( &opcao, 1, 1, LER_comparaLeSoNumero ) ;

			if ( opcao == 1 )
			{
				if ( CDS_retira(codigo) != CDS_CondRetOK )
				{
					printf( "Nao existe sala cadastrada com este codigo %s.\n", codigo ) ;
				}/* if */
				else
				{
					printf ( "\nDados da sala removidos com sucesso!\n" ) ;
				} /* if */
				MEN_menuAnterior() ;
				return ;
			} 
			else 
				if ( opcao == 0 )
				{
					break ;
				} /* if */

			system( "cls" ) ;
			printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
		} /* while */

		MEN_menuAnterior() ;
		return ;

	} /* Fim função: MEN  &Remove Sala */

/***************************************************************************
*
*  Função: MEN  &Remove Todas Sala
*  ****/

	void MEN_removeTodasSalas ( void )
	{

		int opcao ;
		while ( 1 )
		{
			printf ( "TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DE TODAS AS SALAS CADASTRADAS?\n\n" ) ;
			printf( "\nDigite: \n" ) ;
			printf("1: Para SIM.\n") ;
			printf("0: Para NAO.\n\n") ;

			LER_leInteiro(&opcao, 1, 1, LER_comparaLeSoNumero) ;

			if( opcao == 1 )
			{
					CDS_limpa() ;
					printf ( "\nTodos os dados de todas as salas foram removidas com sucesso!\n" ) ;
					MEN_menuAnterior() ;
					return ;
			} 
			else
				if ( opcao == 0 )
				{
					break ;
				} /* if */

			system( "cls" ) ;
			printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
		} /* while */

		printf ( "\nNenhum dado de nenhuma sala foi removido.\n" ) ; 
		MEN_menuAnterior() ;

	} /* Fim função: MEN  &Remove Todas Salas */


/***************************************************************************
*
*  Função: MEN  &Menu Anterior
*  ****/

	void MEN_menuAnterior (void) 
	{
		
		printf("\nPressione qualquer tecla para voltar para o menu anterior.\n") ;
		getch() ;
		system("cls") ;
		
	} /* Fim função: MEN  -Menu Anterior */


/*****  Código das funções encapsuladas no módulo  *****/
	
/***********************************************************************
*
*  $FC Função: MEN  -Compara Le Codigo GRC
*
*  $ED Descrição da função
*	  		
*
***********************************************************************/
/*Assertivas: 
/			 
***********************************************************************/

	int MEN_comparaLeCodigoGRC ( unsigned char c )
	{

		return isalpha(c) || isdigit(c) || c==' ' || c== '-' ;

	} /* Fim função: MEN  -Compara Le Codigo GRC */

/***********************************************************************
*
*  $FC Função: MEN  -Compara Le Predio SAL
*
*  $ED Descrição da função
*	  		
*
***********************************************************************/
/*Assertivas: 
/			 
***********************************************************************/

	int MEN_comparaLePredioSAL ( unsigned char c )
	{

		return c=='I' || c=='K' || c=='L' || c=='R' || c=='F' ;

	} /* Fim função: MEN  -Compara Le Predio SAL */

/********** Fim do módulo de implementação: MEN Menu **********/
