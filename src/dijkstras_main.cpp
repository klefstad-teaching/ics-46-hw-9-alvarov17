#include "dijkstras.h"

int main()
{
    int dest = 3;
    Graph g;
    file_to_graph("small.txt", g);
    vector<int> prev{g.numVertices, -1};
    vector<int> distances = dijkstra_shortest_path(g, 0, prev);
    vector<int> short_path = extract_shortest_path(distances, prev, dest);
    print_path(short_path, distances[dest]);
    return 0;
}