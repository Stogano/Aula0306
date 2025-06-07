#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Filme {
    char titulo[100];
    char diretor[100];
    int ano;
};

int main() {
    struct Filme f;

    printf("Título: ");
    fgets(f.titulo, sizeof(f.titulo), stdin);
    f.titulo[strcspn(f.titulo, "\n")] = '\0'; 

    printf("Diretor: ");
    fgets(f.diretor, sizeof(f.diretor), stdin);
    f.diretor[strcspn(f.diretor, "\n")] = '\0';  

    printf("Ano: ");
    scanf("%d", &f.ano);

    FILE *arquivo = fopen("filmes.txt", "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    fprintf(arquivo, "%s|%s|%d\n", f.titulo, f.diretor, f.ano);
    fclose(arquivo);

    printf("Filme salvo com sucesso!\n");
    return 0;
}
