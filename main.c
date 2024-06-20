#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "constantes.h"
#include "funcoes_ficheiros.h"
#include "funcoes_menu.h"
#include "funcoes_UC.h"
#include "funcoes_AulaOn.h"
#include "funcoes_estatisticas.h"

int main()
{
    //DECLARACAO DE VARIAVEIS
    char escolha;

    //INICIALIZAÇÃO A ZERO

    int num_AA=0;//Quantidade de Aulas Agendadas
    int num_AR=0;//Quantidade de Aulas Realizadas
    int num_AG=0;//Quantidade de Aulas Gravadas
    int num_A=0;//Quantidade Total de Aulas
    int num_EST=0;//Quantidade de Estudantes
    int num_UC=0;//Quantidade UCs

    tipoUC vetor_UC[MAX_UC];//Vetor Unidades Curriculares
    tipoAulaOn *vetor_AulaOn=NULL;//Vetor Dinâmico Aulas Online
    tipoAcessoEST vetor_estudantes[MAX_ESTUDANTES];//VETOR ESTUDANTES

    vetor_AulaOn=malloc(1*sizeof(tipoAulaOn));//Inicializar o bloco de memoria

    do
    {
        escolha = MenuPrincipal(num_UC,num_AA,num_AR,num_AG);// Chama a função -> char MenuPrincipal(int num_UC,int num_AA,int num_AR,int num_AG)
        switch (escolha)
        {
        case 'U'://UNIDADES CURRICULARES

            menuUnidadesCurriculares(vetor_UC,&num_UC);
            // Chama a função -> void menuUnidadesCurriculares(tipoUC vetor_UC[],int *num_UC)

            break;
        case 'A'://AULAS ONLINE

            vetor_AulaOn = menuAulasOnline(vetor_AulaOn,vetor_UC,num_UC,&num_A,&num_AA,&num_AR,&num_AG);
            // Chama a função -> tipoAulaOn *menuAulasOnline(tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_UC,int *num_A,int *num_AA,int *num_AR,int *num_AG)

            break;
        case 'E'://ESTUDANTES
            vetor_AulaOn = menuEstudantes(vetor_AulaOn,vetor_estudantes,vetor_UC,num_A,&num_EST,num_UC);
            break;
        case 'D'://DADOS ESTATISTICOS
           menuDadosEstatisticos(vetor_UC,num_UC,vetor_AulaOn,num_A);
                break;
        case 'R'://RANKING UCS
            RankingUCs(vetor_UC,num_UC);
            break;
        case 'G'://GRAVAR ESTADO DO PROGRAMA
            gravaFicheiroBinarioUC(num_UC,vetor_UC);
            gravaFicheiroBinarioInformacoes(num_AA,num_AR,num_AG,num_A);
            gravaFicheiroBinarioAulasOnline(vetor_AulaOn,num_A);
            gravaFicheiroBinarioEstudantes(num_EST,vetor_estudantes);
            break;
        case 'C'://CARREGAR INFORMACOES PARA O PROGRAMA
            lerFicheiroBinarioUC(&num_UC,vetor_UC);
            lerFicheiroBinarioInformacoes(&num_AA,&num_AR,&num_AG,&num_A);
            vetor_AulaOn=realloc(vetor_AulaOn,(num_A)*sizeof(tipoAulaOn));
            lerFicheiroBinarioAulasOnline(vetor_AulaOn,num_A);
            lerFicheiroBinarioEstudantes(&num_EST,vetor_estudantes);
            break;
        case 'S'://SAIR DO PROGRAMA
            printf("Fim do programa\n");
            break;
        }
    }
    while(escolha!='S');
    free(vetor_AulaOn);//LIBERTAR MEMORIA ALOCADA
    return 0;
}
