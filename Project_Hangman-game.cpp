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
    cout << "\n(Word Size "<< wordSize << ") " <<" Word: " << mask << "\n";
    cout << "You have " << attempts << " Remaining Attempts \n\n";
    cout << "Risky letters: ";

    for(cont = 0;cont < riskyletters.size();cont++){
            
        cout << riskyletters[cont] << ",";

    }

}

string returnRandomNumber(){

    string word [3] = {"abacaxi" , "morango", "melancia"};

    int randomIndex = rand() % 3;

    return word [randomIndex];
}

void playYourself(){

    string word = returnRandomNumber();
    int wordSize = word.size();
    string mask = wordWithMask (wordSize);
    int cont = 0;
    string compare;
    char option;
    string riskyletters;
    string message = "Welcome to the game!";
    bool repeatedLetter = false ,correctLetter = false;
    int contador = 0;

    int attempts = 0,remainingAttempts = 10;
    char letter;

    while( word != mask && (remainingAttempts - attempts) > 0){

        system ("clear");

        correctLetter = false;
        repeatedLetter = false;

        displayStatus(wordSize,mask,remainingAttempts - attempts,riskyletters,message);
        cout << "\n\nPress 1 to risk the word";

        cout << "\n\nType a letter:\n";
        cin >> letter;


        if(letter == '1'){

            system("clear");
            message = " ";
            displayStatus(wordSize,mask,attempts,riskyletters,message);
            cout << "\n\nRisk your word:\n";
            cin >> compare;

            if(compare == word){

                mask = compare;
            }else{

                attempts = remainingAttempts;
            }
            
        }

        for(cont = 0;cont < attempts;cont++){
            if(riskyletters[cont] == tolower(letter)){
                repeatedLetter = true;
            }
        }

        if(repeatedLetter == true){

            message = "Ops, repeated letter!!";

        }else{

           riskyletters += tolower(letter);

           for(cont = 0;cont < wordSize;cont++){

                if(word[cont] == tolower(letter)){
                    mask[cont] = word[cont];
                    contador++;
                    correctLetter = true;
                }
            }

            if(contador == 5 && letter != '1'){

                system("clear");
                
                cout << "Almost there!!\n\n";
                cout << "Do you want to risk the word?\n\n";
                cout << "Type y for yes and n for no\n";

                cin >> option;

                if(option == 'y'){

                    system("clear");
                    message = " ";
                    displayStatus(wordSize,mask,attempts,riskyletters,message);
                    cout << "\n\nRisk your word:\n";
                    cin >> compare;

                    if(compare == word){

                        mask = compare;
                    }else{

                        attempts = 10;
                    }
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
        cout << "You Win!! (^-^)\n";
        cout << "\nCongratulations, you is very good!!!!\n\n";
        cout << "The word is: " << word << "\n\n";
        
    }else{
        system("clear");
        cout << "You Lose! (;-;)\n";
        cout << "\nOh no, try again!\n\n";
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