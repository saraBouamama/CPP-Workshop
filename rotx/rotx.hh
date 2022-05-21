#include "encrypt.hh"

class RotX : public Encrypt
{
public:
    RotX(const std::string& input, int decallage);

    virtual void process() override;

private:
    int decallage_;
};
