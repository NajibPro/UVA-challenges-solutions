#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

int main(){
    int n;
    bool isFirst = true;
    while(cin>>n){

        if(n == 0){
            exit(0);
        }

        vector<queue<int>> order;

        int number;

        while(cin>>number && number != 0){
            queue<int> o;
            o.push(number);
            for(int i = 1; i < n; i++){
                cin>>number;

                o.push(number);
            }

            order.push_back(o);
        }

        for(auto element : order){
            bool increaseTime = true, possible = true, counter(0);

            stack<int> station;

            for(int i = 1; !element.empty() && possible && i <= n; i++){
                if(element.front() > i){
                    station.push(i);
                }else if(element.front() < i){
                    if(station.top() == element.front()){
                        station.pop(); element.pop();
                        i--;
                    }
                }else if(element.front() == i){
                    element.pop();
                }
            }

            while(!element.empty() && possible){
                int a = element.front(), b = station.top();

                if(a == b){
                    element.pop();
                    station.pop();
                }else{
                    possible = false;
                }
            }



            /*if(element[n-1] > n || element[n-1] <= 0){
                possible = false;
            }

            for(int i = 0; i < n-1; i++){
                if((element[i] > n || element[i] <= 0) || (element[i] == element[i+1])){
                    possible = false;
                }else if(element[i] > element[i+1] && increaseTime){
                    increaseTime = false;
                }else if(element[i] < element[i+1] && increaseTime){
        
                }else if(element[i] < element[i+1] && !increaseTime){
                    possible = false;
                }else if(element[i] > element[i+1] && !increaseTime){
                    
                }
            }*/

            cout<<(possible ? "Yes" : "No")<<endl;
        }

        cout<<endl;
    }
    return 0;
}