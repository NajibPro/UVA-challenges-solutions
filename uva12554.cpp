#include <iostream>

using namespace std;

int main(){
    int peopleCount;

    cin>>peopleCount;

    string people[peopleCount];

    for(int i = 0; i < peopleCount; i++){
        cin>>people[i];
    }

    string bSound[16] = {"Happy", "birthday", "to", "you", "Happy", "birthday", "to", "you", "Happy", "birthday", "to", "Rujia", "Happy", "birthday", "to", "you"};

    int currentPerson = 0;
    bool allPeopleAppeared = false;

    while(!allPeopleAppeared){
        for(int i = 0; i < 16; i++){
            cout<<people[(currentPerson++ % peopleCount)]<<": "<<bSound[i]<<endl;

            if(currentPerson >= peopleCount){
                allPeopleAppeared = true;
            }
        }
    }

    
    return 0;
}

// easy+ 14 solved in 12min 48s