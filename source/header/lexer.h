#pragma once

#include <string>
#include <cctype>
#include <cstdlib>
#include <iostream>

class Lexer {
private:

    std::string words;
	double Number;
	int lastChar = ' ';

public:

    enum Token {

        tokEoi = -1,
        tokNumber = -2,
        tokString = -3
    };

    int gettok() {

        //skips all whitespaces
        while(isspace(lastChar))
            lastChar = getchar();

        // recognize complex numbers like i,j,k
        if (isalpha(lastChar)){

			words = lastChar;

			while(isalnum(lastChar = getchar()))
				words += lastChar;

			return tokString;
        
        
        }

        // recognizes Numbers
        if (isdigit(lastChar) || lastChar == '.'){

            std::string numStr = "";

            do {

                numStr += lastChar; // ?
                lastChar = getchar(); // ?

            }
            while (isdigit(lastChar) || lastChar   == '.');

			// converts the Number (currently in a string saved) to a double
            Number = strtod(numStr.c_str(), nullptr);

            return tokNumber;
        }

		// recognizes end od input
        if (lastChar == EOF)
            return tokEoi;

		// If everything is false, then it is an operator and gets returned as an ASCII value
        int Operator = lastChar;
        lastChar = getchar();
        return Operator;
    }

    // (made by AI, Gemini 58-59)
    double getNumVal() const { return Number; }
    std::string getIdentifierStr() const { return words; }
};