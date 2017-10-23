// Be sure that you remove the filename extentions , for example words.txt == words & ...

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
bool searchtwo (string line, string word);
//Precondition: Enter the gotten word from match.txt and word you are testing for from words.txt.
//Postcondition: Serches to see if the words match.
//int numberofwords(string wordOne, string wordTwo, string wordThree, string wordFour, string wordfive, string wordSix, string wordSeven, string wordEight);
//Precondition: Enter all words string from words.txt
//Postcondion: Will return an int value equal to the number of words in words.txt.
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
    bool sentencestart = true;
    while (matchin.eof() == false){ // This loop does the input into the replace text. Has issues with compound words. Replaces extra nonexistant word.
        matchin >> lineTwo;
        if (searchtwo(lineTwo, wordOne) == true){
            if (sentencestart = true){
                for (int i = 0; i < wordTwo.length(); i++){
                    replace << wordTwo[i];
                }
            }
            else{
                replace << wordTwo;
            }
            if (lineTwo[lineTwo.length()-1] != '.'){
            replace << " ";
            }
        }
        else if (searchtwo(lineTwo, wordOne) == false){
            replace << lineTwo;
            if (lineTwo[lineTwo.length()-1] != '.'){
            replace << " ";
            }
        }
        if (lineTwo[lineTwo.length()-1] == '.'){
            replace << "." << endl;
            sentencestart = true;
        }
        sentencestart = false;
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

bool searchtwo (string line, string word){
    int x = 0; //x and y count position in string.
    int y = 0;
    for (int i = 0; i < line.length(); i++){ 
        if (word[x] == line[y] || word[x] == line[y] + 32 || word[x] + 32 == line [y]){ //This checks for match case insesitivily. Checks letter by letter.
            x++;
            if (word.length() == x){ //This checks for match and prevents compund words from returning true such as apple vs apples.
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

/*
int numberofwords(string wordOne, string wordTwo, string wordThree, string wordFour, string wordfive, string wordSix, string wordSeven, string wordEight){
    int x = 0 //x will be the number of words in existence.
    if (wordtest(wordOne) == true){
        x++;
    }
    if (wordtest(wordTwo) == true){
        x++;
    }
    if (wordtest(wordThree) == true){
        x++;
    }
    if (wordtest(wordThree) == true){
        x++;
    }
    if (wordtest(wordFour) == true){
        x++;
    }
    if (wordtest(wordFive) == true){
        x++;
    }
    if (wordtest(wordSix) == true){
        x++;
    }
    if (wordtest(wordSeven) == true){
        x++;
    }
    if (wordtest(wordEight) == true){
        x++;
    }
    return x; //return the number of words in words.txt
}
*/
