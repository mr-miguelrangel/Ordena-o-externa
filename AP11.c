#include <stdio.h>
#include <stdlib.h>

typedef struct heapMin {
    int *v;
    int ultimoRetirado;
} Heap;

void mesclar_fitas (const char *fita1, const char *fita2, const char *saida);

int main (void) {
    FILE *fita1, *fita2;
    int i;

    fita1 = fopen ("fita1.txt", "a");
    fita2 = fopen ("fita2.txt", "a");

    for (i = 0; i < 1000; i++){
        fprintf (fita1, "%d\n", 2*i);
        fprintf (fita2, "%d\n", 2*i+1);
    }

    fclose (fita1);
    fclose (fita2);

    mesclar_fitas ("fita1.txt", "fita2.txt", "saida.txt");

    return 0;
}

void mesclar_fitas (const char *fita1, const char *fita2, const char *saida) {
    FILE *f1, *f2, *fs;
    int num1, num2;

    f1 = fopen (fita1, "r");
    f2 = fopen (fita2, "r");
    fs = fopen (saida, "w");

    if (f1 == NULL || f2 == NULL || saida == NULL) {
        printf ("Erro ao abrir arquivo\n");
        return;
    }

    // Lê o primeiro número de cada arquivo
    fscanf(f1, "%d", &num1);
    fscanf(f2, "%d", &num2);
    printf("%d\n%d", num1, num2);

    // Mescla os números em ordem crescente
    while (!feof (f1) && !feof (f2)) {
        if (num1 <= num2) {
            fprintf (fs, "%d\n", num1);
            fscanf (f1, "%d", &num1);
        }
        else {
           fprintf (fs, "%d\n", num2);
            fscanf (f2, "%d", &num2); 
        }
    }

    // Copia os números restantes, se houver
    while (!feof(f1)) {
        fprintf(fs, "%d\n", num1);
        fscanf(f1, "%d", &num1);
    }
    while (!feof(f2)) {
        fprintf(fs, "%d\n", num2);
        fscanf(f2, "%d", &num2);
    }

    // Fecha os arquivos
    fclose(f1);
    fclose(f2);
    fclose(fs);
}