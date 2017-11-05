#define _CRT_SECURE_NO_WARNINGS
#pragma warning( disable : 4996 ) 

#include <stdio.h>
#include <string.h>
#include "AluMat.h"
#include "corpodiscente.h"

int main(void) {
	Turma* tur;
	Disciplina* disc;
	CPF cpf;
	Data data;
	Endereco end;
	cpf.cod = 00; cpf.dig1 = 123; cpf.dig2 = 456; cpf.dig3 = 789;
	data.ano = 1990; data.dia = 14; data.mes = 07;
	strcpy(end.bairro, "Copacabana");
	strcpy(end.cidade, "Rio de Janeiro");
	strcpy(end.estado, "RJ");
	strcpy(end.rua, "Av. Nossa Sra. de Copacabana");
	strcpy(end.comp, "1900, Apto 708");
	
	GRC_cria();
	GRC_cadastra("Programacao Modular","INF-1000",4,"Livro Texto","Modular");
	GRC_cadastra("Banco de Dados", "INF-1001", 2, "Livro Texto", "BD");
	GRC_cadastra("Inteligencia Artificial", "INF-1002", 4, "Slides", "AI");
	CDI_cria();
	CDI_insere("Albert Einstein",1623011,&cpf,999132113,&data,&end);

	TUR_CriaTurma(&tur,"3WB",9,11,"Segunda e Quarta",30);
	GRC_buscaPorCodigo("INF-1000");
	GRC_devolveDisc(&disc);
	DIS_insere_turma(&disc,&tur);
	TUR_CriaTurma(&tur, "3WA", 9, 11, "Terca", 45);
	GRC_buscaPorCodigo("INF-1002");
	GRC_devolveDisc(&disc);
	DIS_insere_turma(&disc, &tur);
	TUR_CriaTurma(&tur, "3WB", 11, 13, "Terca e Quinta", 30);
	DIS_insere_turma(&disc, &tur);

	AMT_cria();
	AMT_matriculaNaDisc(1623011,"INF-1000","3WB"); // matriculando em prog modular
	AMT_matriculaNaDisc(1623011, "INF-1002", "3WA"); // matriculando em IA
	AMT_imprimeGrade(1623011);

	printf("\n------ Apos alteracao de turma de 3WA para 3WB em IA ------\n");
	AMT_alteraTurma(1623011,"INF-1002","3WB"); // mudo o aluno da turma 3WA para 3WB em IA
	AMT_alteraFaltas(1623011,3,"INF-1000"); // mudo as faltas em prog modular
	AMT_alteraFaltas(1623011, 1, "INF-1002"); // mudo as faltas em IA
	AMT_insereNota(9.2, 9.8, 7, 7.6,1623011,"INF-1002"); // mudo a nota de IA
	AMT_insereNota(7.5, 9.5, 8.9, 6, 1623011, "INF-1000"); // mudo a nota de prog modular

	AMT_imprimeGrade(1623011);

	return 0;
}
