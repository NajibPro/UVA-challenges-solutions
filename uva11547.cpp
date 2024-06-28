#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

int main(){
    int testCases;
    vector<int> solution;

    cin>>testCases;

    while(testCases--){
        int n, answerNumber, answerDigit;
        cin>>n;

        answerNumber = (((((n * 567) / 9) + 7492) * 235) / 47) - 498;
        answerDigit = abs(((answerNumber % 100) - (answerNumber % 10)) / 10);

        solution.push_back(answerDigit);
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

    return 0;
}