#include <iostream>
#include <stack>
#include <queue>
#include <vector>

using namespace std;

void backtrack(queue<char> start, const queue<char>& goal, stack<char> current, vector<string>& writable, string solution){
    //backtrack termination
    if(goal.empty()){
        writable.push_back(solution);
        return;
    }

    bool i = !start.empty(), o = (!goal.empty() && !current.empty() && goal.front() == current.top());

    // this is a dead end
    if(!(i || o)){
        return;
    }

    //try to add i
    if(i){
        stack<char> newCurrent = current;
        queue<char> newStart = start;
        string newSolution = solution;

        newCurrent.push(start.front());
        newStart.pop();
        newSolution.append("i");

        backtrack(newStart, goal, newCurrent, writable, newSolution);
    }

    //try to add o
    if(o){
        queue<char> newGoal = goal;
        stack<char> newCurrent = current;
        string newSolution = solution;

        newGoal.pop();
        newCurrent.pop();
        newSolution.append("o");

        backtrack(start, newGoal, newCurrent, writable, newSolution);
    }
    
}

vector<string> answers(const queue<char>& start, const queue<char>& goal){
    vector<string> possibilities;
    stack<char> current;

    backtrack(start, goal, current, possibilities, "");

    return possibilities;
}

int main(){
    string w, x;

    while(cin>>w && !cin.eof()){
        cin>>x;

        queue<char> goal, start;

        for(int i = 0; i < x.size(); i++){
            goal.push(x[i]);
            start.push(w[i]);
        }

        vector<string> solution = answers(start, goal);

        cout<<"["<<endl;
        for(int i = 0; i < solution.size(); i++){
            for(int j = 0; j < solution[i].size(); j++){
                cout<<solution[i][j];
                if(j != solution[i].size() - 1){
                    cout<<" ";
                }
            }
            cout<<endl;
        }
        cout<<"]"<<endl;

    }
    return 0;
}

// ds 4 this is my first backtracking algo i wrote in my life
// and the best part is my code got accepted by the judge after the
// first submit, i wrote a code with no bugs after only the first try