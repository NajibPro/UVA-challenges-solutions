#include <iostream>
#include <unordered_map>
#include <iomanip>

using namespace std;

int main(){
    int n;


    cin>>n;

    while(n--){
        int k;
        double price(0);
        cin>>k;
        unordered_map<char, double> letter;

        for(int i = 0; i < k; i++){
            char l; double p;
            cin>>l>>p;
            letter[l] = p / 100.0;
        }

        int m;
        cin>>m;
        cin.ignore();
        
        for(int i = 0; i < m; i++){
            string line;
            getline(cin, line);

            for(int j = 0; j < line.size(); j++){
                if(letter.find(line[j]) != letter.end()){
                    price += letter[line[j]];
                }
            }
        }

        cout<<fixed<<setprecision(2)<<price<<"$"<<endl;

    }
    return 0;
}