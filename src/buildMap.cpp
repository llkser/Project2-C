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

//A function to read a file str into myMap.
int readFile(char* str, vector<Vertex>& myMap)
{
    string line,buf;
    fstream fin;
    fin.open(str,ios::in);
    if(fin.is_open())
    {
        int b,c,d;
        double len,la,lo;
        vector<link> dataFile;

        while(!fin.eof())
        {
            getline(fin,line);
            stringstream ss(line);

            while(ss>>buf)
            {
                if(buf=="<link")
                {
                    ss>>buf;
                    buf.erase(0,3);
                    b=stringToNum<int>(buf);
                    ss>>buf;
                    buf.erase(0,5);
                    c=stringToNum<int>(buf);
                    ss>>buf;
                    buf.erase(0,5);
                    d=stringToNum<int>(buf);
                    ss>>buf;
                    ss>>buf;
                    buf.erase(0,7);
                    len=stringToNum<double>(buf);
                    link *a=new link(b,c,d,len);
                    dataFile.push_back(*a);
                    delete a;
                }
                else if(buf=="<node")
                {
                    ss>>buf;
                    buf.erase(0,3);
                    b=stringToNum<int>(buf);
                    ss>>buf;
                    buf.erase(0,4);
                    la=stringToNum<double>(buf);
                    ss>>buf;
                    buf.erase(0,4);
                    lo=stringToNum<double>(buf);
                    if(findID(b,myMap)==-1)
                    {
                        Vertex *a=new Vertex(b,la,lo);
                        myMap.push_back(*a);
                        delete a;
                    }
                    else
                        cout<<"Node ID="<<b<<" already exists!"<<endl;
                }
                else
                    break;
            }
        }
        if(!dataFile.empty())
        {
            int x_ID,y_ID;
            for(int i=0;i<dataFile.size();i++)
            {
                x_ID=findID(dataFile[i].a_ID,myMap);
                y_ID=findID(dataFile[i].b_ID,myMap);
                if(x_ID!=-1&&y_ID!=-1)
                    addEDge(x_ID,y_ID,dataFile[i].ID,dataFile[i].length,myMap);
                else
                    cout<<"Way ID="<<dataFile[i].ID<<" unavailable!"<<endl;
            }
        }
        return 1;
    }
    else
        return 0;
}

//A function to add a edge between two given points x and y.
void addEDge(int x_ID,int y_ID,int id,double len,vector<Vertex>& myMap)
{
    struct edge *x_next,*y_next;
    x_next=myMap[x_ID].next;
    y_next=myMap[y_ID].next;
    if(x_next)
    {
        while(x_next->next)
            x_next=x_next->next;
        x_next->next=new edge(id,y_ID,len);
    }
    else
        myMap[x_ID].next=new edge(id,y_ID,len);
    if(y_next)
    {
        while(y_next->next)
            y_next=y_next->next;
        y_next->next=new edge(id,x_ID,len);
    }
    else
        myMap[y_ID].next=new edge(id,x_ID,len);
}

//A function to find the index of a point in myMap whose ID is given.
int findID(int ID, vector<Vertex>& myMap)
{
    for(int i=0;i<myMap.size();i++)
        if(myMap[i].ID==ID)
            return i;
    return -1;
}

//A template function to convert a string to a number.
template <class Type>
Type stringToNum(const string& str)
{
    stringstream ss(str);
    Type num;
    ss>>num;
    return num;
}

//A function to print myMap into a file named "MyMap.dat".
void printMap(vector<Vertex>& myMap)
{
    if(myMap.empty())
        cout<<"Map data not found!"<<endl;
    else{
        fstream fout;
        fout.open("MyMap.dat",ios::trunc|ios::out);
        struct edge *next;
        for(int i=0;i<myMap.size();i++)
        {
            if(myMap[i].next)
            {
                next=myMap[i].next;
                while(next)
                {
                    fout<<myMap[i].lon<<" "<<myMap[i].lat<<endl;
                    fout<<myMap[next->V_index].lon<<" "<<myMap[next->V_index].lat<<endl;
                    fout<<endl;
                    next=next->next;
                }
            }
            else
                fout<<myMap[i].lon<<" "<<myMap[i].lat<<endl<<endl;
        }
        fout.close();
        cout<<"Complete!"<<endl;
    }
}
