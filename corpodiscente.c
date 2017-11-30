#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listas.h"
#include "corpodiscente.h"


//bibliotecas para cria��o de pastas
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


/*Inicio da fun��o CDI_cria*/
/* Recebe um ponteiro para CorpoDisc e aloca mem�ria para uma lista de alunos,
onde ser�o inseridos os alunos, atrav�s das outras fun��es. */
CDI_tpCondRet CDI_cria(void) {

	// Aloco espa�o para o corpo discente.
	Corpo = (CorpoDisc*)malloc(sizeof(CorpoDisc));
	// Se a lista n�o for criada com sucesso, retorno falha de mem�ria.
	if (createList(&Corpo->Aluno) != LIS_CondRetOK) {
		return CDI_CondRetFaltouMemoria;
	}
	// Se tudo deu certo, retorno OK.
	return CDI_CondRetOK;

}
/*Fim da fun��o CDI_cria*/

/*Inicio da fun��o CDI_insere*/
/*Fun��o que recebe um vetor de ponteiros para aluno a ser inserido, o nome do aluno, sua matricula,seu cpf, seu telefone, sua data de nascimento, seu endere�o e um ponteiro para uma estrutura Corpo Discente*/
CDI_tpCondRet CDI_insere(char *nome, unsigned int mat, struct cpf *cpf, unsigned int telefone, struct data *nasc, struct endereco* end)
{
	Aluno *a = NULL;
	CDI_busca(mat, &a);
	if (a != NULL)	// Se o aluno com esta matricula ja estiver cadastrado
		return CDI_CondRetAlunoJaCadastrado;
	ALU_CriaAluno(&a, nome, mat, cpf, telefone, nasc, end); // sen�o eu crio esse aluno
	if (a == NULL)	// verificando quest�o de mem�ria
		return CDI_CondRetFaltouMemoria;
	else {
		push_back(Corpo->Aluno, (void *)a);	// insiro no fim do corpo discente
		return CDI_CondRetOK;
	}
}
/*Fim da fun��o CDI_insere*/

/*In�cio da fun��o CDI_busca*/
/*Fun��o INTERNA que recebe um ponteiro para CorpoDisc e procura a matr�cula fornecida por refer�ncia em matbusca na lista de alunos e caso encontre o aluno
desejado retorna seus dados em alunodesejado que � um ponteiro para Aluno passado por refer�ncia.Caso n�o encontre,retorna a condi��o
de erro de aluno n�o encontrado.*/
CDI_tpCondRet CDI_busca(unsigned int matbusca, Aluno** alu) {
	unsigned int mat2=0, i=0, size = 0;
	Aluno *a = NULL;
	list_size(Corpo->Aluno, &size);	// Pego o tamanho da lista
	first(Corpo->Aluno);	// Seto a lista para o primeiro n�
	for (i = 0;i < size; i++) {
		get_val_cursor(Corpo->Aluno, (void**)&a);	// Pego o aluno atual
		ALU_GetMat(a, &mat2);	// Pego sua matr�cula
		if (matbusca == mat2) {	// Vejo se a matr�cula � igual � de busca
			*alu = a;
			return CDI_CondRetOK;	// se for, retorno ele.
		}
		next(Corpo->Aluno); // caso n�o seja, vou para o pr�ximo
	}
	return CDI_CondRetAlunoNaoCadastrado;	// N�o encontrei
}
/*Fim da fun��o CDI_busca*/

/*In�cio da fun��o CDI_altera*/
/*Fun��o que altera os dados de um aluno do corpo docente.*/
CDI_tpCondRet CDI_altera(int matbusca, char *nome, unsigned int mat, struct cpf *cpf, unsigned int telefone, struct data *nasc, struct endereco *end) {
	Aluno *alndesejado = NULL;

	CDI_busca(matbusca, &alndesejado);	// busco o aluno no corpo discente

	if (alndesejado == NULL)	// se n�o encontrei
		return CDI_CondRetAlunoNaoCadastrado;	// aluno n�o est� cadastrado.

	ALU_AlteraDados(alndesejado, nome, mat, cpf, telefone, nasc, end); // altero os dados, atrav�s da fun��o de alterar dado do m�dulo aluno.
	return CDI_CondRetOK;	// Tudo deu certo.

}
/*Fim da fun��o CDI_altera*/

