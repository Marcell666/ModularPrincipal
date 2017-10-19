/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Grade Curricular TODO documentacao
*
*  Arquivo gerado:              corpoDocente.h
*  Letras identificadoras:      GRC
*
*  Nome da base de software:    Fonte do módulo Corpo Docente
*
*  Projeto: Disciplina INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Bruce Marcellino, BM  
*			Felipe Alfena, FA
*			Nicolas Paes, NP
*			Mariana Ruddy, MR
*			Rodrigo Pumar, RP.
*
*  $HA Histórico de evolução:
*     Versão	Autor	Data		Observações
*       0.10   BM	07/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*	  Este módulo implementa um conjunto de funções para criar e manipular uma lista de Instâncias de Professor, ou seja, um Corpo Docente.
*     Ao iniciar a execução do programa não existe nenhuma instância de Corpo Docente.
*     Ao chamar a função criar, uma Lista vazia é criada, precisando assim ter Instâncias de Professores cadastrados.
*     Nenhuma funcao deste modulo deve ser chamada antes da cria();
*	  Deve-se usar a função libera para que a memória alocada seja liberada.
*	  Passar argumentos inválidos como 0 ou "" podem causar erro de formato (GRC_CondRetFormatoInvalido).
*     Esse módulo utiliza funções auxiliares para manipulação de Instâncias de Professor (Ref. professor.h)
*
***************************************************************************/

#ifndef GRADECURRICULAR_H
#define GRADECURRICULAR_H

/***********************************************************************
*
*  $TC Tipo de dados: GRC Condições de retorno
*
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
		/* Condicao de Retorno Corpo Docente Vazio, usada quando a lista de Instância de Professores, ou seja o Corpo Docente, está vazia */ 
	GRC_CondRetDisciplinaNaoEncontrada, 
		/* Condicao de Retorno Professor Não Encontrado, usada quando o Professor não é encontrado numa busca ou quando a lista está vazia quando percorrida */ 
	GRC_CondRetIdJaCriado,
		/* Condicao de Retorno Id Já Criado, usada quando existe outra Instância de Professor no Corpo Docente com o mesmo RG/CPF/matricula/email */ 
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
*     Cria uma instância vazia de Corpo Docente
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
*		-Uma instância de Corpo Docente (Lista de Professores) é criada
*
***********************************************************************/

GRC_tpCondRet GRC_cria();

/***********************************************************************
*
*  $FC Função: GRC Cadastra
*
*  $ED Descrição da função
*     Cadastra um professor em corpo docente com os dados passados
*
*  $EP Parâmetros 
*   
*     $P nome - Nome do Professor que deseja cadastrar no corpo Docente
*     $P rg - RG do Professor que deseja cadastrar no corpo Docente
*     $P cpf - CPF do Professor que deseja buscar no corpo Docente
*     $P matricula - Matricula do Professor que deseja cadastrar no corpo Docente
*     $P email - Email do Professor que deseja cadastrar no corpo Docente
*     $P telefome - Telefone do Professor que deseja cadastrar no corpo Docente
*     $P dia - Dia de nascimento do Professor que deseja cadastrar no corpo Docente
*     $P mes - Mes de nascimento do Professor que deseja cadastrar no corpo Docente
*     $P ano - Ano de nascimento do Professor que deseja cadastrar no corpo Docente
*     $P pais - Pais do endereço do Professor que deseja cadastrar no corpo Docente
*     $P uf - UF do endereço do Professor que deseja cadastrar no corpo Docente 
*     $P cidade - Cidade do endereço do Professor que deseja cadastrar no corpo Docente
*     $P bairro - Bairro do endereço do Professor que deseja cadastrar no corpo Docente
*     $P rua - Rua do endereço do Professor que deseja cadastrar no corpo Docente
*     $P numero - Numero do endereço do Professor que deseja cadastrar no corpo Docente
*     $P complemento - Complemento do endereço do Professor que deseja cadastrar no corpo Docente
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetIdJaCriado - Caso o Professor que deseja cadastrar já está cadastrado nessa instância de Corpo Docente com o mesmo RG/cpf/matricula ou email
*	  GRC_CondRetNaoHaMemoria - Caso não haja memória suficiente para cadastrar o Professor no Corpo Docente
*     GRC_CondRetFormatoInvalido - Caso o formato dos parâmetros não esteja de acordo com o esperado pelo modulo professor
*
*  Assertiva de Entrada: 
*		-O corpo docente já foi instanciado
*                    
*  Assertiva de Saída: 
*		-Uma Instância de Professor é cadastrada no Corpo Docente
*
***********************************************************************/

GRC_tpCondRet GRC_cadastra(char* nome, char* codigo, int creditos, char* bibliografia, char* ementa);

/***********************************************************************
*
*  $FC Função: GRC Mostra Atual
*
*  $ED Descrição da função
*     Mostra a atual Instância de Professor selecionada no Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetCorpoDocenteVazio - Caso a Instância de Corpo Docente esteja vazia
*
*  Assertiva de Entrada: 
*		-O corpo docente foi instanciado
*                    
*  Assertiva de Saída: 
*       -É necessário que a Função PRF_mostra tenha suas assertivas de entrada e saida corretamente implementadas
*		-Mostra-se no Prompt de Comando a atual Instância de Professor selecionada
*
***********************************************************************/

