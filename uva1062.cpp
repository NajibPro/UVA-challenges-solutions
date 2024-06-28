#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    string testCase;
    int counter(1);

    while(cin>>testCase && testCase != "end"){
        vector<stack<char>> terminal;

        for(int i = 0; i < testCase.size(); i++){
            // we determine where we put testCase[i]
            int index = -1;
            char small = 'n';
            for(int j = 0; j < terminal.size(); j++){
                if(testCase[i] <= terminal[j].top() && (index == -1 || terminal[j].top() < small)){
                    index = j;
                    small = terminal[j].top();
                }
            }

            if(index == -1){
                stack<char> container;
                container.push(testCase[i]);

                terminal.push_back(container);
            }else{
                terminal[index].push(testCase[i]);
            }
        }

        cout<<"Case "<<counter++<<": "<<terminal.size()<<endl;
    }
    return 0;
}

// ds 8 didn't count time for it but it went fast