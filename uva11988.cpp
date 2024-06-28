#include <iostream>
#include <list>

using namespace std;

int main(){
    string line;

    while(cin>>line && !cin.eof()){
        list<char> real;
        list<char>::iterator it = real.begin();

        bool home = false;
        for(int i = 0; i < line.size(); i++){
            if(line[i] == '['){
                home = true;
                it = real.begin();
                continue;
            }else if(line[i] == ']'){
                home = false;
                it = real.begin();
                continue;
            }

            if(home){
                real.insert(it, line[i]);
            }else{
                real.push_back(line[i]);
            }
        }

        for(auto iter = real.begin(); iter != real.end(); iter++){
            cout<<*iter;
        }
        cout<<endl;
    }
}