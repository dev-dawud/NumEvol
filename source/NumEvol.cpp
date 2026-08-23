#include <iostream>
#include <string>

#include "header/lexer.h"

Lexer lexer;

int main() {

    std::cout << "enter a calculation: \n";

    while (true) {

        int token;

		token = lexer.gettok();

        if (token == Lexer::tokEoi){
            std::cout << "exit\n";
            break;
        }

        if (token == Lexer::tokNumber){

            std::cout << "your Number: " << lexer.getNumVal() << "\n";
        }

        else if (token == Lexer::tokString){

            std::cout << "your variable: " << lexer.getIdentifierStr() << "\n";
        }
        else {

            std::cout << "your operator: " << (char)token << "\n";
        }
    }

	return 0;
}