#ifndef LER_H
#define LER_H

#define LER_MIN_ANO 1850
#define LER_TAM_STRING 80
#define LER_TAM_UF 2
#define LER_TAM_CPF 11
#define LER_TAM_MAT 8
#define LER_MIN_TEL 8
#define LER_MAX_TEL 9
#define LER_QTD_EST 27
#define LER_TAM_RG 9

/* TODO isso nao vai ficar aqui, é só por enquanto*/
#ifdef __linux__
	#define VK_ENTER 10
	#define VK_BACKSPACE 127
#else
	#define VK_ENTER 13
	#define VK_BACKSPACE 8
#endif


	typedef int (*LER_Compara)(unsigned char) ;

	void LER_leString ( char * leValor, int min, int max, LER_Compara compara, int converte ) ;

	void LER_leInteiro( int * leValor,int min, int max, LER_Compara compara) ;

	void LER_leUF ( char * UF ) ;

	void LER_leData ( int * dia, int * mes, int * ano );

	int LER_comparaLeSoLetra ( unsigned char a ) ;

	int LER_comparaLeSoNumero ( unsigned char a ) ;

	int LER_comparaLeLogradouro ( unsigned char a ) ;

	int LER_comparaLeComplemento ( unsigned char a ) ;

	int LER_comparaLeEmail ( unsigned char a ) ;

#endif
