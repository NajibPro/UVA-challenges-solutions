#include <iostream>
#include <fstream>
using namespace std;

void rotatedIndexes(int r, int c, int n, int rotationDegree, int newIndexes[]){
    switch (rotationDegree)
    {
    case 90:
        newIndexes[0] = c;
        newIndexes[1] = n - r - 1;
        break;

    case 180:
        newIndexes[0] = n - r - 1;
        newIndexes[1] = n - c - 1;
        break;

    case 270:
        newIndexes[0] = n - c - 1;
        newIndexes[1] = r;
        break;
    
    default:
        newIndexes[0] = r;
        newIndexes[1] = c;
        break;
    }
}

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
                        int arr[2] = {0, 0};
                        rotatedIndexes(k, l, n, 0, arr);
                        if(big[i+arr[0]][j+arr[1]] != small[k][l]){
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

        //check with 90 rotation clockwise
        bool b = true;
        for(int i = 0; i < N - n + 1; i++){
            for(int j = 0; j < N - n + 1; j++){
                b = true;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        int arr[2] = {0, 0};
                        rotatedIndexes(k, l, n, 90, arr);
                        if(big[i+arr[0]][j+arr[1]] != small[k][l]){
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
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        int arr[2] = {0, 0};
                        rotatedIndexes(k, l, n, 180, arr);
                        if(big[i+arr[0]][j+arr[1]] != small[k][l]){
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

        //check with 270 rotation clockwise
        bool d = true;
        for(int i = 0; i < N - n + 1; i++){
            for(int j = 0; j < N - n + 1; j++){
                d = true;
                for(int k = 0; k < n; k++){
                    for(int l = 0; l < n; l++){
                        int arr[2] = {0, 0};
                        rotatedIndexes(k, l, n, 270, arr);
                        if(big[i+arr[0]][j+arr[1]] != small[k][l]){
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

        cout<<aCount<<" "<<bCount<<" "<<cCount<<" "<<dCount<<endl;

    }
    return 0;
}