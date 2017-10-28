/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Grade Curricular 
*
*  Arquivo gerado:              gradeCurricular.h
*  Letras identificadoras:      GRC
*
*  Nome da base de software:    Módulo Grade Curricular
*
*  Projeto: Disciplina INF 1301
*  Gestor:  Grupo 1, Grupo 4
*  Autores: Bruce Marcellino, BM Grupo 1.
*			Rodrigo Pumar, RP, Grupo 1.
*			Matheus Rodrigues de Oliveira Leal, mrol , Grupo 4.
*
*  $HA Histórico de evolução:
*     Versão	Autor	Data		  Observações
*		0.30    RP	    27/10/2017	  Documentação adicionada
*		0.20	mrol	27/10/2017	  Funções de consulta adicionadas
*       0.10    BM	    07/10/2017	  Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*	  Este módulo implementa um conjunto de funções para criar e manipular uma lista de disciplinas de informatica, ou seja, uma Grade Curricular de uma Universidade de Informática.
*     Ao iniciar a execução do programa não existe nenhuma instância de Grade Curricular.
*     Ao chamar a função criar, uma Grade Curricular vazia é criada, precisando assim ter Instâncias de Disciplinas já cadastrados.
*     Nenhuma funcao deste modulo deve ser chamada antes da GRC_cria();
*	  Deve-se usar a função libera para que a memória alocada seja liberada.
*	  Passar argumentos inválidos como 0 ou "" podem causar erro de formato (GRC_CondRetFormatoInvalido).
*     Esse módulo utiliza funções auxiliares para manipulação de Instâncias de Disciplinas (disciplina.h)
*
***************************************************************************/

#ifndef GRADECURRICULAR_H
#define GRADECURRICULAR_H

/***********************************************************************
*
*  $TC Tipo de dados: GRC Condições de retorno
*
*  $ED Descrição do tipo
*     Condições de retorno
*
***********************************************************************/

typedef enum{
	GRC_CondRetOk,
		/* Condicao de Retorno OK, usada quando a função executa corretamente */
	GRC_CondRetNaoHaMemoria,
		/* Condicao de Retorno Nao Ha Memoria, usada quando a memoria do sistema nao apresenta mais espaco */ 
	GRC_CondRetGradeCurricularVazia,
		/* Condicao de Retorno Grade Curricular Vazia, usada quando a lista de Instância de Disciplinas, ou seja o Grade Curricular, está vazia */ 
	GRC_CondRetDisciplinaNaoEncontrada, 
		/* Condicao de Retorno Disciplina Não Encontrada, usada quando o Disciplina não é encontrado numa busca ou quando a lista está vazia quando percorrida */ 
	GRC_CondRetIdJaCriado,
		/* Condicao de Retorno Id Já Criado, usada quando existe outra Instância de Disciplina na Grade Curricular com o mesmo código */ 
	GRC_CondRetFormatoInvalido 
		/* Condicao de Retorno Formato Inválido, usada quando os parâmetros de uma certa função não estão de acordo com o que é esperado pelas funções auxiliares */ 
} GRC_tpCondRet;


//TODO Inserir comentario
typedef GRC_tpCondRet (*GRC_alteraInt)(int);
typedef GRC_tpCondRet (*GRC_alteraString)(char*);


/***********************************************************************
*
*  $FC Função: GRC Cria
*
*  $ED Descrição da função
*     Cria uma instância vazia de Grade Curricular
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*
*  Assertiva de Entrada: 
*		-A função cria ainda não foi chamada.
*                    
*  Assertiva de Saída: 
*		-Uma instância de Grade Curricular (Lista de Disciplinas) é criada
*
***********************************************************************/

GRC_tpCondRet GRC_cria();

/***********************************************************************
*
*  $FC Função: GRC Cadastra
*
*  $ED Descrição da função
*     Cadastra um Disciplina em Grade Curricular com os dados passados
*
*  $EP Parâmetros 
*     $P nome - Nome do Disciplina que deseja cadastrar no Grade Curricular
*     $P codigo - Código do Disciplina que deseja cadastrar no Grade Curricular
*     $P creditos - Quantidade de Créditos da Disciplina
*     $P Bibliografia - Bibliografia da Disciplina
*     $P Ementa - Ementa da Disciplina
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetIdJaCriado - Caso o Código da Disciplina que deseja cadastrar já esteja cadastrado nessa instância de Grade Curricular.
*	  GRC_CondRetNaoHaMemoria - Caso não haja memória suficiente para cadastrar a Disciplina na Grade Curricular
*     GRC_CondRetFormatoInvalido - Caso o formato dos parâmetros não esteja de acordo com o esperado pelo modulo Disciplina
*
*  Assertiva de Entrada: 
*		-O Grade Curricular já foi instanciado
*                    
*  Assertiva de Saída: 
*		-Uma Instância de Disciplina é cadastrada na Grade Curricular
*
***********************************************************************/

