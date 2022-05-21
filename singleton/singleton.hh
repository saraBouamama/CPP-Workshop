#pragma once

#include <string>

template <typename T>
class Singleton
{
public:
    Singleton(const Singleton& s) = delete;
    Singleton& operator=(const Singleton&) = delete;
    static T* instance()
    {
        static T* inst;
        return inst;
    }

protected:
    Singleton() = default;
    ~Singleton();
};

class Logger : public Singleton<Logger>
{
public:
    Logger(const Logger& s) = delete;
    Logger& operator=(const Logger&) = delete;

    void open_log_file(const std::string& file);
    void write_to_log_file();
    void close_log_file();

protected:
    Logger() = default;
    ~Logger();
};