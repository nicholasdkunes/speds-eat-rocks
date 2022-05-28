#ifndef __OP_MULTIPLY_HPP__
#define __OP_MULTIPLY_HPP__

#include <stack>
#include <utility>
#include <sstream>

#include "base.hpp"

class op_multiply : public Base {

    private:

        Base* _v1 = NULL;
        Base* _v2 = NULL;

    public:

        op_multiply() : Base() {};
        op_multiply(Base* v1, Base* v2) : _v1(v1), _v2(v2) {};
        ~op_multiply() {
            delete _v1;
            delete _v2;
        }

        virtual double evaluate();
        virtual std::string stringify();
        virtual int number_of_children();
        virtual Base* get_child(int i);

        virtual void accept (Visitor* v, int index);
};

#endif
