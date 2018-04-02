#include <stdio.h>
int busquedaBinaria(int arreglo[], int min, int max, int buscado);
void ordenarnumeros(int numero[], int larg);

int main(void){

    int largo;

    printf("Introduzca la cantidad de elementos del arreglo \n");
    scanf(" %i", &largo);

    int arreglo[largo];

    for(int i=0; i<largo; i++){
        int numero;
        printf("introduzca un numero:\n ");
        scanf(" %i", &numero);
        arreglo[i]=numero;
        printf("\n");
    }
    ordenarnumeros(arreglo, largo);

    printf("Que numero buscas?\n");
    int buscado;
    scanf(" %i",&buscado);

    int encontrado=busquedaBinaria(arreglo,0,largo-1,buscado);
    if(encontrado<0){
        printf("El numero no se encuentra\n");
        return 0;
    }
    printf("el numero esta en la posicion: %i", encontrado);
    //le saqué el +1 suponiendo que la primera posicion es 0
}

void ordenarnumeros(int numero[], int larg){
    int aux;
    for(int i=0; i<larg; i++){

        for(int j=i+1; j<larg; j++){

            if(numero[i] > numero[j]){

                aux = numero[i];
                numero[i] = numero[j];
                numero[j] = aux;

            }
        }
    }


}


int busquedaBinaria(int arreglo[], int min, int max, int buscado){
    int posActual;

    if(min>max)
        return -1;

    posActual= min + (max-min)/2;

    if(arreglo[posActual]==buscado)
        return posActual;

    if(arreglo[posActual]<buscado) //si el buscado es mayor
        return  busquedaBinaria(arreglo, posActual+1, max, buscado);

    if(arreglo[posActual]>buscado) //si el buscado es menor
        return busquedaBinaria(arreglo,min,posActual-1,buscado);

    //return 0;
}