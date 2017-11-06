/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Disciplina
*
*  Arquivo gerado:              Disciplina.h
*  Letras identificadoras:      DIS
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 4
*  Autores: mrol - Matheus Rodrigues de Oliveira Leal
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       0.01   mrol   30/08/2017 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Este módulo implementa um conjunto simples de funções para criar e
*      explorar as DISiplinas do sistema acadêmico.
*     Uma disciplina deverá ter um código que a identifica.
*     A cada momento o módulo admite no máximo uma única Disciplina.
*     Ao iniciar a execução do programa não existe DISiplinas.
*     Uma disciplina deverá ter um critério de avaliação, que será um código que se *refere a uma forma de calcular a média final para poder determinar se um aluno *está aprovado ou não.
***************************************************************************/
#include "turma.h"
typedef struct disciplina Disciplina;
/***********************************************************************
*
*  $TC Tipo de dados: DIS ConDISoes de retorno
*
*
***********************************************************************/

   typedef enum {
     DIS_CondRetOK = 0 ,
       /* Executou correto */

     DIS_CondRetErroEstrutura = 1 ,
      /* Estrutura da Disciplina está errada */
     DIS_CondRetDisciplinaCriada = 2,
     /* Estrutura da Disciplina está criada */
     DIS_CondRetDisciplinaDeletada = 3,
     /* Estrutura da Disciplina está deletada */
     DIS_CondRetFaltouMemoria = 4 ,
     /* Faltou memória ao alocar dados */
     DIS_CondRetCreditoNegativo = 5,
		 /* Creditos negativo fornecido */
     DIS_CondRetOKEstrutura = 6,
     /* Estrutura da Disciplina está correta */
     DIS_CondRetParametroInvalido = 7
	  /* Erro no parametro da disciplina */

   }DIS_tpCondRet;
/***********************************************************************
*
*  $FC Função: DIS obter creditos
*
*  $ED Descrição da função
*    Retorna o creditos.
*
***********************************************************************/
DIS_tpCondRet DIS_get_creditos(Disciplina* dis, int* creditos);
/***********************************************************************
*
*  $FC Função: DIS altera creditos
*
*  $ED Descrição da função
*    Altera os creditos de uma disciplina.
*
***********************************************************************/
DIS_tpCondRet DIS_altera_creditos(Disciplina* dis, int creditos);
/***********************************************************************
*
*  $FC Função: DIS obter nome
*
*  $ED Descrição da função
*    Retorna o nome.
*
***********************************************************************/
DIS_tpCondRet DIS_get_nome(Disciplina* dis, char** nome);
/***********************************************************************
*
*  $FC Função: DIS obter codigo
*
*  $ED Descrição da função
*    Retorna o codigo.
*
***********************************************************************/
DIS_tpCondRet DIS_get_codigo(Disciplina* dis, char** codigo);
/***********************************************************************
*
*  $FC Função: DIS obter bibliografia
*
*  $ED Descrição da função
*    Retorna a bibliografia
*
***********************************************************************/
DIS_tpCondRet DIS_get_bibliografia(Disciplina* dis, char** bibliografia);
/***********************************************************************
*
*  $FC Função: DIS altera bibliografia
*
*  $ED Descrição da função
*    Altera a biliografia de uma disciplina.
*
***********************************************************************/
DIS_tpCondRet DIS_altera_bibliografia(Disciplina* dis, char* bibliografia);
/***********************************************************************
*
*  $FC Função: DIS obter ementa
*
*  $ED Descrição da função
*    Retorna a ementa
*
*
***********************************************************************/
DIS_tpCondRet DIS_get_ementa(Disciplina* dis, char** ementa);
/***********************************************************************
*
*  $FC Função: DIS altera ementa
*
*  $ED Descrição da função
*    Altera a ementa da disciplina.
*
***********************************************************************/
DIS_tpCondRet DIS_altera_ementa(Disciplina *dis, char *ementa);
/***********************************************************************
*
*  $FC Função: DIS altera criterio
*
*  $ED Descrição da função
*    Altera o criterio de aprovação de uma disciplina.
*
***********************************************************************/
DIS_tpCondRet DIS_altera_criterio(Disciplina *d, int critAprov);
/***********************************************************************
*
*  $FC Função: DIS obter por meio do teclado
*
*  $ED Descrição da função
*    Função: DIS gera uma disciplina por input do teclado
*
***********************************************************************/
DIS_tpCondRet DIS_gera_cmd(Disciplina** d);
/***********************************************************************
*
*  $FC Função: DIS gera por meio de parametros
*
*  $ED Descrição da função
*    DIS gera uma disciplina recebendo parâmetros externos
*
***********************************************************************/
DIS_tpCondRet DIS_gera_param(Disciplina** d, char* nome, char* codigo, int creditos, char* bibliografia, char* ementa, int critAprov);
/***********************************************************************
*
*  $FC Função: DIS exibe disciplina
*
*  $ED Descrição da função
*    DIS exibe os parametros de disciplina
*
***********************************************************************/
DIS_tpCondRet DIS_exibe(Disciplina* d);
/***********************************************************************
*
*  $FC Função: DIS deleta Disciplina
*
*  $ED Descrição da função
*    Deleta disciplina recebida como parâmetro
*
***********************************************************************/
DIS_tpCondRet DIS_deleta_Disciplina (Disciplina **d);
/***********************************************************************
*
*  $FC Função: DIS insere turma para a disciplina
*
*  $ED Descrição da função
*    Insere uma turma para a lista da disciplina
*
***********************************************************************/
DIS_tpCondRet DIS_insere_turma(Disciplina **d, Turma **t);
/***********************************************************************
*
*  $FC Função: DIS limpa lista de turmas para a disciplina
*
*  $ED Descrição da função
*    Limpa a lista de turmas da disciplina
*
***********************************************************************/
DIS_tpCondRet DIS_limpa_turma(Disciplina **d);
/***********************************************************************
*
*  $FC Função: DIS exibe lista de turmas para a disciplina
*
*  $ED Descrição da função
*    Exibe a lista de turmas da disciplina
*
***********************************************************************/
DIS_tpCondRet DIS_exibe_todas_turmas(Disciplina **d);
/***************************************************************************
*
*  $FC Função: DIS retornar media e situação do aluno
*
*  $ED Descrição da função
*    retorna a media e a situação do aluno
*
*	*****/
DIS_tpCondRet DIS_situacaoAluno(Disciplina* disc,float G1,float G2,float G3,float G4, float* media, int*situacao);