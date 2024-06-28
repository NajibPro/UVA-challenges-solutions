#include <iostream>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n;

    while(cin>>n && n != 0){
        set<string> combinations;
        unordered_map<string, int> repitition;
        for(int i = 0; i < n; i++){
            int numbers[5];

            for(int j = 0; j < 5; j++){
                cin>>numbers[j];
            }

            sort(numbers, numbers + 5);

            string combination;
            combination = to_string(numbers[0]) + to_string(numbers[1]) + to_string(numbers[2]) + to_string(numbers[3]) + to_string(numbers[4]);

            combinations.insert(combination);

            if(repitition.find(combination) == repitition.end()){
                repitition[combination] = 1;
            }else{
                repitition[combination]++;
            }

        }

        //find the highest repitition
        int maxReps(0);

        for(auto it = combinations.begin(); it != combinations.end(); it++){
            maxReps = max(maxReps, repitition[*it]);
        }

        //summing all the combs that has the highest reps
        int sum(0);
        for(auto it = combinations.begin(); it != combinations.end(); it++){
            sum += (repitition[*it] == maxReps) ? repitition[*it] : 0;
        }

        cout<<sum<<endl;
    }
    return 0;
}

// ds 21 solved in 19min