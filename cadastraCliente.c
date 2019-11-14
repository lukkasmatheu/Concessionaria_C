//Função de cadastramento de cliente

#include "libLocadoras.h"
int cadastraCliente(char arqFisicoClientes[], char arqFisicoLogin[], char username[]){
    FILE* arq= fopen(arqFisicoLogin,"rb");
    if(!arq)//verificação de abertura do arquivo
    {
        printf("\nErro ao abrir arquivo %s\n",arqFisicoLogin);
    }
    LogInfo nCliente;
    while(fread(&nCliente,sizeof(LogInfo),1,arq) != 0)//verificação se o nome de usuario já existe
    {
        if(strcmp(username,nCliente.username) == 0)
        {
            return -1;
        }
    }
    int tam=0;
    strcpy(nCliente.username,username);// struct que recebera nome de usuario e senha
    do{
        printf("\nDigite uma senha para a o usuario (ate 8 caracteres)\n");
        scanf("\n%s",nCliente.passwd);
        tam=strlen(nCliente.passwd);
    }while(tam>9);// verificação para ver se a senha tem o tamanho maior que o requerido.
    gravarNewLogingInfo(arqFisicoLogin,nCliente);// função responsavel por gravar o login/senha do novo usuario
    //apos o salvamento da senha o fclose fecha o arquivo.
    fclose(arq);

    Cliente cliente;// structura que ira receber as informações do usuario

    strcpy(cliente.login.username,username);//recebe o username do usuario
    //informações pessoais como nome, endereço, data de nascimento, etc.

    printf("\nInsira o primeiro nome:\n");
    scanf("\n%s",cliente.nome);

    printf("\nInsira o sobrenome:\n");
    scanf("\n%s",cliente.sobrenome);

    printf("\ninsira a data de nascimento(dia/mes/ano):\n");
    scanf("%d %d %d", &cliente.dataNascimento.dia, &cliente.dataNascimento.mes, &cliente.dataNascimento.ano);

    printf("\nInsira o nome da rua: \n");
    scanf("\n%[^\n]s",cliente.endereco.rua);

    printf("\nInsira o numero da casa:\n");
    scanf("%d",&cliente.endereco.numero);

    printf("\nInsira o complemento de referencia:\n");
    scanf("\n%[^\n]s",cliente.endereco.complemento);

    printf("\nInsira a cidade:\n");
    scanf("\n%[^\n]s",cliente.endereco.cidade);

    printf("\nInsira o cep:\n");
    scanf("%d", &cliente.endereco.cep);

    printf("\nInsira o email:\n");
    scanf(" %s",cliente.contato.email);

    printf("\nInsira o telefone:\n");
    scanf(" %s",cliente.contato.fone);

/*    for(int i=0;i<MAX_LOCADORAS_POR_CLIENTE;i++)
    {
        strcpy(cliente.vetAvaliacoes[i].nomeLocadora,"NULL");
    }*/
    cliente.numeroAvaliacoes=0;// zera o numero de avaliaçoes
    gravarCliente(arqFisicoClientes,cliente);//chamada da função para salvar as informações do cliente.
    return 0;
}
