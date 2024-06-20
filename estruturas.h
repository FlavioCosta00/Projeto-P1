#ifndef ESTRUTURAS_H_INCLUDED
#define ESTRUTURAS_H_INCLUDED
#include "constantes.h"

typedef struct
{
    int minuto;//0 a 59
    int hora;//0 a 24
} tipoHora;

typedef struct
{
    int dia;//1 a 31
    int mes;//1 a 12
    int ano;//2020 a 2021
} tipoData;

typedef struct
{
    int qnt_T;//Quantidade de aulas Teoricas Totais
    int qnt_TP;//Quantidade de aulas Teorico-Práticas Totais
    int qnt_PL;//Quantidade de aulas Praticas Totais
    int qnt_T_Agendada;//Quantidade de aulas Teoricas Agendadas
    int qnt_TP_Agendada;//Quantidade de aulas Teorico-Práticas Agendadas
    int qnt_PL_Agendada;//Quantidade de aulas Praticas Agendadas
    int duracao_T;//Duracao das aulas Teoricas em minutos
    int duracao_TP;//Duracao das aulas Teorico Praticas em minutos
    int duracao_PL;//Duracao das aulas Praticas em minutos
} tipoAulaOnPrevista;

typedef struct
{
    char designacao[MAX_STRING];//Nome da UC
    int codigo;//Codigo da UC unico de 100 a 999
    int tipo;//1-Obrigatória 2-Opcional
    int semestre;//1 a 6
    int regime;//1-Diurno 2-Pós-Laboral
    tipoAulaOnPrevista aulaOnPrev;//Estrutura tipoAulaOnPrevista
    int qnt_acessos_gravacoes;//quantidade de acessos as gravacoes da UC
    int aulas_gravadas;//0-Nao tem aulas gravadas  !=0Tem aulas gravadas esta UC
    int qnt_aulas_realizadas;//Quantidade de Aulas realizadas desta UC
}   tipoUC;

typedef struct
{
    char designacao[MAX_STRING];//
    int codigo_UC;//Codigo da UC do vetor tipo UC
    int tipo_aula_online;//tipo aula 1-T,2-TP ou 3-PL
    char nome_docente[MAX_STRING];//nome do docente que vai lecionar a aula
    tipoData data;
    tipoHora hora_i;//hora inicial da aula
    tipoHora hora_f;//hora final da aula
    int estado_aula;//1-Agendada 2-A decorrer 3- Realizada
    int opcao_gravacao;//1-Sim 2-Não
    int qnt_presencas;//Quantidade de presencas em cada aula
    int qnt_acessos_gravacoes;//Quantidade de acessos as gravacoes se a aula estiver a ser gravada
} tipoAulaOn;

typedef struct
{
    int numero;//Numero do estudante
    char designacao_aula[100][MAX_STRING];//Designacao das aulas em que acedeu
    int tipo_acesso[100];//1-Acesso online 2-Acesso offline a gravacao
    int total_aulas;//Total de Aulas do Aluno
} tipoAcessoEST;

#endif // ESTRUTURAS_H_INCLUDED
