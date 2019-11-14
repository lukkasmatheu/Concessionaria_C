//função resposanvel por alterar informações da locadora.
#include "libLocadoras.h"
void alterarLocadora(char arqFisicoLocadoras[]){
    FILE* arq= fopen(arqFisicoLocadoras,"r+b");
    char nomeLocadora[20];//nome da locadora a ser alterado
    Locadora nLocadora;//estrutura locadora
    int achou=0;
    if(!arq)
    {
        printf("\nErro ao abrir arquivo %s\n", arqFisicoLocadoras);// mensagem de erro ao abrir o arquivo
    }
    printf("\nInsira o nome da locadora\n");
    scanf("\n%[^\n]s", nomeLocadora);
    while(fread(&nLocadora,sizeof(Locadora),1,arq) != 0 || achou!=1)//laço de repetição responsavel pela leitura do arquivo binario para buscar os dados da locadora.
    {
        if(strcmp(nLocadora.nome,nomeLocadora) == 0)
            achou=1;
    }
    if(achou == 0)//caso a locadora não seja encontrada mostrara esta mensagem de erro
    {
        printf("\nLocadora não encontrada\n");
    }
    //altera os dado caso o arquivo é encontrado.
    else{

        printf("\nEndereço\nInsira o nome da rua:");
        scanf(" %[^\n]s", nLocadora.endereco.rua);

        printf("\n Insira o numero da rua:");
        scanf("%d", &nLocadora.endereco.numero);

        printf("\nInsira o complemento:");
        scanf(" %[^\n]",nLocadora.endereco.complemento);

        printf("\nInsira o nome da cidade:");
        scanf(" %[^\n]s", nLocadora.endereco.cidade);

        printf("\nInsira o cep:");
        scanf("%d", &nLocadora.endereco.cep);

        printf("\nInsira o email:");
        scanf(" %s", nLocadora.contato.email);

        printf("\nInsira o telefone:");
        scanf(" %s", nLocadora.contato.fone);

        nLocadora.tipoDeCarro.conversivel= setaCategoria("conversivel");
        nLocadora.tipoDeCarro.grande= setaCategoria("grande");
        nLocadora.tipoDeCarro.medio= setaCategoria("medio");
        nLocadora.tipoDeCarro.minivan= setaCategoria("minivan");
        nLocadora.tipoDeCarro.pequeno= setaCategoria("pequeno");
        nLocadora.tipoDeCarro.premium= setaCategoria("premium");
        nLocadora.tipoDeCarro.SUV= setaCategoria("SUV");
        fseek(arq,-1*sizeof(Locadora),SEEK_CUR);//mudando para posição anterior do arquivo.
        fwrite(&nLocadora,sizeof(Locadora),1,arq); //sobrescresvendo dados alterados.
     }
    fclose(arq);//fechamento do arquivo
}
