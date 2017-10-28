/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Corpo Docente
*
*  Arquivo gerado:              corpoDocente.h
*  Letras identificadoras:      CDO
*
*  Nome da base de software:    Módulo Corpo Docente
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
*	1.10	RP	05/10/2017  Ajuste de comentários das alteras de chaves
*   	1.0    BM/RP	05/10/2017 	Mais Revisão
*       0.40   NP	05/10/2017   Documentação finalizada 
*   	0.32   BM/RP	03/10/2017 	Revisão
*    	0.31   NP	03/10/2017 	Documentação iniciada
*       0.30   BM	02/10/2017	Protótipos adicionados 
*       0.20   BM	02/10/2017	Funcoes modelo adicionadas 
*       0.10   BM	01/10/2017	Inicio do desenvolvimento 
*
*  $ED Descrição do módulo
*	  Este módulo implementa um conjunto de funções para criar e manipular uma lista de Instâncias de Professor, ou seja, um Corpo Docente.
*     Ao iniciar a execução do programa não existe nenhuma instância de Corpo Docente.
*     Ao chamar a função criar, uma Lista vazia é criada, precisando assim ter Instâncias de Professores cadastrados.
*     Nenhuma funcao deste modulo deve ser chamada antes da cria();
*	  Deve-se usar a função libera para que a memória alocada seja liberada.
*	  Passar argumentos inválidos como 0 ou "" podem causar erro de formato (CDO_CondRetFormatoInvalido).
*     Esse módulo utiliza funções auxiliares para manipulação de Instâncias de Professor (Ref. professor.h)
*
***************************************************************************/

#ifndef CORPODOCENTE_H
#define CORPODOCENTE_H


/***********************************************************************
*
*  $TC Tipo de dados: CDO Condições de retorno
*
*
*  $ED Descrição do tipo
*     Condições de retorno
*
***********************************************************************/

typedef enum{
	CDO_CondRetOk,
		/* Condicao de Retorno OK, usada quando a função executa corretamente */
	CDO_CondRetNaoHaMemoria,
		/* Condicao de Retorno Nao Ha Memoria, usada quando a memoria do sistema nao apresenta mais espaco */ 
	CDO_CondRetCorpoDocenteVazio,
		/* Condicao de Retorno Corpo Docente Vazio, usada quando a lista de Instância de Professores, ou seja o Corpo Docente, está vazia */ 
	CDO_CondRetProfessorNaoEncontrado, 
		/* Condicao de Retorno Professor Não Encontrado, usada quando o Professor não é encontrado numa busca ou quando a lista está vazia quando percorrida */ 
	CDO_CondRetIdJaCriado,
		/* Condicao de Retorno Id Já Criado, usada quando existe outra Instância de Professor no Corpo Docente com o mesmo RG/CPF/matricula/email */ 
	CDO_CondRetFormatoInvalido 
		/* Condicao de Retorno Formato Inválido, usada quando os parâmetros de uma certa função não estão de acordo com o que é esperado pelas funções auxiliares */ 
} CDO_tpCondRet;

/***********************************************************************
*
*  $FC Função: CDO Cria
*
*  $ED Descrição da função
*     Cria uma instância vazia de Corpo Docente
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		-A função cria ainda não foi chamada.
*                    
*  Assertiva de Saída: 
*		-Uma instância de Corpo Docente (Lista de Professores) é criada
*
***********************************************************************/

CDO_tpCondRet CDO_cria();

/***********************************************************************
*
*  $FC Função: CDO Cadastra
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
*     CDO_CondRetOk 
*     CDO_CondRetIdJaCriado - Caso o Professor que deseja cadastrar já está cadastrado nessa instância de Corpo Docente com o mesmo RG/cpf/matricula ou email
*	  CDO_CondRetNaoHaMemoria - Caso não haja memória suficiente para cadastrar o Professor no Corpo Docente
*     CDO_CondRetFormatoInvalido - Caso o formato dos parâmetros não esteja de acordo com o esperado pelo modulo professor
*
*  Assertiva de Entrada: 
*		-O corpo docente já foi instanciado
*                    
*  Assertiva de Saída: 
*		-Uma Instância de Professor é cadastrada no Corpo Docente
*
***********************************************************************/

