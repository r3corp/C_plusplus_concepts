#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>
#include <map>

//keep track of allocations

void* operator new(size_t size){
  std::cout << "allocating: [" << size << "] bytes." << std::endl;
  return malloc(size);
}

void operator delete(void* object, size_t size){
  std::cout << "deleting: [" << size << "] bytes." << std::endl;
  free(object);
}

void operator delete(void* object) noexcept{
  std::cout << "deleting: [" << sizeof(object) << "] bytes." << std::endl;
  free(object);
}



class TestClass {
  private:
  protected:
    std::string localName;
  public:
    TestClass(){
      std::cout << "TestClass Constructor " << localName << std::endl;
    }
    TestClass( const TestClass& cpObject){
        std::cout << "TestClass Copy Constructor " << localName << std::endl;
    }
    virtual ~TestClass(){
      std::cout << "TestClass Destructor " << localName << std::endl;
    } //call the child classes if accessed by this class descriptor
    void setLocalName(const std::string localNameValue) {
      this->localName = localNameValue;
    }
};

class TestHeritageClass : public TestClass{
  private:
  public:
    TestHeritageClass(){
      std::cout << "TestHeritageClass Constructor " << localName << std::endl;
    }
    TestHeritageClass(const TestHeritageClass& cpObject){
      std::cout << "TestHeritageClass copy Constructor " << localName << std::endl;
    }
    ~TestHeritageClass(){
      std::cout << "TestHeritageClass Destructor " << localName << std::endl;
    }
};



int testHeritage() {
  {
    
    //created on heap
    std::unique_ptr<TestClass> testInstance = std::make_unique<TestHeritageClass>(); //child class created and accessed by the top clas
    std::cout << "Begin Moving" << std::endl;
    std::unique_ptr<TestClass> testCopyInstance = std::move(testInstance);
    std::cout << "End Moving" << std::endl;
    testCopyInstance->setLocalName("Unique");
    std::shared_ptr<TestClass> testSharedInstance = std::make_shared<TestHeritageClass>();
    TestClass copyTesting = *testSharedInstance;
    copyTesting.setLocalName("Copy Test");
    std::shared_ptr<TestClass> testCopySharedInstance = testSharedInstance;
    testSharedInstance->setLocalName("Unique");
    std::cout << "Destroing" << std::endl;
  }
}