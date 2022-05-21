#include "unordered-multimap.hh"

/****************** BASIC FUNCTIONS **********************/
template <typename KeyType, typename ValueType>
void is_there(std::pair<KeyType, ValueType> Pair, const KeyType &key,
              int *res) {}
template <typename KeyType, typename ValueType>
bool UnorderedMultimap<KeyType, ValueType>::empty() const {
  return this->map_.empty();
}

template <typename KeyType, typename ValueType>
unsigned UnorderedMultimap<KeyType, ValueType>::size() const {
  return this->map_.size();
}
template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::clear() {
  this->map_.clear();
}

/*********************** FUNCTIONS **************************/
template <typename KeyType, typename ValueType>
std::pair<typename UnorderedMultimap<KeyType, ValueType>::iterator,
          typename UnorderedMultimap<KeyType, ValueType>::iterator>
UnorderedMultimap<KeyType, ValueType>::equal_range(const KeyType &key) {
  auto map_start = this->map_.end();
  auto map_end = this->map_.end();
  for (unsigned i = 0; i < this->map_.size(); i++) {
    if (this->map_[i].first == key && map_start == this->map_.end())
      map_start = this->map_.begin() + i;
    if (this->map_[i].first == key)
      map_end = this->map_.begin() + i + 1;
  }
  return {map_start, map_end};
}

template <typename KeyType, typename ValueType>
void UnorderedMultimap<KeyType, ValueType>::add(const KeyType &key,
                                                const ValueType &value) {
  this->map_.push_back(std::pair<KeyType, ValueType>{key, value});
}

template <typename KeyType, typename ValueType>
unsigned
UnorderedMultimap<KeyType, ValueType>::count(const KeyType &key) const {
  unsigned count = 0;
  for (auto i : this->map_) {
    if (i.first == key)
      count++;
  }
  return count;
}
