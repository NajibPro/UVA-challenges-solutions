#include <iostream>
#include <set>
#include <algorithm>
using namespace std;


string after(string word){
    char letterToSwap(word[1]);
    int index(1);

    for(int i = 2; i < word.size(); i++){
        if(word[i] > word[0] && word[i] < letterToSwap){
            letterToSwap = word[i];
            index = i;
        }
    }

    swap(word[0], word[index]);

    string charSet = word.substr(1);
    sort(charSet.begin(), charSet.end());

    return word[0] + charSet;
}

string successor(string word){
    
    int k(-1);

    for(int j = word.size() - 1; j > 0; j--){
        if(word[j] > word[j-1]){
            k = j-1;
            break;
        }
    }

    if(k == -1){
        return "No Successor";
    }else{
        return word.substr(0, k) + after(word.substr(k));
    }

    

}


int main(){
    string word;
    while(cin>>word && word != "#"){
        cout<<successor(word)<<endl;
    }
    return 0;
}

// ds 1 solved in 1h 23min and 29sec