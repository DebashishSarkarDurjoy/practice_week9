#include <iostream>
#include <vector>
#include <list>

using namespace std;

class Graph {
public:
    int V;
    list<int> *l;

    Graph(int V) {
        this->V = V;
        this->l = new list<int> [this->V];
    }

    void addEdge(int i, int j) {
        this->l[i].push_back(j);
        this->l[j].push_back(i);
    }

    void showGraph() {
        for (int i = 0; i < this->V; i++) {
            cout << i << ": ";
            for (int num: this->l[i]) {
                cout << num << ", ";
            }
            cout << endl;
        }
    }

    bool isCyclic(int start) {
        vector<bool> visited(this->V, false);
        return dfs(start, visited, -1);
    }

    bool dfs(int node, vector<bool> &visited, int parent) {
        visited[node] = true;
        for (int nbr: this->l[node]) {
            if (!visited[nbr]) {
                bool isCyclePresent = dfs(nbr, visited, node);
                if (isCyclePresent) return true;
            }
            else if (nbr != parent) {
                return true;
            }

        }
        return false;
    }
};

int main(void) {
    Graph g(6);
      g.addEdge(0,1);
      g.addEdge(0,4);
      g.addEdge(2,1);
    //   g.addEdge(3,4);
      g.addEdge(4,5);
      g.addEdge(2,3);
    //   g.addEdge(3,5);
    g.showGraph();
    cout << (g.isCyclic(0) ? "Yes" : "No") << endl;

    return 0;
}
