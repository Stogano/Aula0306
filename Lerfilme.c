#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Filme {
    char titulo[100];
    char diretor[100];
    int ano;
};

int main() {
    FILE *arquivo = fopen("filmes.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    struct Filme f;
    char linha[300];

    while (fgets(linha, sizeof(linha), arquivo)) {
        linha[strcspn(linha, "\n")] = '\0';
        sscanf(linha, "%99[^|]|%99[^|]|%d", f.titulo, f.diretor, &f.ano);

        printf("Título: %s\n", f.titulo);
        printf("Diretor: %s\n", f.diretor);
        printf("Ano: %d\n", f.ano);
        printf("------\n");
    }

    fclose(arquivo);
    return 0;
}
