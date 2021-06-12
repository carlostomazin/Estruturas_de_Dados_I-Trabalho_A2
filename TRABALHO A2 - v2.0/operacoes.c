#include "header.h"
#include <stdio.h>
#include <conio.h> // Biblioteca de manipulação de caracteres
#include <windows.h> //Biblioteca para usar o Sleep e mais algumas funções do cmd
#include <time.h> // Biblioteca para pegar a hora atual

void iniciar(economia *vet, economia_ord *vet_ord){
    
    system("cls"); //função para limpar a tela

    system("color 3"); //função para mudar a cor da fonte do programa (3 = verde água)
    
    FILE *arqEnt; //declarando uma variavel do tipo FILE, para trabalhar com um arquivo txt
    
    arqEnt = fopen("economia.txt","r"); //usando a variavel "arqEnt" abrir um arquivo txt

    if (arqEnt == NULL){ //se arqEnt for igual a NULL quer dizer que o arquivo está vazio
        printf("Erro na abertura do arquivo\n"); //mostra uma mensagem se estiver vazio
        exit(0); //encerra o programa
    }

    for(ctd=0; ctd<tam ; ctd++){ //um for para ler o arquivo e armazenar nas variaves da struct economia
        fscanf(arqEnt,"%d %f",&vet[ctd].ano, &vet[ctd].taxa);
        vet_ord[ctd].ano = vet[ctd].ano;
        vet_ord[ctd].taxa = vet[ctd].taxa; //fazendo uma copia de uma struct para outra
    }

    quickSort(vet_ord, 0, tam-1); //ordenando os dados da struct economia_ord, usando quickSort

    inicializaLista(&inicioLista); //chama a função para inicar a lista 
    
    printf("\n");
    for(a=0;a<30;a++){ //faz uma animação de como se estivesse carregando o programa
        printf("*");
        Sleep(20);
    }
    printf("\nPROOGRAMA CARREGADO COM SUCESSO!\n");
    printf("*********************************\n\n");
    system("pause"); //pausa o programa e espera o usuario aperta alguma tecla para continuar
    system("cls"); //função para limpar a tela
}

void inicializaLista(No **lista){
    *lista = NULL; //faz com que a lista/inicio dela receba NULL (vazia)
}

int listaEhVazia(No *lista){
    if(lista == NULL){ //se a lista for igual a NULL quer dizer que é vazia...
        return 1; //assim retornando -1 se for correto a afirmação
    }
    return 0;
}

void insereInicio(No **lista, int ano, float taxa){
    No *novo; //cria uma variavel do tipo No
    hora(); //função para pegar a hora atual

    novo = (No *)malloc(sizeof(No)); //reservando espaço na memoria para a nova variavel
    novo->ano = ano; //recendo o ano
    novo->taxa = taxa; //recebendo a taxa
    novo->time_hora = data_hora_atual->tm_hour; //recebendo a hora atual
    novo->time_min = data_hora_atual->tm_min; //recebendo o minuto atual
    novo->time_sec = data_hora_atual->tm_sec; //recebendo o segundos atual

    if(listaEhVazia(*lista)){ //teste para ver se a lista está vazia, chamando a função "listaEhVazia"
        novo->proximo = NULL;
    }else{
        novo->proximo = *lista; //se não for vazia o proximo endereço de memoria do novo elemento vai receber a lista...
    }                           //assim adicionando um elemento no começo da lista 
    *lista = novo; //e o inicio agora vai ser o novo elemento
}

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

void imprimir(economia* vet){
    
    printf("\nANO\t  TAXA\t\tANO\t  TAXA\n");
    
    for(ctd=0; ctd<25; ctd++){ //imprimi os dados da struct economia /que é a struct que NÃO ESTÁ ORDENADA/ 
        printf("%d\t%5.2f %%\t\t",vet[ctd].ano,vet[ctd].taxa);
        printf("%d\t%5.2f %%\t\t\n",vet[ctd+25].ano,vet[ctd+25].taxa);
    }                         //o for indo até 25 para fazer duas colunas
    printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal! ");
}

