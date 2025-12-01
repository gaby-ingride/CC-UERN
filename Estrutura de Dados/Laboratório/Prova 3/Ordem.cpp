#include "Ordem.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono>

using namespace std;

Ordem::Ordem() {
    tam = 0;
    Lista = NULL;
}

Ordem::~Ordem() {
    if (Lista != NULL)
        delete[] Lista;
}

void Ordem::Aleatorio(int n) {
    if (Lista != NULL) delete[] Lista;

    tam = n;
    Lista = new int[tam];

    srand(time(NULL)); // semente aleatória

    for (int i = 0; i < tam; i++) {
        Lista[i] = rand() % 1000; // valores entre 0 e 999
    }

    cout << "Vetor gerado automaticamente!" << endl;
}

void Ordem::Entrada(int n) {
    Aleatorio(n);
}

void Ordem::Saida(int n) {
    for (int i = 0; i < tam; i++)
        cout << Lista[i] << " ";

    cout << endl;
}

void Ordem::Bubble(int n) {
	
    for (int i = 0; i < tam - 1; i++) {
        for (int j = 0; j < tam - 1 - i; j++) {
            if (Lista[j] > Lista[j + 1]) {
                int aux = Lista[j];
                Lista[j] = Lista[j + 1];
                Lista[j + 1] = aux;
            }
        }
    }
}

void Ordem::Insertion(int n) {
	
    for (int i = 1; i < tam; i++) {
        int key = Lista[i];
        int j = i - 1;

        while (j >= 0 && Lista[j] > key) {
            Lista[j + 1] = Lista[j];
            j--;
        }
        Lista[j + 1] = key;
    }
}

void Ordem::Selection(int n) {
	
    for (int i = 0; i < tam - 1; i++) {
        int menor = i;

        for (int j = i + 1; j < tam; j++)
            if (Lista[j] < Lista[menor])
                menor = j;

        int aux = Lista[i];
        Lista[i] = Lista[menor];
        Lista[menor] = aux;
    }
}

void Ordem::Intercala(int p, int q, int r) {
    int n1 = q - p + 1;
    int n2 = r - q;

    int *E = new int[n1];
    int *D = new int[n2];

    for (int i = 0; i < n1; i++)
        E[i] = Lista[p + i];

    for (int j = 0; j < n2; j++)
        D[j] = Lista[q + 1 + j];

    int i = 0, j = 0, k = p;

    while (i < n1 && j < n2) {
        if (E[i] <= D[j]) Lista[k++] = E[i++];
        else Lista[k++] = D[j++];
    }

    while (i < n1) Lista[k++] = E[i++];
    while (j < n2) Lista[k++] = D[j++];

    delete[] E;
    delete[] D;
}

void Ordem::Merge(int p, int r) {	
    if (p < r) {
        int q = (p + r) / 2;
        Merge(p, q);
        Merge(q + 1, r);
        Intercala(p, q, r);
    }
}

int Ordem::Separa(int p, int r) {
    int x = Lista[r];
    int i = p - 1;

    for (int j = p; j < r; j++) {
        if (Lista[j] <= x) {
            i++;
            int aux = Lista[i];
            Lista[i] = Lista[j];
            Lista[j] = aux;
        }
    }

    int aux = Lista[i + 1];
    Lista[i + 1] = Lista[r];
    Lista[r] = aux;

    return i + 1;
}

void Ordem::Quick(int p, int r) {
	if (p < r) {
        int q = Separa(p, r);
        Quick(p, q - 1);
        Quick(q + 1, r);
    }
}

int Ordem::MenuOrdenar() {
    system("cls");
    cout << "==============================" << endl;
    cout << "== ESCOLHA UMA OPCAO NO MENU LISTA ==" << endl;
    cout << "==============================" << endl;
    cout << "[1] GERAR VETOR ALEATORIO" << endl;
    cout << "[2] ORDENACAO BUBBLESORT" << endl;
    cout << "[3] ORDENACAO INSERTIONSORT" << endl;
    cout << "[4] ORDENACAO SELECTIONSORT" << endl;
    cout << "[5] ORDENACAO MERGESORT" << endl;
    cout << "[6] ORDENACAO QUICKSORT" << endl;
    cout << "[7] SAIR DO PROGRAMA" << endl;
    cout << "OPCAO ESCOLHIDA: ";

    int op;
    cin >> op;
    return op;
}
