#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    int numberOfTests(0);
    cin>>numberOfTests;

    if(!numberOfTests){
        exit(0);
    }

    vector<int> solution;

    while(numberOfTests--){
        int rows(0), columns(0);
        cin>>rows>>columns;

        solution.push_back((rows / 3) * (columns / 3));
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

    return 0;
}