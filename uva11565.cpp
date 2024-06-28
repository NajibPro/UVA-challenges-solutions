#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int a, b, c;
        bool solved = false;

        cin>>a>>b>>c;

        for(int x = -22; x <= 22; x++){
            for(int y = -100; y <= 100; y++){
                if(x == y){
                    continue;
                }

                for(int z = -100; z <= 100; z++){
                    if(x == z || y == z){
                        continue;
                    }
                    
                    if(x + y + z == a && x * y * z == b && x*x + y*y + z*z == c){ //11 48 41 344

                        vector<int> solution = {x, y, z};

                        sort(solution.begin(), solution.end());
                        cout<<solution[0]<<" "<<solution[1]<<" "<<solution[2];
                        solved = true;
                        break;
                    }
                }

                if(solved){
                    break;
                }
            }

            if(solved){
                break;
            }
        }

        if(!solved){
            cout<<"No solution.";
        }

        if(true){
            cout<<endl;
        }
    }
    return 0;
}