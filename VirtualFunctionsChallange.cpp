#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Person{
protected:
    std::string name;
    int age;
public:
    virtual void getdata() = 0;
    virtual void putdata() = 0;
};
class Professor : public Person{
    int publications;
    int cur_id;
    public:
    static int id;
    Professor () {
        this->cur_id = ++Professor::id;
    }
    void getdata() override { 
        std::cin >> name >> age >> publications;
    }
    void putdata() override { 
        std::cout << this->name << " " <<  this->age << " " <<  this->publications << " " <<  this->cur_id << std::endl;
    }
};
int Professor::id = 0;
class Student : public Person{
    std::vector<int> marks;
    int cur_id;
    public:
    static int id;
    Student () {
        this->cur_id = ++Student::id;
    }
    void getdata() {
        std::cin >> name >> age;
        for (int i = 0 ; i < 6; i ++){
            int mark;
            std::cin >> mark;
            this->marks.push_back(mark);
        }
    }
    void putdata(){ 
        std::cout << this->name << " " <<  this->age;
        int sum = 0;
        for (int mark : marks)
            sum += mark;
        cout << " " << sum << " "  << this->cur_id << std::endl;
    }
};
int Student::id = 0;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

    return 0;

}

/*
4
1
Walter 56 99
2
Jesse 18 50 48 97 76 34 98
2
Pinkman 22 10 12 0 18 45 50
1
White 58 87
*/