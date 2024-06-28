#include <iostream>

using namespace std;

int main(){
    int n;
    cin>>n;

    cout<<"Lumberjacks:"<<endl;

    while(n--){
        int counter(0), neededTotal(9);
        int m, l;
        cin>>m;

        for(int i = 1; i < 10; i++){
            cin>>l;
            if(m > l){
                counter++;
            }else if(m < l){
                counter--;
            }else{
                neededTotal--;
            }

            m = l;
        }

        cout<<((counter == neededTotal || counter == -neededTotal) ? "Ordered" : "Unordered")<<endl;

    }
}

// easy+ 11 solved in 9min 28s