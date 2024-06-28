#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

int valid(int positions[]){
    for(int i = 0; i < 8; i++){
        for(int j = i+1; j < 8; j++){
            if(abs(i - j) == abs(positions[i] - positions[j])){
                return false;
            }
        }
    }

    return true;
}

int main(){
    int n;

    cin>>n;

    while(n--){
        int ir, ic, counter(0);

        cin>>ir>>ic;

        cout<<"SOLN       COLUMN\n #      1 2 3 4 5 6 7 8\n"<<endl;
        

        //start backtracking
        int positions[8] = {0, 1, 2, 3, 4, 5, 6, 7};

        do{
            if(positions[ic-1] != ir-1){
                continue;
            }

            if(valid(positions)){
                cout<<setw(2)<<setfill(' ')<<++counter<<"      ";
                for(int i = 0; i < 8; i++){
                    cout<<positions[i]+1;
                    if(i != 7){
                        cout<<" ";
                    }else{
                        cout<<endl;
                    }
                }
            }
        }while(next_permutation(positions, positions + 8));

        if(n != 0){
            cout<<endl;
        }
    }
    return 0;
}