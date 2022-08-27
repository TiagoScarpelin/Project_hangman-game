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

void displayStatus(int wordSize,string mask,int attempts,string riskyletters,string message){

    int cont = 0;

    cout << message << "\n";
    cout << "\nWord Size: " << wordSize << " Word: " << mask << "\n";
    cout << "You have " << attempts << " Remaining Attempts \n\n";
    cout << "Risky letters: ";

    for(cont = 0;cont < riskyletters.size();cont++){
            
        cout << riskyletters[cont] << ",";

    }

}

string returnRandomNumber(){

    string word [3] = {"abacaxi" , "morango", "uva"};

    int randomIndex = rand() % 3;

    return word [randomIndex];
}

void playYourself(){

    string word = returnRandomNumber();
    int wordSize = word.size();
    string mask = wordWithMask (wordSize);
    int cont = 0;
    string riskyletters;
    string message = "Welcome to the game!";
    bool repeatedLetter = false ,correctLetter = false;

    int attempts = 0,remainingAttempts = 10;
    char letter;

    while( word != mask && (remainingAttempts - attempts) > 0){

        system ("clear");

        correctLetter = false;
        repeatedLetter = false;

        displayStatus(wordSize,mask,remainingAttempts - attempts,riskyletters,message);

        cout << "\n\nType a letter:\n";
        cin >> letter;

        for(cont = 0;cont < attempts;cont++){
            if(riskyletters[cont] == letter){
                repeatedLetter = true;
            }
        }

        if(repeatedLetter == true){

            message = "Ops, repeated letter!!";

        }else{

           riskyletters += letter;

           for(cont = 0;cont < wordSize;cont++){

                if(word[cont] == letter){
                    mask[cont] = word[cont];
                    correctLetter = true;
                }
            }

            if(correctLetter == true){
                message = "Nice (^-^)";
            }else{
                message = "Oou, you missed (;-;)"; 
            }

            attempts++;
        }

    }

    if(word == mask){
        system("clear");
        cout << "\nCongratulations, you is very good!!!!\n\n";
        cout << "The word is: " << word << "\n\n";
        
    }else{
        system("clear");
        cout << "Oh no, try again!\n";
    }
    
    system("read -p 'Press enter to return to home menu...' var");
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
            system ("clear");
            playYourself();
            
            break;
        
        case 2:
            system ("clear");
            cout << "Game Information\n";
            system("read -p 'Press enter to return to home menu...' var");
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