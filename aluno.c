#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
//#include <time.h>

/*In�cio da Struct encapsulada Aluno*/
struct aluno {
	char nome[ALN_TAM_STRING];
	unsigned int mat;
	CPF cpfA;
	unsigned int telefone;
	Data nasc;
	Endereco end;
};
/*Fim da struct*/

	//int ValidaData(Data* data);	// Cabe�alho da fun��o interna que valida data.

/*In�cio da fun��o ALU_CriaAluno*/							
	ALN_tpCondRet ALU_CriaAluno(Aluno **a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end)
	{

		*a = (Aluno*)malloc(sizeof(Aluno));	// Alocando espa�o na mem�ria para um Aluno
											//*a = b;	// Usando outro ponteiro para me referenciar ao aluno, para facilitar leitura
											// e n�o ter que usar (*a)->atributo.
		if (a == NULL)
			return ALN_CondRetFaltouMemoria;	// Faltou mem�ria ao alocar aluno.

		strcpy((*a)->nome, nome);	// Atribuo todas as informa��es ao aluno.
		(*a)->mat = mat;
		(*a)->cpfA.dig1 = cpf->dig1;
		(*a)->cpfA.dig2 = cpf->dig2;
		(*a)->cpfA.dig3 = cpf->dig3;
		(*a)->cpfA.cod = cpf->cod;
		(*a)->telefone = telefone;

		(*a)->nasc.dia = nasc->dia;
		(*a)->nasc.mes = nasc->mes;
		(*a)->nasc.ano = nasc->ano;

		strcpy((*a)->end.bairro, end->bairro);	// Atribuo os dados de endere�o.
		strcpy((*a)->end.cidade, end->cidade);
		strcpy((*a)->end.comp, end->comp);
		strcpy((*a)->end.estado, end->estado);
		strcpy((*a)->end.rua, end->rua);
		(*a)->end.numero = end->numero;

		return ALN_CondRetOK;	// Retorno que tudo deu certo.
	}
/*Fim da fun��o*/

/*In�cio da fun��o ALU_deletaAluno*/
/*Recebe um ponteiro para aluno e desaloca o espa�o de mem�ria apontado pelo mesmo*/
	ALN_tpCondRet ALU_deletaAluno(Aluno** a) 
	{
		if (*a != NULL)						// Caso o ponteiro n�o seja nulo
		{
			free(*a);						// Libero a �rea de mem�ria alocada
			return ALN_CondRetOK;			// Retorno que tudo deu certo
		}
		return ALN_CondRetAlunoNaoExiste;	// Caso contr�rio, retorno que o aluno n�o existe
	}
/*Fim da fun��o*/

/*In�cio da fun��o ALU_GetMat*/
/*Recebe um ponteiro para aluno e outro para um inteiro e retorna a matr�cula do aluno pelo ponteiro para inteiro.*/
	ALN_tpCondRet ALU_GetMat(Aluno *a, unsigned int *mat) 
	{
		if (a == NULL)
			return ALN_CondRetAlunoNaoExiste;	// Caso o ponteiro seja nulo, retorno que o aluno n�o existe.

		*mat = a->mat;							// Copio o conte�do da struct para a vari�vel matricula
		return ALN_CondRetOK;					// Retorno que tudo deu certo
	}
/*Fim da fun��o*/

/*In�cio da fun��o ALU_GetNome*/
/*Recebe um ponteiro para aluno e outro para um char e retorna o nome do aluno pelo ponteiro para char.*/
	ALN_tpCondRet ALU_GetNome(Aluno *a, char* nome)
	{
		if (a == NULL)
			return ALN_CondRetAlunoNaoExiste;	// Caso o ponteiro seja nulo, retorno que o aluno n�o existe.
		strcpy(nome, a->nome);					// Copio o conte�do da struct e coloco na vari�vel
		return ALN_CondRetOK;					// Retorno que tudo deu certo
	}
/*Fim da fun��o*/

/*In�cio da fun��o ALU_AlteraDados*/
// Altera os dados de um aluno, caso eles sejam diferente de NULL / 0 (Zero).
	ALN_tpCondRet ALU_AlteraDados(Aluno *a, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end)
	{

		if (a == NULL)
			return ALN_CondRetAlunoNaoExiste;		// Caso o ponteiro seja nulo, retorno que o aluno n�o existe.

		if (nome)
			strcpy(a->nome, nome);			// Se o nome n�o for nulo, sobrescrevo o nome atual.
		if (mat)
			a->mat = mat;					// Se a matricula n�o for 0, sobrescrevo a matricula atual.
		if (cpf)						
		{
			a->cpfA.dig1 = cpf->dig1;		// Se o CPF n�o for nulo, sobrescrevo o CPF atual.
			a->cpfA.dig2 = cpf->dig2;
			a->cpfA.dig3 = cpf->dig3;
			a->cpfA.cod = cpf->cod;
		}
		if (telefone)
			a->telefone = telefone;			// Se o telefone n�o for 0, sobrescrevo o telefone atual.
		if (nasc) {
			a->nasc.ano = nasc->ano;		// Se a data n�o for nulo e for v�lida, sobrescrevo a data atual.
			a->nasc.mes = nasc->mes;
			a->nasc.dia = nasc->dia;
		}
		if (end) {
			strcpy(a->end.estado, end->estado);		// Se o endere�o n�o for nulo, sobrescrevo o endere�o atual.
			strcpy(a->end.cidade, end->cidade);
			strcpy(a->end.bairro, end->bairro);
			strcpy(a->end.rua, end->rua);
			a->end.numero = end->numero;
			strcpy(a->end.comp, end->comp);
		}
		return ALN_CondRetOK;
	}
