#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funcoes_AulaOn.h"

tipoAulaOn *AgendarAula(tipoAulaOn vetor_AulaOn[],int *num_A,int *num_AA,tipoUC vetor_UC[],int num_UC)
{
    int cod_UC,pos,pos2,i,controlo=0;
    char designacao[MAX_STRING];
    int vetor=1;
    tipoData data;
    tipoHora hora_i;
    tipoHora hora_f;
    tipoAulaOn *vBackup;
    vBackup=vetor_AulaOn;
    if (num_UC != 0)
    {
        lerString("\n Designacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,*num_A,designacao);
        if (pos!=-1)
        {
            printf(" ERRO: Essa designacao ja existe");
        }
        else
        {
            do
            {
                cod_UC=lerInteiro(" Codigo UC:",100,999);
                pos2=procurarUC(num_UC,vetor_UC,cod_UC);
                if (pos2==-1)
                {
                    printf(" ERRO: Nao existe nenhuma Unidade Curricular com esse Codigo\n");
                }
            }
            while (pos2==-1);
            vetor_AulaOn=realloc(vetor_AulaOn,(vetor)*sizeof(tipoAulaOn));
            if (vetor_AulaOn==NULL)
            {
                printf(" ERRO: Erro ao reserver memoria");
                vetor_AulaOn=vBackup;
            }
            else
            {

                do
                {

                    printf(" Insira a data da aula:\n");
                    data=lerData();

                    do
                    {

                        if (vetor_UC[pos2].regime==1)
                        {
                            printf("Inicio da aula:\n");
                            hora_i=lerHora(8,17);
                            printf("Fim da aula\n");
                            hora_f=lerHora(8,18);
                            if (hora_f.hora==18)
                            {
                                hora_f.minuto=0;
                            }
                        }
                        else
                        {
                            printf("Inicio da aula:\n");
                            hora_i=lerHora(18,23);
                            printf("Fim da aula\n");
                            hora_f=lerHora(18,24);
                            if (hora_f.hora==24)
                            {
                                hora_f.minuto=0;
                            }
                        }

                        if (hora_i.hora >= hora_f.hora && hora_i.minuto >= hora_f.minuto)
                        {
                            printf(" ERRO: A hora inicial de uma aula nao pode ser igual ou superior a aula final da aula.\n");
                        }

                    }
                    while (hora_i.hora >= hora_f.hora && hora_i.minuto >= hora_f.minuto);

                    if(*num_A != 0)
                    {
                        for (i=0; i<*num_A; i++)
                        {
                            if(vetor_UC[pos2].codigo == cod_UC)
                            {
                                if (vetor_AulaOn[i].data.ano == data.ano && vetor_AulaOn[i].data.mes == data.mes && vetor_AulaOn[i].data.dia == data.dia)
                                {
                                    if (vetor_AulaOn[i].hora_i.hora < hora_f.hora && vetor_AulaOn[i].hora_f.hora > hora_i.hora)
                                    {
                                        printf(" ERRO: Insira novamente a data.");
                                    }
                                    else
                                    {
                                        controlo++;
                                    }
                                }
                                else
                                {
                                    controlo++;
                                }
                            }
                            else
                            {
                                controlo++;
                            }
                        }
                    }
                    else
                    {
                        controlo++;
                    }
                }
                while(controlo==0);

                strcpy(vetor_AulaOn[*num_A].designacao, designacao);
                vetor_AulaOn[*num_A].estado_aula=1;//Estado da Aula Agendada=1
                vetor_AulaOn[*num_A].codigo_UC=cod_UC;
                vetor_AulaOn[*num_A].tipo_aula_online=lerInteiro(" Tipo da Aula Online(1-T 2-TP 3-PL):",1,3);
                if( vetor_AulaOn[*num_A].tipo_aula_online==1)
                {
                    vetor_UC[pos2].aulaOnPrev.qnt_T_Agendada--;
                }
                else
                {
                    if(vetor_AulaOn[*num_A].tipo_aula_online==2)
                    {
                        vetor_UC[pos2].aulaOnPrev.qnt_TP_Agendada--;
                    }
                    else
                    {
                        vetor_UC[pos2].aulaOnPrev.qnt_PL_Agendada--;
                    }
                }
                lerString(" Nome do Docente:",vetor_AulaOn[*num_A].nome_docente,MAX_STRING);
                vetor_AulaOn[*num_A].data=data;
                vetor_AulaOn[*num_A].hora_i=hora_i;
                vetor_AulaOn[*num_A].hora_f=hora_f;
                (*num_A)++;
                (*num_AA)++;
                vetor++;
            }
        }
    }
    else
    {
        printf("\n ERRO: Ainda nao foram listadas Unidades Curriculares\n\n");
    }
    return vetor_AulaOn;
}


int procurarAula (tipoAulaOn vetor_AulaOn[],int num_A,char designacao[])
{
    int pos=-1,i;

    for (i=0; i<num_A; i++)
    {
        if(strcmp(vetor_AulaOn[i].designacao,designacao)==0)
        {
            pos=i;
            i=num_A;
        }
    }
    return pos;
}

void ListarAulas (tipoAulaOn vetor_AulaOn[],int num_A)
{
    int i;
    if(num_A!=0)
    {
        printf("\nListagem das Aulas Agendadas\n");
        for (i=0; i<num_A; i++)
        {
            printf("\nDesignacao:%s \tNome do Docente:%s",vetor_AulaOn[i].designacao,vetor_AulaOn[i].nome_docente);
            if (vetor_AulaOn[i].tipo_aula_online==1)
            {
                printf("\tTipo:T");
            }
            else
            {
                if (vetor_AulaOn[i].tipo_aula_online==2)
                {
                    printf("\tTipo:TP");
                }
                else
                {
                    printf("\tTipo:PL");
                }
            }
            if (vetor_AulaOn[i].estado_aula==1)
            {
                printf("\nEstado Aula: Agendada ");
            }
            else
            {
                if(vetor_AulaOn[i].estado_aula==2)
                {
                    printf("\nEstado Aula:A decorrer ");
                }
                else
                {
                    printf("\nEstado Aula:Realizada \t Quantidade de Presencas: %d \t Quantidade de Acessos as gravacoes: %d \n ",vetor_AulaOn[i].qnt_presencas,vetor_AulaOn[i].qnt_acessos_gravacoes);
                }
            }
            printf("Data %d / %d / %d ",vetor_AulaOn[i].data.dia,vetor_AulaOn[i].data.mes,vetor_AulaOn[i].data.ano);
            printf(" das %d : %d ate as %d : %d",vetor_AulaOn[i].hora_i.hora,vetor_AulaOn[i].hora_i.minuto,vetor_AulaOn[i].hora_f.hora,vetor_AulaOn[i].hora_f.minuto);
        }
    }
    else
    {
        printf(" ERRO: Nao existem Aulas");
    }
}

tipoAulaOn *EliminarAulasAgendadas(tipoAulaOn vetor_AulaOn[],int *num_A,int *num_AA)
{
    char designacao[MAX_STRING];
    tipoAulaOn *vBackup;
    int pos,i;
    vBackup=vetor_AulaOn;
    if (*num_AA==0)
    {
        printf(" ERRO: Nao existe Aulas Agendadas");
    }
    else
    {
        lerString(" Designacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,*num_A,designacao);
        if (pos==-1)
        {
            printf(" ERRO: Essa designacao nao existe");
        }
        else
        {
            if (vetor_AulaOn[pos].estado_aula==1)
            {
                strcpy( vetor_AulaOn[pos].designacao, designacao);
                for (i=pos; i<*num_A-1; i++)
                {
                    vetor_AulaOn[i]=vetor_AulaOn[i+1];
                }
                vetor_AulaOn = realloc(vetor_AulaOn,(*num_A-1)*sizeof(tipoAulaOn));
                if (vetor_AulaOn==NULL && (*num_A-1)!=0)
                {
                    vetor_AulaOn=vBackup;
                    printf(" ERRO: Erro ao reserver memoria");
                }
                printf(" Aula Agendada Eliminada com sucesso");
                (*num_A)--;
                (*num_AA)--;
            }
            else
            {
                printf(" ERRO: A aula esta a deccorrer ou ja foi realizada");
            }
        }
    }
    return vetor_AulaOn;
}

tipoAulaOn *AlterarAulasAgendadas(tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_A,int num_AA,int num_UC)
{
    char designacao[MAX_STRING];
    int pos,i,cod_UC,pos2,controlo=0;
    tipoData data;
    tipoHora hora_i;
    tipoHora hora_f;


    if (num_AA==0)
    {
        printf(" ERRO: Nao existe Aulas Agendadas");
    }
    else
    {
        lerString(" Designacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,num_A,designacao);
        if (pos==-1)
        {
            printf(" ERRO: Essa designacao nao existe");
        }
        else
        {
            do
            {
                cod_UC=vetor_AulaOn[pos].codigo_UC;
                pos2=procurarUC(num_UC,vetor_UC,cod_UC);
                if (pos2==-1)
                {
                    printf(" ERRO: Nao existe nenhuma Unidade Curricular com esse Codigo\n");
                }
            }
            while (pos2==-1);

            if (vetor_AulaOn[pos].estado_aula==1)
            {



                do
                {

                    printf(" Insira a data da aula:\n");
                    data=lerData();

                    do
                    {

                        if (vetor_UC[pos2].regime==1)
                        {
                            printf("Inicio da aula:\n");
                            hora_i=lerHora(8,17);
                            printf("Fim da aula\n");
                            hora_f=lerHora(8,18);
                            if (hora_f.hora==18)
                            {
                                hora_f.minuto=0;
                            }
                        }
                        else
                        {
                            printf("Inicio da aula:\n");
                            hora_i=lerHora(18,23);
                            printf("Fim da aula\n");
                            hora_f=lerHora(18,24);
                            if (hora_f.hora==24)
                            {
                                hora_f.minuto=0;
                            }
                        }

                        if (hora_i.hora >= hora_f.hora && hora_i.minuto >= hora_f.minuto)
                        {
                            printf(" ERRO: A hora inicial de uma aula nao pode ser igual ou superior a aula final da aula.\n");
                        }

                    }
                    while (hora_i.hora >= hora_f.hora && hora_i.minuto >= hora_f.minuto);

                    for (i=0; i<num_A; i++)
                    {
                        if(vetor_UC[pos2].codigo == cod_UC)
                        {
                            if (vetor_AulaOn[i].data.ano == data.ano && vetor_AulaOn[i].data.mes == data.mes && vetor_AulaOn[i].data.dia == data.dia)
                            {
                                if (vetor_AulaOn[i].hora_i.hora < hora_f.hora && vetor_AulaOn[i].hora_f.hora > hora_i.hora)
                                {
                                    printf(" ERRO: A data inserida coicide com a de outra aula da mesma UC.");
                                }
                                else
                                {
                                    controlo++;
                                }
                            }
                            else
                            {
                                controlo++;
                            }
                        }
                        else
                        {
                            controlo++;
                        }
                    }
                }
                while(controlo==0);

                vetor_AulaOn[pos].hora_i=hora_i;
                vetor_AulaOn[pos].hora_f=hora_f;
                vetor_AulaOn[pos].data=data;

            }
            else
            {
                printf(" ERRO: A aula esta a deccorrer ou ja foi realizada");
            }

        }
    }
    return vetor_AulaOn;
}

tipoAulaOn *ComecarAulaOnline (tipoAulaOn vetor_AulaOn[],int num_A,int *num_AA,int *num_AG,tipoUC vetor_UC[],int num_UC)
{
    char designacao[MAX_STRING];
    int pos,pos2,cod_UC;
    if (*num_AA==0)
    {
        printf(" ERRO: Nao existem aulas previamente agendadas");
    }
    else
    {
        lerString(" Designacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,num_A,designacao);
        cod_UC=vetor_AulaOn[pos].codigo_UC;
        pos2=procurarUC(num_UC,vetor_UC,cod_UC);
        if (pos==-1 || vetor_AulaOn[pos].estado_aula==2 || vetor_AulaOn[pos].estado_aula==3)
        {
            printf(" ERRO: Nao existe nenhuma Aula Agendada com essa designacao");
        }
        else
        {
            vetor_AulaOn[pos].estado_aula=2; //Estado da Aula passa para (a decorrer)
            vetor_AulaOn[pos].opcao_gravacao=lerInteiro("Opcao Gravacao(1-Sim 2-Nao):",1,2);
            if (vetor_AulaOn[pos].opcao_gravacao==1)
            {
                vetor_UC[pos2].aulas_gravadas++;
                vetor_AulaOn[pos].qnt_acessos_gravacoes=0;
                (*num_AG)++;
            }
            vetor_AulaOn[pos].qnt_presencas=0;
            (*num_AA)--;
            printf(" A aula comecou com sucesso");
        }
    }
    return vetor_AulaOn;
}

tipoAulaOn *TerminarAulaOnline (tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_A,int *num_AR,int num_UC)
{
    char designacao[MAX_STRING];
    int pos,pos2,cod_UC;
    if (num_A==0)
    {
        printf(" ERRO: Nao existem aulas");
    }
    else
    {
        lerString(" Designacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,num_A,designacao);
        cod_UC=vetor_AulaOn[pos].codigo_UC;
        pos2=procurarUC(num_UC,vetor_UC,cod_UC);
        if (pos==-1 || vetor_AulaOn[pos].estado_aula!=2)
        {
            printf(" ERRO: Nao existe nenhuma Aula a decorrer com essa designacao");
        }
        else
        {
            vetor_AulaOn[pos].estado_aula=3; //Estado da Aula passa para Realizada
            printf(" A aula passou para o estado realizada");
            if (vetor_AulaOn[pos].opcao_gravacao==1)
            {
                printf(" e foi gravada");
            }
            else
            {
                printf(" e nao foi gravada");
            }
            vetor_UC[pos2].qnt_aulas_realizadas++;
            (*num_AR)++;
        }
    }
    return vetor_AulaOn;
}

int procurarEstudante(int num_EST,tipoAcessoEST vetor_estudantes[],int num_estudante)
{
    int pos=-1,i;
    for (i=0; i<num_EST; i++)
    {
        if (vetor_estudantes[i].numero==num_estudante) //se o codigo for igual
        {
            pos=i;                     //posicao fica igual ao indice
            i=num_EST;              //e o indice fica igual a quantidade para terminar o ciclo for
        }
    }
    return pos;
}

tipoAulaOn *RegistarAcessoEstudante (tipoAulaOn vetor_AulaOn[],tipoAcessoEST vetor_estudantes[],tipoUC vetor_UC[],int num_A,int *num_EST,int num_UC)
{
    char designacao[MAX_STRING],tipo_acesso[MAX_STRING];
    int pos,pos2,pos3,num_estudante,estado_aula=0,cod_UC,qnt_presencas=0,qnt_acessos_gravacoes=0;
    if (num_A==0)
    {
        printf(" ERRO: Nao existe nenhuma Aula!\n");
    }
    else
    {
        printf(" Registar acesso de um estudante\n");
        lerString(" Designacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,num_A,designacao);
        if (pos==-1)
        {
            printf(" ERRO: Nao existe nenhuma aula com essa designacao\n");
        }
        else
        {
            vetor_AulaOn=realloc(vetor_AulaOn,(num_A)*sizeof(tipoAulaOn));
            estado_aula=vetor_AulaOn[pos].estado_aula;
            if (estado_aula==1 || (estado_aula==3 && vetor_AulaOn[pos].opcao_gravacao==2))
            {
                printf(" ERRO: Nao e possivel aceder a uma aula agendada ou uma aula realizada sem gravacao\n");
            }
            else
            {
                num_estudante=lerInteiro(" Numero do Estudante:",NUM_ESTUDANTE_MIN,NUM_ESTUDANTE_MAX);
                pos2=procurarEstudante(*num_EST,vetor_estudantes,num_estudante);
                if (pos2==-1)//PRIMEIRO ACESSO A UMA AULA DE UM ESTUDANTE
                {
                    if (*num_EST==MAX_ESTUDANTES)
                    {
                        printf(" Limite maximo de estudantes no curso foi antigido");
                    }
                    else
                    {
                        vetor_estudantes[*num_EST].total_aulas=0;
                        vetor_estudantes[*num_EST].numero=num_estudante;
                        strcpy( vetor_estudantes[*num_EST].designacao_aula[vetor_estudantes[*num_EST].total_aulas], designacao);
                        if (estado_aula==2)
                        {
                            vetor_estudantes[*num_EST].tipo_acesso[vetor_estudantes[*num_EST].total_aulas]=1;
                            printf("Acesso Online");
                            strcpy( tipo_acesso, "Acesso: Online");
                            qnt_presencas++;
                        }
                        else
                        {
                            vetor_estudantes[*num_EST].tipo_acesso[vetor_estudantes[*num_EST].total_aulas]=2;
                            printf("Acesso Offline a gravacao");
                            strcpy( tipo_acesso, "Acesso: Offline a gravacao");
                            cod_UC=vetor_AulaOn[pos].codigo_UC;
                            pos3=procurarUC(num_UC,vetor_UC,cod_UC);
                            vetor_UC[pos3].qnt_acessos_gravacoes++;
                            qnt_acessos_gravacoes++;
                        }
                        vetor_estudantes[*num_EST].total_aulas++;
                        (*num_EST)++;
                    }
                }
                else//ESTUDANTES QUE JA ACEDERAM A PELO MENOS UMA AULA
                {
                    strcpy( vetor_estudantes[pos2].designacao_aula[vetor_estudantes[pos2].total_aulas], designacao);
                    if (estado_aula==2)
                    {
                        vetor_estudantes[*num_EST].tipo_acesso[vetor_estudantes[*num_EST].total_aulas]=1;
                        printf("Acesso Online");
                        strcpy( tipo_acesso, "Acesso: Online");
                        qnt_presencas++;
                    }
                    else
                    {
                        vetor_estudantes[*num_EST].tipo_acesso[vetor_estudantes[*num_EST].total_aulas]=2;
                        printf("Acesso Offline a gravacao");
                        strcpy( tipo_acesso, "Acesso: Offline a gravacao");
                        cod_UC=vetor_AulaOn[pos].codigo_UC;
                        pos3=procurarUC(num_UC,vetor_UC,cod_UC);
                        vetor_UC[pos3].qnt_acessos_gravacoes++;
                        qnt_acessos_gravacoes++;
                    }
                    vetor_estudantes[pos2].total_aulas++;
                }
            }
            ficheiroLogAcessoEstudante(designacao,num_estudante,tipo_acesso);//ADICIONAR NO FICHEIRO LOG REGISTO ESTUDANTE
            gravaAcessoEstudante(designacao,num_estudante,tipo_acesso);//ADICIONAR NO FICHEIRO BINARIO REGISTO ESTUDANTE
            vetor_AulaOn[pos].estado_aula=estado_aula;
            if(qnt_presencas==1){
                vetor_AulaOn[pos].qnt_presencas++;
            }
            if(qnt_acessos_gravacoes==1){
                  vetor_AulaOn[pos].qnt_acessos_gravacoes++;
            }
        }
    }
    return vetor_AulaOn;
}

void ConsultarAula(tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_A,int num_UC)
{
    char designacao[MAX_STRING];
    int pos,pos2,cod_UC;
    int qnt_AA_PL=0,qnt_AA_T=0,qnt_AA_TP=0; //Quantidades de Aulas de cada tipo por agendar.
    if (num_A==0)
    {
        printf(" ERRO: Nao existe nenhuma Aula!\n");
    }
    else
    {
        lerString(" \nDesignacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,num_A,designacao);
        if (pos==-1)
        {
            printf(" ERRO: Essa designacao nao existe");
        }
        else
        {
            cod_UC=vetor_AulaOn[pos].codigo_UC;
            pos2=procurarUC(num_UC,vetor_UC,cod_UC);
            qnt_AA_T=vetor_UC[pos2].aulaOnPrev.qnt_T + vetor_UC[pos2].aulaOnPrev.qnt_T_Agendada;
            qnt_AA_TP=vetor_UC[pos2].aulaOnPrev.qnt_TP + vetor_UC[pos2].aulaOnPrev.qnt_TP_Agendada;
            qnt_AA_PL=vetor_UC[pos2].aulaOnPrev.qnt_PL + vetor_UC[pos2].aulaOnPrev.qnt_PL_Agendada;
            printf("UC: %s ",vetor_UC[pos2].designacao);
            printf("Quantidade de Aulas por Agendar: T- %d TP- %d PL- %d \n",qnt_AA_T,qnt_AA_TP,qnt_AA_PL);
            printf("Designacao:%s \tNome do Docente:%s",vetor_AulaOn[pos].designacao,vetor_AulaOn[pos].nome_docente);
            if (vetor_AulaOn[pos].tipo_aula_online==1)
            {
                printf("\tTipo:T");
            }
            else
            {
                if (vetor_AulaOn[pos].tipo_aula_online==2)
                {
                    printf("\tTipo:TP");
                }
                else
                {
                    printf("\tTipo:PL");
                }
            }
            if (vetor_AulaOn[pos].estado_aula==1)
            {
                printf("\nEstado Aula: Agendada ");
            }
            else
            {
                if(vetor_AulaOn[pos].estado_aula==2)
                {
                    printf("\nEstado Aula:A decorrer ");
                }
                else
                {
                    printf("\nEstado Aula:Realizada ");
                }
            }
            printf("Data %d / %d / %d ",vetor_AulaOn[pos].data.dia,vetor_AulaOn[pos].data.mes,vetor_AulaOn[pos].data.ano);
            printf(" das %d : %d ate as %d : %d",vetor_AulaOn[pos].hora_i.hora,vetor_AulaOn[pos].hora_i.minuto,vetor_AulaOn[pos].hora_f.hora,vetor_AulaOn[pos].hora_f.minuto);
        }
    }
}

void ListagemEstPresentes(tipoAcessoEST vetor_estudantes[],int num_EST,tipoAulaOn vetor_AulaOn[],int num_A)
{
    int i,j,pos,total_aulas;//numero estudante variavel auxiliar
    char designacao[MAX_STRING];
    if (num_EST==0)
    {
        printf(" \nNao existem estudantes\n");
    }
    else
    {
        printf(" \n Listagem dos Estudantes Presentes numa aula online\n");
        lerString(" Designacao:",designacao,MAX_STRING);
        pos=procurarAula(vetor_AulaOn,num_A,designacao);
        if (pos==-1 || vetor_AulaOn[pos].estado_aula==1)
        {
            printf(" ERRO: Nao existe nenhuma aula a decorrer ou realizada com essa designacao ");
        }
        else
        {
            for(i=0; i<num_EST; i++)
            {
                total_aulas=vetor_estudantes[i].total_aulas;
                for (j=0; j<total_aulas; j++)
                {
                    if (strcmp(vetor_estudantes[i].designacao_aula[j],designacao)==0 && vetor_estudantes[i].tipo_acesso[j]==1)
                    {
                        printf(" Numero Estudante: %d \n",vetor_estudantes[i].numero);
                        j=total_aulas;
                    }
                }
            }
        }
    }
}

