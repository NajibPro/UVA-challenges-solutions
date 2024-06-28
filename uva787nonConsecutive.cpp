#include <iostream>
#include <algorithm>
#include <set>

using namespace std;

int main(){
    int n;
    multiset<int> negativeNumbers;
    multiset<int> positiveNumbers;
    bool isZero = false;

    while(cin>>n){
        if(n == -999999){
            long long maxProduct = 1;
            if(positiveNumbers.size() == 0 && isZero == true && negativeNumbers.size() == 1){
                cout<<0<<endl;
                
            }else if(positiveNumbers.size() == 0 && isZero == false && negativeNumbers.size() == 1){
                cout<<*negativeNumbers.begin()<<endl;

            }else if(positiveNumbers.size() == 0 && negativeNumbers.size() == 0){
                cout<<0<<endl;

            }else if(negativeNumbers.size() % 2 == 1){
                for_each(positiveNumbers.begin(), positiveNumbers.end(), [&maxProduct](int x) { maxProduct *= x; });
                negativeNumbers.erase(max_element(negativeNumbers.begin(), negativeNumbers.end()));
                for_each(negativeNumbers.begin(), negativeNumbers.end(), [&maxProduct](int x) { maxProduct *= x; });

                cout<<maxProduct<<endl;

            }else if(negativeNumbers.size() != 0 && negativeNumbers.size() % 2 == 0){
                for_each(positiveNumbers.begin(), positiveNumbers.end(), [&maxProduct](int x) { maxProduct *= x; });
                for_each(negativeNumbers.begin(), negativeNumbers.end(), [&maxProduct](int x) { maxProduct *= x; });

                cout<<maxProduct<<endl;

            }else{
                for_each(positiveNumbers.begin(), positiveNumbers.end(), [&maxProduct](int x) { maxProduct *= x; });

                cout<<maxProduct<<endl;
            }

            negativeNumbers.clear(); positiveNumbers.clear();
            isZero = false; maxProduct = 1;
            continue;
        }

        if(n > 0){
            positiveNumbers.insert(n);
        }else if(n < 0){
            negativeNumbers.insert(n);
        }else{
            isZero = true;
        }
    }
}