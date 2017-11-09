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
*             Vinícius Cortat (Grupo )
*
*  $HA Histórico de evolução:
*     Versão  Autor         Data		Observações
*     1.02    Cristiane  08/11/2017     Revisão/finalização
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
#include <conio.h>
#include <ctype.h>

#include "menu.h"
#include "corpodiscente.h"
#include "aluno.h"
#include "corpoDocente.h"
#include "gradeCurricular.h"


/***** Declarações encapsuladas pelo módulo *****/

	#define MEN_TAM_STRING 80


/*****  Protótipos das funções encapsuladas no módulo  *****/

	void MEN_leCPF ( char * cpf ) ;
	int MEN_leMatricula ( void ) ;
	void MEN_leData ( int * Ddia, int * Dmes, int * Dano ) ;
	int MEN_leNumero ( void ) ;

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
		mat = MEN_leMatricula();
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
		mat = MEN_leMatricula();
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
		char nome[81];
		int mat, telefone;
		Data nasc; 
		Endereco end;
		char cpf_completo[12];
		CPF cpf;
		CDI_tpCondRet retBusca;

		printf ("*********** CADASTRO DE ALUNO ***********\n\n");

		//adiciona aluno
		system("cls");
		printf("\nDigite o nome do aluno: \n");
		scanf(" %80s", nome);

		printf("\nDigite a matricula (8 digitos): \n");
		mat = MEN_leMatricula();
		printf("\n");

		printf("\nDigite o numero do telefone: \n");
		scanf("%d", &telefone);

		printf("\nDigite a data de nascimento: ");
		MEN_leData (&nasc.dia, &nasc.mes, &nasc.ano);
		printf("\n");

		printf("\nDigite o numero do CPF (11 digitos): \n");
		MEN_leCPF(cpf_completo);
		cpf.cod = atoi(cpf_completo+9);
		cpf_completo[9] = '\0';
		cpf.dig3 = atoi(cpf_completo+6);
		cpf_completo[6] = '\0';
		cpf.dig2 = atoi(cpf_completo+3);
		cpf_completo[3] = '\0';
		cpf.dig1 = atoi(cpf_completo);

		printf("\nDigite a sigla estado:\n");
		scanf(" %2s", end.estado);

		printf("\nDigite a cidade:\n");
		scanf(" %s", end.cidade);

		printf("\nDigite o bairro:\n");
		scanf(" %s", end.bairro);

		printf("\nDigite a rua:\n");
		scanf(" %s", end.rua);

		printf("\nDigite o complemento:\n");
		scanf(" %s", end.comp);

		retBusca = CDI_insere(nome, (unsigned int)mat, &cpf, telefone, &nasc, &end);

		if(retBusca == CDI_CondRetAlunoJaCadastrado)
			printf("Aluno ja cadastrado.");
		else
			if (retBusca == CDI_CondRetFaltouMemoria)
				printf("Erro de memoria ao cadastrar.");
			else
				printf("\nAluno cadastrado com sucesso!\n");
	
		printf("Pressione ENTER para voltar ao menu principal...\n");
		getch();
		system("cls");
		return;
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
		char nome[81], cpf_completo[12];
		int mat, telefone, matAnt;
		Data nasc; 
		Endereco end;
		CPF cpf;
		Aluno* Alu;
		int opcao;

		printf("*********** EDITAR DADOS DE PROFESSOR ***********\n\n");

		printf("Digite a matricula do aluno para alterar seus dados: ");
		scanf("%u",&matAnt);
		if (CDI_busca((unsigned int)matAnt,&Alu) != CDI_CondRetOK) 
		{
			printf("Aluno nao encontrado...\n");
			printf("Pressione ENTER para voltar ao menu principal...\n");
			getch();
			return;
		}

		printf("Escolha o dado a ser alterado: \n\n");
		printf("Digite 1: Nome\n");
		printf("Digite 2: Matricula\n");
		printf("Digite 3: Telefone\n");
		printf("Digite 4: Data de Nascimento\n");
		printf("Digite 5: CPF\n");
		printf("Digite 6: Endereco\n");
		scanf("%d",&opcao);

		system("cls");

		switch(opcao)
		{
			case 1: 
				printf("\nDigite o novo nome do aluno: \n");
				scanf(" %s", nome);
				CDI_altera(matAnt,nome,0,NULL,0,NULL,NULL);
				break;
			case 2:
				printf("\nDigite a nova matricula do aluno (8 digitos): \n");
				mat = MEN_leMatricula();
				CDI_altera(matAnt, NULL, (unsigned int)mat, NULL, 0, NULL, NULL);
				break;
			case 3:
				printf("\nDigite o novo telefone do aluno: \n");
				scanf(" %u", &telefone);
				CDI_altera(matAnt, NULL, 0, NULL,telefone, NULL, NULL);
				break;
			case 4:
				printf("\nDigite a nova data de nascimento do aluno: \n");
				MEN_leData (&nasc.dia, &nasc.mes, &nasc.ano);
				CDI_altera(matAnt, NULL, 0, NULL,0,&nasc, NULL);
				break;
			case 5:
				printf("\nDigite o novo CPF do aluno (11 digitos): \n");
				MEN_leCPF(cpf_completo);
				cpf.cod = atoi(cpf_completo+9);
				cpf_completo[9] = '\0';
				cpf.dig3 = atoi(cpf_completo+6);
				cpf_completo[6] = '\0';
				cpf.dig2 = atoi(cpf_completo+3);
				cpf_completo[3] = '\0';
				cpf.dig1 = atoi(cpf_completo);
				CDI_altera(matAnt, NULL, 0, &cpf, 0, NULL, NULL);
				break;
			case 6:
				printf("\nDigite a sigla do estado: \n");
				scanf(" %s", end.estado);
				printf("\nDigite a cidade: \n");
				scanf(" %s", end.cidade);
				printf("\nDigite o bairro: \n");
				scanf(" %s", end.bairro);
				printf("\nDigite a rua: \n");
				scanf(" %s", end.rua);
				printf("\nDigite o complemento:\n");
				scanf(" %s", end.comp);
				CDI_altera(matAnt, NULL,0,NULL,0, NULL, &end);
				break;
			default:
				printf("Opcao invalida...");
				break;
		}

		printf("\nDados alterados com sucesso!\n");
		printf("Pressione ENTER para voltar ao menu principal...\n");
		getch();
		system("cls");
		return;
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

		system("cls");
		printf ("*********** CADASTRO DE PROFESSOR ***********\n\n");

		//Adiciona professor
		printf("Digite o nome: \n");
		scanf(" %80s", nome);

		printf("\nDigite o RG: \n");
		scanf("%d", &rg);

		printf("\nDigite o CPF (11 digitos): \n");
		MEN_leCPF(cpf);

		printf("\nDigite a matricula (8 digitos): \n");
		matricula = MEN_leMatricula();

		printf("\nDigite o telefone: \n");
		scanf("%d", &telefone);

		printf("\nDigite a data de nascimento: \n");
		MEN_leData (&dia, &mes, &ano);

		printf("\nDigite o pais: \n");
		scanf(" %s", pais);

		printf("\nDigite o email: \n");
		scanf(" %s", email);

		printf("\nDigite o estado:\n");
		scanf(" %2s", uf);

		printf("\nDigite a cidade:\n");
		scanf(" %s", cidade);
		
		printf("\nDigite o bairro:\n");
		scanf(" %s", bairro);

		printf("\nDigite a rua:\n");
		scanf(" %s", rua);

		printf("\nDigite a numero:\n");
		numero = MEN_leNumero();

		printf("\nDigite o complemento:\n");
		scanf(" %s", complemento);

		ret = CDO_cadastra(nome, rg, cpf, matricula, email, telefone, dia, mes, ano, pais, uf, cidade, bairro, rua, numero, complemento);
		if(ret == CDO_CondRetOk)
			printf("\nAlteracao realizada com sucesso!\n");
		else if(ret == CDO_CondRetFormatoInvalido)
			printf("\nERRO. Formato de dados invalido.\n");
		else if(ret == CDO_CondRetIdJaCriado)
			printf("\nERRO. Ja existe um professor com este valor de identificacao.\n");
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

		system("cls");
		printf("\n*********** EDITAR DADOS DE PROFESSOR ***********\n");

		printf("Digite a matrícula do professor que deseja modificar (8 digitos):\n");
		paramInt = MEN_leMatricula();
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
				scanf(" %2s", uf);
				printf("\nDigite a nova cidade:\n");
				scanf(" %s", cidade);
				printf("\nDigite o novo bairro:\n");
				scanf(" %s", bairro);
				printf("\nDigite a nova rua:\n");
				scanf(" %s", rua);
				printf("\nDigite o novo numero:\n");
				numero = MEN_leNumero();
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
					ret = GRC_cadastra(nome, codigo, creditos, bibliografia, ementa, 3);
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

