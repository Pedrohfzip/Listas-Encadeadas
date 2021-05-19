#include <stdio.h>
#include <stdlib.h>

typedef struct Elemento{


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

    insereElemento(lista,NULL,10);
    insereElemento(lista,lista->head,20);
    insereElemento(lista,lista->tail,30);
    insereElemento(lista,lista->tail,40);
    insereElemento(lista,lista->tail,50);
    insereElemento(lista,lista->tail,60);
    mostrarLista(lista);
    encontrarElemento(lista,10);





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

        if(pivo == NULL){
            if(lista->size == 0){
                    lista->tail = novo_elemento;
                }


                novo_elemento->next = lista->head;
                lista->head = novo_elemento;

            }else{
                if(pivo->next==NULL){
                    lista->tail = novo_elemento;
                    novo_elemento->next = pivo->next;
                    pivo->next = novo_elemento;
                }
            }
    lista->size++;
}

void removeElemento(Lista* lista,Elemento* pivo){

Elemento* antigo;


    if(lista->size == 0){
        printf("Lista Vazia");

    }

    if(pivo == NULL){
        antigo = lista->head;
        lista->head=lista->head->next;
            if(lista->head == NULL){
                lista->tail = NULL;
            }

    }else{

            if(pivo->next==NULL){
            printf("Erro final da lista");

            }

            antigo = pivo->next;
            pivo->next = antigo->next;

            if(pivo->next==NULL){
                lista->tail=pivo;
            }

        }

        free(antigo);
        lista->size--;

    }

Elemento* encontrarElemento(Lista* lista,int dado){
Elemento* aux = lista->head;
int cont = 0;

    while(aux->next!=NULL){
        if(aux->dado == dado){
            printf("\nPosicao %i: Elemento encontrado -> %i", cont,aux->dado);

        }else{
            printf("\nPosicao %i: Nenhum elemento foi encontrado", cont);
        }
         aux = aux->next;
         cont++;
    }

}


void mostrarLista(Lista* lista){

Elemento* aux = lista->head;

        while(aux != NULL){
            printf("%i,", aux->dado);
            aux = aux->next;
        }
    }

