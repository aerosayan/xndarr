//-//////////////////////////////////////////////////////////////////////////-//
// @file ndarray.cpp
// @info N dimensional array
// @author Sayan Bhattacharjee
// @date 5-AUG-2019
//-//////////////////////////////////////////////////////////////////////////-//
template<typename T>
xn::ndarray<T>
  ::ndarray() : size_(0)
{

}

template<typename T>
xn::ndarray<T>
  ::ndarray(size_t size)
  : size_(size)
{
  data_.resize(size);
}

template<typename T>
xn::ndarray<T>
  ::ndarray(std::initializer_list<T> data)
  : data_(data)
{
  size_ = data_.size();
}

template<typename T>
size_t
xn::ndarray<T>
  ::size_v()
  const
{
  return size_;
}

template<typename T>
std::vector<T>&
xn::ndarray<T>
  ::data_r()
  const
{
  return data_;
}

template<typename T>
const std::vector<T>&
xn::ndarray<T>
  ::data_cr()
  const
{
  return data_;
}

