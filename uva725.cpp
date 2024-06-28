#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

bool correct(int abcde, int fghij){
    if(abcde < 100000 && abcde >= 1234 && fghij < 100000 && fghij >= 1234){
        string digits = to_string(abcde) + to_string(fghij);

        sort(digits.begin(), digits.end());

        if(digits == "123456789" || digits == "0123456789"){
            return true;
        }
    }

    return false;
}

int main(){
    int n;
    bool first = true;

    while(cin>>n && n != 0){

        if(first){
            first = false;
        }else{
            cout<<endl;
        }

        bool solution = false;

        int abcde(0);

        for(int fghij = 1234; fghij < 100000; fghij++){
            abcde = fghij * n;

            if(correct(abcde, fghij)){
                solution = true;
                cout<<abcde<<" / "<<setw(5)<<setfill('0')<<fghij<<" = "<<n<<endl;
            }
        }

        if(!solution){
            cout<<"There are no solutions for "<<n<<"."<<endl;
        }
    }
    return 0;
}