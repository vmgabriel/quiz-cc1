// Hecho por: Gabriel Vargas Monroy

#include <stdio.h>
#include <iostream>
#include <cstdlib>

//----------------------------
//Parte LIB
//---------------------------

class Arreglo
{
    int tam;
    int * elem;
	
public:
    Arreglo(int);

    void operator=(Arreglo);
    void mostrar();
    void cargarman();
    void cargarpc();
    void clonar(Arreglo);
    int burbuja();
    int insercion();

    int gettam();

    void setval(int,int);
};

Arreglo::Arreglo(int tam)
{
    this->tam=tam;
    elem = new int[tam];
}

void Arreglo::cargarpc()
{
    int num=0;
    for (int i=0;i<tam;i++)
    {
	num=1+rand()%500;
	elem[i]=num;
    }
}

void Arreglo::cargarman()
{
    int temp;
    for(int i=0;i<tam;i++)
    {
	temp=0;
	std::cout<<"Ingrese elemento "<<i+1<<": ";
	std::cin>>temp;
	elem[i]=temp;
    }
}

int Arreglo::burbuja()
{
    int i, j, aux , op=0;
    for (i=0;i<tam-1;i++)
    {
	for (j=i+1;j<tam;j++)
	{
	    op++;
	    if (elem[i]>elem[j])
	    {
		aux=elem[i];
		elem[i]=elem[j];
		elem[j]=aux;
	    }
	}
    }
    return op;
}

void Arreglo::operator = (Arreglo A)
{
    this->tam=A.tam;
    for (int k=0;k<tam;k++)
    {
	elem[k]=A.elem[k];
    }
}

int Arreglo::insercion()
{
    int op=0,aux,a=0;;
    for (int i=0;i<tam;i++)
    {
	aux=elem[i];
	a=i-1;
	op++;
	while (a>=0 && elem[a]>aux)
	{
	    elem[a+1]=elem[a];
	    a--;
	    op++;
	}
	elem[a+1]=aux;
    }
    return op;
}

void Arreglo::mostrar()
{
    std::cout<<"[ ";
    for(int i=0;i<tam;i++)
    {
	std::cout<<elem[i]<<", ";
    }
    std::cout<<" ]"<<std::endl;
}

int Arreglo::gettam(){return tam;}

void Arreglo::setval(int pos,int val){this->elem[pos] = val;}

//-------------------------------
//Parte CLI
//-------------------------------

void inicio()
{
    std::cout<<"-------------------"<<std::endl;
    std::cout<<" Bienvenido a programa  multiopcion"<<std::endl;
    std::cout<<"-------------------"<<std::endl;
}

void fin()
{
    std::cout<<"-------------------"<<std::endl;
    std::cout<<"Gracias por usar el programa,hecho por: Gabriel Vargas Monroy"<<std::endl;
    std::cout<<"-------------------"<<std::endl;
}

void menubusq(Arreglo B)
{
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"Menu de Opciones de busqueda"<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"(s)ecuencial"<<std::endl;
    std::cout<<"binaria (i)terativa"<<std::endl;
    std::cout<<"binaria (r)ecursiva"<<std::endl;
    std::cout<<"(r)egresar"<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    char a;
    std::cout<<"Ingrese una opcion: ";
    std::cin>>a;
}

void menuord(Arreglo B)
{
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"Menu de Opciones de ordenamiento"<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    std::cout<<"(b)urbuja"<<std::endl;
    std::cout<<"(i)nsercion"<<std::endl;
    std::cout<<"(s)hell"<<std::endl;
    std::cout<<"(q)uick sort"<<std::endl;
    std::cout<<"(m)erge sort"<<std::endl;
    std::cout<<"(c)ubetas"<<std::endl;
    std::cout<<"(a)tras"<<std::endl;
    std::cout<<"------------------------"<<std::endl;
    char a;
    std::cout<<"Ingrese una opcion: ";
    std::cin>>a;
    int ope=0;
    Arreglo modi=B;
  
    switch(a)
    {
    case('b'):
    {
	ope=modi.burbuja();
	std::cout<<"Ordenado con metodo de burbuja Correctamente"<<std::endl;
	std::cout<<"------------------------"<<std::endl;
    }
    break;
    case('i'):
    {
	ope=modi.insercion();
	std::cout<<"Ordenado con metodo de insercion Correctamente"<<std::endl;
	std::cout<<"------------------------"<<std::endl;
    }
    break;
    case('s'):
    {
    }
    break;
    case('q'):
    {
    }
    break;
    case('m'):
    {
    }
    break;
    case('c'):
    {
    }
    break;
    }
    std::cout<<"Arreglo ordenado"<<std::endl;
    B.mostrar();
    std::cout<<"Numero de operaciones: "<<ope<<std::endl;
    std::cout<<"------------------------"<<std::endl;
}

void menu()
{
    Arreglo A(0);
    bool bandera=true;
    while(bandera)
    {
	std::cout<<"------------------------"<<std::endl;
	std::cout<<"Menu de Opciones del sistema"<<std::endl;
	std::cout<<"------------------------"<<std::endl;
	std::cout<<"(c)argar"<<std::endl;
	std::cout<<"(m)ostrar"<<std::endl;
	std::cout<<"(b)uscar"<<std::endl;
	std::cout<<"(o)rdenar"<<std::endl;
	std::cout<<"(t)erminar"<<std::endl;
	std::cout<<"------------------------"<<std::endl;
	char a;
	std::cout<<"Ingrese una opcion: ";
	std::cin>>a;
	std::cout<<"------------------------"<<std::endl;
    
	switch(a)
	{
	case('c'):
	{
	    int cant=0;
	    std::cout<<"Ingrese la cantidad de numeros del arreglo: ";
	    std::cin>>cant;
	    A=Arreglo(cant);
	    if (a<30)
	    {
		A.cargarman();
	    }
	    else
	    {
		A.cargarpc();
	    }
	    std::cout<<"Hecho Correctamente"<<std::endl;
	}
	break;
	case('m'):
	{
	    if (A.gettam() > 0)
	    {
		A.mostrar();
	    }
	    else
	    {
		std::cout<<"Aun no se ha cargado"<<std::endl;
	    }
	}
	break;
	case('b'):
	{
	    menubusq(A);
	}
	break;
	case('o'):
	{
	    std::cout<<"Arreglo sin Ordenar"<<std::endl;
	    A.mostrar();
	    menuord(A);
	}
	break;
	case('t'):
	{
	    fin();
	    bandera=false;
	}
	break;
	}
    }
}

int main()
{
    inicio();
    menu();
    return 0;
}
