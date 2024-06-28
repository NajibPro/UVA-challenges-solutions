#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main(){
    int n;

    while(cin>>n && n != 0){
        long long total(0);
        multiset<int> bills;

        for(int i = 0; i < n; i++){
            int k;

            cin>>k;

            for(int j = 0; j < k; j++){
                int bill;
                cin>>bill;

                bills.insert(bill);
            }

            total += *bills.rbegin() - *bills.begin();

            bills.erase(bills.begin());
            bills.erase(prev(bills.end()));
        }

        cout<<total<<endl;
    }
    return 0;
}

// ds 20 solved in 42 min (I read about a new ds while solving it which is multiset)