#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX 100

struct Paciente
{
    int id, idade;
    char nome[50];
    char telefone[20];
    char cpf[20];
    bool convenio;
};

int main()
{
    struct Paciente paciente[MAX];

    int opcao = 0;
    int total = 0;
    int telefoneValido, numTelefone, cpfValido, numCpf, statusConvenio, convenioValido;

    while (opcao != 8)
    {
        printf("-----=====[Clinica Medica]=====-----\n");
        printf("1 - Cadastrar paciente.\n");
        printf("2 - Listar pacientes.\n");
        printf("3 - Buscar paciente por ID.\n");
        printf("4 - Buscar paciente por nome.\n");
        printf("5 - Alterar dados de paciente.\n");
        printf("6 - Verificar convenio de paciente.\n");
        printf("7 - Excluir paciente.\n");
        printf("8 - Sair.\n");
        printf("====================================\n");
        scanf("%d", &opcao);
        getchar();

        if (opcao == 1)
        {
            if (total < MAX)
            {
                paciente[total].id = total + 1;
                printf("Nome: ");
                fgets(paciente[total].nome, 50, stdin);
                paciente[total].nome[strcspn(paciente[total].nome, "\n")] = '\0';

                do
                {
                    printf("Idade: ");
                    scanf("%d", &paciente[total].idade);
                    getchar();

                    if (paciente[total].idade < 0 || paciente[total].idade > 130)
                    {
                        printf("\nIdade invalida.\n");
                    }
                } while (paciente[total].idade < 0 || paciente[total].idade > 130);

                do
                {
                    telefoneValido = 1;

                    printf("Telefone: ");
                    fgets(paciente[total].telefone, 20, stdin);
                    paciente[total].telefone[strcspn(paciente[total].telefone, "\n")] = '\0';

                    numTelefone = strlen(paciente[total].telefone);

                    if (numTelefone < 10 || numTelefone > 11)
                    {
                        telefoneValido = 0;
                    }
                    else
                    {
                        for (int i = 0; i < numTelefone; i++)
                        {
                            if (paciente[total].telefone[i] < '0' || paciente[total].telefone[i] > '9')
                            {
                                telefoneValido = 0;
                                break;
                            }
                        }
                    }

                    if (telefoneValido == 0)
                    {
                        printf("\nNumero de telefone invalido.\n");
                    }

                } while (!telefoneValido);

                do
                {
                    cpfValido = 1;

                    printf("Cpf: ");
                    fgets(paciente[total].cpf, 20, stdin);
                    paciente[total].cpf[strcspn(paciente[total].cpf, "\n")] = '\0';

                    numCpf = strlen(paciente[total].cpf);

                    if (numCpf != 11)
                    {
                        cpfValido = 0;
                    }
                    else
                    {
                        for (int i = 0; i < numCpf; i++)
                        {
                            if (paciente[total].cpf[i] < '0' || paciente[total].cpf[i] > '9')
                            {
                                cpfValido = 0;
                                break;
                            }
                        }
                    }

                    if (cpfValido == 0)
                    {
                        printf("\nNumero de CPF invalido.\n");
                    }

                } while (!cpfValido);

                do
                {
                    convenioValido = 1;
                    printf("Possui convenio? (0=nao / 1=sim): ");
                    scanf("%d", &statusConvenio);
                    if (statusConvenio < 0 || statusConvenio > 1)
                    {
                        printf("\nValor invalido, tente novamente.\n");
                        convenioValido = 0;
                    }
                    else
                    {
                        paciente[total].convenio = statusConvenio;
                    }
                    getchar();

                } while (!convenioValido);
                total++;
                printf("\nPaciente cadastrado com sucesso!\n");
            }
            else
            {
                printf("\nLimite de pacientes atingido!\n");
            }
        }

        if (opcao == 2)
        {
            if (total == 0)
            {
                printf("\nNenhum paciente encontrado.\n\n");
            }
            else
            {
                printf("\n----====[Lista de Pacientes]====----\n");
                for (int i = 0; i < total; i++)
                {
                    printf("Id: %d\n", paciente[i].id);
                    printf("Paciente: %s\n", paciente[i].nome);
                    printf("Idade: %d\n", paciente[i].idade);
                    printf("Telefone: %s\n", paciente[i].telefone);
                    printf("cpf: %s\n", paciente[i].cpf);
                    printf("Status convenio: %s\n\n",
                           paciente[i].convenio ? "Ativado" : "Desativado");
                }
            }
        }

        if (opcao == 3)
        {
            if (total == 0)
            {
                printf("\nNenhum paciente encontrado.\n\n");
            }
            else
            {
                int idPaciente;

                printf("\nId do paciente: ");
                scanf("%d", &idPaciente);
                getchar();

                for (int i = 0; i < total; i++)
                {
                    if (paciente[i].id == idPaciente)
                    {
                        printf("\n-------======[Paciente]======-------\n");
                        printf("Id: %d\n", paciente[i].id);
                        printf("Paciente: %s\n", paciente[i].nome);
                        printf("Telefone: %s\n", paciente[i].telefone);
                        printf("cpf: %s\n", paciente[i].cpf);
                        printf("Status convenio: %s\n\n",
                               paciente[i].convenio ? "Ativado" : "Desativado");

                        break;
                    }

                    if (i == total - 1)
                    {
                        printf("\nPaciente nao encontrado.\n\n");
                    }
                }
            }
        }

        if (opcao == 4)
        {
            if (total == 0)
            {
                printf("\nNenhum paciente encontrado.\n\n");
            }
            else
            {
                char nomePaciente[50];

                printf("\nNome do paciente: ");
                getchar(); // importante para limpar buffer
                fgets(nomePaciente, sizeof(nomePaciente), stdin);
                nomePaciente[strcspn(nomePaciente, "\n")] = '\0';

                for (int i = 0; i < total; i++)
                {
                    if (strcmp(paciente[i].nome, nomePaciente) == 0)
                    {
                        printf("\n-------======[Paciente]======-------\n");
                        printf("Id: %d\n", paciente[i].id);
                        printf("Paciente: %s\n", paciente[i].nome);
                        printf("Telefone: %s\n", paciente[i].telefone);
                        printf("cpf: %s\n", paciente[i].cpf);
                        printf("Status convenio: %s\n\n",
                               paciente[i].convenio ? "Ativado" : "Desativado");

                        break;
                    }

                    if (i == total - 1)
                    {
                        printf("\nPaciente nao encontrado.\n\n");
                    }
                }
            }
        }
        if (opcao == 5)
        {
            if (total == 0)
            {
                printf("\nNenhum paciente encontrado.\n\n");
            }
            else
            {
                int idPaciente;
                int encontrado = 0;

                printf("\nId do paciente: ");
                scanf("%d", &idPaciente);
                getchar();

                for (int i = 0; i < total; i++)
                {
                    if (paciente[i].id == idPaciente)
                    {
                        encontrado = 1;

                        int opcaoAlterar;

                        do
                        {
                            printf("\n-----=====[Clinica Medica]=====-----\n");
                            printf("\nDeseja alterar qual informacao?\n\n");
                            printf("1 - Nome.\n");
                            printf("2 - Idade.\n");
                            printf("3 - Telefone.\n");
                            printf("4 - CPF.\n");
                            printf("5 - Convenio.\n");
                            printf("6 - Sair.\n");
                            printf("====================================\n");

                            scanf("%d", &opcaoAlterar);
                            getchar();

                            if (opcaoAlterar == 1)
                            {
                                printf("Nome: ");
                                fgets(paciente[i].nome, sizeof(paciente[i].nome), stdin);
                                paciente[i].nome[strcspn(paciente[i].nome, "\n")] = '\0';
                            }
                            else if (opcaoAlterar == 2)
                            {
                                do
                                {
                                    printf("Idade: ");
                                    scanf("%d", &paciente[i].idade);
                                    getchar();

                                    if (paciente[i].idade < 0 || paciente[i].idade > 130)
                                    {
                                        printf("\nIdade invalida.\n");
                                    }

                                } while (paciente[i].idade < 0 || paciente[i].idade > 130);
                            }
                            else if (opcaoAlterar == 3)
                            {
                                int telefoneValido, numTelefone;

                                do
                                {
                                    telefoneValido = 1;

                                    printf("Telefone: ");
                                    fgets(paciente[i].telefone, sizeof(paciente[i].telefone), stdin);
                                    paciente[i].telefone[strcspn(paciente[i].telefone, "\n")] = '\0';

                                    numTelefone = strlen(paciente[i].telefone);

                                    if (numTelefone < 10 || numTelefone > 11)
                                    {
                                        telefoneValido = 0;
                                    }
                                    else
                                    {
                                        for (int j = 0; j < numTelefone; j++)
                                        {
                                            if (paciente[i].telefone[j] < '0' || paciente[i].telefone[j] > '9')
                                            {
                                                telefoneValido = 0;
                                                break;
                                            }
                                        }
                                    }

                                    if (!telefoneValido)
                                    {
                                        printf("\nNumero de telefone invalido.\n");
                                    }

                                } while (!telefoneValido);
                            }
                            else if (opcaoAlterar == 4)
                            {
                                int cpfValido, numCpf;

                                do
                                {
                                    cpfValido = 1;

                                    printf("CPF: ");
                                    fgets(paciente[i].cpf, sizeof(paciente[i].cpf), stdin);
                                    paciente[i].cpf[strcspn(paciente[i].cpf, "\n")] = '\0';

                                    numCpf = strlen(paciente[i].cpf);

                                    if (numCpf != 11)
                                    {
                                        cpfValido = 0;
                                    }
                                    else
                                    {
                                        for (int j = 0; j < numCpf; j++)
                                        {
                                            if (paciente[i].cpf[j] < '0' || paciente[i].cpf[j] > '9')
                                            {
                                                cpfValido = 0;
                                                break;
                                            }
                                        }
                                    }

                                    if (!cpfValido)
                                    {
                                        printf("\nNumero de CPF invalido.\n");
                                    }

                                } while (!cpfValido);
                            }
                            else if (opcaoAlterar == 5)
                            {
                                int statusConvenio;

                                do
                                {
                                    printf("Status do convenio (0=nao / 1=sim): ");
                                    scanf("%d", &statusConvenio);
                                    getchar();

                                    if (statusConvenio < 0 || statusConvenio > 1)
                                    {
                                        printf("\nValor invalido.\n");
                                    }
                                    else
                                    {
                                        paciente[i].convenio = statusConvenio;
                                    }

                                } while (statusConvenio < 0 || statusConvenio > 1);
                            }

                        } while (opcaoAlterar != 6);

                        printf("\nAlteracao concluida com sucesso!\n");
                        break;
                    }
                }

                if (!encontrado)
                {
                    printf("\nPaciente nao encontrado.\n\n");
                }
            }
        }

        if (opcao == 6)
        {

            if (total == 0)
            {
                printf("\nNenhum paciente encontrado.\n\n");
            }
            else
            {
                int idPaciente;
                printf("\nId do paciente:");
                scanf("%d", &idPaciente);
                getchar();
                for (int i = 0; i < total; i++)
                {
                    if (idPaciente == paciente[i].id)
                    {
                        printf("\n-------======[Paciente]======-------\n");
                        printf("Id: %d\n", paciente[i].id);
                        printf("Paciente: %s\n", paciente[i].nome);
                        printf("Status convenio: %s\n\n",
                               paciente[i].convenio ? "Ativado" : "Desativado");
                        break;
                    }
                    if(idPaciente>total){
                        printf("\nPaciente nao encontrado.\n\n");
                    }
                }
            }
        }

        if (opcao == 7)
        {
            if (total == 0)
            {
                printf("\nNenhum paciente encontrado.\n\n");
            }
            else
            {
                int idPaciente;

                printf("\nId do paciente: ");
                scanf("%d", &idPaciente);
                getchar();

                for (int i = 0; i < total; i++)
                {
                    if (paciente[i].id == idPaciente)
                    {
                        // desloca os elementos
                        for (int j = i; j < total - 1; j++)
                        {
                            paciente[j] = paciente[j + 1];
                            paciente[j].id--;
                        }

                        total--;

                        printf("\nPaciente removido com sucesso!\n\n");
                        break;
                    }

                    if (i == total - 1)
                    {
                        printf("\nPaciente nao encontrado.\n\n");
                    }
                }
            }
        }
    }

    printf("Encerrando sistema...\n\n");

    return 0;
}