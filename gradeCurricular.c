/***************************************************************************
*  $MCI Módulo de implementação: Módulo Corpo Grade Curricular
*
*  Arquivo gerado:              gradeCurricular.C
*  Letras identificadoras:      GRC
*
*  Nome da base de software:    Fonte do módulo Grade Curricular
*
*  Projeto: Disciplina INF 1301
*  Gestor:  Grupo 1, Grupo 4
*  Autores: Bruce Marcellino, BM Grupo 1.
*			Rodrigo Pumar, RP, Grupo 1.
*			Matheus Rodrigues de Oliveira Leal, mrol , Grupo 4.
*
*  $HA Histórico de evolução:
*     Versão	Autor	Data		  Observações
*		0.40    RP	    28/10/2017	  Get de disciplina agora recebem endereço (funcoes consultas aqui)
*		0.30    RP	    27/10/2017	  Documentação adicionada
*		0.20	mrol	27/10/2017	  Funções de consulta adicionadas
*       0.10    BM	    07/10/2017	  Inicio do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo contém as funções específicas para manipular os disciplinas na lista de Grade Curricular.
*     Este módulo utiliza funcões de interface do módulo disciplina e lista.
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "gradeCurricular.h"
#include "criterio_de_aprovacao.h"
#include "disciplina.h"
#include "listas.h"
#include "turma.h"
#include "corpoDocente.h"
#include "professor.h"
#include "CorpoSala.h"

/***********************************************************************
*
*  $TC Tipo de dados: parDisciplina
*
*  $ED Descrição do tipo
*     Estrutura do par Disciplina e Pre-requisitos encapsulada neste módulo.
*
***********************************************************************/

typedef struct parDisciplina {
	Disciplina *disciplina;
	List *preRequisitos;
} ParDisciplina;

/***********************************************************************
*
*  $TC Tipo de dados: gradeCurricular
*
*  $ED Descrição do tipo
*     Estrutura principal que armazena os dados de uma Grade Curricular ao qual este módulo se dedica.
*
***********************************************************************/
typedef struct gradeCurricular {
	List *parDisciplinas;
} GradeCurricular;


/*****  Dados encapsulados no módulo  *****/

static GradeCurricular *grc;
/* instância de Grade Curricular armazenada por este módulo */

/***** Protótipos das funções encapsuladas no módulo *****/
	void GRC_retiraAspas(char *s);
	GRC_tpCondRet GRC_mostraPreRequisitos(ParDisciplina *parD);


/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: GRC Criar Grade Curricular
*  ****/

