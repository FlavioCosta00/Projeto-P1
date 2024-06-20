#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "funcoes_menu.h"
#include "funcoes_auxiliares.h"
#include "funcoes_UC.h"
#include "funcoes_AulaOn.h"
#include "estruturas.h"

char MenuPrincipal(int num_UC,int num_AA,int num_AR,int num_AG)
{
    int escolha;
    do
    {
        printf("\n Projeto PL1 - GD08\n");
        printf(" 2201707-Flavio Costa\n");
        printf(" 2191607-Henrique Santos\n");
        printf("\n\tNumero de UCs: %d \t\t Aulas Agendadas: %d \n\tAulas Realizadas: %d \t\t Aulas Gravadas: %d  \n",num_UC,num_AA,num_AR,num_AG);
        escolha = lerChar("\n\n U - Unidades Curriculares\n A - Aulas Online\n E - Estudantes\n D - Dados Estatisticos\n R - Ranking UCs\n G - Guardar Estado do Programa\n C - Carregar Dados para o Programa \n S - Sair\n\n Opcao: ");
        if (escolha!='U' && escolha!='A' && escolha!='E' && escolha!='D' && escolha!='R' && escolha!='G' && escolha!='C' && escolha!='S')
        {
            printf("\n\n ERRO: Opcao invalida,insira novamente.\n");
        }
    }
    while (escolha!='U' && escolha!='A' && escolha!='E' && escolha!='D' && escolha!='R' && escolha!='G' && escolha!='C' && escolha!='S');
    return escolha;
}

void menuUnidadesCurriculares(tipoUC vetor_UC[],int *num_UC)
{
    int escolha;
    do
    {
        printf("\n ******************************************************************\n\n                  ** MENU UNIDADES CURRICULARES **");
        do
        {
            printf("\n\n Introduza uma opcao:");
            escolha = lerInteiro("\n\n (1) Inserir UC\n (2) Listar UCs\n (3) Alterar UC\n (0) Menu Principal\n\n Opcao: ",0,3);
            if(escolha!= 1 && escolha!= 2 && escolha!= 3 && escolha!= 0)
            {
                printf("\n\n ERRO: Opcao invalida,insira novamente.\n");
            }
        }
        while(escolha!= 1 && escolha!= 2 && escolha!= 3 && escolha!= 0);
        switch(escolha)
        {
        case 1://Inserir UC
            inserirUC(&(*num_UC),vetor_UC);
            break;
        case 2://Listar UC
            listarUC(*num_UC,vetor_UC);
            break;
        case 3://Alterar UC
            alterarUC(*num_UC,vetor_UC);
            break;
        case 0://Menu Principal
            break;
        }
    }
    while(escolha!= 0);
}

tipoAulaOn *menuAulasOnline(tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_UC,int *num_A,int *num_AA,int *num_AR,int *num_AG)
{
    int escolha;
    do
    {
        printf("\n ******************************************************************\n\n                  ** MENU AULAS ONLINE **");
        do
        {
            printf("\n\n Introduza uma opcao:");
            escolha = lerInteiro("\n\n (1) Agendar Aula Online\n (2) Listar Aulas Online\n (3) Alterar Agendamento Aula Online\n (4) Eliminar Agendamento Aula Online\n (5) Comecar Aula\n (6) Terminar Aula\n (7) Consultar Aula\n (0) Menu Principal\n\nOpcao: ",0,7);
            if(escolha!= 1 && escolha!= 2 && escolha!= 3 && escolha!= 4 && escolha!= 5 && escolha!= 6 && escolha!= 7 && escolha!= 0)
            {
                printf("\n\n ERRO: Opcao invalida,insira novamente.\n");
            }
        }
        while(escolha!= 1 && escolha!= 2 && escolha!= 3 && escolha!= 4 && escolha!= 5 && escolha!= 6 && escolha!= 7 && escolha!= 0);
        switch(escolha)
        {
        case 1://Agendar Aula
            vetor_AulaOn=AgendarAula(vetor_AulaOn,&(*num_A),&(*num_AA),vetor_UC,num_UC);
            break;
        case 2://Listar Aula
            ListarAulas (vetor_AulaOn,*num_A);
            break;
        case 3://Alterar Agendamento Aula
            vetor_AulaOn=AlterarAulasAgendadas(vetor_AulaOn,vetor_UC,*num_A,*num_AA,num_UC);
            break;
        case 4://Eliminar Aula Agendada
            vetor_AulaOn=EliminarAulasAgendadas(vetor_AulaOn,&(*num_A),&(*num_AA));
            break;
        case 5://Comecar Aula
            vetor_AulaOn=ComecarAulaOnline(vetor_AulaOn,*num_A,&(*num_AA),&(*num_AG),vetor_UC,num_UC);
            break;
        case 6://Terminar Aula
            vetor_AulaOn=TerminarAulaOnline(vetor_AulaOn,vetor_UC,*num_A,&(*num_AR),num_UC);
            break;
        case 7://Consultar Aula
            ConsultarAula(vetor_AulaOn,vetor_UC,*num_A,num_UC);
        case 0://Menu Principal
            break;
        }
    }
    while(escolha!= 0);
    return vetor_AulaOn;
}

