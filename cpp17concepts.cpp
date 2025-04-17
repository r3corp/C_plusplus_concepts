#include <memory>
#include <string_view>
#include <array>


//###190

//cpp 17
//guaranteed copy / move elision
auto factory(){
  return std::make_unique<int>();
}

void main_tega()
{
  auto widgget = factory();
}

//constexpr
//constexpr lambdas
//string_view
//Class Template Argument Deduction
std::array<int,5> data{1,2,3,4,5}; //before c++11
std::array moredata {1,2,3,4,5};

//fold expressions
template<typename ... T>
auto add(const T & ... param){
  return (param + ...);
}
int main(){
  return add(1,2,3,4,5);
}
//structured bindings
std::pair<int,int> value{1,2};
auto [first, second] = value;

//if-init expressions
void func(){
  if (auto [one, two] = value; one < 5){}
}