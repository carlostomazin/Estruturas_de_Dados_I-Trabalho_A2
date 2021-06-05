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

    do{
        printf(" PROGRAMA SERGIN v1.0\n");
        printf("***********************\n");

        menu();
        printf("-> ");
        scanf("%d",&resp);

        if(resp == 1){
            imprimir(sergin);
        }else if(resp == 2){
            imprimir_ord(sergin_ord);
        }else if(resp == 3){
            printf("INSIRA O ANO PELO QUAL DESEJA BUSCAR:\n");
            printf("-> ");
            scanf("%d", &alvo);
            busca = buscaBinaria(sergin_ord, 0, tam-1, alvo);
            
            if (busca == -1){
                printf("RA nao existe!!!");
            }else{
                printf("ANO: %d\nTAXA: %.2f\n", sergin_ord[busca].ano, sergin_ord[busca].taxa);
            }
        }else if(resp == 4){
            printf("O PROGRAMA ESTA SENDO ENCERRADO...");
            sleep(1);
            break;
        }else{
            printf("ESCOLHA INVALIDA\n");
            printf("ESCOLHA UMA DAS OPCOES ACIMA!!!\n");
            system("cls");
            menu();
            printf("-> ");
            scanf("%d",&resp);
        }

        printf("\nDESEJA VOLTAR AO MENU?\n1 - SIM\n2 - NAO\n");
        scanf("%d",&resp2);
        system("cls");
    } while (resp2 == 1);
    
    printf("O PROGRAMA ESTA SENDO ENCERRADO...");
    sleep(1);

    return 0;
}