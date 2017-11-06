/***************************************************************************
*  $MCI Módulo de implementação: TUR  Turma
*
*  Arquivo gerado:              TURMA.c
*  Letras identificadoras:      TUR
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathália
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     3       cgln  10/set/2017 manutenção das funções do módulo
*     2       cgln  07/set/2017 unificação de todos os módulos em um só projeto
*     1       cgln  29/ago/2017 início desenvolvimento
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "turma.h"

/***********************************************************************
*
*  $TC Tipo de dados: TUR turma
*
*
***********************************************************************/

	struct turma {

		char CodTurma [4] ;
			/* Código da turma */

		int HorarioInicio ;
			/* Horário de início da turma */

		int HorarioTermino ;
			/* Horário de término da turma */

		char DiaSemana[28] ;
			/* Dias da semana da turma */

		int QtdVaga ;
			/* Número de vagas da turma */

	};

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
* Função: TUR  &Cria turma
*  ****/

	TUR_tpCondRet TUR_CriaTurma ( Turma ** NovaTurma, char * CodTur,
		int HorIni, int HorTer, char * DiaSem, int QtdVag )
	{

		* NovaTurma = ( Turma * ) malloc( sizeof( Turma )) ;

		if ( * NovaTurma == NULL )
		{
			return TUR_CondRetFaltouMemoria ;
		} /* if */
		
		strcpy( ( *NovaTurma )->CodTurma, CodTur ) ;

		if ( HorIni < 7 || HorIni > 21 )
		{
			return TUR_CondRetFormatoInvalido;
		} /* if */

		( *NovaTurma )->HorarioInicio = HorIni ;

		if ( HorTer < 07 || HorTer > 23) 
		{
			return TUR_CondRetFormatoInvalido ;
		} /* if */

		( *NovaTurma )->HorarioTermino = HorTer ;

		strcpy( ( *NovaTurma )->DiaSemana, DiaSem ) ;

		( *NovaTurma )->QtdVaga = QtdVag ;

		return TUR_CondRetOk ;

	} /* Fim função: TUR  &Cria turma */

/***************************************************************************
*
*  Função: TUR  &Altera horario inicio
*  ****/

	TUR_tpCondRet TUR_AlteraHorarioInicio ( Turma * tur, int hora1 )
	{

		if ( hora1 < 7 || hora1 > 21 )
		{
			return TUR_CondRetFormatoInvalido ;
		} else
		{
			tur->HorarioInicio = hora1 ;
			printf( "Hora alterada" ) ;
			return TUR_CondRetOk ;
		} /* if */
	
	} /* Fim função: TUR  &Altera horario inicio */
  
/***************************************************************************
*
*  Função: TUR  &Altera horario final
*  ****/
   
    TUR_tpCondRet TUR_AlteraHorarioFinal ( Turma * tur, int hora2 )
    {

        if ( hora2 < 9 || hora2 > 23 )
		{
			return TUR_CondRetFormatoInvalido ;
		} else
		{
			tur->HorarioTermino = hora2 ;
			printf( "Hora alterada" ) ;
			return TUR_CondRetOk ;
		} /* if */

	} /* Fim função: TUR  &Altera horario final */

/***************************************************************************
*
*  Função: TUR  &Altera dia
*  ****/

	TUR_tpCondRet TUR_AlteraDia ( Turma * tur, char * dia )
	{

		strcpy( tur->DiaSemana, dia ) ;
		printf( "Dias alterados" ) ;
        return TUR_CondRetOk ;

    } /* Fim função: TUR  &Altera dia */

/***************************************************************************
*
*  Função: TUR  &Altera codigo
*  ****/

	TUR_tpCondRet TUR_AlteraCodigo ( Turma * tur, char * cod )
	{ 

		strcpy( tur->CodTurma, cod ) ;
		printf( "Codigo alterado" ) ;
		return TUR_CondRetOk ;

	} /* Fim função: TUR  &Altera codigo */