CDO_tpCondRet CDO_cadastra(char *nome, int rg, char *cpf, int matricula, char *email, int telefone, int dia, int mes, int ano, char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);

/***********************************************************************
*
*  $FC Função: CDO Mostra Atual
*
*  $ED Descrição da função
*     Mostra a atual Instância de Professor selecionada no Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso a Instância de Corpo Docente esteja vazia
*
*  Assertiva de Entrada: 
*		-O corpo docente foi instanciado
*                    
*  Assertiva de Saída: 
*       -É necessário que a Função PRF_mostra tenha suas assertivas de entrada e saida corretamente implementadas
*		-Mostra-se no Prompt de Comando a atual Instância de Professor selecionada
*
***********************************************************************/

CDO_tpCondRet CDO_mostraAtual();

/***********************************************************************
*
*  $FC Função: CDO Mostra Todos
*
*  $ED Descrição da função
*     Mostra todas as Instância de Professor presentes no Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso a Instância de Corpo Docente esteja vazia
*
*  Assertiva de Entrada: 
*		-Exista um Corpo Docente não vazio
*                    
*  Assertiva de Saída: 
*       -É necessário que a Função PRF_mostra tenha suas assertivas de entrada e saida corretamente implementadas
*		-Mostra-se no Prompt de Comando todas as Instâncias de Professor atualmente no Corpo Docente
*
***********************************************************************/

CDO_tpCondRet CDO_mostraTodos();

/***********************************************************************
*
*  $FC Função: CDO Retira
*
*  $ED Descrição da função
*     Retira a atual Instância de Professor presente no Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso a Instância de Corpo Docente esteja vazia
*
*  Assertiva de Entrada: 
*		-Exista um Corpo Docente não vazio
*                    
*  Assertiva de Saída: 
*		-A atual Instância de Professor é retirada do Corpo Docente
*
***********************************************************************/

CDO_tpCondRet CDO_retira();

/***********************************************************************
*
*  $FC Função: CDO Limpa
*
*  $ED Descrição da função
*     Limpa o corpo Docente retirando todas as Instâncias de Professor presentes
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		O corpo docente ja foi instanciado atraves da função cria
*                    
*  Assertiva de Saída: 
*		-Todas as Instâncias de Professor são retiradas do Corpo Docente
*
***********************************************************************/

CDO_tpCondRet CDO_limpa();

/***********************************************************************
*
*  $FC Função: CDO Libera
*
*  $ED Descrição da função
*     Libera o espaço de memoria que está sendo usado para guardar as informações referentes ao Corpo Docente 
*
*  $EP Parâmetros --
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*
*  Assertiva de Entrada: 
*		O corpo docente ja foi instanciado atraves da função cria
*  Assertiva de Saída: 
*		-O espaço de memoria associado ao Corpo Docente é liberado
*
***********************************************************************/

CDO_tpCondRet CDO_libera();

/***********************************************************************
*
*  $FC Função: CDO Busca por RG
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo RG
*
*  $EP Parâmetros
*     
*     $P chave - RG do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio 
*
*  Assertiva de Entrada: 
*		-O corpo docente ja foi instanciado
*                    
*  Assertiva de Saída: 
*		-o cursor passa a aponta para um professor que armazena aquele valor
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorRg(int chave);

/***********************************************************************
*
*  $FC Função: CDO Busca por CPF
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo CPF
*
*  $EP Parâmetros
*     
*     $P chave - CPF do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio 
*
*  Assertiva de Entrada: 
*		-O corpo docente ja foi instanciado
*                    
*  Assertiva de Saída: 
*		-o cursor passa a aponta para um professor que armazena aquele valor
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorCpf(char *chave);

/***********************************************************************
*
*  $FC Função: CDO Busca por Matricula
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pela Matricula
*
*  $EP Parâmetros
*     
*     $P chave - Matricula do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio 
*
*  Assertiva de Entrada: 
*		-O corpo docente ja foi instanciado
*                    
*  Assertiva de Saída: 
*		-o cursor passa a aponta para um professor que armazena aquele valor
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorMatricula(int chave);

/***********************************************************************
*
*  $FC Função: CDO Busca por Email
*
*  $ED Descrição da função
*     Busca no Corpo Docente (Lista de Professores) um Professor pelo Email
*
*  $EP Parâmetros
*     
*     $P chave - Email do Professor que deseja buscar no corpo Docente
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetProfessorNaoEncontrado - Instância de professor desejada não encontrada no Corpo Docente
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio 
*
*  Assertiva de Entrada: 
*		-O corpo docente ja foi instanciado
*                    
*  Assertiva de Saída: 
*		-o cursor passa a aponta para um professor que armazena aquele valor
*
***********************************************************************/

