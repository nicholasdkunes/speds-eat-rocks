#ifndef __VISITOR_HPP__
#define __VISITOR_HPP__

class op;
class op_rand;
class op_add;
class op_subtract;
class op_multiply;
class op_divide;
class op_power;

class Visitor{
    public:
        virtual ~Visitor() = default;

        // Nodes with no children are visited only once (index = 0)
        virtual void visit_op(op* node) = 0;
        virtual void visit_rand(op_rand* node) = 0;

        // Nodes with two children are visited three times.
        // index = 0 -> begin
        // index = 1 -> middle
        // index = 2 -> end
        virtual void visit_add_begin(op_add* node) = 0;
        virtual void visit_add_middle(op_add* node) = 0;
        virtual void visit_add_end(op_add* node) = 0;
        virtual void visit_subtract_begin(op_subtract* node) = 0;
        virtual void visit_subtract_middle(op_subtract* node) = 0;
        virtual void visit_subtract_end(op_subtract* node) = 0;
        virtual void visit_multiply_begin(op_multiply* node) = 0;
        virtual void visit_multiply_middle(op_multiply* node) = 0;
        virtual void visit_multiply_end(op_multiply* node) = 0;
        virtual void visit_divide_begin(op_divide* node) = 0;
        virtual void visit_divide_middle(op_divide* node) = 0;
        virtual void visit_divide_end(op_divide* node) = 0;
        virtual void visit_power_begin(op_power* node) = 0;
        virtual void visit_power_middle(op_power* node) = 0;
        virtual void visit_power_end(op_power* node) = 0;
};

#endif //__VISITOR_HPP__
