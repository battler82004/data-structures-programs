// Mad Libs Project
// James Taddei & Jeremy Brensinger
// 7/1/22

#include <iostream>
#include "quoteType.h"
using namespace std;

void wordReplacement(string[2], quoteType);
// Has the user input the two replacement words

int main() {
  // Variable declarations
  string replacements[2];
  int quoteChoice;
  char isPlayingAgain;
  quoteType fatherQuote("No, I am your father!", " verb", " noun", "No, I ", " your ", "!");
  quoteType boatQuote("You're gonna need a bigger boat.", "n adjective", " noun", "You're gonna need a ", " ", ".");

  // Replacing words and outputting the new sentences
  do {
    // Choosing the quote
    cout << "Type the number of one of the following options:" << endl;
    cout << "1. " << fatherQuote.getStartingQuote() << endl;
    cout << "2. " << boatQuote.getStartingQuote() << endl;
    cout << endl << "Option: ";
    cin >> quoteChoice;

    if (quoteChoice == 1) { // I am your father quote
      wordReplacement(replacements, fatherQuote);
      fatherQuote.setFinalQuote(replacements);

      cout << fatherQuote.getFinalQuote() << endl;
    }
    else if (quoteChoice == 2) { // Bigger boat quote
      wordReplacement(replacements, boatQuote);
      boatQuote.setFinalQuote(replacements);

      cout << boatQuote.getFinalQuote() << endl;
    }
    else { // Invalid input
      cout << "Error, please enter '1' or '2'" << endl;
    }

    cout << "Thank you for playing!" << endl;

    // Has the user pick if they want to play again
    cout << endl << endl << "Play again (Y/N)? ";
    cin >> isPlayingAgain;
    cout << endl;
  } while ((isPlayingAgain == 'Y') || (isPlayingAgain == 'y'));
}

// Has the user input the two replacement words
void wordReplacement(string replacements[2], quoteType quote) {
  // Inputting the replacement words
  cout << endl << "Enter a" << quote.getPartOfSpeech1() << ": ";
  cin >> replacements[0];

  cout << endl << "Enter a" << quote.getPartOfSpeech2() << ": ";
  cin >> replacements[1];

  cout << "The quote you have created is..." << endl;

  return;
}
