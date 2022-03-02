//this a header file and it's purpose is to define a class
#include <iostream>
using namespace std;

class Model{
    public: //access modifiers
        Model();//default constructor
        ~Model();//destructor
        //any public members go here
        string tutStr;
        string normalChar;
        string translateSingleCharacter(char c);
        string translateDoubleCharacter(char c);
        char toEnglishTtranslateSingleCharacter(string s);
        string toEnglishTtranslateDoubleCharacter(string s);
};