CDO_tpCondRet CDO_buscaPorEmail(char *chave);

/***********************************************************************
*
*  $FC Função: CDO Consulta Nome
*
*  $ED Descrição da função
*     Consulta o Nome da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P nome - Cadeia de caracteres que receberá o nome do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
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

CDO_tpCondRet CDO_consultaNome(char *nome);

/***********************************************************************
*
*  $FC Função: CDO Consulta RG
*
*  $ED Descrição da função
*     Consulta o RG da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P rg - Inteiro que receberá o rg do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio 
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

CDO_tpCondRet CDO_consultaRg(int *rg);

/***********************************************************************
*
*  $FC Função: CDO Consulta CPF
*
*  $ED Descrição da função
*     Consulta o CPF da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P cpf - Cadeia de caracteres que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
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

CDO_tpCondRet CDO_consultaCpf(char *cpf);

/***********************************************************************
*
*  $FC Função: CDO Consulta Matricula
*
*  $ED Descrição da função
*     Consulta a Matricula da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P matricula - Inteiro que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
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

CDO_tpCondRet CDO_consultaMatricula(int *matricula);

/***********************************************************************
*
*  $FC Função: CDO Consulta Email
*
*  $ED Descrição da função
*     Consulta o Email da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P email - Cadeia de Caracteres que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk \
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
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

CDO_tpCondRet CDO_consultaEmail(char *email);

/***********************************************************************
*
*  $FC Função: CDO Consulta Telefone
*
*  $ED Descrição da função
*     Consulta o Telefone da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P telefone - Inteiro que receberá o cpf do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para o inteiro telefone é válido
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_consultaTelefone tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o conteúdo do ponteiro para telefone será preenchido com o telefone do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaTelefone(int *tel);

/***********************************************************************
*
*  $FC Função: CDO Consulta Data de Nasciemnto
*
*  $ED Descrição da função
*     Consulta a data de Nascimento da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P dia - Inteiro que receberá o dia de nascimento do professor selecionado, por referência
*	  $P mes - Inteiro que receberá o mes de nascimento do professor selecionado, por referência
*     $P ano - Inteiro que receberá o ano de nascimento do professor selecionado, por referência
*
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para a cadeia possui pelo menos o limite estabelecido no modulo professor como tamanho da string
*		-O ponteiro para o inteiro dia é válido
*		-O ponteiro para o inteiro mes é válido
*		-O ponteiro para o inteiro ano é valido
*                    
*  Assertiva de Saída: 
*	    -É necessário que as função  PRF_consultaDiaNascimento,	PRF_consultaMesNascimento, PRF_consultaAnoNascimento tenham suas assertivas de entrada e saida atendidas completamente
*       -Caso isso ocorra o conteúdo dos ponteiros para dia/mes/ano serão preenchidos com o dia/mes/ano validos da data de nascimento do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaDataNascimento(int *dia, int *mes, int *ano);

/***********************************************************************
*
*  $FC Função: CDO Consulta Endereço
*
*  $ED Descrição da função
*     Consulta o Endereço da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P pais - Cadeia de Caracteres que receberá o pais de moradia do professor selecionado, por referência
*	  $P uf - Cadeia de Caracteres que receberá o uf de moradia do professor selecionado, por referência
*     $P cidade - Cadeia de Caracteres que receberá a cidade de moradia do professor selecionado, por referência
*     $P bairro - Cadeia de Caracteres que receberá o bairro de moradia do professor selecionado, por referência
*	  $P rua - Cadeia de Caracteres que receberá o a rua de moradia professor selecionado, por referência
*     $P numero - Inteiro que receberá o numero da moradia do professor selecionado, por referência
*     $P complemento - Cadeia de Caracteres que receberá o complemento da moradia do professor selecionado, por referência
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para a cadeia de caracteres país é válida
*		-O ponteiro para a cadeia de caracteres uf é válida
*		-O ponteiro para a cadeia de caracteres cidade é válida
*       -O ponteiro para a cadeia de caracteres bairro é válida
*		-O ponteiro para a cadeia de caracteres rua é válida	
*		-O ponteiro para o inteiro numero é válida
*		-O ponteiro para a cadeia de caracteres complemento é válida
* 
*  Assertiva de Saída: 
*	    -É necessário que as funções PRF_consultaPais, PRF_consultaUf, PRF_consultaCidade, PRF_consultaBairro, PRF_consultaRua, PRF_consultaNumero, PRF_consultaComplemento tenham suas assertivas de entrada e saida completamente atendidas 
*       -Caso isso ocorra o conteúdo dos ponteiros para país/uf/cidade/bairoo/rua/numero/complemento serão preenchidos com o país/uf/cidade/bairoo/rua/numero/complemento do endereço valido do Professor em questão
*
***********************************************************************/

