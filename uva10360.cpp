#include <iostream>

using namespace std;

int main(){
    int k;

    cin>>k;

    while(k--){
        int n, d;
        int grid[1025][1025];

        for(int i = 0; i < 1025; i++){
            for(int j = 0; j < 1025; j++){
                grid[i][j] = 0;
            }
        }

        cin>>d>>n;

        for(int i = 0; i < n; i++){
            int x, y, p;

            cin>>x>>y>>p;

            for(int k = x - d; k <= x + d; k++){
                for(int l = y - d; l <= y + d; l++){
                    if(k >= 0 && k <= 1024 && l >= 0 && l <= 1024){
                        grid[k][l] += p;
                    }
                }
            }
        }

        int maxKill(-100000);
        int maxX, maxY;

        for(int i = 0; i < 1025; i++){
            for(int j = 0; j < 1025; j++){
                if(maxKill < grid[i][j]){
                    maxKill = grid[i][j];
                    maxX = i; maxY = j;
                }
            }
        }

        cout<<maxX<<" "<<maxY<<" "<<maxKill<<endl;

    }
    return 0;
}