//função para avaliar locadora
#include "libLocadoras.h"
int avaliarLocadora (char arqFisicoLocadoras[], char nomeLocadora[]){
   int opt = -1, achou=0;
   //abertura do arquivo locadora no modo leitura e escrita.
   FILE* arq=fopen(arqFisicoLocadoras,"r+b");
   //verificação de abertura do arquivo.
   if(!arq)
   {
        printf("\nErro ao abrir o arquivo\n");
        return -1;
   }
   Locadora locadora;
   //verificação do nome da locadora,
    while(fread(&locadora,sizeof(Locadora),1,arq)!=0 || achou != 1)
    {
        if(strcmp(locadora.nome,nomeLocadora) == 0)
            achou=1;
    }
    if(achou == 0)
    {
        return -1;
    }
    printf("\nLocadora selecionada:%s\n", locadora.nome);
    printf("\nDigite sua avaliacao\n2-Ruim\n3-Bom\n4-Excelente\n");
    scanf("%d", &opt);
    if(opt == 2){
        locadora.avaliacao.ruim+=1;
    }
    else if(opt == 3){
    locadora.avaliacao.bom+=1;
    }
    else if(opt == 4){
        locadora.avaliacao.excelente+=1;
    }
    fseek(arq, -1 * sizeof(Locadora),SEEK_CUR);
    fwrite(&locadora, sizeof(Locadora),1, arq);
    fclose(arq);
    return opt;
}

