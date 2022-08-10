int f(int x,int n,vector<int>&a,vector<bool> &del){
    int tmp=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(del[i]) continue;
        else{
            del[i]=true;
            int z=f(x+1,n,a,del);
            del[i]=false;
            tmp=min(z+a[i]/x+(a[i]%x>0),tmp);
        
        }
    }
    return (tmp==INT_MAX?0:tmp);
}
int Solution::solve(vector<int> &a){
    int n=a.size();
    vector<bool> del(n,false);
    return f(1,n,a,del);
}