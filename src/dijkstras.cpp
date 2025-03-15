#include "dijkstras.h"

vector<int> dijkstra_shortest_path(const Graph& G, int source, vector<int>& previous)
{
    int numVertices = G.size();
    vector<int> distance(numVertices, INF);
    vector<bool> visited(numVertices, false);
    distance[source] = 0;
    fill(previous.begin(), previous.end(), -1);
    priority_queue< pair<int, int>, vector<pair<int, int>>, MyComparator > minHeap;
    minHeap.push({0, source});
    while (!minHeap.empty())
    {
        int u = minHeap.top().second;
        minHeap.pop();
        if (visited[u]) continue;
        visited[u] = true;
        for (Edge e : G[u])
        {
            int v = e.dst;
            int weight = e.weight;
            if (!visited[v] && distance[u] + weight < distance[v])
            {
                distance[v] = distance[u] + weight;
                previous[v] = u;
                minHeap.push({distance[v], v});
            }
        }
    }
    return distance;
}

vector<int> extract_shortest_path(const vector<int>& /*distances*/, const vector<int>& previous, int destination)
{
    stack<int> path;
    int v = destination;
    while (v != -1)
    {
        path.push(v);
        v = previous[v];
    }
    vector<int> shortest_path;
    while (!path.empty())
    {
        shortest_path.push_back(path.top());
        path.pop();
    }
    return shortest_path;
}

void print_path(const vector<int>& v, int total)
{
    for (int num : v)
    {
        cout << num << " ";
    }
    cout << endl;
    cout << "Total cost is " << total << endl;    
}
