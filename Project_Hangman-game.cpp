#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;



void menuInicial(){

    int opcao = 1;

    while (opcao > 0 && opcao < 3){
        
        
        system("clear");
        cout << "\n1- Play";
        cout << "\n2- About";
        cout << "\n3- Exit";
        cout << "\nChoose an option and press Enter:\n";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            
            cout << "Play\n";
            break;
        
        case 2:

            cout << "Game Information\n";
            break;

        case 3:

            cout << "See you!!\n";
            break;
        }

        system("read -p 'Press Enter to continue...' var");
    }
}

int main (){

    menuInicial();

}