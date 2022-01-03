#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;

int verticesNum, edgesNum, routesNum;
pair <double , double > locations[999999];
vector<int> map[999999];
pair<int, int> routes[999999];

void ReadInputs() {
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
    }

    myMap.close();

    fstream myRoutes;
    myRoutes.open("Routes.txt");
    myRoutes >> s;
    routesNum = stoi(s);
    for (int i = 0; i < routesNum; i++) {
        myRoutes >> s;
        start = stoi(s);
        myRoutes >> s;
        end = stoi(s);
        routes[i] = { start,end };
    }

    myRoutes.close();
}

double calcDistance(pair<double,double> start, pair<double,double> end) {
    return sqrt(pow(end.first - start.first, 2) +
        pow(end.second - start.second, 2) * 1.0);
}

void findPath(int start, int end) {
    vector<double> distance(verticesNum, 999999);
    vector<int> from(verticesNum, -1);
    
    distance[start] = 0;
    from[start] = start;

}

int main()
{
    //ReadInputs();


    //std::cout << "Hello World!\n";
}