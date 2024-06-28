#include <iostream>

using namespace std;

int main(){
    int N, n;

    while(cin>>N>>n && !(n == 0 && N == 0)){

        char big[N][N], small[n][n];
        int aCount(0), bCount(0), cCount(0), dCount(0);

        cin.ignore();

        for(int i = 0; i < N; i++){
            for(int j = 0; j < N; j++){
                big[i][j] = cin.get();
            }

            cin.ignore();
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                small[i][j] = cin.get();
            }

            cin.ignore();
        }

        //check without rotation
        bool a = true;
        for(int i = 0; i < N - n + 1; i++){
            for(int j = 0; j < N - n + 1; j++){
                a = true;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        if(big[i+k][j+l] != small[k][l]){
                            a = false;
                            break;
                        }
                    }
                    if(!a){
                        break;
                    }
                }
                if(a){
                    aCount++;
                }
            }
        }

        //check with 270 rotation clockwise
        bool b = true;
        for(int i = 0; i < N - n + 1; i++){
            for(int j = 0; j < N - n + 1; j++){
                b = true;
                for(int k = n-1; k >= 0; k--){
                    for(int l = n-1; l >= 0; l--){
                        if(big[i+(n - k)][j+(n - l)] != small[k][l]){
                            b = false;
                            break;
                        }
                    }
                    if(!b){
                        break;
                    }
                }
                if(b){
                    bCount++;
                }
            }
        }

        //check with 180 rotation clockwise
        bool c = true;
        for(int i = 0; i < N - n + 1; i++){
            for(int j = 0; j < N - n + 1; j++){
                c = true;
                for(int k = n-1; k >= 0; k--){
                    for(int l = 0; l < n; l++){
                        if(big[i+(n - k)][j+l] != small[k][l]){
                            c = false;
                            break;
                        }
                    }
                    if(!c){
                        break;
                    }
                }
                if(c){
                    cCount++;
                }
            }
        }

        //check with 90 rotation clockwise
        bool d = true;
        for(int i = 0; i < N - n + 1; i++){
            for(int j = 0; j < N - n + 1; j++){
                d = true;
                for(int k = 0; k < n; k++){
                    for(int l = n-1; l >= 0; l--){
                        if(big[i+k][j+(n - l)] != small[k][l]){
                            d = false;
                            break;
                        }
                    }
                    if(!d){
                        break;
                    }
                }
                if(d){
                    dCount++;
                }
            }
        }

        cout<<aCount<<" "<<dCount<<" "<<bCount<<" "<<cCount<<endl;

    }
    return 0;
}