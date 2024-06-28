#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;

struct Graph{
    int size;
    unordered_map<char, set<char>> dic;
   set<char> awake;

    Graph(int s){
        size = s;
    }

    Graph(){

    }

    void addEdge(char u, char v){
        if(dic.find(u) == dic.end()){
            set<char> c;
            c.insert(v);
            dic[u] = c;
        }else{
            dic[u].insert(v);
        }

        if(dic.find(v) == dic.end()){
            set<char> c;
            c.insert(u);
            dic[v] = c;
        }else{
            dic[v].insert(u); 
        }
        
        
    }

    int awakeNeighbors(char u){
        int res(0);
        set<char> s = dic[u];

        for(auto it = s.begin(); it != s.end(); it++){
            if(awake.find(*it) != awake.end()){
                res++;
            }
        }

        return res;
    }

};

int main(){
    int slept;
    while (cin>>slept){
        int connections, years(0);

        cin>>connections;

        Graph g = Graph(slept);

        string letters;
        cin>>letters;

        for(int i = 0; i < letters.size(); i++){
            g.awake.insert(letters[i]);
        }

        for(int i = 0; i < connections; i++){
            cin>>letters;
            g.addEdge(letters[0], letters[1]);
        }

        bool change(true);

        while(g.awake.size() != slept && change){
            years++;
            set<char> toWakeUp;

            for(auto it = g.dic.begin(); it != g.dic.end(); it++){
                if(g.awake.find(it->first) != g.awake.end()){
                    continue;
                }

                if(g.awakeNeighbors(it->first) >= 3){
                    toWakeUp.insert(it->first);
                }
            }

            if(toWakeUp.size() == 0){
                change = false;
                break;
            }

            for(auto it = toWakeUp.begin(); it != toWakeUp.end(); it++){
                g.awake.insert(*it);
            }


        }

        if(g.awake.size() != slept){
            cout<<"THIS BRAIN NEVER WAKES UP"<<endl;
        }else{
            cout<<"WAKE UP IN, "<<years<<", YEARS"<<endl;
        }

        
    }
    
    return 0;
}

// ds 14 solved in 1h and 2min (it took me to much time cuz i wrote the solution
// at 3 am :) )