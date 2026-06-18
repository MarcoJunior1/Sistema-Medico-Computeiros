#include <stdio.h>
#include <string.h>
#include "globais.h"
#include "medico.h"

void moduloMedicos() {
    int opcao = 0;
    while (opcao != 8) {
        printf("\n===== SISTEMA DE MÉDICOS =====\n");
        printf("1 - Cadastrar médico\n");
        printf("2 - Listar médicos\n");
        printf("3 - Remover médico (Exclusão Lógica)\n");
        printf("4 - Buscar médico por CRM\n");
        printf("5 - Buscar médico por especialidade\n");
        printf("6 - Alterar dados do médico\n");
        printf("7 - Informar horários disponíveis\n");
        printf("8 - Voltar ao Menu Principal\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            if (medicosCadastrados < MAX_MEDICOS) {
                medicos[medicosCadastrados].id = medicosCadastrados + 1;
                medicos[medicosCadastrados].ativo = 1;

                printf("Nome: ");
                fgets(medicos[medicosCadastrados].nome, 50, stdin);
                medicos[medicosCadastrados].nome[strcspn(medicos[medicosCadastrados].nome, "\n")] = '\0';

                printf("Telefone: ");
                fgets(medicos[medicosCadastrados].telefone, 20, stdin);
                medicos[medicosCadastrados].telefone[strcspn(medicos[medicosCadastrados].telefone, "\n")] = '\0';

                printf("CRM (Apenas números): ");
                fgets(medicos[medicosCadastrados].crm, 10, stdin);
                medicos[medicosCadastrados].crm[strcspn(medicos[medicosCadastrados].crm, "\n")] = '\0';

                printf("Horário de atendimento: ");
                fgets(medicos[medicosCadastrados].horarios, 20, stdin);
                medicos[medicosCadastrados].horarios[strcspn(medicos[medicosCadastrados].horarios, "\n")] = '\0';
                
                strcpy(medicos[medicosCadastrados].especialidadeMedico, "Nao associada");

                medicosCadastrados++;
                printf("Médico cadastrado com sucesso!\n");
            } else {
                printf("Limite de médicos atingido!\n");
            }
        }
        else if (opcao == 2) {
            int cont = 0;
            printf("----------- Lista de Médicos -----------\n");
            for (int i = 0; i < medicosCadastrados; i++) {
                if (medicos[i].ativo == 1) {
                    printf("ID: %d;\nNome: %s;\nTelefone: %s;\nCRM: %s;\nEspecialidade: %s.\n----------------------\n\n",
                           medicos[i].id, medicos[i].nome, medicos[i].telefone, medicos[i].crm, medicos[i].especialidadeMedico);
                    cont++;
                }
            }
            if (cont == 0) printf("Nenhum médico cadastrado ou ativo.\n");
        }
        else if (opcao == 3) {
            char medicodeletado[50];
            int oescolhido = -1;

            printf("Qual médico deseja deletar (Nome completo)?\n");
            fgets(medicodeletado, 50, stdin);
            medicodeletado[strcspn(medicodeletado, "\n")] = '\0';

            for (int i = 0; i < medicosCadastrados; i++) {
                if (strcmp(medicos[i].nome, medicodeletado) == 0 && medicos[i].ativo == 1) {
                    oescolhido = i;
                    break;
                }
            }
            if (oescolhido != -1) {
                medicos[oescolhido].ativo = 0; 
                printf("Médico removido com sucesso (Inativado).\n");
            } else {
                printf("Médico não encontrado para remoção.\n");
            }
        }
        else if (opcao == 4) {
            char buscarcrm[10];
            int medencontrado = 0;
            printf("Digite o CRM do médico para buscar: ");
            fgets(buscarcrm, 10, stdin);
            buscarcrm[strcspn(buscarcrm, "\n")] = '\0';

            for (int i = 0; i < medicosCadastrados; i++) {
                if (strcmp(medicos[i].crm, buscarcrm) == 0 && medicos[i].ativo == 1) {
                    printf("Medico encontrado:\nID: %d\nNome: %s\nTelefone: %s\nCRM: %s\nEspecialidade: %s\n",
                           medicos[i].id, medicos[i].nome, medicos[i].telefone, medicos[i].crm, medicos[i].especialidadeMedico);
                    medencontrado = 1;
                }
            }
            if (!medencontrado) printf("Médico não encontrado!\n");
        }
        else if (opcao == 5) {
            char buscarEsp[50];
            int ESPencontrada = 0;
            printf("Digite a especialidade do médico para buscar: ");
            fgets(buscarEsp, 50, stdin);
            buscarEsp[strcspn(buscarEsp, "\n")] = '\0';

            for (int i = 0; i < medicosCadastrados; i++) {
                if (strcmp(medicos[i].especialidadeMedico, buscarEsp) == 0 && medicos[i].ativo == 1) {
                    printf("Médico encontrado:\nID: %d\nNome: %s\nCRM: %s\n-----------------\n",
                           medicos[i].id, medicos[i].nome, medicos[i].crm);
                    ESPencontrada = 1;
                }
            }
            if (!ESPencontrada) printf("Nenhum médico encontrado com essa especialidade!\n");
        }
        else if (opcao == 6) {
            int medicoALT = 0, dadoAlterado = 0;
            printf("Digite o ID do médico que deseja alterar: ");
            scanf("%d", &medicoALT);
            
            if(medicoALT > 0 && medicoALT <= medicosCadastrados && medicos[medicoALT-1].ativo == 1) {
                printf("Qual tipo de dado deseja alterar?:\n1 - Nome\n2 - Telefone\n3 - CRM\n");
                scanf("%d", &dadoAlterado);
                getchar();

                if (dadoAlterado == 1) {
                    printf("Qual é o novo nome do médico? ");
                    fgets(medicos[medicoALT - 1].nome, 50, stdin);
                    medicos[medicoALT - 1].nome[strcspn(medicos[medicoALT - 1].nome, "\n")] = '\0';
                    printf("Nome alterado com sucesso!\n");
                } else if (dadoAlterado == 2) {
                    printf("Qual é o novo telefone do médico? ");
                    fgets(medicos[medicoALT - 1].telefone, 20, stdin);
                    medicos[medicoALT - 1].telefone[strcspn(medicos[medicoALT - 1].telefone, "\n")] = '\0';
                    printf("Telefone alterado com sucesso!\n");
                } else if (dadoAlterado == 3) {
                    printf("Qual é o novo CRM do médico? ");
                    fgets(medicos[medicoALT - 1].crm, 10, stdin);
                    medicos[medicoALT - 1].crm[strcspn(medicos[medicoALT - 1].crm, "\n")] = '\0';
                    printf("CRM alterado com sucesso!\n");
                } else {
                    printf("Opção inválida!\n");
                }
            } else {
                printf("Médico não encontrado.\n");
            }
        }
        else if (opcao == 7) {
            printf("\n--- Horários Disponíveis dos Médicos ---\n");
            for (int i = 0; i < medicosCadastrados; i++) {
                if (medicos[i].ativo == 1) {
                    printf("Médico: %s | Horários: %s\n", medicos[i].nome, medicos[i].horarios);
                }
            }
        }
    }
}