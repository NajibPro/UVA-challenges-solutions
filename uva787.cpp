#include <iostream>
#include <vector>
#include <limits>

using namespace std;

long long arrayProduct(vector<int>& arr, int start, int end){
    long long p = 1;

    for(int i = start; i <= end; i++){
        p *= arr[i];
    }

    return p;
}

long long biggestProduct(vector<int>& arr, int start, int end, bool thereIsZero = false){
    //check for valid start and end
    if(start > end || start < 0 || end > arr.size() - 1){
        if(thereIsZero){
            return 0;
        }else{
            return -std::numeric_limits<long long>::infinity();
        }
    }

    //special case only one number (and if it is negative it can be a disaster without this line of code)
    if(start == end){
        if(thereIsZero){
            return max(arr[0], 0);
        }else{
            return arr[0];
        }
        
    }

    //check for zeros
    for(int i = start; i <= end; i++){
        if(arr[i] == 0){
            if(thereIsZero){
                return max(max(biggestProduct(arr, start, i-1, true), biggestProduct(arr, i+1, end, true)), 0);
            }else{
                return max(biggestProduct(arr, start, i-1, true), biggestProduct(arr, i+1, end, true));
            }
            
        }
    }

    //now negative numbers
    vector<int> negIndexes;
    for(int i = start; i <= end; i++){
        if(arr[i] < 0){
            negIndexes.push_back(i);
        }
    }

    if(negIndexes.size() % 2 == 0){
        return arrayProduct(arr, start, end);
    }else{
        int lastNegIndex = negIndexes[negIndexes.size() - 1];
        int firstNegIndex = negIndexes[0];
        
        return max(biggestProduct(arr, start, lastNegIndex - 1), biggestProduct(arr, firstNegIndex + 1, end));
    }
}

int main(){
    int n;
    vector<int> arr;
    while(!cin.eof()){
        while(cin>>n && n != -999999 && !cin.eof()){
            arr.push_back(n);
        }

        cout<<biggestProduct(arr, 0, arr.size() - 1)<<endl;
        arr.clear();
    }
    
    

}