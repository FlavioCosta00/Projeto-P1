#ifndef FUNCOES_AULAON_H_INCLUDED
#define FUNCOES_AULAON_H_INCLUDED
#include "estruturas.h"
#include "funcoes_auxiliares.h"
#include "funcoes_UC.h"
#include "funcoes_ficheiros.h"

tipoAulaOn *AgendarAula(tipoAulaOn vetor_AulaOn[],int *num_A,int *num_AA,tipoUC vetor_UC[],int num_UC);
int procurarAula (tipoAulaOn vetor_AulaOn[],int num_A,char designacao[]);
void ListarAulas (tipoAulaOn vetor_AulaOn[],int num_A);
tipoAulaOn *EliminarAulasAgendadas(tipoAulaOn vetor_AulaOn[],int *num_A,int *num_AA);
tipoAulaOn *AlterarAulasAgendadas(tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_A,int num_AA,int num_UC);

tipoAulaOn *ComecarAulaOnline (tipoAulaOn vetor_AulaOn[],int num_A,int *num_AA,int *num_AG,tipoUC vetor_UC[],int num_UC);
tipoAulaOn *TerminarAulaOnline (tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_A,int *num_AR,int num_UC);
tipoAulaOn *RegistarAcessoEstudante (tipoAulaOn vetor_AulaOn[],tipoAcessoEST vetor_estudantes[],tipoUC vetor_UC[],int num_A,int *num_EST,int num_UC);

void ConsultarAula(tipoAulaOn vetor_AulaOn[],tipoUC vetor_UC[],int num_A,int num_UC);
void ListagemEstPresentes(tipoAcessoEST vetor_estudantes[],int num_EST,tipoAulaOn vetor_AulaOn[],int num_A);

#endif // FUNCOES_AULAON_H_INCLUDED
