#include <iostream>

using namespace std;

int main(){
    int testCases;

    cin>>testCases;

    while(testCases--){
        int count;
        cin>>count;

        string instructions[count];
        int p(0);

        for(int i = 0; i < count; i++){
            string s;
            cin>>s;
            if(s == "SAME"){
                int n;
                cin>>s;
                cin>>n;
                instructions[i] = instructions[n-1];
            
            }else{
                instructions[i] = s;
            }

            p += (instructions[i] == "LEFT" ? -1 : 1);
        }
        
        cout<<p<<endl;
    }
    return 0;
}

// easy+ 16 solved in 12min and 14 sec