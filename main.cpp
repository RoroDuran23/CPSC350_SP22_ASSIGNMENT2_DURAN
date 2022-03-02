#include "fileProcessor.h"
using namespace std;


int main(int argc, char *argv[]){
  //instantiate variables/classes
  FileProcessor fp;
  FileProcessor fp1;
  Translator t;
  Model m;

  string inputIn;
  string inputOut;
  string inputFormat;

  //set variables to command line
  inputIn = argv[1];
  inputOut = argv[2];
  inputFormat = argv[3];

  //check for correct number of commands
  if(argc == 4){
      if(inputFormat == "E2T"){
        fp.processFile(inputIn, inputOut);
      }
      else if(inputFormat == "T2E"){
        fp1.tutProcessFile(inputIn, inputOut);
      }
      else{
        cout << "Wrong option, try again" << endl;
      }
  }

  else{
    cout << "Error, try again" << endl;
  }

  return 0;
}
