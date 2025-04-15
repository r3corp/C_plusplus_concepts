#include <iostream>
#include <memory>
#include <ranges>
#include <string>
#include <format.h>
#include <source_location>

//modules
//coroutines
//concepts/auto concepts
auto process ( auto first, auto second){
  return first < second;
}
//format
//source location
//calendar updates to chrono




int main(){

    std::source_location::current().function_name();
}