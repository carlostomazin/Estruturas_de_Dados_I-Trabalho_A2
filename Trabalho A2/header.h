#ifndef LISTA_H

#define LISTA_H

#define tam 50

typedef struct _econ{
    int ano;
    float taxa;
}economia;

typedef struct _econ_ord{
    int ano;
    float taxa;
}economia_ord;

void iniciar(economia*, economia_ord*);
void imprimir(economia*);
void imprimir_ord(economia_ord*);
void quickSort(economia_ord*, int, int);
int buscaBinaria(economia_ord*, int, int, int);
int menu();
int voltarMenu();
int buscaAno();

#endif