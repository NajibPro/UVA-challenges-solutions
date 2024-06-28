#include <iostream>
#include <cstring>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_map>

using namespace std;

struct Contestent{
    bool solved[10];
    int id;
    int time;

    Contestent(int i, int t, int p = 0){
        id = i;
        time = t;
        memset(solved, false, sizeof(solved));
        solved[p] = true;
    }

    Contestent(){
        memset(solved, false, sizeof(solved));
    }

    int completed(){
        int res(0);
        for(int i = 1; i < 10; i++){
            if(solved[i]){
                res++;
            }
        }

        return res;
    }
};

unordered_map<int, Contestent> contestents;

void addTime(int c, int p, int t, char l){
    switch (l)
    {
    case 'C':

        contestents[c].time += t;
        break;

    case 'I':
        if(contestents[c].solved[p] == true){
            contestents[c].time += 20;
        }
        break;
    
    
    default:

        break;
    }
}

int main(){
    int tc;

    cin>>tc;
    cin.ignore();
    cin.ignore();

    while(tc--){
        
        vector<int> cList, pList, tList; 
        vector<char> lList;
        string line;
        int c, p, t;
        char l;
        while(getline(cin, line) && !cin.eof() && !line.empty() && !all_of(line.begin(), line.end(), [](char c) { return std::isspace(c); })){
            istringstream ss(line);
            ss>>c>>p>>t>>l;

            auto it = contestents.find(c);
            if(it == contestents.end()){
                if(l == 'C'){
                    contestents[c] = Contestent(c, 0, p);
                }else{
                    contestents[c] = Contestent(c, 0, 0);
                }
                
            }else{
                if(l == 'C'){
                    if(it->second.solved[p] == true){
                        continue;
                    }else{
                        it->second.solved[p] = true;
                    }
                    
                }else if(l == 'I'){
                    if(it->second.solved[p] == true){
                        continue;
                    }
                }
                
            }

            cList.push_back(c);
            pList.push_back(p);
            tList.push_back(t);
            lList.push_back(l);
        }

        for(int i = 0; i < cList.size(); i++){
            addTime(cList[i], pList[i], tList[i], lList[i]);
        }

        vector<Contestent> ordered;
        int i(0);
        //insertion sort
        for(auto it = contestents.begin(); it != contestents.end(); it++){
            ordered.push_back(it->second);
            for(int j = i; j > 0; j--){
                if(ordered[j].completed() > ordered[j-1].completed() || (ordered[j].completed() == ordered[j-1].completed() && ordered[j].time < ordered[j-1].time) || (ordered[j].completed() == ordered[j-1].completed() && ordered[j].time == ordered[j-1].time && ordered[j].id < ordered[j-1].id)){
                    swap(ordered[j], ordered[j-1]);
                }else{
                    break;
                }
            }

            i++;
        }

        for(int i = 0; i < ordered.size(); i++){
            cout<<ordered[i].id<<" "<<ordered[i].completed()<<" "<<ordered[i].time<<endl;
        }

        contestents.clear();

        if(tc != 0){
            cout<<endl;
        }

    }
    return 0;
}


// ds 13 this challenge was very hard to me, it has a lot of things like really hard input format
// to handle and very edge cases that they will not come to your mind instantly i took a lot of time to
// solved and i used internet