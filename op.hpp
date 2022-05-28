#ifndef __OP_HPP__
#define __OP_HPP__

#include <stack>
#include <utility>
#include <sstream>

#include "base.hpp"

class op : public Base {

    private:

        double operand = 0;

    public:

        op();
        op(double value) : operand(value) {};

        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);

        virtual void accept (Visitor* v, int index);
};

#endif
