#pragma once

#include <string>

class StackMaxSize : public std::exception
{
public:
    StackMaxSize(const std::string& msg);
    virtual const char* what() const noexcept;

private:
    std::string msg_;
};