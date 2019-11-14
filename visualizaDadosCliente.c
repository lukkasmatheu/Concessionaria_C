//Função para printar dados do cliente logado
#include "libLocadoras.h"
void visualizaDadosCliente(char arqFisicoClientes[], LogInfo userLog){
    FILE* arq= fopen(arqFisicoClientes,"rb");
    if(!arq)// verificação ao abrir o arquivo
    {
        printf("\nErro ao abrir o arquivo %s\n", arqFisicoClientes);
        return ;
    }
    int achou=0,i=0;
    Cliente cliente;//struct que recebera as informaçoes dos clientes cadastrados.
    while(fread(&cliente,sizeof(Cliente),1,arq)!= 0 || achou!=1)//laço que executara a leitura dos dados dos clientes e passara os dados para a estrutura, que apois isso ira printar os dados dos clientes
    {
        if(strcmp(userLog.username,cliente.login.username)==0)//comparação do nome do usuario
         {
            printf("\nNome:%s %s \t Username:%s\nData de nascimento: (%.2d/%.2d/%d)\nEndereco\nRua:%s \t numero:%d\nComplemento:%s\nCidade:%s\nCep:%d\nContato\nEmail:%s\nTelefone:%s\nTotal de avaliacoes:%d\n\n", cliente.nome, cliente.sobrenome, cliente.login.username, cliente.dataNascimento.dia, cliente.dataNascimento.mes, cliente.dataNascimento.ano, cliente.endereco.rua, cliente.endereco.numero, cliente.endereco.complemento, cliente.endereco.cidade, cliente.endereco.cep, cliente.contato.email, cliente.contato.fone, cliente.numeroAvaliacoes);
           //laço de repetição que ira rodar o vetor de avaliação a avaliação dada a cada locadora pelo cliente.
            for(i=0;i<cliente.numeroAvaliacoes;i++)
            {
                printf("\nAvaliação da locadora %s\n",cliente.vetAvaliacoes[i].nomeLocadora);
                if(cliente.vetAvaliacoes[i].avaliacaoLocadora.bom!=0)
                    printf("\nboa\n");
                else if(cliente.vetAvaliacoes[i].avaliacaoLocadora.excelente!=0)
                    printf("\nexcelente\n");
                else if(cliente.vetAvaliacoes[i].avaliacaoLocadora.ruim!=0)
                    printf("\nRuim\n");
            }
            achou=1;//apos imprimir todas as informaçoẽs o laço ira parar
        }
    }
    fclose(arq);//fechamento do arquivo.
}

