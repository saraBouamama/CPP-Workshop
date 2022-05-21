#include "termcolor.hh"

namespace termcolor
{
    int my_ostream::res = 0;

    my_ostream::my_ostream(std::ostream& stream)
        : stream_(stream)
    {
        res = res + 1;
    }
    my_ostream::~my_ostream()
    {
        res--;
        if (res == 0)
            stream_ << "\x1B[0m";
    }

    my_ostream operator<<(std::ostream& out, termcolor::background value)
    {
        out << "\x1B[" << static_cast<int>(value) << "m";
        return my_ostream(out);
    }
    my_ostream operator<<(std::ostream& out, termcolor::foreground value)
    {
        out << "\x1B[" << static_cast<int>(value) << "m";
        return my_ostream(out);
    }

    my_ostream& my_ostream::operator<<(termcolor::background value)
    {
        stream_ << "\x1B[" << static_cast<int>(value) << "m";
        return *this;
    }
    my_ostream& my_ostream::operator<<(termcolor::foreground value)
    {
        stream_ << "\x1B[" << static_cast<int>(value) << "m";
        return *this;
    }
} // namespace termcolor