#include <stdio.h>
#include <string.h>

int main() {
    FILE *arquivo = fopen("Remedio.txt", "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return 1;
    }

    char linha[100],ultima[100];


    while (fgets(linha, sizeof(linha), arquivo)) {
        strcpy(ultima, linha); 
    }

    fclose(arquivo);

    printf("Última: %s", ultima);
    return 0;
}
