 typedef struct node Node;
typedef struct fila Fila;

Fila* criaFila();
void insereNo(Fila* f, Node no);
void imprimiFila(Fila * f);
int filaVazia(Fila * f);
int filaCheia(Fila* f);
void liberaElemento(Fila* f);
void liberaFila(Fila* f);
int buscaElemento(Fila* f, Node no);
