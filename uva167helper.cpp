#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iomanip>
#include <fstream>

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
    ofstream fout("result.txt");
        
        int positions[8] = {0, 1, 2, 3, 4, 5, 6, 7};

        do{
            if(valid(positions)){
                for(int i = 0; i < 8; i++){
                    fout<<positions[i];
                    if(i != 7){
                        fout<<" ";
                    }else{
                        fout<<endl;
                    }
                }
            }
        }while(next_permutation(positions, positions + 8));
}