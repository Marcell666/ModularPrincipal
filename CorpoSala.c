/***************************************************************************
*  $MCI Modulo de implementacao: CDS  Corpo de Salas
*
*  Arquivo gerado:             CorpoSala.c
*  Letras identificadoras:     CDS
*
*  Nome da base de software:    Arcabouco para a automacao de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza??o dos testes de modulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathalia 
*	BM - Bruce Marcellino
*
*  $HA Hist?rico de evolu??o:
*     Vers?o  Autor    Data     Observacoes
*	3.01	BM	01/dez/2017	Persistencia de dados de sala
*     3       cgln  04/nov/2017 manutencao das funcoes do modulo
*     2       cgln  02/nov/2017 unificacao de todos os modulos em um so projeto
*     1       cgln  31/out/2017 inicio desenvolvimento
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "CorpoSala.h"

/***********************************************************************
*
*  $TC Tipo de dados: CDS Corpo Sala
*
***********************************************************************/

	typedef struct corposala{

		List * Sala ;
		/* Cabeca da lista de salas */

	} CorpoSala ;


/*****  Dados encapsulados no modulo  *****/

	static CorpoSala * CorpoS ;
	/* inst�ncia de corpo de sala armazenada por este m�dulo */


/*****  Prot�tipos das fun��es encapsuladas no m�dulo  *****/

	SAL_tpSala* CDS_buscaDispo( int dia, int horini, int horfim, int qtd, int lab ) ;

 
/***************************************************************************
* Funcao: CDS  &Cria Corpo Sala
*  ****/

	CDS_tpCondRet CDS_cria ()
	{

		CorpoS = ( CorpoSala * ) malloc( sizeof( CorpoSala )) ;
		//createList(&CorpoS->Sala);
    
		if ( createList( &(CorpoS->Sala )) != LIS_CondRetOK )
		{
			return CDS_CondRetFaltouMemoria ;
		} /* if */

		return CDS_CondRetOK ;

	} /* Fim funcao: CDS  &Cria Corpo Sala */
 
