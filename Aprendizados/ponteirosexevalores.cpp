#include <stdio.h>

void trocar(int *a, int *b) {
    if (a != b) { // Evita problemas caso o mesmo ponteiro seja passado
        *a = *a + *b; // a agora é a soma dos dois (30 + 20 = 50)
        *b = *a - *b; // b recebe a soma antiga menos b (50 - 20 = 30)
        *a = *a - *b; // a recebe a soma antiga menos o novo b (50 - 30 = 20)
    }
}

int main() {
    int a = 30;
    int b = 20;

    printf("Antes: a = %d, b = %d\n", a, b);
    
    // Passa os endereços de memória das variáveis
    trocar(&a, &b);

    printf("Depois: a = %d, b = %d\n", a, b);

    return 0;
}
