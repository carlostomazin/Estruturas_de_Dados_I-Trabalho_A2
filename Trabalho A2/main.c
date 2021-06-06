#include "proc.c"
#include <stdio.h>

int main(){
    
    economia sergin[tam];
    economia_ord sergin_ord[tam];
    int resp, resp2, alvo, busca;

    printf ("\n1 - INICIAR\n");
    printf ("2 - SAIR\n\n");

    printf("-> ");
    scanf("%d",&resp);

    while (1){
        
        switch (resp){
        case 1:
            iniciar(sergin, sergin_ord);
            break;
        case 2:
            printf("ENCERRANDO O PROGRAMA...\n");
            sleep(1);
            exit(1);
        default:
            printf("ESCOLHA INVALIDA\n");
            printf("ESCOLHA UMA DAS OPCOES ACIMA!!!\n");
            printf("-> ");
            scanf("%d",&resp);
            break;
        }
        break;
    }

    quickSort(sergin_ord, 0, tam-1);

    do{fflush(stdin);
        resp = menu();
    
        if(resp == 1){
            imprimir(sergin);
            resp2 = voltarMenu();
        }else if(resp == 2){
            imprimir_ord(sergin_ord);
            resp2 = voltarMenu();
        }else if(resp == 3){
            alvo = buscaAno();
            busca = buscaBinaria(sergin_ord, 0, tam-1, alvo);
            
            if (busca == -1){
                printf("ANO nao existe!!!\n");
            }else{
                printf("TAXA: %.2f\n",sergin_ord[busca].taxa);
            }
            resp2 = voltarMenu();
        }else if(resp == 4){
            printf("O PROGRAMA ESTA SENDO ENCERRADO...");
            sleep(1);
            exit(1);
        }else{
            printf("ESCOLHA INVALIDA\n");
            printf("ESCOLHA UMA DAS OPCOES ACIMA!!!\n");
            sleep(2);
            system("cls");
            resp2 = 1;
        }

    } while (resp2 == 1);
    
    printf("O PROGRAMA ESTA SENDO ENCERRADO...");
    sleep(1);

    return 0;
}