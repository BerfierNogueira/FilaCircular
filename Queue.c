#include "Queue.h"
#include "stdlib.h"
#include "stdio.h"
#include "locale.h"

Fila * initialization (){
  Fila * lista;
  lista = (Fila *) malloc(sizeof(Fila));
  if(lista == NULL)
  return NULL;
  lista->beginning = NULL;
  lista->end = NULL;
  lista->size = 0;
  return lista;
}

void insert(Fila * lista, char value){
  ElementLista * elem = createElement(value);
  if(lista->beginning == NULL && lista->end == NULL){
    lista->beginning = elem; lista->end = elem; lista->size++;
    return;
  }
  ElementLista * elfirst = lista->beginning;
  while(elfirst->next != NULL){
    elfirst = elfirst->next;
  }
  elfirst->next = elem;
  lista->end = elem;
  lista->size++;
  printf("Elemento inserido %c com sucesso", lista->end->data);
}

ElementLista * createElement(char value){
  ElementLista * elem = (ElementLista *) malloc(sizeof(ElementLista));
    elem->data = value; elem->next = NULL;
    if(elem == NULL) {printf("\nErro durante alocação de recursos"); return NULL;}
    return elem;
}

void mostrarElementos(Fila * root){
    ElementLista * element = root->beginning;
    showElement(element, 1);
}

void showElement(ElementLista * element, int i){
    if(element == NULL){
        printf("\nNenhum elemento resta");
        return;
    }
    printf("\nValor no membro %d: %c",i, element->data);
    showElement(element->next, ++i);
}

ElementLista * unqueue(Fila * queue){

    ElementLista * selected = queue->beginning;
    if(queue->beginning == NULL || queue->end == NULL){
        printf("\nNao ha elementos para retirar");
        return NULL;
    }
    else if(queue->beginning == queue->end){
        printf("\nRemovido o filho único\n");
        queue->beginning = NULL;
        queue->end = NULL;
        return selected;
        queue->size--;
    }
    queue->beginning = selected->next;
    return selected;
}

void unqueueLiberate(Fila * queue){
  ElementLista * el = unqueue(queue);
  printf("\nRemovendo e liberando o valor %c", el->data);
  free(el);
}

void liberateQueue(Fila * queue){
  ElementLista * el;
  while(el != NULL){
    el = unqueue(queue);
    free(el);
  } 
  free(queue);
  printf(". Todos os elementos foram removidos");
}