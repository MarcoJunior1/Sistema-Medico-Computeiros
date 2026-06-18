#include <stdio.h>
#include <string.h>
#include "globais.h"
#include "consulta.h"

int buscarConsultaPorCodigo(int codigo) {
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].codigoConsulta == codigo) {
            return i;
        }
    }
    return -1;
}

int horarioDisponivel(int crm, char data[], char horario[]) {
    for (int i = 0; i < totalConsultas; i++) {
        if (consultas[i].crmMedico == crm &&
            strcmp(consultas[i].data, data) == 0 &&
            strcmp(consultas[i].horario, horario) == 0 &&
            consultas[i].cancelada == 0) {
            return 0; 
        }
    }
    return 1; 
}

void exibirConsulta(Consulta c) {
    printf("\n==============================");
    printf("\nCodigo: %d", c.codigoConsulta);
    printf("\nPaciente (ID): %d", c.codigoPaciente);
    printf("\nCRM Medico: %d", c.crmMedico);
    printf("\nEspecialidade: %s", c.especialidade);
    printf("\nData: %s", c.data);
    printf("\nHorario: %s", c.horario);

    if (c.cancelada)
        printf("\nStatus: Cancelada");
    else if (c.realizada)
        printf("\nStatus: Realizada");
    else
        printf("\nStatus: Agendada");
    printf("\n==============================\n");
}

void moduloConsultas() {
    int opcao = 0;
    while (opcao != 8) {
        printf("\n===== MÓDULO CONSULTAS =====\n");
        printf("1 - Agendar Consulta\n");
        printf("2 - Listar Consultas\n");
        printf("3 - Buscar Consulta por Paciente\n");
        printf("4 - Buscar Consulta por Médico\n");
        printf("5 - Cancelar Consulta\n");
        printf("6 - Alterar Data ou Horário\n");
        printf("7 - Marcar Consulta como Realizada\n");
        printf("8 - Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            Consulta nova;
            if (totalConsultas >= MAX_CONSULTAS) {
                printf("Limite de consultas atingido.\n");
                return;
            }
            printf("Codigo da consulta: ");
            scanf("%d", &nova.codigoConsulta);

            if (buscarConsultaPorCodigo(nova.codigoConsulta) != -1) {
                printf("Codigo ja existente.\n");
                continue;
            }

            printf("Codigo (ID) do paciente: ");
            scanf("%d", &nova.codigoPaciente);

            printf("CRM do medico (apenas números): ");
            scanf("%d", &nova.crmMedico);

            printf("Especialidade: ");
            scanf("%s", nova.especialidade);

            printf("Data (dd/mm/aaaa): ");
            scanf("%10s", nova.data);

            printf("Horario (hh:mm): ");
            scanf("%5s", nova.horario);

            if (!horarioDisponivel(nova.crmMedico, nova.data, nova.horario)) {
                printf("Horario indisponivel para este médico.\n");
                continue;
            }

            nova.realizada = 0;
            nova.cancelada = 0;

            consultas[totalConsultas] = nova;
            totalConsultas++;
            printf("Consulta agendada com sucesso.\n");
        }
        else if (opcao == 2) {
            if (totalConsultas == 0) {
                printf("Nenhuma consulta cadastrada.\n");
            } else {
                for (int i = 0; i < totalConsultas; i++) {
                    exibirConsulta(consultas[i]);
                }
            }
        }
        else if (opcao == 3) {
            int codigo, encontrou = 0;
            printf("Codigo (ID) do paciente: ");
            scanf("%d", &codigo);

            for (int i = 0; i < totalConsultas; i++) {
                if (consultas[i].codigoPaciente == codigo) {
                    exibirConsulta(consultas[i]);
                    encontrou = 1;
                }
            }
            if (!encontrou) printf("Nenhuma consulta encontrada para este paciente.\n");
        }
        else if (opcao == 4) {
            int crm, encontrou = 0;
            printf("CRM do medico: ");
            scanf("%d", &crm);

            for (int i = 0; i < totalConsultas; i++) {
                if (consultas[i].crmMedico == crm) {
                    exibirConsulta(consultas[i]);
                    encontrou = 1;
                }
            }
            if (!encontrou) printf("Nenhuma consulta encontrada para este médico.\n");
        }
        else if (opcao == 5) {
            int codigo, pos;
            printf("Codigo da consulta: ");
            scanf("%d", &codigo);
            pos = buscarConsultaPorCodigo(codigo);

            if (pos == -1) {
                printf("Consulta nao encontrada.\n");
            } else {
                consultas[pos].cancelada = 1;
                printf("Consulta cancelada com sucesso.\n");
            }
        }
        else if (opcao == 6) {
            int codigo, pos;
            printf("Codigo da consulta: ");
            scanf("%d", &codigo);
            pos = buscarConsultaPorCodigo(codigo);

            if (pos == -1) {
                printf("Consulta nao encontrada.\n");
            } else if (consultas[pos].cancelada || consultas[pos].realizada) {
                printf("Esta consulta já foi realizada ou cancelada.\n");
            } else {
                printf("Nova data: ");
                scanf("%10s", consultas[pos].data);
                printf("Novo horario: ");
                scanf("%5s", consultas[pos].horario);
                printf("Consulta alterada com sucesso.\n");
            }
        }
        else if (opcao == 7) {
            int codigo, pos;
            printf("Codigo da consulta: ");
            scanf("%d", &codigo);
            pos = buscarConsultaPorCodigo(codigo);

            if (pos == -1) {
                printf("Consulta nao encontrada.\n");
            } else if (consultas[pos].cancelada) {
                printf("Consulta está cancelada.\n");
            } else {
                consultas[pos].realizada = 1;
                printf("Consulta marcada como realizada.\n");
            }
        }
    }
}