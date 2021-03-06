#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int conteudo;
	struct no *esquerda, *direita;
}No;

typedef struct{
   No *raiz;
}ArvB;

void inserirEsquerda(No *no, int valor){
	if(no->esquerda == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		no->esquerda = novo;
	}
	else{
		if(valor < no->esquerda->conteudo)
		  inserirEsquerda();
	}
}

void inserirDireita(No *no, int valor){
	
}
void inserir(ArvB *arv, int valor){
	if(arv->raiz == NULL){
		No *novo = (No*)malloc(sizeof(No));
		novo->conteudo = valor;
		novo->esquerda = NULL;
		novo->direita = NULL;
		arv->raiz = novo;
	}
	else{
		if(valor < arv->raiz->conteudo)
		   inserirEsquerda(arv->raiz, valor);
		else
		   inserirDireita((arv->raiz, valor);
	}
}

int main(){
	
}