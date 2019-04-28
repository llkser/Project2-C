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

void routeFinding(int a_ID,int b_ID,vector<Vertex>& myMap)
{
    int a=findID(a_ID);
    int b=findID(b_ID);
    if(a==-1||b==-1)
        return -1;
    else if(a==b)
        return 0;
    else{
        struct dijkstra *route=new struct dijkstra[myMap.size()];
        delete
    }
}

