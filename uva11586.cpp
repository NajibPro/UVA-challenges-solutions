#include <iostream>
#include <vector>

using namespace std;

int main(){
    int tc;
    cin>>tc;

    while(tc--){
        vector<string> p;
        string line;

        getline(cin>>ws, line);

        for (size_t i = 0; i < line.size(); ++i) {
            if (line[i] == ' ') {
                line.erase(i, 1);
                --i;
            }
        }

        for(int i = 0; i < line.length(); i += 2){
            string peice = line.substr(i, 2);
            p.push_back(peice);
        }

        int lf(0), rf(0), lm(0), rm(0);

        for(int i = 0; i < p.size(); i++){
            lf += (p[i][0] == 'F' ? 1 : 0);
            rf += (p[i][1] == 'F' ? 1 : 0);
            lm += (p[i][0] == 'M' ? 1 : 0);
            rm += (p[i][1] == 'M' ? 1 : 0);
        }



        cout<<(lm == rf && rm == lf && p.size() != 1? "LOOP" : "NO LOOP")<<endl;
    }
    return 0;
}

// medium 10 solved in 53min and 15sec