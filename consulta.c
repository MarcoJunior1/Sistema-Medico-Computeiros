#include <stdio.h>
#include <string.h>

#define MAX_CONSULTAS 100

typedef struct
{
    int codigoConsulta;
    int codigoPaciente;
    int crmMedico;

    char especialidade[50];

    char data[11];
    char horario[6];

    int realizada;
    int cancelada;

} Consulta;

Consulta consultas[MAX_CONSULTAS];
int totalConsultas = 0;

int buscarConsultaPorCodigo(int codigo)
{
    int i;

    for(i = 0; i < totalConsultas; i++)
    {
        if(consultas[i].codigoConsulta == codigo)
        {
            return i;
        }
    }

    return -1;
}


int horarioDisponivel(int crm, char data[], char horario[])
{
    int i;

    for(i = 0; i < totalConsultas; i++)
    {
        if(
            consultas[i].crmMedico == crm &&
            strcmp(consultas[i].data, data) == 0 &&
            strcmp(consultas[i].horario, horario) == 0 &&
            consultas[i].cancelada == 0
        )
        {
            return 0;
        }
    }

    return 1;
}

void exibirConsulta(Consulta c)
{
    printf("\n==============================");
    printf("\nCodigo: %d", c.codigoConsulta);
    printf("\nPaciente: %d", c.codigoPaciente);
    printf("\nCRM Medico: %d", c.crmMedico);
    printf("\nEspecialidade: %s", c.especialidade);
    printf("\nData: %s", c.data);
    printf("\nHorario: %s", c.horario);

    if(c.cancelada)
        printf("\nStatus: Cancelada");
    else if(c.realizada)
        printf("\nStatus: Realizada");
    else
        printf("\nStatus: Agendada");

    printf("\n==============================\n");
}

void agendarConsulta()
{
    Consulta nova;

    if(totalConsultas >= MAX_CONSULTAS)
    {
        printf("Limite de consultas atingido.\n");
        return;
    }

    printf("Codigo da consulta: ");
    scanf("%d", &nova.codigoConsulta);

    if(buscarConsultaPorCodigo(nova.codigoConsulta) != -1)
    {
        printf("Codigo ja existente.\n");
        return;
    }

    printf("Codigo do paciente: ");
    scanf("%d", &nova.codigoPaciente);

    printf("CRM do medico: ");
    scanf("%d", &nova.crmMedico);

    printf("Especialidade: ");
    scanf("%s", nova.especialidade);

    printf("Data (dd/mm/aaaa): ");
    scanf("%10s", nova.data);

    printf("Horario (hh:mm): ");
    scanf("%5s", nova.horario);

    if(!horarioDisponivel(
        nova.crmMedico,
        nova.data,
        nova.horario))
    {
        printf("Horario indisponivel.\n");
        return;
    }

    nova.realizada = 0;
    nova.cancelada = 0;

    consultas[totalConsultas] = nova;
    totalConsultas++;

    printf("Consulta agendada com sucesso.\n");
}

void listarConsultas()
{
    int i;

    if(totalConsultas == 0)
    {
        printf("Nenhuma consulta cadastrada.\n");
        return;
    }

    for(i = 0; i < totalConsultas; i++)
    {
        exibirConsulta(consultas[i]);
    }
}

void buscarConsultaPaciente()
{
    int codigo;
    int i;
    int encontrou = 0;

    printf("Codigo do paciente: ");
    scanf("%d", &codigo);

    for(i = 0; i < totalConsultas; i++)
    {
        if(consultas[i].codigoPaciente == codigo)
        {
            exibirConsulta(consultas[i]);
            encontrou = 1;
        }
    }

    if(!encontrou)
    {
        printf("Nenhuma consulta encontrada.\n");
    }
}

void buscarConsultaMedico()
{
    int crm;
    int i;
    int encontrou = 0;

    printf("CRM do medico: ");
    scanf("%d", &crm);

    for(i = 0; i < totalConsultas; i++)
    {
        if(consultas[i].crmMedico == crm)
        {
            exibirConsulta(consultas[i]);
            encontrou = 1;
        }
    }

    if(!encontrou)
    {
        printf("Nenhuma consulta encontrada.\n");
    }
}

void cancelarConsulta()
{
    int codigo;
    int pos;

    printf("Codigo da consulta: ");
    scanf("%d", &codigo);

    pos = buscarConsultaPorCodigo(codigo);

    if(pos == -1)
    {
        printf("Consulta nao encontrada.\n");
        return;
    }

    consultas[pos].cancelada = 1;

    printf("Consulta cancelada com sucesso.\n");
}

void alterarConsulta()
{
    int codigo;
    int pos;

    printf("Codigo da consulta: ");
    scanf("%d", &codigo);

    pos = buscarConsultaPorCodigo(codigo);

    if(pos == -1)
    {
        printf("Consulta nao encontrada.\n");
        return;
    }

    if(consultas[pos].cancelada)
    {
        printf("Consulta cancelada.\n");
        return;
    }

    if(consultas[pos].realizada)
    {
        printf("Consulta ja realizada.\n");
        return;
    }

    printf("Nova data: ");
    scanf("%10s", consultas[pos].data);

    printf("Novo horario: ");
    scanf("%5s", consultas[pos].horario);

    printf("Consulta alterada com sucesso.\n");
}

void marcarRealizada()
{
    int codigo;
    int pos;

    printf("Codigo da consulta: ");
    scanf("%d", &codigo);

    pos = buscarConsultaPorCodigo(codigo);

    if(pos == -1)
    {
        printf("Consulta nao encontrada.\n");
        return;
    }

    if(consultas[pos].cancelada)
    {
        printf("Consulta cancelada.\n");
        return;
    }

    consultas[pos].realizada = 1;

    printf("Consulta marcada como realizada.\n");
}