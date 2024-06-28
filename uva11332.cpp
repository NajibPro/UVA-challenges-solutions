#include <iostream>

using namespace std;

int g(string n){
    int sum(0);
    bool stop = false;

    while(!stop){
        for(int i = 0; i < n.size(); i++){
            sum += (n[i] - '0');
        }

        if(sum < 10){
            stop = true;
        }else {
            n = to_string(sum);
            sum = 0;
        }
    }

    return sum;
}

int main(){
    string number;

    while(cin>>number && number != "0"){
        cout<<g(number)<<endl;
    }
    return 0;
}

// easy+ 5 solved in 12min and 12s (it took me a long time because i forgot about adding line 18 before :) )