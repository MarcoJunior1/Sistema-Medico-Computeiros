#include <stdio.h>
#include <string.h>
#include "globais.h"
#include "relatorios.h"
#include "consulta.h" // Necessário para usar a função exibirConsulta

void moduloRelatorios() {
    int totalPacientesAtivos = 0;
    for(int i = 0; i < totalPacientes; i++) {
        if(paciente[i].ativo == 1) totalPacientesAtivos++;
    }

    int totalMedicosAtivos = 0;
    for(int i = 0; i < medicosCadastrados; i++) {
        if(medicos[i].ativo == 1) totalMedicosAtivos++;
    }

    int consultasAgendadas = 0;
    int consultasCanceladas = 0;
    int consultasRealizadas = 0;

    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].cancelada) consultasCanceladas++;
        else if (consultas[i].realizada) consultasRealizadas++;
        else consultasAgendadas++;
    }

    printf("\n============================================\n");
    printf("Total de Pacientes Ativos Cadastrados: %d\n", totalPacientesAtivos);
    printf("Total de Médicos Ativos Cadastrados: %d\n", totalMedicosAtivos);
    printf("============================================\n");

    printf("======== Total Consultas Específicas =========\n");
    printf("Total de Consultas Agendadas (Aguardando): %d\n", consultasAgendadas);
    printf("Consultas Canceladas: %d\n", consultasCanceladas);
    printf("Consultas Realizadas: %d\n", consultasRealizadas);
    printf("============================================\n");

    int pesquisaEspecifica;
    printf("=========== Pesquisa Específica =============\n");
    printf("1. Consultas por Médico (por CRM)\n");
    printf("2. Consultas por Especialidade\n");
    printf("Escolha uma opção: ");
    scanf("%d", &pesquisaEspecifica);
    getchar();

    if (pesquisaEspecifica == 1) {
        int crmBusca;
        int totalDoMed = 0;
        printf("Digite o CRM do Médico para o relatório de consultas: ");
        scanf("%d", &crmBusca);
        
        printf("=======================================\n");
        for(int i = 0; i < totalConsultas; i++) {
            if(consultas[i].crmMedico == crmBusca) {
                exibirConsulta(consultas[i]);
                totalDoMed++;
            }
        }
        printf("Total de Consultas encontradas para o CRM %d: %d\n", crmBusca, totalDoMed);
        printf("=======================================\n");
    }
    
    if (pesquisaEspecifica == 2) {
        char espBusca[50];
        int totalDaEsp = 0;
        printf("Qual Especialidade deseja pesquisar? ");
        fgets(espBusca, 50, stdin);
        espBusca[strcspn(espBusca, "\n")] = '\0';

        printf("=======================================\n");
        for(int i = 0; i < totalConsultas; i++) {
            if(strcmp(consultas[i].especialidade, espBusca) == 0) {
                exibirConsulta(consultas[i]);
                totalDaEsp++;
            }
        }
        printf("Total de Consultas para a Especialidade '%s': %d\n", espBusca, totalDaEsp);
        printf("=======================================\n");
    }
}