#include "main.hpp"

#include <cstring> // `memset`
#include <iostream>
#include <vector>

// Class static
std::string ExampleClass::s_title = "Test";

// Global
auto g_index = 0U;
// File-scope global
[[maybe_unused]] static auto g_foo = 100ULL;
namespace {
// File-scope global (implicit `static`)
[[maybe_unused]] auto g_foo2 = 1U;
} // namespace

Buffer::Buffer(uint8_t *const p_data_, size_t size_) : p_data(p_data_), size(size_)
{
}

void ExampleClass::foo()
{
  [[maybe_unused]] static size_t prev_value = 0U;
  prev_value = m_something;
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

  const std::vector<int> items = {10, 20, 13, 23, 24, 1, 23};
  uint64_t snail = 0U;
  for (const auto &item : items)
  {
    snail |= item;
  }

  const auto *const p_snail = &snail;
  std::cout << "Snail (" << p_snail << "): " << snail << '\n';

  return 0;
}