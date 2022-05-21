#include "list.hh"

List::List()
    : nb_elts_(0)
    , first_(nullptr)
    , last_(nullptr)
{}

void List::push_front(int i)
{
    auto elem = std::make_shared<Node>(Node(i));
    elem->prev_set(nullptr);

    if (first_ != nullptr)
    {
        elem->next_set(first_);
        first_->prev_set(elem);
    }
    else
    {
        elem->next_set(nullptr);
        last_ = elem;
    }
    nb_elts_++;
    first_ = elem;
}

void List::push_back(int i)
{
    if (first_ == nullptr)
        push_front(i);
    else
    {
        nb_elts_++;
        auto elem = std::make_shared<Node>(Node(i));
        last_->next_set(elem);
        elem->next_set(nullptr);
        elem->prev_set(last_);
        last_ = elem;
    }
}

std::optional<int> List::pop_front()
{
    int count;
    if (first_ == nullptr)
        return std::nullopt;
    else
    {
        count = first_->val_get();
        first_ = first_->next_get();
        if (nb_elts_ != 1)
            first_->prev_set(nullptr);
        else
        {
            first_ = nullptr;
            last_ = nullptr;
        }
        nb_elts_--;
        return count;
    }
}

std::optional<int> List::pop_back()
{
    int count;
    if (first_ == nullptr)
        return std::nullopt;
    else
    {
        count = last_->val_get();
        last_ = last_->prev_get();
        if (nb_elts_ != 1)
            last_->next_set(nullptr);
        else
        {
            first_ = nullptr;
            last_ = nullptr;
        }
        nb_elts_--;
        return count;
    }
}

void List::print(std::ostream& os) const
{
    if (first_ == nullptr)
        return;
    else
    {
        auto f = *first_;
        os << f.val_get();
        while (f.next_get() != nullptr)
        {
            auto r = f.next_get();
            f = *r;
            os << " " << f.val_get();
        }
    }
}
int List::length() const
{
    return nb_elts_;
}