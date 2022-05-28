#include "op.hpp"
#include <iostream>

double op::evaluate() { 
    return operand;
}

std::string op::stringify() {
    return std::to_string(operand);
}

int op::number_of_children() {
    return 0; 
}

Base* op::get_child(int i) {
    return (Base*)nullptr;
}

void op::accept(Visitor* v, int index) {
    v->visit_op(this);
}
