#include <stdio.h>
#include <stdlib.h>

struct nodo {
	int info;
	struct nodo *sig;
};

struct nodo *raiz=NULL;

void insertar(int x){
	struct nodo *nuevo;
	nuevo = malloc(sizeof(struct nodo));
	nuevo -> info = x;
	if(raiz == NULL){
		raiz =nuevo;
		nuevo -> sig =NULL;
	}else {
		nuevo->sig=raiz;
		raiz=nuevo;
	}
}
void imprimir (){
	struct nodo *reco=raiz;
	printf("Lista completa.\n");
	while (reco!=NULL){
		printf("%i\n ",reco->info);
		reco=reco->sig;
	}
	printf("\n");
}
int extraer(){
	if (raiz !=NULL){
		int informacion = raiz ->info;
		struct nodo *bor = raiz;
		raiz = raiz ->sig;
		free(bor);
		return informacion;
	}else {
		return -1;
	}
}
void liberar(){
	struct nodo *reco = raiz;
	struct nodo *bor;
	while(reco!=NULL){
		bor=reco;
		reco=reco->sig;
		free(bor);
	}
}
int contar(){
	int contador=0;
	struct nodo *cont =raiz;
	while(cont!=NULL){
	cont=cont->sig;
	contador++;
	}
	return contador;

}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	insertar(10);
	insertar(10);
	insertar(3);
	if(contar()==0){
	printf("La pila esta vacia\n");
	}else{
	printf("Hay %i nodos en la pila\n",contar());
	}
	
	imprimir();
	printf("Extraemos de la pila: %i \n",extraer());
	if(contar()==0){
	printf("La pila esta vacia\n");
	}else{
	printf("Hay %i nodos en la pila\n",contar());
	}
	imprimir();
	printf("Extraemos de la pila: %i \n",extraer());
	if(contar()==0){
	printf("La pila esta vacia\n");
	}else{
	printf("Hay %i nodos en la pila\n",contar());
	}
	printf("Extraemos de la pila: %i \n",extraer());
	if(contar()==0){
	printf("La pila esta vacia\n");
	}else{
	printf("Hay %i nodos en la pila\n",contar());
	}
	liberar();
	return 0;
}