GRC_tpCondRet GRC_mostraAtual();

/***********************************************************************
*
*  $FC Função: GRC Mostra Todos
*
*  $ED Descrição da função
*     Mostra todas as Instância de Professor presentes no Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetCorpoDocenteVazio - Caso a Instância de Corpo Docente esteja vazia
*
*  Assertiva de Entrada: 
*		-Exista um Corpo Docente não vazio
*                    
*  Assertiva de Saída: 
*       -É necessário que a Função PRF_mostra tenha suas assertivas de entrada e saida corretamente implementadas
*		-Mostra-se no Prompt de Comando todas as Instâncias de Professor atualmente no Corpo Docente
*
***********************************************************************/

GRC_tpCondRet GRC_mostraTodas();

/***********************************************************************
*
*  $FC Função: GRC Retira
*
*  $ED Descrição da função
*     Retira a atual Instância de Professor presente no Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetCorpoDocenteVazio - Caso a Instância de Corpo Docente esteja vazia
*
*  Assertiva de Entrada: 
*		-Exista um Corpo Docente não vazio
*                    
*  Assertiva de Saída: 
*		-A atual Instância de Professor é retirada do Corpo Docente
*
***********************************************************************/

GRC_tpCondRet GRC_retira();

/***********************************************************************
*
*  $FC Função: GRC Limpa
*
*  $ED Descrição da função
*     Limpa o corpo Docente retirando todas as Instâncias de Professor presentes
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*
*  Assertiva de Entrada: 
*		O corpo docente ja foi instanciado atraves da função cria
*                    
*  Assertiva de Saída: 
*		-Todas as Instâncias de Professor são retiradas do Corpo Docente
*
***********************************************************************/

GRC_tpCondRet GRC_limpa();

/***********************************************************************
*
*  $FC Função: GRC Libera
*
*  $ED Descrição da função
*     Libera o espaço de memoria que está sendo usado para guardar as informações referentes ao Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*
*  Assertiva de Entrada: 
*		O corpo docente ja foi instanciado atraves da função cria
*  Assertiva de Saída: 
*		-O espaço de memoria associado ao Corpo Docente é liberado
*
***********************************************************************/

GRC_tpCondRet GRC_libera();

/***********************************************************************
*
*  $FC Função: GRC Busca por RG
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo RG
*
*  $EP Parâmetros
*     
*     $P chave - RG do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     GRC_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio 
*
*  Assertiva de Entrada: 
*		-O corpo docente ja foi instanciado
*                    
*  Assertiva de Saída: 
*		-o cursor passa a aponta para um professor que armazena aquele valor
*
***********************************************************************/

GRC_tpCondRet GRC_buscaPorCodigo(char *chave);

/* insere na discplina atual uma disciplina com codigo correspondente como pre-requisito */
GRC_tpCondRet GRC_inserePreRequisito(char *codigoPre);
/* remove TODOS os prerequisitos*/
GRC_tpCondRet GRC_removePreRequisitos();


/***********************************************************************
*
*  $FC Função: GRC Consulta Nome
*
*  $ED Descrição da função
*     Consulta o Nome da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P nome - Cadeia de caracteres que receberá o nome do professor selecionado, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para a cadeia possui pelo menos o limite estabelecido no modulo professor como tamanho da string
*		-O ponteiro para nome é valido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaNome tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteudo do ponteiro para nome será preenchido com o nome  valido do Professor em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaNome(char *nome);

/***********************************************************************
*
*  $FC Função: GRC Consulta RG
*
*  $ED Descrição da função
*     Consulta o RG da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P rg - Inteiro que receberá o rg do professor selecionado, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk
*     GRC_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio 
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para o inteiro RG é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaRg tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para RG será preenchido com o RG  valido do Professor em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaCodigo(char *codigo);

/***********************************************************************
*
*  $FC Função: GRC Consulta CPF
*
*  $ED Descrição da função
*     Consulta o CPF da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P cpf - Cadeia de caracteres que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*     GRC_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para a cadeia possui pelo menos o limite estabelecido no modulo professor como tamanho da string
*		-O ponteiro para o cadeia CPF é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaCpf tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para CPF será preenchido com o CPF  valido do Professor em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaCreditos(int *creditos);

/***********************************************************************
*
*  $FC Função: GRC Consulta Matricula
*
*  $ED Descrição da função
*     Consulta a Matricula da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P matricula - Inteiro que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk 
*	  GRC_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para o inteiro matricula é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaMatricula tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para matricula será preenchido com a matricula  valida do Professor em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaBibiliografia(char *bibiliografia);

/***********************************************************************
*
*  $FC Função: GRC Consulta Email
*
*  $ED Descrição da função
*     Consulta o Email da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P email - Cadeia de Caracteres que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     GRC_CondRetOk \
*     GRC_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para a cadeia email é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaEmail tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para email será preenchido com o email  valido do Professor em questão
*
***********************************************************************/

GRC_tpCondRet GRC_consultaEmenta(char *ementa);

#endif

/***********************************************************************/
