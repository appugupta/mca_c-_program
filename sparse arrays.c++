#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    map<string,int> count;
    int n;
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        count[s]++;
    }
    cin>>n;
    while(n--){
        string s;
        cin>>s;
        cout<<count[s]<<endl;
    }
    return 0;
}
