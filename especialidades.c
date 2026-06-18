#include <stdio.h>
#include <string.h>
#include "globais.h"
#include "especialidades.h"

void CadastrarEspecialidade(char arrayDestino[]) {
    printf("Digite o nome da nova especialidade: ");
    fgets(arrayDestino, TAMANHO_NOME, stdin);
    arrayDestino[strcspn(arrayDestino, "\n")] = '\0';
}

void moduloEspecialidades() {
    int numeroSelecionado = 0;
    while (numeroSelecionado != 5) {
        printf("\n======== SUBMENU ESPECIALIDADES ======== \n");
        printf("1 - Cadastrar Especialidade \n");
        printf("2 - Listar Especialidade \n");
        printf("3 - Associar Médico a Especialidade \n");
        printf("4 - Relatório de Especialidades \n");
        printf("5 - Voltar ao Menu Principal \n");
        printf("Escolha uma opção: ");
        scanf("%d", &numeroSelecionado);
        getchar();

        if (numeroSelecionado == 1) {
            if (especialidadesCadastradas < MAX_ESPECIALIDADES) {
                CadastrarEspecialidade(especialidades[especialidadesCadastradas]);
                printf("Nova especialidade cadastrada: %s \n", especialidades[especialidadesCadastradas]);
                especialidadesCadastradas++;
            } else {
                printf("Limite de especialidades atingido.\n");
            }
        }
        else if (numeroSelecionado == 2) {
            if (especialidadesCadastradas == 0) {
                printf("Nenhuma especialidade cadastrada \n");
            } else {
                printf("======== LISTA DE ESPECIALIDADES ======== \n");
                for (int i = 0; i < especialidadesCadastradas; i++) {
                    printf("Especialidade número: %d -> %s\n", i + 1, especialidades[i]);
                    printf("------------------------------------------------ \n");
                }
            }
        }
        else if (numeroSelecionado == 3) {
            int numeroMedico;
            int numeroEspecialidade;

            printf("======== LISTA DE MÉDICOS CADASTRADOS ======== \n");
            for (int i = 0; i < medicosCadastrados; i++) {
                if (medicos[i].ativo == 1) {
                    printf("Número (ID) do Médico: %d \n", medicos[i].id);
                    printf("Nome do Médico: %s \n", medicos[i].nome);
                    printf("------------------------------------------------ \n");
                }
            }

            printf("Digite o ID do médico que deseja associar uma especialidade: ");
            scanf("%d", &numeroMedico);

            printf("======== LISTA DE ESPECIALIDADES ======== \n");
            for (int i = 0; i < especialidadesCadastradas; i++) {
                printf("Especialidade número: %d -> %s\n", i + 1, especialidades[i]);
            }

            printf("Digite o número da especialidade correspondente: ");
            scanf("%d", &numeroEspecialidade);

            if (numeroMedico > 0 && numeroMedico <= medicosCadastrados && numeroEspecialidade > 0 && numeroEspecialidade <= especialidadesCadastradas) {
                strcpy(medicos[numeroMedico - 1].especialidadeMedico, especialidades[numeroEspecialidade - 1]);
                printf("\nEspecialidade associada com sucesso! \n");
            } else {
                printf("Médico ou Especialidade inválida.\n");
            }
        }
        else if (numeroSelecionado == 4) {
            int numeroEspecialidade;
            int quantidadeEspecialistas = 0;

            printf("======== LISTA DE ESPECIALIDADES ======== \n");
            for (int i = 0; i < especialidadesCadastradas; i++) {
                printf("Especialidade número: %d -> %s\n", i + 1, especialidades[i]);
            }

            printf("Digite o número da especialidade para relatório: ");
            scanf("%d", &numeroEspecialidade);

            if (numeroEspecialidade > 0 && numeroEspecialidade <= especialidadesCadastradas) {
                printf("======== LISTA DE MÉDICOS POR ESPECIALIDADE ======== \n");
                printf("Especialidade selecionada: %s \n", especialidades[numeroEspecialidade - 1]);

                for (int i = 0; i < medicosCadastrados; i++) {
                    if (medicos[i].ativo == 1 && strcmp(medicos[i].especialidadeMedico, especialidades[numeroEspecialidade - 1]) == 0) {
                        printf("Número do Médico: %d | Nome: %s \n", medicos[i].id, medicos[i].nome);
                        quantidadeEspecialistas++;
                    }
                }

                if (quantidadeEspecialistas == 0) {
                    printf("Nenhum médico especialista nessa área! \n");
                } else {
                    printf("Número de médicos especialistas em %s: %d \n", especialidades[numeroEspecialidade - 1], quantidadeEspecialistas);
                }
            }
        }
    }
}