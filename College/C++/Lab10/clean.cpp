void clean() {
  std::size_t newcapacity = capacity;
  for (std::size_t i = capacity; i > 0; --i) {
    if (data_[i - 1] != 0) {
      break;
    }
    --newcapacity;
  }

  std::size_t *temp = new unsigned short[newcapacity];
  for (std::size_t i = 0; i < newcapacity; ++i) {
    temp[i] = data_[i];
  }
  delete [] data_;
  data_ = temp;
  temp = nullptr;
  capacity = newcapacity;

}
