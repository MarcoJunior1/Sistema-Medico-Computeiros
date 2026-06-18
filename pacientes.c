#include <stdio.h>
#include <string.h>
#include "globais.h"
#include "pacientes.h"

void moduloPacientes() {
    int opcao = 0;
    int telefoneValido, numTelefone, cpfValido, numCpf, statusConvenio, convenioValido;

    while (opcao != 8) {
        printf("\n-----=====[ Módulo Pacientes ]=====-----\n");
        printf("1 - Cadastrar paciente\n");
        printf("2 - Listar pacientes\n");
        printf("3 - Buscar paciente por ID\n");
        printf("4 - Buscar paciente por nome\n");
        printf("5 - Alterar dados de paciente\n");
        printf("6 - Verificar convenio de paciente\n");
        printf("7 - Excluir paciente (Lógico)\n");
        printf("8 - Voltar ao Menu Principal\n");
        printf("====================================\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1) {
            if (totalPacientes < MAX) {
                paciente[totalPacientes].id = totalPacientes + 1;
                paciente[totalPacientes].ativo = 1;

                printf("Nome: ");
                fgets(paciente[totalPacientes].nome, 50, stdin);
                paciente[totalPacientes].nome[strcspn(paciente[totalPacientes].nome, "\n")] = '\0';

                do {
                    printf("Idade: ");
                    scanf("%d", &paciente[totalPacientes].idade);
                    getchar();
                    if (paciente[totalPacientes].idade < 0 || paciente[totalPacientes].idade > 130) {
                        printf("\nIdade invalida.\n");
                    }
                } while (paciente[totalPacientes].idade < 0 || paciente[totalPacientes].idade > 130);

                do {
                    telefoneValido = 1;
                    printf("Telefone (somente números): ");
                    fgets(paciente[totalPacientes].telefone, 20, stdin);
                    paciente[totalPacientes].telefone[strcspn(paciente[totalPacientes].telefone, "\n")] = '\0';
                    numTelefone = strlen(paciente[totalPacientes].telefone);

                    if (numTelefone < 10 || numTelefone > 11) {
                        telefoneValido = 0;
                    } else {
                        for (int i = 0; i < numTelefone; i++) {
                            if (paciente[totalPacientes].telefone[i] < '0' || paciente[totalPacientes].telefone[i] > '9') {
                                telefoneValido = 0;
                                break;
                            }
                        }
                    }
                    if (telefoneValido == 0) printf("\nNumero de telefone invalido.\n");
                } while (!telefoneValido);

                do {
                    cpfValido = 1;
                    printf("CPF (11 dígitos, apenas números): ");
                    fgets(paciente[totalPacientes].cpf, 20, stdin);
                    paciente[totalPacientes].cpf[strcspn(paciente[totalPacientes].cpf, "\n")] = '\0';
                    numCpf = strlen(paciente[totalPacientes].cpf);

                    if (numCpf != 11) {
                        cpfValido = 0;
                    } else {
                        for (int i = 0; i < numCpf; i++) {
                            if (paciente[totalPacientes].cpf[i] < '0' || paciente[totalPacientes].cpf[i] > '9') {
                                cpfValido = 0;
                                break;
                            }
                        }
                    }
                    if (cpfValido == 0) printf("\nNumero de CPF invalido.\n");
                } while (!cpfValido);

                do {
                    convenioValido = 1;
                    printf("Possui convenio? (0=nao / 1=sim): ");
                    scanf("%d", &statusConvenio);
                    if (statusConvenio < 0 || statusConvenio > 1) {
                        printf("\nValor invalido, tente novamente.\n");
                        convenioValido = 0;
                    } else {
                        paciente[totalPacientes].convenio = statusConvenio;
                    }
                    getchar();
                } while (!convenioValido);

                totalPacientes++;
                printf("\nPaciente cadastrado com sucesso!\n");
            } else {
                printf("\nLimite de pacientes atingido!\n");
            }
        }
        else if (opcao == 2) {
            int cont = 0;
            printf("\n----====[Lista de Pacientes]====----\n");
            for (int i = 0; i < totalPacientes; i++) {
                if (paciente[i].ativo == 1) {
                    printf("Id: %d\nPaciente: %s\nIdade: %d\nTelefone: %s\nCPF: %s\nStatus convenio: %s\n----------------------\n",
                           paciente[i].id, paciente[i].nome, paciente[i].idade, paciente[i].telefone, paciente[i].cpf, paciente[i].convenio ? "Ativado" : "Desativado");
                    cont++;
                }
            }
            if (cont == 0) printf("Nenhum paciente ativo encontrado.\n");
        }
        else if (opcao == 3) {
            int idPaciente, encontrado = 0;
            printf("\nId do paciente: ");
            scanf("%d", &idPaciente);
            getchar();

            for (int i = 0; i < totalPacientes; i++) {
                if (paciente[i].id == idPaciente && paciente[i].ativo == 1) {
                    printf("\n-------======[Paciente]======-------\n");
                    printf("Id: %d\nPaciente: %s\nTelefone: %s\nCPF: %s\nStatus convenio: %s\n",
                           paciente[i].id, paciente[i].nome, paciente[i].telefone, paciente[i].cpf, paciente[i].convenio ? "Ativado" : "Desativado");
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) printf("\nPaciente nao encontrado ou excluído.\n");
        }
        else if (opcao == 4) {
            char nomePaciente[50];
            int encontrado = 0;
            printf("\nNome do paciente: ");
            fgets(nomePaciente, sizeof(nomePaciente), stdin);
            nomePaciente[strcspn(nomePaciente, "\n")] = '\0';

            for (int i = 0; i < totalPacientes; i++) {
                if (strcmp(paciente[i].nome, nomePaciente) == 0 && paciente[i].ativo == 1) {
                    printf("\n-------======[Paciente]======-------\n");
                    printf("Id: %d\nPaciente: %s\nTelefone: %s\nCPF: %s\nStatus convenio: %s\n",
                           paciente[i].id, paciente[i].nome, paciente[i].telefone, paciente[i].cpf, paciente[i].convenio ? "Ativado" : "Desativado");
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) printf("\nPaciente nao encontrado.\n");
        }
        else if (opcao == 5) {
            int idPaciente, encontrado = 0;
            printf("\nId do paciente que deseja alterar: ");
            scanf("%d", &idPaciente);
            getchar();

            for (int i = 0; i < totalPacientes; i++) {
                if (paciente[i].id == idPaciente && paciente[i].ativo == 1) {
                    encontrado = 1;
                    int opcaoAlterar;
                    do {
                        printf("\nDeseja alterar qual informacao?\n");
                        printf("1 - Nome\n2 - Idade\n3 - Telefone\n4 - CPF\n5 - Convenio\n6 - Sair\n");
                        scanf("%d", &opcaoAlterar);
                        getchar();

                        if (opcaoAlterar == 1) {
                            printf("Novo Nome: ");
                            fgets(paciente[i].nome, sizeof(paciente[i].nome), stdin);
                            paciente[i].nome[strcspn(paciente[i].nome, "\n")] = '\0';
                        } else if (opcaoAlterar == 2) {
                            printf("Nova Idade: ");
                            scanf("%d", &paciente[i].idade);
                            getchar();
                        } else if (opcaoAlterar == 3) {
                            printf("Novo Telefone: ");
                            fgets(paciente[i].telefone, sizeof(paciente[i].telefone), stdin);
                            paciente[i].telefone[strcspn(paciente[i].telefone, "\n")] = '\0';
                        } else if (opcaoAlterar == 4) {
                            printf("Novo CPF: ");
                            fgets(paciente[i].cpf, sizeof(paciente[i].cpf), stdin);
                            paciente[i].cpf[strcspn(paciente[i].cpf, "\n")] = '\0';
                        } else if (opcaoAlterar == 5) {
                            printf("Status do convenio (0=nao / 1=sim): ");
                            int st;
                            scanf("%d", &st);
                            paciente[i].convenio = st;
                            getchar();
                        }
                    } while (opcaoAlterar != 6);
                    printf("\nAlteracao concluida com sucesso!\n");
                    break;
                }
            }
            if (!encontrado) printf("\nPaciente nao encontrado.\n");
        }
        else if (opcao == 6) {
            int idPaciente, encontrado = 0;
            printf("\nId do paciente: ");
            scanf("%d", &idPaciente);
            getchar();
            for (int i = 0; i < totalPacientes; i++) {
                if (paciente[i].id == idPaciente && paciente[i].ativo == 1) {
                    printf("\nPaciente: %s | Status convenio: %s\n", paciente[i].nome, paciente[i].convenio ? "Ativado" : "Desativado");
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) printf("\nPaciente nao encontrado.\n");
        }
        else if (opcao == 7) {
            int idPaciente, encontrado = 0;
            printf("\nId do paciente a ser removido (Exclusão Lógica): ");
            scanf("%d", &idPaciente);
            getchar();

            for (int i = 0; i < totalPacientes; i++) {
                if (paciente[i].id == idPaciente && paciente[i].ativo == 1) {
                    paciente[i].ativo = 0; 
                    printf("\nPaciente removido com sucesso de forma lógica!\n");
                    encontrado = 1;
                    break;
                }
            }
            if (!encontrado) printf("\nPaciente nao encontrado.\n");
        }
    }
}