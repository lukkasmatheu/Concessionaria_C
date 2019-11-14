//Função para salavar os dados da locadora
#include "libLocadoras.h"
void gravarLocadora(char arqFisicoLocadoras[], Locadora locadora){
    FILE* arq=fopen(arqFisicoLocadoras,"ab");//abertura do arquivo.
    if(!arq)//verificação se arquivo foi aberto corretamente.
    {
        printf("\nErro ao abrir o arquivo %s\n",arqFisicoLocadoras);
    }
    fwrite(&locadora,sizeof(Locadora),1,arq);
    fclose(arq);
}

