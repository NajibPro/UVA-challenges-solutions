#include <iostream>

using namespace std;

int main(){
    int l;
    string direction = "+x", instruction;


    while(cin>>l && l != 0){
        while(--l){
            cin>>instruction;
            if(direction == "+x"){
                if(instruction == "+y"){ direction = "+y"; continue;}
                if(instruction == "-y"){ direction = "-y"; continue;}
                if(instruction == "+z"){ direction = "+z"; continue;}
                if(instruction == "-z"){ direction = "-z"; continue;}
            }else if(direction == "-x"){
                if(instruction == "+y"){ direction = "-y"; continue;}
                if(instruction == "-y"){ direction = "+y"; continue;}
                if(instruction == "+z"){ direction = "-z"; continue;}
                if(instruction == "-z"){ direction = "+z"; continue;}
            }else if(direction == "+y"){
                if(instruction == "+y"){ direction = "-x"; continue;}
                if(instruction == "-y"){ direction = "+x"; continue;}
                if(instruction == "+z"){ direction = "+y"; continue;}
                if(instruction == "-z"){ direction = "+y"; continue;}
            }else if(direction == "-y"){
                if(instruction == "+y"){ direction = "+x"; continue;}
                if(instruction == "-y"){ direction = "-x"; continue;}
                if(instruction == "+z"){ direction = "-y"; continue;}
                if(instruction == "-z"){ direction = "-y"; continue;}
            }else if(direction == "+z"){
                if(instruction == "+y"){ direction = "+z"; continue;}
                if(instruction == "-y"){ direction = "+z"; continue;}
                if(instruction == "+z"){ direction = "-x"; continue;}
                if(instruction == "-z"){ direction = "+x"; continue;}
            }else if(direction == "-z"){
                if(instruction == "+y"){ direction = "-z"; continue;}
                if(instruction == "-y"){ direction = "-z"; continue;}
                if(instruction == "+z"){ direction = "+x"; continue;}
                if(instruction == "-z"){ direction = "-x"; continue;}
            }
        }

        cout<<direction<<endl;
        direction = "+x";
    }
}



// medium 10 got inturapted when solving it so no time


































/*#include <iostream>

using namespace std;

string deduceDirection(int a[], int b[]){
    if(b[0] - a[0] != 0){
        return b[0] - a[0] > 0 ? "+x" : "-x";
    }else if(b[1] - a[1] != 0){
        return b[1] - a[1] > 0 ? "+y" : "-y";
    }else if(b[2] - a[2] != 0){
        return b[2] - a[2] > 0 ? "+z" : "-z";
    }

    return "+x";
}

int main(){
    int l;

    while(cin>>l && l != 0){
        int a[3] = {l-1, 0, 0}, b[3] = {l, 0, 0};
        string direction;

        do{
            cin>>direction;
        }while(direction == "No" && l != 2 && l--);

        if(direction == "+x"){
            b[0]++;

            b[1] = a[1];
            b[2] = a[2];
        }else if(direction == "-x"){
            b[0]--;

            b[1] = a[1];
            b[2] = a[2];
        }else if(direction == "+y"){
            b[1]++;

            b[0] = a[0];
            b[2] = a[2];
        }else if(direction == "-y"){
            b[1]--;

            b[0] = a[0];
            b[2] = a[2];
        }else if(direction == "+z"){
            b[2]++;

            b[0] = a[0];
            b[1] = a[1];
        }else if(direction == "-z"){
            b[2]--;

            b[0] = a[0];
            b[1] = a[1];
        }
        for(int i = 2; i < l; i++){
            do{
                cin>>direction;
            }while(direction == "No" && i != l && i++);

            if(direction == "+x"){
                b[0]++; 
                a[0]++; 
            }else if(direction == "-x"){
                b[0]--;
                a[0]--;
            }else if(direction == "+y"){
                b[1]++;
                a[1]++;

            }else if(direction == "-y"){
                b[1]--;
                a[1]--;

            }else if(direction == "+z"){
                b[2]++;
                a[2]++;

            }else if(direction == "-z"){
                b[2]--;
                a[2]--;

            }
        }

        cout<<deduceDirection(a, b)<<endl;
    }
    return 0;
}
*/