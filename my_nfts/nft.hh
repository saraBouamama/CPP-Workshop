#pragma once

#include <memory>

// NFT declaration
using NFT = std::unique_ptr<std::string>;

// Create an empty NFT (convient in some scenarios).
inline NFT create_empty_nft();
// Create a NFT with the given name.
inline NFT create_nft(const std::string& name);

// Define the functions in the nft.hxx file.
#include "nft.hxx"