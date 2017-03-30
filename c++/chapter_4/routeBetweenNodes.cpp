#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
	public:
		int V;
		vector<int> *adj;
		Graph(int);
		void addEdge(int, int);
		bool isRoute(int, int);
};

Graph :: Graph(int V) {
	this->V = V;
	adj = new vector<int>[V];
}

void Graph :: addEdge(int x, int y) {
	adj[x].push_back(y);
}

bool Graph :: isRoute(int x, int y) {
	if(x == y) {
		return true;
	}

	vector<bool> visited(V, false);
	queue<int> q;
	q.push(x);

	while(!q.empty()) {
		int temp = q.front();
		if(temp == y) {
			return true;
		}
		q.pop();
		int len = adj[temp].size();
		for(int i=0; i<len; i++) {
			if(visited[adj[temp][i]] == false) {
				q.push(adj[temp][i]);
			}
			visited[temp] = true;
		}
	}
	return false;
}

int main(){
	
    Graph g(6);	
    g.addEdge(5, 2);
    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(2, 3);
    g.addEdge(3, 1);

    cout<<g.isRoute(5,4)<<endl; // false
    cout<<g.isRoute(5,1)<<endl; // true

    return 0;
}