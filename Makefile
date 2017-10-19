SRC := professor.c \
	corpoDocente.c \
	aluno.c \
	corpodiscente.c \
	disciplina.c \
	gradeCurricular.c \
	listas.c \
	menu.c

APP := modularPrincipal
OBJ_PATH := Build
MAIN := main.c

CFLAGS :=  -Wall

######################################

OBJ := $(SRC:.c=.o)
OBJ_P := $(addprefix $(OBJ_PATH)/,$(OBJ))

AUTODEPS := $(patsubst %.c,$(OBJ_PATH)/%.d,$(SRC))
DF = $(OBJ_PATH)/$(*F)

all: $(OBJ_P)
	$(CC) $(OBJ_P) -o $(APP) $(MAIN)

clean:
	rm $(OBJ_P) $(APP) $(AUTODEPS)
	rm $(MAIN)

$(OBJ_PATH)/%.o: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) -c $(CFLAGS) $< -o $@

$(OBJ_PATH)/%.d: %.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) -MM -MP -MT $(DF).o $< > $(DF).d

-include $(AUTODEPS)
.PHONY: clean
