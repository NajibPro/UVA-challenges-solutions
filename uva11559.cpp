#include <iostream>

using namespace std;

struct Hotel{
    int cost, available;

    Hotel(){
        cost = 0;
        available = 0;
    }

    Hotel(int c, int a){
        cost = c;
        available = a;
    }
};

int main(){
    int p, b, h, w;

    while(!cin.eof() && cin>>p>>b>>h>>w){
        Hotel hotel[h];
        for(int i = 0; i < h; i++){
            cin>>hotel[i].cost;
            for(int j = 0; j < w; j++){
                int a;
                cin>>a;
                hotel[i].available = max(a, hotel[i].available);
            }
        }

        int minCost(-1);

        for(int i = 0; i < h; i++){
            int hotelCost;
            if(hotel[i].available >= p && b >= hotel[i].cost * p){
                hotelCost = hotel[i].cost * p;
                if(hotelCost < minCost || minCost == -1){
                    minCost = hotelCost;
                }
            }
        }

        cout<<(minCost == -1 ? "stay home" : to_string(minCost))<<endl;
        
    }
}

// easy+ 6 solved in 32min and 35s