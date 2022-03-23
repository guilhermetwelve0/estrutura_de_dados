#include <stdio.h>
#include <stdlib.h>

typedef struct no{
     int valor;
     struct no *proximo;
}No;

No* inserir(No *inicio, int x){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x;
        novo->proximo = inicio;
    }
    return novo;
}

void inserir2(No **inicio, int x){
    No *novo = malloc(sizeof(No));
    if(novo){
        novo->valor = x;
        novo->proximo = *inicio;
        *inicio = novo;
    }
}

void imprimir(No *inicio){
  if(inicio){
    printf("%d", inicio->valor);
    imprimir(inicio->proximo);
  }
}

int main(){
 No *lista = NULL;

 lista = inserir(lista, 10);
 lista = inserir(lista, 50);
 lista = inserir(lista, 100);

 inserir2(&lista, 17);
 inserir2(&lista, 57);
 inserir2(&lista, 107);

 imprimir(lista);
 return 0;
}
/*
void descobrirValores(int *v, int *me, int *ma, int tam){
  int i;
  *me = v[0];
  *ma = v[0];

  for(i = 1; i < tam; i++){
    if(v[i] < *me)
      *me = v[i];
    if(v[i] > *ma)
      *ma = v[i];
  }
  printf("Na funcao: Menor: %d\tMaior: %d\n", *me, *ma);
  printf("Na funcao -> End de me: %p\tEnd de ma: %p\n", &me, &ma);
  printf("Na funcao -> Cont de me: %p\tCont de ma: %p\n", me, ma);
}

int main(){

 int valor = 10, menor, maior, vet[] = {50,10,250,500,25};
 int *p;

 p = &valor;

 printf("Valor: %d\tEndereco de valor: %p\n", valor, &valor);
 printf("Endereco de p: %p\n", &p);
 printf("Conteudo de p: %p\n", p);
 printf("Conteudo apontado por p: %d\n", *p);

 descobrirValores(vet, &menor, &maior, 5);
 printf("Em main: Menor: %d\tMaior: %d\n", menor, maior);
 printf("End de menor: %p\tEnd de maior: %p\n", &menor, &maior);
 return 0;
}
*/
