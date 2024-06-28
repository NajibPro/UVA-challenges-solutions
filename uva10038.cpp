#include <iostream>
#include <set>
#include <math.h>

using namespace std;

int main(){
    int size;
    

    while(cin>>size && !cin.eof()){
        bool joly = true;
        bool r[size];
        for(int i = 0; i < size; i++){
            r[i] = false;
        }
        int s[size];

        for(int i = 0; i < size; i++){
            cin>>s[i];
        }

        for(int i = 0; i < size-1; i++){
            if(abs(s[i] - s[i+1]) > size - 1){
                joly = false;
            }else{
                if(!r[abs(s[i] - s[i+1])]){
                    r[abs(s[i] - s[i+1])] = true;
                }else{
                    joly = false;
                }
            }

            
        }

        for(int i = 1; i < size; i++){
            if(r[i] == false){
                joly = false;
                break;
            }
        }

        cout<<(joly? "Jolly" : "Not jolly")<<endl;
    }

    return 0;
}


// ds 10 solved in 24min and 40sec