#include "libLocadoras.h"
void listarClientes(char arqFisicoClientes[]){
    //abertura do arquivo de clientes
    FILE* arq= fopen(arqFisicoClientes,"rb");
    if(!arq)// verificação ao abrir o arquivo
    {
        printf("\nErro ao abrir o arquivo %s\n", arqFisicoClientes);
        return ;
    }
    Cliente cliente;//struct que recebera as informaçoes dos clientes cadastrados.
    while(fread(&cliente,sizeof(Cliente),1,arq)!= 0)//laço que executara a leitura dos dados dos clientes e passara os dados para a estrutura, que apois isso ira printar os dados dos clientes
    {
        printf("\nNome:%s %s \t Username:%s\nData de nascimento: (%.2d/%.2d/%d)\nEndereco\nRua:%s \t numero:%d\nComplemento:%s\nCidade:%s\nCep:%d\nContato\nEmail:%s\nTelefone:%s\n\n", cliente.nome, cliente.sobrenome, cliente.login.username, cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano, cliente.endereco.rua, cliente.endereco.numero, cliente.endereco.complemento, cliente.endereco.cidade, cliente.endereco.cep, cliente.contato.email, cliente.contato.fone);
    }
    fclose(arq);//fechamento do arquivo.
}


