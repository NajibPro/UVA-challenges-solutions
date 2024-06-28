#include <iostream>
#include <vector>

using namespace std;

int main(){
    int numberOfTests(0);
    cin>>numberOfTests;

    if(!numberOfTests){
        exit(0);
    }

    vector<int> solution;

    while(numberOfTests--){
        int numberOfStops(0);
        cin>>numberOfStops;

        vector<int> stopNumber;
        int far(-1), near(1000000000), stop(0);

        for(int i = 0; i < numberOfStops; i++){
            cin>>stop;

            if(stop < near){
                near = stop;
            }

            if(stop > far){
                far = stop;
            }

            stopNumber.push_back(stop);
        }



        solution.push_back((far - near) * 2);
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

    return 0;
}