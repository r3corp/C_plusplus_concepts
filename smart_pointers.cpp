#include <memory>
#include <iostream>


struct B; // Forward declaration

struct A {
  std::weak_ptr<B> b_ptr;  // A holds shared_ptr to B
  //std::shared_ptr<B> b_ptr;  // A holds shared_ptr to B
  ~A() { std::cout << "A destroyed\n"; }
};

struct B {
    //the weekptr will not increment the ref counter 
    std::weak_ptr<A> a_ptr;  // B holds shared_ptr to A
    //std::shared_ptr<A> a_ptr;  // B holds shared_ptr to A
    ~B() { std::cout << "B destroyed\n"; }
};



//memory leak com referencia circular
int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();

    a->b_ptr = b;  // A -> B
    b->a_ptr = a;  // B -> A (circular reference!)

    std::cout << "Exiting main...\n";
    return 0;
}