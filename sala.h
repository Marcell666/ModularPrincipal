#if ! defined( SALA_ )
#define SALA_

/****************************************************************
*$AD MÛdulo de definiÁ„o
*	Arquivo: SALA.h
*	Propriet·rio: Grupo 3 INF1301 17.2
*	Projeto: Trabalho 1
*	Gestor:  DI/PUC-Rio
*	Letras Identificadoras: SAL
*	Autores: mc - Matheus Caldas
*		 bp - Bruno Pedrazza
*	         pg - Pedro Gomes
*	         va - VinÌcius Arcoverde
*	         lf - Leon FranÁa
*	         gc - Gabriel Costa
*
*$ED Descricao do modulo
*     Este mÛdulo implementa um conjunto de funcoes para criar e manipular
*     atributos do mÛdulo Sala.
*
*
*
*$HA AlteraÁıes:
*       Versao       Autor         Data            Observacoes
*	1.3.1	      lf	10/09/2017	Padronizacao da documentacao
*	1.3.0	      mc	10/09/2017	Remove sala agora usa ponteiro de ponteiro
*	1.2.7	      pg	07/09/2017	Adicionando removeSala, Corrigindo parametros reservaSala
*	1.2.6	      mc        07/09/2017	MudanÁa na estrutura b·sica da criaSala, agora recebendo os parametros.
*       1.2.5	      gp	05/09/2017	ImplementaÁ„o de SAL
*       1.2.4	      pg        04/09/2017	ImplementaÁ„o de SAL_CondRetReservada
*       1.2.3         bp        03/09/2017   	Implementacao funcoes getELaboratorio e setELaboratorio
*       1.2.2         mc        02/09/2017   	Implementacao funcoes setQtdComputadores e getQtdComputadores
*       1.2.1         bp        02/09/2017   	Mudanca nas condicoes de retorno funcoes getNumero, getPredio, getAndar, setCodigo
*       1.2.0         pg        31/08/2017   	Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
*       1.1.0         bp        31/08/2017   	Implementacao funcoes getNumero, getPredio, getAndar
*       1.0.0         mc        30/08/2017   	Inicio do desenvolvimento
*
*$.***************************************************************************/

#if defined( SALA_OWN )
   #define SALA_EXT
#else
   #define SALA_EXT extern
#endif


#define HORARIOS 16
#define DIAS 6
#define tamPredio 10
#define tamCodigoSala 6
#define ajusteHora 7
#define salaReservada 1
#define salaLiberada 0
#define salaLivre 0
#define inicioDiaLetivo 7
#define fimDiaLetivo 23
#define inicioSemanaLetiva 0
#define fimSemanaLetiva 5

/***** Declara¡?es exportadas pelo m€dulo *****/

/*Tipo estruturado tpSala » constituido por quatro (4) tipos de dados diferentes, criados para identifica¡Ño, categoriza¡Ño
 e manipula¡Ño dos hor∑rios das salas de aula do curso de inform∑tica da PUC-Rio, sÑo eles o C€digo da sala (exs: L222, F765, K1001),
 a Capacidade M∑xima de alunos da mesma (exs: 42, 25, 34), um parametro categorizador entre salas laborat€rios e nÑo laborat€rios
 e por fim uma matriz de disponibilidade que indica em que dia e hor∑rio a sala est∑ sendo ultilizada ou nÑo por uma turma de alunos*/
typedef struct SAL_tagSala SAL_tpSala;

/***********************************************************************
 *
 *$TC Tipo de dados: SAL Condicoes de retorno
 *$ED Descri¡Ño do tipo
 *    Condi¡?es de retorno das fun¡?es da Sala
 *
 *$.***********************************************************************/