/***************************************************************************
* Funcao: CDS  &Busca Codigo 
*  ****/

	CDS_tpCondRet CDS_buscaCod ( SAL_tpSala **s, char * codigo )
	{ 

		char cod[CDS_TAM_COD] ;
		unsigned int i=0, size = 0 ; 
   
		if(s == NULL){
			return CDS_CondRetParametroInvalido;
		}
    
		list_size( CorpoS->Sala, &size ) ;
    
		first( CorpoS->Sala ) ;
    
		for ( i = 0;i < size; i++ ) 
		{
			get_val_cursor( CorpoS->Sala, ( void** ) s ) ;
			SAL_getCodigo( *s, cod ) ;
			if ( strcmp( codigo, cod ) == 0 )
			{
				return CDS_CondRetOK ;
			} /* if */

			next( CorpoS->Sala ) ;
		} /* for */

		*s = NULL;

		return CDS_CondRetNaoAchou ;

	} /* Fim funcao: CDS &Busca Codigo Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Insere Corpo Sala
*  ****/

	CDS_tpCondRet CDS_insere( char * codigo, int maxAlunos, int eLaboratorio )
	{
		SAL_tpCondRet ret;
		SAL_tpSala * s ;
 		CDS_buscaCod( &s, codigo );
		if (  s != NULL )
		{
			return CDS_CondRetSalaJaCadastrada ;
		} /* if */
    
		s = NULL;
		ret = SAL_criarSala( &s, codigo, maxAlunos, eLaboratorio ) ;

		if(ret != SAL_CondRetOK){
			#ifdef _DEBUG
			printf("Erro ao inserir sala %d\n", (int) ret);
			#endif
			return CDS_CondRetParametroInvalido;
		}
		if ( s == NULL )
		{
			return CDS_CondRetFaltouMemoria ;
		} else
		{
			push_back( CorpoS->Sala, s) ;
			return CDS_CondRetOK ;
		} /* if */

	}/* Fim funcao: CDS &Insere Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Retira Corpo Sala
*  ****/

	CDS_tpCondRet CDS_retira( char * codigo )
	{

		SAL_tpSala * s ;
    
		CDS_buscaCod( &s, codigo ) ;
    
		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			pop_cursor( CorpoS->Sala, ( void** ) &s ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Retira Corpo Sala */
		
/***************************************************************************
* Funcao: CDS  &Exibe Corpo Sala
*  ****/

	CDS_tpCondRet CDS_exibe ()
	{

		unsigned int i=0, tam = 0 ;
		SAL_tpSala  * s = NULL;
	
		list_size( CorpoS->Sala, &tam ) ;

		printf("funcao exibe\n");

		if ( tam == 0 )
		{
			printf( "\n\nNao ha salas cadastradas.\n" ) ;
			return CDS_CondRetCDSVazio ;
		} /* if */

		first( CorpoS->Sala ) ;

		for ( i = 0; i < tam; i++ )
		{
			get_val_cursor( CorpoS->Sala, ( void** ) &s ) ;
			SAL_printSala( s );
			next( CorpoS->Sala ) ;
			printf( "\n" ) ;
		}

		return CDS_CondRetOK ;

	} /* Fim funcao: CDS &Exibe Corpo Sala */
	
/***************************************************************************
* Funcao: CDS  &Libera Corpo Sala
*  ****/

	CDS_tpCondRet CDS_libera ()
	{
		CDS_limpa();
		del(CorpoS->Sala);
		return CDS_CondRetOK ; 

	} /* Fim funcao: CDS &Libera Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Limpa Corpo Sala
*  ****/

	CDS_tpCondRet CDS_limpa ()
	{
		/*  TODO IMPORTANTE

			Corrigir esta fun��o
			Ela esta com VAZAMENTO DE MEMORIA
		
		SAL_tpSala *pSala=NULL;
		if(pop_back(CorpoS->Sala, (void**) &pSala) == LIS_CondRetListaVazia)
			return CDS_CondRetCDSVazio;
		SAL_removeSala(&pSala);
		while(pop_back(CorpoS->Sala, (void**) &pSala)==LIS_CondRetOK){
			SAL_removeSala(&pSala);
		}
		*/
		clear(CorpoS->Sala);
		return CDS_CondRetOK;

	} /* Fim funcao: CDS &Limpa Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Qtd Max Corpo Sala
*  ****/

	CDS_tpCondRet CDS_getQtdMax( int * max, char * cod )
	{
		SAL_tpSala * s ;
		CDS_buscaCod(&s, cod ) ;
	
		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_getMaxAlunos( s, max ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Qtd Max Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Tipo Corpo Sala
*  ****/

	CDS_tpCondRet CDS_getTipo( int * tipo, char * cod )
	{
		SAL_tpSala * s ;
		CDS_buscaCod(&s, cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_getELaboratorio( s, tipo ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Tipo Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Num Corpo Sala
*  ****/

	CDS_tpCondRet CDS_getNum( int * num, char * cod )
	{
		SAL_tpSala * s ;
		CDS_buscaCod(&s, cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_getNumero ( s, num ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Num Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Predio Corpo Sala
*  ****/

	CDS_tpCondRet CDS_getPredio( char * predio, char * cod )
	{
		SAL_tpSala * s ;
		CDS_buscaCod(&s, cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;

		} else
		{
			SAL_getPredio ( s,predio ) ;
			return CDS_CondRetOK ;
		} /* if */
	
	} /* Fim funcao: CDS &Get Predio Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Get Andar Corpo Sala
*  ****/

	CDS_tpCondRet CDS_getAndar( int * andar, char * cod )
	{
		SAL_tpSala * s ;
		CDS_buscaCod(&s, cod ) ;
		
		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;

		} else
		{
			SAL_getAndar ( s, andar ) ;
			return CDS_CondRetOK ;
		} /* if */

	} /* Fim funcao: CDS &Get Andar Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Exibe Disponibilidade Corpo Sala
*  ****/

	CDS_tpCondRet CDS_exibeDisponibilidade( char * cod )
	{
		SAL_tpSala * s ;
		CDS_buscaCod(&s, cod ) ;

		if ( s == NULL )
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			SAL_printDisponibilidade( s ) ;
			return CDS_CondRetOK ; 
		} /* if */

	} /* Fim funcao: CDS &Exibe Disponibilidade Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Busca Disponibilidade Corpo Sala
*  ****/

	SAL_tpSala * CDS_buscaDispo( int dia, int horini, int horfim, int qtd, int lab )
	{
    
		unsigned int i = 0, size = 0 ;
		SAL_tpSala  * s = NULL ;
		int elab ;
		int maxalu ;
		list_size( CorpoS->Sala, &size ) ;
		first( CorpoS->Sala ) ;

		for ( i = 0;i < size; i++ )
		{
			get_val_cursor( CorpoS->Sala, ( void ** ) &s ) ;
			if ( SAL_getHorarioNoDia( s, dia, horini, horfim ) == SAL_CondRetOK )
			{
				SAL_getELaboratorio ( s, &elab ) ;
				if ( elab == lab )
				{
					SAL_getMaxAlunos( s, &maxalu ) ;
					if( maxalu >= qtd )
					{
						return s ;
					} /* if */
				} /* if */
			} /* if */
        
			next( CorpoS->Sala ) ; 
		} /* for */
    
		printf( "Sala nao disponivel ou inexistente\n" ) ;
		return NULL ;
    
	} /* Fim funcao: CDS &Busca Disponibilidade Corpo Sala */

/***************************************************************************
* Funcao: CDS  &Reserva Sala
*  ****/

	CDS_tpCondRet CDS_reservaSala( int dia, int horini, int horfim, int qtd, int lab )
	{
		int a = -1 ; 
		SAL_tpSala  * s =  NULL ;
		s = CDS_buscaDispo( dia,  horini,  horfim, qtd, lab ) ;

		if (s == NULL)
		{
			return CDS_CondRetSalaNaoCadastrada ;
		} else
		{
			a = SAL_reservaSala( s, dia, horini, horfim ) ;
			if( a == SAL_CondRetOK )
			{
				SAL_printSala( s ) ;
				printf( "Sala Reservada Com Sucesso\n" ) ;
			} /* if */

			return CDS_CondRetOK ;
		} /* if */
        
	}/* Fim funcao: CDS &Reserva Sala */

/***************************************************************************
 *
 *  Fun��o: CDS Salva Dados
 *  ****/

	CDS_tpCondRet CDS_salvaDados( char * path )
	{

		SAL_tpSala * pSala;

		FILE *f ;
		#ifdef _DEBUG
			printf("PATH: %s\n", path) ;
		#endif

		f = fopen(path,"wt") ;

		if ( !f )
		{
			#ifdef _DEBUG	
				printf( "Erro ao salvar arquivo de dados das salas no m�dulo CDS. %s\n", path ) ;
			#endif
			return CDS_CondRetErroAbrirArquivo ;
		} /* if */

		first( CorpoS->Sala ) ;
		do
		{
			if( get_val_cursor( CorpoS->Sala , (void**) &pSala) == LIS_CondRetListaVazia )
			{
				fclose(f) ;
				return CDS_CondRetCDSVazio;
			}
			SAL_salvaDados(pSala, f);
		} while( next(CorpoS->Sala)==LIS_CondRetOK ) ;
		
		fclose(f) ;

		return CDS_CondRetOK ;

	}  /* Fim fun��o: CDS Salva Dados */

 /***************************************************************************
 *
 *  Fun��o: CDS Le Dados
 *  ****/

	CDS_tpCondRet CDS_leDados ( char * path )
	{

		
		CDS_tpCondRet ret;
		SAL_tpSala *pSala;
		FILE *f ;
		//int i;
		char c;
		/* TODO Esta variavel est� aqui somente para usar a scanf. Essa parte do codigo precisa ser melhorada num momento oportuno*/

		#ifdef _DEBUG
			printf( "PATH: %s\n", path ) ;
		#endif

		//abrindo arquivo
		f = fopen( path, "rt" ) ;

		if ( !f )
		{
			#ifdef _DEBUG
				printf("Erro ao abrir arquivo de dados pessoais das Salas no modulo Corpo de Salas.\nPATH: %s\n", path) ;
			#endif
			return CDS_CondRetOK;
		} /* if */

	
		//for(i=0;i<4;i++){
		while(fscanf(f, "%c", &c)>0){

			/*
				A sala n�o disponibiliza uma maneira de mudar a matriz de disponibilidade (Sim, � isso mesmo. A matriz de disponibilidade nao esta disponivel.)
				Por isso, a matriz gravada em arquivo precisa ser lida pela propria sala, pois aqui os dados dela estao encapsulados.
				Ent�o estou cadastrando uma sala com dados quaisquer, e passando para a sala. La ela le de um arquivo os daodos que precisa e os atribui a sala passada. Aqui, eu coloco a sala na lista.
				
			*/
			fseek(f, -1 , SEEK_CUR);
			ret = SAL_criarSala(&pSala, "F999", 1, 1);
			
			if(ret != CDS_CondRetOK)
			{
				#ifdef _DEBUG
					printf("Erro ao cadastrar Sala\n") ;
				#endif
			}
			ret = SAL_leDados(pSala, f);
			if(ret != CDS_CondRetOK)
			{
				#ifdef _DEBUG
					printf("Erro ao ler Sala\n") ;
				#endif
			}
			push_back( CorpoS->Sala, (void*) pSala) ;
		}

		fclose(f) ;

		return CDS_CondRetOK ;

	} /* Fim fun��o: CDS Le Dados */



/********** Fim do modulo de implementacao: CDS Corpo de Salas **********/
