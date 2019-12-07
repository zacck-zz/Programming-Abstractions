#include <iostream>
#include <cctype>
#include <string>
#include "error.h"
#include "stack.h"
#include "strlib.h"
using namespace std;


/*
 * Function: applyOperator
 * Usage: applyOperator(op, operandStack)
 * -------------------------------------
 * Applies the given operator to the top two elements of the supplied
 * stack. Since the operands are popped in reverse order the right operand is
 * popped before the left.
 */
void applyOperator(char op, Stack<double> & operandStack){
    double result;
    double rhs = operandStack.pop();
    double lhs = operandStack.pop();
    switch (op) {
        case '+': result = lhs + rhs; break;
        case '-': result = lhs - rhs; break;
        case '*': result = lhs * rhs; break;
        case '/': result = lhs / rhs; break;
        default: error("Illegal Operator");
    }
    //print out result
    cout << lhs << " "<< op << " " << rhs << " = "<< result << endl;
    //push result back to stack
    operandStack.push(result);
}


/*
 * Function: helpCommand
 * Usage: helpCommand();
 * ----------------------
 * Displays a help message to enable the user
 */
void helpCommand(){
    cout << "Enter expressions in Reverse Polish Notation," << endl;
    cout << "in which operators follow the operands to which " << endl;
    cout << "they apply. Each line consists of a number, an" << endl;
    cout << "operator, or one of the following commands:" << endl;
    cout << "  Q -- Quit the program" << endl;
    cout << "  H -- Display this help message" << endl;
    cout << "  C -- Clear the calculator stack" << endl;
}
