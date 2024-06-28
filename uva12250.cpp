#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<string> solution;
    int counter(1);
    string word;

    while(cin>>word && word != "#"){

        if(word == "HELLO"){
            solution.push_back("Case " + to_string(counter++) + ": ENGLISH");
        } else if(word == "HOLA"){
            solution.push_back("Case " + to_string(counter++) + ": SPANISH");

        } else if(word == "HALLO"){
            solution.push_back("Case " + to_string(counter++) + ": GERMAN");

        } else if(word == "BONJOUR"){
            solution.push_back("Case " + to_string(counter++) + ": FRENCH");

        } else if(word == "CIAO"){
            solution.push_back("Case " + to_string(counter++) + ": ITALIAN");

        } else if(word == "ZDRAVSTVUJTE"){
            solution.push_back("Case " + to_string(counter++) + ": RUSSIAN");

        } else {
            solution.push_back("Case " + to_string(counter++) + ": UNKNOWN");
        }

        
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }
}