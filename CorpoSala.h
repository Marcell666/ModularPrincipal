#if ! defined( CORPO_SALA_H )
#define CORPO_SALA_H 
/***************************************************************************
 *
 *  $MCD Modulo de definicao: CDS  Corpo de Sala
 *
 *  Arquivo gerado:             CorpoSala.h
 *  Letras identificadoras:     CDS
 *
 *  Nome da base de software:    Arcabouco para a automacao de testes de programas redigidos em C
 *  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
 *
 *  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
 *  Gestor:  LES/DI/PUC-Rio
 *  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathalia
 *
 *  $HA Histórico de evolução:
 *     Versão  Autor    Data     Observaушes
 *     2       cgln  02/nov/2017 unificacao de todos os modulos em um só projeto
 *     1       cgln  31/out/2017 inicio desenvolvimento
 *
 *  $ED Descrição do módulo
 *     Este modulo implementa um conjunto de funções para criar e manipular o corpo de salas.
 *
 ***************************************************************************/

/***** Declarações exportadas pelo módulo *****/


#define CDS_TAM_COD 6
#define CDS_TAM_STRING 81


/* Tipo referência para lista de salas */

	typedef struct corposala CorpoSala ;

/***********************************************************************
 *  
 *  $TC Tipo de dados: CDS Condições de retorno
 *
 *
 *  $ED Descrição do tipo
 *     Condições de retorno das funções do corpo de salas.
 *
 ***********************************************************************/

	typedef enum {
    
		CDS_CondRetOK ,
		/* Concluiu corretamente */
    
		CDS_CondRetFaltouMemoria ,
		/* Faltou memoria ao tentar criar o corpo de salas */
    
		CDS_CondRetSalaJaCadastrada ,
		/* A sala ja foi cadastrada */
    
		CDS_CondRetSalaNaoCadastrada ,
		/* A sala nao foi cadastrada */
    
		CDS_CondRetCDSVazio,
		/* O corpo de salas esta vazio */
		
		CDS_CondRetParametroInvalido
		/* Recebeu parametro invalidos para cadastrar uma sala */
    
	} CDS_tpCondRet ;

