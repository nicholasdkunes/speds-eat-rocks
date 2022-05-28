#include "op_divide.hpp"
#include <iostream>

double op_divide::evaluate() { 
    return _v1->evaluate() / _v2->evaluate();
}

std::string op_divide::stringify() {
    return
        "(" +
            _v1->stringify() +
        " / " +
            _v2->stringify() +
        ")";
}

int op_divide::number_of_children() {
    return 2; 
}

Base* op_divide::get_child(int i) {
    return (i > this->number_of_children()) ? nullptr : ((i == 0) ? _v1 : _v2);
}

void op_divide::accept(Visitor* v, int index) {
    if(index == 0)
        v->visit_divide_begin(this);
    else if(index == 1)
        v->visit_divide_middle(this);
    else if(index == 2)
        v->visit_divide_end(this);
}
