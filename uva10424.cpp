#include <iostream>
#include <iomanip>

using namespace std;

int charToInt(char a){
    if(a >= 97){
        return a - 96;
    }

    return a - 64;
}

bool isAlpha(char a){
    return (a >= 97 && a <= 122) || (a >= 65 && a <= 90);
}

int nameToNumber(string name){
    int result(0);
    for(int i = 0; i < name.size(); i++){
        if(isAlpha(name[i])){
            result += charToInt(name[i]);
        }
    }

    string res = to_string(result);

    while(result >= 10){
        result = 0;

        for(int i = 0; i < res.size(); i++){
            result += res[i] - '0';
        }

        res = to_string(result);
    }

    return result;
}

int main(){
    /*cout<<(0 + 'a')<<endl; // 97
    cout<<(0 + 'A')<<endl; //65
    cout<<(0 + 'Z')<<endl; // 90
    cout<<(0 + 'z')<<endl; // 122*/

    cout<<setprecision(2)<<fixed;

    string l, m;

    while(getline(cin>>ws, l) && ! cin.eof()){
        getline(cin>>ws, m);

        float r(nameToNumber(l)), s(nameToNumber(m));

        cout<<(min(r, s) * 100.0) / max(r, s)<<" "<<"%"<<endl;
    }
}

// medium 8 solved in 32min and 52sec