GRC_tpCondRet GRC_cadastra(char* nome, char* codigo, int creditos, char* bibliografia, char* ementa);

/***********************************************************************
*
*  $FC Função: GRC Mostra Atual
*
*  $ED Descrição da função
*     Mostra a atual Instância de Disciplinas presentes na Grade Curricular
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetGradeCurricularVazia - Caso a Instância de Grade Curricular esteja vázia
*
*  Assertiva de Entrada: 
*		-A Grade Curricular foi instanciada
*		-Se Grade Curricular não esta vazia então instancia atual é valida.
*                    
*  Assertiva de Saída: 
*       -É necessário que a Função DIS_exibe e GRC_mostraPreRequisitos tenha suas assertivas de entrada e saida corretamente implementadas
*		-Mostra-se no Prompt de Comando a atual Instância de Disciplina selecionada e seus correspondentes pre-requisitos.
*
***********************************************************************/

GRC_tpCondRet GRC_mostraAtual();

/***********************************************************************
*
*  $FC Função: GRC Mostra Todos
*
*  $ED Descrição da função
*     Mostra todas as Instância de Disciplinas presentes na Grade Curricular
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetGradeCurricularVazia - Caso a Instância de Grade Curricular esteja vázia
*
*  Assertiva de Entrada: 
*		-A Grade Curricular já foi instanciada através da função cria
*		-Se Grade Curricular não esta vazia então instancia atual é valida.
*                    
*  Assertiva de Saída: 
*       -É necessário que a Função DIS_exibe e GRC_mostraPreRequisitos tenha suas assertivas de entrada e saida corretamente implementadas
*		-Mostra-se no Prompt de Comando todas as Instância de Disciplina e seus correspondentes pre-requisitos.
*
***********************************************************************/

GRC_tpCondRet GRC_mostraTodas();

/***********************************************************************
*
*  $FC Função: GRC Retira
*
*  $ED Descrição da função
*     Retira a atual Instância de Disciplina presente na Grade Curricular
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetGradeCurricularVazia - Caso a Instância de Grade Curricular esteja vazia
*
*  Assertiva de Entrada: 
*		-A Grade Curricular já foi instanciada através da função cria
*                    
*  Assertiva de Saída: 
*		-A atual Instância de Disciplina é retirada da Grade Curricular
*
***********************************************************************/

GRC_tpCondRet GRC_retira();

/***********************************************************************
*
*  $FC Função: GRC Limpa
*
*  $ED Descrição da função
*     Limpa a Grade Curricular retirando todas as Instâncias de Disciplinas presentes
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*                    
*  Assertiva de Saída: 
*		-Todas as Instâncias de Disciplinas são retiradas da Grade Curricular
*
***********************************************************************/

GRC_tpCondRet GRC_limpa();

/***********************************************************************
*
*  $FC Função: GRC Libera
*
*  $ED Descrição da função
*     Libera o espaço de memoria que está sendo usado para guardar as informações referentes a Grade Curricular 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*  Assertiva de Saída: 
*		-O espaço de memoria associado ao Grade Curricular é liberado
*
***********************************************************************/

GRC_tpCondRet GRC_libera();

/***********************************************************************
*
*  $FC Função: GRC Busca por Codigo
*
*  $ED Descrição da função
*     Busca no Grade Curricular (Lista de Disciplinas) um Professor pelo codigo
*
*  $EP Parâmetros
*     
*     $P codigo - Código da disciplina que deseja buscar na Grade Curricular
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetDisciplinaNaoEncontrada - Instância de Disciplina desejada não encontrada em Grade Curricular
*     GRC_CondRetGradeCurricularVazia - Caso a Grade Curricular apontada esteja vazio 
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*                    
*  Assertiva de Saída: 
*		-O cursor passa a aponta para uma Disciplina que armazena aquele código
*
***********************************************************************/

GRC_tpCondRet GRC_buscaPorCodigo(char *chave);


/***********************************************************************
*
*  $FC Função: GRC Insere Pre-Requisito
*
*  $ED Descrição da função
*     Insere na Discplina atual um novo pré-requisito,sendo este uma Disciplina já existente.
*
*  $EP Parâmetros
*     $P codigoPre - Código da disciplina que deseja inserir como pre-requisito na disciplina atual
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetDisciplinaNaoEncontrada - Codigo de Disciplina que tentamos adicionar como pre-requisito não se encontra na Grade Curricular
*     GRC_CondRetGradeCurricularVazia - Caso o Grade Curricular apontada esteja vazia
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*		- O cursor aponta para disciplina para qual deseja se adicionar um pre-requisito
*                    
*  Assertiva de Saída: 
*		- Caso o codigo da diciplina passada como exista na grade curricular, este condigo de disciplina é adicionada a lista de prerequisitos para a disciplina atual.
*		- Caso o contrário, a disciplina não tem pre-requisito adicionado.
*
***********************************************************************/

