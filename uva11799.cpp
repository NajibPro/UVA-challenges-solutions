#include <iostream>

using namespace std;

int main(){
    int testCases;
    int counter(1);
    cin>>testCases;

    while(testCases--){
        int gosts, maxSpeed(-1), speed;
        cin>>gosts;

        for(int i = 0; i < gosts; i++){
            cin>>speed;

            if(speed > maxSpeed){
                maxSpeed = speed;
            }
        }

        cout<<"Case "<<counter++<<": "<<maxSpeed<<endl;
    }
}

// easy+ 10 solved in 6 min and 46 seconds