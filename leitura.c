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

typedef int (*LER_Compara)(unsigned char);

void LER_leString ( char * leValor, int min, int max, LER_Compara compara)
{
	unsigned char a;
	int cont = 0 ;
	do
	{
		a = getch() ;
		
		if ( compara(a)  && cont < max)
		{			
			leValor [cont] = (char) a ;
			printf("%c", leValor[cont]) ;
			cont++ ;
		}
		else if (a==VK_BACKSPACE && cont)
		{
				printf("\b \b") ;
				cont-- ;
				leValor [cont] = '\0' ;
		}/* if */
	} while ( cont < min || (a != VK_ENTER && cont <= max) ) ;
	leValor[cont] = '\0' ;
	printf("\n");
}

void LER_leInteiro( int * leValor,int min, int max, LER_Compara compara)
{
	char cad_carac[LER_TAM_STRING+1];
	LER_leString(cad_carac, min, max, compara);
	*leValor = atoi(cad_carac);
}

int LER_comparaLeSoLetra(unsigned char a){
	return (isalpha(a) || a == ' ') ;
}

int LER_comparaLeSoNumero(unsigned char a){
	return  isdigit(a);
}

int LER_comparaLeLogradouro(unsigned char a){
	return isdigit(a) || isalpha(a) || a == ' ' ||  a == '.' || a == '-';
}
int LER_comparaLeComplemento(unsigned char a){
	return isalpha(a) || isdigit(a) || a == ' ' || a == ',' || a == '.' || a == ';' || a == '(' || a == ')' || a == '-';
}

int LER_comparaLeEmail(unsigned char a){
	return islower(a) || isdigit(a) || a == '.' || a == '@' || a == '_' || a == '-';
}

void LER_leUF ( char * UF )
	{
		int i;
		char estados [][3]= {"AC","AL", "AP", "AM", "BA", "CE", "DF", "ES", "GO", "MA", "MT", "MS", "MG",
			"PA", "PB", "PR", "PE", "PI", "RJ", "RN", "RS", "RO", "RR", "SC", "SP", "SE", "TO"};

		do {
			LER_leString(UF, LER_TAM_UF, LER_TAM_UF, LER_comparaLeSoLetra);
			UF[0] = toupper(UF[0]);
			UF[1] = toupper(UF[1]);
			i = 0 ;

			while ( i < LER_QTD_EST && strcmp (UF, estados[i]) )
			{
				i++ ;
			}

			if ( i == LER_QTD_EST )
			{
				printf ("\nEsta sigla de estado não existe. Digite uma sigla correspondente a um estado brasileiro.\n\n") ;
			} /* if */

		} while ( i == LER_QTD_EST ) ;

		printf("\n") ;
	}

void LER_leDataUtil(int *leValor, int max, char *nome){
	do
	{
		printf("\t%s: ", nome) ; 
		LER_leInteiro(leValor, 1, 2, LER_comparaLeSoNumero);
	
		if (* leValor > max)
		{
			printf ("\n\t%c%s invalido. Digite o %s novamente.\n", toupper(nome[0]), nome+1, nome) ;
		}
	} while ( * leValor > max) ;
}

void LER_leData ( int * dia, int * mes, int * ano )
	{
		static int maxDias[] = { 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 } ; 

		do // verifica se o número do dia corresponde ao número máximo de dias do mês informado
		{
			LER_leDataUtil(dia, 31, "dia");
			LER_leDataUtil(mes, 12, "mes");
			

			if ( * dia > maxDias [* mes - 1])
			{
				printf ("\n   Dia invalido para o mes informado. Digite o dia e o mes novamente.\n") ;
			}

		} while ( * dia > maxDias [* mes - 1] ) ;
		
		//ANO
		do 
		{
			printf("\n\tAno: ") ;
			LER_leInteiro(ano, 4, 4, LER_comparaLeSoNumero);
		
			if ( * ano < LER_MIN_ANO )
			{
				printf ("\n   Ano invalido. Digite o ano novamente.") ;
			}

		} while ( * ano < LER_MIN_ANO ) ;

		printf("\n") ;

	}
