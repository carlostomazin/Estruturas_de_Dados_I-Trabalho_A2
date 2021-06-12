#include "header.h"
#include <stdio.h>
#include <conio.h> // Biblioteca de manipulação de caracteres
#include <windows.h>
#include <time.h> // Biblioteca para pegar a hora atual

void inicializaLista(No **lista){
    *lista = NULL;
}

int listaEhVazia(No *lista){
    if(lista == NULL){
        return 1;
    }
    return 0;
}

void insereInicio(No **lista, int ano, float taxa){
    No *novo;
    hora(); //função para pegar a hora atual

    novo = (No *)malloc(sizeof(No));
    novo->ano = ano;
    novo->taxa = taxa;
    novo->time_hora = data_hora_atual->tm_hour; //recebendo a hora atual
    novo->time_min = data_hora_atual->tm_min; //recebendo o minuto atual
    novo->time_sec = data_hora_atual->tm_sec; //recebendo o segundos atual

    if(listaEhVazia(*lista)){
        novo->proximo = NULL;
    }else{
        novo->proximo = *lista;
    }
    *lista = novo;
}

void buscaBinaria(economia_ord *vetdados, int inicio, int fim, int alvo){
    int meio;

    meio = (int)(inicio + fim) /2;

    if(alvo == vetdados[meio].ano){
        insereInicio(&inicioLista, alvo, vetdados[meio].taxa);
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

    inicializaLista(&inicioLista);
    

    printf("\n");
    for(a=0;a<30;a++){
        printf("*");
        Sleep(20);
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
    printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");
}

void imprimir_ord(economia_ord *vet){

    printf("\nANO\t  TAXA\t\tANO\t  TAXA\n");

    for(int ctd=0; ctd<25; ctd++){
        printf("%d\t%5.2f %%\t\t",vet[ctd].ano,vet[ctd].taxa);
        printf("%d\t%5.2f %%\t\t\n",vet[ctd+25].ano,vet[ctd+25].taxa);
    }
    printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");
}

void historico(No *lista){
	
	No *atual = lista;
	
	if(listaEhVazia(lista)){
		printf("O historico esta vazia!!!\n");
		return;
	}

    printf("HISTORICO: \n\n");
	while(atual != NULL){
        printf("%d:%d:%d", atual->time_hora, atual->time_min, atual->time_sec);//hora//minutos//segundos
		printf("\t- Ano: %d Taxa: %.2f\n\n", atual->ano, atual->taxa);
		atual = atual->proximo;
	}
	printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");
}

void menu(){

    opcao=0;
    b=2;
    co=0; // coluna 
    L=4; // linha
    L2=L;
    L3=L+4;
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
    printf("4 - HISTORICO");
    gotoxy(co+4,L+4);
    printf("5 - ENCERRAR PROGRAMA");
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
        gotoxy(0,10);         /*posiciona o cursor fora da tela para ele não ficar piscando*/
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

void hora(){

    //variável do tipo time_t para armazenar o tempo em segundos  
    time_t segundos;
  
    //obtendo o tempo em segundos  
    time(&segundos);

    data_hora_atual = localtime(&segundos);
}