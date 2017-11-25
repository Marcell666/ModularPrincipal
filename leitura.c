/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Leitura
*
*  Arquivo gerado:              leitura.c
*  Letras identificadoras:      LER
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 1 / Grupo 5
*  Autores:   Bruce Marcellino (Grupo 1)
*             Cristiane Ramalho Guimarães (Grupo 5)
*
*  $HA Histórico de evolução:
*     Versão  Autor         Data		Observações
*     0.02    Bruce/Cris  25/11/2017  	Revisão
*     0.01    Bruce/Cris  25/11/2017    Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo efetura leitura.
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
#include "leitura.h"

typedef int (*LER_Compara) (unsigned char) ;

/*****  Protótipos das funções encapsuladas no módulo  *****/

	void LER_leDataUtil ( int * leValor, int max, char * nome ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
* Função: LER  &Le String
*  ****/

	void LER_leString ( char * leValor, int min, int max, LER_Compara compara, int converte )
	{

		unsigned char a ;
		int cont = 0 ;
		do
		{
			a = getch() ;
		
			if ( compara(a)  && cont < max )
			{			
				if ( converte == 1 ) 
				{
					a = toupper(a) ;
				}
				else
					if ( converte == -1 )
					{
						a = tolower(a) ;
					} /* if */
			
				leValor [cont] = (char) a ;
				printf( "%c", leValor[cont] ) ;
				cont++ ;
			}
			else
				if ( a == VK_BACKSPACE && cont )
				{
					printf( "\b \b" ) ;
					cont-- ;
					leValor [cont] = '\0' ;
				} /* if */
		} while ( cont < min || (a != VK_ENTER && cont <= max) ) ;
	
		leValor[cont] = '\0' ;
		printf( "\n" ) ;

	}  /* Fim função: LER  &Le string */

/***************************************************************************
*
* Função: LER  &Le Inteiro
*  ****/

	void LER_leInteiro ( int * leValor,int min, int max, LER_Compara compara )
	{

		char cad_carac[LER_TAM_STRING+1] ;
		LER_leString( cad_carac, min, max, compara, 0 ) ;
		* leValor = atoi( cad_carac ) ;

	} /* Fim função: LER  &Le Inteiro */

/***************************************************************************
*
* Função: LER  &Compara Le So Letra
*  ****/

	int LER_comparaLeSoLetra ( unsigned char a )
	{

		return ( isalpha(a) || a == ' ' ) ;

	} /* Fim função: LER  &Compara Le So Letra */

/***************************************************************************
*
* Função: LER  &Compara Le So Numero
*  ****/

	int LER_comparaLeSoNumero ( unsigned char a )
	{

		return  isdigit(a) ;

	} /* Fim função: LER  &Compara Le So Numero */

/***************************************************************************
*
* Função: LER  &Compara Le Logradouro
*  ****/

	int LER_comparaLeLogradouro ( unsigned char a )
	{

		return isdigit(a) || isalpha(a) || a == ' ' ||  a == '.' || a == '-' ;

	} /* Fim função: LER  &Compara Le Logradouro */

/***************************************************************************
*
* Função: LER  &Compara Le Complemento
*  ****/

	int LER_comparaLeComplemento ( unsigned char a )
	{

		return isalpha(a) || isdigit(a) || a == ' ' || a == ',' || a == '.' || a == ';' || a == '(' || a == ')' || a == '-' ;

	} /* Fim função: LER  &Compara Le Complemento */

/***************************************************************************
*
* Função: LER  &Compara Le Email 
*  ****/

	int LER_comparaLeEmail ( unsigned char a )
	{

		return islower(a) || isdigit(a) || a == '.' || a == '@' || a == '_' || a == '-' ;

	} /* Fim função: LER  &Compara Le Email */

/***************************************************************************
*
* Função: LER  &Compara Le UF
*  ****/

	void LER_leUF ( char * UF )
	{

		int i ;
		char estados [][3]= { "AC","AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG",
			"PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO" } ;

		do {
			LER_leString( UF, LER_TAM_UF, LER_TAM_UF, LER_comparaLeSoLetra, 1 ) ;
			i = 0 ;

			while ( i < LER_QTD_EST && strcmp( UF, estados[i] ) )
			{
				i++ ;
			} /* while */

			if ( i == LER_QTD_EST )
			{
				printf ( "Esta sigla de estado não existe. Digite uma sigla correspondente a um estado brasileiro.\n" ) ;
			} /* if */

		} while ( i == LER_QTD_EST ) ;

		printf( "\n" ) ;

	} /* Fim função: LER  &Compara Le UF */

/***************************************************************************
*
* Função: LER  &Compara Le Data
*  ****/

	void LER_leData ( int * dia, int * mes, int * ano )
	{
		static int maxDias[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ; 

		do // verifica se o número do dia corresponde ao número máximo de dias do mês informado
		{
			LER_leDataUtil( dia, 31, "Dia" ) ;
			LER_leDataUtil( mes, 12, "Mes" ) ;
			
			if ( * dia > maxDias [* mes - 1] )
			{
				printf ( "\tDia invalido para o mes informado. Digite o dia e o mes novamente.\n" ) ;
			} /* if */

		} while ( * dia > maxDias [* mes - 1] ) ;
		
		//ANO
		do 
		{
			printf( "\tAno: " ) ;
			LER_leInteiro( ano, 4, 4, LER_comparaLeSoNumero ) ;
		
			if ( * ano < LER_MIN_ANO )
			{
				printf( "\tAno invalido. Digite o ano novamente.\n" ) ;
			}

		} while ( * ano < LER_MIN_ANO ) ;

		printf( "\n" ) ;

	} /* Fim função: LER  &Compara Le UF */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: LER  -Le Data Util
*
*  $ED Descrição da função
*     
*
***********************************************************************/

	void LER_leDataUtil ( int * leValor, int max, char * nome )
	{
		do
		{
			printf( "\t%s: ", nome ) ; 
			LER_leInteiro( leValor, 1, 2, LER_comparaLeSoNumero ) ;
	
			if ( * leValor > max ) 
			{
				printf( "\t%c%s invalido. Digite o %s novamente.\n", toupper(nome[0]), nome+1, nome ) ;
			} /* if */

		} while ( * leValor > max ) ;

	} /* Fim função: LER  -Le Data Util */