typedef enum {
    
    SAL_CondRetOK = 0 ,
    /* Executou correto */
    
    SAL_CondRetFaltouMemoria = 1 ,
    /* Erro ao tentar ciar sala */
    
    SAL_CondRetRecebeuPonteiroNulo = 2 ,
    /* Recebeu ponteiro para sala nulo */
    
    SAL_CondRetErroEstrutura = 3 ,
    /* Recebeu estrutura com erro */
    
    SAL_CondRetParamInvalido = 4 ,
    /* Erro no parametro recebido em funcao set */
    
    SAL_CondRetErroAoReservar = 5 ,
    /* Enviada quando uma sala ja esta reservada */
    
    SAL_CondRetErroAoLiberar = 6
    /* Erro ao tentar liberar sala */
    
} SAL_tpCondRet ;


/***********************************************************************
 *$FC Fun¡Ño: SAL_criarSala
 *$ED Descri¡Ño da fun¡Ño
 *	Cria umsa sala, chama todas as fun¡?es set para preencher todas as dependÕncias nescess∑rias.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetErroEstrutura
 *	SAL_CondRetRecebeuPonteiroNulo
 *	SAL_CondRetParamInvalido
 *$EP Parametros
 *$P	psala: Ponteiro de ponteiro para tipo estruturado sala onde ser∑ armazenada a sala resultante.
 *$P	codigo: C€digo da sala a ser inserido
 *$P	maxAlunos: Capacidade m∑xima de alunos da sala a ser inserida.
 *$P	eLaboratorio: Valor entre 1(» laborat€rio) e 0(nÑo » laborat€rio) para a dependÕncia se a sala » ou nÑo um laborat€rio.
 *
 *$.***********************************************************************/


SAL_tpCondRet SAL_criarSala(SAL_tpSala ** pSala, char *codigo, int maxAlunos, int eLaboratorio);

/***********************************************************************
 *$FC Fun¡Ño: SAL_removeSala
 *$ED Descri¡Ño da fun¡Ño
 *	Remove uma sala, destruindo toda as informa¡?es contidas no tipo estruturado.
 *$FV Valor retornado
 *	SAL_CondRetOK
 * SAL_CondRetRecebeuPonteiroNulo
 *$EP Parametros
 *$P	psala: Endere¡o do ponteiro para tipo estruturado sala.
 *$.***********************************************************************/

SAL_tpCondRet SAL_removeSala (SAL_tpSala ** pSala);

/***********************************************************************
 *$FC Fun¡Ño: SAL_printSala
 *$ED Descri¡Ño da fun¡Ño
 *	Imprime no terminal todas as informa¡?es pertinentes a sala fornecida.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetErroEstrutura
 *	SAL_CondRetRecebeuPonteiroNulo
 *$EP Parametros
 *$P	psala: Ponteiro para tipo estruturado sala.
 *$.***********************************************************************/

SAL_tpCondRet SAL_printSala (SAL_tpSala * pSala);

/***********************************************************************
 *$FC Fun¡Ño: SAL_setCodigo
 *$ED Descri¡Ño da fun¡Ño
 *	Define o c€digo da sala fornecida.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 *    	SAL_CondRetParamInvalido
 *$EP Parametros
 *$P	pSala: Ponteiro para tipo estruturado sala.
 *$P	codigo: C€digo da sala a ser inserido.
 *$.***********************************************************************/

SAL_tpCondRet SAL_setCodigo(SAL_tpSala * pSala, char *codigo);

/***********************************************************************
 *$FC Fun¡Ño: SAL_getCodigo
 *$ED Descri¡Ño da fun¡Ño
 *	Retrona o c€digo da sala fornecida no conte?do do ponteiro c€digo.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetErroEstrutura
 *	SAL_CondRetRecebeuPonteiroNulo
 *$EP Parametros
 *$P	pSala: Ponteiro para tipo estruturado sala.
 *$P	codigo: C€digo da sala a ser retornado.
 *$.***********************************************************************/

SAL_tpCondRet SAL_getCodigo(SAL_tpSala * pSala, char *codigo);

/***********************************************************************
 *$FC Fun¡Ño: SAL_setMaxAlunos
 *$ED Descri¡Ño da fun¡Ño
 *	Insere a capacidade m∑xima de alunos em uma sala.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 *	SAL_CondRetErroEstrutura
 *$EP Parametros
 *$P	pSala: Ponteiro para tipo estruturado sala.
 *$P	maxAlunos: Capacidade m∑xima de alunos na sala.
 *$.***********************************************************************/

