#include "header.h"
#include <stdio.h>
#include <conio.h> // Biblioteca de manipulação de caracteres
#include <windows.h> 

void buscaBinaria(economia_ord *vetdados, int inicio, int fim, int alvo){
    int meio;

    meio = (int)(inicio + fim) /2;

    if(alvo == vetdados[meio].ano){
        printf("TAXA: %.2f\n",vetdados[meio].taxa);
        return;
    }

    if (inicio >= fim){
        printf("ANO nao existe!!!\n");
        return;
    }
    
    if( alvo < vetdados[meio].ano){
        buscaBinaria(vetdados,inicio,meio-1,alvo);
    }else{
        buscaBinaria(vetdados,meio+1,fim,alvo);
    }

}

void quickSort(economia_ord *vetor, int esquerda, int direita){

    int i,j;
    int pivo;
    economia_ord aux;

    i = esquerda;
    j = direita;

    pivo = vetor[direita].ano;

    if((i == esquerda) && (j == direita)){
        while (i <= j){
            while ((vetor[i].ano < pivo) && (i < direita)){
                i++;
            }
            while ((vetor[j].ano > pivo) && (j > esquerda)){
                j--;
            }
            if(i <= j){
                aux = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = aux;
                i++;
                j--;
            }
        }
    }
    if(j > esquerda)
        quickSort(vetor, esquerda, j);
    if(i < direita)
        quickSort(vetor, i, direita);
}

void iniciar(economia *vet, economia_ord *vet_ord){
    
    system("cls");

    system("color 3");
    
    FILE *arqEnt;
    
    arqEnt = fopen("economia.txt","r");

    if (arqEnt == NULL){
        printf("Erro na abertura do arquivo\n");
        exit(0);
    }

    for(int ctd=0; ctd<tam ; ctd++){
        fscanf(arqEnt,"%d %f",&vet[ctd].ano, &vet[ctd].taxa);
        vet_ord[ctd].ano = vet[ctd].ano;
        vet_ord[ctd].taxa = vet[ctd].taxa;
    }

    quickSort(vet_ord, 0, tam-1);

    printf("\n");
    for(a=0;a<30;a++){
        printf("*");
        Sleep(50);
    }
    printf("\nPROOGRAMA CARREGADO COM SUCESSO!\n");
    printf("*********************************\n\n");
    system("pause");
    system("cls");
}

void imprimir(economia* vet){
    
    printf("\nANO\t  TAXA\t\tANO\t  TAXA\n");
    
    for(int ctd=0; ctd<25; ctd++){
        printf("%d\t%5.2f %%\t\t",vet[ctd].ano,vet[ctd].taxa);
        printf("%d\t%5.2f %%\t\t\n",vet[ctd+25].ano,vet[ctd+25].taxa);
    }
}

void imprimir_ord(economia_ord *vet){

    printf("\nANO\t  TAXA\t\tANO\t  TAXA\n");

    for(int ctd=0; ctd<25; ctd++){
        printf("%d\t%5.2f %%\t\t",vet[ctd].ano,vet[ctd].taxa);
        printf("%d\t%5.2f %%\t\t\n",vet[ctd+25].ano,vet[ctd+25].taxa);
    }

}

void menu(){

    opcao=0;
    b=2;
    co=0;
    L=4;
    L2=L;
    L3=L+3;
    L4=L;

    system("cls");
    printf("Dica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");
    printf("\n\n\t>>> MENU PRINCIPAL <<<\n\n");
    
    gotoxy(co+4,L);     // co é a coluna de inicio do menu e L é a linha de inico do menu
    printf("1 - IMPRIMIR DADOS NAO ORDENADOS");
    gotoxy(co+4,L+1);
    printf("2 - IMPRIMIR DADOS ORDENADOS");
    gotoxy(co+4,L+2);
    printf("3 - BUSCAR UM DADO");
    gotoxy(co+4,L+3);
    printf("4 - ENCERRAR PROGRAMA");

}

void voltarMenu(){
    
    do{
        if(kbhit){a=getch();}
    }while(a != 27);
}

void sairMenu(){
    
    system("cls");

    printf("Voce pediu para sair, fechando programa...");

    for(a=0;a<10;a++){
        printf(".");
        Sleep(200);
    }
    printf("!\n\n");
	exit(1);
}

void buscaAno(int alvo, economia_ord *vet){
    
    printf("\nINSIRA O ANO PELO QUAL DESEJA BUSCAR:\n");
    printf("-> ");
    scanf("%d", &alvo);

    buscaBinaria(vet, 0, tam-1, alvo);
}

void funcaoSetas(){
    
    do{                       /*loop para movimentar a seta*/
        gotoxy(co+2,L);       /*gotoxy posiciona o cursor, o co é a coluna e L é a linha onde imprimir a seta*/
        printf("-%c",16);     /*imprime a seta*/
        gotoxy(0,8);         /*posiciona o cursor fora da tela para ele não ficar piscando*/
        if(kbhit){a=getch();} /*se alguma tecla foi pressionada a igual a tecla*/
        if(a == 80){          /*80 é valor do cactere seta p/baixo do teclado*/
            L2=L;             /*L2 é posição onde estava a seta para apagar senao fica duas setas*/
            L++;              /*L aponta para a nova posição da seta*/
            if(L>L3){L=L4;}   /*L vai de 2 ate 5 pois é onde estão as 4 opções, mudando mude tambem os valores*/
        }                     /*a seta estando no 4 e for movida p/baixo ela vai para a primeira opção*/
        if(a == 72){          /*72 é valor do cactere seta p/cima do teclado*/
            L2=L;             /*L2 é onde estava a seta para apagar*/
            L--;              /*L aponta para a nova posição da seta*/
            if(L<L4){L=L3;}   /*a seta estando no 1 e for movida p/cima ela vai para a ultima opção*/
            }
        if(L!=L2){            /*se a seta for movida */
            gotoxy(co+2,L2);  /*posicione o cursor onde estava a seta*/
            printf("  ");     /*imprime espaços em branco(que sao pretos) em cima da seta para apaga-la*/
            L2=L;             /*L2 igual a nova posição da seta*/
        }
        if(a == 13){          /*se a tecla enter for pressionada*/
            opcao=L-(L4-1);        /*opcao igual a linha onde esta a opção menos um, pois a primeira opção */
                                  /*esta na linha 2*/
        }
    }while(opcao == 0);       /*repete enquanto opcao igual a zero*/
}
