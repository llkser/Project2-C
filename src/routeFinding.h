#ifndef ROUTEFINDING_H
#define ROUTEFINDING_H
#include <vector>
#include <string>
using namespace std;

//A structure to store the data of points'ID in the shortest route.
struct dijkstra{
    double length=0;
    vector<int> routeFound;
};

//Functions to find the shortest route between two points a and b in myMap.
void routeFinding(int a_ID,int b_ID,vector<Vertex>& myMap);
int findMin(struct dijkstra *route,set<int>& flag,int s);
void printRoute(vector<int> &routeFound,vector<Vertex>& myMap);

#endif
