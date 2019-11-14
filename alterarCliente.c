//função resposavel por alterar dados dos clientes
#include "libLocadoras.h"
int alterarCliente(char arqFisicoClientes[], char usernameCliente[]){
    FILE* arq=fopen(arqFisicoClientes, "r+b");//abertura do arquivo de clientes
    if(!arq)// verificação da abertura do arquivo.
    {
        printf("\nErro ao abrir o arquivo %s\n", arqFisicoClientes);
        return 1;
    }
    Cliente alter;//struct que recebera os dados do cliente a ser alterado.
    //estrutura de dados a ser alterado.
    Endereco endereco;
    Contatos contato;
    int achou=0;//indicador que ira informar quando a condição encontrar as informações do usuario no arquivo.
    while(fread(&alter,sizeof(Cliente),1,arq)!=0 || achou !=1)// loop percorrendo o arquivo binario.
    {
        if(strcmp(usernameCliente,alter.login.username)==0)// condição de comparação do usuario informado com o usuario do arquivo.
            achou=1;
    }
    if(achou== 0)//no caso do programa não encontrar o usuario a ser alterado ele retornara -1.
    {
        return -1;
    }
    int n=0;
    while(n!= 3)//escolha dos dados a ser alterado.
    {
        printf("\nescolha uma opção abaixo\n1-Alterar o contato\n2-Alterar endereço\n3-sair\n");
        scanf("%d", &n);
        if(n == 1)//alteração do contato.
        {
            printf("\nInsira o email\n");
            scanf(" %[^\n]s", contato.email);
            printf("\nInsira o telefone\n");
            scanf(" %[^\n]s", contato.fone);
            alter.contato=contato;
        }
        else if(n == 2)//alteração do endereço.
        {
            printf("\nDigite o nome da rua\n");
            scanf(" %[^\n]s", endereco.rua);
            printf("\nDigite o numero da moradia\n");
            scanf("%d", &endereco.numero);
            printf("\nInsira o complemento\n");
            scanf(" %[^\n]s", endereco.complemento);
            printf("\nInsira a cidade\n");
            scanf(" %[^\n]s", endereco.cidade);
            printf("\nInsira o cep\n");
            scanf("%d", &endereco.cep);
            alter.endereco=endereco;
        }
    }


    fseek(arq,-1*sizeof(Cliente),SEEK_CUR);//alteração da posição, para a posição anterior cujo esta localizado o arquivo.
    fwrite(&alter,sizeof(Cliente),1,arq);//sobrescrendo as informações apos a alteração.
    fclose(arq);//fechamento do arquivo.
    return 0;
}