SAL_tpCondRet SAL_setMaxAlunos (SAL_tpSala * pSala, int maxAlunos);

/***********************************************************************
 *$FC Fun¡Ño: SAL_getMaxAlunos
 *$ED Descri¡Ño da fun¡Ño
 *	Retorna no conte?do de um ponteiro a capacidade m∑xima de alunos da sala fornecida.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 *	SAL_CondRetErroEstrutura
 *$EP Parametros
 *$P	pSala: Ponteiro para tipo estruturado sala.
 *$P	maxAlunos: Capacidade m∑xima de alunos na sala.
 *$.***********************************************************************/

SAL_tpCondRet SAL_getMaxAlunos (SAL_tpSala * pSala, int *maxAlunos);

/***********************************************************************
 *$FC Fun¡Ño: SAL_setELaboratorio
 *$ED Descri¡Ño da fun¡Ño
 *	Insere um inteiro (1 se sim, 0 se nÑo) na dependÕncia se a sala fornecida » laborat€rio.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetErroEstrutura
 *	SAL_CondRetRecebeuPonteiroNulo
 *$EP Parametros
 *$P	pSala: ponteiro para tipo estruturado sala.
 *$P	eLaboratorio: Indicador de que a sala » laborat€rio (1 se sim, 0 se nÑo)
 *$.***********************************************************************/

SAL_tpCondRet SAL_setELaboratorio (SAL_tpSala * pSala, int eLaboratorio);

/***********************************************************************
 *$FC Fun¡Ño: SAL_getELaboratorio
 *$ED Descri¡Ño da fun¡Ño
 *	Retorna se a sala fornecida » um laborat€rio em um ponteiro (1 se sim, 0 se nÑo).
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetErroEstrutura
 *	SAL_CondRetRecebeuPonteiroNulo
 *$EP Parametros
 $P	pSala: ponteiro para tipo estruturado sala.
 $P	eLaboratorio: Indicador de que a sala » laborat€rio (1 se sim, 0 se nÑo).
 *$.***********************************************************************/

SAL_tpCondRet SAL_getELaboratorio (SAL_tpSala * pSala, int *eLaboratorio);

/***********************************************************************
 *$FC Fun¡Ño: SAL_getNumero
 *$ED Descri¡Ño da fun¡Ño
 *	Pega numero da sala fornecida e coloca no conte?do de um ponteiro.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 *	SAL_CondRetErroEstrutura
 *$EP Parametros
 *$P	pSala: ponteiro para tipo estruturado sala.
 *$P	numero: numero da sala a ser retornado pela fun¡Ño.
 *$.***********************************************************************/

SAL_tpCondRet SAL_getNumero (SAL_tpSala * pSala, int *numero);

/***********************************************************************
 *$FC Fun¡Ño: SAL_getPredio
 *$ED Descri¡Ño da fun¡Ño
 *	Pega predio da sala.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetErroEstrutura
 *	SAL_CondRetRecebeuPonteiroNulo
 *$EP Parametros
 *$P	pSala: ponteiro para tipo estruturado sala.
 *$P	predio: string para retornar pr»dio da sala fornecida.
 *$.************************************************************************/

SAL_tpCondRet SAL_getPredio (SAL_tpSala * pSala, char *predio);

/***********************************************************************
 *$FC Fun¡Ño: SAL_getAndar
 *$ED Descri¡Ño da fun¡Ño
 *	Pega andar da sala.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetErroEstrutura
 *	SAL_CondRetRecebeuPonteiroNulo
 *$EP Parametros
 *$P	pSala: ponteiro para tipo estruturado sala.
 *$P	andar: andar da sala fornecida.
 *$.***********************************************************************/

SAL_tpCondRet SAL_getAndar (SAL_tpSala * pSala, int *andar);