CDO_tpCondRet CDO_consultaEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int *numero, char *complemento);

/***********************************************************************
*
*  $FC Função: CDO Altera Nome
*
*  $ED Descrição da função
*     Altera o nome da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P nome - Cadeia de caracteres que substituirá o nome do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetFormatoInvalido - Caso o formato do nome não esteja de acordo com o esperado pela função PRF_alteraNome
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*		-O ponteiro para a cadeia de caracteres nome é válida
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_alteraNome tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o nome dessa da instância de Professor selecionada será alterada para o conteúdo do parâmetro
*
***********************************************************************/

CDO_tpCondRet CDO_alteraNome(char *nome);

/***********************************************************************
*
*  $FC Função: CDO Altera RG
*
*  $ED Descrição da função
*     Altera o rg da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P rg - Inteiro que substituirá o rg do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetFormatoInvalido - Caso o formato do rg não esteja de acordo com o esperado pela função PRF_alteraRg
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*     CDO_CondRetIdJaCriado - Já existe professor na lista com esse RG
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_alteraRg tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o rg dessa da instância de Professor selecionada será alterada para o conteúdo do parâmetro
*
***********************************************************************/

CDO_tpCondRet CDO_alteraRg(int rg);

/***********************************************************************
*
*  $FC Função: CDO Altera CPF
*
*  $ED Descrição da função
*     Altera o CPF da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P cpf - Cadeia de caracteres que substituirá o cpf do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetFormatoInvalido - Caso o formato do cpf não esteja de acordo com o esperado pela função PRF_alteraCpf
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*     CDO_CondRetIdJaCriado - Já existe professor na lista com esse CPF
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_alteraCpf tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o cpf dessa da instância de Professor selecionada será alterada para o conteúdo do parâmetro
*
***********************************************************************/

CDO_tpCondRet CDO_alteraCpf(char *cpf);

/***********************************************************************
*
*  $FC Função: CDO Altera RG
*
*  $ED Descrição da função
*     Altera a matricula da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P matricula - Inteiro que substituirá a matricula do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetFormatoInvalido - Caso o formato da matricula não esteja de acordo com o esperado pela função PRF_alteraMatricula
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*     CDO_CondRetIdJaCriado - Já existe professor na lista com esse Matricula
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_alteraMatricula tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o matricula dessa da instância de Professor selecionada será alterada para o conteúdo do parâmetro
*
***********************************************************************/

CDO_tpCondRet CDO_alteraMatricula(int matricula);

/***********************************************************************
*
*  $FC Função: CDO Altera Email
*
*  $ED Descrição da função
*     Altera o email da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P email - Cadeia de caracteres que substituirá o email do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*     CDO_CondRetFormatoInvalido - Caso o formato do email não esteja de acordo com o esperado pela função PRF_alteraEmail
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*     CDO_CondRetIdJaCriado - Já existe professor na lista com esse Email
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_alteraEmail tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o email dessa da instância de Professor selecionada será alterada para o conteúdo do parâmetro
*
***********************************************************************/

