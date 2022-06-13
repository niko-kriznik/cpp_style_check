#include "main.hpp"

#include <cstring> // `memset`
#include <iostream>

Buffer::Buffer(uint8_t *const p_data_, size_t size_) : p_data(p_data_), size(size_)
{
}

void ExampleClass::foo()
{
  ++m_something;
}

void ExampleClass::bar(const Buffer &buffer_)
{
  m_something = buffer_.size;
}

int main(int, char **)
{
  static constexpr auto DATA_SIZE = 16U;
  uint8_t data[DATA_SIZE];
  memset(&data[0], 0, DATA_SIZE);

  const auto buffer = Buffer(&data[0], DATA_SIZE);

  auto example = ExampleClass();
  example.foo();
  example.bar(buffer);

  return 0;
}