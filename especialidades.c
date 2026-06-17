#include<stdio.h>
#include<string.h>

#define MAX_MEDICOS 200
#define MAX_ESPECIALIDADES 100
#define TAMANHO_NOME 50

void CadastrarEspecialidade(char destino[]);

struct Medico{
    int id;
    char nome[TAMANHO_NOME];
    char especialidadeMedico[TAMANHO_NOME];
};

int main(){
    int numeroSelecionado = 0;
    int especialidadesCadastradas = 0;
    int medicosCadastrados = 0;
    char especialidades [MAX_ESPECIALIDADES][TAMANHO_NOME] = {};
    struct Medico medicos[MAX_MEDICOS];

    while (numeroSelecionado != 5) {
        printf(" ======== BEM-VINDO AO SISTEMA MÉDICO ======== \n");
        printf("Selecione uma opção abaixo: \n");
        printf("1 - Cadastrar Especialidade \n");
        printf("2 - Listar Especialidade \n");
        printf("3 - Associar Médico a Especialidade \n");
        printf("4 - Relatório de Especialidades \n");
        printf("5 - Sair \n");

        scanf("%d", &numeroSelecionado);

        getchar();

        if (numeroSelecionado == 1){
            CadastrarEspecialidade(especialidades[especialidadesCadastradas]); 

            printf("Nova especialidade cadastrada: %s \n", especialidades[especialidadesCadastradas]);
            especialidadesCadastradas++;
        } else if(numeroSelecionado == 2){
            if(especialidadesCadastradas == 0){
                printf("Nenhuma especialidade cadastrada \n");
            } else {
                printf("======== LISTA DE ESPECIALIDADES ======== \n");
                for(int i = 0; i < especialidadesCadastradas; i++){
                    printf("Especialidade número: %d \n", i + 1);
                    printf("%s", especialidades[i]);
                    printf("------------------------------------------------ \n");
                }
            }
        } else if(numeroSelecionado == 3){
            int numeroMedico;
            int numeroEspecialidade;

            printf("======== LISTA DE MÉDICOS CADASTRADOS ======== \n");
            for(int i = 0; i< medicosCadastrados; i++){
                printf("Número do Médico: %d \n", medicos[i].id);
                printf("Nome do Médico: %s \n", medicos[i].nome);
                printf("------------------------------------------------ \n");
            }

            printf("Digite o número do médico que deseja associar uma especialidade:");
            scanf("%d", &numeroMedico);

            printf("======== LISTA DE ESPECIALIDADES ======== \n");
            for(int i = 0; i < especialidadesCadastradas; i++){
                printf("Especialidade número: %d \n", i + 1);
                printf("%s", especialidades[i]);
                printf("------------------------------------------------ \n");
            }

            printf("Digite o número da especialidade que deseja associar ao médico: ");
            scanf("%d", &numeroEspecialidade);

            strcpy(medicos[numeroMedico - 1].especialidadeMedico, especialidades[numeroEspecialidade - 1]);

            printf("\n Especialidade associada com sucesso! \n");
        } else if(numeroSelecionado == 4){
            int numeroEspecialidade;
            int quantidadeEspecialistas = 0;

            printf("======== LISTA DE ESPECIALIDADES ======== \n");
            for(int i = 0; i < especialidadesCadastradas; i++){
                printf("Especialidade número: %d \n", i + 1);
                printf("%s", especialidades[i]);
                printf("------------------------------------------------ \n");
            }

            printf("Digite o número da especialidade para verificar o relatório dos médicos com a especialidade correspondente: ");
            scanf("%d", &numeroEspecialidade);

            printf("======== LISTA DE MÉDICOS POR ESPECIALIDADE ======== \n");
            printf("Especialidade selecionada: %s \n", especialidades[numeroEspecialidade - 1]);

            for(int i = 0; i< medicosCadastrados; i++){
                if(strcmp(medicos[i].especialidadeMedico, especialidades[numeroEspecialidade - 1]) == 0){
                    printf("Número do Médico: %d \n", medicos[i].id);
                    printf("Nome do Médico: %s \n", medicos[i].nome);
                    printf("------------------------------------------------ \n");

                    quantidadeEspecialistas++;
                }
            }

            if(quantidadeEspecialistas == 0){
                printf("Nenhum médico especialista nessa área! \n");
            } else {
                printf("Número de médicos especialistas em %s : %d \n", especialidades[numeroEspecialidade - 1], quantidadeEspecialistas);
            }
        }else if(numeroSelecionado == 6){
            if(medicosCadastrados < MAX_MEDICOS){
                printf("======== CADASTRAR MÉDICO ======== \n");

                medicos[medicosCadastrados].id = medicosCadastrados + 1;

                printf("Insira o nome do médico a ser cadastrado: \n");
                fgets(medicos[medicosCadastrados].nome, TAMANHO_NOME, stdin);
                medicos[medicosCadastrados].nome[strcspn(medicos[medicosCadastrados].nome, "\n")] = '\0';

                printf("Médico cadastrado com sucesso! \n");

                medicosCadastrados++;
            } else{
                printf("Limite máximo de médicos atingido! \n");
            }
        }
    }
    return 0;
}

void CadastrarEspecialidade (char arrayDestino[]){

    printf("Digite o nome da nova especialidade: \n");
    fgets(arrayDestino, TAMANHO_NOME, stdin);
}

