#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "corpodiscente.h"


//bibliotecas para criação de pastas
#ifdef __linux__
	#include <sys/stat.h>
	#include <sys/types.h>
	#include <fcntl.h>
#else
	#include <direct.h>
#endif


struct corpodisc {
	List* Aluno;
}typedef CorpoDisc;

static CorpoDisc *Corpo;


/*Inicio da função CDI_cria*/
/* Recebe um ponteiro para CorpoDisc e aloca memória para uma lista de alunos,
onde serão inseridos os alunos, através das outras funções. */
CDI_tpCondRet CDI_cria(void) {

	// Aloco espaço para o corpo discente.
	Corpo = (CorpoDisc*)malloc(sizeof(CorpoDisc));
	// Se a lista não for criada com sucesso, retorno falha de memória.
	if (createList(&Corpo->Aluno) != LIS_CondRetOK) {
		return CDI_CondRetFaltouMemoria;
	}
	// Se tudo deu certo, retorno OK.
	return CDI_CondRetOK;

}
/*Fim da função CDI_cria*/

/*Inicio da função CDI_insere*/
/*Função que recebe um vetor de ponteiros para aluno a ser inserido, o nome do aluno, sua matricula,seu cpf, seu telefone, sua data de nascimento, seu endereço e um ponteiro para uma estrutura Corpo Discente*/
CDI_tpCondRet CDI_insere(char *nome, unsigned int mat, struct cpf *cpf, unsigned int telefone, struct data *nasc, struct endereco* end)
{
	Aluno *a = NULL;
	CDI_busca(mat, &a);
	if (a != NULL)	// Se o aluno com esta matricula ja estiver cadastrado
		return CDI_CondRetAlunoJaCadastrado;
	ALU_CriaAluno(&a, nome, mat, cpf, telefone, nasc, end); // senão eu crio esse aluno
	if (a == NULL)	// verificando questão de memória
		return CDI_CondRetFaltouMemoria;
	else {
		push_back(Corpo->Aluno, (void *)a);	// insiro no fim do corpo discente
		return CDI_CondRetOK;
	}
}
/*Fim da função CDI_insere*/

/*Início da função CDI_busca*/
/*Função INTERNA que recebe um ponteiro para CorpoDisc e procura a matrícula fornecida por referência em matbusca na lista de alunos e caso encontre o aluno
desejado retorna seus dados em alunodesejado que é um ponteiro para Aluno passado por referência.Caso não encontre,retorna a condição
de erro de aluno não encontrado.*/
CDI_tpCondRet CDI_busca(unsigned int matbusca, Aluno** alu) {
	unsigned int mat2=0, i=0, size = 0;
	Aluno *a = NULL;
	list_size(Corpo->Aluno, &size);	// Pego o tamanho da lista
	first(Corpo->Aluno);	// Seto a lista para o primeiro nó
	for (i = 0;i < size; i++) {
		get_val_cursor(Corpo->Aluno, (void**)&a);	// Pego o aluno atual
		ALU_GetMat(a, &mat2);	// Pego sua matrícula
		if (matbusca == mat2) {	// Vejo se a matrícula é igual à de busca
			*alu = a;
			return CDI_CondRetOK;	// se for, retorno ele.
		}
		next(Corpo->Aluno); // caso não seja, vou para o próximo
	}
	return CDI_CondRetAlunoNaoCadastrado;	// Não encontrei
}
/*Fim da função CDI_busca*/

/*Início da função CDI_altera*/
/*Função que altera os dados de um aluno do corpo docente.*/
CDI_tpCondRet CDI_altera(int matbusca, char *nome, unsigned int mat, struct cpf *cpf, unsigned int telefone, struct data *nasc, struct endereco *end) {
	Aluno *alndesejado = NULL;

	CDI_busca(matbusca, &alndesejado);	// busco o aluno no corpo discente

	if (alndesejado == NULL)	// se não encontrei
		return CDI_CondRetAlunoNaoCadastrado;	// aluno não está cadastrado.

	ALU_AlteraDados(alndesejado, nome, mat, cpf, telefone, nasc, end); // altero os dados, através da função de alterar dado do módulo aluno.
	return CDI_CondRetOK;	// Tudo deu certo.

}
/*Fim da função CDI_altera*/

