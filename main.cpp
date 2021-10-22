#include <iostream>
#include "heritage.hpp"
#include "fibonacci.hpp"



void* operator new(size_t size){
  //std::cout << "allocating: [" << size << "] bytes." << std::endl;
  return malloc(size);
}

void operator delete(void* object, size_t size){
  //std::cout << "deleting: [" << size << "] bytes." << std::endl;
  free(object);
}

void operator delete(void* object) noexcept{
  //std::cout << "deleting: [" << sizeof(object) << "] bytes." << std::endl;
  free(object);
}



int main()
 {

    testHeritage();
    testFibonacci();

    //Const concepts
    int inConstantVariable = 3;
    inConstantVariable=6; //perfectly fine
    const int constantVariable = 6;
    // constantVariable=4; //error as the content of cont shouldn't be changed
    const int* constantPointer = new int;
    //int * const pointerConstant;

    //*constantPointer = 3; // the value of the pointer content can't be changed
    constantPointer = &constantVariable; // but the pointer itself can be redirected



    //tenary operations
    int ternaryInt = 0;
    ternaryInt > 3 ? std::cout << "Print if true" : std::cout << "Print if false";
    std::cout << std::endl;
    //equal to
    if (ternaryInt > 3)
        printf("Print if true");
    else
        printf("Print if false");
    std::cout << std::endl;


    return 0;
}
