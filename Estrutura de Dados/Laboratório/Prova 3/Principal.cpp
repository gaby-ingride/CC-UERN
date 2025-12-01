#include <iostream>
#include "Ordem.h"
#include <cstdlib> 

using namespace std;

int main() {

    Ordem obj;
    int opc, n;
    bool vetorGerado = false;

    do {
        system("cls"); // Limpa a tela (Windows)
        opc = obj.MenuOrdenar();

        switch (opc) {

        case 1:
            system("cls");
            cout << "Quantidade de elementos: ";
            cin >> n;
            obj.Entrada(n);  // AGORA GERA ALEATÓRIO
            cout << "Vetor gerado aleatoriamente:" << endl;
            obj.Saida(n);
            vetorGerado = true;
            break;

        case 2:
            system("cls");
            if (vetorGerado) {
                cout << "Vetor original (nao ordenado):" << endl;
                obj.Saida(n);
                cout << "\nOrdenando com Bubble Sort..." << endl;
                obj.Bubble(n);
                cout << "Vetor ordenado:" << endl;
                obj.Saida(n);
            } else {
                cout << "Erro: Gere um vetor primeiro (Opcao 1)!" << endl;
            }
            break;

        case 3:
            system("cls");
            if (vetorGerado) {
                cout << "Vetor original (nao ordenado):" << endl;
                obj.Saida(n);
                cout << "\nOrdenando com Insertion Sort..." << endl;
                obj.Insertion(n);
                cout << "Vetor ordenado:" << endl;
                obj.Saida(n);
            } else {
                cout << "Erro: Gere um vetor primeiro (Opcao 1)!" << endl;
            }
            break;

        case 4:
            system("cls");
            if (vetorGerado) {
                cout << "Vetor original (nao ordenado):" << endl;
                obj.Saida(n);
                cout << "\nOrdenando com Selection Sort..." << endl;
                obj.Selection(n);
                cout << "Vetor ordenado:" << endl;
                obj.Saida(n);
            } else {
                cout << "Erro: Gere um vetor primeiro (Opcao 1)!" << endl;
            }
            break;

        case 5:
            system("cls");
            if (vetorGerado) {
                cout << "Vetor original (nao ordenado):" << endl;
                obj.Saida(n);
                cout << "\nOrdenando com Merge Sort..." << endl;
                obj.Merge(0, n - 1);
                cout << "Vetor ordenado:" << endl;
                obj.Saida(n);
            } else {
                cout << "Erro: Gere um vetor primeiro (Opcao 1)!" << endl;
            }
            break;

        case 6:
            system("cls");
            if (vetorGerado) {
                cout << "Vetor original (nao ordenado):" << endl;
                obj.Saida(n);
                cout << "\nOrdenando com Quick Sort..." << endl;
                obj.Quick(0, n - 1);
                cout << "Vetor ordenado:" << endl;
                obj.Saida(n);
            } else {
                cout << "Erro: Gere um vetor primeiro (Opcao 1)!" << endl;
            }
            break;

        case 7:
            system("cls");
            cout << "Saindo..." << endl;
            break;

        default:
            system("cls");
            cout << "Opcao invalida!" << endl;
        }

        if (opc != 7) {
            cout << "\nPressione Enter para continuar...";
            cin.ignore();
            cin.get();
        }

    } while (opc != 7);

    return 0;
}
