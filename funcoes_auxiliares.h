#ifndef FUNCOES_AUXILIARES_H_INCLUDED
#define FUNCOES_AUXILIARES_H_INCLUDED

#include "constantes.h"
#include "estruturas.h"

int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo);
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo);
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres);
void limpaBufferStdin(void);
char lerChar(char mensagem[MAX_STRING]);
tipoData lerData();
tipoHora lerHora(int minimo,int maximo);

#endif // FUNCOES_AUXILIARES_H_INCLUDED
