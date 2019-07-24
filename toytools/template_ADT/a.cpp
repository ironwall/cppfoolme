#include <iostream>
#include <string>
#include <utility>
using namespace std;
template <char... chars>
using stream = std::integer_sequence<char, chars...>;
template <typename T, T... chars>
constexpr stream<chars...> operator""_stream() { return { }; }
int main()
{
  using hello_world = decltype("Hello world!"_stream);
}
