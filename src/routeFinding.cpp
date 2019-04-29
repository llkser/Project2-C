#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <climits>
using namespace std;
#include "mapStructure.h"
#include "buildMap.h"
#include "routeFinding.h"

//A function to find the shortest route between two points a and b in myMap.
void routeFinding(int a_ID,int b_ID,vector<Vertex>& myMap)
{
    int a=findID(a_ID,myMap);
    int b=findID(b_ID,myMap);
    if(a==-1||b==-1)
        cout<<"Points unavailable!"<<endl;
    else if(a==b)
        cout<<"Same points input!"<<endl;
    else{
        struct dijkstra *route=new struct dijkstra[myMap.size()];
        set<int> flag;
        flag.insert(a);
        route[a].length=0;
        route[a].routeFound.push_back(a);
        struct edge *next;
        while(!flag.count(b))
        {
            next=myMap[a].next;
            while(next)
            {
                if(route[next->V_index].length==0||route[next->V_index].length>route[a].length+next->length)
                {
                    route[next->V_index].length=route[a].length+next->length;
                    route[next->V_index].routeFound.clear();
                    for(int i=0;i<route[a].routeFound.size();i++)
                        route[next->V_index].routeFound.push_back(route[a].routeFound[i]);
                    route[next->V_index].routeFound.push_back(next->V_index);
                }
                next=next->next;
            }
            a=findMin(route,flag,myMap.size());
            flag.insert(a);
            if(a==-1)
                break;
        }
        if(flag.count(b))
        {
            cout<<"The shortest route between the given points is:"<<endl;
            cout<<"From point ID="<<myMap[route[b].routeFound[0]].ID<<endl;
            for(int i=1;i<route[b].routeFound.size();i++)
                cout<<"-> Point ID="<<myMap[route[b].routeFound[i]].ID<<endl;
            cout<<"The length of the shortest route = "<<route[b].length<<endl;
            cout<<"Print the route in myMap? (Y/N)"<<endl;
            char ch;
            cin>>ch;
            if(ch=='Y')
                printRoute(route[b].routeFound,myMap);
        }
        else
            cout<<"No shortest route between the given points!"<<endl;
        delete [] route;
    }
}

//A function to find the index of next point in a dijkstra's operation.
int findMin(struct dijkstra *route,set<int>& flag,int s)
{
    double mi=-1;
    int index=-1;
    for(int i=0;i<s;i++)
    {
        if(!flag.count(i)&&route[i].length!=0)
        {
            if(mi==-1||mi>route[i].length)
            {
                mi=route[i].length;
                index=i;
            }
        }
    }
    return index;
}

//A function to print the shortest route into a file named "MyRoute.dat".
void printRoute(vector<int> &routeFound,vector<Vertex>& myMap)
{
    fstream fout;
    fout.open("MyRoute.dat",ios::trunc|ios::out);
    for(int i=0;i<routeFound.size();i++)
        fout<<myMap[routeFound[i]].lon<<" "<<myMap[routeFound[i]].lat<<endl;
    fout.close();
    cout<<"Complete!"<<endl;
}




















