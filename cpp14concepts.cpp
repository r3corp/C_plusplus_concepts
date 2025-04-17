#include <algorithm>
#include <memory>

//auto with return type deduction
template<typename T>
auto contador(const T &vec, int value)
{
   const auto contagem = std::count(vec.begin(), vec.end(), value);
   return contagem;
}

//lambdas - generic
template<typename T>
auto contadero(const T &vec, int value)
{
   const auto contagem = std::count(vec.begin(), vec.end(), 
    [](const auto i){ return i < 3;}
   );
   return contagem;
}

//lambdas - generalized capture method
template<typename T>
auto contadero_cpp14(const T &vec, int value)
{
   const auto contagem = std::count(vec.begin(), vec.end(), 
    [value = [](){ return 3;}()](const auto i){ return i < value;}
   );
   return contagem;
}

//make_unique
void allocate()
{
    std::unique_ptr<int> ptr(new int(5)); //instead of doing this 
    auto ptru{std::make_unique<int>(5)};//can do this

}//freed when going out of scope

//constexpr more flexible
constexpr int get_value()
{
    int val = 1;
    int ted = 1;
    return val + ted;
}
