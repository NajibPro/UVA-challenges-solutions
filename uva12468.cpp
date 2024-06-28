#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, m;

    while(cin>>n>>m && !(n == -1 && m == -1)){
        cout<<min(abs(n - m), 100 - abs(n - m))<<endl;
    }
    
    return 0;
}

// easy+ 15 solved in 6min and 35s