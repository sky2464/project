#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool wordtest(string word);
//Precondition: Entering a string from the words file.
//Postcondition: This fuction will return true if the argument exists.

int main(){
    string wordOne, wordTwo, wordThree, wordFour, wordFive, wordSix, wordSeven, wordEight;
    ifstream words, sentances; //defining input streams
    ofstream match, replace, allwords; //defining output streams
    words.open("words.txt");
    if (words.fail()){ //Error checking.
        cerr << "Error opening words.txt";
        return(1);
    }
    words >> wordOne >> wordTwo >> wordThree >> wordFour >> wordFive >> wordSeven >> wordEight;
}

bool wordtest(string word);
    if(word[0] != ' '){
        return false;
    }
    else {
    return true
    }
}
