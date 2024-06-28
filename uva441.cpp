#include <iostream>

using namespace std;

int main(){
    int k;
    cin>>k;
    while(k != 0){
        int numbers[k];

        for(int i = 0; i < k; i++){
            cin>>numbers[i];
        }

        for(int a = 0; a < k; a++){
            for(int b = a+1; b < k; b++){
                for(int c = b+1; c < k; c++){
                    for(int d = c+1; d < k; d++){
                        for(int e = d+1; e < k; e++){
                            for(int f = e+1; f < k; f++){
                                cout<<numbers[a]<<" "<<numbers[b]<<" "<<numbers[c]<<" "<<numbers[d]<<" "<<numbers[e]<<" "<<numbers[f]<<endl;
                            }
                        }
                    }
                }
            }
        }

        cin>>k;

        if(k == 0){
            break;
        }else{
            cout<<endl;
        }
    }
    return 0;
}