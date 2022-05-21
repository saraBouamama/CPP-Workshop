#pragma once

#include <iostream>
#include <memory>

namespace termcolor
{
    enum class background : unsigned int
    {
        black = 40,
        red = 41,
        green = 42,
        yellow = 43,
        blue = 44,
        magenta = 45,
        cyan = 46,
        white = 47
    };

    enum class foreground : unsigned int
    {
        black = 30,
        red = 31,
        green = 32,
        yellow = 33,
        blue = 34,
        magenta = 35,
        cyan = 36,
        white = 37
    };

    class my_ostream
    {
    public:
        static int res;
        my_ostream(std::ostream& stream);
        ~my_ostream();

        my_ostream& operator<<(termcolor::background value);
        my_ostream& operator<<(termcolor::foreground value);

        template <typename T>
        my_ostream& operator<<(const T& value)
        {
            stream_ << value;
            return *this;
        }

        my_ostream& operator<<(std::ostream& (*func)(std::ostream&))
        {
            func(stream_);
            return *this;
        }

    private:
        std::ostream& stream_;
    };

    my_ostream operator<<(std::ostream& out, background value);
    my_ostream operator<<(std::ostream& out, foreground value);
} // namespace termcolor
