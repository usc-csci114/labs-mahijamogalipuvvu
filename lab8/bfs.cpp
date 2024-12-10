#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>

using namespace std;

void readIn(string& filename, map<char, set<char>>& graph) {
    ifstream file(filename);

    string line;
    while (getline(file, line)) {
        stringstream ss(line);

        char vertex, edge;
        set<char> neighbors;

        ss >> vertex; 

        while (ss >> edge) 
            if (edge != '0') 
                neighbors.insert(edge); 
            
        graph[vertex] = neighbors; 
    }

    file.close();
}

map<char, int> BFS(map<char, set<char>>& graph, char startVertex) {

    queue<char> q;               
    set<char> visited;  
    map<char, int> depth; 
         

    q.push(startVertex);
    visited.insert(startVertex);
    depth[startVertex] = 0;

    while (!q.empty()) {
        char current = q.front();
        q.pop();

        for (char neighbor : graph.at(current)) {
            if (visited.count(neighbor) == 0) { 
                q.push(neighbor);
                visited.insert(neighbor);
                depth[neighbor] = depth[current] + 1;
            }
        }
    }

    return depth;
}

int main(int argc, char* argv[]) {
    string filename = argv[1];
    map<char, set<char>> graph;
    char input;


    readIn(filename, graph);

    cout << "Processed file " << filename << ". Found " << graph.size() << " vertex: ";
    for (auto it = graph.begin(); it != graph.end(); ++it) 
        cout << it->first;

    cout << endl;


    cout << "please enter the vertex you would like to start BFS: ";
    cin >> input;
    map<char, int> BFSOutput = BFS(graph, input);

    cout << "BFS starting at " << input << ": ";
    for (auto& pair : BFSOutput) 
        cout << pair.first << ":" << pair.second;
            
    cout << endl;

    return 0;
}
