/***************************************************************************
 *  $MCD Modulo de implementacao: Modulo Sala
 *
 *	Arquivo gerado
 *  Letras identificadoras:      SAL
 *
 *  Autores: mc - Matheus Caldas
 *	     bp - Bruno Pedrazza
 *	     pg - Pedro Gomes
 *	     va - Vin�cius Arcoverde
 *	     lf - Leon Fran�a
 *	     gc - Gabriel Costa
 *  $HA Historico de evolucao:
 *  Versao       Autor	Data            Observacoes
 *	1.3.1	      mc	10/09/2017		Corrigindo caso de erro na setCodigo
 *	1.3.0         bp    07/09/2017		Ajeitando ponteiros e consicoes de retorno de criarSala e removeSala.
 *										Implementacao funcoes imprimeSala e imprimeMatriz
 *  1.2.9         pg    07/09/2017  	Adicionando removeSala
 *	1.2.8	      mc    07/09/2017		Implementa��o b�sica da criaSala, agora recebendo os parametros.
 *	1.2.7	      pg	05/09/2017  	Ajustes menores de codumenta��o.
 *	1.2.6	      pg	04/09/2017   	Ajustando reservaSala com nova condRet
 *	1.2.5	      bp	04/09/2017   	Implementacao resetDisponibilidade, adicao de s�bados e novos defines
 *	1.2.4         pg	04/09/2017		Ajustando reservaSala e incluindo novos defines
 *	1.2.3	      bp	03/09/2017		Implementacao funcoes getELaboratorio e setELaboratorio
 *  1.2.2         mc    02/09/2017   	Implementacao funcoes setQtdComputadores e getQtdComputadores
 *  1.2.1         bp    02/09/2017  	Mudanca nas condicoes de retorno funcoes getNumero, getPredio, getAndar, setCodigo
 *	1.2.0	      pg    31/08/2017  	Implementacao das funcoes setaCodigo, setaMaxAlunos, reservaSala
 *	1.1.0         bp    31/08/2017   	Implementacao funcoes getNumero, getPredio, getAndar
 *  1.0.0         mc    30/08/2017  	Inicio do desenvolvimento
 *  $ED Descri��o do m�dulo
 *     Este m�dulo implementa um conjunto de funcoes para criar e manipular
 *     atributos do m�dulo Sala.
 *
 *
 *
 ***************************************************************************/

/* Inclus�es do compilador */
#include  <stdio.h>
#include  <string.h>
#include <stdlib.h>
#include "sala.h"



/* Inclus�o do respectivo m�dulo de defini��o */

#define SALA_OWN
#include "sala.h"
#undef SALA_OWN

/***********************************************************************
 *
 *  $TC Tipo de dados: SAL que define a estrutura do tipo SALA
 *
 *	$ED Descri��o do tipo
 *		Descreve a estrutura de uma sala
 *
 ***********************************************************************/

struct SAL_tagSala  {
    /* C�digo da sala, ex: L232,
     indicando 'L' o pr�dio e 232 o n?mero */
    char codigo[tamCodigoSala];
    
    /* N?mero m�ximo de alunos que a sala comporta */
    int maxAlunos;
    
    /* Indica se a sala � laborat�rio: 1 se � 0 se n�o */
    int eLaboratorio;
    
    /* Matriz de disponibilidade onde 1 representa sala "ocupada"
     e 0 "livre", assim, por exemplo, a sala estaria ocupada
     segunda e quarta (7-9) e
     terca e quinta (21-23)
	|Segunda|Terca|Quarta|Quinta|Sexta|S�bado|
     07	|  1    |  0  |  1   |  0   |  0  |  0  |
     08	|  1    |  0  |  1   |  0   |  0  |  0  |
     09	|  0    |  0  |  0   |  0   |  0  |  0  |
     10	|  0    |  0  |  0   |  0   |  0  |  0  |
     11	|  0    |  0  |  0   |  0   |  0  |  0  |
     12	|  0    |  0  |  0   |  0   |  0  |  0  |
     13	|  0    |  0  |  0   |  0   |  0  |  0  |
     14	|  0    |  0  |  0   |  0   |  0  |  0  |
     15	|  0    |  0  |  0   |  0   |  0  |  0  |
     16	|  0    |  0  |  0   |  0   |  0  |  0  |
     17	|  0    |  0  |  0   |  0   |  0  |  0  |
     18	|  0    |  0  |  0   |  0   |  0  |  0  |
     19	|  0    |  0  |  0   |  0   |  0  |  0  |
     20	|  0    |  0  |  0   |  0   |  0  |  0  |
     21	|  0    |  1  |  0   |  1   |  0  |  0  |
     22	|  0    |  1  |  0   |  1   |  0  |  0  |
     --------------------------------------
     */
    int disponibilidade[HORARIOS][DIAS];
    
};


