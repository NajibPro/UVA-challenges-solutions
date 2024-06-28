#include <iostream>
#include <queue>

using namespace std;

queue<int> ferry, leftSide, rightSide;

int currentloading(0);

int l, m, count(0);

//left => 0, right => 1
bool position(0);

void fillFerry(){
    if(position == 0){
        while(!leftSide.empty() && leftSide.front() <= l - currentloading){
            ferry.push(leftSide.front());
            currentloading += leftSide.front();
            leftSide.pop();
        }
    }else{
        while(!rightSide.empty() && rightSide.front() <= l - currentloading){
            ferry.push(rightSide.front());
            currentloading += rightSide.front();
            rightSide.pop();
        }
    }
     
}

void emptyFerry(){
   while(!ferry.empty()){
    ferry.pop();
   }

   currentloading = 0;
}

void changePosition(){
    position = !position;
    count++;
}

void reset(){
    count = 0;
    position = false;
}

int main(){
    int n;
    cin>>n;

    while(n--){
        cin>>l>>m;

        l *= 100;
        for(int i = 0; i < m; i++){
            int len;
            string po;
            cin>>len>>po;

            if(po == "left"){
                leftSide.push(len);
            }else{
                rightSide.push(len);
            }
        }

        while(!(leftSide.empty() && rightSide.empty() && ferry.empty())){
            fillFerry();
            changePosition();
            emptyFerry();
        }
        
        cout<<count<<endl;

        reset();
    }

    return 0;
}

// ds 19 solved in 50 min