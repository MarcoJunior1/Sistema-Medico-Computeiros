#include<stdio.h>
#include<string.h>

#define MAX 100

// Estrutura do medico
struct Medico
{
    int id;
    char nome[50];
    char telefone[20];
    char crm[6];
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
        printf("\n===== SISTEMA DE MEDICOS =====\n");
        printf("1 - Cadastrar medico\n");
        printf("2 - Listar medicos\n");
        printf("3 - Buscar medico\n");
        printf("4 - Remover medico\n");
        printf("5 - Buscar medico por CRM\n");
        printf("6 - Buscar medico por especialidade\n");
        printf("7 - Alterar dados do medico\n");
        printf("8 - Sair\n");
        printf("Escolha uma opcao: ");
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
                fgets(medicos[total].crm, 6, stdin);
                medicos[total].crm[strcspn(medicos[total].crm, "\n")] = '\0';

                total++;
                printf("Medico cadastrado com sucesso!\n");
            }
            else
            {
                printf("Limite de medicos atingido!\n");
            }
        }

        else if (opcao == 2)
        {
            if (total == 0)
            {
                printf("Nenhum medico cadastrado.\n");
            }
            else
            {
                printf("----------- Lista de Medicos -----------\n");
                for (int i = 0; i < total; i++)
                {
                    printf("ID: %d.\nNome: %s.\nTelefone: %s.\nCRM: %s.\n----------------------\n\n",medicos[i].id, medicos[i].nome, medicos[i].telefone, medicos[i].crm);
                }
            }
        }

        else if(opcao==3){
            char buscar[50];
            int encontrado =0;

            printf("Digite o nome do medico para buscar: ");
            fgets(buscar, 50, stdin);
            buscar[strcspn(buscar, "\n")]='\0';

            for(int i=0; i<total; i++){
                if(strcmp(medicos[i].nome, buscar)==0){
                    printf("Medico encontrado:\n");
                    printf("ID: %d\n", medicos[i].id);
                    printf("Nome: %s\n", medicos[i].nome);
                    printf("Telefone: %s\n", medicos[i].telefone);
                    printf("CRM: %s\n", medicos[i].crm);
                    encontrado =1;
                }
                
            }
            if(!encontrado){
                    printf("Medico nao encontrado!\n");
                }
        }

        else if(opcao == 4){

            char medicodeletado[50];
            int oescolhido = -1;

            printf("Qual medico deseja deletar?\n");
            scanf("%s", medicodeletado);

            for (int i = 0; i < total; i++) {

                if(strcmp(medicos[i].nome, medicodeletado)== 0){
                    oescolhido = i;
                    break;
                }
            }
            if (oescolhido != -1){
                for (int j = oescolhido; j < total -1; j++){
                medicos[j] = medicos[j + 1];
                }
            }
            total--;
            printf("Medico removido com sucesso\n");

        }
        else if(opcao == 5){

            char crmbuscar[6];
            int encontrado = 0;

            printf("Digite o CRM do medico para buscar: ");
            fgets(crmbuscar, 6, stdin);
            crmbuscar[strcspn(crmbuscar, "\n")] = '\0';

            for(int i = 0; i < total; i++){
                if(strcmp(medicos[i].crm, crmbuscar) == 0){
                    printf("Medico encontrado:\n");
                    printf("ID: %d\n", medicos[i].id);
                    printf("Nome: %s\n", medicos[i].nome);
                    printf("Telefone: %s\n", medicos[i].telefone);
                    printf("CRM: %s\n", medicos[i].crm);
                    encontrado = 1;
                }
            }
            if(!encontrado){
                printf("Medico nao encontrado!\n");
            }
        
        else{
            printf("Medico nao encontrado!\n");
            }    
        }
        
        else if (opcao == 8){

            printf("Ate breve... :D\n");
        }

        else{
            printf("Opcao invalida\n");
        }
    }

    printf("Encerrando sistema...\n");
    return 0;
}
