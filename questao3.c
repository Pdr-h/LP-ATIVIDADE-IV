#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};

float calcularValorTotal(struct Produto produto) {
    return produto.preco * produto.quantidade;
}

void realizarCompra(struct Produto *produto) {
    int quantidadeComprada;
    printf("Quantidade a ser comprada: ");
    scanf("%d", &quantidadeComprada);
    system("cls");
    if (quantidadeComprada > 0 && quantidadeComprada <= produto->quantidade) {
        float valorCompra = quantidadeComprada * produto->preco;
        sleep(1);
        printf("Compra realizada com sucesso!\n\n");
        printf("Produtos comprados:\n");
        printf("Nome do Produto: %s\n", produto->nome);
        printf("Quantidade comprada: %d\n", quantidadeComprada);
        printf("Valor total da compra: R$%.2f\n", valorCompra);
        produto->quantidade -= quantidadeComprada;
        sleep(4);
        system("cls");
    } else {
        printf("Quantidade inválida ou insuficiente em estoque.\n");
    }
}

void consultarEstoque(struct Produto produto) {
    printf("Nome do Produto: %s\n", produto.nome);
    printf("Preço: R$%.2f\n", produto.preco);
    printf("Quantidade em Estoque: %d\n", produto.quantidade);
    printf("Valor Total em Estoque: R$%.2f\n", calcularValorTotal(produto));
    sleep(5);
    system("cls");
}

int main() {
    setlocale(LC_ALL, "portuguese");
    struct Produto produtos[3] = {
        {"Prato", 10.00, 100},
        {"Copo", 5.00, 500},
        {"Talheres", 20.00, 200}
    };

    int escolha;
    int indiceProduto;

    do {
        printf("\nMenu:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n\n");
        printf("Escolha a opção: \n");
        scanf("%d", &escolha);
        system("cls");
        switch (escolha) {
            case 1:
                printf("Escolha o produto:\n\n");
                printf("[1] - Prato R$10,00\n");
                printf("[2] - Copo R$5,00\n");
                printf("[3] - Talheres R$20,00\n");
                scanf("%d", &indiceProduto);
                system("cls");
                if (indiceProduto >= 1 && indiceProduto <= 3) {
                    realizarCompra(&produtos[indiceProduto - 1]);
                } else {
                    printf("Opção inválida\nTente novamente.\n");
                }
                break;
            case 2:
                printf("Escolha o produto:\n\n");
                printf("[1] - Prato R$10,00\n");
                printf("[2] - Copo R$5,00\n");
                printf("[3] - Talheres R$20,00\n");
                scanf("%d", &indiceProduto);
                system("cls");
                if (indiceProduto >= 1 && indiceProduto <= 3) {
                    consultarEstoque(produtos[indiceProduto - 1]);
                } else {
                    printf("Opção inválida\nTente novamente.\n");
                }
                break;
            case 3:
                printf("Saindo do programa!\n");
                break;
            default:
                printf("Opção inválidan\nTente novamente.\n");
        }
    } while (escolha != 3);

    return 0;
}
