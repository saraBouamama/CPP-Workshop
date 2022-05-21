#include <memory>
#include <ostream>

#include "nft.hh"

NFT create_empty_nft()
{
    return std::unique_ptr<std::string>(nullptr);
}

NFT create_nft(const std::string& name)
{
    NFT res = std::make_unique<std::string>(std::string(name));
    return res;
}