#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include </usr/include/boost/format>
#include <source_location>
#include <compare>
#include <concepts>
#include <span>
#include <chrono>

//###385


//Designated initializers
struct one3{
    int i;
    int h;
    float f;
    constexpr auto operator<=>(const one3&) const  = default;
};

void des_init(){
    one3 s{.i=2, .h=33, .f = 33.3f};
    //one3 d{.h=33, .i=2, .f = 33.3f};//out of order #compilation error
    one3 d{.i=2, .f = 33.3f};//missing members
}
// 3 way comparison

struct one{
    int i;
    int h;
    constexpr auto operator<=>(const one&) const  = default;
};
bool compare(one lhs, one rhs){
    return lhs < rhs;
}

//modules
//coroutines
//concepts/auto concepts
auto function(std::integral auto i) {
  //só aceita valores integrais int, long, short, char, size_t
    std::cout << "Integral: " << i << '\n';
}



//this creates a template automatically 
auto process ( auto first, auto second){
  return first < second;
}
//format
auto makelog(std::string_view str){
  //kinda like python string format
    return std::format("{}", str);
}
//source location
auto log(std::source_location loc = std::source_location::current()){
    return std::format("File: {}, Line: {}, Function: {}", loc.file_name(), loc.line(), loc.function_name());
}

//calendar updates to chrono

//ranges
void use_ranges(){
  std::vector<int> v{1,2,3,4,5,6,7,8,9,10};
  auto view = v | std::views::filter([](int i){return i%2 == 0;}); //filtra só pares
  for(auto i : view | std::views::drop(1)){
      std::cout << i << " ";
  }
  std::cout << "\n";
}

//constexpr now any code can work at compile time

//span
void use_span(){
  std::array<int, 5> arr = {1,2,3,4,5};
  std::span<int> sp(arr.data(), arr.size());
  for(auto i : sp){
      std::cout << i << " ";
  }
  std::cout << "\n";
}


//thread updates
//std::jthread thread with support to automatic joining and cancellation
void use_jthread(){
  std::jthread t([]{
      std::cout << "Hello from jthread\n";
  });
  //t.join(); //no need to join, jthread does it automatically
}

int main(){

    std::source_location::current().function_name();
}