#include <iostream>
#include <cstring>

using namespace std;

int main(){
    int duration(0), deps(0);
    double payment(0), amount(0);

    while(cin>>duration>>payment>>amount>>deps && duration > 0){
        double depList[100];
        double persentage;

        memset(depList, 0, sizeof(depList));

        for(int i = 0; i < deps; i++){
            int depNumber(0);
            cin>>depNumber>>persentage;

            depList[depNumber] = persentage;
        }

        double savedDep(depList[0]);

        for(int i = 0; i < 100; i++){
            if(depList[i] == 0){
                depList[i] = savedDep;
            } else {
                savedDep = depList[i];
            }
        }

        double carPrice = payment + amount - ((payment + amount) * depList[0]);
        double owes = amount, monthlyPay = amount / duration;
        int counter = 0;

        while(carPrice <= owes){
            owes -= monthlyPay;
            carPrice = carPrice - (carPrice * depList[++counter]);
        }

        cout<<counter<<" "<<(counter == 1 ? "month" : "months")<<endl;
    }
    return 0;
}

// easy+ 2 solved in 1h 43min and 26s because i didn't know how lbay3 with taksit works so after 1h and 30min of
// trying i unfortunatly I searched in the internet