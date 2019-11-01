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
	printf("\nNumero Invertido.\n");
	while (reco!=NULL){
		printf("%i",reco->info);
		reco=reco->sig;
	}
	printf("\n");
}
int multiplo(int z){
	if(z<10){
		return 1;
	}else{
		return 10*multiplo(z/10);
	}
}
int invertir(int x){
	if(x<10){
	insertar(x);
	return 0;
	}else{
	int y=multiplo(x);
	int n=x/y;
	insertar(n);
	return invertir(x-(y*n));
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
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int numero;
	printf("Ingrese un numero\n");
	scanf("%d",&numero);
	invertir(numero);
	imprimir();
	liberar();
	return 0;
}
