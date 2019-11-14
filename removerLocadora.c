#include "libLocadoras.h"
void removerLocadora(char arqFisicoLocadoras[], int idLocadora){
    FILE *arq = fopen (arqFisicoLocadoras, "r+b");
    //verificação de abertura dos arquivos onde esta as locadoras
    if (arq == NULL){
        printf("\nErro ao abrir arquivo de locadoras.\n");
    }
    //verificação de abertura do arquivo que recebera as locadoras.
    FILE *arqTmp = fopen ("tmp.bin", "wb");
    if (arqTmp == NULL){
        printf("\nErro ao abrir arquivo de copia\n");
    }
    Locadora locadora;
    int encontrou = 0;
    while (fread(&locadora, sizeof(Locadora), 1, arq) != 0 ){
        //condição que verifica a locadora a ser removido
        if (locadora.id == idLocadora){
            encontrou  = 1;
        }
        //no caso de não ser a locadora a ser removida salva as informações da locadora em outro arquivo, ou seja todas locadoras menos a que sera removida sera salava no novo arquivo.
        else{
            fwrite(&locadora, sizeof(Locadora), 1, arqTmp);
        }
    }
    if(encontrou == 0)
    {
        printf("\nLocadora inexistente\n");
    }
    //fechamento dos arquivos ultilizados
    fclose(arq);
    fclose(arqTmp);
    //remove o arquivo ondce esta as locadoras com a que deve ser removida.
    remove(arqFisicoLocadoras);
   //renomeia o arquivo de copia para o arquivo de locadoras, contendo todas as locadoras menos a que deveria ser removida.
    rename("tmp.bin", arqFisicoLocadoras);
}

