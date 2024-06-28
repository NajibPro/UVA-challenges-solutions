#include <iostream>
#include <vector>

using namespace std;

int main(){
    int numberOfTests(0);
    cin>>numberOfTests;

    if(!numberOfTests){
        exit(0);
    }

    vector<string> solution;

    while(numberOfTests--){
        int n1(0), n2(0);
        cin>>n1>>n2;
        string op;
        if(n1 > n2){
            op = ">";
        } else if(n1 < n2){
            op = "<";
        } else {
            op = "=";
        }

        solution.push_back(op);
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

    return 0;
}