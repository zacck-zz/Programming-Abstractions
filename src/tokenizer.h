/*
 * File: tokenizer.h
 * -----------------
 * This file expeors a simple Tokenizer class that divides a string into individual logical units
 * called tokens. In this version of the package, tokens come in two forms:
 *
 * 1. Strings consecutive letters and digits representing words
 * 2. One-Charachter strings representing punctuation or separators
 *
 * The use of Tokenizer class is illustrated by the following code pattern, which
 * reads the tokens in the string variable input:
 *
 *
 *      Tokenizer tok;
 *      tok.setInput(input);
 *      while(tok.hasMoreTokens()) {
 *          string token = tok.nextToken();
 *          ---- process the token ----
 *      }
 */
#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <string>

/*
 * Class: Tokenizer
 * ----------------
 * This class is used to represent a single instance of a scanner.
 */

class Tokenizer {
public:

/*
 * Constructor: Tokenizer
 * Usage: Tokenizer token;
 *        Tokenizer token(str);
 * ----------------------------
 * Initializes a tokenizer object. The initial token stream comes from the string str, if it is
 * specified. The default constructor creates a tokenizer with an empty token stream.
 */
    Tokenizer();
    Tokenizer(std::string str);


/*
 * Method: setInput
 * Usage: tok.setInput(str);
 *-------------------------
 * Sets the input for this tokenizer to the specified string. Any
 * previous input string is discarded.
 */
    void setInput(std::string str);

/*
 * Method: hasMoreTokens
 * Usage: if (scanner.hasMoreTokens())....
 * ---------------------------------------
 * Returns true if there are additional tokens for this tokenizer to read.
 */

    bool hasMoreTokens();

 /*
  * Method: nextToken
  * Usage: token = scanner.nextToken();
  * -----------------------------------
  * Returns the next token from this tokenizer. If callled when no tokens are available, nextToken returns
  * an empty string.
  */

    std::string nextToken();

 /*
  * Method: ignoreWhitespace();
  * Usage: tokenizer.ignoreWhiteSpace();
  * ------------------------------------
  * Tells the tokenizer to ignoreWhitespace characters. By default, the nextToken method
  * treats whitespace characters (typically spaces, and tabs) just like any other
  * punctuation mark and returns them as single-character tokens. Calling
  *
  *     token.ignoreWhitespace();
  *
  * changes this behaviour so the tokenizer ignores whitespace characters
  */
    void ignoreWhitespace();

private:
    std::string buffer; //input string containign the tokens
    int cp; // current positioni in the buffer
    bool ignoreWhitespaceFlag; //Flag to ingore or consumewhitespace

    /* Private Methods */

    void skipWhitespace();
};


#endif // TOKENIZER_H
