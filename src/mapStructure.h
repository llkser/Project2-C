#ifndef MAPSTRUCTURE_H
#define MAPSTRUCTURE_H
#define PB push_back
typedef long long ll;

//Vertexes in a map.
struct Vertex{
    int ID;
    double lat,lon;
    struct edge *next;
    Vertex(int i,double la,double lo): ID(i),lat(la),lon(lo),next(NULL) {};
};
//Edges connected to every vertex.
struct edge{
    int ID,V_index;
    double length;
    struct edge *next;
    edge(int i1,int i2,double l): ID(i1),V_index(i2),length(l),next(NULL) {};
};

#endif