/*Fim da fun��o*/

/*In�cio da fun��o ALU_GetAll*/
// Fun��o que copia os dados do aluno
	ALN_tpCondRet ALU_GetAll(Aluno *a, char *nome, unsigned int *mat, CPF *cpf, unsigned int *tel, Data *nasc, Endereco *endereco) 
	{

		if (a == NULL)
			return ALN_CondRetAlunoNaoExiste;		// Caso o ponteiro seja nulo, retorno que o aluno n�o existe.
		strcpy(nome, a->nome);						// Copio todos os dados do aluno para as suas respectivas vari�veis.
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
		endereco->numero = a->end.numero;

		return ALN_CondRetOK;
	}
/*Fim da fun��o*/

/*In�cio da fun��o ALU_imprimeAluno*/
// Fun��o recebe um ponteiro pra aluno e imprime todos os seus dados
	ALN_tpCondRet ALU_imprimeAluno(Aluno *a)
	{
		if (a == NULL)
			return ALN_CondRetAlunoNaoExiste;			// Caso o ponteiro seja nulo, retorno que o aluno n�o existe.
		printf("Nome: %s\n", a->nome);					// Imprimo todos os dados do aluno.
		printf("Matricula: %u\n", a->mat);
		printf("CPF:  %03d.%03d.%03d-%02d\n", a->cpfA.dig1, a->cpfA.dig2, a->cpfA.dig3, a->cpfA.cod);
		printf("Telefone: %u\n", a->telefone);
		printf("Data de Nascimento: %02d/%02d/%d\n", a->nasc.dia, a->nasc.mes, a->nasc.ano);
		printf("Endereco: %s, %d, %s, %s, %s - %s\n", a->end.rua, a->end.numero, a->end.comp, a->end.bairro, a->end.cidade, a->end.estado);
		return ALN_CondRetOK;
	}
/*Fim da fun��o*/

/*In�cio da fun��o interna ValidaData*/
/*
Considera a data atual do sistema como data limite.
Retorna 1 se a data for v�lida e 0 caso contr�rio.
Valida verificando o n�mero de dias por m�s, p. ex. O dia 31 de setembro n�o � v�lido. */
/*
	int ValidaData(Data* data) 
	{

		time_t t = time(NULL);
		struct tm *time = localtime(&t);	// Pego a data atual do computador para comparar
		char meses31[7] = { 1,3,5,7,8,10,12 };	// Meses com 31 dias
		char meses30[4] = { 4,6,9,11 };	// Meses com 30 dias
		int i;	// iterador

				// Um aluno n�o pode ter mais de 120 anos, nem menos de 15 anos.

		if ((data->ano >= ((time->tm_year + 1900) - 120) && data->ano <= ((time->tm_year + 1900) - 15)) && data->ano <= (time->tm_year + 1900))
		{
			if (data->ano == (time->tm_year + 1900))	// verifico se o ano fornecido � o ano atual.
			{
				if (data->mes == (time->tm_mon + 1)){	// verifico se o mes fornecido � o m�s atual.
					if (data->dia <= time->tm_mday)		// verifico se o dia fornecido � menor ou igual que o dia atual.
						return 1;					// Data v�lida.
					else
						return 0;					// Data inv�lida.
				}
			}
			for (i = 0; i < 7; i++) {
				if (data->mes == meses31[i])	// verifico se o mes fornecido possui 31 dias.
					if (data->dia <= 31)	// verifico se o dia fornecido � menor ou igual a 31.
						return 1;			// Data v�lida.
			}
			for (i = 0; i < 4; i++) {
				if (data->mes == meses30[i])	// verifico se o mes fornecido possui 30 dias.
					if (data->dia <= 30)	// verifico se o dia fornecido � menor ou igual a 30.
						return 1;			// Data v�lida.
			}
			if (data->mes == 2)		// verifico se o mes fornecido � fevereiro.
				if (data->dia <= 28)	// verifico se o dia fornecido � menor ou igual a 28.
					return 1;			// Data v�lida.
		}
		return 0;		// Neste caso, a data � inv�lida.
	}
*/
/*Fim da fun��o*/


/***************************************************************************
*
*  Fun��o: PRF Salva Dados
*  ****/
 
	ALN_tpCondRet ALN_salvaDados ( Aluno * alu, FILE *f )
	{
			if ( !f )
			{
				#ifdef _DEBUG	
					printf("Erro ao abrir arquivo de dados pessoais dos alunos.\n") ;
				#endif
				return ALN_CondRetErroAbrirArquivo ;
			} /* if */

			fprintf(f,
					"\'%s\' %d %d %d %d %u %u %d %d %d %s \'%s\' \'%s\' \'%s\' %d \'%s\' \n",

				alu->nome,
				alu->cpfA.dig1,
				alu->cpfA.dig2,
				alu->cpfA.dig3,
				alu->cpfA.cod,
				alu->mat,
				alu->telefone,

				alu->nasc.dia,
				alu->nasc.mes,
				alu->nasc.ano,

				alu->end.estado,
				alu->end.cidade,
				alu->end.bairro,
				alu->end.comp,
				alu->end.numero,
				alu->end.rua
			) ;

			#ifdef _DEBUG	
				printf( "Dados do aluno de matricula %d salvos com sucesso!\n", alu->mat ) ;
			#endif

			return ALN_CondRetOK ;

	} /* Fim fun��o: PRF Salva Dados */
