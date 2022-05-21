#include "person.hh"

#include <vector>

Person::Person(const std::string& name, uint money)
    : name_(name)
    , money_(money)
{}

// GETTERS
uint Person::get_money() const
{
    return money_;
}
std::string Person::get_name() const
{
    return name_;
}

// MONEY TRANSACTIONS
void Person::add_nft(NFT nft)
{
    nfts_.push_back(std::move(nft));
}
NFT Person::remove_nft(const std::string& name)
{
    NFT nft_res;
    for (auto cursor = nfts_.begin(); cursor < nfts_.end(); cursor++)
    {
        if (name == **cursor)
        {
            nft_res = std::move(*cursor);
            nfts_.erase(cursor);
        }
    }
    return nft_res;
}
void Person::add_money(uint money)
{
    money_ = money_ + money;
}

bool Person::remove_money(uint money)
{
    int remaining_money = money_ - money;
    if (remaining_money < 0)
        return false;
    money_ = remaining_money;
    return true;
}
std::vector<std::string> Person::enumerate_nfts() const
{
    std::vector<std::string> vector_res;
    for (size_t cursor = 0; cursor < nfts_.size(); cursor++)
    {
        vector_res.push_back(std::string(*nfts_[cursor]));
    }
    return vector_res;
}

std::ostream& operator<<(std::ostream& os, const Person& p)
{
    os << "Name: " << p.get_name() << '\n';
    os << "Money: " << p.get_money() << '\n';
    os << "NFTs:";
    std::vector<std::string> vector_nft = p.enumerate_nfts();
    for (size_t cursor = 0; cursor < vector_nft.size(); cursor++)
    {
        os << ' ' << vector_nft[cursor];
    }
    return os << '\n';
}
