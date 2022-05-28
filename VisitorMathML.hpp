#ifndef __VISITORMATHML_HPP__
#define __VISITORMATHML_HPP__

#include <vector>
#include <iostream>

#include "iterator.hpp"
#include "visitor.hpp"
#include "op.hpp"
#include "op_rand.hpp"
#include "op_add.hpp"
#include "op_subtract.hpp"
#include "op_multiply.hpp"
#include "op_divide.hpp"
#include "op_power.hpp"

class op;
class op_rand;
class op_add;
class op_subtract;
class op_multiply;
class op_divide;
class op_power;

class VisitorMathML : public Visitor {

    private:
        std::vector<std::string> out;

    public:

        VisitorMathML() {
            out.push_back("<math>\n");
        }

        virtual ~VisitorMathML() = default;


        virtual void visit_op(op* node) {
            //out.push_back("<cn>" + std::to_string(node->evaluate()) + "</cn>\n");
        }

        virtual void visit_rand(op_rand* node) {
            //out.push_back("<cn>" + std::to_string(node->evaluate()) + "</cn>\n");
        }



        virtual void visit_add_begin(op_add* node) {
            out.push_back("<apply>\n<plus/>\n");
        }

        virtual void visit_add_middle(op_add* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(0)->evaluate()) + "</cn>\n");
        }

        virtual void visit_add_end(op_add* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(1)->evaluate()) + "</cn>\n</apply>\n");
        }


        virtual void visit_subtract_begin(op_subtract* node) {
            out.push_back("<apply>\n<minus/>\n");
        }

        virtual void visit_subtract_middle(op_subtract* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(0)->evaluate()) + "</cn>\n");
        }

        virtual void visit_subtract_end(op_subtract* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(1)->evaluate()) + "</cn>\n</apply>\n");
        }


        virtual void visit_multiply_begin(op_multiply* node) {
            out.push_back("<apply>\n<times/>\n");
        }

        virtual void visit_multiply_middle(op_multiply* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(0)->evaluate()) + "</cn>\n");
        }

        virtual void visit_multiply_end(op_multiply* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(1)->evaluate()) + "</cn>\n</apply>\n");
        }


        virtual void visit_divide_begin(op_divide* node) {
            out.push_back("<apply>\n<divide/>\n");
        }

        virtual void visit_divide_middle(op_divide* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(0)->evaluate()) + "</cn>\n");
        }

        virtual void visit_divide_end(op_divide* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(1)->evaluate()) + "</cn>\n</apply>\n");
        }


        virtual void visit_power_begin(op_power* node) {
            out.push_back("<apply>\n<power/>\n");
        }

        virtual void visit_power_middle(op_power* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(0)->evaluate()) + "</cn>\n");
        }

        virtual void visit_power_end(op_power* node) {
            out.push_back("<cn>" + std::to_string(node->get_child(1)->evaluate()) + "</cn>\n</apply>\n");
        }

        std::string str() {
            std::string _str;
            for(std::string i : out) {
                _str += i;
            }
            _str.append("</math>\n");

            return _str;
        }

};

std::string PrintMathML(Base* ptr) {

    Iterator op_iterator(ptr);
    VisitorMathML* v_mathml = new VisitorMathML();

    while(!op_iterator.is_done())
    {
        op_iterator.current_node()->accept(v_mathml, op_iterator.current_index());
        op_iterator.next();
    }

    std::string _out = v_mathml->str();
    delete v_mathml;

    return _out;
}

#endif
