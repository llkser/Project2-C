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
    if(readFile("Final_Map.map",myMap))
        printMap(myMap);
    else
        cout<<"No file found"<<endl;
    int a,b;
    while(cin>>a>>b)
        routeFinding(a,b,myMap);
    return 0;
}