/*In�cio da fun��o CDI_remove*/
/*Fun��o que recebe como par�metros a matr�cula do aluno a ser removido, o ponteiro para a estrutura Corpo Discente e remove da Lista do Corpo Discente o Aluno com matr�cula igual a recebida*/
CDI_tpCondRet CDI_remove(unsigned int matbusca) {
	Aluno *alndesejado = NULL;
	CDI_busca(matbusca, &alndesejado);	// Pego o ponteiro pro aluno, cuja matricula � matbusca
	if (alndesejado == NULL)
		return CDI_CondRetAlunoNaoCadastrado;
	else {
		pop_cursor(Corpo->Aluno, (void**)&alndesejado);//Remove da lista o elemento apontado pelo cursor
		return CDI_CondRetOK;
	}
}
/*Fim da fun��o CDI_remove*/

/*In�cio da fun��o CDI_imprime*/
/*Fun��o que recebe como par�metro o ponteiro para a estrutura Corpo Discente e imprime na tela todos os seus elementos*/
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
		next(Corpo->Aluno);	// vou para o pr�ximo
		printf("\n");	// Imprimo uma nova linha para dividir um aluno de outro
	}
	return CDI_CondRetOK;
}
/*Fim da fun��o CDI_imprime*/

/*In�cio da fun��o CDI_deleta*/
/*Fun��o que limpa a lista e libera o Corpo Discente. (Este deixa de existir)*/
CDI_tpCondRet CDI_deleta(void) {
	clear(Corpo->Aluno);	// limpo o corpo discente
	free(Corpo);	// libero o corpo discente
	return CDI_CondRetOK;
}
/*Fim da fun��o CDI_deleta*/

/*In�cio da fun��o CDI_limpa*/
/*Fun��o que limpa a lista e libera o Corpo Discente.
(Este continua existindo, permitido novas inser��es*/
CDI_tpCondRet CDI_limpa(void) {
	unsigned int size;
	list_size(Corpo->Aluno,&size);
	if (size == 0)
		return CDI_CondRetCDIVazio;
	clear(Corpo->Aluno);	// limpo o corpo discente
	return CDI_CondRetOK;
}
/*Fim da fun��o CDI_limpa*/

/*In�cio da fun��o CDI_imprimeInfo*/
/*Fun��o que imprime a informa��o de um aluno, dada sua matr�cula*/
CDI_tpCondRet CDI_imprimeInfo(unsigned int matbusca) {
	Aluno *a;
	CDI_tpCondRet retBuscaCDI;

	retBuscaCDI = CDI_busca(matbusca,&a);	// Busco o aluno
	if (retBuscaCDI != CDI_CondRetOK)
		return CDI_CondRetAlunoNaoCadastrado;
	ALU_imprimeAluno(a);	// imprimo os seus dados.
	return CDI_CondRetOK;
}
/*Fim da fun��o CDI_imprimeInfo*/


 /***************************************************************************
 *
 *  Fun��o: CDI Salva Dados
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
				printf( "Erro ao salvar arquivo de dados pessoais dos professores no m�dulo Corpo Docente. %s\n", pathComPasta ) ;
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

	}  /* Fim fun��o: CDO Salva Dados */

 /***************************************************************************
 *
 *  Fun��o: CDO Le Dados
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
				printf("Erro ao abrir arquivo de dados pessoais dos alunos no m�dulo Corpo Dicente.\n PATH: %s\n", pathComPasta) ;
			#endif
			//nao deu para abrir, criar pasta
			/*
				N�o deve existir a possibilidade de abrir a pasta e n�o ter nenhum arquivo dentro dela.
				Se n�o existe pasta, � a primeira vez que o o programa funciona, e portanto n�o tem arquivos.
				Se existe pasta, j� n�o � a primeira vez e tem algum arquivo la dentro, mesmoq ue esteja vazio.
				A n�o ser que o usu�rio delete os arquivos da pasta manualmente, mas ent�o, por isso eu n�o mes responsabilizo. Afinal estamos possibilitando que ele remova os dados atraves do proprio programa, o que n�o causa erros.
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

	} /* Fim fun��o: CDO Le Dados */

