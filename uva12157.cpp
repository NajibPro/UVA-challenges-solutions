#include <iostream>

using namespace std;

int main(){
    int t, counter(1);
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int jCost(0), mCost(0);

        int sequence[n];
        for(int i = 0; i < n; i++){
            cin>>sequence[i];

            jCost +=  15 * (sequence[i] / 60) + 15;
            mCost +=  10 * (sequence[i] / 30) + 10;
        }

        cout<<"Case "<<counter++<<": ";
        if(jCost == mCost){
            cout<<"Mile Juice "<<jCost;
        }else if(jCost < mCost){
            cout<<"Juice "<<jCost;
        }else{
            cout<<"Mile "<<mCost;
        }

        if(true){
            cout<<endl;
        }
    }
}


// easy+ 12 solved in 22min (all of this because i did not add \n at the end of my output its weird because in some
// challenges we have to remove it while in others we have to keep it and they don't clarify about it at all)