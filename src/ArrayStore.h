#pragma once

#include <cassert>
#include <unordered_set>
#include <vector>

using namespace std;

template <typename T> class ArrayStore {

public:
  ArrayStore();
  ArrayStore(const int initial_size);
  ArrayStore(const int initial_size, const bool debug);
  size_t alloc();
  void free(size_t i);
  T &operator[](size_t i);
  size_t size() const;
  size_t capacity() const;

private:
  void grow_to(size_t n);
  void debug_check_valid(size_t i);

  union T_or_next {
    T as_T;
    size_t as_next;
  };

  vector<T_or_next> data_;
  unordered_set<size_t> debug_valid_indices_;
  size_t next_free_;
  size_t size_;
  const bool debug_;
};

template <typename T>
ArrayStore<T>::ArrayStore()
    : data_(), debug_valid_indices_(), next_free_(0), size_(0), debug_(false) {}

template <typename T>
ArrayStore<T>::ArrayStore(const int initial_size)
    : data_(), debug_valid_indices_(), next_free_(0), size_(0), debug_(false) {
  grow_to(initial_size);
}

template <typename T>
ArrayStore<T>::ArrayStore(const int initial_size, const bool debug)
    : data_(), debug_valid_indices_(), next_free_(0), size_(0), debug_(debug) {
  grow_to(initial_size);
}

template <typename T> void ArrayStore<T>::grow_to(size_t n) {
  assert(n > data_.size());
  size_t old_size = data_.size();
  data_.resize(n);
  for (size_t i = old_size; i < data_.size(); i++)
    data_[i].as_next = i + 1;
}

template <typename T> void ArrayStore<T>::debug_check_valid(size_t i) {
  if (debug_ && debug_valid_indices_.count(i) == 0)
    throw std::runtime_error("Index " + to_string(i) + " is not valid.");
}

template <typename T> size_t ArrayStore<T>::alloc() {
  if (next_free_ >= data_.size()) {
    grow_to(next_free_ + 1);
  }
  size_++;
  size_t ret = next_free_;
  next_free_ = data_[next_free_].as_next;
  if (debug_)
    debug_valid_indices_.insert(ret);
  return ret;
}

template <typename T> void ArrayStore<T>::free(const size_t i) {
  assert(0 <= i && i < data_.size());
  debug_check_valid(i);
  data_[i].as_next = next_free_;
  next_free_ = i;
  size_--;
  if (debug_)
    debug_valid_indices_.erase(i);
}

template <typename T> T &ArrayStore<T>::operator[](const size_t i) {
  debug_check_valid(i);
  return data_[i].as_T;
}

template <typename T> size_t ArrayStore<T>::size() const { return size_; }

template <typename T> size_t ArrayStore<T>::capacity() const {
  return data_.size();
}
