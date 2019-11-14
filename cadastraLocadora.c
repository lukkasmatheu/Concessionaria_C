//função responavel por cadastrar novas locadoras
#include "libLocadoras.h"
void cadastraLocadora(char arqFisicoLocadoras[]){
    FILE* arq= fopen(arqFisicoLocadoras,"rb");//abertura do arquivo.
    if(!arq)//teste de abertura do arquivo
	{
		printf("\nErro ao abrir o arquivo\n");
		return;
	}
    char nomelocadora[50];//variavel que recebera o nome da locadora
    int id, igual=0;
    Locadora nLocadora;//struct da locadora
    //laço responsavel por fazer a verificação do nome da locadora e o id da nova locadora
    while(igual!= 1)
    {
        id=1;// o id começa do 1.
        printf("\nInsira o nome da locadora\n");
        scanf("\n%[^\n]s",nomelocadora);
	igual=1;//seta igual ao valor 1, apos o teste abaixo sai do while caso não ouver nenhum nome igual.
        //verificação se o nome da locadora ja esta sendo usado.
        while(fread(&nLocadora,sizeof(Locadora),1,arq) != 0)
        {
            //id da locadora cadastrada, como a locadora vai ser adicionada no fim do arquivo ela recebera o id correspondente ao seu cadastro
            id++;
            if(strcmp(nomelocadora,nLocadora.nome) == 0){
                printf("\nNome digitado ja esta sendo usado por outra locadora\n");
                igual=0;// pede novamente o nome da locadora ate o nome digitado ser diferente dos que ja existem.
            }

        }
    }
    strcpy(nLocadora.nome, nomelocadora);// apos a verificação do nome copia o nome da locadora para a struct.
    nLocadora.id=id;
    //recebe as informações da locadora na struct nLocadora.
    printf("\nEndereço\nInsira o nome da rua:");
    scanf(" %[^\n]s", nLocadora.endereco.rua);

    printf("\n Insira o numero :");
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
    //verificação dos tipos de veiculos existente na locadora.
    nLocadora.tipoDeCarro.conversivel= setaCategoria("conversivel");
    nLocadora.tipoDeCarro.grande= setaCategoria("grande");
    nLocadora.tipoDeCarro.medio= setaCategoria("medio");
    nLocadora.tipoDeCarro.minivan= setaCategoria("minivan");
    nLocadora.tipoDeCarro.pequeno= setaCategoria("pequeno");
    nLocadora.tipoDeCarro.premium= setaCategoria("premium");
    nLocadora.tipoDeCarro.SUV= setaCategoria("SUV");
    //zera as avaliaçoes.
    nLocadora.avaliacao.bom=nLocadora.avaliacao.excelente=nLocadora.avaliacao.ruim=0;

    //grava as informaçoes da locadora no arquivo e fecha o arquivo.
    gravarLocadora(arqFisicoLocadoras,nLocadora);
    fclose(arq);
}
