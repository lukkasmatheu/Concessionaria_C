
#include "libLocadoras.h"
void listarLocadoras(char arqFisicoLocadoras[]){
    FILE* arq = fopen(arqFisicoLocadoras,"rb");
    //Abertura e verificação do arquivo, caso não seja aberto o programa apresentara uma mensagem de erro e fechara o programa
    if(!arq)
    {
        printf("\nErro ao abrir o arquivo %s\n",arqFisicoLocadoras);
        return ;
    }
    // struct que recebera as informaçoes da locadoras.
    Locadora infoLocadora;
    //Laço que verificara cada struct salva no arquivo binario,lançado os dados na variavel de estrutura cujo sera printado as informaçoes lida.
    while(fread(&infoLocadora,sizeof(Locadora),1,arq)!= 0)
    {
        //printa as informaçoes como nome e endereço contato id etc.
        printf("\nNome da locadora: %s \t id:%d\n   \t\tCONTATO\nE-mail:%s \tTelefone:%s\n  \t\tENDEREÇO\nRua:%s\t\tnumero:%d\ncomplemento:%s\nCidade:%s  \tcep:%d\n\nModelos de carro existente na locadora:", infoLocadora.nome, infoLocadora.id, infoLocadora.contato.email, infoLocadora.contato.fone, infoLocadora.endereco.rua, infoLocadora.endereco.numero, infoLocadora.endereco.complemento, infoLocadora.endereco.cidade, infoLocadora.endereco.cep );
        //condições utilizadas para a verficação dos veiculos que a locadora possui, no caso de possuir os modelos de veiculo ele sera printado
        if(infoLocadora.tipoDeCarro.conversivel== 1)
        {
            printf("\nconversivel\n");
        }
        if(infoLocadora.tipoDeCarro.premium == 1)
        {
            printf("\nPremiun\n");
        }
        if(infoLocadora.tipoDeCarro.grande == 1)
        {
            printf("\nGrande\n");
        }
        if(infoLocadora.tipoDeCarro.medio == 1)
        {
            printf("\nMedio\n");
        }

        if(infoLocadora.tipoDeCarro.pequeno == 1)
        {
            printf("\nPequeno\n");
        }
        if(infoLocadora.tipoDeCarro.SUV == 1)
        {
            printf("\nSUV\n");
        }
        if(infoLocadora.tipoDeCarro.minivan == 1)
        {
            printf("\nMinivans\n");
        }
        //variavel que ira receber o total de avaliações realiazadas pelos clientes a locadora.
        int total=0;
	//a variavel total recebera o total de avaliações da locadora.
        total= infoLocadora.avaliacao.bom + infoLocadora.avaliacao.excelente + infoLocadora.avaliacao.ruim;
	//impressão das avaliações da locadora seguida do total de avaliações.
        printf("\n  AVALIACAO DA LOCADORA \nExcelente:%d/%d\nBoa:\t\t%d/%d\nRuim:\t\t%d/%d\n\n",infoLocadora.avaliacao.excelente,total,infoLocadora.avaliacao.bom, total, infoLocadora.avaliacao.ruim, total);
    }
    //fechamento do arquivo apos o uso.
    fclose(arq);
}
