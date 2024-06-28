#include <iostream>

using namespace std;

int main(){
    int testCases;
    cin>>testCases;
    int counter(1);
    while(testCases--){
        int walls(0), high(0), low(0), first(0), second(0);
        cin>>walls;
        cin>>first;
        for(int i = 1; i < walls; i++){
            cin>>second;
            if(second > first){
                high++;
            }else if(second < first){
                low++;
            }
            first = second;
        }

        cout<<"Case "<<counter++<<": "<<high<<" "<<low<<endl;

    }
    return 0;
}

// easy+ 8 solved in 10min 58s