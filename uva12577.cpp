#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> solution;
    int counter(1);
    string name;

    while(cin>>name && name != "*"){
        solution.push_back("Case " + to_string(counter++) + ": " + (name == "Hajj" ? "Hajj-e-Akbar" : "Hajj-e-Asghar"));
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }
}