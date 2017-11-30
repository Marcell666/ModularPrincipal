#pragma once
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Corpo Discente
*
*  Arquivo gerado:              corpodiscente.h
*  Letras identificadoras:      CDI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acad�mico da turma 3WB
*  Gestor:  Grupo 2
*  Autores:   Fl�vio Thiago Franco Vaz
*             Bruno Miranda Marinho
*             Matheus Henrique Branco Zeitune
*             Jo�o Victor Cerqueira
*             Vin�cius Cortat
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data			Observa��es
*     0.01    Fl�vio   01/10/2017	In�cio do desenvolvimento
*     0.02    Fl�vio   02/10/2017   Reparo nas fun��es cria e remove
*     0.03    Fl�vio   02/10/2017   Implementa��o das fun��es altera e deleta
*     0.04    Fl�vio   03/10/2017   Reparo nas fun��es altera e insere
*     0.05    Fl�vio   04/10/2017   Implementa��o da fun��o limpa
*  $ED Descri��o do m�dulo
*     Este m�dulo implementa o Corpo Discente do Sistema Acad�mico a ser desenvolvido.
*     O Corpo Discente � uma lista de Alunos da universidade.
***************************************************************************/

#include "aluno.h"

/***** Declara��es exportadas pelo m�dulo *****/

	#define  CDI_DADOS_PATH "dadosCDI.txt"

/***********************************************************************
*
*  $TC Tipo de dados: CDI Condi��es de retorno
*
*
***********************************************************************/
typedef enum {
	CDI_CondRetOK,	// Executou corretamente
	CDI_CondRetAlunoNaoCadastrado,	// O aluno n�o est� cadastrado
	CDI_CondRetAlunoJaCadastrado,	// O aluno j� foi cadastrado
	CDI_CondRetAlunoNaoEncontrado, // O aluno n�o foi encontrado
	CDI_CondRetFaltouMemoria,	// Faltou mem�ria ao alocar dados
	CDI_CondRetCDIVazio, // Corpo Discente vazio
	CDI_CondRetErroAbrirArquivo
		/* Condicao de Retorno Erro Abrir Arquivo, usada quando ocorrer erro ao abrir arquivo com os dados pessoais dos alunos. */
} CDI_tpCondRet;
/***********************************************************************
*
*  $TD	Typedef
*			Para que outros m�dulos conhe�am a existencia da struct.
*
***********************************************************************/
typedef struct corpodisc CorpoDisc;

/***********************************************************************
*
*  $FC Fun��o: CDI cria
*
*  $ED Descri��o da fun��o
*		Cria lista de Alunos do Corpo Discente.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetFaltouMemoria caso n�o consiga criar a lista do
/								 corpo discente e CDI_CondRetOK caso contr�rio.
/			 Par�mentros: N�o h� passagem de par�metros.
***********************************************************************/
CDI_tpCondRet CDI_cria(void);
/***********************************************************************
*
*  $FC Fun��o: CDI remove
*
*  $ED Descri��o da fun��o
*		Varre a lista do Corpo Discente procurando Aluno com matr�cula igual ao valor de matbusca e o remove da lista.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetAlunoNaoCadastrado caso n�o consiga encontrar o aluno
/                                com matr�cula matbusca na lista do corpo discente e CDI_CondRetOK
/                                caso contr�rio.
/			 Par�mentros: Um inteiro para matr�cula do Aluno a ser removido.
***********************************************************************/
CDI_tpCondRet CDI_remove(unsigned int matbusca);
/***********************************************************************
*
*  $FC Fun��o: CDI imprime
*
*  $ED Descri��o da fun��o
*		Imprime na tela o Corpo Discente.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetCDIVazio caso a lista do corpo discente
/								 esteja vazia e CDI_CondRetOK caso contr�rio.
/			 Par�mentros: N�o h� passagem de par�metros.
***********************************************************************/
CDI_tpCondRet CDI_imprime(void);
/***********************************************************************
*
*  $FC Fun��o: CDI insere
*
*  $ED Descri��o da fun��o
*		Cria e insere um Aluno no final da lista do Corpo Discente.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetAlunoJaCadastrado caso j� haja um Aluno com matr�cula
/                                 igual � passada como par�metro cadastrado no CDI e ALN_CondRetOK caso contr�rio.
/			 Par�mentros: Uma string para nome, um inteiro para matr�cula, um ponteiro para CPF(struct) para cpf, um inteiro
/                         para telefone,um ponteiro para Data(struct) para data de nascimento e um ponteiro para Endereco(struct) para endere�o.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_insere(char *nome, unsigned int mat, struct cpf *cpf, unsigned int telefone, struct data *nasc, struct endereco* end);
/***********************************************************************
*
*  $FC Fun��o: CDI altera
*
*  $ED Descri��o da fun��o
*		Percorre a lista procurando pelo Aluno com matr�cula igual a matbusca e altera os dados passados que sejam diferentes de NULL.
*		Caso n�o queira alterar um dado, basta passar NULL no par�metro que se manter� inalterado.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetAlunoNaoCadastrado caso n�o haja um Aluno com matr�cula
/                                 igual � passada como par�metro cadastrado no CDI e ALN_CondRetOK caso contr�rio.
/			 Par�mentros: Um inteiro para matr�cula a ser buscada, uma string para novo nome, um inteiro para nova matr�cula, um ponteiro para novo CPF(struct) para cpf, um inteiro
/                         para novo telefone, um ponteiro para nova Data(struct) para data de nascimento e um ponteiro para novo Endereco(struct) para endere�o.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_altera(int matbusca, char *nome, unsigned int mat, struct cpf *cpf, unsigned int telefone, struct data *nasc, struct endereco *end);
/***********************************************************************
*
*  $FC Fun��o: CDI deleta
*
*  $ED Descri��o da fun��o
*		Limpa todo o corpo discente e ent�o o deleta.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetOK ao deletar.
/			 Par�mentros: N�o h� passagem de par�metros.
***********************************************************************/
CDI_tpCondRet CDI_deleta(void);
/***********************************************************************
*
*  $FC Fun��o: CDI imprime Info
*
*  $ED Descri��o da fun��o
*		Imprime na tela os dados do Aluno com matr�cula igual a matbusca.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetAlunoNaoCadastrado caso n�o haja um Aluno com matr�cula
/                                 igual � passada como par�metro cadastrado no CDI e ALN_CondRetOK caso contr�rio.
/			 Par�mentros:        Um inteiro para matr�cula do aluno cujos dados devem ser impressos.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_imprimeInfo(unsigned int matbusca);
/***********************************************************************
*
*  $FC Fun��o: CDI limpa
*
*  $ED Descri��o da fun��o
*		Limpa todos os alunos do corpo discente, mas o mant�m.
*
***********************************************************************/
/*Assertivas: Retorno da fun��o: CDI_CondRetCDIVazio caso a lista do corpo discente
/								 esteja vazia e CDI_CondRetOK caso contr�rio.
/			 Par�mentros: N�o h� passagem de par�metros.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_limpa(void);

CDI_tpCondRet CDI_busca(unsigned int matbusca, Aluno** alu);

CDI_tpCondRet CDI_leDados(char *path) ;

CDI_tpCondRet CDI_salvaDados(char *path) ;

