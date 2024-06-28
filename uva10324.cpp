#include <iostream>
#include <fstream>

using namespace std;

const int maxSize = 1000000;

struct Node{
    bool has0, has1, isIdentity = false;
    Node(){

    }

    Node(char num, bool isI = false){
        isIdentity = isI;
        if(num == '0'){
            has0 = true; has1 = false;
        }else{
            has0 = false; has1 = true;
        }
    }

    bool same(){
        return isIdentity || (has0 && !has1) || (!has0 && has1);
    }
};

const Node identityNode = Node(0, true);



Node tree[4 * maxSize];

Node merge(Node a, Node b){
    if(a.isIdentity && b.isIdentity){
        return identityNode;
    }else if(a.isIdentity){
        return b;
    }else if(b.isIdentity){
        return a;
    }
    Node result;

    result.has0 = a.has0 || b.has0;
    result.has1 = a.has1 || b.has1;

    return result;
}


void build(int nodeIndex, int leftIndex, int rightIndex, const string& space){
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

    Node leftNode = query(leftChildIndex, leftIndex, midIndex, leftQueryIndex, rightQueryIndex);
    Node rightNode = query(rightChildIndex, midIndex + 1, rightIndex, leftQueryIndex, rightQueryIndex);

    return merge(leftNode, rightNode);
}


int main(){
    string binaryNum;
    int counter(1);

    while(cin>>binaryNum && !cin.eof()){

        build(1, 0, binaryNum.size() - 1, binaryNum);

        int q;

        cin>>q;

        cout<<"Case "<<counter++<<":"<<endl;

        for(int k = 0; k < q; k++){
            int i, j;
            cin>>i>>j;

            cout<<(query(1, 0, binaryNum.size() - 1, min(i, j), max(i, j)).same() ? "Yes" : "No")<<endl;
        }


    }

    return 0;
}

// medium 6 took a lot of time because i wrote "string space" instead of "const string& space" in line
// 51, it took it a lot of time to always copy the value of the space!!