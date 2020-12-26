#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;
using namespace System;


int numalumnossalon()
{
	int n;
	do
	{
		cout << "ingrese numero de alumnos salon <20; "; cin >> n;
	} while (n > 20);
	return n;
}

void generarlistadevectores(int n, char gripe[], char tos[], int peso[],int alumnos[])
{
	Random r;
	int aux;
	for (int i = 0; i < n; i++)
	{
		aux = r.Next(0, 2);
		if (aux == 0)gripe[i] = 'S'; else gripe[i] = 'N';

		aux = r.Next(0, 2);
		if (aux == 0)tos[i] = 'S'; else tos[i] = 'N';

		peso[i] = r.Next(0, 31);
		alumnos[i] = i + 1;
	}//salida de datos
	cout << "alumno" << "\t" << "c/gripe" << "\t" << " c/tos" << "\t" << "peso" << endl;
	for (int i = 0; i < n; i++)
		cout << alumnos[i] << "\t" << gripe[i] << "\t" << tos[i] << "\t" << peso[i] << endl;
}


void Porcentaje_gripe_tos(int n, char gripe[], char tos[])
{
	float contador = 0; float porcentaje;
	for (int i = 0; i < n; i++)
		if (gripe[i] == 'S' && tos[i] == 'S')
			contador++;
	porcentaje = (contador / n);
	cout << "%  con gripe y tos a la vez sobre el total:" << porcentaje * 100 << "%" << endl;
}


void Promedio_pesos_enfermos(int n, char gripe[], char tos[], int peso[])
{
	float sumapeso = 0, promedio; int contador = 0;
	for (int i = 0; i < n; i++)
	{
		if (gripe[i] == 'S' || tos[i] == 'S') {
			contador++; sumapeso += peso[i];
		}
	}
	promedio = (sumapeso) / n;
	cout << "promedio de pesos ( enfermos):" << promedio << endl;
}

void listado_ordenado_descendete_xpeso(int n, char gripe[], char tos[], int peso[], int alumnos[])
{
	cout << "ordenados descendentemente" << endl;
	cout << "alumno" << "\t" << "c/gripe" << "\t" << " c/tos" << "\t" << "peso" << endl;
	int i;
	int temppeso, tempalum, tempgripe, temptos, tempalumnos;
	for (int i = 0; i < n-1; i++)
		for (int j = i + 1; j < n; j++)
			if (peso[i] < peso[j])
			{
				temppeso = peso[i];
				peso[i] = peso[j];
				peso[j] = temppeso;
				tempgripe = gripe[i];
				gripe[i] = gripe[j];
				gripe[j] = tempgripe;
				temptos = tos[i];
				tos[i] = tos[j];
				tos [j] = temptos;
				tempalumnos = alumnos[i];
				alumnos[i]=alumnos[j];
				alumnos[j] = tempalumnos;

/*
				tempalum = i;
				i = j;
				j = tempalum;*/
			}//salida de datos ordenados en funcion del peso
	for (int k = 0; k < n; k++)
	cout <<alumnos[k] << "\t" << gripe[k] << "\t" << tos[k] << "\t" << peso[k] << endl;
	
		

}



int main()
{
	int n = numalumnossalon();
	char*gripe = new char[n];
	char*tos = new char[n];
	int*peso = new int[n];
	int*alumnos = new int[n];
	generarlistadevectores(n, gripe, tos, peso, alumnos);
	Porcentaje_gripe_tos(n, gripe, tos);
	Promedio_pesos_enfermos(n, gripe, tos, peso);
	listado_ordenado_descendete_xpeso(n, gripe, tos, peso, alumnos);
	delete []gripe ;
	delete []tos ;
	delete []peso ;
	delete []alumnos ;
	
	_getch();


}

