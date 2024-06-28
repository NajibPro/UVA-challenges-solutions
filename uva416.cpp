#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const vector<string> representation = {
    "YYYYYYN",
    "NYYNNNN",
    "YYNYYNY",
    "YYYYNNY",
    "NYYNNYY",
    "YNYYNYY",
    "YNYYYYY",
    "YYYNNNN",
    "YYYYYYY",
    "YYYYNYY"
};

bool burnt[10];

bool match(string sequence, int number){
    for(int i = 0; i < sequence.size(); i++){
        if(sequence[i] == 'Y' && burnt[i]){
            return false;
        }

        if(representation[number][i] == sequence[i]){
            continue;
        }else if(sequence[i] == 'Y'){
            return false;
        }else if(sequence[i] == 'N'){ 
            burnt[i] = true;
        }
    }

    return true;
}

bool countMatch(vector<string>& sequences, int start){
    int count = sequences.size();
    memset(burnt, 0, sizeof(burnt));

    for(int i = start; i > start - count; i--){
        if(!match(sequences[start - i], i)){
            return false;
        }
    }

    return true;
}

bool isCountingDown(vector<string>& sequences){
    for(int i = 9; i >= sequences.size() - 1; i--){
        if(countMatch(sequences, i)){
            return true;
        }
    }

    return false;
}

int main(){
    int n;

    while(cin>>n && n != 0){
        vector<string> sequences;
        string line;

        for(int i = 0; i < n; i++){
            cin>>line;
            sequences.push_back(line);
        }

        cout<<(isCountingDown(sequences) ? "MATCH" : "MISMATCH")<<endl;

        
    }
}