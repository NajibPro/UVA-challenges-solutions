#include <iostream>
#include <sstream>
#include <bitset>
#include <vector>
#include <set>

using namespace std;

void backtrack(int total, int& maxPossibleSum, vector<int>& number, int index, int currentSum, vector<int> current, vector<int>& solution){
    if(currentSum > total || number.size() < 1){
        return;
    }

    if(currentSum == total){
        solution = current;
        maxPossibleSum = currentSum;
        return;
    }

    if(index < 0){
        if(currentSum >= maxPossibleSum){
            maxPossibleSum = currentSum;
            solution = current;
        }
        return;
    }

    if(currentSum >= maxPossibleSum){
        maxPossibleSum = currentSum;
        solution = current;
    }

    backtrack(total, maxPossibleSum, number, index-1, currentSum, current, solution);
        
    currentSum += number[index];
    current.push_back(number[index]);

    backtrack(total, maxPossibleSum, number, index-1, currentSum, current, solution);
}

int main(){
    string line;

    while(getline(cin>>ws, line)){
        stringstream sin;
        int n, t, num;

        sin<<line;
        sin>>n>>t;
        vector<int> number;

        for(int i = 0; i < t; i++){
            sin>>num;
            number.push_back(num);
        }

        vector<int> solution;
        vector<int> current;
        int maxPossibleSum = 0;
        int sum = 0;
        backtrack(n, maxPossibleSum, number, number.size() - 1, 0, current, solution);

        for(int i = solution.size() - 1; i >= 0; i--){
            cout<<solution[i]<<" ";
            sum += solution[i];
        }

        cout<<"sum:"<<sum<<endl;
    }
}