#include <iostream>
#include <vector>

using namespace std;

int main(){
    int testCases(0);
    vector<string> solution;

    while(cin>>testCases && testCases != 0){
        int ox(0), oy(0);

        cin>>ox>>oy;

        for(int i = 0; i < testCases; i++){
            int x, y;
            cin>>x>>y;

            if(y == oy || x == ox){
                solution.push_back("divisa");
            } else if(x > ox && y > oy){
                solution.push_back("NE");
            } else if(x > ox && y < oy){
                solution.push_back("SE");
            } else if(x < ox && y > oy){
                solution.push_back("NO");
            } else if(x < ox && y < oy){
                solution.push_back("SO");
            }
        }
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

    return 0;
}