#include<stdio.h>
#include<string.h>

#define MAX 100

// Estrutura do medico
struct Medico
{
    int id;
    char nome[50];
    char telefone[20];
    char crm[10];
    char especialidade[30]; 
    char horarios[20];
};

/*
Cadastrar médico
Listar médicos
Buscar médico por CRM
Buscar médico por especialidade
Alterar dados do médico
Excluir médico
Informar horários disponíveis
*/

int main()
{
    struct Medico medicos[MAX];
    int total = 0;
    int opcao = 0;

    while (opcao != 8)
    {
        printf("\n===== SISTEMA DE MÉDICOS =====\n");
        printf("1 - Cadastrar médico\n");
        printf("2 - Listar médicos\n");
        printf("3 - Remover médico\n");
        printf("4 - Buscar médico por CRM\n");
        printf("5 - Buscar médico por especialidade\n");
        printf("6 - Alterar dados do médico\n");
        printf("7 - Informar horários disponíveis\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcão: ");
        scanf("%d", &opcao);
        getchar(); // limpar buffer

        // CADASTRAR
        if (opcao == 1)
        {
            if (total < MAX)
            {
                medicos[total].id = total + 1;

                printf("Nome: ");
                fgets(medicos[total].nome, 50, stdin);
                medicos[total].nome[strcspn(medicos[total].nome, "\n")] = '\0';

                printf("Telefone: ");
                fgets(medicos[total].telefone, 20, stdin);
                medicos[total].telefone[strcspn(medicos[total].telefone, "\n")] = '\0';

                printf("CRM: ");
                fgets(medicos[total].crm, 10, stdin); 
                medicos[total].crm[strcspn(medicos[total].crm, "\n")] = '\0';

                printf("Horário de atendimento: ");
                fgets(medicos[total].horarios, 20, stdin);
                medicos[total].horarios[strcspn(medicos[total].horarios, "\n")] = '\0';

                total++;
                printf("Médico cadastrado com sucesso!\n");
            }
            else
            {
                printf("Limite de médicos atingido!\n");
            }
        }

        else if (opcao == 2)
        {
            if (total == 0)
            {
                printf("Nenhum médico cadastrado.\n");
            }
            else
            {
                printf("----------- Lista de Médicos -----------\n");
                for (int i = 0; i < total; i++)
                {
                    printf("ID: %d;\nNome: %s;\nTelefone: %s;\nCRM: %s;\nEspecialidade: %s.\n----------------------\n\n",medicos[i].id, medicos[i].nome, medicos[i].telefone, medicos[i].crm, medicos[i].especialidade);
                }
            }
        }


        else if(opcao == 3){
            char medicodeletado[50];
            int oescolhido = -1;

            printf("Qual médico deseja deletar?\n");
            // Usando fgets para evitar problemas se o nome tiver espaços
            fgets(medicodeletado, 50, stdin);
            medicodeletado[strcspn(medicodeletado, "\n")] = '\0';

            for (int i = 0; i < total; i++) {
                if(strcmp(medicos[i].nome, medicodeletado) == 0){
                    oescolhido = i;
                    break;
                }
            }
            if (oescolhido != -1){
                for (int j = oescolhido; j < total - 1; j++){
                    medicos[j] = medicos[j + 1];
                }
                total--;
                printf("Médico removido com sucesso\n");
            } else {
                printf("Médico não encontrado para remoção.\n");
            }
        }
        
         else if(opcao == 4 ){
            char buscarcrm[50];
            int medencontrado = 0;

            printf("Digite o CRM do médico para buscar: ");
            fgets(buscarcrm, 50, stdin);
            buscarcrm[strcspn(buscarcrm, "\n")] = '\0';

            for(int i = 0; i < total; i++){
                if(strcmp(medicos[i].crm, buscarcrm) == 0){
                    printf("Medico encontrado:\n");
                    printf("ID: %d\n", medicos[i].id);
                    printf("Nome: %s\n", medicos[i].nome);
                    printf("Telefone: %s\n", medicos[i].telefone);
                    printf("CRM: %s\n", medicos[i].crm);
                    printf("Especialidade: %s\n", medicos[i].especialidade);
                    medencontrado = 1;
                }
            }
            if(!medencontrado){
                printf("Médico não encontrado!\n");
            }
        }

        else if(opcao == 5 ){
            char buscarEsp[30];
            int ESPencontrada = 0;

            printf("Digite a especialidade do médico para buscar: ");
            fgets(buscarEsp, 30, stdin);
            buscarEsp[strcspn(buscarEsp, "\n")] = '\0';

            for(int i = 0; i < total; i++){
                if(strcmp(medicos[i].especialidade, buscarEsp) == 0){
                    printf("Médico encontrado:\n");
                    printf("ID: %d\n", medicos[i].id);
                    printf("Nome: %s\n", medicos[i].nome);
                    printf("Telefone: %s\n", medicos[i].telefone);
                    printf("CRM: %s\n", medicos[i].crm);
                    printf("Especialidade: %s\n", medicos[i].especialidade);
                    ESPencontrada = 1;
                }
            }
            if(!ESPencontrada){
                printf("Médico não encontrado!\n");
            }
        }

        else if (opcao == 6){

            int medicoALT = 0;
            int dadoAlterado = 0;
            

            printf("----------- Lista de Médicos -----------\n");

            for (int i = 0; i < total; i++)
                {
                printf("ID: %d.\nNome: %s.\nTelefone: %s.\nCRM: %s.\nEspecialidade: %s.\n----------------------\n\n",medicos[i].id, medicos[i].nome, medicos[i].telefone, medicos[i].crm, medicos[i].especialidade);
                }
            printf("Digite o ID do médico que deseja alterar:\n ");
            scanf("%d", & medicoALT);
            printf("Qual tipo de dado deseja alterar?: ");
            printf("1 - Nome: \n");
            printf("2 - Telefone: \n");
            printf("3 - CRM: \n");
            printf("Pressione qualquer outro número caso deseje retornar ao menu:\n");
            scanf("%d", & dadoAlterado);
            getchar();

            if(dadoAlterado == 1){

                printf("Qual é o novo nome do médico? \n");
                fgets(medicos[medicoALT -1].nome, 50, stdin);
                printf("Nome alterado com sucesso!\n");

    
            }
            else if(dadoAlterado == 2){

                printf("Qual é o novo telefone do médico? \n");
                fgets(medicos[medicoALT -1].telefone, 20, stdin);
                printf("Telefone alterado com sucesso!\n");

            }
            else if(dadoAlterado == 3){

                printf("Qual é o novo CRM do médico?\n");
                fgets(medicos[medicoALT - 1].crm, 10, stdin);
                printf("CRM alterado com sucesso!\n");

            }
            else{
                printf("Opção inválida!\n");
            }
            

        }

        else if(opcao == 7){

            for (int i = 0; i < total; i++){

                printf("ID: %d;\nNome: %s;\nHorários: %s.\n----------------------\n\n",medicos[i].id, medicos[i].nome, medicos[i].horarios);
                
            } 
        }
        
        else if (opcao == 8){
            printf("Até breve... :D\n");
        }

        else{
            printf("Opção inválida\n");
        }
    }

    printf("Encerrando Sistema...\n");
    return 0;
}