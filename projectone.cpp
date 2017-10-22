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
    string line, lineTwo;
    int place, x, pos;
    bool firstrun = true;
    ifstream words, sentences, matchin; //defining input streams
    ofstream match, replace, allwords; //defining output streams
    words.open("words.txt");
    if (words.fail()){ //Error checking.
        cerr << "Error opening words.txt" << endl;
        return(1);
    }
    words >> wordOne >> wordTwo >> wordThree >> wordFour >> wordFive >> wordSeven >> wordEight;
    words.close();
    sentences.open("sentences.txt");
    if (sentences.fail()){
        cerr << "Error finding/creating sentances.txt" << endl;
        return (2);
    }
    match.open("match.txt");
    if (sentences.fail()){ //Error checking.
        cerr << "Error opening sentences.txt" << endl;
        return(3);
    }
    while (sentences.eof() == false){ //This while loop is the match portion of the project.
        if (firstrun == false){
            sentences.ignore(); //clean stream of unwanted whitespace.
        }
        getline(sentences, line, '.');
        firstrun = false;
        if (search(line, wordOne) == true){
            char letter;
            for (int i = 0; i < line.length(); i++){
                if(i == 0 && line[0] >= 97 && line[0] <= 122){ //checks if the first letter is lower case.
                    letter = line[i] - 32;
                    match << letter; //capitlizes first letter.
                }
                else{
                    match << line[i];
                }
            }
                match << "." << endl;
        }
    }
    match.close();
    matchin.open("match.txt");
    if (matchin.fail()){
        cerr << "Error opening match.txt" << endl;
        return (4);
    }
    replace.open("replace.txt");
    if (replace.fail()){
        cerr << "Error finding/creating replace.txt" << endl;
        return(5);
    }
    firstrun = true;
    while (matchin.eof() == false){ // This loop does the input into the replace text. 
        if (firstrun == false){
            matchin.ignore();
        }
        getline(matchin, lineTwo);
        for (int i = 0; i < lineTwo.length(); i++){ 
            if (lineTwo[i] == wordOne[0] && lineTwo[i + wordOne.length()] == wordOne[wordOne.length()]){ //Currently this only works if there is not words that are the same lenght that differ in the middle for example cat vs car.
            replace << wordTwo << " ";
            i = i + wordOne.length();     
        }
            else{
            replace << lineTwo[i];
            }
        }
        replace << endl;
    }
    cout << wordTwo.length() << endl;
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
        if (word[x] == line[y] || word[x] == line[y] + 32 || word[x] + 32 == line [y]){ //This checks for match case insesitivily. Checks letter by letter.
            x++;
            if (word.length() == x && line[y + 1] == ' '){ //This checks for match and prevents compund words from returning true such as apple vs apples.
                return true;
            }
        }
        else{
            x = 0; // Resets in the case of a partial match eariler in the sentance. 
        }
        y++;
        if (word.length() == x && y == line.length()){ //This checks for match and prevents compund words from returning true such as apple vs apples, But in the case of the end of the sentance rather then the middle.
            return true;
        }
    }
}