CDO_tpCondRet CDO_alteraEmail(char* email);

/***********************************************************************
*
*  $FC Função: CDO Altera Tel
*
*  $ED Descrição da função
*     Altera o telefone da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P tel - Cadeia de caracteres que substituirá o telefone do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetFormatoInvalido - Caso o formato do tel não esteja de acordo com o esperado pela função PRF_alteraTelefone
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*       -Corpo docente foi alocado             
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_alteraTelefone tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra o tel dessa da instância de Professor selecionada será alterada para o conteúdo do parâmetro
*
***********************************************************************/

CDO_tpCondRet CDO_alteraTelefone(int tel);

/***********************************************************************
*
*  $FC Função: CDO Altera Data de Nascimento
*
*  $ED Descrição da função
*     Altera a Data de Nascimento da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P dia - Inteiro que substituirá o dia da Data de Nascimento do professor selecionado
*     $P mes - Inteiro que substituirá o mes da Data de Nascimento do professor selecionado
*     $P ano - Inteiro que substituirá o ano da Data de Nascimento do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetFormatoInvalido - Caso o formato da Data de Nascimento (dia/mes/ano) não esteja de acordo com o esperado pela função PRF_alteraDataNascimento
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
*                    
*  Assertiva de Saída: 
*	    -É necessário que a Função PRF_alteraDataNascimento tenha suas assertivas de entrada e saida corretamente implementadas
*       -Caso isso ocorra a Data de Nascimemto dessa da instância de Professor selecionada será alterada para o conteúdo dos parâmetros
*
***********************************************************************/

CDO_tpCondRet CDO_alteraDataNascimento(int dia, int mes, int ano);

/***********************************************************************
*
*  $FC Função: CDO Consulta Endereço
*
*  $ED Descrição da função
*     Altera o Endereço da instância de Professor selecionada naquele momento
*
*  $EP Parâmetros     
*     $P pais - Cadeia de Caracteres que substituirá o pais de moradia do professor selecionado
*	  $P uf - Cadeia de Caracteres que substituirá o uf de moradia do professor selecionado
*     $P cidade - Cadeia de Caracteres que substituirá a cidade de moradia do professor selecionado
*     $P bairro - Cadeia de Caracteres que substituirá o bairro de moradia do professor selecionado
*	  $P rua - Cadeia de Caracteres que substituirá o a rua de moradia professor selecionado
*     $P numero - Inteiro que substituirá o numero da moradia do professor selecionado
*     $P complemento - Cadeia de Caracteres que substituirá o complemento da moradia do professor selecionado
*						
*  $FV Valor retornado
*     CDO_CondRetOk 
*	  CDO_CondRetFormatoInvalido - Caso o formato do Endereço (pais/uf/cidade/bairro/rua/numero/complemento) não esteja de acordo com o esperado pelas função PRF_alteraPais, PRF_alteraUf, PRF_alteraCidade, PRF_alteraBairro, PRF_alteraRua, PRF_alteraNumero, PRF_alteraComplemento
*     CDO_CondRetCorpoDocenteVazio - Caso o Corpo Docente apontado esteja vazio
*
*  Assertiva de Entrada: 
*		-Corpo docente foi alocado
* 
*  Assertiva de Saída: 
*	    -É necessário que as funções PRF_alteraPais, PRF_alteraUf, PRF_alteraCidade, PRF_alteraBairro, PRF_alteraRua, PRF_alteraNumero, PRF_alteraComplemento tenham suas assertivas de entrada e saida completamente atendidas 
*       -Caso isso ocorra o Endereço nos parâmetros (país,uf,cidade,bairro,rua,numero,complemento) substituirá o Endereço da instância selecionada de Professor
*
***********************************************************************/

CDO_tpCondRet CDO_alteraEndereco(char *pais, char *uf, char *cidade, char *bairro, char *rua, int numero, char *complemento);

#endif

/***********************************************************************/
