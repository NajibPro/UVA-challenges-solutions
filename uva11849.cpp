#include <iostream>
#include <unordered_map>

using namespace std;

int main(){
    int n, m;
    while(cin>>n>>m && !(n == 0 && m == 0)){
        unordered_map<int, int> cd;
        for(int i = 0; i < n + m; i++){
            int c;
            cin>>c;
            cd[c]++;
        }

        int reps(0);

        for(auto it = cd.begin(); it != cd.end(); it++){
            if(it->second > 1){
                reps++;
            }
        }

        cout<<reps<<endl;
    }
    return 0;
}

//ds 27 solved in 4 min