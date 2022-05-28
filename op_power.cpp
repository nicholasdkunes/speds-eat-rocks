#include "op_power.hpp"
#include <iostream>

double op_power::evaluate() { 
    return std::pow(_v1->evaluate(), _v2->evaluate());
}

std::string op_power::stringify() {
    return
        "(" +
            _v1->stringify() +
        " ** " +
            _v2->stringify() +
        ")";
}

int op_power::number_of_children() {
    return 2; 
}

Base* op_power::get_child(int i) {
    return (i > this->number_of_children()) ? nullptr : ((i == 0) ? _v1 : _v2);
}

void op_power::accept(Visitor* v, int index) {
    if(index == 0)
        v->visit_power_begin(this);
    else if(index == 1)
        v->visit_power_middle(this);
    else if(index == 2)
        v->visit_power_end(this);
}
