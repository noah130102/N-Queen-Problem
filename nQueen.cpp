#include<iostream>
using namespace std;

bool isSafe (int** arr , int x , int y , int n){
    for (int i = 0; i < x; i++)
    {
        if (arr[i][y]==1)
        {
            return false;
        }
    }
    int r = x;
    int c = y;
    while (c<=n-1 && r>=0)
    {
        if (arr[r][c]==1)
        {
            return false;
        }
        c++;
        r--;
    }
    r = x;
    c = y;
    while (c>=0 && r>=0)
    {
        if (arr[r][c]==1)
        {
            return false;
        }
        c--;
        r--;
    }
    return true;
}

bool NQP (int** arr , int x , int n){
    if (x>=n)
    {
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (isSafe(arr,x,i,n))
        {
            arr[x][i]=1;

            if (NQP(arr,x+1,n))
            {
                return true;
            }
            arr[x][i]=0;
        }
        
    }
    return false;

}
int main()
{
    int n ;
    cin>>n;

    int** arr = new int*[n];
    for (int i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            arr[i][j]=0;
        }
        
    }
    
    
        
    
    if (NQP(arr,0,n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
    return 0;
}