/*****  Codigo das funcoes exportadas pelo modulo  *****/

/**************************************************************************
 *                                                                        *
 * Funcao: SAL Criar sala                                                 *
 **************************************************************************/

SAL_tpCondRet SAL_criarSala (SAL_tpSala ** pSala,
                             char *codigo,
                             int maxAlunos,
                             int eLaboratorio)
{
    SAL_tpCondRet retorno;
    SAL_tpCondRet retornoDaRemove;
    
    *pSala = NULL;
    *pSala = ( SAL_tpSala * ) malloc( sizeof( SAL_tpSala )) ;
    
    if( *pSala == NULL )
        return SAL_CondRetFaltouMemoria ;
    
    retorno = SAL_setCodigo(*pSala,codigo);
	if (retorno != SAL_CondRetOK) {
		retornoDaRemove = SAL_removeSala(pSala);
		if( retornoDaRemove != SAL_CondRetOK) 
			return retornoDaRemove;
		return retorno;
	}
    retorno = SAL_setMaxAlunos(*pSala,maxAlunos);
    if (retorno != SAL_CondRetOK){retornoDaRemove = SAL_removeSala(pSala); if( retornoDaRemove != SAL_CondRetOK) return retornoDaRemove; return retorno;}
    retorno = SAL_setELaboratorio(*pSala,eLaboratorio);
    if (retorno != SAL_CondRetOK){retornoDaRemove = SAL_removeSala(pSala); if( retornoDaRemove != SAL_CondRetOK) return retornoDaRemove; return retorno;}
    retorno = SAL_resetDisponibilidade(*pSala);
    if (retorno != SAL_CondRetOK){retornoDaRemove = SAL_removeSala(pSala); if( retornoDaRemove != SAL_CondRetOK) return retornoDaRemove; return retorno;}
    
    return SAL_CondRetOK ;
}
/* Fim funcao: SAL Criar sala */


/**************************************************************************
 *                                                                        *
 * Funcao: SAL remove sala                                            	  *
 **************************************************************************/

SAL_tpCondRet SAL_removeSala (SAL_tpSala ** pSala)
{
    if (*pSala == NULL)
	return SAL_CondRetRecebeuPonteiroNulo;

    else{
        free(*pSala);
        *pSala = NULL;
    }
    return SAL_CondRetOK ;
}
/* Fim funcao: SAL remove sala */


/**************************************************************************
 *                                                                        *
 * Funcao: SAL imprime sala                                            	  *
 **************************************************************************/

SAL_tpCondRet SAL_printSala (SAL_tpSala * pSala)
{
    SAL_tpCondRet retorno;
    char codigo [tamCodigoSala];
    char predio [tamPredio];
    int andar, maxAlunos, eLab;
    
	if (pSala == NULL){
		return SAL_CondRetRecebeuPonteiroNulo;
	}
    
    retorno = SAL_getCodigo( pSala, codigo );
    if (retorno != SAL_CondRetOK)
        return retorno;

    retorno = SAL_getPredio( pSala, predio );
    if (retorno != SAL_CondRetOK)
        return retorno;

    retorno = SAL_getAndar( pSala, &andar );
    if (retorno != SAL_CondRetOK)
        return retorno;

    retorno = SAL_getMaxAlunos( pSala, &maxAlunos );
    if (retorno != SAL_CondRetOK)
        return retorno;

    retorno = SAL_getELaboratorio( pSala, &eLab );
    if (retorno != SAL_CondRetOK)
        return retorno;
    
    printf ("\nSala %s\nLocalizada no %do andar do edificio %s\nCapacidade: %d alunos\n",codigo,andar,predio,maxAlunos);
    if (eLab)
        printf("E laboratorio\n");
    else
        printf("Nao e laboratorio\n");
    
    return SAL_CondRetOK;
}

/* Fim funcao: SAL imprime sala */


/**************************************************************************
 *                                                                        *
 * Funcao: SAL seta codigo da sala                                        *
 **************************************************************************/

