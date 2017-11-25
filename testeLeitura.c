#include <stdio.h>
#include "leitura.h"

int  main(void){
	int a;
	/*
		Esse +1 é MUITO IMPORTANTE, ele representa o '\0' no final do texto.
		Eu fiquei pensando em onde colocar um +1 ou -1, achei que o melhor lugar era aqui, pois só precisariamos escrever uma vez.
		A outra opção era colocar tirar daqui e colocar -1 em todos os outros, acho essa opção pior.
		A terceira é mudar as funções para que não incluam o max. O min, max seria fechado em min e aberto em max. Mas eu achei que isso poderia gerar confusão. Além disso num valor estrito como cpf (exatamente 11 digitos), o tamanho teria que ter um -1 ou +1 em um dos dois, então não da para fugir.
		Do jeito que esta o maximo de erro que acontece é alguem esquecer do +1 e quando o usuario digitar 80 caracteres o '\0', vai extrapolar a string, isso deve acontecer dentro da função. A chance de quebrar o programa é bem pequena.
		Mas principalmente, a falta desse +1 é facil de achar, e a gente sabe onde procurar.. Em toda criação de variáveis usadas por funções do modulo LER. 

	*/
	char b[LER_TAM_STRING+1];
	
	/*
		Agora basta colocar os defines com os tamanhos certos para cada coisa
		Note que ainda é possivel colocar essas coisas dentro de funções para prevenir que cada um leia cpf de um jeito
	*/
	int dia, mes, ano;
	char uf[LER_TAM_UF];
	
	//le data
	LER_leData ( &dia, &mes, &ano );
	printf("O que voce digitou: %d/%d/%d\n", dia, mes, ano);

	//le uf
	printf("Digite o UF\n");
	LER_leUF ( uf );
	printf("O que voce digitou: %s\n", uf);

	//Le so letra 
	printf("\nFale sobre voce:\n");
	LER_leString(b, 0, LER_TAM_STRING, LER_comparaLeSoLetra, 0);
	printf("O que voce digitou: %s\n", b);

	//Le so letra
	printf("\nGrite sobre voce:\n");
	LER_leString(b, 0, LER_TAM_STRING, LER_comparaLeSoLetra, 1);
	printf("O que voce digitou: %s\n", b);

	//Le so letra
	printf("\nSussurre sobre voce:\n");
	LER_leString(b, 0, LER_TAM_STRING, LER_comparaLeSoLetra, -1);
	printf("O que voce digitou: %s\n", b);

	//le matricula
	printf("\nDigite a matricula:\n");
	LER_leInteiro(&a, LER_TAM_MAT, LER_TAM_MAT, LER_comparaLeSoNumero);
	printf("O que voce digitou: %d\n", a);

	// le cpf
	printf("\nDigite o CPF:\n");
	LER_leString(b, LER_TAM_CPF, LER_TAM_CPF, LER_comparaLeSoNumero, 0);
	printf("O que voce digitou: %s\n", b);

	// le logradouro
	printf("\nDigite o logradouro:\n");
	LER_leString(b, 0, LER_TAM_STRING, LER_comparaLeLogradouro, 0);
	printf("O que voce digitou: %s\n", b);

	// le complemento
	printf("\nDigite o complemento:\n");
	LER_leString(b, 0, LER_TAM_STRING, LER_comparaLeComplemento, 0);
	printf("O que voce digitou: %s\n", b);

	// le email
	printf("\nDigite o email:\n");
	LER_leString(b, 5, 20, LER_comparaLeEmail, 0);
	printf("O que voce digitou: %s\n", b);

	//le telefone
	printf("\nDigite o telefone:\n");
	LER_leInteiro(&a, LER_MIN_TEL, LER_MAX_TEL, LER_comparaLeSoNumero);
	printf("O que voce digitou: %d\n", a);

	//le rg
	printf("\nDigite RG:\n");
	LER_leInteiro(&a, LER_TAM_RG, LER_TAM_RG, LER_comparaLeSoNumero);
	printf("O que voce digitou: %d\n", a);

	return 0;
}
