#include "dijkstras.h"

int main()
{
    Graph g;
    file_to_graph("src/small.txt", g);
    vector<int> prev{g.numVertices, -1};
    vector<int> path = dijkstra_shortest_path(g, 0, prev);
    vector<int> short_path = extract_shortest_path(prev, path, 0);
    print_path(short_path, 0);
    return 0;
}