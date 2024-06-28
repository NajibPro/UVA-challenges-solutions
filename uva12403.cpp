#include <iostream>

using namespace std;

int main(){
    int operationsCount(0);

    cin>>operationsCount;

    int total(0), donation(0);
    string operation;

    while(operationsCount--){
        cin>>operation;

        if(operation == "donate"){
            cin>>donation;
            total += donation;
        } else {
            cout<<total<<endl;
        }   
    }
    
    return 0;
}