/***********************************************************************
*
*  $FC Função: MEN_leCPF
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: 
/			 
***********************************************************************/

	void MEN_leCPF ( char * cpf )

	{
		char a ;
		int cont = 0 ;

		do
		{
			a = getch() ;
			if (a < 0)
				a = 128 + (128 - a) ;

			if ( isdigit(a) && cont < 11 )
			{			
				cpf [cont] = a ;
				printf("%c", cpf[cont]) ;
				cont++ ;
			} 
			else
				if (a==8 && cont) // 8 = BackSpace
				{
					printf("\b \b") ;
					cont-- ;
					cpf[cont] = '\0' ;
				} /* if */
		} while ( cont < 11 || (a != 13 && cont == 11) ); // 13 = Enter

		cpf[11] = '\0' ;

		printf ("\n");
	}

/***********************************************************************
*
*  $FC Função: MEN_leMatricula
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: 
/			 
***********************************************************************/

	int MEN_leMatricula ( void )
	{
		char a, mat[9] ; 
		int cont = 0 ;

		do
		{
			a = getch() ;
			if (a < 0)
				a = 128 + (128 - a) ;

			if ( isdigit(a) && cont < 8 )
			{			
				mat [cont] = a ;
				printf("%c", mat[cont]) ;
				cont++ ;
			} 
			else
				if (a==8 && cont) // 8 = BackSpace
				{
					printf("\b \b") ;
					cont-- ;
					mat[cont] = '\0' ;
				} /* if */
		} while ( cont < 8 || (a != 13 && cont == 8) ) ; // 13 = Enter

		mat[8] = '\0' ;

		printf("\n");

		return atoi(mat) ;

	}

