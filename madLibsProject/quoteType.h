#include <string>
using namespace std;

class quoteType {
  private:
    string startingQuote, finalQuote, partOfSpeech1, partOfSpeech2;
    string quoteParts[3];
  public:
    string getStartingQuote() const;
    // Returns the starting quote
    string getPartOfSpeech1() const;
    // Returns the first part of speech
    string getPartOfSpeech2() const;
    // Returns the second part of speech
    string getFinalQuote() const;
    // Returns the final quote
    void setFinalQuote(string replacments[2]);
    // Creates and assigns the final quote
    quoteType(string originalQuote, string part1, string part2, string quotePart1, string quotePart2, string quotePart3);
    // Constructor
};