/***************************************************************************
*
*  Função: TUR  &Altera qtd vaga
*  ****/

	TUR_tpCondRet TUR_AlteraQtdVaga ( Turma * tur, int qtd )
	{

		tur->QtdVaga = qtd ;
		printf( "Quantidade alterada" ) ;
		return TUR_CondRetOk ;

	} /* Fim função: TUR  &Altera qtd vaga */

/***************************************************************************
*
*  Função: TUR  &Get codigo
*  ****/

	TUR_tpCondRet TUR_GetCodigo ( Turma * tur, char * CodTur)
	{

		strcpy( CodTur, tur->CodTurma ) ;
		return TUR_CondRetOk ;
		
	} /* Fim função: TUR  &Get codigo */

/***************************************************************************
*
*  Função: TUR  &Get horário inicio
*  ****/

	TUR_tpCondRet TUR_GetHorIni ( Turma * tur, int * HorIni)
	{

		*HorIni = tur->HorarioInicio ;
		return TUR_CondRetOk ;

	} /* Fim função: TUR  &horário inicio */

/***************************************************************************
*
*  Função: TUR  &Get horário final
*  ****/

	TUR_tpCondRet TUR_GetHorFin ( Turma * tur, int * HorTer )
	{

		*HorTer = tur->HorarioTermino ;
		return TUR_CondRetOk ;

	}  /* Fim função: TUR  &horário final */

/***************************************************************************
*
*  Função: TUR  &Get dia
*  ****/

	TUR_tpCondRet TUR_GetDiaSem ( Turma * tur, char * DiaSem ) 
	{

		strcpy( DiaSem, tur->DiaSemana ) ;
		return TUR_CondRetOk ;

	}  /* Fim função: TUR  &Get dia */

/***************************************************************************
*
*  Função: TUR  &Get qtd vaga
*  ****/
	
	TUR_tpCondRet TUR_GetQtdVaga ( Turma * tur, int * QtdVag )
	{

		*QtdVag = tur->QtdVaga ;
		return TUR_CondRetOk ;

	} /* Fim função: TUR  &Get qtd vaga */

/***************************************************************************
*
*  Função: TUR  &Get turma
*  ****/

	TUR_tpCondRet TUR_GetTurma ( Turma * tur, char * CodTur, int * HorIni, int * HorTer,
		char * DiaSem, int * QtdVag )
	{

		strcpy( CodTur, tur->CodTurma ) ;
		*HorIni = tur->HorarioInicio ;
		*HorTer = tur->HorarioTermino ;
		strcpy( DiaSem, tur->DiaSemana ) ;
		*QtdVag = tur->QtdVaga ;

		return TUR_CondRetOk ;

	}  /* Fim função: TUR  &Get turma */

/***************************************************************************
*
*  Função: TUR &Exibe turma
*  ****/
	
	TUR_tpCondRet TUR_ExibeTurma ( Turma * tur )
	{

		puts( "\n\n****** TURMA SELECIONADA ******" ) ;
		printf( "\nCodigo: %s",tur->CodTurma ) ;
		printf( "\nHorario de inicio: %d:00",tur->HorarioInicio ) ;
		printf( "\nHorario de termino: %d:00",tur->HorarioTermino ) ;
		printf( "\nDias da semana: %s",tur->DiaSemana ) ;
		printf( "\nQuantidade de vagas: %d\n\n",tur->QtdVaga ) ;

		return TUR_CondRetOk ;

	} /* Fim função: TUR  &Exibe turma */

/***************************************************************************
*
*  Função: TUR  &Exclui turma
*  ****/

	TUR_tpCondRet TUR_ExcluiTurma ( Turma * turma )
	{

		free( turma ) ;
		
		return TUR_CondRetOk ;

	} /* Fim função: TUR  &Exclui turma */

/********** Fim do módulo de implementação: TUR  Turma **********/