SAL_tpCondRet SAL_setCodigo (SAL_tpSala * pSala, char *codigo)
{
    unsigned int i;
    if (pSala == NULL){
        return SAL_CondRetRecebeuPonteiroNulo;
    }
    
    if (codigo == NULL || strlen(codigo) >= tamCodigoSala){
        return SAL_CondRetParamInvalido;
    }
    
    if (codigo[0] != 'L' && codigo[0] != 'K' && codigo[0] != 'F' && codigo[0] != 'I' && codigo[0] != 'R'){
        return SAL_CondRetParamInvalido;
    }
    
    for(i=1;i< strlen(codigo);i++){
        if(codigo[i] < '0' || codigo[i] > '9')
        {
            return SAL_CondRetParamInvalido;
        }
    }
    
    strcpy(pSala->codigo, codigo);
    
    return SAL_CondRetOK;
}
/* Fim funcao: SAL seta codigo da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get codigo da sala                                         *
 **************************************************************************/

SAL_tpCondRet SAL_getCodigo (SAL_tpSala * pSala, char *codigo)
{
    if(pSala == NULL){
        return SAL_CondRetRecebeuPonteiroNulo;
    }
    
    strcpy(codigo, pSala->codigo);
    
    if (codigo == NULL || strlen(codigo) > tamCodigoSala)
        return SAL_CondRetErroEstrutura;
    
    return SAL_CondRetOK;
}
/* Fim funcao: Sal get codigo da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal set Max Alunos                                             *
 **************************************************************************/

SAL_tpCondRet SAL_setMaxAlunos (SAL_tpSala * pSala, int maxAlunos)
{
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    
    if (maxAlunos <= 0)
        return SAL_CondRetParamInvalido;
    
    pSala->maxAlunos = maxAlunos;
    return SAL_CondRetOK;
}
/* Fim funcao: Sal set Max Alunos */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get Max Alunos                                             *
 **************************************************************************/

SAL_tpCondRet SAL_getMaxAlunos (SAL_tpSala * pSala, int *maxAlunos)
{
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    
    *maxAlunos = pSala->maxAlunos;
    
    if (*maxAlunos <= 0)
        return SAL_CondRetErroEstrutura;
    
    return SAL_CondRetOK;
}
/* Fim funcao: Sal get Max Alunos */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal set eLaboratorio                                           *
 **************************************************************************/

SAL_tpCondRet SAL_setELaboratorio (SAL_tpSala * pSala, int eLaboratorio)
{
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    
    if (eLaboratorio != SAL_TIPO_LABORATORIO && eLaboratorio != SAL_TIPO_COMUM)
        return SAL_CondRetParamInvalido;
    
    pSala->eLaboratorio = eLaboratorio;
    
    return SAL_CondRetOK;
}
/* Fim funcao: Sal set eLaboratorio */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get eLaboratorio                                           *
 **************************************************************************/

SAL_tpCondRet SAL_getELaboratorio (SAL_tpSala * pSala, int *eLaboratorio)
{
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    
    *eLaboratorio = pSala->eLaboratorio;
    
    if (*eLaboratorio != SAL_TIPO_LABORATORIO && *eLaboratorio != SAL_TIPO_COMUM)
        return SAL_CondRetErroEstrutura;
    
    return SAL_CondRetOK;
}
/* Fim funcao: Sal get eLaboratorio */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get numero da sala                                         *
 **************************************************************************/

SAL_tpCondRet SAL_getNumero (SAL_tpSala * pSala, int *numero)
{
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;

    if (pSala->codigo[4] == '\0'){
        *numero = (pSala->codigo[1]-'0')*100+(pSala->codigo[2]-'0')*10+(pSala->codigo[3]-'0');
        return SAL_CondRetOK;
    }
    else{
        *numero = (pSala->codigo[1]-'0')*1000+(pSala->codigo[2]-'0')*100+(pSala->codigo[3]-'0')*10+(pSala->codigo[4]-'0');
        return SAL_CondRetOK;
    }
    
    /*if (numero == NULL)
        return SAL_CondRetErroEstrutura;*/
}
/* Fim funcao: Sal get numero da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get predio da sala                                         *
 **************************************************************************/

SAL_tpCondRet SAL_getPredio (SAL_tpSala * pSala, char *predio)
{
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    switch (pSala->codigo[0]){
        case 'L' :
            strcpy(predio, "Leme");
            break;
        case 'F' :
            strcpy(predio, "Frings");
            break;
        case 'K' :
            strcpy(predio, "Kennedy");
            break;
        case 'I' :
            strcpy(predio, "IAG");
            break;
        case 'R' :
            strcpy(predio, "RDC");
            break;
        default :
            return SAL_CondRetErroEstrutura;
    }
    return SAL_CondRetOK;
}
/* Fim funcao: Sal get predio da sala */


