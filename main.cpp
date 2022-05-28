#include <iostream>

#include "visitor.hpp"
#include "VisitorLaTeX.hpp"
#include "VisitorMathML.hpp"

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

    Base* _equation = new op_add(
                            new op(2),
                            new op_subtract(
                                new op(2),
                                new op(4)
                                )
                            ); 

    std::cout << "addtion, standard" << std::endl;
    std::cout << _addition->stringify() << " == " << _addition->evaluate() << std::endl;

    std::cout << std::endl;

    // addition, latex
    std::cout << "addtion, latex" << std::endl;
    std::cout << _addition->stringify() << " => " << PrintLaTeX(_addition) << std::endl;


    std::cout << std::endl;

    // addition, mathml
    std::cout << "addtion, mathml" << std::endl;
    std::cout << _addition->stringify() << " => " << std::endl << PrintMathML(_addition) << std::endl;


    std::cout << std::endl;

    std::cout << "equation, standard" << std::endl;
    std::cout << _equation->stringify() << " == " << _equation->evaluate() << std::endl;


    std::cout << std::endl;

    // equation, latex
    std::cout << "equation, latex" << std::endl;
    std::cout << _equation->stringify() << " => " << PrintLaTeX(_equation) << std::endl;


    std::cout << std::endl;

    // equation, mathml
    std::cout << "equation, mathml" << std::endl;
    std::cout << _equation->stringify() << " => " << std::endl << PrintMathML(_equation) << std::endl;


    std::cout << std::endl;

    // cleanup
    delete _addition;
    delete _subtraction;
    delete _multiplication;
    delete _division;
    delete _exponentiation;

    delete _equation;

    return 0;
}