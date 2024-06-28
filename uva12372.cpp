#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> solution;
    int counter(1), testCases;
    int l, w, h;

    cin>>testCases;

    while(testCases--){
        cin>>l>>w>>h;
        solution.push_back("Case " + to_string(counter++) + ": " + ((l <= 20 && w <= 20 && h <= 20) ? "good" : "bad"));
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }
}