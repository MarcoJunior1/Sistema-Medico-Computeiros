#include <stdio.h>

//Relatório Completo do Sistema Médico

int main(){

    int totalPacientes;
    int totalMedico;
    int totalConsultas;

    printf("============================================\n");
    printf("Total de Pacientes Cadastrados: %d", totalPacientes);
    printf("Total de Médicos Cadastrados: %d", totalMedico);
    printf("============================================\n");

    int consultasCadastradas;
    int consultasCanceladas;
    int consultasRealizadas;

    printf("========Total Consultas Específicas=========\n");
    printf("Total de Consultas Cadastradas: %d", consultasCadastradas);
    printf("Consultas Canceladas: %d", consultasCanceladas);
    printf("Consultas Realizadas: %d", consultasRealizadas);
    printf("============================================\n");

    int pesquisaEspecifica;

    printf("===========Pesquisa Específica=============\n");
    printf("1. Pesquisar por Médico");
    printf("2. Pesquisar por Especialidade");
    printf("===========================================\n");

    scanf("%d", &pesquisaEspecifica);

    char nomeMedico[50];
    int numeroConsultasporMedico[50];

    if(pesquisaEspecifica == 1){
        printf("=======================================\n");
        printf("Lista de Médicos");
        printf("Número de Consultas Realizadas: %s", numeroConsultasporMedico);
        printf("=======================================\n");
    };
    
    if(pesquisaEspecifica == 2){
        printf("=======================================\n");
        printf("Qual Especialidade?");
        
        char selecEspecialidade[50];
        char nomeEspecialidade[50];

        scanf("%s", &selecEspecialidade);

        if(selecEspecialidade == 1){
            printf("Especialidade: %s", selecEspecialidade);
            printf("Número de Consultas Cadastradas de %s: ");
        };

    };

    return 0;
}