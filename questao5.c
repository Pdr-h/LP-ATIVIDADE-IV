#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int i;
struct Funcionario
{
    char nome[300];
    char cargo[100];
    float salario;
};

float calcularMediaSalarial(struct Funcionario funcionarios[], char programador[])
{
    float somaSalarios = 0;
    int quantia = 0;

    for (i = 0; i < 50; i++)
    {
        if (strcmp(funcionarios[i].cargo, programador) == 0)
        {
            somaSalarios += funcionarios[i].salario;
            quantia++;
        }
    }
    if (quantia > 0)
    {
        return somaSalarios / quantia;
    }
    else
    {
        return 0;
    }
}

int main()
{
    // coloquei pra adicionar até 50 funcionários, porém pode ser menos
    struct Funcionario funcionarios[50];
    char continuar;
    int max = 50;
    setlocale(LC_ALL, "portuguese");
    for (i = 0; i < 50; i++)
    {
        printf("Digite o nome do %d° funcionário: ", i + 1);
        scanf("%s", funcionarios[i].nome);

        printf("\nDigite o cargo de %s\n(Programador, Analista, Gerente):\n", funcionarios[i].nome);
        scanf("%s", funcionarios[i].cargo);

        printf("\nDigite o salário de %s\nR$", funcionarios[i].nome);
        scanf("%f", &funcionarios[i].salario);
        system("cls");
        fflush(stdin);
        printf("Adicionar outro funcionário? (s/n): ");
        scanf("%c", &continuar);
        if (continuar != 's' && continuar != 'S')
        {
            system("cls");
            break;
        }
        if (i == max)
        {
            printf("Número de funcionarios excedido");
            printf("Programa encerrando e exibindo a média salarial dos programadores");
        }
        
    }

    char programador[] = "Programador";
    float mediaSalarialProgramadores = calcularMediaSalarial(funcionarios, programador);

    if (mediaSalarialProgramadores > 0)
    {
        printf("A média salarial dos programadores é: R$%.2f\n", mediaSalarialProgramadores);
    }
    else
    {
        printf("Não há programadores na empresa.\n");
    }

    return 0;
}
