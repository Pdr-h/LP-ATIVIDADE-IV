#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int i, j;
struct dados_Aluno
{
    char nome[200];
    char dataNasc[100];
    float notas[2];
    float media;
};

float calcular_Media(float notas[])
{
    float soma = 0;
    for (j = 0; j < 2; j++)
    {
        soma += notas[j];
    }
    float media = soma / 2;
    return media;
}

int main()
{
    setlocale(LC_ALL, "portuguese");
    struct dados_Aluno alunos[5];

    for (i = 0; i < 5; i++)
    {
        printf("Digite os Dados do Aluno %d:\n\n", i + 1);

        printf("Nome:");
        gets(alunos[i].nome);
        printf("\n");
        printf("Data de Nascimento de %s:", alunos[i].nome);
        gets(alunos[i].dataNasc);
        printf("\n");
        for (j = 0; j < 2; j++)
        {
            printf("Digite a %d nota de %s:\n", j + 1, alunos[i].nome);
            scanf("%f", &alunos[i].notas[j]);
            fflush(stdin);
        }

        alunos[i].media = calcular_Media(alunos[i].notas);

        system("cls");
    }

    for (i = 0; i < 5; i++)
    {
        printf("Dados do Aluno %d:\n", i + 1);
        printf("Nome: %s\n", alunos[i].nome);
        printf("Data de Nascimento: %s\n", alunos[i].dataNasc);
        
        for (j = 0; j < 2; j++)
        {
            printf("Nota %d: %.2f\n", j + 1, alunos[i].notas[j]);
        }

        printf("Média: %.2f\n", alunos[i].media);
        printf("\n\n");
    }

    return 0;
}
