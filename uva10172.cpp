#include <iostream>
#include <stack>
#include <vector>
#include <queue>

using namespace std;

bool workDone(const vector<queue<int>>& b){
    bool done = true;
    for(int i = 0; i < b.size(); i++){
        if(!b[i].empty()){
            done = false;
            break;
        }
    }

    return done;
}

int main(){
    int set;

    cin>>set;

    while(set--){
        int n, s, q;
        stack<int> c;

        cin>>n>>s>>q;

        vector<queue<int>> b(n);

        for(int i = 0; i < n; i++){
            int cargoes;
            cin>>cargoes;

            while(cargoes--){
                int cargo;
                cin>>cargo;
                b[i].push(cargo-1);
            }
        }

        //starting the simulation
        int time(0);
        int currentStation = 0;
        while(!workDone(b) || !c.empty()){
            if(!(time == 0 && currentStation == 0)){
                time += 2;
            }
            //unload cargos
            //check the stack
            while(!c.empty() && (b[currentStation].size() < q || c.top() == currentStation)){
                if(c.top() == currentStation){
                    c.pop();
                    time++;
                }else if(b[currentStation].size() < q){
                    b[currentStation].push(c.top());
                    c.pop();
                    time++;
                }
            }

            //now time to load
            while(!b[currentStation].empty() && c.size() < s){
                c.push(b[currentStation].front());
                b[currentStation].pop();
                time++;
            }
            



            currentStation = (currentStation + 1) % n;
        }


        std::cout<<time<<endl;
        
    }
    return 0;
}


// ds 11 solved in 1h and 19min and 19sec