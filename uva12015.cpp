#include <iostream>
#include <set>

using namespace std;

int main(){
    int testCases;

    cin>>testCases;

    int counter(1);

    while(testCases--){
        string url[10];
        int relevance[10];
        int maxRelevance(-1000);
        for(int i = 0; i < 10; i++){
            cin>>url[i];
            cin>>relevance[i];
            
            if(relevance[i] > maxRelevance){
                maxRelevance = relevance[i];
            }
        }

        set<string> resultUrls;

        for(int i = 0; i < 10; i++){
            if(relevance[i] == maxRelevance){
                resultUrls.insert(url[i]);
            }
        }

        cout<<"Case #"<<counter++<<":"<<endl;
        /*for(auto it = resultUrls.begin(); it != resultUrls.end(); it++){
            cout<<*it<<endl;
        }*/

        for(int i = 0; i < 10; i++){
            if(resultUrls.find(url[i]) != resultUrls.end()){
                cout<<url[i]<<endl;
                resultUrls.erase(url[i]);
            }
        }

    }
    return 0;
}

// easy+ 9 solved in 27min (because of a presentation error that happend cuz i incorrectly ordered the links of the result)