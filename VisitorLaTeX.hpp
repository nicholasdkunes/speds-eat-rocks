#ifndef __VISITORLATEX_HPP__
#define __VISITORLATEX_HPP__

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

class VisitorLaTeX : public Visitor {

    private:
        std::vector<std::string> out;

    public:

        VisitorLaTeX() {
            out.push_back("$");
        }

        virtual ~VisitorLaTeX() = default;


        virtual void visit_op(op* node) {
            out.push_back("{" + std::to_string(node->evaluate()) + "}");
        }

        virtual void visit_rand(op_rand* node) {
            out.push_back("{" + std::to_string(node->evaluate()) + "}");
        }



        virtual void visit_add_begin(op_add* node) {
            out.push_back("{(");
        }

        virtual void visit_add_middle(op_add* node) {
            out.push_back(std::to_string(node->get_child(0)->evaluate()) + "+");
        }

        virtual void visit_add_end(op_add* node) {
            out.push_back(std::to_string(node->get_child(1)->evaluate()) + ")}");
        }


        virtual void visit_subtract_begin(op_subtract* node) {
            out.push_back("{(");
        }

        virtual void visit_subtract_middle(op_subtract* node) {
            out.push_back(std::to_string(node->get_child(0)->evaluate()) + "-");
        }

        virtual void visit_subtract_end(op_subtract* node) {
            out.push_back(std::to_string(node->get_child(1)->evaluate()) + ")}");
        }


        virtual void visit_multiply_begin(op_multiply* node) {
            out.push_back("{(");
        }

        virtual void visit_multiply_middle(op_multiply* node) {
            out.push_back(std::to_string(node->get_child(0)->evaluate()) + "\\cdot");
        }

        virtual void visit_multiply_end(op_multiply* node) {
            out.push_back(std::to_string(node->get_child(1)->evaluate()) + ")}");
        }


        virtual void visit_divide_begin(op_divide* node) {
            out.push_back("{\\frac");
        }

        virtual void visit_divide_middle(op_divide* node) {
            out.push_back("{" + std::to_string(node->get_child(0)->evaluate()) + "}");
        }

        virtual void visit_divide_end(op_divide* node) {
            out.push_back("{" + std::to_string(node->get_child(1)->evaluate()) + "}");
        }


        virtual void visit_power_begin(op_power* node) {
            out.push_back("{(");
        }

        virtual void visit_power_middle(op_power* node) {
            out.push_back(std::to_string(node->get_child(0)->evaluate()) + "^");
        }

        virtual void visit_power_end(op_power* node) {
            out.push_back(std::to_string(node->get_child(1)->evaluate()) + ")}");
        }

        std::string str() {
            std::string _str;
            for(std::string i : out) {
                _str += i;
            }
            _str.append("$");

            return _str;
        }

};

std::string PrintLaTeX(Base* ptr) {

    Iterator op_iterator(ptr);
    VisitorLaTeX* v_latex = new VisitorLaTeX();

    while(!op_iterator.is_done())
    {
        op_iterator.current_node()->accept(v_latex, op_iterator.current_index());
        op_iterator.next();
    }

    std::string _out = v_latex->str();
    delete v_latex;

    return _out;
}

#endif
