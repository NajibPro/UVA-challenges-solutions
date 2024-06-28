#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int b, n;
    while(cin>>b>>n && b != 0 && n != 0){
        int recovery[b], depth[b];

        memset(depth, 0, sizeof(depth));
        for(int i = 0; i < b; i++){
            cin>>recovery[i];

            depth[i] = -recovery[i];
        }

        for(int i = 0; i < n; i++){
            int d, c, v;
            cin>>d>>c>>v;

            depth[d-1] += v;
            depth[c-1] -= v;
        }

        bool needBailout = false;

        for(int i = 0; i < b; i++){
            if(depth[i] > 0){
                needBailout = true;
                break;
            }
        }

        cout<<(needBailout ? "N" : "S")<<endl;

    }
    return 0;
}

// easy+ 7 solved in 11min and 13s (i counted only the time of writing the code since comprehension took a lot of time)
// the challenge was talking about banks and it has a lot of terminologies that i don't understand so i looked up in
// the internet to understand and that took me a lot of time