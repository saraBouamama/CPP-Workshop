#include "compute-visitor.hh"

#include <cassert>

using namespace std;

visitor::ComputeVisitor::ComputeVisitor()
{}

void visitor::ComputeVisitor::visit(const tree::Tree& e)
{
    e.accept(*this);
}

void visitor::ComputeVisitor::visit(const tree::Node& e)
{
    auto l = ComputeVisitor();
    auto r = ComputeVisitor();

    e.lhs_get()->accept(l);
    e.rhs_get()->accept(r);

    auto val = l.value_get();
    auto var = r.value_get();

    if (e.value_get() == ("+"))
        val_ = val + var;
    if (e.value_get() == ("-"))
        val_ = val - var;
    if (e.value_get() == ("*"))
        val_ = val * var;
    if (e.value_get() == ("/"))
    {
        if (var == 0)
            throw std::overflow_error("Divide by zero exception");
        val_ = val / var;
    }
}

int visitor::ComputeVisitor::value_get()
{
    return val_;
}

void visitor::ComputeVisitor::visit(const tree::Leaf& e)
{
    val_ = stoi(e.value_get());
}
