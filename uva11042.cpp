#include <iostream>
// the best thing to do now is to find the solution for this problem by searching
using namespace std;

const unsigned int maxSize = 1050000;

struct Node{
    unsigned int bucCount;
    Node(){
        bucCount = 0;
    }

    Node(unsigned int n){
        this->bucCount = n;
    }
};

const Node identityNode = Node(0);



Node tree[4 * maxSize];

Node merge(Node a, Node b){

    return Node(a.bucCount + b.bucCount);
}


void build(unsigned int nodeIndex, unsigned int leftIndex, unsigned int rightIndex, const string& space){
    if(leftIndex == rightIndex){
        tree[nodeIndex] = Node(space[leftIndex] == '0' ? 0 : 1);
        return;
    }

    unsigned int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);

    unsigned int leftChildIndex = nodeIndex * 2;
    unsigned int rightChildIndex = leftChildIndex + 1;

    build(leftChildIndex, leftIndex, midIndex, space);
    build(rightChildIndex, midIndex + 1, rightIndex, space);

    tree[nodeIndex] = merge(tree[leftChildIndex], tree[rightChildIndex]);
}

Node query(unsigned int nodeIndex, unsigned int leftIndex, unsigned int rightIndex, unsigned int leftQueryIndex, unsigned int rightQueryIndex){
    if(tree[nodeIndex].bucCount == 0){
        return Node(0);
    }

    if (leftIndex > rightQueryIndex || rightIndex < leftQueryIndex)
        return identityNode;


    if (leftIndex >= leftQueryIndex && rightIndex <= rightQueryIndex)
        return tree[nodeIndex];


    if(tree[nodeIndex].bucCount == rightIndex - leftIndex + 1){
        return Node(min(rightIndex, rightQueryIndex) - max(leftIndex, leftQueryIndex) + 1);
    }


    unsigned int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);

    unsigned int leftChildIndex = nodeIndex * 2;
    unsigned int rightChildIndex = leftChildIndex + 1;

    Node leftNode = query(leftChildIndex, leftIndex, midIndex, leftQueryIndex, rightQueryIndex);
    Node rightNode = query(rightChildIndex, midIndex + 1, rightIndex, leftQueryIndex, rightQueryIndex);
    /*Node tNode = Node(tree[nodeIndex].bucCount - leftNode.bucCount);*/

    return merge(leftNode, rightNode);
}



void updateTree(unsigned int nodeIndex, unsigned int leftIndex, unsigned int rightIndex, unsigned int leftUpdateIndex, unsigned int rightUpdateIndex, const string& space){
    if (leftIndex > rightUpdateIndex || rightIndex < leftUpdateIndex)
        return;


    if (leftUpdateIndex >= leftIndex && rightUpdateIndex <= rightIndex)

        build(nodeIndex, leftIndex, rightIndex, space);
        return;


    unsigned int midIndex = leftIndex + ((rightIndex - leftIndex) / 2);

    unsigned int leftChildIndex = nodeIndex * 2;
    unsigned int rightChildIndex = leftChildIndex + 1;

    updateTree(leftChildIndex, leftIndex, midIndex, leftUpdateIndex, rightUpdateIndex, space);
    updateTree(rightChildIndex, midIndex + 1, rightIndex, leftUpdateIndex, rightUpdateIndex, space);

    tree[nodeIndex] = merge(tree[leftChildIndex], tree[rightChildIndex]);
}

void update(char order, unsigned int a, unsigned int b, string& space){
    switch (order)
    {
    case 'F':
        for(unsigned int i = a; i <= b; i++){
            space[i] = '1';
        }
        break;
    

    case 'I':
        for(unsigned int i = a; i <= b; i++){
            space[i] = space[i] == '0' ? '1' : '0';
        }
        break;

    case 'E':
        for(unsigned int i = a; i <= b; i++){
            space[i] = '0';
        }
        break;

    
    default:
        break;
    }

    updateTree(1, 0, space.size() - 1, a, b, space);
}

int main(){
    unsigned int tests, counter(0);

    cin>>tests;


    while(tests--){
        unsigned int m;
        cin>>m;
        string land = "";
        for(unsigned int i = 0; i < m; i++){
            unsigned int t;
            cin>>t;

            string somePirates;

            cin>>somePirates;

            for(unsigned int j = 0; j < t; j++){
                land += somePirates;
            }

        }

        build(1, 0, land.size() - 1, land);

        unsigned int q, godQuery(0);
        cin>>q;

        cout<<"Case "<<++counter<<":"<<endl;

        for(unsigned int i = 0; i < q; i++){
            char o;
            unsigned int a, b;

            cin>>o>>a>>b;


            if(o == 'S'){
                /*cout<<"the tree"<<endl;
                for(unsigned int i = 0; i < land.size() * 4; i++){
                    cout<<tree[i].bucCount<<'\t';
                }

                cout<<endl<<endl;

                cout<<"the land: "<<land<<endl<<endl;*/

                cout<<"Q"<<++godQuery<<": "<<query(1, 0, land.size() - 1, a, b).bucCount<<endl;
            }else{
                update(o, a, b, land);
            }


        }
    }
    return 0;
}