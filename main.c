#include <stdio.h>
#include "globais.h"
#include "pacientes.h"
#include "medico.h"
#include "consulta.h"
#include "especialidades.h"
#include "relatorios.h"

// Inicialização das variáveis globais compartilhadas
struct Paciente paciente[MAX];
int totalPacientes = 0;

struct Medico medicos[MAX_MEDICOS];
int medicosCadastrados = 0;

// CORREÇÃO AQUI: Removido o '=' vazio que causava o erro na linha 16
char especialidades[MAX_ESPECIALIDADES][TAMANHO_NOME]; 
int especialidadesCadastradas = 0;

Consulta consultas[MAX_CONSULTAS];
int totalConsultas = 0;

int main() {
    int opcaoPrincipal = 0;

    while (opcaoPrincipal != 6) {
        printf("\n ======== BEM-VINDO AO SISTEMA CLÍNICA MÉDICA ======== \n");
        printf("Selecione um módulo abaixo: \n");
        printf("1 - Módulo Pacientes \n");
        printf("2 - Módulo Médicos \n");
        printf("3 - Módulo Consultas \n");
        printf("4 - Módulo Especialidades \n");
        printf("5 - Módulo Relatórios \n");
        printf("6 - Sair do Sistema \n");
        printf("===================================================== \n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcaoPrincipal);
        getchar();

        switch (opcaoPrincipal) {
            case 1:
                moduloPacientes();
                break;
            case 2:
                moduloMedicos();
                break;
            case 3:
                moduloConsultas();
                break;
            case 4:
                moduloEspecialidades();
                break;
            case 5:
                moduloRelatorios();
                break;
            case 6:
                printf("\nEncerrando Sistema... Até breve! :D\n");
                break;
            default:
                printf("\nOpção inválida! Tente novamente.\n");
        }
    }
    return 0;
}