#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(){
    int tc;

    cin>>tc;

    while(tc--){
        int b, sg, sb;
        cin>>b>>sg>>sb;

        int battles[b];
        priority_queue<int> green, blue;

        for(int i = 0; i < sg; i++){
            int soldier;
            cin>>soldier;

            green.push(soldier);
        }

        for(int i = 0; i < sb; i++){
            int soldier;
            cin>>soldier;

            blue.push(soldier);
        }

        while(!green.empty() && !blue.empty()){
            int i;
            for(i = 0; i < b && !green.empty() && !blue.empty(); i++){
                battles[i] = green.top() - blue.top();
                green.pop();
                blue.pop();
            }

            for(int j = 0; j < i; j++){
                if(battles[j] < 0){
                    blue.push(-battles[j]);
                }else if(battles[j] > 0){
                    green.push(battles[j]);
                }
            }
        }

        if(green.empty() && blue.empty()){
            cout<<"green and blue died"<<endl;
        }else if(green.empty()){
            cout<<"blue wins"<<endl;

            while(!blue.empty()){
                cout<<blue.top()<<endl;
                blue.pop();
            }
        }else if(blue.empty()){
            cout<<"green wins"<<endl;

            while(!green.empty()){
                cout<<green.top()<<endl;
                green.pop();
            }
        }

        if(tc != 0){
            cout<<endl;
        }
    }
    return 0;
}

// ds 6 solved in 37min and 54sec