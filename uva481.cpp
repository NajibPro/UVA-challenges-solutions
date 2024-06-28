#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int lis(vector<int>& number, vector<int>& solution){
    vector<int> l;
    vector<bool> changed;
    l.push_back(number[0]);
    solution.push_back(number[0]);
    changed.push_back(false);

    for(int i = 1; i < number.size(); i++){
        if(number[i] > l[l.size() - 1]){
            solution.push_back(number[i]);
            l.push_back(number[i]);
            changed.push_back(false);
        }else{
            int lowerBoundIndex = lower_bound(l.begin(), l.end(), number[i]) - l.begin();
            l[lowerBoundIndex] = number[i];
            changed[lowerBoundIndex] = true;
            if(lowerBoundIndex == l.size() - 1){
                for(int i = l.size() - 1; i >= 0; i--){
                    if(changed[i]){
                        solution[i] = l[i];
                        changed[i] = false;
                    }else{
                        break;
                    }
                }
            }
        }
    }

    return l.size();
}

int main(){
    vector<int> number, solution;
    int n;

    while(cin>>n){
        number.push_back(n);
    }

    int ans = lis(number, solution);

    cout<<ans<<endl;
    cout<<"-"<<endl;

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

}