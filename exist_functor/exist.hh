#include <vector>

template <class T>
class Exist
{
public:
    bool operator()(T);

private:
    std::vector<T> vector_;
};
#include "exist.hxx"
