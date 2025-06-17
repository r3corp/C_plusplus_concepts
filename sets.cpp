#include <cmath>
#include <cstdio>
#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    std::set<int> s;
    int queries= 0;
    cin >> queries;
    for (int i = 0; i < queries; i ++){
        int op, val;
        cin >> op >> val;
        if (op == 1){
            s.insert(val);
        }
        if (op == 2){
            s.erase(val);
        }
        if (op == 3){
            if (s.find(val)!= s.end())
                cout << "Yes" << endl;
            else
                cout << "No" << endl;
        }
    }
    return 0;
}
