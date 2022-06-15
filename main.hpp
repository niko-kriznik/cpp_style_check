#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

enum ExampleEnum {
  EXAMPLE_NONE,
  EXAMPLE_FOO,
  EXAMPLE_BAR
};

enum class ExampleEnumClass
{
  NONE,
  FOO,
  BAR
};

struct Buffer
{
    Buffer() = default;
    explicit Buffer(uint8_t *const p_data_, size_t size_);

    uint8_t *const p_data = nullptr;
    size_t size = 0U;
};

class ExampleClass
{
  public:
    static std::string s_title;

  public:
    ExampleClass() = default;

    void foo();
    void bar(const Buffer &buffer_);
    constexpr size_t something() const
    {
      return m_something;
    };

  private:
    size_t m_something = 0U;
};
