#include <iostream>

using namespace std;

int main(){
    int testCases;
    string number;

    cin>>testCases;

    while(testCases--){
        cin>>number;

        if(number.size() > 3){
            cout<<3<<endl;
            continue;
        }

        if(number[0] == 'o' || number[0] == 't'){
            cout<<(number[0] == 'o'? 1 : 2)<<endl;
            continue;
        }

        if(number[1] == 'n' || number[1] == 'w'){
            cout<<(number[1] == 'n'? 1 : 2)<<endl;
            continue;
        }

        if(number[2] == 'e' || number[2] == 'o'){
            cout<<(number[2] == 'e'? 1 : 2)<<endl;
            continue;
        }
    }
    
    return 0;
}