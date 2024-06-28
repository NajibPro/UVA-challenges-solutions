#include <iostream>
#include <bitset>

using namespace std;

const int maxSize = 100000;

struct Node{
    bitset<2> number;
    Node(){
       
    }

    Node(int number){
        if(number > 0) return;

        if(number == 0){
            this->number.set(1); return;
        }

        this->number.set(0);
    }

    char getStatus(){
        if(number.test(1)){
            return '0';
        }

        if(number.test(0)){
            return '-';
        }

        return '+';
    }
};

const Node identityNode = Node(5);



Node tree[4 * maxSize];

Node merge(Node a, Node b){
    Node result;

    if(a.number.test(1) || b.number.test(1)){
        result.number.set(1);
        return result;
    }

    if(a.number.test(0) != b.number.test(0)){
        result.number.set(0);
    }

    return result;
}


void build(int nodeIndex, int leftIndex, int rightIndex, int space[]){
    if(leftIndex == rightIndex){
        tree[nodeIndex] = Node(space[leftIndex]);
        return;
    }

    int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);

    int leftChildIndex = nodeIndex * 2;
    int rightChildIndex = leftChildIndex + 1;

    build(leftChildIndex, leftIndex, midIndex, space);
    build(rightChildIndex, midIndex + 1, rightIndex, space);

    tree[nodeIndex] = merge(tree[leftChildIndex], tree[rightChildIndex]);
}

Node query(int nodeIndex, int leftIndex, int rightIndex, int leftQueryIndex, int rightQueryIndex){
    if (leftIndex > rightQueryIndex || rightIndex < leftQueryIndex)
        return identityNode;


    if (leftIndex >= leftQueryIndex && rightIndex <= rightQueryIndex)
        return tree[nodeIndex];


    int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);

    int leftChildIndex = nodeIndex * 2;
    int rightChildIndex = leftChildIndex + 1;

    return merge(
        query(leftChildIndex, leftIndex, midIndex, leftQueryIndex, rightQueryIndex),
        query(rightChildIndex, midIndex + 1, rightIndex, leftQueryIndex, rightQueryIndex)
    );
}

void update(int nodeIndex, int updateIndex, int leftIndex, int rightIndex, int value){
    if(updateIndex > rightIndex || updateIndex < leftIndex){
        return;
    }

    if(updateIndex == rightIndex && rightIndex == leftIndex){
        tree[nodeIndex] = value;
        return;
    }

    int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);

    int leftChildIndex = nodeIndex * 2;
    int rightChildIndex = leftChildIndex + 1;

    update(leftChildIndex, updateIndex, leftIndex, midIndex, value);
    update(rightChildIndex ,updateIndex, midIndex + 1, rightIndex, value);

    tree[nodeIndex] = merge(tree[leftChildIndex], tree[rightChildIndex]);
}


int main(){
    int n, k;
    
    while(cin>>n>>k && !cin.eof()){
        int numbers[n];

        for(int i = 0; i < n; i++){
            cin>>numbers[i];
        }

        build(1, 0, n-1, numbers);

        for(int i = 0; i < k; i++){
            int a, b;
            char command;
            cin>>command>>a>>b;

            if(command == 'C'){

                update(1, a-1, 0, n-1, b);
                continue;
            }

            if(command == 'P'){
                cout<<query(1, 0, n-1, a-1, b-1).getStatus();
            }
            

            
        }

        cout<<endl;
    }
}