/**************************************************************************
 *                                                                        *
 * Funcao: Sal get andar da sala                                          *
 **************************************************************************/

SAL_tpCondRet SAL_getAndar (SAL_tpSala * pSala, int *andar)
{
    SAL_tpCondRet retorno;
    int numero;
    
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    
    retorno = SAL_getNumero (pSala,&numero);
    
    if (retorno != SAL_CondRetOK)
        return retorno;
    
    *andar = numero/100;
    
    return SAL_CondRetOK;
}
/* Fim funcao: Sal get andar da sala */

/***************************************************************************
 *                                                                         *
 * Funcao: Sal get horario da sala em determinado dia                      *
 **************************************************************************/

	SAL_tpCondRet SAL_getHorarioNoDia(SAL_tpSala * pSala, int dia, int horaInicio, int horaFim)
	{
		int hora;

		if (pSala == NULL)
			return SAL_CondRetRecebeuPonteiroNulo;

		if (horaInicio < inicioDiaLetivo || horaInicio >= fimDiaLetivo || horaFim <= inicioDiaLetivo || horaFim > fimDiaLetivo)
		{
			return SAL_CondRetParamInvalido;
		}

		if (horaInicio >= horaFim)
		{
			 return SAL_CondRetParamInvalido;
		}

		if (dia < inicioSemanaLetiva || dia > fimSemanaLetiva)
		{
			return SAL_CondRetParamInvalido;
		}

		horaInicio -= ajusteHora;
		horaFim -= ajusteHora;

		for (hora = horaInicio; hora < horaFim; hora++)
		{
			if (pSala->disponibilidade[hora][dia] != SAL_LIBERADA && pSala->disponibilidade[hora][dia] != SAL_RESERVADA)
			{
				return SAL_CondRetErroEstrutura;
			}
			if (pSala->disponibilidade[hora][dia] != SAL_LIBERADA) {
				return SAL_CondRetErroAoReservar;
			}
		}

		return SAL_CondRetOK;
	}

/* Fim da fun��o SAL_getHorarioNoDia */

/**************************************************************************
 *                                                                        *
 * Funcao: Sal -Reserva a Sala                                            *
 **************************************************************************/

SAL_tpCondRet SAL_reservaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim)
{
    int hora, verificaHorario;
    
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    
    verificaHorario = SAL_getHorarioNoDia(pSala, dia, horaInicio, horaFim);
    
    if (verificaHorario != SAL_CondRetOK) {
        return (SAL_tpCondRet)verificaHorario;
    }
    
    for(hora = horaInicio - ajusteHora; hora < horaFim - ajusteHora; hora++)
    {
        pSala->disponibilidade [hora][dia] = SAL_RESERVADA;
    }
    return SAL_CondRetOK;
}

/* Fim funcao: Sal reserva Sala */

/**************************************************************************
 *                                                                        *
 * Funcao: SAL_Libera a Sala                                              *
 **************************************************************************/
SAL_tpCondRet SAL_liberaSala (SAL_tpSala * pSala, int dia, int horaInicio, int horaFim)
{
    int hora;
    if (pSala == NULL)
        return SAL_CondRetRecebeuPonteiroNulo;
    
    if( horaInicio < inicioDiaLetivo || horaInicio >= fimDiaLetivo || horaFim <= inicioDiaLetivo
       || horaFim > fimDiaLetivo || dia <inicioSemanaLetiva || dia > fimSemanaLetiva || horaInicio >= horaFim )
        return  SAL_CondRetParamInvalido;
    
    
    for(hora = horaInicio - ajusteHora; hora < horaFim - ajusteHora; hora++)
    {
        if (pSala->disponibilidade[hora][dia] != SAL_LIBERADA && pSala->disponibilidade[hora][dia] != SAL_RESERVADA)
            return SAL_CondRetErroEstrutura;
        if(pSala->disponibilidade[hora][dia] == SAL_LIBERADA)
        {
            return SAL_CondRetErroAoLiberar;
        }
    }
    
    for(hora = horaInicio - ajusteHora; hora < horaFim - ajusteHora; hora++)
    {
        pSala->disponibilidade [hora][dia] = SAL_LIBERADA;
    }
    return SAL_CondRetOK;
}
/* Fim funcao: Sal libera Sala */

/**************************************************************************
 *                                                                        *
 * Funcao: Sal reset disponibilidade Sala                                 *
 **************************************************************************/

