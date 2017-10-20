#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool wordtest(string word);
//Precondition: Entering a string from the words file.
//Postcondition: This fuction will return true if the argument exists.
bool search(string line, string word);
//Precondition: Enter the gotten line from scentences.txt and word you are testing for from words.txt.
//Postcondition: Serches to see if word is in line will return true if word is in line.

int main(){
    string wordOne, wordTwo, wordThree, wordFour, wordFive, wordSix, wordSeven, wordEight; 
    string line, periodFinder;
    int place, x;
    bool firstrun = true;
    ifstream words, sentences; //defining input streams
    ofstream match, replace, allwords; //defining output streams
    words.open("words.txt");
    if (words.fail()){ //Error checking.
        cerr << "Error opening words.txt" << endl;
        return(1);
    }
    words >> wordOne >> wordTwo >> wordThree >> wordFour >> wordFive >> wordSeven >> wordEight;
    words.close();
    sentences.open("sentences.txt");
    if (sentences.fail()){ //Error checking.
        cerr << "Error opening sentences.txt" << endl;
        return(2);
    }
    while (sentences.eof() == false){
        if (firstrun == false){
            sentences.clear();
        }
        getline(sentences, line, '.');
        firstrun = false;
        if (search(line, wordOne) == true){
            cout << line << endl;
        }
    }
}

bool wordtest(string word){
    if(word[0] != ' '){
        return false;
    }
    else {
    return true;
    }
}

bool search (string line, string word){
    int x = 0; //x and y count position in string.
    int y = 0;
    for (int i = 0; i < line.length(); i++){ 
        if (word[x] == line[y]){ //add or statments subtracting to make it check for positive and negetive chars.
            x++;
        }
    y++;
    }
    if (word.length() == x){
        return true;
    }
    else {
        return false;
    }
}
