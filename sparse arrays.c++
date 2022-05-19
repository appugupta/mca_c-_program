#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
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
        //cout<<s<<endl;
        cout<<count[s]<<endl;
    }
    return 0;
}