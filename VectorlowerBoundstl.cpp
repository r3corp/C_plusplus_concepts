#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    vector<int> v;
    int queries = 0, count = 0;
    cin >> count;
    for (int i = 0; i < count; i++){
        int item;
        cin >> item;
        v.push_back(item);
    }
    cin >> queries;
    for (int i = 0; i < queries; i++){
        int item = 0;
        cin >> item;
        auto idx = std::lower_bound(v.begin(), v.end(), item);
        //cout <<"item:"<< item  << "  " << idx -v.begin() <<endl; 
        if (*idx == item){ //compara a posição com o item que está procurando
            cout << "Yes " << idx - v.begin() + 1 << endl;
        }else{
            cout << "No " << idx - v.begin() + 1 << endl;
        }
    }
    return 0;
}
