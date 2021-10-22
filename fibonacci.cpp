#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>
#include <map>

int fibonacci(int number, std::shared_ptr<std::map<int,int>> memo =  std::make_shared<std::map<int,int>>()){
  std::cout << "MEMO:[" << sizeof(*memo) + sizeof(memo) << "]" << std::endl;
  std::cout << "number:[" << sizeof(number) << "]" << std::endl;
  if ( ( number == 2 ) || ( number == 1 ) )
    return 1;
  auto item = memo->find(number);
  if (item != memo->cend())
    return item->second;
  memo->emplace(number, fibonacci(number-1, memo) + fibonacci(number-2, memo) );
  std::cout << "memosize:[" << memo->size() << "]" << std::endl;
  return memo->at(number);
  
}

void testFibonacci()
{
  
    std::cout << fibonacci(5) << std::endl;//701408733
}