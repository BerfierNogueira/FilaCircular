typedef struct Element{
  char data;
  struct Element * next;
}ElementLista;

typedef struct Queue{
  ElementLista * beginning;
  ElementLista * end;
  int size;
}Fila;

Fila * initialization ();

void insert(Fila * lista, char value);

ElementLista * createElement(char value);

void mostrarElementos(Fila * root);

void showElement(ElementLista * element, int i);

ElementLista * unqueue(Fila * queue);

void unqueueLiberate(Fila * queue);

void liberateQueue(Fila * queue);