#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;

    while(cin>>n && n != 0){
        int cost(0);
        priority_queue<int> q;
        for(int i = 0; i < n; i++){
            int number;
            cin>>number;

            q.push(-number);
        }

        if(n == 1){
            cout<<0<<endl;
            continue;
        }

        while(q.size() != 1){
            int a, b;
            a = -q.top();
            q.pop();
            b = -q.top();
            q.pop();

            cost += a + b;
            q.push(-(a+b));
        }

        cout<<cost<<endl;

    }
    return 0;
}

// ds 18 solved in 50 min, but with cheating with stackoverflow :)