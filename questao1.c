#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
int i;
struct Contato
{
    char nome[200];
    char telefone[50];
    char email[200];
};

char *buscarTelefone(struct Contato contatos[], char *nome)
{
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(contatos[i].nome, nome) == 0)
        {
            return contatos[i].telefone;
        }
    }
    return "INEXISTENTE!";
}

int main()
{
    struct Contato contatos[3];
    char nome[50];
    char *telefoneEncontrado;
    int opcao, opcao2, opcao3;

    setlocale(LC_ALL, "portuguese");

    do
    {
        printf("Digite a opção que deseja: \n\n");
        printf("[1] - Cadastrar 3 pessoas;\n[2] - SAIR.\n\n");
        scanf("%d", &opcao);
        system("cls");
        fflush(stdin);
        switch (opcao)
        {
        case 1:
            for (i = 0; i < 3; i++)
            {
                printf("Digite o nome do %d° contato: ", i + 1);
                scanf("%s", contatos[i].nome);
                printf("Digite o telefone de %s: ", contatos[i].nome);
                scanf("%s", contatos[i].telefone);
                printf("Digite o email de %s: ", contatos[i].nome);
                scanf("%s", contatos[i].email);
                system("cls");
            }
            printf("PESQUISAR TELEFONE?\n1 - SIM\n2 - NAO\n");
            scanf("%d", &opcao3);
            system("cls");
            if (opcao3 == 2)
            {
                return 0;
            }
            do
            {
                printf("\nDigite o nome do contato que você deseja buscar: ");
                scanf("%s", nome);
                telefoneEncontrado = buscarTelefone(contatos, nome);
                if (telefoneEncontrado != NULL)
                {
                    printf("O número de telefone de %s é: %s\n", nome, telefoneEncontrado);
                 
                }
                else
                {
                    printf("Contato não encontrado.\n");
                  
                }
                printf("Procurar outro telefone?\n[1] - Sim\n[2] - Não\n\n");
                scanf("%d", &opcao2);
                system("cls");
            } while (opcao2 == 1);
            break;
        case 2:
        printf("saindo.......");
        break;
        default:
            printf("INVÁLIDO");
            break;
        }
    } while (opcao3 == 1);
    return 0;
}
