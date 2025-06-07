#include <stdio.h>
#include <string.h>
int main(void) {
    
    char nome[200],nomeArquivo[100],des[200], *fim;
    int res = 1;

    printf("Digite o titulo do livro que quer encontrar(ex: chapeuzinho_vermelho.txt): ");
    scanf("%s",nomeArquivo);

 
    nomeArquivo[strcspn(nomeArquivo, "\n")] = 0;


    if (strstr(nomeArquivo, ".txt") == NULL) {
        strcat(nomeArquivo, ".txt");
    }

    FILE *arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao encontrar o arquivo!\n");
        return 1;
    }

    do { 
        
        printf("Digite P para ver o nome dos personagens ou F para encerrar ");
        scanf("%19s", nome);
        res = strcmp(nome,"F");
        
        
        if(res != 0 && strcmp(nome,"P") == 0 )
        {
             fim=fgets(des, 200, arquivo);
             printf("%s", des);
        }
       
        if (fim == NULL){
               printf("Acabou os personagens! \n");  
               break;
            }
    }
    while( res != 0 &&  fim  != NULL);

    fclose(arquivo);

    return 0;
}  