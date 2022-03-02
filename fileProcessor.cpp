#include "fileProcessor.h"
#include <fstream>
#include <cstdlib>

//default constructor
FileProcessor::FileProcessor(){
}

//destructor
FileProcessor::~FileProcessor(){
}

void FileProcessor::processFile(string inputFile, string outputFile){
  string fileContentReceiver;
  ifstream readFile; //ifstream reads the files
  ofstream writeFile; //ofstream writes on the file

  Translator t;

  //open files
  readFile.open(inputFile);
  writeFile.open(outputFile);

  if(readFile.is_open() && writeFile.is_open()){ //make sure both files are open
    while (getline(readFile, fileContentReceiver)) { //tried EndOfFile but didn't work :/
      writeFile << t.translateEnglishWord(fileContentReceiver) << endl;
    }
    readFile.close(); //close file
  }

  else{
    exit(EXIT_FAILURE);
  }
}

void FileProcessor::tutProcessFile(string inputFileTut, string outputFileTut){
  string fileContentReceiver;
  ifstream readFile; //ifstream reads the files
  ofstream writeFile; //ofstream writes on the file

  Translator t;

  //open files
  readFile.open(inputFileTut);
  writeFile.open(outputFileTut);

  if(readFile.is_open() && writeFile.is_open()){ //make sure both files are open
    while (getline(readFile, fileContentReceiver)) {
      writeFile << t.translateTutneseWord(fileContentReceiver) << endl;
    }
    readFile.close(); //close file
  }

  else{
    exit(EXIT_FAILURE);
  }
}
