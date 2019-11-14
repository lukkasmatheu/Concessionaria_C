//função responsavel por gravar as informaçoes do clientes
#include "libLocadoras.h"

void gravarCliente(char arqFisicoClientes[], Cliente c){
    FILE* arq = fopen (arqFisicoClientes, "ab");
    if (!arq){
       printf("\nErro ao abrir arquivo de clientes.\n");
       return;
    }
    fwrite(&c, sizeof(Cliente), 1, arq);
    fclose(arq);
}