GRC_tpCondRet GRC_cria() {
	grc = (GradeCurricular*)calloc(1, sizeof(GradeCurricular));
	createList(&grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim função: GRC Criar Grade Curricular */

 /***************************************************************************
 *
 *  Função: GRC Cadastrar Disciplina
 *  ****/

GRC_tpCondRet GRC_cadastra(char* nome, char* codigo, int creditos, char* bibliografia, char* ementa, int criterio) {
	ParDisciplina *parD = NULL;
	Disciplina *disc = NULL;
	DIS_tpCondRet ret;
	if (GRC_buscaPorCodigo(codigo) == GRC_CondRetOk)
		return GRC_CondRetIdJaCriado;
	ret = DIS_gera_param(&disc, nome, codigo, creditos, bibliografia, ementa, criterio);
	if (ret == DIS_CondRetFaltouMemoria) return GRC_CondRetNaoHaMemoria;
	if (ret == DIS_CondRetParametroInvalido) return GRC_CondRetFormatoInvalido;
	parD = (ParDisciplina*)calloc(1, sizeof(ParDisciplina));
	parD->disciplina = disc;
	createList(&parD->preRequisitos);
	push_back(grc->parDisciplinas, parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Cadastrar Disciplina */

 /***************************************************************************
 *
 *  Função: GRC Cadastra Disciplina pelo CMD
 *  ****/
GRC_tpCondRet GRC_cadastraCMD() {
	ParDisciplina *parD = NULL;
	Disciplina *disc = NULL;
	char codigo[MAX_CODIGO];
	DIS_tpCondRet ret;

	ret = DIS_gera_cmd(&disc, codigo);
	if (ret == DIS_CondRetFaltouMemoria)
		return GRC_CondRetNaoHaMemoria;
	if (ret == DIS_CondRetParametroInvalido)
		return GRC_CondRetFormatoInvalido;
	if (GRC_buscaPorCodigo(codigo) == GRC_CondRetOk)
		return GRC_CondRetIdJaCriado;
	parD = (ParDisciplina*)calloc(1, sizeof(ParDisciplina));
	parD->disciplina = disc;
	createList(&parD->preRequisitos);
	push_back(grc->parDisciplinas, parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Cadastrar Disciplina pelo CMD */

 /***********************************************************************
 *
 *  $FC Função: GRC Mostra Pre-Requisitos
 *
 *  $ED Descrição da função
 *     Mostra Pre-requisitos da disciplina atual.
 *
 *  $FV Valor retornado
 *     GRC_CondRetOk
 *
 *  Assertiva de Entrada:
 *		- A Grade Curricular já foi instanciada através da função cria
 *		- O cursor aponta para disciplina para qual deseja se mostrar todos os seus pre-requisitos
 *
 *  Assertiva de Saída:
 *		-Mostra-se no Prompt de Comando todos os pre-requisitos da disciplina atual.
 *
 ***********************************************************************/
GRC_tpCondRet GRC_mostraPreRequisitos(ParDisciplina *parD) {
	Disciplina *disc = NULL;
	char buffer[80] = "";
	char *codigo = NULL;
	int tam = 0;
	first(parD->preRequisitos);
	printf("Pre-Requisitos: ");
	do {
		if (get_val_cursor(parD->preRequisitos, (void**)&disc) == LIS_CondRetListaVazia) break;
		DIS_get_codigo(disc, &codigo);
		printf(" %s", buffer);
		strcpy(buffer, codigo);
		strcat(buffer, ",");
		free(codigo);
	} while (next(parD->preRequisitos) == LIS_CondRetOK);
	if (strcmp(buffer, "") == 0)
		printf("--//--");
	else {
		tam = strlen(buffer);
		/* Tam não é igual a zero, pois se fosse, nao estariamos neste if */
		buffer[tam - 1] = '.';
		printf("%s", buffer);
	}
	printf("\n");
	return GRC_CondRetOk;
}/* Fim função: GRC Mostra Pre-Requisitos */

 /***************************************************************************
 *
 *  Função: GRC Mostra Atual
 *  ****/

GRC_tpCondRet GRC_mostraAtual() {
	ParDisciplina *parD = NULL;
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_exibe(parD->disciplina);
	GRC_mostraPreRequisitos(parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Mostra Atual */

 /***************************************************************************
 *
 *  Função: GRC Mostra Todos Professores
 *  ****/

GRC_tpCondRet GRC_mostraTodas() {
	ParDisciplina *parD = NULL;
	first(grc->parDisciplinas);
	do {
		if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
		DIS_exibe(parD->disciplina);
		GRC_mostraPreRequisitos(parD);
	} while (next(grc->parDisciplinas) == LIS_CondRetOK);
	return GRC_CondRetOk;
}/* Fim função: GRC Mosta Todos Professores */

 /***************************************************************************
 *
 *  Função: GRC Limpa Lista
 *  ****/

GRC_tpCondRet GRC_limpa() {
	ParDisciplina *parD = NULL;
	while (pop_back(grc->parDisciplinas, (void**)&parD) == LIS_CondRetOK) {
		DIS_deleta_Disciplina(&parD->disciplina);
		del(parD->preRequisitos);
		free(parD);
	};
	return GRC_CondRetOk;
}/* Fim função: GRC Limpa Lista */

 /***************************************************************************
 *
 *  Função: GRC Retira da Lista
 *  ****/

GRC_tpCondRet GRC_retira() {
	ParDisciplina *parD = NULL;
	if (pop_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_deleta_Disciplina(&parD->disciplina);
	del(parD->preRequisitos);
	free(parD);
	return GRC_CondRetOk;
}/* Fim função: GRC Retira da Lista */

 /***************************************************************************
 *
 *  Função: GRC Libera
 *  ****/

GRC_tpCondRet GRC_libera() {
	GRC_limpa();
	del(grc->parDisciplinas);
	return GRC_CondRetOk;
}/* Fim função: GRC Libera */

 /***************************************************************************
 *
 *  Função: GRC Busca Por Codigo
 *  ****/

GRC_tpCondRet GRC_buscaPorCodigo(char *chave) {
	ParDisciplina *parD = NULL;
	char *inicioCod = NULL;
	int i;
	unsigned int size = 0;

	list_size(grc->parDisciplinas, &size);	// Pego o tamanho da lista
	first(grc->parDisciplinas);	// Seto a lista para o primeiro nó
	for (i = 0;i < size; i++) {
		get_val_cursor(grc->parDisciplinas, (void**)&parD);	// Pego o aluno atual
		DIS_get_codigo(parD->disciplina, &inicioCod);	// Pego sua matrícula
		if (strcmp(inicioCod, chave) == 0) {	// Vejo se a matrícula é igual à de busca
			return GRC_CondRetOk;	// se for, retorno ele.
		}
		next(grc->parDisciplinas); // caso não seja, vou para o próximo
	}
	return GRC_CondRetDisciplinaNaoEncontrada;
}/* Fim função: GRC Busca Por Codigo */

 /***************************************************************************
 *
 *  Função: GRC Insere Pre-Requisito
 *  ****/

 /*
 TODO formalizar este comentário
 Note que o codigo passado como argumento é o codigo do pre-requisito. E NÃO o código da disciplina a qual vamos adicionar um preRequisito.
 A disciplina a qual vamos adicionar é a disciplina selecionada (cursor).
 */
GRC_tpCondRet GRC_inserePreRequisito(char *codigoPre) {
	ParDisciplina *parD = NULL;
	ParDisciplina *parDPre = NULL;
	char *codigo = NULL;
	/* Recuperando disciplina atual da lista */
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) 
		return GRC_CondRetGradeCurricularVazia;
	/* Recuperando o código dela */
	DIS_get_codigo(parD->disciplina, &codigo);
	/* Procurando o pre requisito */
	if (GRC_buscaPorCodigo(codigoPre) != GRC_CondRetOk) 
	{
		/* Se não encontrei retorno o cursor para onde comecei e retorno */
		GRC_buscaPorCodigo(codigo);
		free(codigo);
		return GRC_CondRetDisciplinaNaoEncontrada;
	}
	/*
	Recuperando a disciplina Pre-Requisito
	Ja sei que a lista não esta vazia, não preciso verificar de novo
	*/
	get_val_cursor(grc->parDisciplinas, (void**)&parDPre);
	/* Guardo o endereco do pre-requisito (disciplina, nao par) na lista do par (e nao disciplina) que recuperei no inicio */
	push_back(parD->preRequisitos, parDPre->disciplina);
	/* Retorno o cursor para onde comecei e retorno */
	GRC_buscaPorCodigo(codigo);
	free(codigo);
	return GRC_CondRetOk;
}/* Fim função: GRC Insere Pre-Requisito */


 /***************************************************************************
 *
 *  Função: GRC Remove Pre-requisitos
 *  ****/

GRC_tpCondRet GRC_removePreRequisitos() {
	ParDisciplina *parD = NULL;
	/* Recuperando disciplina da lista */
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	clear(parD->preRequisitos);
	return GRC_CondRetOk;
}/* Fim função: GRC Remove Pre-requisitos */


 /***************************************************************************
 *
 *  Função: GRC Consulta Nome
 *  ****/
GRC_tpCondRet GRC_consultaNome(char *nome) {
	ParDisciplina *parD = NULL;
	char *nomeTemp = NULL;
	/* Recuperando disciplina da lista */
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_nome(parD->disciplina, &nomeTemp);
	strcpy(nome, nomeTemp);
	free(nomeTemp);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Nome */

 /***************************************************************************
 *
 *  Função: GRC Consulta Codigo
 *  ****/
GRC_tpCondRet GRC_consultaCodigo(char *codigo) {
	ParDisciplina *parD = NULL;
	char *codigoTemp = NULL;
	/* Recuperando disciplina da lista */
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_codigo(parD->disciplina, &codigoTemp);
	strcpy(codigo, codigoTemp);
	free(codigoTemp);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Codigo*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Credito
 *  ****/
GRC_tpCondRet GRC_consultaCreditos(int *creditos) {
	ParDisciplina *parD = NULL;
	int credTemp;
	/* Recuperando disciplina da lista */
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_creditos(parD->disciplina, &credTemp);
	*creditos = credTemp;
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Credito*/

 /***************************************************************************
 *
 *  Função: GRC Consulta Bibliografia
 *  ****/
GRC_tpCondRet GRC_consultaBibliografia(char *bibliografia) {
	ParDisciplina *parD = NULL;
	char *biblioTemp = NULL;
	/* Recuperando disciplina da lista */
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_bibliografia(parD->disciplina, &biblioTemp);
	strcpy(bibliografia, biblioTemp);
	free(biblioTemp);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Bibliografia*/


 /***************************************************************************
 *
 *  Função: GRC Consulta Ementa
 *  ****/
GRC_tpCondRet GRC_consultaEmenta(char *ementa) {
	ParDisciplina *parD = NULL;
	char *EmentaTemp = NULL;
	/* Recuperando disciplina da lista */
	if (get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	DIS_get_ementa(parD->disciplina, &EmentaTemp);
	strcpy(ementa, EmentaTemp);
	free(EmentaTemp);
	return GRC_CondRetOk;
}/* Fim função: GRC Consulta Ementa*/


 /***************************************************************************
 *
 *  Função: GRC cadastra Turma Na Sala
 *  ****/
GRC_tpCondRet GRC_cadastraTurmaNaSala( char *codDis, char *codTur, char *codSala){
	Disciplina * dis;
	SAL_tpSala * pSala;
	Turma * tur;

	/* TODO inserir verificacoes */
	GRC_buscaPorCodigo(codDis);
	GRC_devolveDisc((void**) &dis);

	CDS_buscaCod(&pSala, codSala);

	DIS_buscaTurma(dis, codTur, &tur);

	TUR_cadastraTurmaNaSala(tur, pSala);
	return GRC_CondRetOk;
}/* Fim função: GRC cadastra Turma Na Sala */


 /***************************************************************************
 *
 *  Função: GRC Devolve a Disciplina do cursor atual
 *  ****/
GRC_tpCondRet GRC_devolveDisc(void** Disc) {
	ParDisciplina *parDisc1;

	if (get_val_cursor(grc->parDisciplinas, (void**)&parDisc1) == LIS_CondRetListaVazia) return GRC_CondRetGradeCurricularVazia;
	get_val_cursor(grc->parDisciplinas, (void**)&parDisc1);
	*Disc = parDisc1->disciplina;
	return GRC_CondRetOk;
} /* Fim função:GRC_devolveDisc*/

  /***************************************************************************
  *
  *  Função: GRC Devolve a situação do aluno na Disciplina cursor atual, notas não utilizadas = 0
  *  ****/
GRC_tpCondRet GRC_attSituacaoDisCorrente(float G1, float G2, float G3, float G4, float* media, int* situacao) {
	ParDisciplina *parDisc1;

	get_val_cursor(grc->parDisciplinas, (void**)&parDisc1);
	DIS_situacaoAluno(parDisc1->disciplina, G1, G2, G3, G4, media, situacao);
	return GRC_CondRetOk;
} /* Fim função:GRC_devolveDisc*/

GRC_tpCondRet GRC_insereTurma(char* codTur, int horIni, int horTer, char* diaSem, int qtdVag, int qtdMat, char* codigo)
{
	Turma* novaTurma = NULL;
	ParDisciplina* parDisc;
	int ret2;
	GRC_tpCondRet ret = GRC_buscaPorCodigo(codigo);

	if (ret != GRC_CondRetOk)
		return ret;
	if (get_val_cursor(grc->parDisciplinas, (void**)&parDisc) == LIS_CondRetListaVazia)
		return GRC_CondRetGradeCurricularVazia;
	ret2 = TUR_CriaTurma(&novaTurma, codTur, horIni, horTer, diaSem, qtdVag, qtdMat);
	if (ret2 == TUR_CondRetFaltouMemoria)
		return GRC_CondRetNaoHaMemoria;
	DIS_insere_turma(parDisc->disciplina, novaTurma);
	//DIS_exibe_todas_turmas(parDisc->disciplina);

	return GRC_CondRetOk;
}


GRC_tpCondRet GRC_exibeTurmas(char* codigo)
{
	ParDisciplina* parDisc;
	GRC_tpCondRet ret = GRC_buscaPorCodigo(codigo);
	if (ret != GRC_CondRetOk)
	{
		return ret;
	}
	if (get_val_cursor(grc->parDisciplinas, (void**)&parDisc) == LIS_CondRetListaVazia)
		return GRC_CondRetGradeCurricularVazia;
	DIS_exibe_todas_turmas(parDisc->disciplina);

	return GRC_CondRetOk;
}

 /***************************************************************************
 *
 *  Função: GRC 
 *  ****/

	GRC_tpCondRet GRC_CadastraProfNaTurma ( char * codDisc, int matProf, char * codTurma ) 
	{
		Prof * professor = NULL;
		Disciplina * Disc = NULL ;
		Turma * tur = NULL;
		
		GRC_buscaPorCodigo(codDisc);
		GRC_devolveDisc ((void**)&Disc); 

		DIS_buscaTurma(Disc, codTurma, &tur);

		CDO_DevolvProf( &professor, matProf );
		
		TUR_cadastraProfTurma (tur, &professor);
		
		return GRC_CondRetOk;
		
	}

 /***************************************************************************
 *
 *  Função: GRC 
 *  ****/

	GRC_tpCondRet GRC_CadastraSalaNaTurma ( char * codDisc, char * codTur, char * codSala ) 
	{
		SAL_tpSala * pSala = NULL;
		Disciplina * Disc = NULL ;
		Turma * tur = NULL;
		
		GRC_buscaPorCodigo(codDisc);
		GRC_devolveDisc ((void**)&Disc); 

		DIS_buscaTurma(Disc, codTur, &tur);

		CDS_buscaCod ( &pSala, codSala );
		
		TUR_alteraSala (tur, pSala);
		
		return GRC_CondRetOk;
		
	}


 /***************************************************************************
 *
 *  Função: GRC Salva Dados
 *  ****/

	GRC_tpCondRet GRC_salvaDados ( char * path )
	{

		ParDisciplina *parD = NULL;
		unsigned int tam = 0;
		char c = ',';

		FILE *f ;

		#ifdef _DEBUG	
			printf("PATH: %s\n", path) ;
		#endif

		printf( "PATH: %s\n", path ) ;
		f = fopen(path,"wt") ;

		if ( !f )
		{
			#ifdef _DEBUG	
				printf( "Erro ao salvar arquivo de dados de Grade Curricular.\nPATH: %s\n", path ) ;
			#endif
			return GRC_CondRetErroAbrirArquivo ;
		} /* if */

		first( grc->parDisciplinas ) ;
		list_size(grc->parDisciplinas, &tam);
		for(;tam;tam--)
		{
			if( get_val_cursor(grc->parDisciplinas, (void**)&parD) == LIS_CondRetListaVazia )
			{
				fclose(f) ;
				return GRC_CondRetGradeCurricularVazia ;
			} /* if */
			DIS_salvaDados ( parD->disciplina, f ) ;
			DIS_salvaTurma ( parD->disciplina, f ) ;

			/*
				Caractere de Separação.
				Não sei quantos turma vou ler, por isso coloquei uma virgula, ao final de cada uma delas e um ponto-e-virgula, no final de todas.
				Após um ponto-e-virgula começa outra disciplina.
			*/
			if(tam==1) c = ';';
			printf("%c\n", c);

		} while( next(grc->parDisciplinas)==LIS_CondRetOK ) ;
		
		
		fclose(f) ;

		return GRC_CondRetOk ;

	}  /* Fim função: GRC Salva Dados */

 /***************************************************************************
 *
 *  Função: GRC Retira Aspas
 *  ****/

void GRC_retiraAspas(char *s){
	int tam = strlen(s);
	if( tam == 2 ) s[0] = '\0';
	else{
		s[tam-1] = '\0';
		strcpy(s, s+1);
	}
} /* Fim função: GRC Retira Aspas */
	


 /***************************************************************************
 *
 *  Função: GRC Le Dados
 *  ****/

	GRC_tpCondRet GRC_leDados ( char * path )
	{

		char nome[MAX_NOME];
		char codigo[MAX_CODIGO];
		int creditos;
		char bibliografia[MAX_BIBLIOGRAFIA];
		char ementa[MAX_EMENTA];
		int criterio;
		//List * turmas;
		char codTur[4];
		char diaSem[28];
		int horIni, horFin;
		int qtdVag, qtdMat;
		char c ;
		GRC_tpCondRet ret;

		/* TODO colocar define */

		/*
			Estou lendo a matricula de professor como string, porque a turma não necessariamente possui um professor.
			Então lemos aspas simples vazia para indicar isso.

		*/
		int matProf;
		char matProfS[81] = "";
		char codSala[81] = "";

		FILE * f ;

		#ifdef _DEBUG
			printf( "PATH: %s\n", path) ;
		#endif

		//abrindo arquivo
		f = fopen( path, "rt" ) ;

		if ( !f )
		{
			#ifdef _DEBUG
				printf("Erro ao abrir arquivo de dados de Grade Curricular.\n PATH: %s\n", path) ;
			#endif

			return GRC_CondRetOk ;
		} /* if */

		while( fscanf(f, "\'%[^\']\' %s %d \'%[^\']\' \'%[^\']\' %d\n",
				nome, codigo, &creditos, bibliografia, ementa, &criterio )>0 )
		{

			#ifdef _DEBUG
				printf( "%s %s %d %s %s %d \n",
					nome, codigo, creditos, bibliografia, ementa, criterio ) ;
			#endif

			ret = GRC_cadastra( nome, codigo, creditos, bibliografia, ementa, criterio) ;
			
			if ( ret != GRC_CondRetOk )
			{
				#ifdef _DEBUG
					printf("Erro ao cadastrar Disciplina.\n") ;
				#endif
				return ret ;
			} /* if */

			while( fscanf(f, "%s %s %d %d %d %d %s %s %c\n",
				codTur, diaSem, &horIni, &horFin, &qtdMat, &qtdVag, matProfS, codSala, &c )>0 )
			{

				#ifdef _DEBUG
					printf( "%s %s %d %d %d %d %s %s %c\n",
						codTur, diaSem, horIni, horFin, qtdMat, qtdVag, matProfS, codSala,  c ) ;
				#endif

				GRC_retiraAspas(matProfS);
				GRC_retiraAspas(codSala); 

				#ifdef _DEBUG
					printf( "Aspas retiradas:%s %s \n",
						matProfS, codSala ) ;
				#endif

				matProf = atoi(matProfS);				

				ret = GRC_insereTurma( codTur, horIni, horFin, diaSem, qtdVag, qtdMat, codigo);
				
				GRC_CadastraProfNaTurma(codigo, matProf, codTur);
				GRC_CadastraSalaNaTurma ( codigo, codTur, codSala );
				
				if ( ret != GRC_CondRetOk )
				{
					#ifdef _DEBUG
						printf("Erro ao cadastrar Turma.\n") ;
					#endif
				} /* if */

				if (c == ';')
				{
					printf("cheguei no fim\n");
					break ;
				} /* if */

			} /* while */
			
		} /* while */

		fclose(f) ;

		return ret ;

	} /* Fim função: GRC Le Dados */
