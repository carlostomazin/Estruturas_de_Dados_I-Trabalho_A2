#ifndef LISTA_H

#define LISTA_H

#include <windows.h> 

#define tam 50

typedef struct _econ{
    int ano;
    float taxa;
}economia;

typedef struct _econ_ord{
    int ano;
    float taxa;
}economia_ord;

int a,b,L,L2; // Declaração das váriaveis das setas
int co,L3,L4; // Declarações do menu
int opcao, alvo;
economia sergin[tam];
economia_ord sergin_ordenado[tam];

void iniciar(economia*, economia_ord*);
void imprimir(economia*);
void imprimir_ord(economia_ord*);
void quickSort(economia_ord*, int, int);
void buscaBinaria(economia_ord*, int, int, int);
void menu();
void voltarMenu();
void sairMenu();
void buscaAno(int, economia_ord *);
void funcaoSetas();
void gotoxy(int x,int y){
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}

#endif