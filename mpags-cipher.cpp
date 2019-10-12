#include <iostream>
#include <string>
#include <vector>

std::string convertIntToString(char x);

int main(int argc, char* argv[])
{

  const std::vector<std::string> cmdLineArgs{argv, argv+argc};

  std::cout << "Command Line Arguments: ";
  for(int i{0}; i < argc; ++i){
    std::cout << cmdLineArgs[i];
    if(i != (argc - 1)){
      std::cout << ", ";
    } else {
      std::cout << "\n";
    }
  }

  std::string inputFileName{};
  std::string outputFileName{};
 
  for(int i{0}; i < argc; ++i){
    if(cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help"){
      std::cout << "HELP - Type an input, when finished press Enter and then Ctrl+D" << std::endl;
    }
    else if(cmdLineArgs[i] == "-i"){
      inputFileName = cmdLineArgs[i+1];
      std::cout << "Input file name: " << inputFileName << std::endl;
    }
    else if(cmdLineArgs[i] == "-o"){
      outputFileName = cmdLineArgs[i+1];
      std::cout << "Output file name: " << outputFileName << std::endl;
    }
    else if(cmdLineArgs[i].at(0) == '.'){
      continue;
    }
    else if(cmdLineArgs[i] == "--version"){
      std::cout << "Version 1" << std::endl;
    }
    else{
      if(i != 0 && (cmdLineArgs[i-1] == "-i" || cmdLineArgs[i-1] == "-o")) continue;
      std::cout << "Command line input: '"; 
      for(int j{0}; j < cmdLineArgs[i].size(); ++j){
         std::cout << cmdLineArgs[i].at(j);
	 if(j == (cmdLineArgs[i].size() - 1)) std::cout << "' is not understood" << std::endl;
      }
    }
  }

  char in_char{'x'};

  std::string outputString = "";

  while(std::cin >> in_char){

    if(isalpha(in_char)){
      in_char = toupper(in_char);
      outputString += in_char;
    }

    if(isdigit(in_char)){
      outputString += convertIntToString(in_char);
    }

  }

  std::cout << "Output String: " << outputString << std::endl;

}

std::string convertIntToString(char x){

  std::string returnString{};

  switch(x){
  case '0':
    returnString = "ZERO";
    break;
  case '1':
    returnString = "ONE";
    break;
  case '2':
    returnString = "TWO";
    break;
  case '3':
    returnString =  "THREE";
    break;
  case '4':
    returnString =  "FOUR";
    break;
  case '5':
    returnString =  "FIVE";
    break;
  case '6':
    returnString =  "SIX";
    break;
  case '7':
    returnString =  "SEVEN";
    break;
  case '8':
    returnString =  "EIGHT";
    break;
  case '9':
    returnString =  "NINE";
    break;
  default:
    std::cout << "NOT A SINGLE DIGIT INT, RETURNING 0" << std::endl;
    returnString =  "ERROR";
    break;
  }
  
  return returnString;

}

