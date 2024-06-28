#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int to_int(string number){
    int value(0);
    for(int i = 0, j = number.size() - 1; i < number.size(); i++, j--){
        value += (number[j] - '0') * pow(10, i);
    }

    return value;
}

class UFDS{
    vector<int> parent;

    public:

    UFDS(int size){
        parent.assign(size, -1);
    }

    int findGrandParent(int x){
        if(parent[x] < 0){
            return x;
        }

        parent[x] = findGrandParent(parent[x]);

        return parent[x];
    }

    void unit(int x, int y){
        int xParent = findGrandParent(x), yParent = findGrandParent(y);

        if(xParent == yParent){
            return;
        }

        int biggerParent = parent[xParent] > parent[yParent] ? yParent : xParent,
        smallerParent = parent[xParent] <= parent[yParent] ? yParent : xParent;

        int unionNegativeSize = parent[xParent] + parent[yParent];

        parent[biggerParent] = unionNegativeSize;

        parent[smallerParent] = biggerParent;
    }

    bool isConnected(int x, int y){
        return findGrandParent(x) == findGrandParent(y);
    }

    int getSetSize(int x){
        if(parent[x] < 0){
            return -parent[x];
        }

        return getSetSize(parent[x]);
    }

    void printArray(){
        for(int i = 0; i < parent.size(); i++){
            cout<<parent[i]<<"\t";
            if(i == parent.size() - 1){
                cout<<endl;
            }
        }
    }
};

int main(){
    int tc;
    string type;
    int computers;
    int counter(0);

    cin>>tc;
    cin.ignore();

    while(tc--){
        

        if(counter == 0){
            cin>>computers;
            counter++;
        }else{
            computers = to_int(type);
        }
        

        UFDS network = UFDS(computers+1);

        
        int edgel, edger;
        int good(0), bad(0);

        while(cin>>type && (type == "c" || type == "q") && !cin.eof()){
            cin>>edgel>>edger;

            if(type == "c"){
                network.unit(edgel, edger);
            }else if(type == "q"){
                if(network.isConnected(edgel, edger)){
                    good++;
                }else{
                    bad++;
                }
            }
        }

        cout<<good<<","<<bad<<endl;

        if(tc != 0){
            cout<<endl;
        }
    }
    return 0;
}

// med 6 didnt count time i was too lazy to do that