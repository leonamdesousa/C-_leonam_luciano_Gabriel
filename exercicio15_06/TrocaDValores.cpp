#include <stdio.h>

// Função que recebe os ponteiros e faz a troca
void trocar(int *ptr_a, int *ptr_b) {
    *ptr_a = *ptr_a + *ptr_b; // Passo 1: a vira (30 + 20) = 50
    *ptr_b = *ptr_a - *ptr_b; // Passo 2: b vira (50 - 20) = 30 (valor antigo de a)
    *ptr_a = *ptr_a - *ptr_b; // Passo 3: a vira (50 - 30) = 20 (valor antigo de b)
}

int main() {
    int a = 30;
    int b = 20;

    printf("Antes da troca:\n");
    printf("a = %d, b = %d, Soma = %d\n\n", a, b, a + b);

    // Passamos o endereço de memória de 'a' e 'b' para a função
    trocar(&a, &b);

    printf("Depois da troca:\n");
    printf("a = %d, b = %d, Soma = %d\n", a, b, a + b);

    return 0;
}