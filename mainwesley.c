#include <stdio.h>
#include <stdlib.h>
#include "FilaCircularDinamica.h"

typedef struct node{
    int num;
    Node *prox;
} Node;

typedef struct fila{
    Node* prim;
    Node* ultm;
} Fila;

Fila* criaFila(){

    Fila* f = (Fila*) malloc(sizeof(Fila));

    if(f!=NULL){

        f->prim = NULL;
        f->ultm = NULL;

        return f;
    }

    printf("\nMemoria Insuficiente!\n\n");
    exit(1);
}

int filaVazia(Fila * f){

    if(f->ultm == NULL){
        return 1;
    }

    return 0;

}

void insereNo(Fila* f, Node novo){

    Node* no = (Node*) malloc(sizeof(Node));
    no->num = novo.num;

    int vazia = filaVazia(f);

    if(vazia == 1){
        f->prim = no;
        f->ultm = no;
        no->prox = f->prim;
    }else{

        f->ultm->prox = no;
        f->ultm = no;
        no->prox = f->prim;
    }

    //printf("\n\nEnd : %d\n",no);
    //printf("\nEnd : %d\n\n",no->prox);

}

void imprimiFila(Fila * f){

        Node* atual = f->prim;
        Node* primeiro = f->prim;

        printf("\n\n[ ");

        do{

            printf("%d ",atual->num);
            atual = atual->prox;

        }while(atual!=primeiro);

        printf(" ]\n\n");
}

void liberaElemento(Fila* f){


    Node* atual = f->prim;

    if(atual->prox==atual){

        free(atual);
        free(f->prim);
        free(f->ultm);
        f->prim = NULL;
        f->ultm = NULL;
        return;

    }

    Node* proximo = f->prim->prox;
    f->prim = proximo;
    free(atual);

    f->ultm->prox = proximo;

}


void liberaFila(Fila* f){

     Node* atual = f->prim;
     Node* primeiro = f->prim;

    Node* proximo;

    do{
        proximo = atual;
        atual = atual->prox;
        free(proximo);

    }while(atual!=primeiro);

    free(f);

    f->prim = NULL;
    f->ultm = NULL;

}

int buscaElemento(Fila* f, Node no){

    int pos = 0;

    Node* atual = f->prim;
    Node* primeiro = f->prim;

        do{

            if(atual->num == no.num){
                return pos;
            }

            atual = atual->prox;
            pos++;

        }while(atual!=primeiro);


    return -1;
}


int main(){


    int op,vazia,cheia,tamanho,busca;
    Fila* f = criaFila();
    Node no;

    do{

        printf("1 - Insere No\n");
        printf("2 - Imprimi Fila\n");
        printf("3 - Remover No\n");
        printf("4 - Esvazia Fila\n");
        printf("5 - Buscar Elemento na Fila\n");
        printf("0 - Sair\n");
        scanf("%d",&op);

        switch(op){

        case 0:
            break;

        case 1:

            printf("Digite um numero: ");
            scanf("%d",&no.num);

            insereNo(f,no);

            break;

        case 2:

            vazia = filaVazia(f);

            if(vazia == 1){
                printf("\nFila vazia\n\n");
            }else{
                imprimiFila(f);
            }


            break;

             case 3:

            vazia = filaVazia(f);

            if(vazia == 1){
                printf("\nFila vazia\n\n");
            }else{
                liberaElemento(f);
            }


            break;

            case 4:

            vazia = filaVazia(f);

            if(vazia == 1){
                printf("\nFila vazia\n\n");
            }else{
                liberaFila(f);
                printf("\nFila Esvaziada com Sucesoo\n\n");
            }


            break;

            case 5:

            vazia = filaVazia(f);

            if(vazia == 1){
                printf("\nFila vazia\n\n");
            }else{

                Node no;
                printf("Digite um valor para Busca:");
                scanf("%d",&no.num);

                busca = buscaElemento(f,no);

                if(busca == -1){
                    printf("\nElemento nao Encontrado!\n\n");
                }else{
                    printf("\nElemento encontrado na posicao: %d\n\n",busca);
                }


            }


            break;

        }

    }while(op!=0);


    return 0;
}
	
	
	
