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

//Main function including an user interface.
int main(int argc, char **argv)
{
    vector<Vertex> myMap;
    char str[100];

    cout<<"*************************"<<endl;
    cout<<"          myMap          "<<endl;
    cout<<"*************************"<<endl<<endl;
    if(argc!=2)
    {
        cout<<"No data file input!"<<endl;
        cout<<"Please input a date file:"<<endl;
        cin>>str;
        while(!readFile(str,myMap))
        {
            cout<<"Data file unavailable!"<<endl;
            cout<<"Please input a date file:"<<endl;
            cin>>str;
            myMap.clear();
        }
    }
    else{
        while(!readFile(argv[1],myMap))
        {
            cout<<"Data file unavailable!"<<endl;
            cout<<"Please input a date file:"<<endl;
            cin>>str;
            myMap.clear();
        }
    }
    cout<<"Welcome!"<<endl<<endl;

    int flag=0;
    int a,b;
    while(true)
    {
        cout<<"1. insert new data into myMap."<<endl;
        cout<<"2. print myMap out."<<endl;
        cout<<"3. Shortest route finding"<<endl;
        cout<<" 'q' to quit."<<endl<<endl;
        if(cin>>flag)
        {
            switch(flag){
            case 1:
                cout<<"Please input a date file:"<<endl;
                cin>>str;
                if(!readFile(str,myMap))
                    cout<<"Data file unavailable!"<<endl;
                break;
            case 2:
                printMap(myMap);
                break;
            case 3:
                cout<<"Please input two points to find the shortest route between them:"<<endl;
                cout<<"Point a ID = ";
                cin>>a;
                cout<<"Point b ID = ";
                cin>>b;
                routeFinding(a,b,myMap);
                break;
            }
        }
        else
            break;
        cout<<endl;
    }

    return 0;
}
