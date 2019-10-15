#include <iostream>
#include <string>
#include <vector>

// For std::isalpha and std::isupper
#include <cctype>

std::string convertIntToString(const char x);

int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs{argv, argv+argc};

  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {cmdLineArgs.size()};

  std::cout << "Command Line Arguments: ";
  for(size_type i{0}; i < nCmdLineArgs; ++i){
    std::cout << cmdLineArgs[i];
    if(i != (nCmdLineArgs - 1)){
      std::cout << ", ";
    } else {
      std::cout << "\n";
    }
  }

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFileName{};
  std::string outputFileName{};
 
  // Start loop from 1 rather than 0 to skip over the program name
  for(size_type i{1}; i < nCmdLineArgs; ++i){
    if(cmdLineArgs[i] == "-h" || cmdLineArgs[i] == "--help"){
      helpRequested = true;
    }
    else if(cmdLineArgs[i] == "-i"){
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[Error] -i option requires a filename argument" << std::endl;
        // Exit main with non-zero return to indicate failure
        return 1;
      }
      inputFileName = cmdLineArgs[i+1];
      ++i;
    }
    else if(cmdLineArgs[i] == "-o"){
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1) {
        std::cerr << "[Error] -o option requires a filename argument" << std::endl;
        // Exit main with non-zero return to indicate failure
        return 1;
      }
      outputFileName = cmdLineArgs[i+1];
      ++i;
    }
    else if(cmdLineArgs[i] == "--version"){
      versionRequested = true;
    }
    else{
      std::cerr << "[Error] command line input: '" << cmdLineArgs[i] << "' is not understood" << std::endl;
      // exit main with non-zero return to indicate failure
      return 1;
    }
  }

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n"
      << "If providing input on stdin, when finished press Enter and then Ctrl+D\n" << std::endl;
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 0;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "Version 1" << std::endl;
    return 0;
  }

  // Read in user input from stdin/file
  // Warn that input file option not yet implemented
  if (!inputFileName.empty()) {
    std::cout << "[Warning] input from file ('"
      << inputFileName
      << "') not implemented yet, using stdin\n";
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

  // Output the transliterated text
  // Warn that output file option not yet implemented
  if (!outputFileName.empty()) {
    std::cout << "[Warning] output to file ('"
      << outputFileName
      << "') not implemented yet, using stdout\n";
  }

  std::cout << "Output String: " << outputString << std::endl;

  // No strict requirement to return from main, but we recommend to do so for
  // clarity and for consistency with other functions
  return 0;
}

std::string convertIntToString(const char x){

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
    std::cerr << "[Error] NOT A SINGLE DIGIT INT, RETURNING EMPTY STRING" << std::endl;
    break;
  }
  
  return returnString;
}

