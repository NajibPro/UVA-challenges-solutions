#include <iostream>

using namespace std;

int main(){
    int a, b;

    unsigned long long n;

    cin>>a>>b>>n;

    n %= 5;

    while(!(a == 0 && b == 0 && n == 0)){
        if(n == 0){
            cout<<a<<endl;
        }else if(n == 1){
            cout<<b<<endl;
        }else if(n == 2){
            cout<<(1+b)/a<<endl;
        }else if(n == 3){
            cout<<(1+a+b)/(b*a)<<endl;
        }else{
            cout<<(1+a)/b<<endl;
        }

        cin>>a>>b>>n;

        n %= 5;
    }

    
}

// easy+ 13 this challenge was a little bit tricky and I didn't get the correct formula
// because of a calculation mistake in paper