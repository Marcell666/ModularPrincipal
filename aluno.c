#include "aluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
/*Início da Struct encapsulada Aluno*/
struct aluno {
	char nome[81];
	unsigned int mat;
	CPF cpfA;
	unsigned int telefone;
	Data nasc;
	Endereco end;
};
/*Fim da struct*/

int ValidaData(Data* data);	// Cabeçalho da função interna que valida data.

/*Início da função ALU_CriaAluno*/							
ALN_tpCondRet ALU_CriaAluno(Aluno **a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end) {

	*a = (Aluno*)malloc(sizeof(Aluno));	// Alocando espaço na memória para um Aluno
										//*a = b;	// Usando outro ponteiro para me referenciar ao aluno, para facilitar leitura
										// e não ter que usar (*a)->atributo.
	if (a == NULL)
		return ALN_CondRetFaltouMemoria;	// Faltou memória ao alocar aluno.

	strcpy((*a)->nome, nome);	// Atribuo todas as informações ao aluno.
	(*a)->mat = mat;
	(*a)->cpfA.dig1 = cpf->dig1;
	(*a)->cpfA.dig2 = cpf->dig2;
	(*a)->cpfA.dig3 = cpf->dig3;
	(*a)->cpfA.cod = cpf->cod;
	(*a)->telefone = telefone;
	if (ValidaData(nasc)) {
		(*a)->nasc.dia = nasc->dia;
		(*a)->nasc.mes = nasc->mes;
		(*a)->nasc.ano = nasc->ano;
	}
	else {
		printf("\nData de nascimento fornecida invalida.\n\n");	// Caso a data seja inválida, informo ao usuário.
		(*a)->nasc.dia = 0;
		(*a)->nasc.mes = 0;
		(*a)->nasc.ano = 0;
	}
	strcpy((*a)->end.bairro, end->bairro);	// Atribuo os dados de endereço.
	strcpy((*a)->end.cidade, end->cidade);
	strcpy((*a)->end.comp, end->comp);
	strcpy((*a)->end.estado, end->estado);
	strcpy((*a)->end.rua, end->rua);

	return ALN_CondRetOK;	// Retorno que tudo deu certo.
}
/*Fim da função*/

/*Início da função ALU_deletaAluno*/
/*Recebe um ponteiro para aluno e desaloca o espaço de memória apontado pelo mesmo*/
ALN_tpCondRet ALU_deletaAluno(Aluno** a) {
	if (*a != NULL)						// Caso o ponteiro não seja nulo
	{
		free(*a);						// Libero a área de memória alocada
		return ALN_CondRetOK;			// Retorno que tudo deu certo
	}
	return ALN_CondRetAlunoNaoExiste;	// Caso contrário, retorno que o aluno não existe
}
/*Fim da função*/

/*Início da função ALU_GetMat*/
/*Recebe um ponteiro para aluno e outro para um inteiro e retorna a matrícula do aluno pelo ponteiro para inteiro.*/
ALN_tpCondRet ALU_GetMat(Aluno *a, unsigned int *mat) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;	// Caso o ponteiro seja nulo, retorno que o aluno não existe.

	*mat = a->mat;							// Copio o conteúdo da struct para a variável matricula
	return ALN_CondRetOK;					// Retorno que tudo deu certo
}
/*Fim da função*/

/*Início da função ALU_GetNome*/
/*Recebe um ponteiro para aluno e outro para um char e retorna o nome do aluno pelo ponteiro para char.*/
ALN_tpCondRet ALU_GetNome(Aluno *a, char* nome) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;	// Caso o ponteiro seja nulo, retorno que o aluno não existe.
	strcpy(nome, a->nome);					// Copio o conteúdo da struct e coloco na variável
	return ALN_CondRetOK;					// Retorno que tudo deu certo
}
/*Fim da função*/

/*Início da função ALU_AlteraDados*/
// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
ALN_tpCondRet ALU_AlteraDados(Aluno *a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end) {

	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;		// Caso o ponteiro seja nulo, retorno que o aluno não existe.

	if (nome)
		strcpy(a->nome, nome);			// Se o nome não for nulo, sobrescrevo o nome atual.
	if (mat)
		a->mat = mat;					// Se a matricula não for 0, sobrescrevo a matricula atual.
	if (cpf)						
	{
		a->cpfA.dig1 = cpf->dig1;		// Se o CPF não for nulo, sobrescrevo o CPF atual.
		a->cpfA.dig2 = cpf->dig2;
		a->cpfA.dig3 = cpf->dig3;
		a->cpfA.cod = cpf->cod;
	}
	if (telefone)
		a->telefone = telefone;			// Se o telefone não for 0, sobrescrevo o telefone atual.
	if (nasc && ValidaData(nasc)) {
		a->nasc.ano = nasc->ano;		// Se a data não for nulo e for válida, sobrescrevo a data atual.
		a->nasc.mes = nasc->mes;
		a->nasc.dia = nasc->dia;
	}
	if (end) {
		strcpy(a->end.estado, end->estado);		// Se o endereço não for nulo, sobrescrevo o endereço atual.
		strcpy(a->end.cidade, end->cidade);
		strcpy(a->end.bairro, end->bairro);
		strcpy(a->end.rua, end->rua);
		strcpy(a->end.comp, end->comp);
	}
	return ALN_CondRetOK;
}
/*Fim da função*/

