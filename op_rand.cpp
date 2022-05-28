#include "op.hpp"
#include "op_rand.hpp"
#include <iostream>

double op_rand::evaluate() { 
    return operand;
}

std::string op_rand::stringify() {
    return std::to_string(operand);
}

int op_rand::number_of_children() {
    return 0; 
}

Base* op_rand::get_child(int i) {
    return new op(operand);
}

void op_rand::accept(Visitor* v, int index) {
    v->visit_rand(this);
}
