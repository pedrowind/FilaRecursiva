#include <stdio.h>
#include <stdlib.h> // Inclusão para malloc

// Defina as estruturas e typedefs
struct Fila {
    struct No *frente;
    struct No *tras;
};

struct No {
    int dado;
    struct No *prox;
};

typedef struct No no;
typedef struct Fila fila;
typedef no *noPtr;
typedef fila *filaPtr;

// Protótipos de função
void menu();
noPtr criarNo(int);
filaPtr criarFila();
filaPtr enfileirarRecursivo(filaPtr, int);
void imprimirFila(filaPtr);

int main() {
    int operador = 9, numero;
    filaPtr F = criarFila();

    while (operador != 0) {
        menu();
        printf("Insira o operador desejado: ");
        scanf("%d", &operador);

        switch (operador) {
        case 0:
            return 0;

        case 1:
            printf("Insira o primeiro número a ser enfileirado: ");
            scanf("%d", &numero);
            F = enfileirarRecursivo(F, numero); // Chamada de função corrigida
            printf("Fila enfileirada com sucesso.\n");
            break;

        case 2:
            imprimirFila(F); // Chamada de função corrigida
            printf("Fila impressa com sucesso.\n");
            break;

        default:
            printf("Insira um parâmetro válido.\n"); // Adicionado um caractere de nova linha
            break;
        }
    }
    return 0;
}

noPtr criarNo(int numero) {
    noPtr novoNo = (no*)malloc(sizeof(no));

    novoNo->prox = NULL;
    novoNo->dado = numero;
    return novoNo; // Retorna o novo nó criado
}

filaPtr criarFila() {
    filaPtr novaFila = (fila*)malloc(sizeof(fila));

    novaFila->frente = NULL;
    novaFila->tras = NULL;
    return novaFila;
}

filaPtr enfileirarRecursivo(filaPtr fila, int numero) {
    noPtr novoNo = criarNo(numero);

    if (fila->frente == NULL) {
        fila->frente = novoNo;
        fila->tras = novoNo;
    } else {
        printf("Insira o próximo número a ser enfileirado (0 para parar): ");
        scanf("%d", &numero);

        if (numero != 0) {
            fila->tras->prox = enfileirarRecursivo(fila, numero);
            fila->tras = fila->tras->prox;
        }
    }
    return fila;
}

void imprimirFila(filaPtr filaPtr) {
    noPtr atual = filaPtr->frente;

    if (atual == NULL) {
        printf("Fila vazia.\n");
        return;
    }

    printf("Elementos na fila:\n");

    while (atual != NULL) {
        printf("%d ", atual->dado);
        atual = atual->prox;
    }

    printf("\n");
}

void menu() {
    system("cls"); // Isso é para o Windows, considere usar "clear" para sistemas semelhantes ao Unix
    printf("*-------------------------*\n");
    printf("* 1- Enfileirar recursivo *\n");
    printf("* 2- Imprimir fila        *\n");
    printf("*-------------------------*\n");
}
