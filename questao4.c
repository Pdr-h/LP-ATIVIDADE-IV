#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

struct ContaBancaria {
    int numeroDaConta;
    char titular[300];
    float saldo;
    int tipoConta;
};

void limpar(){
    sleep(2);
    system("cls");
};

void depositar(struct ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido para depósito.\n");
    } 
    limpar();
}

void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de R$%.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido para saque ou saldo insuficiente.\n");
    }
    limpar();
}

void saldo(struct ContaBancaria conta) {
    printf("Saldo atual: R$%.2f\n", conta.saldo);
    limpar();
}

int main() {
    struct ContaBancaria Conta;
    int escolha;
    float valor;
    setlocale(LC_ALL, "portuguese");

    printf("Digite o número da conta: ");
    scanf("%d", &Conta.numeroDaConta);
    fflush(stdin);
    printf("Digite o nome do titular: ");
    gets(Conta.titular);
    fflush(stdin);
    printf("Digite o tipo de conta\n1 - poupanca\n2- corrente):\n");
    scanf("%d", &Conta.tipoConta);
    fflush(stdin);
    limpar();
    do {
        printf("\nMenu:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Saldo\n");
        printf("4 - Sair\n\n");
        printf("Escolha uma opção:\n");
        scanf("%d", &escolha);
        limpar();
        switch (escolha) {
            case 1:
                printf("Digite o valor pra depósito: ");
                scanf("%f", &valor);
                depositar(&Conta, valor);
                break;
            case 2:
                printf("Digite o valor pro saque: ");
                scanf("%f", &valor);
                sacar(&Conta, valor);
                break;
            case 3:
                saldo(Conta);
                break;
            case 4:
                printf("Saindo!\n");
                break;
            default:
                printf("Opção inválida\nTente novamente.\n");
        }
    } while (escolha != 4);

    return 0;
}
