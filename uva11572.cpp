#include <iostream>
#include <set>

using namespace std;

int main(){
    int t;

    cin>>t;

    while(t--){
        int n, maxUnique(0);
        set<int> snowFlackes;
        cin>>n;

        int order[n];

        for(int i = 0; i < n; i++){
            cin>>order[i];
        }

        if(n == 1){
            cout<<1<<endl;
            continue;
        }

        int start(0), end(1);
        snowFlackes.insert(order[start]);

        while(end < n){
            if(snowFlackes.find(order[end]) == snowFlackes.end()){
                snowFlackes.insert(order[end]);
                end++;
            }else{
                if(maxUnique < snowFlackes.size()){
                    maxUnique = snowFlackes.size();
                }

                while(order[start] != order[end]){
                    snowFlackes.erase(order[start]);
                    start++;
                }

                if(start == end){
                    end++;
                    snowFlackes.insert(order[start]);
                }else{
                    start++; end++;
                }
            }
            
        }

        if(maxUnique < snowFlackes.size()){
            maxUnique = snowFlackes.size();
        }

        cout<<maxUnique<<endl;
    }
}

//ds 26 solved in 46 min