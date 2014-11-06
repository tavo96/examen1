// queue::push/pop
#include "Monstruo.h"
#include "Evaluador.h"
#include <iostream>
#include <list>
#include <fstream>
using namespace std;

//Escribe los datos del objeto monstruo (dado) en el archivo binario nombre_archivo (dado) en la posicion dada
//Nota: Se deben poder agregar varias mascotas en un solo archivo
void escribir(string nombre_archivo, Monstruo*monstruo, int posicion)
{
    ofstream out(nombre_archivo.c_str(),ios::in | ios::binary);
    out.seekp(posicion*33);
    out.write((char*)&monstruo->cabezas,4);
    out.write((char*)&monstruo->brazos,4);
    out.write((char*)&monstruo->piernas,4);
    out.write(monstruo->nombre.c_str(),10);
    out.write(monstruo->apodo.c_str(),10);
    out.write((char*)&monstruo->es_carnivoro,1);
    out.close();
}

//Devuelve un monstruo previamente escrita (con la funcion escribir()) en un archivo binario con nombre dado en la posicion dada
//Nota: Se deben poder leer varias mascotas de un solo archivo
Monstruo* leer(string nombre_archivo, int posicion)
{
    Monstruo *leer = new Monstruo(-1,-1,-1,"","",false);
    ifstream in(nombre_archivo.c_str());
    in.seekg(33*posicion);

    char nombre[10], apodo[10];
    int brazos, piernas, cabezas;
    bool es_carnivoro;


    in.read((char*)&cabezas,4);
    in.read((char*)&brazos,4);
    in.read((char*)&piernas,4);
    in.read(nombre,10);
    in.read(apodo,10);
    in.read((char*)&es_carnivoro,1);


    leer->nombre = nombre;
    leer->apodo = apodo;
    leer->brazos = brazos;
    leer->cabezas=cabezas;
    leer->piernas = piernas;
    leer->es_carnivoro= es_carnivoro;

    return leer;

}

//Devuelve el nombre del monstruo con mas cabezas previamente escrito (con la funcion escribir) en el archivo dado
string getMonstruoConMasCabezas(string nombre_archivo)
{
     return "";
}


int main ()
{
    //Funcion evaluadora
    evaluar();
    return 0;
}
