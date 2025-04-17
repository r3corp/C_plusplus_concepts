#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include <format.h>
#include <source_location>
#include <compare>

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

//this creates a template automatically 
auto process ( auto first, auto second){
  return first < second;
}
//format
//source location
//calendar updates to chrono




int main(){

    std::source_location::current().function_name();
}