/***********************************************************************
 *$FC Fun¡Ño: SAL_reservaSala
 *$ED Descri¡Ño da fun¡Ño
 *	Reserva a sala em um determinado dia em um determinado intervalo.
 *
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 *	SAL_CondRetErroAoReservar
 *	SAL_CondRetParamInvalido
 *$EP Parametros
 *$P	pSala: ponteiro para tipo estruturado sala.
 *$P	dia
 *$P	horaInicio: inÃcio do intervalo de tempo a ser reservado pela aula na sala.
 *$P	horaFim: fim do intervalo de tempo a ser reservado pela aula na sala.
 *$.***********************************************************************/

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim);


/***********************************************************************
 *$FC Fun¡Ño: SAL_liberaSala
 *$ED Descri¡Ño da fun¡Ño
 *	Libera a sala em um determinado dia em um determinado intervalo de tempo.
 *
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 *	SAL_CondRetErroAoLiberar
 *	SAL_CondRetParamInvalido
 *$EP Parametros
 *$P	pSala: ponteiro para tipo estruturado sala.
 *$P	dia
 *$P	horaInicio: inÃcio do intervalo de tempo a ser liberado da aula na sala.
 *$P	horaFim: fim do intervalo de tempo a ser liberado da aula na sala.
 *$.***********************************************************************/

SAL_tpCondRet SAL_liberaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim);

/***********************************************************************
 *$FC Fun¡Ño: SAL_resetDisponibilidade
 *$ED Descri¡Ño da fun¡Ño
 *	Reseta a matriz disponibilidade (todos horarios disponiveis).
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 * SAL_CondRetErroAoLiberar
 *$EP Parametros
 *$P	pSala: ponteiro para tipo estruturado sala.
 *$.***********************************************************************/

SAL_tpCondRet SAL_resetDisponibilidade (SAL_tpSala * pSala);

/***********************************************************************
 *$FC Fun¡Ño: SAL_printDisponibilidade
 *$ED Descri¡Ño da fun¡Ño
 *	Imprime a matriz disponibilidade da Sala com XXXXXX quando
 *	estiver ocupada e ------ quando livre.
 *$FV Valor retornado
 *	SAL_CondRetOK
 *	SAL_CondRetRecebeuPonteiroNulo
 *	SAL_CondRetErroEstrutura
 *$EP ParÇmetros
 *$P pSala: ponteiro para tipo estruturado sala.
 ***********************************************************************/

SAL_tpCondRet SAL_printDisponibilidade(SAL_tpSala * pSala);

/***********************************************************************
 *$FC Fun¡Ño: SAL_getHorarioNoDia
 *$ED Descri¡Ño da fun¡Ño
 *	Pega hor∑rio da sala fornecida no dia especificado.
 *$FV Valor retornado
 *	SAL_CondRetOK, se a fun¡Ño for concluÃda com sucesso
 *	SAL_CondRetRecebeuPonteiroNulo, se a sala recebida for nula
 *	SAL_CondRetParamInvalido, se:
 *	  1. O hor∑rio de inÃcio for maior ou igual ao hor∑rio de fim;
 *	  2. Se algum dos hor∑rios nÑo estiver compreendido no perÃodo de 7 a 22 horas
 *	  durante o qual as aulas ocorrem;
 *$EP	ParÇmetros
 *$PpSala: ponteiro para a sala desejada
 *$P	dia: valor inteiro entre 0 e 5 (ambos inclusive) representando um dos dias da semana
 *	de segunda a s∑bado (0 = segunda, 1 = ter¡a, ..., 5 = s∑bado)
 *$P	horarioInicio: valor entre 7 e 22 representando o hor∑rio de inÃcio do perÃodo a ser
 *	verificado
 *$P	horarioFim: valor entre 7 e 22 representando o hor∑rio de fim do perÃodo a ser verificado
 *$P	estaDisponivel: ponteiro para uma vari∑vel inteira onde ser∑ armazenado 1 se o intervalo
 *	selecionado estiver disponÃvel, 0 se nÑo estiver.
 *$.***********************************************************************/

SAL_tpCondRet SAL_getHorarioNoDia(SAL_tpSala * pSala, int dia, int horarioInicio, int horarioFim);

#undef SALA_EXT

/********** Fim do m€dulo de defini¡Ño: M€dulo Sala **********/

#else
#endif

