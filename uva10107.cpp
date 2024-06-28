#include <iostream>

using namespace std;

int main(){
    unsigned int numbers[10000];
    int i(0);
    
    while(cin>>numbers[i]){

        for(int j = i; j > 0; j--){
            if(numbers[j] < numbers[j-1]){
                swap(numbers[j], numbers[j-1]);
            }else{
                break;
            }
        }

        if((i+1) % 2 == 1){
            cout<<numbers[((i+1)/2)]<<endl;
        }else{
            cout<<(numbers[((i+1)/2) - 1] + numbers[((i+1)/2)]) / 2<<endl;
        }
        i++;
    }
}


// ds 12 solved in 47min and 15sec


// actually it was solved in less the 10 minutes but i had a problem with dealing with the bad input format