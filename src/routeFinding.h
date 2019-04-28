#ifndef ROUTEFINDING_H
#define ROUTEFINDING_H
#include <vector>
#include <string>
using namespace std;

struct dijkstra{
    int flag=0;
    double length;
    vector<vector<int>> routeFound;
};
//
void routeFinding(int a_ID,int b_ID,vector<Vertex>& myMap);

#endif
