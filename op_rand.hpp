#ifndef __OP_RAND_HPP__
#define __OP_RAND_HPP__

#include <stack>
#include <utility>
#include <time.h>
#include <sstream>

#include "base.hpp"

class op_rand : public Base {

    private:

        double operand = 0;

    public:

        op_rand() {
            srand(time(NULL));
            operand = rand() % 100;
        };

        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);

        virtual void accept (Visitor* v, int index);
};

#endif
