#include <iostream>
#include <math.h>
using namespace std;

int to_int(string number){
    int value(0);
    for(int i = 0, j = number.size() - 1; i < number.size(); i++, j--){
        value += (number[j] - '0') * pow(10, i);
    }

    return value;
}

int main(){
    string number;

    while(cin>>number && number != "END"){
        if(number == "1"){
            cout<<"1"<<endl;
            continue;
        }

        if(number.size() == 1){
            cout<<2<<endl;
            continue;
        }



        int xfirst = to_int(number), xSecond = to_string(xfirst).size();
        int counter(1);
        while(xfirst != xSecond){
            counter++;
            xfirst = xSecond;
            xSecond = to_string(xfirst).size();
        }
        
        cout<<counter<<endl;

    }
}

// (mid 4) solved in 33min 24s (i used uDebug :) )