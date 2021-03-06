#ifndef LISTA_H

#define LISTA_H

#include <windows.h> 

#define tam 50

typedef struct _econ{
    int ano;
    float taxa;
}economia; //struct dos dados não ordenados

typedef struct _econ_ord{
    int ano;
    float taxa;
}economia_ord; //struct dos dados ordenados

typedef struct _no{
    int ano;
    float taxa;
    int time_sec;
    int time_min;
    int time_hora;
    struct _lista *proximo;
}No; //struct para a Lista 

typedef struct _tm {
    int tm_sec; //representa os segundos de 0 a 59
    int tm_min; //representa os minutos de 0 a 59
    int tm_hour; //representa as horas de 0 a 24
}tm; //struct para armazenar a hora atual

int a,b,L,L2; // Declaração das váriaveis das setas
int co,L3,L4; // Declarações do menu
int opcao, alvo, ctd;
economia sergin[tam];
economia_ord sergin_ordenado[tam];
No *inicioLista;  
struct tm *data_hora_atual; //ponteiro para struct que armazena data e hora

void iniciar(economia*, economia_ord*);
void inicializaLista(No **);
void insereInicio(No**, int, float);

void imprimir(economia*);
void imprimir_ord(economia_ord*);
void historico(No *);
void hora();

void quickSort(economia_ord*, int, int);

int buscaBinaria(economia_ord*, int, int, int);
void buscaAno(int, economia_ord *);

void menu();
void voltarMenu();
void sairMenu();

void funcaoSetas();
void gotoxy(int x,int y){ //função para trabalhar com posição de elementos na tela **NÃO RECOMENDADO USAR**
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

#endif