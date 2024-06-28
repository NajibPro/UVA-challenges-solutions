#include <iostream>

using namespace std;

int main(){
    int h, w;
    while(cin>>h && h != 0){
        int removedLayers(0);
        cin>>w;

        int heights[w], maxH(0);

        for(int i = 0; i < w; i++){
            cin>>heights[i];

            heights[i] = h - heights[i];
        }

        /*while(h--){
            for(int i = 0; i < w; i++){
                if(heights[i] >= h){
                    if(i == w-1 || heights[i+1] < h){
                        removedLayers++;
                    }
                }
            }

        }*/

        removedLayers += heights[w-1];

        for(int i = 1; i < w; i++){
            removedLayers += (heights[i-1] - heights[i] > 0 ? heights[i-1] - heights[i] : 0);
        }

        cout<<removedLayers<<endl;
    }
}

// medium 11 solved in 1h and 32min (because if forgot a minur detail which is line
// 16: removedLayers += heights[w-1];)