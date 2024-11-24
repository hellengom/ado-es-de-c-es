#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


#define ARQUIVO "adocoes.txt"

typedef struct {
    char nome[50];
    int idade;
    char endereco[100];
} Usuario;

typedef struct {
    char raca[30];
} Cachorro;

void listarRacas() {
    printf("Ra�as dispon�veis para ado��o:\n");
    printf("1. Labrador\n");
    printf("2. Poodle\n");
    printf("3. Bulldog\n");
    printf("4. Golden Retriever\n");
    printf("5. Pastor Alem�o\n");
    printf("6. Vira Lata\n");
    printf("7. Husky Siberiano\n");
     
}

void cadastrarUsuario(Usuario *usuario) {
    printf("Digite seu nome: \n");
    scanf(" %[^\n]", usuario->nome);
    printf("Digite sua idade: \n");
    scanf("%d", &usuario->idade);
    printf("Digite seu endere�o:\n");
    scanf(" %[^\n]", usuario->endereco);
    
    printf("Cadastro realizado com sucesso!\n");
}

void adotarCachorro(Usuario usuario) {
    Cachorro cachorro;
    int opcao;

    listarRacas();
    printf("Escolha uma ra�a para adotar: ");
    scanf("%d", &opcao);

    switch(opcao) {
        case 1:
            strcpy(cachorro.raca, "Labrador");
            break;
        case 2:
            strcpy(cachorro.raca, "Poodle");
            break;
        case 3:
            strcpy(cachorro.raca, "Bulldog");
            break;
        case 4:
            strcpy(cachorro.raca, "Golden Retriever");
            break;
        case 5:
            strcpy(cachorro.raca, "Pastor Alem�o");
            break;
        case 6:
        	 strcpy(cachorro.raca, "Vira Lata");
            break;
        case 7:
       		 strcpy(cachorro.raca, "Husky Siberiano");
            break;
            
        default:
            printf("Op��o inv�lida!\n");
            return;
    }

    FILE *arquivo = fopen(ARQUIVO, "a");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return;
    }

    fprintf(arquivo, "Nome: %s\nIdade: %d\nEndere�o: %s\nRa�a do Cachorro: %s\n\n",
            usuario.nome, usuario.idade, usuario.endereco, cachorro.raca);
    fclose(arquivo);
    
    
    printf("Parab�ns, voc� adotou um %s!\n", cachorro.raca);
}

void listarAdocoes(){
    char linha[200];
    FILE *arquivo = fopen(ARQUIVO, "r");

    if (arquivo == NULL) {
        printf("Nenhuma ado��o registrada.\n");
        return;
    }

    printf("Ado��es Registradas:\n");
    while (fgets(linha, sizeof(linha), arquivo)) {
        printf("%s", linha);
    }
    fclose(arquivo);
}

int main() {
	setlocale(LC_ALL, "portuguese");
    Usuario usuario;
    int opcao;
    int cadastroFeito = 0;
    
    	printf("Ol�, tudo bem? Vamos adotar um doguinho!\n");

    do {
    	
    
    	printf("\n============== Menu ==============\n");
    
    	printf("1. Listar Ra�as para Ado��o\n");
        printf("2. Cadastrar Usu�rio\n");
        printf("3. Adotar um Cachorro\n");
        printf("4. Listar Ado��es\n");
        printf("5. Sair\n");
        printf("=========================================\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listarRacas();
                break;
            case 2:
                cadastrarUsuario(&usuario);
                cadastroFeito = 1;
                break;
            case 3:
                if (cadastroFeito) {
                    adotarCachorro(usuario);
                } else {
                    printf("� necess�rio cadastrar um usu�rio antes de adotar.\n");
                }
                break;
            case 4:
                listarAdocoes();
                break;
            case 5:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida! Tente novamente.\n");
        }
    } while (opcao != 5);

    return 0;
}

