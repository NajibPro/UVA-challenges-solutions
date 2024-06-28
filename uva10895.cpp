#include <iostream>
#include <vector>
#include <limits>

using namespace std;

struct Node
{
    int name;
    int weight;

    Node(){

    }

    Node(int n, int w){
        name = n;
        weight = w;
    }
};


struct Graph{
    vector<vector<Node>> graph;
    int m, n;

    Graph(){

    }

    Graph(int m, int n){
        this->m = m;
        this->n = n;

        for(int i = 0; i < m; i++){
            vector<Node> emp;
            graph.push_back(emp);
        }
    }

    void insert(int u, int v, int w){
        graph[u].push_back(Node(v-1, w));

        for(int i = graph[u].size() - 1; i > 0; i--){
            if(graph[u][i].name < graph[u][i - 1].name){
                swap(graph[u][i], graph[u][i - 1]);
            }
        }
    }

    Graph transpose(){
        Graph transposedGraph(n, m);

        for(int i = 0; i < graph.size(); i++){
            for(int j = 0; j < graph[i].size(); j++){
                transposedGraph.insert(graph[i][j].name, i+1, graph[i][j].weight);
            }
        }

        return transposedGraph;


    }

    void display(){
        cout<<m<<" "<<n<<endl;
        for(int i = 0; i < graph.size(); i++){
            if(graph[i].empty()){
                cout<<0<<endl<<endl;
                continue;
            }

            cout<<graph[i].size()<<" ";


            for(int j = 0; j < graph[i].size(); j++){
                cout<<(graph[i][j].name+1);

                if(j != graph[i].size() - 1){
                    cout<<" ";
                }
            }

            cout<<endl;

            for(int j = 0; j < graph[i].size(); j++){
                cout<<graph[i][j].weight;

                if(j != graph[i].size() - 1){
                    cout<<" ";
                }
            }

            if(i != graph.size() - 1){
                cout<<endl;
            }
        }

        
    }
};

int main(){
    int m, n;
    bool first(true);

    while(cin>>m>>n){
        if(!first){
            cout<<endl;
        }else{
            first = false;
        }

        Graph g(m, n);

        for(int i = 0; i < m; i++){
            int size;
            cin>>size;

            if(size == 0){
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            int cols[size], weights[size];

            for(int j = 0; j < size; j++){
                cin>>cols[j];
            }

            for(int k = 0; k < size; k++){
                cin>>weights[k];
            }

            for(int j = 0; j < size; j++){
                g.insert(i, cols[j], weights[j]);
            }


        }

        g.transpose().display();
    }
    return 0;
}


// ds 15 solved in 1h and 30min