#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class UFDS{
    
    vector<int> parent;

    public:
    unordered_map<char, int> letters;

    UFDS(int size, const string& ls){
        parent.assign(size, -1);
        for(int i = 0; i < ls.size(); i++){
            letters.emplace(ls[i], i);
        }
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

    int getSetSize(int x){
        if(parent[x] < 0){
            return -parent[x];
        }

        return getSetSize(parent[x]);
    }

    void count(){
        int trees(0), acrons(0);
        for(int i = 0; i < parent.size(); i++){
            if(parent[i] < -1){
                trees++;
            }else if(parent[i] == -1){
                acrons++;
            }
        }
        cout<<"There are "<<trees<<" tree(s) and "<<acrons<<" acorn(s)."<<endl;
    }
};


int main(){
    int tc;

    cin>>tc;

    while(tc--){
        vector<string> edges;
        string edge;
        while(getline(cin>>ws, edge) && edge[0] != '*'){
            string cleanEdge = "";
            for(int i = 0; i < edge.size() && cleanEdge.size() < 2; i++){
                if(edge[i] >= 'A' && edge[i] <= 'Z'){
                    cleanEdge += edge[i];
                }
            }
            edges.push_back(cleanEdge);
        }

        string lettersList, letters;
        getline(cin>>ws, lettersList);

        for(int i = 0; i < lettersList.size(); i++){
            if(lettersList[i] >= 'A' && lettersList[i] <= 'Z'){
                letters += lettersList[i];
            }
        }

        UFDS forest = UFDS(letters.size(), letters);

        for(int i = 0; i < edges.size(); i++){
            forest.unit(forest.letters[edges[i][0]], forest.letters[edges[i][1]]);
        }

        forest.count();

    }
    return 0;
}

// ds 3 solved in 58min and 44sec

// why it took me so long??
/*
first i know an easier solution for this, but i prefered to use UFDS to
learn better about them

second, i added a debugging statement and i forgot to remove it when 
submitting, it took me a while to notice it, i would solve the 
challenge in 30 min if i didn't add that statement
*/