/*Início da função ALU_GetAll*/
// Função que copia os dados do aluno
ALN_tpCondRet ALU_GetAll(Aluno *a, char *nome, unsigned int *mat, CPF *cpf, unsigned int *tel, Data *nasc, Endereco *endereco) {

	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;		// Caso o ponteiro seja nulo, retorno que o aluno não existe.
	strcpy(nome, a->nome);						// Copio todos os dados do aluno para as suas respectivas variáveis.
	*mat = a->mat;
	(cpf)->dig1 = a->cpfA.dig1;
	(cpf)->dig2 = a->cpfA.dig2;
	(cpf)->dig3 = a->cpfA.dig3;
	(cpf)->cod = a->cpfA.cod;
	*tel = a->telefone;
	nasc->ano = a->nasc.ano;
	nasc->dia = a->nasc.dia;
	nasc->mes = a->nasc.mes;
	strcpy(endereco->estado, a->end.estado);
	strcpy(endereco->cidade, a->end.cidade);
	strcpy(endereco->bairro, a->end.bairro);
	strcpy(endereco->rua, a->end.rua);
	strcpy(endereco->comp, a->end.comp);

	return ALN_CondRetOK;
}
/*Fim da função*/

/*Início da função ALU_imprimeAluno*/
// Função recebe um ponteiro pra aluno e imprime todos os seus dados
ALN_tpCondRet ALU_imprimeAluno(Aluno *a) {
	if (a == NULL)
		return ALN_CondRetAlunoNaoExiste;			// Caso o ponteiro seja nulo, retorno que o aluno não existe.
	printf("Nome: %s\n", a->nome);					// Imprimo todos os dados do aluno.
	printf("Matricula: %d\n", a->mat);
	printf("CPF:  %03d.%03d.%03d-%02d\n", a->cpfA.dig1, a->cpfA.dig2, a->cpfA.dig3, a->cpfA.cod);
	printf("Telefone: %d\n", a->telefone);
	printf("Data de Nascimento: %02d/%02d/%d\n", a->nasc.dia, a->nasc.mes, a->nasc.ano);
	printf("Endereco: %s, %s, %s, %s - %s\n", a->end.rua, a->end.comp, a->end.bairro, a->end.cidade, a->end.estado);
	return ALN_CondRetOK;
}
/*Fim da função*/

/*Início da função interna ValidaData*/
/*
Considera a data atual do sistema como data limite.
Retorna 1 se a data for válida e 0 caso contrário.
Valida verificando o número de dias por mês, p. ex. O dia 31 de setembro não é válido. */
int ValidaData(Data* data) {

	time_t t = time(NULL);
	struct tm *time = localtime(&t);	// Pego a data atual do computador para comparar
	char meses31[7] = { 1,3,5,7,8,10,12 };	// Meses com 31 dias
	char meses30[4] = { 4,6,9,11 };	// Meses com 30 dias
	int i;	// iterador

			// Um aluno não pode ter mais de 120 anos, nem menos de 15 anos.

	if ((data->ano >= ((time->tm_year + 1900) - 120) && data->ano <= ((time->tm_year + 1900) - 15)) && data->ano <= (time->tm_year + 1900))
	{
		if (data->ano == (time->tm_year + 1900))	// verifico se o ano fornecido é o ano atual.
		{
			if (data->mes == (time->tm_mon + 1)){	// verifico se o mes fornecido é o mês atual.
				if (data->dia <= time->tm_mday)		// verifico se o dia fornecido é menor ou igual que o dia atual.
					return 1;					// Data válida.
				else
					return 0;					// Data inválida.
			}
		}
		for (i = 0; i < 7; i++) {
			if (data->mes == meses31[i])	// verifico se o mes fornecido possui 31 dias.
				if (data->dia <= 31)	// verifico se o dia fornecido é menor ou igual a 31.
					return 1;			// Data válida.
		}
		for (i = 0; i < 4; i++) {
			if (data->mes == meses30[i])	// verifico se o mes fornecido possui 30 dias.
				if (data->dia <= 30)	// verifico se o dia fornecido é menor ou igual a 30.
					return 1;			// Data válida.
		}
		if (data->mes == 2)		// verifico se o mes fornecido é fevereiro.
			if (data->dia <= 28)	// verifico se o dia fornecido é menor ou igual a 28.
				return 1;			// Data válida.
	}
	return 0;		// Neste caso, a data é inválida.
}
/*Fim da função*/
