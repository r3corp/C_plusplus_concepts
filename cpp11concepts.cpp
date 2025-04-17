#include <memory>
#include <algorithm>
#include <vector>

//auto
template<typename T>
void contador(const T &vec, int value)
{
   const auto contagem = std::count(vec.begin(), vec.end(), value);
}

//ranged - for 
template<typename T>
void to_stuff(const T &item_list)
{
    for(const auto elem : item_list)
    {
        //do something
    }
}

//lambdas
template<typename T>
void contadero(const T &vec, int value)
{
   const auto contagem = std::count(vec.begin(), vec.end(), 
    [=](int i){ return i < value;}
   );
}

//variatic template
template<typename Func, typename ... T>
void call( const Func &function, const T & ... param )
{
    function(param ...);
}

//unique_ptr
void allocate()
{
    std::unique_ptr<int> ptr(new int(5));
}//freed when going out of scope

//constexpr  ##limited
