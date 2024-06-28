#include <iostream>
#include <vector>
#include <set>

using namespace std;

struct Category{
    int c, min;
    set<int> cNumbers;

    int matches(int courses[], int size){
        int counter(0);
        for(int i = 0; i < size; i++){
            if(cNumbers.find(courses[i]) != cNumbers.end()){
                counter++;
            }
        }

        return counter;
    }

    bool satisfied(int courses[], int size){
        return (matches(courses, size) >= min);
    }

};

int main(){
    int k, m;

    while(cin>>k){
        if(k == 0){
            exit(0);
        }
        int taken[k];
        bool allSatesfied = true;
        
        cin>>m;

        Category c[m];

        for(int i = 0; i < k; i++){
            cin>>taken[i];
        }

        for(int i = 0; i < m; i++){
            cin>>c[i].c;
            cin>>c[i].min;
            for(int j = 0; j < c[i].c; j++){
                int s;
                cin>>s;
                c[i].cNumbers.insert(s);
            }

            if(!c[i].satisfied(taken, k)){
                allSatesfied = false;
            }
        }

        cout<<(allSatesfied ? "yes" : "no")<<endl;
    }

    return 0;
}

// medium 9 solved in 32min and 51sec