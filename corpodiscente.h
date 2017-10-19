/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Corpo Discente
*
*  Arquivo gerado:              corpodiscente.h
*  Letras identificadoras:      CDI
*
*  Nome da base de software:
*  Arquivo da base de software:
*
*  Projeto: Sistema Acadêmico da turma 3WB
*  Gestor:  Grupo 2
*  Autores:   Flávio Thiago Franco Vaz
*             Bruno Miranda Marinho
*             Matheus Henrique Branco Zeitune
*             João Victor Cerqueira
*             Vinícius Cortat
*  $HA Histórico de evolução:
*     Versão  Autor    Data			Observações
*     0.01    Flávio   01/10/2017	Início do desenvolvimento
*     0.02    Flávio   02/10/2017   Reparo nas funções cria e remove
*     0.03    Flávio   02/10/2017   Implementação das funções altera e deleta
*     0.04    Flávio   03/10/2017   Reparo nas funções altera e insere
*     0.05    Flávio   04/10/2017   Implementação da função limpa
*  $ED Descrição do módulo
*     Este módulo implementa o Corpo Discente do Sistema Acadêmico a ser desenvolvido.
*     O Corpo Discente é uma lista de Alunos da universidade.
***************************************************************************/

#include "aluno.h"

#ifndef CORPODISCENTE_H
#define CORPODISCENTE_H


/***********************************************************************
*
*  $TC Tipo de dados: CDI Condições de retorno
*
*
***********************************************************************/
typedef enum {
	CDI_CondRetOK,	// Executou corretamente
	CDI_CondRetAlunoNaoCadastrado,	// O aluno não está cadastrado
	CDI_CondRetAlunoJaCadastrado,	// O aluno já foi cadastrado
	CDI_CondRetAlunoNaoEncontrado, // O aluno não foi encontrado
	CDI_CondRetFaltouMemoria,	// Faltou memória ao alocar dados
	CDI_CondRetCDIVazio // Corpo Discente vazio
} CDI_tpCondRet;
/***********************************************************************
*
*  $TD	Typedef
*			Para que outros módulos conheçam a existencia da estrutura.
*
***********************************************************************/
typedef struct corpodisc CorpoDisc;

/***********************************************************************
*
*  $FC Função: CDI cria
*
*  $ED Descrição da função
*		Cria lista de Alunos do Corpo Discente.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetFaltouMemoria caso não consiga criar a lista do
/								 corpo discente e CDI_CondRetOK caso contrário.
/			 Parâmentros: Não há passagem de parâmetros.
***********************************************************************/
CDI_tpCondRet CDI_cria(void);
/***********************************************************************
*
*  $FC Função: CDI remove
*
*  $ED Descrição da função
*		Varre a lista do Corpo Discente procurando Aluno com matrícula igual ao valor de matbusca e o remove da lista.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetAlunoNaoCadastrado caso não consiga encontrar o aluno
/                                com matrícula matbusca na lista do corpo discente e CDI_CondRetOK
/                                caso contrário.
/			 Parâmentros: Um inteiro para matrícula do Aluno a ser removido.
***********************************************************************/
CDI_tpCondRet CDI_remove(unsigned int matbusca);
/***********************************************************************
*
*  $FC Função: CDI imprime
*
*  $ED Descrição da função
*		Imprime na tela o Corpo Discente.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetCDIVazio caso a lista do corpo discente
/								 esteja vazia e CDI_CondRetOK caso contrário.
/			 Parâmentros: Não há passagem de parâmetros.
***********************************************************************/
CDI_tpCondRet CDI_imprime(void);
/***********************************************************************
*
*  $FC Função: CDI insere
*
*  $ED Descrição da função
*		Cria e insere um Aluno no final da lista do Corpo Discente.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetAlunoJaCadastrado caso já haja um Aluno com matrícula
/                                 igual à passada como parâmetro cadastrado no CDI e ALN_CondRetOK caso contrário.
/			 Parâmentros: Uma string para nome, um inteiro para matrícula, um ponteiro para CPF(struct) para cpf, um inteiro
/                         para telefone,um ponteiro para Data(struct) para data de nascimento e um ponteiro para Endereco(struct) para endereço.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_insere(char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco* end);
/***********************************************************************
*
*  $FC Função: CDI altera
*
*  $ED Descrição da função
*		Percorre a lista procurando pelo Aluno com matrícula igual a matbusca e altera os dados passados que sejam diferentes de NULL.
*		Caso não queira alterar um dado, basta passar NULL no parâmetro que se manterá inalterado.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetAlunoNaoCadastrado caso não haja um Aluno com matrícula
/                                 igual à passada como parâmetro cadastrado no CDI e ALN_CondRetOK caso contrário.
/			 Parâmentros: Um inteiro para matrícula a ser buscada, uma string para novo nome, um inteiro para nova matrícula, um ponteiro para novo CPF(struct) para cpf, um inteiro
/                         para novo telefone, um ponteiro para nova Data(struct) para data de nascimento e um ponteiro para novo Endereco(struct) para endereço.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_altera(int matbusca, char *nome, unsigned int mat, CPF *cpf, unsigned int telefone, Data *nasc, Endereco *end);
/***********************************************************************
*
*  $FC Função: CDI deleta
*
*  $ED Descrição da função
*		Limpa todo o corpo discente e então o deleta.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetOK ao deletar.
/			 Parâmentros: Não há passagem de parâmetros.
***********************************************************************/
CDI_tpCondRet CDI_deleta(void);
/***********************************************************************
*
*  $FC Função: CDI imprime Info
*
*  $ED Descrição da função
*		Imprime na tela os dados do Aluno com matrícula igual a matbusca.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetAlunoNaoCadastrado caso não haja um Aluno com matrícula
/                                 igual à passada como parâmetro cadastrado no CDI e ALN_CondRetOK caso contrário.
/			 Parâmentros:        Um inteiro para matrícula do aluno cujos dados devem ser impressos.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_imprimeInfo(unsigned int matbusca);
/***********************************************************************
*
*  $FC Função: CDI limpa
*
*  $ED Descrição da função
*		Limpa todos os alunos do corpo discente, mas o mantém.
*
***********************************************************************/
/*Assertivas: Retorno da função: CDI_CondRetCDIVazio caso a lista do corpo discente
/								 esteja vazia e CDI_CondRetOK caso contrário.
/			 Parâmentros: Não há passagem de parâmetros.
************************************************************************************************************************************************/
CDI_tpCondRet CDI_limpa(void);
#endif
