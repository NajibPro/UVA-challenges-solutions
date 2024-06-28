#include <iostream>

using namespace std;

int x, y, n, s, m(1), current(1);

// up0, left1, down2, right3
int direction(0);

void initCoordinates(){
    x = y = (s / 2) + 1;
}

void setDirection(){
    direction = (direction + 1) % 4;
}

void setCoordinates(){
    switch (direction)
    {
    case 0:
        y = y + m;
        break;

    case 1:
        x = x - m;
        break;

    case 2:
        y = y - m;
        break;

    case 3:
        x = x + m;
        break;
    
    default:
        break;
    }
}

void setCurrentNumber(){
    current += m;
}

void setStepWidth(){
    if(direction % 2 == 0){
        m++;
    }
}

void checkOverflow(){
    if(current <= n){
        return;
    }

    int diff = current - n;
    current = n;

    switch (direction)
    {
    case 0:
        y = y - diff;
        break;

    case 1:
        x = x + diff;
        break;

    case 2:
        y = y + diff;
        break;

    case 3:
        x = x - diff;
        break;
    
    default:
        break;
    }
}

void solution(){
    initCoordinates();
    while(n != current){
        setCoordinates();
        setCurrentNumber();
        checkOverflow();
        setDirection();
        setStepWidth();
    }
}

void reset(){
    cin>>s>>n;
    m = 1; current = 1;
    direction = 0;
}

int main(){

    cin>>s>>n;

    while(!(n == 0 && s == 0)){
        solution();
        
        cout<<"Line = "<<y<<", column = "<<x<<"."<<endl;
        reset();
    }
    return 0;
}

//ds 17, it took me days to solve it hh.