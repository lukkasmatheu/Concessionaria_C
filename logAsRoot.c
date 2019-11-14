//libLocadoras.h é inclusa para que a função logAsRoot tenha acesso às definições de registros, funções e constantes
#include "libLocadoras.h"
void logAsRoot(char arqFisicoClientes[], char arqFisicoLogin[], char arqFisicoLocadoras[]){
    printf("\n**** Bem vindo root **** \n");
    int opt, idLocadora;
    char username[MAX_USER];

    menuRoot();
    scanf("%d", &opt);
    while (opt != 9){
        switch(opt){
        case 1: printf("\nInsira um username:\n");
            scanf(" %s",username);
            int cadastro = cadastraCliente(arqFisicoClientes,arqFisicoLogin,username);
            if(cadastro == -1)
                printf("\nUsername fornecido ja esta em uso\n");
            else
                printf("\nUsuario cadastrado com sucesso\n");
            break;
        case 2: cadastraLocadora(arqFisicoLocadoras);
            break;
        case 3:printf("\nInsira o username do usuario:\n");
            scanf(" %s",username);
            int alteraDados=alterarCliente(arqFisicoClientes,username);
            if(alteraDados == -1)
                printf("\nUsuario informado não cadastrado\n");
            else if(alteraDados == 0)
                printf("\nDados alterados com sucesso\n");
            break;
        case 4:alterarLocadora(arqFisicoLocadoras);
            break;
        case 5:printf("\nInsira o username do usuario:\n");
            scanf(" %s",username);
            int remove=removerCliente(arqFisicoClientes,arqFisicoLogin,username);
            if(remove == -1)                    
                printf("\nErro ao excluir cliente\n");
            else
                printf("\nCliente removido com sucesso\n");
            break;
        case 6:printf("\nInsira o ID da locadora a ser removida:\n");
            scanf("%d", &idLocadora);
            removerLocadora(arqFisicoLocadoras,idLocadora);
            break;
        case 7: listarClientes(arqFisicoClientes);
            break;
        case 8:listarLocadoras(arqFisicoLocadoras);
            break;
        case 9: printf("\nLogout realizado com sucesso\n");
            break;
        default: printf("\nNumero invalido\n");
        }

       menuRoot();
       scanf("%d", &opt);
    }
}

