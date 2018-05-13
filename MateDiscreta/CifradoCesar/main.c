#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

void encriptar();
void desencriptar();

int main(void){
    char c;
    system("color 0B");

    do
    {
        //imprimir instrucciones
        printf("\nMENU\n\n"
                       "1 - Encrypt message\n"
                       "2 - Decrypt message\n"
                       "0 - Exit\n");
        // obtener una opción
        printf("Choose an option:");

        scanf(" %c",&c);

        // Ejecutar la opción
        switch (c)
        {
            case '1': encriptar(); break;
            case '2': desencriptar(); break;
            case '0': break;
            default: printf("Try again\n"); break;
        }
    }
    while (c != '0');
}


void encriptar()
{
    int error=0;
    char texto2[MAX];
    int largo=0;
    do {
        error=0;
        printf("\nEnter text to encrypt\n");
        char texto[MAX];
        scanf(" %[^\t\n]",texto); //preguntar al usuario, lo guarda en array texto
        printf("Enter shift value:\n");
        int llave;
        scanf(" %i",&llave);

        if(llave>=26 || llave<=-26){
            do{
                printf("Shift value out of range\n");
                scanf(" %i",&llave);
            }while(llave>26 || llave<-26);
        }

        largo = strlen(texto); //define largo como el largo del array texto
        for(int k=0;k<largo;k++)//encriptar
        {
            int encriptar=((int)texto[k]);//toma una letra, typecastea a numero (ascii)

            if(encriptar>96 && encriptar<123)//si entre a-z
            {
                encriptar=encriptar+llave;

                while(encriptar>122 || encriptar < 97) //si al sumar me salgo del limite, hago ciclico
                { //TODO : cambiarlo por mod 26
                    if(llave>=0)
                        encriptar=(encriptar-26);
                    if(llave<0)
                        encriptar=(encriptar+26);
                }

            }
            else if(encriptar > 64 && encriptar < 91)//si entre A-Z
            {
                encriptar = encriptar + llave;
                while (encriptar > 90 || encriptar <65) { //si al sumar me salgo del limite, hago ciclico
                    //TODO : cambiarlo por mod 26
                    if(llave>=0)
                        encriptar = (encriptar - 26);
                    if(llave<0)
                        encriptar= (encriptar+26);
                }
            }
            else if(encriptar==32){ //si hay algun espacio, no hacer nada
                ;
            }
            else{ //si hay caracter -> error
                printf("Character invalid, '%c' in position %d\n",texto[k],k+1);
                error=1;
            }
            if(encriptar!=32){ //si no es un espacio, cambia minuscula a mayuscula
                if(!(encriptar>64 && encriptar <91)){
                    encriptar=encriptar-32;//la cambia a mayuscula
                }
            }
            texto2[k]=(char)encriptar; //guarda la letra en un array texto2, typecasteado a letra nuevamente
        }
    } while (error==1); //si hay error, preguntar denuevo

    printf("Your message encrypted: ");
    for(int k=0;k<largo;k++){
        if(texto2[k]!=32) //imprime el texto, ignora el espacio (32)
            printf("%c",texto2[k]);
    }

    printf("\n\n");
}

void desencriptar() {
    int error=0;
    char texto2[MAX];
    int largo=0;
    do {
        error=0;
        printf("\nEnter text to decrypt:\n");
        char texto[MAX];
        scanf(" %[^\t\n]",texto); //lee lo escrito en teclado, guarda en array texto
        printf("Enter shift value:\n");
        int llave;
        scanf(" %i",&llave);
        if(llave>=26 || llave<=-26){
            do{
                printf("Shift value out of range\n");
                scanf(" %i",&llave);
            }while(llave>26 || llave<-26);
        }

        largo = strlen(texto);
        printf("\n\n");
        for (int k = 0; k < largo; k++)//encriptar
        {
            int encriptar = ((int) texto[k]);//toma una letra, typecastea a numero (ascii)

            if (encriptar > 64 && encriptar < 91)//si entre A-Z
            {
                encriptar = encriptar - llave;

                while (encriptar > 90 || encriptar < 65) { //si al restar me salgo del limite, hago ciclico
                    //TODO : cambiarlo por mod
                    if(llave>=0)
                        encriptar = (encriptar + 26);
                    if(llave<0)
                        encriptar = (encriptar-26);
                }
            }
            else if(encriptar>96 && encriptar<123)//si entre a-z
            {
                encriptar=encriptar-llave;

                while(encriptar>122 || encriptar<97) //si al restar me salgo del limite, hago ciclico
                {
                    //TODO : cambiarlo por mod
                    if(llave>=0)
                        encriptar=(encriptar+26);
                    if(llave<0)
                        encriptar=(encriptar-26);
                }

            }
            else if(encriptar==32){ //si hay un espacio -> error
                printf("Character invalid, in position %d text cant have blank spaces\n",k+1);
                error=1;
            }
            else{ //si hay caracter -> error
                printf("Character invalid, '%c' in position %d\n",texto[k],k+1);
                error=1;
            }

            if(!(encriptar>64 && encriptar <91)){
                encriptar=encriptar-32;//la cambia a mayuscula
            }

            texto2[k]=(char)encriptar;
        }
    } while (error==1);

    printf("Your message decrypted: ");
    for(int k=0;k<largo;k++){ //imprime el texto desencriptado
        printf("%c",texto2[k]);
    }
    printf("\n\n");
}