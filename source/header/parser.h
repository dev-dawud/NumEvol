#pragma once

#include <string>

class AST {
private:

virtual	~AST() = default;

};

class numberAST : public AST {
private:

double value;public:

};class stringAST : public AST {
private:

	std::string variable;

};class operatorAST : public AST {
private:

	char operator;


};