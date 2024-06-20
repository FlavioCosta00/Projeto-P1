#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoes_auxiliares.h"

// Acrescentada variavel controlo para repetir insercao se ao for inserido numero int

//FUNÇÃO LER INT
int lerInteiro(char mensagem[MAX_STRING], int minimo, int maximo)
{
    int numero, controlo;
    do
    {
        printf("%s (%d a %d) :", mensagem, minimo, maximo);
        controlo = scanf ("%d", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();     //limpa todos os caracteres do buffer stdin (nomeadamente o \n)

        if (controlo == 0)
        {
            printf("Devera inserir um numero inteiro \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

//FUNÇÃO LER FLOAT
float lerFloat(char mensagem[MAX_STRING], float minimo, float maximo)
{
    float numero;
    int controlo;
    do
    {
        printf("%s (%.2f a %.2f) :", mensagem, minimo, maximo);
        controlo = scanf ("%f", &numero);  // scanf devolve quantidade de valores vàlidos obtidos
        limpaBufferStdin();

        if (controlo == 0)
        {
            printf("Devera inserir um numero decimal (float) \n");
        }
        else
        {

            if(numero<minimo || numero>maximo)
            {
                printf("Numero invalido. Insira novamente:\n");
            }

        }
    }
    while(numero<minimo || numero>maximo || controlo ==0);

    return numero;
}

//FUNÇÃO STRING
void lerString(char mensagem[MAX_STRING], char vetorCaracteres[MAX_STRING], int maximoCaracteres)
{
    int tamanhoString;

    do 			// Repete leitura caso sejam obtidas strings vazias
    {
        printf("%s", mensagem);
        fgets(vetorCaracteres, maximoCaracteres, stdin);

        tamanhoString = strlen(vetorCaracteres);

        if (tamanhoString == 1)
        {
            printf("Nao foram introduzidos caracteres!!! . apenas carregou no ENTER \n\n");  // apenas faz sentido limpar buffer se a ficarem caracteres
        }

    }
    while (tamanhoString == 1);

    if(vetorCaracteres[tamanhoString-1] != '\n')  // ficaram caracteres no buffer....
    {
        limpaBufferStdin();  // apenas faz sentido limpar buffer se a ficarem caracteres
    }
    else
    {
        vetorCaracteres[tamanhoString-1] = '\0'; 	//Elimina o \n da string armazenada em vetor
    }

}

//FUNÇÃO LIMPAR BUFFER
void limpaBufferStdin(void)
{
    char chr;
    do
    {
        chr = getchar();
    }
    while (chr != '\n' && chr != EOF);
}

//FUNÇÃO LER CHAR
char lerChar(char mensagem[MAX_STRING])
{
    char escolha;
    printf("%s", mensagem);
    scanf("%c", &escolha);
    limpaBufferStdin();
    escolha=toupper(escolha);

    return escolha;
}

//FUNÇÃO LER DATA
tipoData lerData()
{
    tipoData data;
    int maxDia;
    printf(" Ano: ");
    data.ano = lerInteiro("",MIN_ANO,MAX_ANO);//ANO MINIMO 2020 ,ANO MAXIMO 2021
    printf(" Mes: ");
    data.mes = lerInteiro("",MIN_MES,MAX_MES);//MES MINIMO 1 ,MES MAXIMO 12
    switch(data.mes)
    {
    case 2:
        if ((data.ano%400==0) || (data.ano%4==0 && data.ano%100!=0))
        {
            maxDia = 29;
        }
        else
        {
            maxDia = 28;
        }
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        maxDia = 30;
        break;
    default:
        maxDia = 31;
    }
    printf(" Dia: ");
    data.dia = lerInteiro("",1,maxDia);
    return data;
}

tipoHora lerHora(int minimo,int maximo)
{
    tipoHora hora;
    hora.hora=lerInteiro(" Hora: ",minimo,maximo);
    hora.minuto=lerInteiro(" minutos: ",0,59);
    return hora;
}
