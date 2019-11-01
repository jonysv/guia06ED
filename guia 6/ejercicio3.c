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
		printf("%i\n",reco->info);
		reco=reco->sig;
	}
	printf("\n");
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
void reemplazar(struct nodo *rem,int nuevo, int viejo){
	int ex=0;

	while (rem!=NULL){
		if(rem->info==viejo){
			ex++;
			printf("se encontro uno viejo, ha sido reemplazado\n");
			rem->info=nuevo;
		}
		rem=rem->sig;
	}
	printf("\n");
	if(ex<1){
		printf("no se encontro nada\n");
	}
}
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	insertar(10);
	insertar(8);
	insertar(3);
	if(contar()==0){
	printf("La pila esta vacia\n");
	}else{
	printf("Hay %i nodos en la pila\n",contar());
	}
	imprimir();
	struct nodo *reco=raiz;
	int x,y;
	printf("escriba el numero que quiere buscar\n");
	scanf("%d",&x);
	printf("escriba el valor que reemplazara\n");
	scanf("%d",&y);
	reemplazar(reco,y,x);
	imprimir();
	liberar();
	return 0;
}
