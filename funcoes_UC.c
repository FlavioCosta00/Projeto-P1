#include <stdio.h>
#include <string.h>
#include "funcoes_UC.h"

void inserirUC(int *num_UC,tipoUC vetor_UC[])
{
    if (*num_UC< MAX_UC)
    {
        printf("\n Inserir UC\n\n");
        vetor_UC[*num_UC].codigo=MIN_COD_UC+*num_UC;//o codigo de UC é incrementado automaticamente
        vetor_UC[*num_UC].qnt_acessos_gravacoes=0;
        lerString(" Designacao Unidade Curricular:",vetor_UC[*num_UC].designacao,MAX_STRING);
        vetor_UC[*num_UC].tipo=lerInteiro(" Tipo UC(1-Obrigatoria 2-Opcional):",1,2);
        vetor_UC[*num_UC].semestre=lerInteiro(" Semestre da UC:",1,6);
        vetor_UC[*num_UC].regime=lerInteiro(" Regime da UC(1-Diurno 2-Pos-Laboral):",1,2);
        vetor_UC[*num_UC].aulaOnPrev.qnt_T=lerInteiro(" Quantidade de Aulas T online previstas:",0,MAX_AULAS);
        vetor_UC[*num_UC].aulaOnPrev.qnt_T_Agendada=0;
        if ( vetor_UC[*num_UC].aulaOnPrev.qnt_T!=0)
        {
            vetor_UC[*num_UC].aulaOnPrev.duracao_T=lerInteiro(" Tempo da Aula online (minutos):",MIN_TEMPO_AULA,MAX_TEMPO_AULA);
        }
        else
        {
            vetor_UC[*num_UC].aulaOnPrev.duracao_T=0;
        }
        vetor_UC[*num_UC].aulaOnPrev.qnt_TP=lerInteiro(" Quantidade de Aulas  TP online previstas:",0,MAX_AULAS);
        vetor_UC[*num_UC].aulaOnPrev.qnt_TP_Agendada=0;
        if ( vetor_UC[*num_UC].aulaOnPrev.qnt_TP!=0)
        {
            vetor_UC[*num_UC].aulaOnPrev.duracao_TP=lerInteiro(" Tempo da Aula TP(min):",MIN_TEMPO_AULA,MAX_TEMPO_AULA);
        }
        else
        {
            vetor_UC[*num_UC].aulaOnPrev.duracao_TP=0;
        }

        vetor_UC[*num_UC].aulaOnPrev.qnt_PL=lerInteiro(" Quantidade de Aulas Online PL previstas:",0,MAX_AULAS);
        vetor_UC[*num_UC].aulaOnPrev.qnt_PL_Agendada=0;
        if ( vetor_UC[*num_UC].aulaOnPrev.qnt_PL!=0)
        {
            vetor_UC[*num_UC].aulaOnPrev.duracao_PL=lerInteiro(" Tempo da Aula PL(min):",MIN_TEMPO_AULA,MAX_TEMPO_AULA);
        }
        else
        {
            vetor_UC[*num_UC].aulaOnPrev.duracao_PL=0;
        }
        vetor_UC[*num_UC].aulas_gravadas=0;//INICIALIZACAO A 0 para as estatisticas
        vetor_UC[*num_UC].qnt_aulas_realizadas=0;//INICIALIZACAO A 0 para as estatisticas
        (*num_UC)++;
    }
    else
    {
        printf("\n Erro numero maximo de UCs antigido\n");
    }
}

int procurarUC(int num_UC,tipoUC vetor_UC[],int cod_uc)
{
    int pos=-1,i;
    for (i=0; i<num_UC; i++)
    {
        if (cod_uc==vetor_UC[i].codigo) //se o codigo for igual
        {
            pos=i;                     //posicao fica igual ao indice
            i=num_UC;              //e o indice fica igual a quantidade para terminar o ciclo for
        }
    }
    return pos;
}

