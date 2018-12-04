#include <stdio.h>
#include "Queue.h"
#include <string.h>
#include "locale.h"

int main(void) {
  setlocale(LC_ALL, "Portuguese");

  Fila * fila = initialization();

  char * name = "Gabriel ";
  int i, max = strlen(name);

  for(i = 0; i<max; i++){
    printf("\nInserindo a letra %c na fila", name[i]);
    insert(fila, name[i]);
  }
  mostrarElementos(fila);
  liberateQueue(fila);
  //Liberando o ponteiro

  /*for(i = 0; i < 5; i++){
    unqueueLiberate(fila);
  }

  //Retornando valores ainda restantes na fila

  for(i = 0; i < 5; i++){
    ElementLista * el = unqueue(fila);
    if(el == NULL){
        printf("\nAcabou..."); continue;
    }
    printf("\nValor retirado: %c", el->data);
  }

  */

  return 0;

}
