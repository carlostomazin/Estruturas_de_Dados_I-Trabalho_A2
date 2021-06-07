#include "operacoes.c"
#include <stdio.h>

int main(){

    iniciar(sergin, sergin_ordenado);

    do{
        inicio:
        
        menu();
        funcaoSetas();

        switch (opcao) {
        case 1:
            imprimir(sergin);
            voltarMenu();
            break;
        case 2:
            imprimir_ord(sergin_ordenado);
            voltarMenu();
            break;
        case 3:
            buscaAno(alvo, sergin_ordenado);
            voltarMenu();
            break;
        case 4:
            sairMenu();
        default:
            printf("Voce deve escolher uma opcao valida\n");
            printf("Precione qualquer tecla para voltar ao menu\n");
            system("pause");
            goto inicio;
        }
    }while(1);

    return 0;
}