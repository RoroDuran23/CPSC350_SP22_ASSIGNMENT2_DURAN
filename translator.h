#include <iostream>
#include "model.h"
using namespace std;

class Translator{

  public:
    Translator(); //defualt constructor
    ~Translator(); //destructor
    //member variables
    string tutStr;
    string normalStr;
    Model m;
    string translateEnglishWord(string wordInput);
    string translateEnglishSentence(string sentInput);
    string translateTutneseWord(string wordInput);
};