void imprimir_ord(economia_ord *vet){

    printf("\nANO\t  TAXA\t\tANO\t  TAXA\n");

    for(ctd=0; ctd<25; ctd++){//imprimi os dados da struct economia /que é a struct que NÃO ESTÁ ORDENADA/ 
        printf("%d\t%5.2f %%\t\t",vet[ctd].ano,vet[ctd].taxa);
        printf("%d\t%5.2f %%\t\t\n",vet[ctd+25].ano,vet[ctd+25].taxa);
    }                        //o for indo até 25 para fazer duas colunas
    printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal! ");
}

void historico(No *lista){
	
	No *atual = lista; //criando um variavel do tipo No e fazendo ela receber a Lista
	
	if(listaEhVazia(lista)){ //teste para ver se a lista está vazia, chamando a função "listaEhVazia"
		printf("O historico esta vazia!!!\n");
        printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal! ");
		return;
	}

    printf("HISTORICO: \n\n");
	while(atual != NULL){ //um while para ir até o ultimo elemento da lista
        if(atual->taxa == -1){ //se taxa for igual a -1 ira aparecer uma mensagem de que o ano não existe na base de dados
            printf("%d:%d:%d  ", atual->time_hora, atual->time_min, atual->time_sec);//imprimindo a hora, minutos, segundos atuais
		    printf("Ano: %d - Nao existe na base de dados!\n\n", atual->ano); //imprimindo o ano e taxa
        }else{
            printf("%d:%d:%d  ", atual->time_hora, atual->time_min, atual->time_sec);//imprimindo a hora, minutos, segundos atuais
		    printf("Ano: %d - Taxa: %.2f\n\n", atual->ano, atual->taxa); //imprimindo o ano e taxa
        }
		atual = atual->proximo; //atribuição para rodar o while
	}
	printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal! ");
}

void menu(){

    opcao=0;
    b=2;
    co=0; //coluna 
    L=4; //linha
    L2=L;
    L3=L+4; //quantidade de linha 
    L4=L;

    system("cls");
    printf("Dica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal!");
    printf("\n\n\t>>> MENU PRINCIPAL <<<\n\n");
    
    gotoxy(co+4,L);     // co é a coluna de inicio do menu e L é a linha de inico do menu
    printf(" - IMPRIMIR DADOS NAO ORDENADOS");
    gotoxy(co+4,L+1);
    printf(" - IMPRIMIR DADOS ORDENADOS");
    gotoxy(co+4,L+2);
    printf(" - BUSCAR UM DADO");
    gotoxy(co+4,L+3);
    printf(" - HISTORICO");
    gotoxy(co+4,L+4);
    printf(" - ENCERRAR PROGRAMA");
}

void voltarMenu(){
    
    do{ //usa um do while para ver se a tecla esq foi pressionada
        if(kbhit){ //um if que usa o "kbhit", essa função verifica se alguma tecla foi pressionada
            a=getch(); //se sim a variavel a armazena essa tecla
        }
    }while(a != 27); //e faz uma verificação apartir do valor ASCII da tecla ESQ /ESQ = 27 na tebela ASCII/
}

void sairMenu(){
    
    system("cls"); 

    printf("Voce pediu para sair, fechando programa...");

    for(a=0;a<10;a++){ //faz uma animação de como se estivesse carregando o programa
        printf(".");
        Sleep(200);
    }
    printf("!\n\n");
	exit(0); //encerra o programa
}

void buscaAno(int alvo, economia_ord *vet){
    
    int result;
    
    printf("\nINSIRA O ANO PELO QUAL DESEJA BUSCAR:\n");
    printf("-> ");
    scanf("%d", &alvo); //pede para o usuario digitar um ano e esse ano será passado para a função buscaBinaria

    result = buscaBinaria(vet, 0, tam-1, alvo); //chama a função buscaBinaria para verificar se o ano tem uma taxa

    if (result == -1){ //se o ano pesquisado não tiver taxa a função ira retornar -1 e falar que o ano não existe
        insereInicio(&inicioLista, alvo, result);//chama a função insereInicio para armazenar o valor /mesmo não existindo o ano
        printf("ANO nao existe!!!\n");
        printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal! ");
    }else{ //se o ano existir ira chamar a função insereInicio para armazenar o ano e taxa
        insereInicio(&inicioLista, alvo, vet[result].taxa);
        printf("TAXA: %.2f\n",vet[result].taxa); //mostra o resultado na tela
        printf("\nDica: Precione a tecla ESQ a qualquer momento para voltar para o menu principal! ");
    }
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