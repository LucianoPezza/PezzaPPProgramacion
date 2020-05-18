#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 4

typedef struct
{
    int id;
    char procesador[25];
    char marca[25];
    int precio;
} eNotebook;

float aplicarDescuento(float );
void hardcodearNotbooks(eNotebook[], int);
void mostrarNotebook(eNotebook);
void mostrarNoteboocks(eNotebook [], int);
void ordenarNotebooksPorMarcayPrecio(eNotebook[], int);

int main()
{
    eNotebook unaNotebook[TAM];
    hardcodearNotbooks(unaNotebook, TAM);
    float precioConDescuentro;
    float resultado;
    int opcion;

printf("Ingrese una opcion: \n1.Ejerciocio 3(estructura ordenada por marca y precio)\n2.Ejerciocio 1 (aplicar descuento)");
scanf("%d", &opcion);
    switch(opcion)
    {
    case 1:
        system("cls");
        ordenarNotebooksPorMarcayPrecio(unaNotebook, TAM);
        mostrarNoteboocks(unaNotebook, TAM);
        break;
    case 2:
        system("cls");
        printf("Ingrese precio con descuento: ");
        scanf("%f", & precioConDescuentro);

        resultado = aplicarDescuento(precioConDescuentro);
        printf("El descuento de %.2f es: %.2f\n", precioConDescuentro ,resultado);
        system("pause");
        break;
    }
}

float aplicarDescuento(float precioProducto)
{
    float descuento = 5;
    float resultado;
    resultado = (precioProducto * descuento )/ 100;
    return resultado;

}
void hardcodearNotbooks(eNotebook lista[], int tam)
{
    int ids []= {1,2,3,4,5};
    char procesadores[][25] = {"i4 4500k","i5 7300k", "i6 5000k","17 5000k"};
    char marcas[][25] = {"AMD","INTEL"," AMD","INTEL "};
    int precios []= {10000, 22000,50000,70000};

    for(int i =0; i< tam; i++)
    {
        lista[i].id = ids[i];
        strcpy(lista[i].procesador,procesadores[i]);
        strcpy(lista[i].marca, marcas[i]);
        lista[i].precio = precios[i];
    }
}
void mostrarNotebook(eNotebook unaNotebook)
{
    printf("\n%d %10s %10s %10d", unaNotebook.id, unaNotebook.procesador, unaNotebook.marca, unaNotebook.precio);
}
void mostrarNoteboocks(eNotebook lista[], int tam)
{
    printf("%s %10s %10s %10s", "ID", "Procesadores", "Marcas","Precios");

    for(int i= 0; i<tam; i++)
    {
        mostrarNotebook(lista[i]);
    }
}
void ordenarNotebooksPorMarcayPrecio(eNotebook lista[], int tam)
{
    eNotebook aux;
    for(int i =0; i<tam-1; i++)
    {
        for(int j= i+1; j< tam; j++)
        {
            if(strcmp(lista[i].marca, lista[j].marca) > 0)
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j] = aux;
            }
            else if((strcmp(lista[i].marca, lista[j].marca) ==0) && (lista[i].precio > lista[j].precio))
            {
                aux = lista[i];
                lista[i] = lista[j];
                lista[j]= aux;
            }
        }
    }
}
