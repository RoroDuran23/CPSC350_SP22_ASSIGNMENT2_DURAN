//this a header file and it's purpose is to define a class
#include <iostream>
#include "translator.h"

using namespace std;

class FileProcessor{
    public: //access modifiers
        FileProcessor();//default constructor
        ~FileProcessor();//destructor
        //any public members go here
        Translator t;
        string fileContentReceiver;
        void processFile(string inputFile, string outputFile);
        void tutProcessFile(string inputFileTut, string outputFileTut);
};
