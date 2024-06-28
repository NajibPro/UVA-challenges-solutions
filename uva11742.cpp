#include <iostream>
#include <algorithm>

using namespace std;

struct Contstraint{
    int p1, p2, c;

    Contstraint(){

    }

    Contstraint(int p1, int p2, int c){
        this->p1 = p1;
        this->p2 = p2;
        this->c = c;
    }
};

int main(){
    int n, m;

    while(cin>>n>>m && !(n == 0 && m == 0)){
        Contstraint cons[m];
        int arrang[n];
        int counter(0);

        for(int i = 0; i < n; i++){
            arrang[i] = i;
        }

        for(int j = 0; j < m; j++){
            cin>>cons[j].p1; cin>>cons[j].p2; cin>>cons[j].c;
        }

        do{
            bool valid = true;
            for(int i = 0; i < m; i++){
                if((cons[i].c < 0 && abs(arrang[cons[i].p1] - arrang[cons[i].p2]) >= -cons[i].c) || (cons[i].c > 0 && abs(arrang[cons[i].p1] - arrang[cons[i].p2]) <= cons[i].c)){
                    
                }else{
                    valid = false;
                }
            }

            if(valid){
                counter++;
            }
        }while(next_permutation(arrang, arrang + n));

        cout<<counter<<endl;
    }
    return 0;
}