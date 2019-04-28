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

int main(int argc, char **argv)
{
    vector<Vertex> myMap;
    if(readFile("Final_Map.map",myMap))
        cout<<"complete"<<endl;
    else
        cout<<"No file found"<<endl;;
    return 0;
}
