#include <stdio.h>
#include <string.h>
int main(void) {
    
    char nome[200];
    char enter[200];
    char nomeArquivo[100];
    int res = 1;

    printf("Digite o titulo do livro (ex: chapeuzinho_vermelho.txt): ");
    scanf("%s",nomeArquivo);

 
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;


    if (strstr(nomeArquivo, ".txt") == NULL) {
        strcat(nomeArquivo, ".txt");
    }

    FILE *arquivo = fopen(nomeArquivo, "w");
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;
    }

    do {
        printf("Digite o nome dos personagens do livro(F para finalizar)");
        scanf("%19s", nome);
        
        res = strcmp(nome,"F");
        if(res != 0){
            fputs(strcat(nome, "\n") , arquivo);
        }
        
    }
    while( res != 0);
    fclose(arquivo);

    return 0;
}  