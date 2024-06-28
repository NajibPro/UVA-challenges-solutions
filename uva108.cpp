#include <iostream>
#include <sstream>

using namespace std;

int main(){
    int n;
    cin>>n;

    int a[n][n];

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        cin>>a[i][j];
        cin.ignore();
    }

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++){
        if(i > 0) a[i][j] += a[i-1][j];
        if(j > 0) a[i][j] += a[i][j-1];

        if(i > 0 && j > 0) a[i][j] -= a[i-1][j-1];
    }

    int subSum(0), maxSum(-127 * 100 * 100);

    for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) for(int k = i; k < n; k++) for(int l = j; l < n; l++){
        subSum = a[k][l];

        if(i > 0) subSum -= a[i-1][l];
        if(j > 0) subSum -= a[k][j-1];
        if(i > 0 && j > 0) subSum += a[i-1][j-1];

        maxSum = max(maxSum, subSum);
    }

    cout<<maxSum<<endl;

    return 0;
}