#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main(){
    vector<int> solution;
    int start, c1, c2, c3;

    while(cin>>start>>c1>>c2>>c3 && !(start == 0 && c1 == 0 && c2 == 0 && c3 == 0)){
        int sol(0);

        sol += 360 * 3;
        int distance(0);

        //degree between the start and the 1st comb (direction <)
        distance = c1 > start? 40 - abs(c1 - start) : abs(c1 - start);
        sol += (distance * 360) / 40; 

        //degree between c1 and c2 (>)
        distance = c2 < c1? 40 - abs(c2 - c1) : abs(c2 - c1);
        sol += (distance * 360) / 40;

        //degree between c2 and c3 (<)
        distance = c3 > c2? 40 - abs(c3 - c2) : abs(c3 - c2);
        sol += (distance * 360) / 40;

        solution.push_back(sol);
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

    return 0;
}