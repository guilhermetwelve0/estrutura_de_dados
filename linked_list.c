#include<stdlib.h>
#include<stdio.h>

typedef struct Node{
int data;
struct Node *next;
}Node;

typedef struct List{
int size;
Node *head;
}List;

void initList(List *l){
l->head = NULL;
l->size = 0;
}

int isEmpty(List *l){
return(l->head == NULL);
}

void insertFront(List *l,int value){
Node *newNode = (Node *)malloc(sizeof(Node));
if(newNode != NULL){
l->size++;
if(isEmpty(l)){
//inserts new node to empty list
newNode->data =value;
newNode->next = NULL;
l->head = newNode;
}else{
//inserts new node to the front of existing list
newNode->data = value;
newNode->next = l->head;
l->head = newNode;
}
}
}

void insertEnd(List *l, int value){
Node *newNode = (Node *)malloc(sizeof(Node));
if(newNode != NULL){
l->size++;
if(isEmpty(l)){
	//inserts new node to empty list
	newNode->data = value;
	newNode->next = NULL;
	l->head = newNode;
}else {
	Node *ptr = l->head; // Iniciando o ponteiro
	//lista atual tranversal até que o pointeiro ache o fim da lista.
	while(ptr->next != NULL){
		ptr = ptr->next;
	}
	newNode->data = value;
	newNode->next = NULL;
	ptr->next=newNode; // conecta o novo nó a lista inserindo no final
     }
   }
}

//Deletando o primeiro no da lista
void deleteFront(List *l){
	if(!isEmpty(l)){ // Determina se a lista não esta vazia
		Node *ptr = l->head;
		l->head = l->head->next; //Atualizar a cabeça do ponteiro para o proximo ponteiro
		free(ptr);
		l->size--;
	}
}

//Deletando o ultimo no da lista
void deleteEnd(List *l){
	if(!isEmpty(l)){ //Determina se a lista não esta vazia
	//Incializa ponteiros para iterar a lista
	Node *nextNode = l->head->next;
	Node *currentNode = l->head;
	//Iterage atraves da lista ate que nextNode->next equals NULL
	while(nextNode->next != NULL){
		currentNode = nextNode;
		nextNode = nextNode->next;
	}
	currentNode->next = NULL; //separa o utimo no da lista
	free(nextNode); //  lista com memoria alocada para nó excluido
	l->size--;
   }
}

//inserindo no em uma posicao desejada.Exemplo:inserir no na localizacao(lista, 3, 5) precisa criar a no com dados com valor de 5
//e registrar o no criado como o terceiro da lista
void insertNodeAtLocation(List *l, int location, int value){
	if(location > l->size+1 || location < 1){ //determina se a localizacao e valida
		printf("Invalid Location\n");
	}else{
		if(location == 1){ //Se a localizacao 1, inserir no na frente da lista
			insertFront(l, value);
		}else{
			int currentNodeLocation = 1;
			l->size++;
			Node *ptr = l->head; //Inicializa ponteiros para iterializar fins
			Node *newNode = (Node *)malloc(sizeof(Node)); // Aloca memoria para o novo no
			newNode->data = value;
			//Iterage lista ate que a localizao da lista+1
			//igual ate a localizao desejada
			while(currentNodeLocation+1 != location){
				ptr = ptr->next;
				currentNodeLocation++;
			}
			//conecta a novo no para a lista
			newNode->next = ptr->next;
			ptr->next = newNode;
		}
	}
}

//Remove primeiro no contendo especifico valor
void removeNode(List *l, int value){
	if(!isEmpty(l)){ //Determina se a lista nao e vazia
	//Inicializa o novoatual e o nodeanterior dos ponteiros
	Node *currentNode = l->head;
	Node *prevNode = NULL;
	if(currentNode->data == value){ // Determina se o primeiro no tem um valor
		deleteFront(l);
	} else{
		//Atualizar o noanteior e o noatual dos ponteiros
		prevNode = currentNode;
		currentNode = currentNode->next;
		while(currentNode!=NULL){ // iNTERAGE ATRAVES DA LISTA QUE O NO ATUAL SEJA NULO
			if(currentNode->data == value){ //Detrmina se o no atual tem um valor
				//Deletado no da lista
				prevNode->next = currentNode->next;
				free(currentNode); // Desalocando espaco de memoria
				l->size--;
				return; //Terminacao da funcao
			}
		// Atualizando ponteiros para iterar através da lista
		prevNode = currentNode;
		currentNode = currentNode->next;
		}
		printf("Valor nao encontrado na lista\n");
	    }		
	}
}

//Pronta o valor de todos os dados de todos os dados
void printLinkedList(List *l){
	//Inicializa o ponteiro usado para iteracao atraves da lista
	Node *ptr = l ->head;
	if(ptr == NULL){
		printf("A lista esta vazia\n");
	}else{
		printf("A lista encadeada tem %d nos \n", l->size);
		printf("Lista Encadeada: ");
	//Iteracao atraves da amostragem de todos os valores de dados de todos os nos
	while(ptr != NULL){
		printf("%d   ",  ptr->data);
		ptr = ptr->next;
	   }
	}
	printf("\n\n");
}

void main(){
	List linkedList;
	printf("Lista encadeada demonstracao\n\n");
	// Inicializando a lista
	initList(&linkedList);
	//Inserindo no na frente
	insertFront(&linkedList,5);
	insertFront(&linkedList,3);
	insertFront(&linkedList,1);
	//Inserindo no no fim
	insertEnd(&linkedList, 9);
	insertEnd(&linkedList, 21);
	//Mostrado a lista
	printf("Estado atual da lista:\n");
	printLinkedList(&linkedList);
	//Inserindo no em uma localizacao desejada
	printf("Inserindo valor: 7 na localizacao 3\n");
	insertNodeAtLocation(&linkedList, 3, 7);
	//Mostrando a lista
	printf("Atual estado da lista:\n");
	printLinkedList(&linkedList);
	//Deletando no com um valor especifico
	printf("Deletado o valor 5\n");
	removeNode(&linkedList, 5);
	//Mostrando a lista
	printf("Atual estado da lista:\n");
	printLinkedList(&linkedList);
	//Deletado o ultimo no
	printf("Deletado o ultimo no\n");
	deleteEnd(&linkedList);
	//Mostrado o valor
	printf("Atual estado da lista:\n");
	printLinkedList(&linkedList);
	//Deletando o primeiro no
	printf("Deletando o primeiro no\n");
	deleteFront(&linkedList);
	//Mostrado o valor
	printf("Atual estado da lista:\n");
	printLinkedList(&linkedList);
}