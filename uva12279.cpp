#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> solution;
    int counter(1), n;

    while(cin>>n && n != 0){
        int emoogleBalance(0), number;

        for(int i = 0; i < n; i++){
            cin>>number;

            if(number){
                emoogleBalance++;
            }else{
                emoogleBalance--;
            }
        }

        solution.push_back("Case " + to_string(counter++) + ": " + to_string(emoogleBalance));
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }
}