/***********************************************************************
*
*  $FC Função: MEN_leData
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: 
/			 
***********************************************************************/

	void MEN_leData ( int * Ddia, int * Dmes, int * Dano )
	{
		char a, dia[3], mes[3], ano[5]; 
		int cont = 0;

		//Dia
		do {
			printf("   Dia: "); 
			do
			{
				a = getch() ;
				if (a < 0)
					a = 128 + (128 - a) ;

				if ( isdigit(a) && cont < 2 )
				{			
					dia [cont] = a ;
					printf("%c", dia[cont]) ;
					cont++ ;
				} 
				else
					if (a==8 && cont) // 8 = BackSpace
					{
						printf("\b \b") ;
						cont-- ;
						dia[cont] = '\0' ;
					} /* if */
			} while ( cont < 2 || (a != 13 && cont == 2) ); // 13 = Enter

			dia[2] = '\0' ;
			* Ddia = atoi(dia);
		
			if (* Ddia > 31)
			{
				printf ("\n   Dia inválido. Digite o dia novamente.");
				cont = 0;
			}
		} while ( *Ddia > 31 );

		//Mes
		cont = 0;
		do {
			printf("\n   Mes: "); 
			do
			{
				a = getch() ;
				if (a < 0)
					a = 128 + (128 - a) ;

				if ( isdigit(a) && cont < 2 )
				{			
					mes [cont] = a ;
					printf("%c", mes[cont]) ;
					cont++ ;
				} 
				else
					if (a==8 && cont) // 8 = BackSpace
					{
						printf("\b \b") ;
						cont-- ;
						mes[cont] = '\0' ;
					} /* if */
			} while ( cont < 2 || (a != 13 && cont == 2) ); // 13 = Enter

			mes[2] = '\0' ;
			* Dmes = atoi(mes);
		
			if (* Dmes > 12)
			{
				printf ("\n   Mes inválido. Digite o mes novamente.");
				cont = 0;
			}
		} while ( *Dmes > 12 );

		//Ano
		cont = 0;
		do {
			printf("\n   Ano: "); 
			do
			{
				a = getch() ;
				if (a < 0)
					a = 128 + (128 - a) ;

				if ( isdigit(a) && cont < 4 )
				{			
					ano [cont] = a ;
					printf("%c", ano[cont]) ;
					cont++ ;
				} 
				else
					if (a==8 && cont) // 8 = BackSpace
					{
						printf("\b \b") ;
						cont-- ;
						ano[cont] = '\0' ;
					} /* if */
			} while ( cont < 4 || (a != 13 && cont == 4) ); // 13 = Enter

			ano[4] = '\0' ;
			* Dano = atoi(ano);
		
			if (* Dano < 1900)
			{
				printf ("\n   Ano inválido. Digite o ano novamente.");
				cont = 0;
			}
		} while ( *Dano < 1900 );

		printf("\n");
	}

/***********************************************************************
*
*  $FC Função: MEN_leNumero
*
*  $ED Descrição da função
*		
*
***********************************************************************/
/*Assertivas: 
/			 
***********************************************************************/

	int MEN_leNumero ( void )
	{
		char a, num[9] ; 
		int cont = 0 ;

		do
		{
			a = getch() ;
			if (a < 0)
				a = 128 + (128 - a) ;

			if ( isdigit(a) && cont < 8 )
			{			
				num [cont] = a ;
				printf("%c", num[cont]) ;
				cont++ ;
			} 
			else
				if (a==8 && cont) // 8 = BackSpace
				{
					printf("\b \b") ;
					cont-- ;
					num[cont] = '\0' ;
				} /* if */
		} while ( a != 13 ) ; // 13 = Enter

		num[8] = '\0' ;

		printf("\n");

		return atoi(num) ;

	}