/*Início da função CDI_remove*/
/*Função que recebe como parâmetros a matrícula do aluno a ser removido, o ponteiro para a estrutura Corpo Discente e remove da Lista do Corpo Discente o Aluno com matrícula igual a recebida*/
CDI_tpCondRet CDI_remove(unsigned int matbusca) {
	Aluno *alndesejado = NULL;
	CDI_busca(matbusca, &alndesejado);	// Pego o ponteiro pro aluno, cuja matricula é matbusca
	if (alndesejado == NULL)
		return CDI_CondRetAlunoNaoCadastrado;
	else {
		pop_cursor(Corpo->Aluno, (void**)&alndesejado);//Remove da lista o elemento apontado pelo cursor
		return CDI_CondRetOK;
	}
}
/*Fim da função CDI_remove*/

/*Início da função CDI_imprime*/
/*Função que recebe como parâmetro o ponteiro para a estrutura Corpo Discente e imprime na tela todos os seus elementos*/
CDI_tpCondRet CDI_imprime(void) {
	unsigned int i, size = 0;
	Aluno *a;
	list_size(Corpo->Aluno, &size);	// Pego o tamanho da lista
	if (size == 0) {	// Se a lista estiver vazia
		printf("Nao ha alunos cadastrados no Corpo Discente.\n");
		return CDI_CondRetCDIVazio;
	}
	first(Corpo->Aluno);
	for (i = 0; i < size; i++) {
		get_val_cursor(Corpo->Aluno, (void**) &a); // pego o aluno atual
		ALU_imprimeAluno(a);	// imprimo
		next(Corpo->Aluno);	// vou para o próximo
		printf("\n");	// Imprimo uma nova linha para dividir um aluno de outro
	}
	return CDI_CondRetOK;
}
/*Fim da função CDI_imprime*/

/*Início da função CDI_deleta*/
/*Função que limpa a lista e libera o Corpo Discente. (Este deixa de existir)*/
CDI_tpCondRet CDI_deleta(void) {
	clear(Corpo->Aluno);	// limpo o corpo discente
	free(Corpo);	// libero o corpo discente
	return CDI_CondRetOK;
}
/*Fim da função CDI_deleta*/

/*Início da função CDI_limpa*/
/*Função que limpa a lista e libera o Corpo Discente.
(Este continua existindo, permitido novas inserções*/
CDI_tpCondRet CDI_limpa(void) {
	unsigned int size;
	list_size(Corpo->Aluno,&size);
	if (size == 0)
		return CDI_CondRetCDIVazio;
	clear(Corpo->Aluno);	// limpo o corpo discente
	return CDI_CondRetOK;
}
/*Fim da função CDI_limpa*/

