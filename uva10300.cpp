#include <iostream>

using namespace std;

int main(){
    int testCases;

    cin>>testCases;

    while(testCases--){
        int f, cost(0);
        cin>>f;
        while(f--){
            int size, animal, degree;
            cin>>size>>animal>>degree;

            cost += size * degree;
        }

        cout<<cost<<endl;
    }
    return 0;
}

// easy+ 3 solved in 14min and 8s