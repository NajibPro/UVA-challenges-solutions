#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<int> solution;
    int l;

    while(cin>>l && l != 0){
        string highway;
        cin>>highway;

        char savedPlace, place;
        int distance(1), minDistance(l+1), current;

        //loop for a saved place  first
        for(current = 0; current < l; current++){
            if(highway[current] == 'Z'){
                minDistance = 0;
                break;
            }

            if(highway[current] != '.'){
                savedPlace = highway[current];
                current++;
                break;
            }
        }

        for(current; current < l && minDistance != 0; current++){
            if(highway[current] == 'Z'){
                minDistance = 0;
                break;
            }

            if(highway[current] == '.'){
                distance++;

            } else if(highway[current] == savedPlace){
                savedPlace = highway[current];
                distance = 1;
            } else if(highway[current] != savedPlace){
                if(distance < minDistance){
                    minDistance = distance;
                }
                savedPlace = highway[current];
                distance = 1;
            }
        }

        solution.push_back(minDistance);



    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }

    return 0;
}




/*
//answer without using strings
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int l;
    vector<int> solution;

    while(cin>>l && l != 0){
        int minDistance(2000001);
        char savedPlace;
        char place;
        int distance(1);

        cin.ignore();
        do{
            savedPlace = cin.get();
            l--;
        } while(savedPlace == '.');

        if(savedPlace == 'Z'){
            solution.push_back(0);
            string rest;
            cin>>rest;
            continue;
        }
        

        while(l--){
            place = cin.get();
            if(place == 'Z'){
                minDistance = 0;
                if(l != 0){
                    string rest;
                    cin>>rest;
                }
                break;
            }

            if(place == '.'){
                distance++;
            } else if(place != savedPlace){
                if(distance < minDistance){
                    minDistance = distance; 
                }

                distance = 1;
                savedPlace = place;

            } else if(place == savedPlace){
                distance = 1;
            }
        }

        solution.push_back(minDistance);
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<solution[i]<<endl;
    }
}
*/


// (1 mid) got inturrepted when solving it but anyway i took a lot of time (more then 40min)