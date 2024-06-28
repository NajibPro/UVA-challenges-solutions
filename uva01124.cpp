#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char> solution;
    char c;
    while((c = cin.get()) && !cin.eof()){
        solution.push_back(c);
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i];
    }
    return 0;
}