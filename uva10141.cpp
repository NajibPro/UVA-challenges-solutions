#include <iostream>
#include <vector>

using namespace std;

int main(){
    int n, p, counter(1);

    while(cin>>n>>p){
        if(n == 0 && p == 0){
            break;
        }else{
            if(counter != 1){
                cout<<endl;
            }
            
        }

        string requirments;

        for(int i = 0; i < n; i++){
            getline(cin>>ws, requirments);
        }

        string rfp[p];
        double price[p];
        double compliance[p];

        for(int j = 0; j < p; j++){
            getline(cin>>ws, rfp[j]);
            cin>>price[j];

            int met;

            cin>>met;
            for(int k = 0; k < met; k++){
                getline(cin>>ws, requirments);
            }

            compliance[j] = (met * 1.0) / n;
        }

        vector<int> maxCompIndexes;
        double maxComp = -1;


        for(int l = 0; l < p; l++){
            if(compliance[l] > maxComp){
                maxCompIndexes.clear();
                maxComp = compliance[l];

                maxCompIndexes.push_back(l);
            }else if(compliance[l] == maxComp){
                maxCompIndexes.push_back(l);
            }
        }

        int bestRfpIndex;
        double minPrice = 1000000000000;

        for(int j = 0; j < maxCompIndexes.size(); j++){
            if(minPrice > price[maxCompIndexes[j]]){
                minPrice = price[maxCompIndexes[j]];
                bestRfpIndex = maxCompIndexes[j];
            }
        }


        cout<<"RFP #"<<counter++<<endl;
        cout<<rfp[bestRfpIndex]<<endl;

    }
    return 0;
}

// medium 5 solved in 36min and 56sec