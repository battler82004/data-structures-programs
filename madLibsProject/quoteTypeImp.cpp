#include <string>
#include "quoteType.h"
using namespace std;

// Returns the starting quote
string quoteType::getStartingQuote() const {
  return startingQuote;
}

// Returns the first part of speech
string quoteType::getPartOfSpeech1() const {
  return partOfSpeech1;
}

// Returns the second part of speech
string quoteType::getPartOfSpeech2() const {
  return partOfSpeech2;
}

// Returns the final quote
string quoteType::getFinalQuote() const {
  return finalQuote;
}

// Creates and assigns the final quote
void quoteType::setFinalQuote(string replacements[2]) {
  finalQuote =  quoteParts[0] + replacements[0] + quoteParts[1] + replacements[1] + quoteParts[2];
}

// Constructor
quoteType::quoteType(string originalQuote, string part1, string part2, string quotePart1, string quotePart2, string quotePart3) {
  startingQuote = originalQuote;
  partOfSpeech1 = part1;
  partOfSpeech2 = part2;
  quoteParts[0] = quotePart1;
  quoteParts[1] = quotePart2;
  quoteParts[2] = quotePart3;
}