#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <time.h>

using namespace std;

string wordWithMask(int wordSize){
    
    int cont = 0;
    string wordMask;
    int Size = wordSize;

    while(cont < Size){

        wordMask += "_";
        cont++;
    }

    return wordMask;
}

string returnRandomNumber(){

    string word [3] = {"abacaxi" , "morango", "uva"};

    int randomIndex = rand() % 3;

    return word [randomIndex];
}

void playYourself(){

    string word = returnRandomNumber();
    int WordSize = word.size();
    string mask = wordWithMask (WordSize);
    int cont , res;
    

    int attempts = 0,remainingAttempts = 10;
    char letter;

    while( word != mask && (remainingAttempts - attempts) > 0){

        cout << "\nWord Size: " << WordSize << " Word: " << mask << "\n";
        cout << "You have " << remainingAttempts - attempts << " Remaining Attempts \n\n";

        cout << "Type a letter:\n";
        cin >> letter;

        for(cont = 0;cont < WordSize;cont++){

            if(word[cont] == letter){
                mask[cont] = word[cont];
            }
        }

        attempts++;
    }

    if(word == mask){
        cout << "\nCongratulations, you is very good!!!!\n\n";
        cout << "The word is: " << word << "\n\n";
        
    }else{
        cout << "Oh no, try again!\n";
    }

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