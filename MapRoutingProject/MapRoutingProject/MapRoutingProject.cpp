#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int verticesNum, edgesNum, routesNum;
pair <long double , long double> locations[99999];
vector<int> map[99999];

void ReadMap() {
    fstream myMap;
    string s;
    myMap.open("Map.txt");

    myMap >> s;
    verticesNum = stoi(s);
    myMap >> s;
    edgesNum = stoi(s);

    int vert,x, y;
    for (int i = 0; i < verticesNum; i++) {
        myMap >> s;
        vert = stoi(s);
        myMap >> s;
        x = stoi(s);
        myMap >> s;
        y = stoi(s);

        locations[vert].first = x;
        locations[vert].second = y;
    }

    int start, end;
    for (int i = 0; i < edgesNum; i++) {
        myMap >> s;
        start = stoi(s);
        myMap >> s;
        end = stoi(s);
        
        map[start].push_back(end);
        map[end].push_back(start);
    }

    myMap.close();
}

long double calcDistance(pair<long double, long double> start, pair<long double, long double> end) {
    return sqrt(pow(end.first - start.first, 2) +
        pow(end.second - start.second, 2) * 1);
}

void findPath(int start, int end) {
    stack<int> path;
    vector<long double> distance(99999, 999999);
    vector<int> from(99999, -1);
    vector<int> visited(99999, 0);
    queue<int> toVisit;
    toVisit.push(start);
    distance[start] = 0;
    from[start] = start;
    
    while (!toVisit.empty()) {
        int node = toVisit.front();
        toVisit.pop();
        if (visited[node]) continue;
        visited[node] = 1;
        for (int i = 0; i < map[node].size(); i++) {
            int next = map[node][i];
            if (calcDistance(locations[node], locations[next]) + distance[node] <= distance[next]) {
                distance[next] = calcDistance(locations[node], locations[next]) + distance[node];
                from[next] = node;
                toVisit.push(next);
            }
        }
    }
    
    for (int i = end; i != start; i = from[i]) path.push(i);
    path.push(start);

    while (!path.empty()) {
        cout << path.top();
        path.pop();
        if (!path.empty()) cout << "-";
    }
}

void solve() {
    fstream myRoutes;
    myRoutes.open("ShortRoutes100.txt");
    string s;
    myRoutes >> s;
    routesNum = stoi(s);
    int start, end;
    for (int i = 0; i < routesNum; i++) {
        myRoutes >> s;
        start = stoi(s);
        myRoutes >> s;
        end = stoi(s);
        findPath(start, end);
        cout << endl;
    }

    myRoutes.close();
}

int main()
{
    ReadMap();
    
    solve();
    //findPath(4, 3);

    //std::cout << "Hello World!\n";
}