tipoAulaOn *menuEstudantes (tipoAulaOn vetor_AulaOn[],tipoAcessoEST vetor_estudantes[],tipoUC vetor_UC[],int num_A,int *num_EST,int num_UC)
{
    int escolha;
    do
    {
        printf("\n ******************************************************************\n\n                  ** MENU ESTUDANTES **");
        do
        {
            printf("\n\n Introduza uma opcao:");
            escolha = lerInteiro("\n\n (1) Registar Acesso Estudante\n (2) Listar Estudantes Presentes numa Aula\n (0) Menu Principal\n\nOpcao: ",0,2);
            if(escolha!= 1 && escolha!= 2 && escolha!= 0)
            {
                printf("\n\n ERRO: Opcao invalida,insira novamente.\n");
            }
        }
        while(escolha!= 1 && escolha!= 2 && escolha!= 0);
        switch(escolha)
        {
        case 1://Registar Acesso de um Estudante
            vetor_AulaOn=RegistarAcessoEstudante(vetor_AulaOn,vetor_estudantes,vetor_UC,num_A,&(*num_EST),num_UC);
            break;
        case 2://Listar Estudantes Presentes
            ListagemEstPresentes(vetor_estudantes,*num_EST,vetor_AulaOn,num_A);
            break;
        case 0://Menu Principal
            break;
        }
    }
    while(escolha!= 0);
    return vetor_AulaOn;
}

void  menuDadosEstatisticos(tipoUC vetor_UC[],int num_UC,tipoAulaOn vetor_AulaOn[],int num_A)
{
    int escolha;
    do
    {
        printf("\n ******************************************************************\n\n                  ** MENU DADOS ESTATISTICOS **");
        do
        {
            printf("\n\n Introduza uma opcao:");
            escolha = lerInteiro("\n\n (1) Quantidade Media de Presencas\n (2) Percentagem de UCs com Aulas Gravadas\n (3) UCs com menor quantidade de Aulas online realizadas\n (4) Tipo de Aulas com maior quantidade de acessos as gravacoes\n (5) Aulas Online Realizadas a mais tempo\n (0) Menu Principal\n\nOpcao: ",0,5);
            if(escolha!= 1 && escolha!= 2 && escolha!= 3 && escolha!= 4 && escolha!= 5 && escolha!= 0)
            {
                printf("\n\n ERRO: Opcao invalida,insira novamente.\n");
            }
        }
        while(escolha!= 1 && escolha!= 2 && escolha!= 3 && escolha!= 4 && escolha!= 5 && escolha!= 0);
        switch(escolha)
        {
        case 1://Quantidade Media de Presencas
            QntMediaPresencasAR(vetor_AulaOn,num_A);
            break;
        case 2://Mostar Percentagem de Uc´s Com Aulas Gravadas
            PercentagemUCsAG(vetor_UC,num_UC);
            break;
        case 3://Listar UCs com menor quantidade de Aulas online realizadas
            UCsComMenorQntAR (vetor_UC,num_UC);
            break;
        case 4://Listar Tipo de Aulas com maior quantidade de acessos as gravacoes

            break;
        case 5://Listar Aulas Online Realizadas a mais tempo

            break;
        case 0://Menu Principal
            break;
        }
    }
    while(escolha!= 0);
}
