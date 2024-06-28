#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

bool isPrime(int number){
    if(number == 1 || number == 0){
        return false;
    }

    if(number == 2){
        return true;
    }

    if(number % 2 == 0){
        return false;
    }

    int possibleDevider = sqrt(number);

    for(int i = 2; i <= possibleDevider; i++){
        if(number % i == 0){
            return false;
        }
    }

    return true;
}

bool primeRing(vector<int> ring, int size){
    if(ring.size() == 1){
        return true;
    }

    for(int i = 0; i < ring.size() - 1; i++){
        if(!isPrime(ring[i] + ring[i+1])){
            return false;
        }
    }

    if(ring.size() == size && !isPrime(ring[0] + ring[ring.size() - 1])){
        return false;
    }

    return true;
}

void backtrack(vector<int> ring, int size, vector<vector<int>>& solutions){
    if(!primeRing(ring, size)){
        return;
    }

    if(ring.size() == size){
        solutions.push_back(ring);
        return;
    }

    for(int i = 2; i <= size; i++){
        auto it = find(ring.begin(), ring.end(), i);

        if(it == ring.end()){
            ring.push_back(i);
            backtrack(ring, size, solutions);
            ring.pop_back();
        }
    }
}

int main(){
    int n, counter(0);

    while(cin>>n){
        if(counter != 0){
            cout<<endl;
        }

        vector<int> ring = {1};
        vector<vector<int>> solutions;
        backtrack(ring, n, solutions);

        cout<<"Case "<<++counter<<":"<<endl;
        for(int i = 0; i < solutions.size(); i++){
            for(int j = 0; j < solutions[i].size(); j++){
                cout<<solutions[i][j];

                if(j == solutions[i].size() - 1){
                    cout<<endl;
                }else{
                    cout<<" ";
                }
            }
        }
    }
}