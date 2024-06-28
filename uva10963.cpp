#include <iostream>

using namespace std;

int main(){
    int testCases;

    cin>>testCases;

    while (testCases--){
        int w, gapLineSize(-1000);
        bool closable = true;
        cin.ignore();
        cin>>w;

        while(w--){
            int north, south;

            cin>>north>>south;

            if(north - south != gapLineSize && gapLineSize != -1000){
                closable = false;
            }else if(gapLineSize == -1000){
                gapLineSize = north - south;
            }
        }

        cout<<(closable ? "yes" : "no")<<endl;

        if(testCases != 0){
            cout<<endl;
        }
    }
    
    return 0;
}

// easy+ 4 solved in 39min 11s

// when directly getting the input, when you find the correct output for a test
// don't forget to get the input all the rest of the input of the current test
// case before going to the next one