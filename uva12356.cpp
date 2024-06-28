#include <iostream>
#include <bitset>

using namespace std;

int main(){
    int s, b;


    while(cin>>s>>b && !(s == 0 && b == 0)){
        pair<int, int> buddies[s+2];

        buddies[0] = {-1, 1};
        buddies[s+1] = {s, -1};

        if(s == 1){
            buddies[1] = {-1, -1};
        }else{
            for(int i = 1; i < s+1; i++){
                /*if(i == 1){
                    buddies[i] = {-1, i+1};
                    continue;
                }

                if(i == s){
                    buddies[i] = {i-1, -1};
                    continue;
                }*/

                buddies[i] = {i-1, i+1};
            }
        }

        
        for(int i = 0; i < b; i++){
            int l, r;
            cin>>l>>r;

            //buddies[l-1].second = buddies[r].second;
            buddies[buddies[l].first].second = buddies[r].second;
            //buddies[r+1].first = buddies[l].first;
            buddies[buddies[r].second].first = buddies[l].first;

            cout<<(buddies[buddies[r].second].first < 1 || buddies[buddies[r].second].first > s ? "*" : to_string(buddies[buddies[r].second].first))<<" "<<(buddies[buddies[l].first].second < 1 || buddies[buddies[l].first].second > s ? "*" : to_string(buddies[buddies[l].first].second))<<endl;
        }

        cout<<"-"<<endl;
    }
}