/*Início da função CDI_imprimeInfo*/
/*Função que imprime a informação de um aluno, dada sua matrícula*/
CDI_tpCondRet CDI_imprimeInfo(unsigned int matbusca) {
	Aluno *a;
	CDI_tpCondRet retBuscaCDI;

	retBuscaCDI = CDI_busca(matbusca,&a);	// Busco o aluno
	if (retBuscaCDI != CDI_CondRetOK)
		return CDI_CondRetAlunoNaoCadastrado;
	ALU_imprimeAluno(a);	// imprimo os seus dados.
	return CDI_CondRetOK;
}
/*Fim da função CDI_imprimeInfo*/


 /***************************************************************************
 *
 *  Função: CDI Salva Dados
 *  ****/

	CDI_tpCondRet CDI_salvaDados( char * path )
	{

		Aluno * alu = NULL ;

		FILE * f ;
		char pathComPasta[ALN_TAM_STRING] ;

		//colocando pasta no inicio do path
		#ifdef __linux__
			strcpy(pathComPasta,"Dados/");
		#else
			strcpy(pathComPasta,"Dados\\") ;
		#endif

		strcat(pathComPasta, path) ;

		#ifdef _DEBUG_	
			printf("PATH: %s\n", pathComPasta) ;
		#endif

		f = fopen(pathComPasta,"wt") ;

		if ( !f )
		{
			#ifdef _DEBUG_	
				printf( "Erro ao salvar arquivo de dados pessoais dos professores no módulo Corpo Docente. %s\n", pathComPasta ) ;
			#endif
			return CDI_CondRetErroAbrirArquivo ;
		} /* if */

		first( Corpo->Aluno ) ;
		do
		{
			if( get_val_cursor(Corpo->Aluno, (void**) &alu) == LIS_CondRetListaVazia )
			{
				fclose(f) ;
				return CDI_CondRetCDIVazio ;
			}
			ALN_salvaDados(alu, f);
		} while( next(Corpo->Aluno)==LIS_CondRetOK ) ;
		
		fclose(f) ;

		return CDI_CondRetOK ;

	}  /* Fim função: CDO Salva Dados */

 /***************************************************************************
 *
 *  Função: CDO Le Dados
 *  ****/

	CDI_tpCondRet CDI_leDados ( char * path )
	{

		int rg ;
		unsigned int matricula, telefone ;
		Data nasc ;
		CPF cpf; 
		char nome[ALN_TAM_STRING] ;
		Endereco end ; 
		CDI_tpCondRet ret ;
		FILE * f ;
				
		char pathComPasta[ALN_TAM_STRING] ;

		//colcocando pasta no inicio do path
		#ifdef __linux__
			strcpy( pathComPasta,"Dados/" ) ;
		#else
			strcpy( pathComPasta,"Dados\\" ) ;
		#endif

		strcat( pathComPasta, path ) ;

		#ifdef _DEBUG_	
			printf( "PATH: %s\n", pathComPasta ) ;
		#endif

		//abrindo arquivo
		f = fopen( pathComPasta, "rt" ) ;

		if ( !f )
		{
			#ifdef _DEBUG_	
				printf("Erro ao abrir arquivo de dados pessoais dos alunos no módulo Corpo Dicente.\n PATH: %s\n", pathComPasta) ;
			#endif
			//nao deu para abrir, criar pasta
			/*
				Não deve existir a possibilidade de abrir a pasta e não ter nenhum arquivo dentro dela.
				Se não existe pasta, é a primeira vez que o o programa funciona, e portanto não tem arquivos.
				Se existe pasta, já não é a primeira vez e tem algum arquivo la dentro, mesmoq ue esteja vazio.
				A não ser que o usuário delete os arquivos da pasta manualmente, mas então, por isso eu não mes responsabilizo. Afinal estamos possibilitando que ele remova os dados atraves do proprio programa, o que não causa erros.
			*/
			#ifdef __linux__
				mkdir( "Dados",0666 ) ;
			#else
				_mkdir( "Dados" ) ;
			#endif
			return CDI_CondRetOK ;
		} /* if */
	
		while( fscanf(f, "\'%[^\']\' %d %d %d %d %u %u %d %d %d %s \'%[^\']\' \'%[^\']\' \'%[^\']\' %d \'%[^\']\'\n",
						nome, &cpf.dig1, &cpf.dig2, &cpf.dig3, &cpf.cod, &matricula, &telefone, &nasc.dia,
						&nasc.mes, &nasc.ano, &end.estado, &end.cidade, &end.bairro, &end.comp, &end.numero, &end.rua )>0 )
		{
			#ifdef _DEBUG_
				printf( "%s %d.%d.%d-%d %u %u %d %d %d %s %s %s %s %d %s \n",
					nome, cpf.dig1, cpf.dig2, cpf.dig3, cpf.cod, matricula, telefone, nasc.dia,
					nasc.mes, nasc.ano, end.estado, end.cidade, end.bairro, end.comp, end.numero, end.rua ) ;
			#endif

			ret = CDI_insere( nome, matricula, &cpf, telefone, &nasc, &end ) ;
			
			if(ret != CDI_CondRetOK)
			{
				#ifdef _DEBUG_
					printf("Erro ao cadastrar Professor\n") ;
				#endif
			}
		} /* while */

		fclose(f) ;

		return ret ;

	} /* Fim função: CDO Le Dados */

