#include <iostream>

using namespace std;

string decrypte(string encryption){
    int size = encryption.size();
    
    if(encryption[size - 2] == '3' && encryption[size - 1] == '5'){
        return "-";
    }else if(encryption[0] == '9' && encryption[size - 1] == '4'){
        return "*";
    }else if(encryption[0] == '1' && encryption[1] == '9' && encryption[2] == '0'){
        return "?";
    }

    return "+";
}

int main(){
    int testCases;

    cin>>testCases;

    while(testCases--){
        string encryption;

        cin>>encryption;

        cout<<decrypte(encryption)<<endl;
    }
}

// easy+ 1 solved in 49min (because of a really stupid mistake)