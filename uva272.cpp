#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<char> solution;

    char c;
    bool even = true;

    while((c = cin.get()) && !cin.eof()){
        if(c == '\"'){
            if(even){
                solution.push_back('`');
                solution.push_back('`');
            } else {
                solution.push_back('\'');
                solution.push_back('\'');
            }

            even = !even;
            
        } else {
            solution.push_back(c);
        }
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i];
    }

    return 0;
}