SAL_tpCondRet SAL_resetDisponibilidade (SAL_tpSala * pSala){
    int i, j;
    if (pSala == NULL){
        return SAL_CondRetRecebeuPonteiroNulo;
    }
    
    for (i = 0 ; i < HORARIOS ; i++){
        for (j = 0; j < DIAS ; j++){
            pSala->disponibilidade[i][j] = SAL_LIBERADA;
            if (pSala->disponibilidade[i][j] != SAL_LIBERADA)
                return SAL_CondRetErroAoLiberar;
        }
    }
    
    return SAL_CondRetOK;
}

/* Fim funcao: Sal reset disponibilidade Sala */

/***************************************************************************
 *                                                                         *
 * Funcao: Sal imprime matriz disponibilidade Sala                         *
 **************************************************************************/

SAL_tpCondRet SAL_printDisponibilidade(SAL_tpSala * pSala) {
    int i, j;
    if (pSala == NULL) 
        return SAL_CondRetRecebeuPonteiroNulo;
    printf("\n\n\tSegunda\tTerca\tQuarta\tQuinta\tSexta\tSabado\n");
    for (i = 0 ; i < HORARIOS ; i++){
        printf("%d-%d\t",i+7,i+8);
        for (j = 0 ; j < DIAS ; j++){
            if (pSala->disponibilidade[i][j] != SAL_LIBERADA && pSala->disponibilidade[i][j] != SAL_RESERVADA)
                return SAL_CondRetErroEstrutura;
            if (pSala->disponibilidade[i][j] == SAL_RESERVADA)
                printf("XXXXXX\t");
            else
                printf("------\t");
        }
        printf("\n");
    }
    printf("\n");
    
    return SAL_CondRetOK;
}

/* Fim funcao: Sal reset disponibilidade Sala */

/***************************************************************************
*
*  Fun��o: SAL Salva Dados
*  ****/

	SAL_tpCondRet SAL_salvaDados (SAL_tpSala * pSala,  FILE *f )
	{
			int i, e;
			if ( !f )
			{
				#ifdef _DEBUG	
					printf("Erro ao abrir arquivo de dados das salas.\n") ;
				#endif
				return SAL_CondRetErroAbrirArquivo ;
			} /* if */
				/*
					Formato de escrita/leitura
					Dados da sala:
					%s %d %d
					disponibilidade:
					%d %d ....
				*/

			fprintf(f, "%s %d %d\n",
				pSala->codigo,
				pSala->maxAlunos,
				pSala->eLaboratorio
			) ;
			for( i=0; i<HORARIOS; i++ ){
				for( e=0; e<DIAS; e++ ){
					fprintf(f, "%d ", pSala->disponibilidade[i][e]);
				}
			}
			fprintf(f, "\n");

			#ifdef _DEBUG	
				printf("Dados da sala de codigo %s salvos com sucesso!\n", pSala->codigo);
			#endif

			return SAL_CondRetOK ;

	} /* Fim fun��o: SAL Salva Dados */

/***************************************************************************

*
*  Fun��o: SAL Le Dados
*  ****/

	SAL_tpCondRet SAL_leDados (SAL_tpSala * pSala,  FILE *f )
	{
			int i, e;
			if ( !f )
			{
				#ifdef _DEBUG	
					printf("Erro ao abrir arquivo de dados das salas.\n") ;
				#endif
				return SAL_CondRetErroAbrirArquivo ;
			} /* if */
				/*
					Formato de escrita/leitura
					Dados da sala:
					%s %d %d
					disponibilidade:
					%d %d ....
				*/

			fscanf(f, " %s %d %d\n",
				pSala->codigo,
				&pSala->maxAlunos,
				&pSala->eLaboratorio
			) ;
			#ifdef _DEBUG
				printf("%s %d %d\n",
				pSala->codigo,
				pSala->maxAlunos,
				pSala->eLaboratorio);
			#endif
			for(i=0;i<HORARIOS;i++){
				for(e=0;e<DIAS;e++){					
					fscanf(f, "%d ", pSala->disponibilidade[i] + e );
					#ifdef _DEBUG	
						printf("%d ", pSala->disponibilidade[i][e] );
					#endif
				}
			}


			#ifdef _DEBUG	
				printf("Dados da sala de codigo %s carregados com sucesso!\n", pSala->codigo);
			#endif

			return SAL_CondRetOK ;

	} /* Fim fun��o: SAL le Dados */


/********** Fim do modulo de implementacao: Modulo Sala **********/
