//função responsavel por alterar as votação realizadas pelos usuarios
#include "libLocadoras.h"
void atualizaAvaliacaoCliente(char arqFisicoClientes[], char usernameCliente[], char nomeLocadora[], int avaliacao){
    FILE* arq=fopen(arqFisicoClientes,"r+b");//abertura do arquivo em modo de leitura e escrita.
    if(!arq)//verificação de abertura do arquivo
    {
        printf("\nErro ao abrir o arquivo\n");
    }
    Cliente cliente;// estrutura que sera colocado os dados do cliente.
    int achou=0,i=0;
    //verifica se o cliente existe e salva os dados na estrutura cliente
    while(fread(&cliente,sizeof(Cliente),1,arq)!=0 || achou !=1)
    {
        if(strcmp(usernameCliente,cliente.login.username)==0)
        {
            achou=1;
        }
    }
    if(achou == 0)
    {
        printf("\nUsuario não encontrado\n");
    }
    int aux=0;
    //loop enquanto o i estiver menor que o maximo de locadoras ou a locadora não for encontrada.
    for(i=0;i<cliente.numeroAvaliacoes;i++)
    {
        if(strcmp(cliente.vetAvaliacoes[i].nomeLocadora,nomeLocadora) == 0)
         {
            aux=1;
            achou=i;
         }
    }
    i=achou;
    //acrecenta 1 ao numero de avaliações realizadas, caso não hava nenhuma avaliação realizada para esta locadora.
    if(aux == 0){
        strcpy(cliente.vetAvaliacoes[i].nomeLocadora,nomeLocadora);
        printf("\n o nome  %s \n", cliente.vetAvaliacoes[i].nomeLocadora);
        cliente.numeroAvaliacoes+=1;
    }
    // condiçoes que atualizara as avaliações.
    if(avaliacao == 2)
    {
        cliente.vetAvaliacoes[i].avaliacaoLocadora.ruim=1;
        cliente.vetAvaliacoes[i].avaliacaoLocadora.excelente=0;
        cliente.vetAvaliacoes[i].avaliacaoLocadora.bom=0;
    }
    else if(avaliacao == 3)
    {
        cliente.vetAvaliacoes[i].avaliacaoLocadora.ruim=0;
        cliente.vetAvaliacoes[i].avaliacaoLocadora.excelente=0;
        cliente.vetAvaliacoes[i].avaliacaoLocadora.bom=1;
    }
    else if(avaliacao == 4)
    {
        cliente.vetAvaliacoes[i].avaliacaoLocadora.ruim=0;
        cliente.vetAvaliacoes[i].avaliacaoLocadora.excelente=1;
        cliente.vetAvaliacoes[i].avaliacaoLocadora.bom=0;
    }
    fseek(arq, -1 * sizeof(Cliente) ,SEEK_CUR);
    fwrite(&cliente, sizeof(Cliente) ,1,arq);
    fclose(arq);
}
