#include "dijkstras.h"

int main()
{
    Graph g;
    file_to_graph("medium.txt", g);
    vector<int> prev{g.numVertices, -1};
    vector<int> distances = dijkstra_shortest_path(g, 0, prev);
    for (int i = 0; i < 6 ; ++i) {
        vector<int> short_path = extract_shortest_path(distances, prev, i);
        print_path(short_path, distances[i]);
    }
    return 0;
}