void listarUC(int num_UC,tipoUC vetor_UC[])
{
    int i;
    if (num_UC != 0)
    {
        printf("\n\n Informacoes das Unidades Curriculares\n\n");
        for (i=0; i<num_UC; i++)
        {
            printf("\n Codigo:%d",vetor_UC[i].codigo);
            printf("\tDesignacao:%s",vetor_UC[i].designacao);
            if (vetor_UC[i].tipo==1)
            {
                printf("\tTipo:Obrigatoria");
            }
            else
            {
                printf("\tTipo:Opcional");
            }
            printf("\tSemestre:%d",vetor_UC[i].semestre);
            if (vetor_UC[i].regime==1)
            {
                printf("\tRegime:Diurno\n");
            }
            else
            {
                printf("\tRegime:Pos-Laboral\n");
            }
            printf(" Quantidade de Aulas Online Previstas: %dT(%d min cada)",vetor_UC[i].aulaOnPrev.qnt_T,vetor_UC[i].aulaOnPrev.duracao_T);
            printf(" +%dTP(%d min cada)",vetor_UC[i].aulaOnPrev.qnt_TP,vetor_UC[i].aulaOnPrev.duracao_TP);
            printf(" +%dPL(%d min cada)\n",vetor_UC[i].aulaOnPrev.qnt_PL,vetor_UC[i].aulaOnPrev.duracao_PL);
        }
    }
    else
    {
        printf("\n ERRO: Ainda nao foram listadas Unidades Curriculares\n\n");
    }
}

void alterarUC(int num_UC,tipoUC vetor_UC[])
{
    int cod_uc,i,escolha;
    if (num_UC != 0)
    {
        cod_uc=lerInteiro(" Codigo da UC a alterar:",100,999);
        i=procurarUC(num_UC,vetor_UC,cod_uc);//vai a função procurar se existe alguma UC com o codigo que se pretende alterar
        if (i!=-1)//caso o indice seja -1 nao existe nenhuma UC com esse codigo
        {
            do
            {
                do
                {
                    printf(" 1-Designacao 2-Tipo 3-Semestre 4-Regime 5-Quantidade Prevista de Aulas Online 6-Sair\n");
                    escolha=lerInteiro(" Qual o campo que deseja alterar ?",1,6);
                    if (escolha!=1 && escolha!=2 && escolha!=3 && escolha!=4 && escolha!=5 && escolha!=6)
                    {
                        printf(" \t\t ERRO: Opcao invalida\n\t\t Insira uma nova opcao--> ");
                    }
                }
                while (escolha!=1 && escolha!=2 && escolha!=3 && escolha!=4 && escolha!=5 && escolha!=6);
                switch (escolha)
                {
                case 1:
                    lerString(" Designacao Unidade Curricular:",vetor_UC[i].designacao,MAX_STRING);
                    break;
                case 2:
                    vetor_UC[i].tipo=lerInteiro(" Tipo UC(1-Obrigatoria 2-Opcional):",1,2);
                    break;
                case 3:
                    vetor_UC[i].semestre=lerInteiro("Semestre da UC:",1,6);
                case 4:
                    vetor_UC[i].regime=lerInteiro(" Regime da UC(1-Diurno 2-Pos-Laboral):",1,2);
                    break;
                case 5:
                    vetor_UC[i].aulaOnPrev.qnt_T=lerInteiro(" Quantidade de Aulas T online previstas:",0,MAX_AULAS);
                    if ( vetor_UC[i].aulaOnPrev.qnt_T!=0)
                    {
                        vetor_UC[i].aulaOnPrev.duracao_T=lerInteiro(" Tempo da Aula online (minutos):",MIN_TEMPO_AULA,MAX_TEMPO_AULA);
                    }
                    else
                    {
                        vetor_UC[i].aulaOnPrev.duracao_T=0;
                    }
                    vetor_UC[i].aulaOnPrev.qnt_TP=lerInteiro(" Quantidade de Aulas  TP online previstas:",0,MAX_AULAS);
                    if ( vetor_UC[i].aulaOnPrev.qnt_TP!=0)
                    {
                        vetor_UC[i].aulaOnPrev.duracao_TP=lerInteiro(" Tempo da Aula TP(min):",MIN_TEMPO_AULA,MAX_TEMPO_AULA);
                    }
                    else
                    {
                        vetor_UC[i].aulaOnPrev.duracao_TP=0;
                    }
                    vetor_UC[i].aulaOnPrev.qnt_PL=lerInteiro(" Quantidade de Aulas Online PL previstas:",0,MAX_AULAS);
                    if ( vetor_UC[i].aulaOnPrev.qnt_PL!=0)
                    {
                        vetor_UC[i].aulaOnPrev.duracao_PL=lerInteiro(" Tempo da Aula PL(min):",MIN_TEMPO_AULA,MAX_TEMPO_AULA);
                    }
                    else
                    {
                        vetor_UC[i].aulaOnPrev.duracao_PL=0;
                    }
                    break;
                case 6:
                    printf(" Alteracoes efetuadas com sucesso");
                    break;
                }
            }
            while (escolha!=6);
        }
        else
        {
            printf(" ERRO: Nao existe nenhuma UC com esse codigo");
        }
    }
    else
    {
        printf("\n ERRO: Ainda nao foram listadas Unidades Curriculares\n\n");
    }
}


