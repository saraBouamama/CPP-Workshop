#include "rotx.hh"

RotX::RotX(const std::string& input, int decallage)
    : Encrypt(input)
    , decallage_(decallage)
{}

void RotX::process()
{
    int de = decallage_ % 26;
    int num = decallage_ % 10;
    while (de < 0)
        de += 26;
    while (num < 0)
        num += 10;

    for (const char& element : input_)
    {
        char i = element;
        if (element >= 'a' and element <= 'z')
        {
            /*-26 pour rester dans la table ascii*/
            i = element - 26 + de;
            while (i < 'a')
                i += 26;
            while (i > 'z')
                i -= 26;
        }
        else if (element >= 'A' and element <= 'Z')
        {
            i = element + de;
            while (i < 'A')
                i += 26;
            while (i > 'Z')
                i -= 26;
        }
        else if (element >= '0' and element <= '9')
        {
            i = element + num;
            while (i > '9')
                i -= 10;
            while (i < '0')
                i += 10;
        }
        std::cout << i;
    }
    std::cout << '\n';
}
