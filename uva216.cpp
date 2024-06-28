#include <iostream>
#include <unordered_map>
#include <limits>
#include <math.h>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

double ecludienDistance(pair<int, int> a, pair<int, int> b){
    double result = pow(a.first - b.first, 2) + pow(a.second - b.second, 2);

    result = sqrt(result);

    return result;
}

double calculateCableLength(unordered_map<int ,pair<int, int>>& computer, vector<int> order, int n){
    double sum = 0;
    for(int i = 0; i < n-1; i++){
        sum += ecludienDistance(computer[order[i]], computer[order[i+1]]);
    }

    return sum;
}

int main(){
    int n, counter(0);

    while(cin>>n && n != 0){
        unordered_map<int ,pair<int, int>> computer;
        for(int i = 0; i < n; i++){
            int a, b;
            cin>>a>>b;

            computer[i].first = a; computer[i].second = b;
        }

        vector<int> order;
        vector<int> bestOrder;

        for(int i = 0; i < n; i++){
            order.push_back(i);
            bestOrder.push_back(i);
        }

        double cableMinLength = std::numeric_limits<std::streamsize>::max();
        double current = 0;

        do{
            current = calculateCableLength(computer, order, n);
            if(cableMinLength > current){
                cableMinLength = current;

                bestOrder = order;
            }

        }while(next_permutation(order.begin(), order.end()));

        //printing the results:
        cout<<"**********************************************************"<<endl;
        cout<<"Network #"<<++counter<<endl;
        for(int i = 0; i < n-1; i++){
            double dist = ecludienDistance(computer[bestOrder[i]], computer[bestOrder[i+1]]);

            cout<<"Cable requirement to connect ("<<computer[bestOrder[i]].first<<","<<computer[bestOrder[i]].second<<") to ("<<computer[bestOrder[i+1]].first<<","<<computer[bestOrder[i+1]].second<<") is "<<fixed<<setprecision(2)<<dist + 16<<" feet."<<endl;
        }

        cout<<"Number of feet of cable required is "<<fixed<<setprecision(2)<<cableMinLength + 16 * (n-1)<<"."<<endl;
    }
    return 0;
}