#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

string returnRandomNumber(){

    string word [3] = {"Abacaxi" , "Morango", "Uva"};

    int randomIndex = rand() % 3;

    return word [randomIndex];
}

void playYourself(){

    string word = returnRandomNumber();
    cout << word;
    system("read -p 'Press Enter to continue...' var");
}

void homeMenu(){

    int option = 1;

    while (option > 0 && option < 3){
        
        
        system("clear");
        cout << "\n1- Play";
        cout << "\n2- About";
        cout << "\n3- Exit";
        cout << "\nChoose an option and press Enter:\n";
        cin >> option;

        switch (option)
        {
        case 1:
            
            playYourself();
            
            break;
        
        case 2:

            cout << "Game Information\n";
            break;

        case 3:

            cout << "See you!!\n";
            system("read -p 'Press Enter to Exit...' var");
            break;
        }

        
    }
}

int main (){

    srand((unsigned)time(NULL));

    homeMenu();

}