/***********************************************************************
 *
 *  $FC Função: CDS &Cria 
 *
 *  $ED Descricao da funcao:
 *     Cria uma lista de salas.
 *     Alocando o espaco da mesma na memoria.
 *
 *  $EP Parametros --
 *
 *  $FV Valor retornado
 *    CDS_CondRetFaltouMemoria
 *    CDS_CondRetOK
 *
 *  Assertiva de Entrada: 
 *               - A função CDS_CriaCorpoSala ainda não foi chamada.
 *
 *  Assertiva de Saida: 
 *               - Lista de salas criada.
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_cria () ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Insere
 *
 *  $ED Descricao da funcao:
 *     Insere uma sala na lista de salas.
 *     Verifica pelo codigo da sala se a mesma a foi criada.
 *
 *  $EP Parametros
 *      $P codigo - ponteiro para o codigo da sala.
 *      $P maxAlunos - quantidade maxima de alunos que aquela sala suporta.
 *      $P eLaboratorio - numero que identifica se a sala e laboratorio ou nao.
 *
 *  $FV Valor retornado
 *    CDS_CondRetSalaJaCadastrada
 *    CDS_CondRetFaltouMemoria
 *    CDS_CondRetOK
 *
 *  Assertiva de Entrada: 
 *               - A função recebe valores validos para salas.
 *
 *  Assertiva de Saida: 
 *               - Elemento da lista de salas e preenchido com os valores recebidos.
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_insere ( char * codigo, int maxAlunos, int eLaboratorio ) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Retira Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Retira uma sala da lista de salas.
 *     Verifica pelo codigo da sala se a mesma não foi cadastrada.
 *
 *  $EP Parametros
 *      $P codigo - ponteiro para o codigo da sala que deseja-se retirar.
 *
 *  $FV Valor retornado
 *    CDS_CondRetSalaNaoCadastrada
 *    CDS_CondRetOK
 *
 *  Assertiva de entrada: 
 *               - Codigo de sala valido.
 *
 *  Assertiva de Saida: 
 *               - Sala com o codigo informado retirada.
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_retira ( char * codigo ) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Exibe Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Exibe o Corpo de Salas.
 *
 *  $EP Parametros --
 *
 *  $FV Valor retornado
 *    CDS_CondRetCDSVazio
 *    CDS_CondRetOK
 *
 *  Assertiva de Entrada: 
 *               - Uma lista de salas existe.
 *
 *  Assertiva de Saida:
 *               - Lista de salas é exibida caso possua salas ou isso e informado. 
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_exibe () ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Libera Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Libera o Corpo de Sala.
 *
 *  $EP Parametros --
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *
 *  Assertiva de Entrada: 
 *               - Uma lista de salas existe.
 *
 *  Assertiva de Saida: 
 *               - Lista de salas e excluida.
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_libera () ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Limpa Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Exclui todos os nós da lista de Corpo de Sala.
 *
 *  $EP Parametros --
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetCDSVazio
 *
 *  Assertiva de Entrada: 
 *               - Lista de salas existe.
 *
 *  Assertiva de Saida:
 *               - Todos os nós da lista de salas são excluidos mantendo apenas a cabeca.
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_limpa () ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Get Qtd Max Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Acessa a quantidade maxima de alunos em uma sala buscada pelo codigo.
 *     Verifica se a sala e cadastrada.
 *
 *  $EP Parametros
 *      $P max - ponteiro para a quantidade maxima de alunos que aquela sala suporta.
 *      $P cod - codigo para buscar a sala que se deseja acessar.
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetSalaNaoCadastrada
 *
 *  Assertiva de Entrada: 
 *               - Código de sala válido.
 *               - Ponteiro válido do tipo int.
 *
 *  Assertiva de Saida: 
 *               - Caso o código de seja encontrado o ponteiro do tipo int possui a capacidade maxima de alunos daquela sala.
 *               - Caso o código não seja encontrado o ponteiro do tipo int permanece vazio. 
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_getQtdMax ( int * max, char * cod ) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Get Tipo Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Acessa o tipo de uma sala buscada pelo codigo.
 *     Verifica se a sala e cadastrada.
 *
 *  $EP Parametros
 *      $P tipo - ponteiro para o tipo daquela sala (laboratorio ou nao).
 *      $P cod - codigo para buscar a sala que se deseja acessar.
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetSalaNaoCadastrada
 *
 *  Assertiva de Entrada:
 *               - Ponteiro válido do tipo int.
 *               - Código de sala válido. 
 *
 *  Assertiva de Saida: 
 *               - Caso o código de seja encontrado o ponteiro do tipo int possui o tipo da daquela sala.
 *               - Caso o código não seja encontrado o ponteiro do tipo int permanece vazio. 
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_getTipo ( int * tipo, char * cod ) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Get Num Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Acessa o numero de uma sala buscada pelo codigo.
 *     Verifica se a sala e cadastrada.
 *
 *  $EP Parametros
 *      $P num - ponteiro para o numero daquela sala.
 *      $P cod - codigo para buscar a sala que se deseja acessar.
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetSalaNaoCadastrada
 *
 *  Assertiva de Entrada: 
 *               - Ponteiro válido do tipo int.
 *               - Código de sala válido. 
 *
 *  Assertiva de Saida:
 *               - Caso o código de seja encontrado o ponteiro do tipo int possui o numero daquela sala.
 *               - Caso o código não seja encontrado o ponteiro do tipo int permanece vazio. 
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_getNum ( int * num, char * cod) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Get Predio Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Acessa o predio de uma sala buscada pelo codigo.
 *     Verifica se a sala e cadastrada.
 *
 *  $EP Parametros
 *      $P predio - ponteiro para o predio daquela sala.
 *      $P cod - codigo para buscar a sala que se deseja acessar.
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetSalaNaoCadastrada
 *
 *  Assertiva de Entrada: 
 *               - Ponteiro válido do tipo char.
 *               - Código de sala válido. 
 *
 *  Assertiva de Saida:
 *               - Caso o código de seja encontrado o ponteiro do tipo char possui o prédio daquela sala.
 *               - Caso o código não seja encontrado o ponteiro do tipo char permanece vazio. 
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_getPredio ( char * predio, char * cod ) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Get Andar Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Acessa o andar de uma sala buscada pelo codigo.
 *     Verifica se a sala e cadastrada.
 *
 *  $EP Parametros
 *      $P andar - ponteiro para o andar daquela sala.
 *      $P cod - codigo para buscar a sala que se deseja acessar.
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetSalaNaoCadastrada
 *
 *  Assertiva de Entrada: 
 *               - Ponteiro válido do tipo char.
 *               - Código de sala válido. 
 *
 *  Assertiva de Saida: 
 *               - Caso o código de seja encontrado o ponteiro do tipo char possui andar daquela sala.
 *               - Caso o código não seja encontrado o ponteiro do tipo char permanece vazio. 
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_getAndar ( int * andar, char * cod ) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Exibe Disponibilidade Corpo Sala
 *
 *  $ED Descricao da funcao:
 *     Exibe a disponibilidade de horario de uma sala buscada pelo codigo.
 *     Verifica se a sala e cadastrada.
 *
 *  $EP Parametros
 *      $P cod - codigo para buscar a sala que se deseja exibir a disponibilidade.
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetSalaNaoCadastrada
 *
 *  Assertiva de Entrada: 
 *               - Código de sala válido.
 *
 *  Assertiva de Saida: 
 *               - Caso o código de seja encontrado exibe no prompt  uma matriz com a disponibilidade daquela sala.
 *               - Caso o código não seja encontrado não exibe no prompt a disponibilidade daquela sala. 
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_exibeDisponibilidade ( char * cod ) ;

/***********************************************************************
 *
 *  $FC Funcao: CDS &Reserva Sala
 *
 *  $ED Descricao da funcao:
 *     Reserva uma sala.
 *     Verifica se a sala e cadastrada.
 *
 *  $EP Parametros
 *      $P dia- dia da semana que se deseja reservar a sala.
 *      $P horini- horario de inicio que se deseja reservar a sala.
 *      $P horfim- horario de fim que se deseja reservar a sala.
 *      $P qtd- quantidade maxima de alunos que a sala desejada precisa comportar.
 *      $P lab- tipo de sala que se deseja reservar (laboratorio ou nao laboratorio).
 *
 *  $FV Valor retornado
 *    CDS_CondRetOK
 *    CDS_CondRetSalaNaoCadastrada
 *
 *  Assertiva de Entrada:
 *               - parametro dia esta entre 0(seg) e 5(sab).
 *               - horaini e horfim entre 7 e 23.
 *               - lab sendo 0 ou 1.
 *
 *  Assertiva de Saida: 
 *               - A disponiblidade da sala que possuem parametros recebidos e alterada para reservado.
 *
 ***********************************************************************/

	CDS_tpCondRet CDS_reservaSala ( int dia, int horini, int horfim, int qtd, int lab ) ;

/********** Fim do modulo de definicao: Modulo Corpo de Salas **********/

#endif
