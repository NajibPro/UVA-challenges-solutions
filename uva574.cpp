#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>

using namespace std;



void backtrack(int total, vector<int>& number, int index, int currentSum, multiset<int> current, set<multiset<int>>& solutions){
    if(currentSum > total || number.size() < 1){
        return;
    }

    if(currentSum == total){
        solutions.insert(current);
        return;
    }

    if(index >= number.size()){
        return;
    }
        
    currentSum += number[index];
    current.insert(-number[index]);

    backtrack(total, number, index+1, currentSum, current, solutions);

    currentSum -= number[index];
    current.erase(current.find(-number[index]));

    backtrack(total, number, index+1, currentSum, current, solutions);

}

int main(){
    int t, n;

    while(cin>>t>>n && !(n == 0 && t == 0)){
        vector<int> number;

        for(int i = 0; i < n; i++){
            int num;
            cin>>num;
            number.push_back(num);
        }

        set<multiset<int>> solutions;
        multiset<int> current;

        backtrack(t, number, 0, 0, current, solutions);

        cout<<"Sums of "<<t<<":"<<endl;

        if(solutions.size() == 0){
            cout<<"NONE"<<endl;
        }else{
            for(auto it = solutions.begin(); it != solutions.end(); it++){
                for(auto it2 = it->begin(); it2 != it->end(); it2++){
                    if(it2 != it->begin()){
                        cout<<"+";
                    }
                    cout<<-*it2;
                }
                cout<<endl;
            }
        }

    }
}