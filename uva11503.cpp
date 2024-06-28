#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

class UFDS{
    
    vector<int> parent;

    public:
    unordered_map<string, int> id;

    UFDS(int size){
        parent.assign(size, -1);
    }

    int cindGrandParent(int x){
        if(parent[x] < 0){
            return x;
        }

        parent[x] = cindGrandParent(parent[x]);

        return parent[x];
    }

    void unit(int x, int y){
        int xParent = cindGrandParent(x), yParent = cindGrandParent(y);

        if(xParent == yParent){
            return;
        }

        int biggerParent = parent[xParent] > parent[yParent] ? yParent : xParent,
        smallerParent = parent[xParent] <= parent[yParent] ? yParent : xParent;

        int unionNegativeSize = parent[xParent] + parent[yParent];

        parent[biggerParent] = unionNegativeSize;

        parent[smallerParent] = biggerParent;
    }

    int getSetSize(int x){
        if(parent[x] < 0){
            return -parent[x];
        }

        return getSetSize(parent[x]);
    }
};

int main(){
    int n, f;
    cin>>n;

    while(n--){
        cin>>f;
        UFDS ufds(2*f);
        int counter(0);

        for(int i = 0; i < f; i++){
            string s, t;
            cin>>s>>t;

            if(ufds.id.find(s) == ufds.id.end()){
                ufds.id[s] = counter++;
            }

            if(ufds.id.find(t) == ufds.id.end()){
                ufds.id[t] = counter++;
            }

            ufds.unit(ufds.id[s], ufds.id[t]);

            cout<<ufds.getSetSize(ufds.id[s])<<endl;
        }
    }
}