#include "fibonacci.hpp"

int fibonacci(int number, std::shared_ptr<std::map<int,int>> memo =  std::make_shared<std::map<int,int>>()){
  if ( ( number == 2 ) || ( number == 1 ) )
    return 1;
  auto item = memo->find(number);
  if (item != memo->cend())
    return item->second;
  memo->emplace(number, fibonacci(number-1, memo) + fibonacci(number-2, memo) );
  return memo->at(number);
  
}

void testFibonacci()
{
  
    std::cout << fibonacci(55) << std::endl;//701408733
}