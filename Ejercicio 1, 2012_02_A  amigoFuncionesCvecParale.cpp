#include <iostream>
#include <conio.h>
#include <string>

using namespace System;
using namespace std;

int pedirnumero(string mensaje)
{
	int numero;

	do {
		cout << mensaje;
		cin >> numero;
	} while (!(1 <= numero && numero <= 20));

	return (numero);

}

void GeneraryListas_Parelelo(char *vgripe, char *vtos, int *vpeso, int n)
{

	for (int i = 0; i < n; i++)
	{
		cout << "Alumno " << i + 1 << " : \n";

		do
		{
			cout << "Gripe (S o N): ";
			cin >> vgripe[i];
			vgripe[i] = toupper(vgripe[i]);
		} while (vgripe[i] != 'S' && vgripe[i] != 'N');

		do
		{
			cout << "Tos (S o N): ";
			cin >> vtos[i];
			vtos[i] = toupper(vtos[i]);
		} while (vtos[i] != 'S' && vtos[i] != 'N');

		do
		{
			cout << "Peso (de 30 a 60): ";
			cin >> vpeso[i];
		} while (!(30 <= vpeso[i] && vpeso[i] <= 60));
	}
}

void Porcentaje_gripo_tos(char *vgripe, char *vtos, int n)
{
	int contador = 0;
	float porcentaje;

	for (int i = 0; i < n; i++)
	{
		if ((vgripe[i] == 'S' || vgripe[i] == 'N') && (vtos[i] == 'S' || vtos[i] == 'N'))
			contador++;
	}


	porcentaje = (contador * 100) / n;


	cout << "Porcentaje de " << n << " alumnos(as) que tien gripe y tos : " << porcentaje << " % " << endl;
}

void Promedio_Peso(char *vgripe, char *vtos, int *vpeso, int n)
{

	int suma = 0;

	for (int i = 0; i < n; i++)
	{
		if ((vgripe[i] == 'S' || vgripe[i] == 'N') && (vtos[i] == 'S' || vtos[i] == 'N'))
			suma += vpeso[i];
	}

	cout << "Promedio de pesos de los alumnos con alguans enfermedades : " << suma / n;
}

void Listado_ordenado(char *vgripe, char *vtos, int *vpeso, int n)
{
	int aux;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; i++)
		{
			if (vpeso[i] < vpeso[j])
			{
				aux = vpeso[j];
				vpeso[j] = vpeso[i];
				vpeso[i] = aux;
			}
		}
	}

	cout << "Peso   Gripe   Tos ";

	for (int i = 0; i < n; i++)
	{
		cout << vpeso[i] << "  " << vgripe[i] << "  " << vtos[i] << endl;
	}
}

void main()
{
	int n;
	char *vgripe, *vtos;
	int *vpeso;

	n = pedirnumero("Ingrese el numero de alumnos: ");

	vgripe = new char[n];
	vtos = new char[n];
	vpeso = new int[n];

	GeneraryListas_Parelelo(vgripe, vtos, vpeso, n);
	Porcentaje_gripo_tos(vgripe, vtos, n);
	Promedio_Peso(vgripe, vtos, vpeso, n);
	Listado_ordenado(vgripe, vtos, vpeso, n);

	delete[] vgripe;
	delete[] vtos;
	delete[] vpeso;

	getch();
}

