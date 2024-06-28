#include <iostream>
#include <sstream>
#include <iomanip>

using namespace std;

int main(){
    string line;

    getline(cin, line);

    int currentDistance(0), leaks(0);
    double volume(0), neededVolume(0);

    while(true){
        istringstream ss(line);

        int d, n;
        string inst;

        ss>>d;
        ss>>inst;

        if(inst == "Fuel"){
            int distanceDiff = d - currentDistance;

            volume += ((distanceDiff * n * 1.0) / 100.0) + (leaks * distanceDiff);

            ss>>inst; ss>>n;

            if(d == 0 && inst == "consumption" && n == 0){
                break;
            }

            currentDistance = d;


        }else if(inst == "Leak"){
            int distanceDiff = d - currentDistance;
            volume += ((distanceDiff * n * 1.0) / 100.0) + (leaks * distanceDiff);

            leaks++;
            currentDistance = d;

        }else if(inst == "Gas"){
            int distanceDiff = d - currentDistance;
            ss>>inst;

            volume += ((distanceDiff * n * 1.0) / 100.0) + (leaks * distanceDiff);

            if(volume > neededVolume){
                neededVolume = volume;
            }

            volume = 0;
            currentDistance = d;
        }else if(inst == "Mechanic"){
            int distanceDiff = d - currentDistance;
            volume += ((distanceDiff * n * 1.0) / 100.0) + (leaks * distanceDiff);

            leaks = 0;
            currentDistance = d;
        }else{
            int distanceDiff = d - currentDistance;

            volume += ((distanceDiff * n * 1.0) / 100.0) + (leaks * distanceDiff);

            if(volume > neededVolume){
                neededVolume = volume;
            }

            cout<<fixed<<setprecision(3)<<neededVolume<<endl;

            currentDistance = 0;
            leaks = 0;
            volume = 0;
            neededVolume = 0;
        }

        getline(cin, line);

    }
    return 0;
}