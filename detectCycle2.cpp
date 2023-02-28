#include <iostream>
#include <list>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

public:
    Graph(int v) {
        this->V = v;
        this->l = new list<int>[this->V];
    }

    void addEdge(int i, int j, bool undir = true) {
        this->l[i].push_back(j);
        if (undir) this->l[j].push_back(i);
    }

    void print() {
        for (int i = 0; i < this->V; i++) {
            cout << i << " : ";
            for (int node: this->l[i]) {
                cout << node << ", ";
            }
            cout << endl;
        }
    }

    bool dfs(int node, vector<bool> &visited, int parent) {

        visited[node] = true;
        for (int nbr: this->l[node]) {
            if (!visited[nbr]) {
                bool contains_cycle = dfs(nbr, visited, node);
                if (contains_cycle) return true;
            }
            else if (nbr != parent) return true; 
        }

        return false;
    }

    bool isCyclic() {
        vector<bool> visited (this->V, false);
        return dfs(0, visited, 0);
    }
};


int main(void) {
    Graph myGraph(6);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 4);
    myGraph.addEdge(2, 1);
    // myGraph.addEdge(3, 4);
    myGraph.addEdge(4, 5);
    myGraph.addEdge(2, 3);
    // myGraph.addEdge(3, 5);

    myGraph.print();
    cout << endl;

    // string cycle = myGraph.isCyclic() ? "Yes" : "No";
    // cout << "Is cyclic: " << cycle << endl;
    
    if (myGraph.isCyclic()) cout << "Contains cycle" << endl;
    else cout << "No cycle" << endl;

    return 0;
}