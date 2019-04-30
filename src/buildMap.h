#ifndef MAPCONSTRUCTOR_H
#define MAPCONSTRUCTOR_H
#include <vector>
#include <string>
using namespace std;

//A structure to store the data of ways in map temporarily.
struct link{
    int ID,a_ID,b_ID;
    double length;
    link(int i,int a,int b,double l): ID(i),a_ID(a),b_ID(b),length(l) {};

};

//Functions to build myMap from a file address in str.
int readFile(char* str, vector<Vertex>& myMap);
void addEDge(int x_ID,int y_ID,int id,double len,vector<Vertex>& myMap);
int findID(int ID, vector<Vertex>& myMap);
template <class Type>
Type stringToNum(const string& str);
void printMap(vector<Vertex>& myMap);

#endif
