#include "fibonacci.hpp"


long long fibonacciddd(long long number, std::map<int,long long> &memo){
  if (number <= 0 )
    return 0;
  if ( ( number == 2 ) || ( number == 1 ) )
    return 1;
  auto item = memo.find(number);
  if (item != memo.end()){
    std::cout << item->second << " found in map" << std::endl;
    return item->second;
  }
  //memo.emplace(number, fibonacciddd(number-1, memo) + fibonacciddd(number-2, memo) );
  memo[number] = fibonacciddd(number - 1, memo) + fibonacciddd(number - 2, memo);
  return memo[number];
  
}
long long fibonacci(int number, std::shared_ptr<std::map<int,long long>> memo =  std::make_shared<std::map<int,long long>>()){
  if ( ( number == 2 ) || ( number == 1 ) )
    return 1;
  auto item = memo->find(number);
  if (item != memo->cend())
    return item->second;
  memo->emplace(number, fibonacci(number-1, memo) + fibonacci(number-2, memo) );
  return memo->at(number);
  
}

int main()
{
    std::map<int,long long> amemo;
  
    std::cout << fibonacci(55) << std::endl;//139583862445
    std::cout << fibonacciddd(55, amemo) << std::endl;//139583862445

    return 0;
}
