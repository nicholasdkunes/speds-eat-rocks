#include <iostream>

#include "visitor.hpp"
#include "VisitorLaTeX.hpp"

#include "base.hpp"
#include "op.hpp"
#include "op_add.hpp"
#include "op_subtract.hpp"
#include "op_multiply.hpp"
#include "op_divide.hpp"
#include "op_power.hpp"


int main() {

    Base* _addition = new op_add(new op(2), new op(4));
    Base* _subtraction = new op_subtract(new op(2), new op(4)); 
    Base* _multiplication = new op_subtract(new op(2), new op(4)); 
    Base* _division = new op_subtract(new op(2), new op(4)); 
    Base* _exponentiation = new op_power(new op(2), new op(4)); 

    std::cout << _addition->stringify() << " == " << _addition->evaluate() << std::endl;
    std::cout << _addition->stringify() << " => " << PrintLaTeX(_addition) << std::endl;

    delete _addition;
    delete _subtraction;
    delete _multiplication;
    delete _division;
    delete _exponentiation;

    return 0;
}