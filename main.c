#include <stdio.h>
#include <string.h>


#define MAX_USUARIOS 100
#define TAMANHO_SENHA 50
#define ARQUIVO "usuarios.txt"


typedef struct {
    int id;
    char nome[50];
    char senha[TAMANHO_SENHA];
} Usuario;


void criptografar(char *senha) {
    for (int i = 0; i < strlen(senha); i++) {
        senha[i] ^= 0xAA; 
    }
}


void adicionarUsuario() {
    Usuario usuario;
    FILE *arquivo = fopen(ARQUIVO, "a");

    printf("Digite o ID do usuario: ");
    scanf("%d", &usuario.id);
    printf("Digite o nome do usuario: ");
    scanf("%s", usuario.nome);
    printf("Digite a senha: ");
    scanf("%s", usuario.senha);

    criptografar(usuario.senha);

    fprintf(arquivo, "%d %s %s\n", usuario.id, usuario.nome, usuario.senha);
    fclose(arquivo);
    printf("Usuario adicionado com sucesso.\n");
}



int main() {
    int opcao;
    do {
        printf("1. Adicionar Usuario\n");
        printf("2. Alterar Usuario\n");
        printf("3. Excluir Usuario\n");
        printf("4. Listar Usuarios\n");
        printf("5. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: adicionarUsuario(); break;
          
            case 5: printf("Saindo...\n"); break;
            default: printf("Opcao invalida!\n");
        }
    } while (opcao != 5);

    return 0;
}