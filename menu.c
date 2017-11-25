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
*			  Bruno Miranda Marinho (Grupo 2)
*             Cristiane Ramalho Guimarães (Grupo 5)
*             Flávio Thiago Franco Vaz (Grupo 2)
*             João Victor Cerqueira (Grupo 2)
*             Matheus Henrique Branco Zeitune (Grupo 2)
*             Vinícius Cortat (Grupo 2)
*
*  $HA Histórico de evolução:
*     Versão  Autor         Data		Observações
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

#include "leitura.h"

/*****  Protótipos das funções encapsuladas no módulo  *****/

	/*void MEN_leSoLetra ( char * cad_carac ) ;
	void MEN_leCPF ( char * cpf ) ;
	void MEN_leData ( int * dia, int * mes, int * ano ) ;
	void MEN_leUF ( char * UF ) ;
	void MEN_leLogradouro ( char * logr ) ;
	void MEN_leComplemento ( char * comp ) ;
	void MEN_leEmail ( char * email ) ;
	int MEN_leTelefone ( void ) ;
	int MEN_leRG ( void ) ;
	*/
	void MEN_menuAnterior (void) ;

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

		printf("\nDigite a matricula (8 digitos): ");
//		mat = MEN_leMatricula();
		printf("\n");
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

	int MEN_loginAluno(unsigned int *matricula)
	{
		int mat;
		Aluno* Al;

		printf("\nLogin Aluno\n");

		printf("\nDigite a matricula (8 digitos): ");
		//mat = MEN_leMatricula();
		printf("\n");

		if(CDI_busca(mat,&Al) == CDI_CondRetAlunoNaoCadastrado)
		{
			printf("Matricula invalida\n");
			printf("Pressione ENTER para voltar ao menu principal...\n");
			getch();
			system("cls");
			return 0;
		}

		*matricula = mat;
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
		printf( "\nDigite o nome do aluno: \n" ) ;
		//MEN_leSoLetra( nome ) ;

		printf( "\nDigite o numero da matricula (8 digitos): \n" ) ;
		//mat = MEN_leMatricula() ;

		printf( "\nDigite o numero do CPF (11 digitos): \n" ) ;
		//MEN_leCPF( cpf_completo ) ;
		cpf.cod = atoi( cpf_completo+9 ) ;
		cpf_completo[9] = '\0' ;
		cpf.dig3 = atoi( cpf_completo+6 ) ;
		cpf_completo[6] = '\0' ;
		cpf.dig2 = atoi( cpf_completo+3 ) ;
		cpf_completo[3] = '\0' ; 
		cpf.dig1 = atoi( cpf_completo ) ;

		printf( "\nDigite a data de nascimento:\n" ) ;
		//MEN_leData( &nasc.dia, &nasc.mes, &nasc.ano ) ;

		printf( "\nDigite o numero do telefone (8 ou 9 digitos):\n" ) ;
		telefone = //MEN_leTelefone() ;

		printf( "\nInforme o endereco:" );
		printf( "\nDigite o logradouro:\n" ) ;
		//MEN_leLogradouro( end.rua ) ;

		printf("\nDigite o numero:\n") ;
		//MEN_leend.numero = MEN_leNumero() ;
		
		printf( "\nDigite o complemento:\n" ) ;
		//MEN_leComplemento( end.comp ) ;

		printf( "\nDigite o bairro:\n" ) ;
		//MEN_leSoLetra( end.bairro ) ;

		printf( "\nDigite a cidade:\n" ) ;
		//MEN_leSoLetra( end.cidade ) ;		

		printf( "\nDigite a sigla estado:\n") ;
		//MEN_leUF( end.estado ) ;

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
		char nome[MEN_TAM_STRING], cpf_completo[MEN_TAM_CPF] ;
		int mat, telefone, matAnt ;
		Data nasc ; 
		Endereco end ;
		CPF cpf ;
		Aluno * Alu ;
		int opcao ;
		CDI_tpCondRet ret ;

		printf( "\n*********** EDITAR DADOS DE ALUNO ***********\n\n" ) ;

		printf( "Digite a matricula do aluno para alterar seus dados: " ) ;
		//matAnt = //MEN_leNumero() ;

		if ( CDI_busca( (unsigned int)matAnt, &Alu ) != CDI_CondRetOK ) 
		{
			printf( "Nao existe aluno cadastrado com este numero de matricula %d.\n", matAnt ) ;
			MEN_menuAnterior() ;
		}

		do
		{
			printf( "Dados do aluno que deseja modificar os dados:\n" ) ;
			CDI_imprimeInfo( (unsigned int)matAnt ) ;
			printf( "\n\nEscolha o dado a ser alterado: \n\n" ) ;
			printf( "Digite 1: Nome\n" ) ;
			printf( "Digite 2: Matricula\n" ) ;
			printf( "Digite 3: Telefone\n" ) ;
			printf( "Digite 4: Data de nascimento\n" ) ;
			printf( "Digite 5: CPF\n" ) ;
			printf( "Digite 6: Endereco\n" ) ;
			printf( "\nDigite 0: Para voltar ao menu anterior\n" ) ;
			
			//MEN_leopcao = MEN_leNumero() ;

			system("cls") ;

			switch( opcao )
			{
				case 1: 
					printf( "\nDigite o novo nome do aluno: \n" ) ;
					//MEN_leSoLetra( nome ) ;
					ret = CDI_altera( matAnt, nome, 0, NULL, 0, NULL, NULL ) ;
					break ;
				case 2:
					printf( "\nDigite a nova matricula do aluno (8 digitos): \n" ) ;
					//MEN_lemat = //MEN_leMatricula() ;
					ret = CDI_altera( matAnt, NULL, (unsigned int)mat, NULL, 0, NULL, NULL ) ;
					break ;
				case 3:
					printf( "\nDigite o novo telefone do aluno: \n" ) ;
					//MEN_letelefone = MEN_leTelefone() ;
					ret = CDI_altera( matAnt, NULL, 0, NULL, (unsigned int)telefone, NULL, NULL ) ;
					break ;
				case 4:
					printf( "\nDigite a nova data de nascimento do aluno: \n" ) ;
					//MEN_leData ( &nasc.dia, &nasc.mes, &nasc.ano ) ;
					ret = CDI_altera( matAnt, NULL, 0, NULL, 0, &nasc, NULL ) ;
					break ;
				case 5:
					printf( "\nDigite o novo CPF do aluno (11 digitos): \n" ) ;
					//MEN_leCPF( cpf_completo ) ;
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
					printf( "\nDigite o logradouro:\n" ) ;
					//MEN_leLogradouro( end.rua ) ;
					printf( "\nDigite o numero:\n" ) ;
					//MEN_leend.numero = MEN_leNumero() ;
					printf( "\nDigite o complemento:\n" ) ;
					//MEN_leComplemento( end.comp ) ;
					printf( "\nDigite o bairro: \n" ) ;
					//MEN_leSoLetra( end.bairro ) ;
					printf( "\nDigite a cidade: \n" ) ;
					//MEN_leSoLetra( end.cidade ) ;
					printf( "\nDigite a sigla do estado: \n" ) ;
					//MEN_leUF( end.estado ) ;
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
		printf( "Digite o nome: \n" ) ;
		//MEN_leSoLetra( nome ) ;

		printf( "\nDigite o numero do RG (9 digitos): \n") ;
		//MEN_lerg = MEN_leRG() ;

		printf( "\nDigite o numero do CPF (11 digitos): \n" ) ;
		//MEN_leCPF( cpf ) ;

		printf( "\nDigite o numero da matricula (8 digitos): \n" ) ;
		//matricula = MEN_leMatricula() ;

		printf( "\nDigite a data de nascimento: \n" ) ;
		//MEN_leData( &dia, &mes, &ano ) ;

		printf("\nDigite o numero do telefone (8 ou 9 digitos): \n") ;
		//MEN_letelefone = MEN_leTelefone() ;

		printf( "\nDigite o email: \n" ) ;
		//MEN_leEmail( email ) ;

		printf( "\nInforme o endereco:" ) ;
		printf( "\nDigite o logradouro:\n" ) ;
		//MEN_leLogradouro( rua ) ;

		printf( "\nDigite o numero:\n" ) ;
		//MEN_lenumero = MEN_leNumero() ;

		printf( "\nDigite o complemento:\n" ) ;
		//MEN_leComplemento( complemento ) ;

		printf( "\nDigite o bairro:\n" ) ;
		//MEN_leSoLetra( bairro ) ;

		printf( "\nDigite a cidade:\n" ) ;
		//MEN_leSoLetra( cidade ) ;

		printf( "\nDigite a sigla do estado:\n" ) ;
		//MEN_leUF( uf ) ;

		printf( "\nDigite o pais: \n" ) ;
		//MEN_leSoLetra( pais ) ;

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
		char nomeFunc[][30] = { "Para voltar ao menu anterior.", "Nome", "RG", "CPF", "Matricula", "Email", "Telefone", "Data", "Endereco" } ;
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
		printf( "\nDigite a matricula do professor que deseja modificar (8 digitos):\n" ) ;
		//MEN_leparamInt = MEN_leMatricula() ;
		
		if ( CDO_buscaPorMatricula(paramInt) != CDO_CondRetOk )
		{
			printf( "Nao existe professor cadastrado com este numero de matricula %d, por favor tente novamente\n", paramInt ) ;
			MEN_menuAnterior() ;
			return ;
		} /* if */
		
		do
		{
			printf( "Dados do professor que deseja modificar os dados:\n" ) ;
			CDO_mostraAtual() ;
			printf( "\n\nEscolha o dado a ser alterado: \n\n" ) ;

			for ( i = 1; i < nAlteras; i++ )
			{
				printf( "Digite %d: %s.\n", i, nomeFunc[i] ) ;
			} /* for */

			printf( "\nDigite 0: %s.\n", nomeFunc[0] ) ;
			//MEN_leopcao = MEN_leNumero() ;
			
			switch( opcao )
			{
				case 1:
					//Nome
					printf( "\nDigite o novo valor para %s.\n", nomeFunc[opcao] ) ;
					//MEN_leMEN_leSoLetra( paramString ) ;
					ret = funcString[opcao](paramString) ;
					break ;
				case 2: 
					//RG
					printf( "\nDigite o novo valor para %s.\n", nomeFunc[opcao] ) ;
					//MEN_leparamInt = MEN_leRG() ;
					ret = funcInt[opcao](paramInt) ;
					break ;
				case 3:
					//CPF
					printf( "\nDigite o novo valor para %s.\n", nomeFunc[opcao] ) ;
					//MEN_leMEN_leCPF( paramString ) ;
					ret = funcString[opcao](paramString) ;
					break ;
				case 4: 
					//Matricula
					printf( "\nDigite o novo valor para %s.\n", nomeFunc[opcao] ) ;
					//MEN_leparamInt = MEN_leMatricula() ;
					ret = funcInt[opcao](paramInt) ;
					break ;
				case 5: 
					//Email
					printf( "\nDigite o novo valor para %s.\n", nomeFunc[opcao] ) ;
					//MEN_leMEN_leEmail ( paramString ) ;
					ret = funcString[opcao](paramString) ;
					break ;
				case 6: 
					//Telefone
					printf( "\nDigite o novo valor para %s.\n", nomeFunc[opcao] ) ;
					//MEN_leparamInt = MEN_leTelefone() ;
					ret = funcInt[opcao](paramInt) ;
					break ;
				case 7:
					//Data
					printf( "\nDigite a nova data de nascimento: \n" ) ;
					//MEN_leMEN_leData (&dia, &mes, &ano) ;
					ret = CDO_alteraDataNascimento( dia, mes, ano ) ;
					break ;
				case 8:
					//Nascimento
					printf( "\nInforme o novo endereco:" ) ;
					printf("\nDigite o logradouro:\n") ;
					//MEN_leMEN_leLogradouro( rua ) ;
					printf( "\nDigite o novo numero:\n" ) ;
					//MEN_lenumero = //MEN_leNumero() ;
					printf( "\nDigite o novo complemento:\n" ) ;
					scanf( " %s", complemento ) ;
					printf( "\nDigite o novo bairro:\n" ) ;
					//MEN_leSoLetra( bairro ) ;
					printf( "\nDigite a nova cidade:\n" ) ;
					//MEN_leSoLetra( cidade ) ;
					printf( "\nDigite o novo estado:\n" ) ;
					//MEN_leUF( uf ) ;
					printf( "\nDigite o novo pais:\n" ) ;
					//MEN_leSoLetra( pais ) ;
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
					if( ret == CDO_CondRetIdJaCriado )
					{
						printf( "ERRO. Ja existe um professor com este valor de identificacao.\n" ) ;
					} /* if */

		} while ( opcao ) ;
	}

/***********************************************************************
*
*  $FC Função: MEN_removeProfessor
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeProfessor ( void )
	{
		int mat, opcao ;
		CDO_tpCondRet ret ;

		printf( "\n*********** REMOVE PROFESSOR(A) ***********\n" ) ;
		
		printf( "\nDigite a matricula do professor que deseja remover permanentemente da relacao de professores: \n" ) ;
		//MEN_lemat = MEN_leMatricula() ;
	
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
				printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DESTE PROFESSOR?\n\n") ;
				printf ("Digite 1: Para SIM.\n") ;
				printf ("Digite 0: Para NAO.\n\n") ;

				//MEN_leopcao = //MEN_leNumero() ;

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
	
	} 

/***********************************************************************
*
*  $FC Função: MEN_removeProfessor
*
*  $ED Descrição da função
*		Mostra o menu inicial.
*
***********************************************************************/
/*Assertivas: Retorno da função: Retona 1, se os dados são validos.
/			 Parâmentros: Estruturas de ponteiros.
***********************************************************************/

	void MEN_removeTodosProfessores ( void )
	{
		int opcao ;

		do
			{
				printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DE TODOS OS PROFESSORES CADASTRADOS?\n\n") ;
				printf ("Digite 1: Para SIM.\n") ;
				printf ("Digite 0: Para NAO.\n\n") ;

				//MEN_leopcao = MEN_leNumero() ;

				switch( opcao )
				{
					case 1:
						CDO_limpa() ;
						printf ("\nTodos os dados de todos os professores foram remivos com sucesso!\n");
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

		printf ("\nNenhum o dado de nenhmu professor foi remivo.\n");
		MEN_menuAnterior() ;
		return ;
	}
//TODO comentar, essta é uma função auxiliar usada na proxima função. Olhe o modulo leitura.c essa é uma função de comparação
int MEN_comparaLeCodigoGRC(unsigned char c){
	return isalpha(c) || isdigit(c) || c==' ' || c== '-';
}

/***********************************************************************
*
*  $FC Função: MEN_menuGradeCurricular
*
*  $ED Descrição da função
*		Mostra o menu Grade Curricular.
*
***********************************************************************/
/*Assertivas: 
***********************************************************************/
			
	void MEN_adicionaDisciplina(){
		//TODO trocar isso por define
		char nome[25] ;
		char codigo[8];
		char bibliografia[300];
		char ementa[300];
		int creditos;
		int criterio;
		GRC_tpCondRet ret ;

		system( "cls" ) ;
		printf( "\n*********** CADASTRO DE DISCIPLINA ***********\n" ) ;
				
		//adiciona aluno
		printf( "\nDigite o nome da disciplina: \n" ) ;
		LER_leString(nome, 0, 25, LER_comparaLeSoLetra, 0);


		printf( "\nDigite o codigo da disciplina: \n" ) ;
		LER_leString(codigo, 4, 8, MEN_comparaLeCodigoGRC, 1);

		printf( "\nDigite a bibliografia da disciplina: \n" ) ;
		LER_leString(bibliografia, 1, 300, LER_comparaLeSoLetra, 0);

		printf( "\nDigite a ementa da disciplina: \n" ) ;
		LER_leString(ementa, 1, 300, LER_comparaLeSoLetra, 0);
	
		printf( "\nDigite a quantidade de creditos da disciplina: \n" ) ;
		LER_leInteiro(&creditos, 1, 2, LER_comparaLeSoNumero);

		do{
			printf( "\nDigite o criterio da disciplina: \n" ) ;
			LER_leInteiro(&criterio, 1, 1, LER_comparaLeSoNumero);
			if(criterio < 1 || 5 < criterio)
				printf("Criterio deve ser um numero de 1 ate 5.\n");
		}while( criterio < 1 || 5 < criterio);
		
		ret = GRC_cadastra(nome, codigo, creditos, bibliografia, ementa, criterio);

		if ( ret == GRC_CondRetIdJaCriado)
		{
			printf( "Disciplina ja cadastrada.\n" ) ;
		} else {
			if ( ret == GRC_CondRetNaoHaMemoria )
			{
				printf( "Erro de memoria ao cadastrar." ) ;
			} else
			{
				system( "cls" ) ;
				printf( "\nDisciplina cadastrado com sucesso!\n\n" ) ;
				GRC_mostraAtual () ;
			} /* if */
		} /* if */
		MEN_menuAnterior() ;
	}

	void MEN_modificaDisciplina(){
		char nomeFunc[][40] = {
				"voltar ao menu anterior.",
				"mostrar a disciplina atual",
				"buscar outra disciplina",
				"inserir um Pre-Requisito",
				"remover todos os Pre-Requisitos",
				"inserir uma turma",
				"exibir as turmas de uma disciplina"
		};
		//TODO trocar por define
		char nome[MEN_MAX_NOME], codigo[MEN_MAX_CODIGO], codTur[MEN_COD_TUR], diaSem[MEN_DIA_SEMANA];

		int horIni, horTer, qtdVag;
		int nOpcoes = 7, i ;
		GRC_tpCondRet ret;
		int opcao ;

		system( "cls" ) ;
		printf( "\n*********** EDITAR DADOS DE DISCIPLINA ***********\n" ) ;
		
		do
		{
			printf( "Dados da disciplina que deseja modificar os dados:\n" ) ;
			GRC_mostraAtual();
			printf( "\n\nEscolha o dado a ser alterado: \n\n" ) ;

			for ( i = 1; i < nOpcoes; i++ )
			{
				printf( "Digite %d: %s.\n", i, nomeFunc[i] ) ;
			} /* for */

			printf( "\nDigite 0: %s.\n", nomeFunc[0] ) ;
			LER_leInteiro(&opcao, 1, 1, LER_comparaLeSoNumero) ;
			
			switch( opcao )
			{
				case 1:
					GRC_mostraAtual();
					break ;
				case 2: 
					if ( GRC_buscaPorCodigo(codigo) != GRC_CondRetOk )
						printf( "Nao existe disciplina cadastrada com este codigo %s.\n", codigo ) ;
					else
						GRC_mostraAtual();
					break ;
				
				case 3:
					//inserir um Pre-Requisito
					system("cls");
					printf("Digite o código da disciplina que deseja configurar como pre-requisito:\n");
					LER_leString(codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
					ret = GRC_inserePreRequisito(codigo);
					if(ret!=GRC_CondRetOk)
						printf("Erro ao cadastrar\n");
					else
						printf("Cadastro realizado com sucesso.\n");
					break;
				case 4:
					//remover todos os Pre-Requisitos
					system("cls");
					
					
					printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS PRE-REQUISITOS DESTA DISCIPLINA?\n\n") ;
					while(1){
						printf ("Digite 1: Para SIM.\n") ;
						printf ("Digite 0: Para NAO.\n\n") ;

						LER_leInteiro(&opcao, 1, 2, LER_comparaLeSoNumero);

						if(opcao==1){
							ret = GRC_retira() ;
							ret = GRC_removePreRequisitos();
		
							if ( ret == GRC_CondRetOk )
							{
								printf ("\nPre-requisitos da disciplina removidos com sucessos!\n");
								MEN_menuAnterior() ;
								return ;
							}
						} /* if */
						else if(opcao==0) break;
						system( "cls" ) ;
						printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
					}
					break;
				case 5:
					//inserir uma turma
					system("cls");
					printf("Digite o codigo da disciplina em que deseja inserir uma turma:\n");
					LER_leString(codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
					printf("Digite o codigo da turma:\n");				
					LER_leString(codTur, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
					printf("Digite o dia da semana da aula:\n");
					// Pode nao parecer coerente pelo nome da funcao usa-la aqui, mas na verdade os caracteres sao quase os mesmos
					// Talvez fosse bom renomear essas funções para que uso delas fosse mais intuitivo
					LER_leString(diaSem, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);

					do {
						printf("Digite a hora de inicio da aula(7 >= HorIni <= 21):\n");
						LER_leInteiro(&horIni, 1, 2, LER_comparaLeSoNumero);
						//scanf("%d", &horIni);
					} while (horIni > 21 || horIni <7);
					do {
						printf("Digite a hora do termino da aula (9 >= HorTer <= 23):\n");
						LER_leInteiro(&horTer, 1, 2, LER_comparaLeSoNumero);
						//scanf("%d", &horTer);
					} while (horTer >23 || horTer < 9);
					printf("Digite a quantidade de vagas:\n");
					LER_leInteiro(&qtdVag, 0, 2, LER_comparaLeSoNumero);
					ret = GRC_insereTurma(codTur, horIni, horTer, diaSem, qtdVag, codigo);
					break;
				case 6:
					//exibir as turmas de uma disciplina
					system("cls");
					printf("Digite o codigo da disciplina que deseja checar as turmas:\n");
					scanf(" %s", codigo);
					ret = GRC_exibeTurmas(codigo);
					break;
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
					if( ret == CDO_CondRetIdJaCriado )
					{
						printf( "ERRO. Ja existe um professor com este valor de identificacao.\n" ) ;
					} /* if */

		} while ( opcao ) ;
	}
	void MEN_removeDisciplina(){
		int opcao ;
		char codigo[LER_TAM_STRING+1];
		GRC_tpCondRet ret ;

		printf( "\n*********** REMOVE DISCIPLINA ***********\n" ) ;
		
		printf( "\nDigite a codigo da disciplina que deseja remover permanentemente da relacao de disciplinas: \n" ) ;

		LER_leString(codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
	
		if ( GRC_buscaPorCodigo(codigo) != GRC_CondRetOk )
		{
			printf( "Nao existe disciplina cadastrada com este codigo %s.\n", codigo ) ;
			MEN_menuAnterior() ;
		} else
		{
			while(1)
			{
				printf ("\nDISCIPLINA:\n") ;
				GRC_mostraAtual() ;
				printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DESTE PROFESSOR?\n\n") ;
				printf ("Digite 1: Para SIM.\n") ;
				printf ("Digite 0: Para NAO.\n\n") ;

				LER_leInteiro(&opcao, 1, 2, LER_comparaLeSoNumero);

				if(opcao==1){
					ret = GRC_retira() ;
		
					if ( ret == GRC_CondRetOk )
					{
						printf ("\nDados da disciplina removidos com sucessos!\n");
						MEN_menuAnterior() ;
						return ;
					}
				} /* if */
				else if(opcao==0) break;
				system( "cls" ) ;
				printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
			}

		}

		MEN_menuAnterior() ;
		return ;

	}
	void MEN_removeTodasDisciplinas(){
		int opcao ;
		while(1){
			printf ("TEM CERTEZA QUE DESEJA REMOVER PERMANENTEMENTE TODOS OS DADOS DE TODAS AS DISCIPLINAS CADASTRADAS?\n\n") ;
			printf ("Digite 1: Para SIM.\n") ;
			printf ("Digite 0: Para NAO.\n\n") ;
			
			LER_leInteiro(&opcao, 1, 2, LER_comparaLeSoNumero);

			if(opcao==1){
					GRC_limpa() ;
					printf ("\nTodos os dados de todas as disciplinas foram removidas com sucesso!\n");
					MEN_menuAnterior() ;
					return ;
			} /* if */
			else if(opcao==0) break;
			system( "cls" ) ;
			printf( "\nOPCAO INVALIDA! Digite o numero de algumas das opcoes abaixo. \n\n" ) ;
		}

		printf ("\nNenhum dado de nenhuma disciplina foi removido.\n");
		MEN_menuAnterior() ;
	}

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

	void MEN_menuGradeCurricular()
	{
		char nomeFunc[][40] = { "Sair", "Adicionar disciplina" , "Mostrar a disciplina atual", "Buscar outra disciplina",
			"Mostrar todas as disciplinas", "Inserir um Pre-Requisito", "Remover todos os Pre-Requisitos",
			"Limpar a grade Curricular", "Inserir uma turma", "Exibe as turmas de uma disciplina" };
		int nItens = 9, i;
		int creditos;
		char nome[MEN_MAX_NOME], codigo[MEN_MAX_CODIGO], bibliografia[MEN_MAX_BIBLIOGRAFIA], ementa[MEN_MAX_EMENTA],
			codTur[MEN_COD_TUR], diaSem[MEN_DIA_SEMANA];

		int horIni, horTer, qtdVag;
		int criterio;
		GRC_tpCondRet ret;
		int opcao;

		do {
			printf("\nMenu Grade Curricular\n");
			for (i = 0;i <= nItens;i++)
				printf("Digite %d: %s.\n", i, nomeFunc[i]);				
			LER_leInteiro(&opcao, 1, 2, LER_comparaLeSoNumero);

			switch (opcao) {
			case 1:
				system("cls");
				ret = GRC_cadastraCMD();
				break;
			case 2:
				system("cls");
				GRC_mostraAtual();
				break;
			case 3:
				system("cls");
				printf("Digite o código da disciplina que deseja buscar:\n");
				LER_leString(codigo, 0, LER_TAM_STRING, LER_comparaLeSoLetra, 0);				
				ret = GRC_buscaPorCodigo(codigo);
				GRC_mostraAtual();
				break;
			case 4:
				system("cls");
				GRC_mostraTodas();
				printf("\n\n");
				break;
			case 5:
				system("cls");
				printf("Digite o código da disciplina que deseja configurar como pre-requisito:\n");
				LER_leString(codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
				ret = GRC_inserePreRequisito(codigo);
				break;
			case 6:
				system("cls");
				GRC_removePreRequisitos();
				break;
			case 7:
				system("cls");
				printf("\nDeseja mesmo apagar toda a grade curricular?\n1-Sim\n2-Nao\n");				
				LER_leInteiro(&opcao, 0, 1, LER_comparaLeSoNumero);
				if (opcao == 1) {
					system("cls");
					CDI_limpa();
					printf("A grade curricular foi completamente apagada.\n");
				}
				ret = GRC_limpa();//TODO verificar retorno
				MEN_menuAnterior();
				break;
			case 8:
				system("cls");
				printf("Digite o codigo da disciplina em que deseja inserir uma turma:\n");
				LER_leString(codigo, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
				printf("Digite o codigo da turma:\n");				
				LER_leString(codTur, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
				printf("Digite o dia da semana da aula:\n");
				// Pode nao parecer coerente pelo nome da funcao usa-la aqui, mas na verdade os caracteres sao quase os mesmos
				// Talvez fosse bom renomear essas funções para que uso delas fosse mais intuitivo
				LER_leString(diaSem, 0, LER_TAM_STRING, MEN_comparaLeCodigoGRC, 1);
				do {
					printf("Digite a hora de inicio da aula(7 >= HorIni <= 21):\n");
					LER_leInteiro(&horIni, 1, 2, LER_comparaLeSoNumero);
					//scanf("%d", &horIni);
				} while (horIni > 21 || horIni <7);
				do {
					printf("Digite a hora do termino da aula (9 >= HorTer <= 23):\n");
					LER_leInteiro(&horTer, 1, 2, LER_comparaLeSoNumero);
					//scanf("%d", &horTer);
				} while (horTer >23 || horTer < 9);
				printf("Digite a quantidade de vagas:\n");
				LER_leInteiro(&qtdVag, 0, 2, LER_comparaLeSoNumero);
				ret = GRC_insereTurma(codTur, horIni, horTer, diaSem, qtdVag, codigo);
				break;
			case 9:
				system("cls");
				printf("Digite o codigo da disciplina que deseja checar as turmas:\n");
				scanf(" %s", codigo);
				ret = GRC_exibeTurmas(codigo);
				break;
			default:
				if (opcao)
					printf("Opcao inválida!\n");
				break;
			}
			if (ret == GRC_CondRetOk)
			{
				printf("Operacao realizada com sucesso!\n");
			}
			else if (ret == GRC_CondRetNaoHaMemoria)
				printf("ERRO. Nao ha memoria suficiente.\n");
			else if (ret == GRC_CondRetGradeCurricularVazia)
				printf("Ainda nao existe nenhuma disciplina cadastrada.\n");
			else if (ret == GRC_CondRetDisciplinaNaoEncontrada)
				printf("A disciplina solicitada nao foi encontrada.\n");
			else if (ret == GRC_CondRetIdJaCriado)
				printf("ERRO.Ja existe uma Disciplina com este codigo.\n");
			else if (ret == GRC_CondRetFormatoInvalido)
				printf("ERRO. Formato de dados invalido.\n");
			MEN_menuAnterior();
		} while (opcao);
	}

/***********************************************************************
*
*  $FC Função: MEN_menuAnterior
*
*  $ED Descrição da função
*	  		
*
***********************************************************************/
/*Assertivas: 
/			 
***********************************************************************/

	void MEN_menuAnterior (void) 
	{
		
		printf("\nPressione qualquer tecla para voltar para o menu anterior.\n") ;
		getch() ;
		system("cls") ;
		return ;
		
	}

/********** Fim do módulo de implementação: MEN Menu **********/
