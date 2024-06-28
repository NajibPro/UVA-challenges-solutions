#include <iostream>
#include <vector>
using namespace std;

const string hexaDigits[] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "A", "B", "C", "D", "E", "F"};

struct Byte{
    int number = 0;

    Byte(int n){
        number = n;
    }

    Byte(){

    }

    void increase(){
        number++;
        if(number >= 256){
            number = 0;
        }
    }

    void decrease(){
        number--;
        if(number <= -1){
            number = 255;
        }
    }

    void display(){
        string hexaNumber("");
        int result(number);
        do{
            hexaNumber = hexaDigits[result % 16] + hexaNumber;
            result /= 16;
        }while(result != 0);

        if(hexaNumber.size() == 2){
            cout<<" "<<hexaNumber;
        } else {
            cout<<" "<<"0"<<hexaNumber;
        }
    }
};

struct Memory{
    Byte buffer[100];
    int i = 0;

    Memory(){

    }

    void instruction(char symbol){
        if(symbol == '+'){
            buffer[i].increase();
        }else if(symbol == '-'){
            buffer[i].decrease();
        }else if(symbol == '<'){
            i--;
            if(i <= -1){
                i = 99;
            }
        }else if(symbol == '>'){
            i++;
            if(i >= 100){
                i = 0;
            }
        }else{
            //do nothing i guess
        }
    }

    void display(){
        for(int j = 0; j < 100; j++){
            buffer[j].display();
        }
    }

    void compile(string symbols){
        for(int j = 0; j < symbols.size(); j++){
            instruction(symbols[j]);
        }
    }
};






int main(){
    vector<Memory> solution;
    int testCases;
    int counter(1);

    cin>>testCases;

    while(testCases--){
        string symbols;
        Memory m;
        cin>>symbols;

        m.compile(symbols);

        solution.push_back(m);
        
    }

    for(int i = 0; i < solution.size(); i++){
        cout<<"Case "<<counter++<<":";
        solution[i].display();
        cout<<endl;
    }
}

// (3 med) solved in 56min 57s