GRC_tpCondRet GRC_inserePreRequisito(char *codigoPre);

/***********************************************************************
*
*  $FC Função: GRC Remove Pre-requisitos
*
*  $ED Descrição da função
*     Remove da Discplina atual todos pré-requisito.
*				
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetGradeCurricularVazia - Caso o Grade Curricular apontada esteja vazia
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*		- O cursor aponta para disciplina para qual deseja se remover todos os pre-requisitos
*                    
*  Assertiva de Saída: 
*		- Agora diciplina atual não possui pre-requisitos.
*
***********************************************************************/

GRC_tpCondRet GRC_removePreRequisitos();


/***********************************************************************
*
*  $FC Função: GRC Consulta Nome
*
*  $ED Descrição da função
*     Consulta o Nome da instância de Disciplina selecionada naquele momento
*
*  $EP Parâmetros     
*     $P nome - Cadeia de caracteres que receberá o nome da Disciplina selecionada, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetGradeCurricularVazia - Caso a Grade Curricular apontada esteja vazia
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*		-O ponteiro para a cadeia possui pelo menos o limite estabelecido no modulo Disciplina como tamanho da string
*		-O ponteiro para nome é valido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função DIS_get_nome tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteudo do ponteiro para nome será preenchido com o nome valido da Disciplina em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaNome(char *nome);

/***********************************************************************
*
*  $FC Função: GRC Consulta Codigo
*
*  $ED Descrição da função
*     Consulta o Codigo da instância de Disciplina selecionada naquele momento
*
*  $EP Parâmetros     
*     $P codigo - Cadeia de caracteres que receberá o Código da Disciplina selecionada, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk
*     GRC_CondRetGradeCurricularVazia - Caso a Grade Curricular apontada esteja vazia 
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*		-O ponteiro para a cadeia possui pelo menos o limite estabelecido no modulo Disciplina como tamanho da string
*		-O ponteiro para codigo é valido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função DIS_get_codigo tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteudo do ponteiro para nome será preenchido com o codigo valido da Disciplina em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaCodigo(char *codigo);

/***********************************************************************
*
*  $FC Função: GRC Consulta Creditos
*
*  $ED Descrição da função
*     Consulta o numero de Creditos da instância de Disciplina selecionada naquele momento
*
*  $EP Parâmetros     
*     $P creditos - Inteiro que receberá o número de creditos da Disciplina selecionada, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk
*     GRC_CondRetGradeCurricularVazia - Caso a Grade Curricular apontada esteja vazia 
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*		- O ponteiro para o inteiro creditos é valido
*                    
*  Assertiva de Saída: 
*	    - É necessário que a Função DIS_get_creditos tenha suas assertivas de entrada e saida corretamente implementadas
*       - Caso isso ocorra o conteudo do ponteiro para creditos será preenchido com um numero de creditos valido da Disciplina em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaCreditos(int *creditos);

/***********************************************************************
*
*  $FC Função: GRC Consulta Bibliografia
*
*  $ED Descrição da função
*     Consulta a Bibliografia da instância de Disciplina selecionada naquele momento
*
*  $EP Parâmetros     
*     $P bibliografia - Cadeia de caracteres que receberá o Código da Disciplina selecionada, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk
*     GRC_CondRetGradeCurricularVazia - Caso a Grade Curricular apontada esteja vazia 
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*		- O ponteiro para a cadeia possui pelo menos o limite estabelecido no modulo Disciplina como tamanho da string
*		- O ponteiro para bibliografia é valido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função DIS_get_bibliografia tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteudo do ponteiro para bibliografia será preenchido com uma bibliografia valida da Disciplina em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaBibiliografia(char *bibiliografia);

/***********************************************************************
*
*  $FC Função: GRC Consulta Ementa
*
*  $ED Descrição da função
*     Consulta a Ementa da instância de Ementa selecionada naquele momento
*
*  $EP Parâmetros     
*     $P ementa - Cadeia de caracteres que receberá a Ementa da Disciplina selecionada, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk
*     GRC_CondRetGradeCurricularVazia - Caso a Grade Curricular apontada esteja vazia 
*
*  Assertiva de Entrada: 
*		- A Grade Curricular já foi instanciada através da função cria
*		- O ponteiro para a cadeia possui pelo menos o limite estabelecido no modulo Disciplina como tamanho da string
*		- O ponteiro para ementa é valido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função DIS_get_ementa tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteudo do ponteiro para ementa será preenchido com uma ementa valida da Disciplina em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaEmenta(char *ementa);

#endif

/***********************************************************************/
