#include <stdio.h>
#include <string.h>
int main(void) {
    char data[11],hora[6];

    printf("Digite uma data (Exp: 01/01/2023)");
    scanf("%10s",data);
    printf("Digite uma hora (Exp: 12:00)");
    scanf("%5s",hora);

     FILE *pArquivo = NULL;
    pArquivo = fopen("Remedio.txt", "a");

    if (pArquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    fprintf(pArquivo, "%s %s\n", data, hora);

    printf("Informação salva com sucesso!\n");
    fclose(pArquivo);
    return 0;
}  