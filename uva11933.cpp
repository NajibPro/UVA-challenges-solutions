#include <iostream>
#include <math.h>

using namespace std;

int main(){
    int n;

    while(cin>>n && n != 0){
        int a(0), b(0);
        bool aTurn = true;
        for(int i = 0; n != 0; i++){
            if(n % 2 == 1){
                if(aTurn){
                    a += pow(2, i);
                }else{
                    b += pow(2, i);
                }

                aTurn = !aTurn;
            }

            n /= 2;
        }

        cout<<a<<" "<<b<<endl;
    }
    return 0;
}

// ds 7 solved in 13min and 15sec 