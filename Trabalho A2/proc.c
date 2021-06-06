#include "header.h"
#include <stdio.h>

int buscaBinaria(economia_ord *vetdados, int inicio, int fim, int alvo){
    int meio;

    meio = (int)(inicio + fim) /2;

    if(alvo == vetdados[meio].ano){
        return meio;
    }

    if (inicio >= fim){
        return -1;
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

    printf("\n***********************\n");
    printf(" INICIADO COM SUCESSO!\n");
    printf("***********************\n");
    sleep(1);
    system("cls");
}

void imprimir(economia* vet){

    printf("ANO:  TAXA:\n");

    for(int ctd=0; ctd<tam; ctd++){
        printf("%d %.2f%% \n",vet[ctd].ano,vet[ctd].taxa);
    }
}

void imprimir_ord(economia_ord *vet){

    printf("ANO  TAXA\n");

    for(int ctd=0; ctd<tam; ctd++){
        printf("%d  %.2f\n",vet[ctd].ano,vet[ctd].taxa);
    }
}

int menu(){
    int resp;
    printf(" PROGRAMA SERGIN v1.0\n");
    printf("***********************\n");

    printf ("-> MENU <- \n");
    printf ("1 - IMPRIMIR DADOS NAO ORDENADOS\n");
    printf ("2 - IMPRIMIR DADOS ORDENADOS DE FORMA CRESCENTE\n");
    printf ("3 - BUSCAR DADOS\n");
    printf ("4 - ENCERRAR PROGRAMA\n");

    printf("-> ");
    scanf("%d",&resp);

    return resp;
}

int voltarMenu(){
    
    int resp2;
    
    printf("\nDESEJA VOLTAR AO MENU?\n1 - SIM\n2 - NAO\n");
    scanf("%d",&resp2);
    system("cls");

    return resp2;
}

int buscaAno(){
    
    int alvo;
    
    printf("\nINSIRA O ANO PELO QUAL DESEJA BUSCAR:\n");
    printf("-> ");
    scanf("%d", &alvo);

    return alvo;
}