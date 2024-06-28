#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int pgcd(int n, int m){
    return 1;
}

struct Query{
    int id;
    int period;

    Query(int i, int p){
        id = i;
        period = p;
    }

    Query(){

    }
};

int main(){
    vector<Query> q;

    string s;

    while(cin>>s && s != "#"){
        Query r;
        cin>>r.id>>r.period;

        q.push_back(r);
    }

    int n;

    cin>>n;

    int pg(q[0].period);

    for(int i = 1; i < q.size(); i++){
        pg = pgcd(pg, q[i].period);
    }

    //now start the time
    int counter(0);
    int time(1);
    priority_queue<int> toPrint;
    

    while(counter != n){
        for(int i = 0; i < q.size(); i++){
            if(time % q[i].period == 0){
                toPrint.push(-q[i].id);
                counter++;
                if(counter == n){
                    break;
                }
            }
        }

        time += pg;

        while(!toPrint.empty()){
            cout<<-toPrint.top()<<endl;
            toPrint.pop();
        }
    }
    return 0;
}

// ds 9 solved in 47min and 48sec