#include <iostream>
#include <list>

using namespace std;

class Graph {
private:
    int V;
    list<int> *l;

public:
    Graph (int v) {
        this->V = v;
        this->l = new list<int>[this->V];
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

    void addEdge(int i, int j, bool undir = true) {
        this->l[i].push_back(j);
        if (undir) this->l[j].push_back(i);
    }

    bool dfs(int start, bool *visited, int parent) {
    
        visited[start] = true;
        for (int nbr: this->l[start]) {
            if (!visited[nbr]) {
                bool cycle_present = dfs(nbr, visited, start);
                if (cycle_present) return true;
            }
            else if (start != parent) return true;
        }

        return false;
    }

    bool isCyclic(int start) {
        bool *visited = new bool[this->V]{false};
        return dfs(start, visited, -1);
    }
};

int main(void) {
    Graph myGraph(6);
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 4);
    // myGraph.addEdge(2, 1);
    // myGraph.addEdge(3, 4);
    // myGraph.addEdge(4, 5);
    // myGraph.addEdge(2, 3);
    // myGraph.addEdge(3, 5);

    myGraph.print();
    cout << endl;

    // cout << "Is cyclic: " << (myGraph.isCyclic(0) ? "Yes" : "No") << endl;
    cout << "Is cyclic: ";
    if (myGraph.isCyclic(0)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}