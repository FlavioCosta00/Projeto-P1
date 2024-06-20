#ifndef FUNCOES_MENU_H_INCLUDED
#define FUNCOES_MENU_H_INCLUDED
#include "funcoes_menu.h"
#include "funcoes_auxiliares.h"
#include "funcoes_UC.h"
#include "estruturas.h"
#include "funcoes_estatisticas.h"

char MenuPrincipal(int num_UC,int num_AA,int num_AR,int num_AG);
void menuUnidadesCurriculares(tipoUC vetor_UC[],int *num_UC);
tipoAulaOn *menuAulasOnline(tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_UC,int *num_A,int *num_AA,int *num_AR,int *num_AG);
tipoAulaOn *menuEstudantes (tipoAulaOn vetor_AulaOn[],tipoAcessoEST vetor_estudantes[],tipoUC vetor_UC[],int num_A,int *num_EST,int num_UC);
void  menuDadosEstatisticos(tipoUC vetor_UC[],int num_UC,tipoAulaOn vetor_AulaOn[],int num_A);

#endif // FUNCOES_MENU_H_INCLUDED
