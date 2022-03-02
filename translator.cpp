#include "translator.h"

//default constructor
Translator::Translator(){
  tutStr = "";
  normalStr = "";
  Model m;
}

//destructor
Translator::~Translator(){
}

string Translator::translateEnglishWord(string wordInput){
  tutStr = ""; //set empty string
  for(int i = 0; i < wordInput.length(); ++i){
    if(i == wordInput.length()-1){
      tutStr += m.translateSingleCharacter(wordInput[i]);
    }
    else{
      if(wordInput[i] != wordInput[i + 1] ){
      tutStr += m.translateSingleCharacter(wordInput[i]);
      }
      else{
        tutStr += m.translateDoubleCharacter(wordInput[i]);
        ++i;
      }
    }
  }
  return tutStr;
}

string Translator::translateEnglishSentence(string sentInput){ //Should have made a substring (or use the split function) to store each individual words in a variable; this could have helped when writing on the output-file.
  for (int i = 0; i < sentInput.length(); ++i){
    if(sentInput[i] != sentInput[i + 1]){
      tutStr += m.translateSingleCharacter(sentInput[i]);
    }
    else{
      tutStr += m.translateDoubleCharacter(sentInput[i]);
      ++i;
    }
  }
  return tutStr;
}

string Translator::translateTutneseWord(string wordInput){ //do i need to use wordInput ?
  normalStr = "";
  for(int i = 0; i < wordInput.length(); ++i){

    //check for "letters" of length one
    if(wordInput[i] == 'a' || wordInput[i] == 'A'|| wordInput[i] == 'e' || wordInput[i] == 'E' ||
    wordInput[i] == 'i' || wordInput[i] == 'I' || wordInput[i] == 'o' || wordInput[i] == 'O' ||
    wordInput[i] == 'u' || wordInput[i] == 'U'){
      normalStr += wordInput[i];
    }

    //check for "letters" of length two, letter 'x'
    else if(wordInput[i] == 'x' || wordInput[i] == 'X'){
      normalStr += wordInput[i+1];
      i += 1;
    }

    //check for "letters" of length three -> 14 letters
    else if(wordInput[i] == 'b' || wordInput[i] == 'd' || wordInput[i] == 'f' || wordInput[i] == 'j'
    || wordInput[i] == 'l' || wordInput[i] == 'm' || wordInput[i] == 'n' || wordInput[i] == 'p'
    || wordInput[i] == 'r'|| wordInput[i] == 's'|| wordInput[i] == 't'|| wordInput[i] == 'v'
    || wordInput[i] == 'y' || wordInput[i] == 'z' || wordInput[i] == 'B' || wordInput[i] == 'D'
    || wordInput[i] == 'F' || wordInput[i] == 'J' || wordInput[i] == 'L' || wordInput[i] == 'M'
    || wordInput[i] == 'N' || wordInput[i] == 'P'|| wordInput[i] == 'R'|| wordInput[i] == 'S'
    || wordInput[i] == 'T'|| wordInput[i] == 'V'|| wordInput[i] == 'Y' || wordInput[i] == 'Z'){

      if(wordInput[i] == 's' || wordInput[i] == 'S'){ //check for double-characters (squa(t)-)

        //check for two letters in a row
        if(wordInput[i + 1] == 'q' || wordInput[i + 1] == 'Q'){

          //one letter words / vowels
          if(wordInput[i + 4] == 't' || wordInput[i + 4] == 'T'){
            normalStr += wordInput[i + 5];
            normalStr += wordInput[i + 5];
            i += 5;
          }

          //two letter words, only for 'x'
          else if(wordInput[i + 4] == 'e' || wordInput[i + 4] == 'E'){
            normalStr +=  wordInput[i + 5];
            normalStr +=  wordInput[i + 5];
            i += 5;
          }

          //four letter words
          else if(wordInput[i + 4] == 'c' || wordInput[i + 4] == 'h' || wordInput[i + 4] == 'k' || wordInput[i + 4] == 'w'
          || wordInput[i + 4] == 'C' || wordInput[i + 4] == 'H' || wordInput[i + 4] == 'K' || wordInput[i + 4] == 'W'){
            normalStr += wordInput[i + 4];
            normalStr += wordInput[i + 4];
            i += 7;
          }

          //five letter words
          else if(wordInput[i + 5] == 'q' || wordInput[i + 5] == 'Q'){
            normalStr += wordInput[i + 5];
            normalStr += wordInput[i + 5];
            i += 8;
          }

          //check for three length words
          else{
            normalStr += wordInput[i + 4];
            normalStr += wordInput[i + 4];
            i += 6;
          }
        }

      //check for "sus"
        else{
          normalStr += wordInput[i];
          i += 4;
        }
      }

      //return other three letter words that do not start with an s
      else{
        normalStr += wordInput[i];
        i += 2;
      }
    }

      //check for "letters" of length four
      else if(wordInput[i] == 'c' || wordInput[i] == 'h' || wordInput[i] == 'k' || wordInput[i] == 'w'
      || wordInput[i] == 'C' || wordInput[i] == 'H' || wordInput[i] == 'K' || wordInput[i] == 'W'){
        normalStr += wordInput[i];
        i += 3;
      }

      //check for "letters" of length five, letter 'q'
      else if(wordInput[i] == 'q' || wordInput[i] == 'Q'){
        normalStr += wordInput[i];
        i += 4;
      }
    else{
      normalStr += wordInput[i];
    }
  }
  return normalStr;
}
