// EF_2012_2_Pregunta1.cpp : main project file.

#include "stdafx.h"
#include <iostream>
#include "conio.h"
#include "windows.h"

using namespace System;
using namespace std;

void GenerayLista_paralelos(char Vg[], char Vt[],
	int Vp[], int N)
{
	Random f;
	int aux;
	for (int i = 0; i<N; i++)
	{
		aux = f.Next(0, 2);
		if (aux == 0) Vg[i] = 'S';
		else Vg[i] = 'N';

		aux = f.Next(0, 2);
		if (aux == 0) Vt[i] = 'S';
		else Vt[i] = 'N';

		Vp[i] = f.Next(30, 61);
	}

}

void Porcentaje_gripe_tos(char Vg[], char Vt[], int N)
{
	int cont = 0;
	for (int i = 0; i<N; i++)
		if (Vg[i] == 'S' && Vt[i] == 'S')
			cont++;
	cout << "Porcentaje es : " << cont*100.0 / N;
}

void Promedio_pesos(char Vg[], char Vt[],
	int Vp[], int N)
{
	int suma = 0;
	int cont = 0;
	for (int i = 0; i<N; i++)
		if (Vg[i] == 'S' || Vt[i] == 'S')
		{
			cont++;
			suma = suma + Vp[i];
		}
	cout << "Promedio pesos es : " << suma*1.0 / cont;
}

void Listado_ordenado(char Vg[], char Vt[],
	int Vp[], int N)
{
	char aux1; int aux2;
	for (int i = 0; i<N - 1; i++)
		for (int j = i + 1; j<N; j++)
			if (Vp[i]<Vp[j])
			{
				aux1 = Vg[i];
				Vg[i] = Vg[j];
				Vg[j] = aux1;

				aux1 = Vt[i];
				Vt[i] = Vt[j];
				Vt[j] = aux1;

				aux2 = Vp[i];
				Vp[i] = Vp[j];
				Vp[j] = aux2;
			}

	for (int i = 0; i<N - 1; i++)
		cout << Vg[i] << " " << Vt[i] << " " << Vp[i] << endl;
}

int main()
{
	int N;
	do {
		cout << "Ingrese N:";
		cin >> N;
	} while (N <= 0 || N>20);
	char * Vgripe = new char[N];
	char * Vtos = new char[N];
	int * Vpesos = new int[N];
	GenerayLista_paralelos(Vgripe, Vtos, Vpesos, N);
	Porcentaje_gripe_tos(Vgripe, Vtos, N);
	Promedio_pesos(Vgripe, Vtos, Vpesos, N);
	Listado_ordenado(Vgripe, Vtos, Vpesos, N);
	_getch();
	return 0;
}
