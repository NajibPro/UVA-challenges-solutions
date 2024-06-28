#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <unordered_map>
#include <bitset>
#include <fstream>


using namespace std;

struct Graph{
    unordered_map<int, set<int>> dic;

    Graph(){
    }

    void addEdge(int u, int v){
        dic[u].insert(v);
        dic[v].insert(u); 
    }

};

void backtrack(int index, int n, Graph& g, set<int> currentBlack, set<int>& bestBlack){
    //the end of backtracking
    if(index == n+1){
        if(currentBlack.size() > bestBlack.size()){
            bestBlack = currentBlack;
        }
        return;
    }

    //try to make node with the number index black
    bool canBeBlack = true;
    set<int> neighbors = g.dic[index];

    for(auto it = neighbors.begin(); it != neighbors.end(); it++){
        if(currentBlack.find(*it) != currentBlack.end()){
            canBeBlack = false;
        }
    }

    if(canBeBlack){
        currentBlack.insert(index);
        if(currentBlack.size() > bestBlack.size()){
            bestBlack = currentBlack;
        }
        backtrack(index + 1, n, g, currentBlack, bestBlack);
    }

    //try to make node with the number index white
    if(canBeBlack) currentBlack.erase(index);
    backtrack(index + 1, n, g, currentBlack, bestBlack);
}

int main(){
    int m;
    cin>>m;

    while(m--){
        int n, k;
        cin>>n>>k;
        Graph g;

        for(int i = 0; i < k; i++){
            int a, b;
            cin>>a>>b;

            g.addEdge(a, b);
        }

        set<int> currentBlack, bestBlack; int counter;
        backtrack(1, n, g, currentBlack, bestBlack);

        counter = bestBlack.size();

        cout<<counter<<endl;
        for(auto it = bestBlack.begin(); it != bestBlack.end(); it++){
            cout<<*it;
            counter--;

            if(counter == 0){
                cout<<endl;
            }else{
                cout<<" ";
            }
        }
    }
}