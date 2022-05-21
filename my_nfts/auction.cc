#include "auction.hh"

#include <algorithm>
#include <memory>

Auction::Auction(Person& organizer, NFT nft, uint initial_bid)
    : organizer_(organizer)
    , highest_bid_(initial_bid)
{
    if (nft == nullptr)
        throw std::invalid_argument("nft empty");
    nft_ = std::move(nft);
    highest_bidder_ = &organizer_;
}

Auction::~Auction()
{
    highest_bidder_->add_nft(std::move(nft_));
    if (highest_bidder_->get_name() != organizer_.get_name())
        organizer_.add_money(highest_bid_);
}

bool Auction::bid(Person& person, uint money)
{
    if (money > highest_bid_ && person.get_money() >= money)
    {
        if (highest_bidder_->get_name() != organizer_.get_name())
            highest_bidder_->add_money(highest_bid_);
        highest_bidder_ = &person;
        highest_bid_ = money;
        highest_bidder_->remove_money(this->get_highest_bid());
        return true;
    }
    return false;
}
uint Auction::get_highest_bid() const
{
    return highest_bid_;
}

std::string Auction::get_nft_name() const
{
    return *nft_;
}
