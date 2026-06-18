#ifndef GLOBAIS_H
#define GLOBAIS_H

#include <stdbool.h>

#define MAX 100
#define MAX_MEDICOS 200
#define MAX_ESPECIALIDADES 100
#define MAX_CONSULTAS 100
#define TAMANHO_NOME 50

// Estruturas Unificadas
struct Paciente {
    int id, idade;
    char nome[50];
    char telefone[20];
    char cpf[20];
    bool convenio;
    int ativo; // Exclusão lógica
};

struct Medico {
    int id;
    char nome[TAMANHO_NOME];
    char telefone[20];
    char crm[10];
    char especialidadeMedico[TAMANHO_NOME];
    char horarios[20];
    int ativo; // Exclusão lógica
};

typedef struct {
    int codigoConsulta;
    int codigoPaciente;
    int crmMedico;
    char especialidade[50];
    char data[11];
    char horario[6];
    int realizada;
    int cancelada;
} Consulta;

// Declaração das variáveis globais (extern indica que estão definidas em outro lugar, no caso, no main.c)
extern struct Paciente paciente[MAX];
extern int totalPacientes;

extern struct Medico medicos[MAX_MEDICOS];
extern int medicosCadastrados;

extern char especialidades[MAX_ESPECIALIDADES][TAMANHO_NOME];
extern int especialidadesCadastradas;

extern Consulta consultas[MAX_CONSULTAS];
extern int totalConsultas;

#endif