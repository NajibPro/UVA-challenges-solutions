#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> solution;
    int testCases, counter(1);

    cin>>testCases;

    while(testCases--){
        int s, t, u;
        int staying;
        cin>>s>>t>>u;

        if((s >= t && t >= u) || (u >= t && t >= s)){
            staying = t;
        } else if((s >= u && u >= t) || (t >= u && u >= s)){
            staying = u;
        } else {
            staying = s;
        }

        solution.push_back("Case " + to_string(counter++) + ": " + to_string(staying));
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }
}