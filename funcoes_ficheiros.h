#ifndef FUNCOES_FICHEIROS_H_INCLUDED
#define FUNCOES_FICHEIROS_H_INCLUDED

#include "estruturas.h"

//DADOS UNIDADES CURRICULARES
void gravaFicheiroBinarioUC(int num_UC, tipoUC vetor_UC[]);
void lerFicheiroBinarioUC(int *num_UC, tipoUC vetor_UC[]);

//DADOS AULAS ONLINE
void gravaFicheiroBinarioAulasOnline(tipoAulaOn *vetor_AulaOn,int num_A);
void lerFicheiroBinarioAulasOnline(tipoAulaOn vetor_AulaOn[],int num_A);

//INFORMACOES APRESENTDAS NO MENU
void gravaFicheiroBinarioInformacoes(int num_AA,int num_AR,int num_AG,int num_A);
void lerFicheiroBinarioInformacoes(int *num_AA,int *num_AR,int *num_AG,int *num_A);

//ACESSOS ESTUDANTES
void ficheiroLogAcessoEstudante(char designacao[MAX_STRING], int num_estudante,char tipo_acesso[MAX_STRING]);
void gravaAcessoEstudante(char designacao[MAX_STRING], int num_estudante,char tipo_acesso[MAX_STRING]);

void gravaFicheiroBinarioEstudantes(int num_EST,  tipoAcessoEST vetor_estudantes[]);
void lerFicheiroBinarioEstudantes(int *num_EST,  tipoAcessoEST vetor_estudantes[]);

#endif // FUNCOES_FICHEIROS_H_INCLUDED
