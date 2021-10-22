#include <iostream>
#include <heritage.cpp>
#inlcude <fibonacci.cpp>

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
    ternaryInt > 3 ? printf("Print if true") : printf("Print if false");

    //equal to
    if (ternaryInt > 3)
        printf("Print if true");
    else
        printf("Print if false");


    return 0;
}
