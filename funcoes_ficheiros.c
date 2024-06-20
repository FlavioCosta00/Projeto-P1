#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes_ficheiros.h"

void gravaFicheiroBinarioUC(int num_UC, tipoUC vetor_UC[])
{
    FILE *ficheiro;
    int quantEscrito;
    ficheiro = fopen("UnidadesCurriculares.dat", "wb");

    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro UCs");
    }
    else //conseguiu abrir o ficheiro
    {
        quantEscrito = fwrite(&num_UC, sizeof(int), 1, ficheiro);
        if (quantEscrito != 1)
        {
            printf(" ERRO: Erro ao escrever a quantidade de UCs no ficheiro");
        }
        else
        {
            quantEscrito = fwrite(vetor_UC, sizeof(tipoUC), num_UC, ficheiro);
            if (quantEscrito != num_UC)
            {
                printf(" ERRO: Erro ao escrever a informacao do vetor UCs");
            }
            else
            {
                printf(" UCs Gravadas com sucesso.\n");
            }
        }
        fclose(ficheiro);
    }
}

void lerFicheiroBinarioUC(int *num_UC, tipoUC vetor_UC[])
{
    FILE *ficheiro;
    int quantLido;
    ficheiro = fopen("UnidadesCurriculares.dat", "rb");

    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro UCs");
    }
    else //conseguiu abrir o ficheiro
    {

        quantLido = fread(num_UC, sizeof(int), 1, ficheiro);
        if (quantLido != 1)
        {
            printf(" ERRO: Erro ao ler a quantidade de UCs a partir do ficheiro");
        }
        else
        {
            quantLido = fread(vetor_UC, sizeof(tipoUC), *num_UC, ficheiro);
            if (quantLido != *num_UC)
            {
                printf(" ERRO: Erro ao ler a informacao do vetor UCs");
            }
            else
            {
                printf(" UCs carregadas com sucesso \n");
            }
        }
        fclose(ficheiro);
    }
}

void gravaFicheiroBinarioInformacoes(int num_AA,int num_AR,int num_AG,int num_A)
{
    FILE *ficheiro;
    ficheiro = fopen("Informacoes.dat", "wb");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro Informacoes\n");
    }
    else
    {
        fwrite(&num_AA, sizeof(int), 1, ficheiro);
        fwrite(&num_AR, sizeof(int), 1, ficheiro);
        fwrite(&num_AG, sizeof(int), 1, ficheiro);
        fwrite(&num_A, sizeof(int), 1, ficheiro);
        printf(" Informacoes gravadas com sucesso\n");
    }
    fclose(ficheiro);
}

void lerFicheiroBinarioInformacoes(int *num_AA,int *num_AR,int *num_AG,int *num_A)
{
    FILE *ficheiro;
    ficheiro = fopen("Informacoes.dat", "rb");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro Informacoes\n");
    }
    else //conseguiu abrir o ficheiro
    {
        fread(num_AA, sizeof(int), 1, ficheiro);
        fread(num_AR, sizeof(int), 1, ficheiro);
        fread(num_AG, sizeof(int), 1, ficheiro);
        fread(num_A, sizeof(int), 1, ficheiro);
        printf(" Informacoes carregadas com sucesso\n");
        fclose(ficheiro);
    }
}

void gravaFicheiroBinarioAulasOnline(tipoAulaOn *vetor_AulaOn,int num_A)
{
    FILE *ficheiro;
    ficheiro = fopen("AulasOnline.dat", "wb");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro Aulas Online");
    }
    else
    {
        fwrite(vetor_AulaOn, sizeof(tipoAulaOn), num_A, ficheiro);
        printf(" Aulas online gravadas com sucesso\n");
        fclose(ficheiro);
    }
}


void lerFicheiroBinarioAulasOnline(tipoAulaOn vetor_AulaOn[],int num_A)
{
    FILE *ficheiro;
    ficheiro = fopen("AulasOnline.dat", "rb");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro Aulas Online\n");
    }
    else //conseguiu abrir o ficheiro
    {
        if (vetor_AulaOn == NULL && num_A != 0)
        {
            printf(" ERRO: Erro ao reservar memoria\n");
        }
        else
        {
            fread(vetor_AulaOn, sizeof(tipoAulaOn), num_A, ficheiro);
            printf(" Aulas Online carregadas com sucesso\n");
        }
    }
    fclose(ficheiro);
}

void ficheiroLogAcessoEstudante(char designacao[MAX_STRING], int num_estudante,char tipo_acesso[MAX_STRING])
{
    FILE *ficheiro;
    ficheiro = fopen("AcessosEstudantes.txt", "a");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro Acessos Estudantes\n");
    }
    else
    {
        fprintf(ficheiro, "\nNumero Estudante: %d Designacao: %s %s",num_estudante, designacao,tipo_acesso);
        fclose(ficheiro);
    }
}

void gravaAcessoEstudante(char designacao[MAX_STRING], int num_estudante,char tipo_acesso[MAX_STRING])
{
    FILE *ficheiro;
    ficheiro = fopen("AcessosEstudantes.dat", "ab");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro AcessosEstudantes\n");
    }
    else //conseguiu abrir o ficheiro
    {
        fwrite(designacao, sizeof(char), MAX_STRING, ficheiro);
        fwrite(&num_estudante, sizeof(int), 1, ficheiro);
        fwrite(tipo_acesso, sizeof(char), MAX_STRING, ficheiro);
    }
    fclose(ficheiro);
}

void gravaFicheiroBinarioEstudantes(int num_EST,  tipoAcessoEST vetor_estudantes[])
{
    FILE *ficheiro;
    int quantEscrito;
    ficheiro = fopen("Estudantes.dat", "wb");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro Estudantes\n");
    }
    else //conseguiu abrir o ficheiro
    {
        quantEscrito = fwrite(&num_EST, sizeof(int), 1, ficheiro);
        if (quantEscrito != 1)
        {
            printf(" ERRO: Erro ao escrever a quantidade de Estudantes no ficheiro\n");
        }
        else
        {
            quantEscrito = fwrite(vetor_estudantes, sizeof(tipoAcessoEST), num_EST, ficheiro);
            if (quantEscrito != num_EST)
            {
                printf(" ERRO: Erro ao escrever a informacao do vetor Estudantes\n");
            }
            else
            {
                printf(" Estudantes Gravados com sucesso.\n");
            }
        }
        fclose(ficheiro);
    }
}

void lerFicheiroBinarioEstudantes(int *num_EST,  tipoAcessoEST vetor_estudantes[])
{
    FILE *ficheiro;
    int quantLido;
    ficheiro = fopen("Estudantes.dat", "rb");
    if (ficheiro == NULL)
    {
        printf(" ERRO: Erro ao abrir o ficheiro Estudantes");
    }
    else //conseguiu abrir o ficheiro
    {
        quantLido = fread(num_EST, sizeof(int), 1, ficheiro);
        if (quantLido != 1)
        {
            printf(" ERRO: Erro ao ler a quantidade de Estudantes a partir do ficheiro\n");
        }
        else
        {
            quantLido = fread(vetor_estudantes, sizeof(tipoAcessoEST), *num_EST, ficheiro);
            if (quantLido != *num_EST)
            {
                printf(" ERRO: Erro ao ler a informacao do vetor Estudantes\n");
            }
            else
            {
                printf(" Estudantes carregados com sucesso \n");
            }
        }
        fclose(ficheiro);
    }
}






