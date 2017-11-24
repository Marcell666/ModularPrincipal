/***************************************************************************
*
*  $MCD Módulo de definição: TUR  Turma
*
*  Arquivo gerado:              TURMA.h
*  Letras identificadoras:      TUR
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: cgln - Cristiane - Guilherme - Leonardo - Nathália
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     2       cgln  07/set/2017 unificação de todos os módulos em um só projeto
*     1       cgln  29/ago/2017 início desenvolvimento
*
*  $ED Descrição do módulo
*     Este modulo implementa um conjunto de funcoes para criar e manipular a estrutura turma.
*
***************************************************************************/

/***** Declarações exportadas pelo módulo *****/

/* Tipo referência para uma turma */

	typedef struct turma Turma ;

/***********************************************************************
*
*  $TC Tipo de dados: TUR Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno das funções da turma
*
***********************************************************************/

	typedef enum {

		TUR_CondRetOk ,
			/* Concluiu corretamente */
					
		TUR_CondRetFaltouMemoria ,
			/* Faltou memória ao tentar criar turma */
			
		TUR_CondRetFormatoInvalido ,
			/* Parâmetro com formato inválido */

	} TUR_tpCondRet ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Cria Turma
 *  $ED Descricao da funcao:
 *     Cria uma nova turma.
 *     Inserindo os dados pertinentes a ela.
 *     Caso os horarios nao estejam nos limites estabelecidos de: 07-21 para inicio e de: 09-23 para final, a turma nao e criada.
 *
 *  $EP Parametros
 *     $P NovaTurma - nome do ponteiro do ponteiro para a estrutura turma
 *     $P CodTur - nome do codigo da turma
 *     $P HorIni - horario de inicio da turma
 *     $P HorTer - horario de termino da turma
 *     $P DiaSem - Dias da semana da turma
 *     $P QtdVag - Quantidade de vagas da turma
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *     TUR_CondRetFormatoInvalido
 *     TUR_CondRetFaltouMemoria
 *

 ***********************************************************************/

	TUR_tpCondRet TUR_CriaTurma ( Turma ** NovaTurma, char * CodTur,
		int HorIni, int HorTer, char * DiaSem, int QtdVag ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Altera Horario Inicio
 *  $ED Descricao da funcao:
 *     Altera o horario de inicio de uma turma.
 *     Caso o novo horario que deseja-se alterar nao esteja no limite estabelecido para horario de inicio de uma turma (07-21), o horario nao e alterado.
 *
 *  $EP Parametros
 *     $P tur - nome do ponteiro para a estrutura turma
 *     $P hora1 - novo horario de inicio da turma
 *                 
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *     TUR_CondRetFormatoInvalido
 *

 ***********************************************************************/

	TUR_tpCondRet TUR_AlteraHorarioInicio ( Turma * tur, int hora1 ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Altera Horario Final
 *  $ED Descricao da funcao:
 *     Altera o horario de inicio de uma turma.
 *     Caso o novo horario que deseja-se alterar nao esteja no limite estabelecido para horario final de uma turma (09-23), o horario nao e alterado.
 *
 *  $EP Parametros
 *     $P tur - nome do ponteiro para a estrutura turma
 *     $P hora2 - novo horario final da turma
 *                
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *     TUR_CondRetFormatoInvalido
 *
 *
 ***********************************************************************/

	TUR_tpCondRet TUR_AlteraHorarioFinal ( Turma * tur, int hora2 ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Altera Dia 
 *  $ED Descricao da funcao:
 *     Altera os dias da semana de uma turma.
 *
 *  $EP Parametros
 *     $P tur - nome do ponteiro para a estrutura turma
 *     $P dia - nome do ponteiro de um vetor de char que contem os novos dias de semana da turma
 *               
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *    
 ***********************************************************************/

	TUR_tpCondRet TUR_AlteraDia ( Turma * tur, char * dia ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Altera Codigo
 *  $ED Descricao da funcao:
 *     Altera o codigo de uma turma.
 *     
 *  $EP Parametros
 *     $P tur - nome do ponteiro para a estrutura turma
 *     $P cod - nome do ponteiro de um vetor de char que contem o novo codigo da turma
 *                
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 ***********************************************************************/

	TUR_tpCondRet TUR_AlteraCodigo ( Turma * tur, char * cod ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Altera Qtd Vaga
 *  $ED Descricao da funcao:
 *     Altera quantidade de vagas de uma turma.
 *     Nao possui limite de vagas.
 *     
 *  $EP Parametros
 *     $P tur - nome do ponteiro para a estrutura turma
 *     $P qtd - nova quantidade de vagas da turma
 *                
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 ***********************************************************************/

	TUR_tpCondRet TUR_AlteraQtdVaga ( Turma * tur, int qtd ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Get Codigo
 *  $ED Descricao da funcao:
 *     Obtem o codigo de uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma que deseja-se obter os dados
 *     $P CodTur - ponteiro para obter nome do codigo da turma
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/

   TUR_tpCondRet TUR_GetCodigo ( Turma * tur, char * CodTur) ;


 /***********************************************************************
 *
 *  $FC Funcao: TUR &Get Hor Ini
 *  $ED Descricao da funcao:
 *     Obtem o horario de inicio de uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma que deseja-se obter os dados
 *     $P HorIni - ponteiro para obter horario de inicio da turma
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/

   TUR_tpCondRet TUR_GetHorIni ( Turma * tur, int * HorIni) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Get Hor Fin
 *  $ED Descricao da funcao:
 *     Obtem o horario final de uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma que deseja-se obter os dados
 *     $P HorTer - ponteiro para obter horario de termino da turma
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/

   TUR_tpCondRet TUR_GetHorFin ( Turma * tur, int * HorTer) ;

   
 /***********************************************************************
 *
 *  $FC Funcao: TUR &Get Dia Sem
 *  $ED Descricao da funcao:
 *     Obtem os dias da semana de uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma que deseja-se obter os dados
 *     $P DiaSem - ponteiro para obter Dias da semana da turma
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/

   TUR_tpCondRet TUR_GetDiaSem ( Turma * tur, char * DiaSem) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Get Qtd Vaga
 *  $ED Descricao da funcao:
 *     Obtem a quantidade de vagas de uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma que deseja-se obter os dados
 *     $P QtdVag - ponteiro para obter Quantidade de vagas da turma
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/
  
   TUR_tpCondRet TUR_GetQtdVaga ( Turma * tur, int * QtdVag ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Get Turma
 *  $ED Descricao da funcao:
 *     Obtem os dados pertencentes a uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma que deseja-se obter os dados
 *     $P CodTur - ponteiro para obter nome do codigo da turma
 *     $P HorIni - ponteiro para obter horario de inicio da turma
 *     $P HorTer - ponteiro para obter horario de termino da turma
 *     $P DiaSem - ponteiro para obter Dias da semana da turma
 *     $P QtdVag - ponteiro para obter Quantidade de vagas da turma
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/

	TUR_tpCondRet TUR_GetTurma ( Turma * tur, char * CodTur,
		int * HorIni, int * HorTer, char * DiaSem, int * QtdVag ) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Exibe Turma
 *  $ED Descricao da funcao:
 *     Exibe os dados pertencentes a uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma a ser exibida
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/

	TUR_tpCondRet TUR_ExibeTurma ( Turma * tur) ;


/***********************************************************************
 *
 *  $FC Funcao: TUR &Exclui Turma
 *  $ED Descricao da funcao:
 *      Exclui uma turma.
 *
 *  $EP Parametros
 *     $P tur - ponteiro para a estrutura turma a ser excluida
 *
 *  $FV Valor retornado
 *     TUR_CondRetOk
 *
 
 ***********************************************************************/

	TUR_tpCondRet TUR_ExcluiTurma ( Turma * turma ) ;

/********** Fim do módulo de definição: Módulo turma **********/
