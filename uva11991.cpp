#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main(){
    int n, m;
    while(cin>>n>>m && !cin.eof()){
        unordered_map<int, vector<int>> numbers;

        for(int i = 0; i < n; i++){
            int num;
            cin>>num;

            numbers[num].push_back(i+1);
        }

        for(int i = 0; i < m; i++){
            int k, v;
            cin>>k>>v;

            cout<<(numbers.find(v) == numbers.end() || numbers[v].size() < k ? 0 : numbers[v][k-1])<<endl;
        }
    }
}