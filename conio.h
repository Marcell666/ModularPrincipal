#ifdef __linux__
/* reads from keypress, doesn't echo */
int getch(void);

/* reads from keypress, echoes */
int getche(void);
#else
#pragma warning "Por favor, compile sem usar os arquivos conio.c e conio.h. No windows eles nao sao necessarios."
#endif
