#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcoes_estatisticas.h"

void RankingUCs(tipoUC vetor_UC[],int num_UC)
{
    int i;
    if (num_UC==0)
    {
        printf("Nao existe Unidades Curriculares\n");
    }
    else
    {
        printf(" Ranking das Unidades Curriculares\n\n");
        ordenarUCs(vetor_UC,num_UC);
        for (i=0; i<num_UC; i++)
        {
            printf("\n Codigo: %d ",vetor_UC[i].codigo);
            printf("\t Designacao: %s ",vetor_UC[i].designacao);
            printf("\t Quantidade Total Acessos a aulas gravadas: %d \n",vetor_UC[i].qnt_acessos_gravacoes);
        }
    }
}

void ordenarUCs (tipoUC vetor_UC[], int num_UC) //ORDENA UCS CONSIDERANDO A QUANTIDADE TOTAL DE ACESSOS ÁS AULAS GRAVADAS POR ORDEM DECRESCENTE
{
    int i, j, haTrocas;
    tipoUC vBackup;
    haTrocas=1;
    for(i=0; i<num_UC-1 && haTrocas!=0; i++)
    {
        haTrocas=0;
        for (j= 0; j > num_UC-i-1; j++)
        {
            if(vetor_UC[j+1].qnt_acessos_gravacoes < vetor_UC[j].qnt_acessos_gravacoes)
            {
                haTrocas=1;
                vBackup=vetor_UC[j];
                vetor_UC[j]=vetor_UC[j+1];
                vetor_UC[j+1]=vBackup;
            }
        }
    }
}

void QntMediaPresencasAR(tipoAulaOn vetor_AulaOn[],int num_A)
{
    int soma=0,i;
    float qnt_media_presencas;
    for(i=0;i<num_A;i++){
        if(vetor_AulaOn[i].estado_aula==3)
            soma=soma+vetor_AulaOn[i].qnt_presencas;
    }
    qnt_media_presencas=(float)soma/num_A;
    printf(" Quantidade Media de Presencas Aulas Online: %f ",qnt_media_presencas);
}

void PercentagemUCsAG(tipoUC vetor_UC[],int num_UC)
{
    float percentagem;
    int contador=0,i;
    if (num_UC==0)
    {
        printf("Nao existe Unidades Curriculares");
    }
    else
    {
        for (i=0; i<num_UC; i++)
        {
            if (vetor_UC[i].aulas_gravadas!=0)
            {
                contador++;
            }
        }
        percentagem= contador*100/num_UC;
        printf(" Percentagem de UCs com aulas gravadas: %.2f %% \n",percentagem);
    }
}

void UCsComMenorQntAR (tipoUC vetor_UC[],int num_UC) //Unidades Curriculares com a menor quantidade de aulas online realizadas
{
    int i,j,k,haTrocas;
    tipoUC vBackup;
    if (num_UC==0)
    {
        printf("Nao existe Unidades Curriculares");
    }
    else
    {
        haTrocas=1;
        for(i=0; i<num_UC-1 && haTrocas!=0; i++)
        {
            haTrocas=0;
            for (j= 0; j > num_UC-i-1; j++)
            {
                if(vetor_UC[j+1].qnt_aulas_realizadas < vetor_UC[j].qnt_aulas_realizadas)
                {
                    haTrocas=1;
                    vBackup=vetor_UC[j];
                    vetor_UC[j]=vetor_UC[j+1];
                    vetor_UC[j+1]=vBackup;
                }
            }
        }
        for (k=0; k<num_UC; k++)
        {
            printf("\n Codigo: %d ",vetor_UC[k].codigo);
            printf("\t Designacao: %s ",vetor_UC[k].designacao);
            printf("\t Quantidade Total Aulas realizadas: %d ",vetor_UC[k].qnt_aulas_realizadas);
        }
    }
}









