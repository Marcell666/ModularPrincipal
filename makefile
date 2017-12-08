modularPrincipal: main.c \
	conio.c conio.h \
	leitura.c leitura.h \
	menu.c menu.h \
	listas.c listas.h \
	corpodiscente.c corpodiscente.h \
	corpoDocente.c corpoDocente.h \
	gradeCurricular.c gradeCurricular.h \
	alumat.c alumat.h \
	gradehorario.c gradehorario.h \
	CorpoSala.c CorpoSala.h \
	aluno.c aluno.h \
	professor.c professor.h \
	disciplina.c disciplina.h \
	criterio_de_aprovacao.c criterio_de_aprovacao.h \
	turma.c turma.h \
	sala.c sala.h \
	HISTORICO.c HISTORICO.h \
	DISCIPLINACURSADA.c DISCIPLINACURSADA.h
	gcc -Wall -D _DEBUG -o modularPrincipal main.c conio.c leitura.c menu.c listas.c corpodiscente.c corpoDocente.c gradeCurricular.c alumat.c gradehorario.c aluno.c professor.c disciplina.c criterio_de_aprovacao.c turma.c CorpoSala.c sala.c HISTORICO.c DISCIPLINACURSADA.c
