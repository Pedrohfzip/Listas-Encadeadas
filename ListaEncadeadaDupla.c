#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{

struct Elemento* previous;
struct Elemento* next;
int dado;

}Elemento;

typedef struct Lista{

struct Elemento* head;
struct Elemento* tail;
int size;

}Lista;


Lista* criaLista();
Elemento* criaElemento(int);
void insereElemento(Lista*,Elemento*,Elemento*);
void removeElemento(Lista*,Elemento*);
void mostrarLista(Lista*);
Elemento* encontrarElemento(Lista*,int);


int main(){
Lista* lista = criaLista();


    insereElemento(lista,lista->head,10);
    insereElemento(lista,lista->head,20);
    insereElemento(lista,lista->tail,30);
    mostrarLista(lista);
    removeElemento(lista,lista->head);
    printf("\n");
    mostrarLista(lista);


}

Lista* criaLista(){

    Lista* lista=(Lista*)malloc(sizeof(Lista));

    lista->head = NULL;
    lista->tail = NULL;
    lista->size = 0;

    return lista;
}
Elemento* criaElemento(int dado){

    Elemento* novo = (Elemento*)malloc(sizeof(Elemento));

    novo->next = NULL;
    novo->dado = dado;

    return novo;
}

void insereElemento(Lista* lista, Elemento* pivo,Elemento* dado){

    Elemento* novo_elemento = criaElemento(dado);

        if(pivo == NULL && lista->size != 0){
            printf("[ERRO]->{Na primeira insercao, so eh valido pivo NULL}");
        }

        if(lista->size == 0){
            lista->head = novo_elemento;
            lista->tail = novo_elemento;
        }else{
            novo_elemento->next = pivo->next;
            novo_elemento->previous = pivo;

                if(pivo->next==NULL){
                    lista->tail=novo_elemento;
                }else{
                    pivo->next->previous = novo_elemento;
                }

            pivo->next = novo_elemento;
        }

    lista->size++;
}

void removeElemento(Lista* lista,Elemento* pivo){

Elemento* antigo;



    if(pivo != NULL && lista->size != 0){
        if(pivo == lista->head){
            lista->head = pivo->next;
                if(lista->head == NULL){
                    lista->head == NULL;
                }else{
                    pivo->next->previous = NULL;
                }
        }else{
            pivo->previous->next = pivo->next;
            if(pivo->next == NULL){
                lista->tail = pivo->previous;
            }else{
                pivo->next->previous = pivo->previous;
            }
        }
        free(pivo);
        lista->size--;
    }
}




Elemento* encontrarElemento(Lista* lista,int dado){
//
}


void mostrarLista(Lista* lista){

Elemento* aux = lista->head;

        if(lista->size == 0){
                printf("Lista Vazia");
        }else{

            while(aux != NULL){
            printf("%i,", aux->dado);
            aux = aux->next;
            }
        }

    }
