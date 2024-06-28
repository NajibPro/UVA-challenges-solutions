#include <iostream>
#include <cstring>
#include <bitset>
#include <fstream>

using namespace std;

const int maxSize = 1000000;

bitset<maxSize> calender;

int main(){

    int n, m;

    while(cin>>n>>m && !(n == 0 && m == 0)){
        calender.reset();

        pair<int, int> constant;
        pair<pair<int, int>, int> repeated;
        bool conflict = false;

        for(int i = 0; i < n; i++){
            cin>>constant.first;
            cin>>constant.second;

            //fill calender array:
            for(int i = constant.first; i < constant.second && !conflict; i++){
                if(calender.test(i)){
                    conflict = true;
                }else{
                    calender.set(i);
                }
            }
        }

        for(int i = 0; i < m; i++){
            cin>>repeated.first.first;
            cin>>repeated.first.second;
            cin>>repeated.second;

            //fill calender array:
            while(repeated.first.first < maxSize && !conflict){
                for(int i = repeated.first.first; i < repeated.first.second && i < maxSize && !conflict; i++){
                    if(calender.test(i)){
                        conflict = true;
                    }else{
                        calender.set(i);
                    }
                }

                repeated.first.first += repeated.second;
                repeated.first.second += repeated.second;
            }
        }

        cout<<(conflict ? "CONFLICT" : "NO CONFLICT")<<endl;

    }
    return 0;
}

// ds 28 solved in 1h (tfnynt nzrb)