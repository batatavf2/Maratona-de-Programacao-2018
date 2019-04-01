#include<bits/stdc++.h>

int adj[30005], visited[30005], n;

int vis(int m){
    visited[m] = 1;
    if(m < n)
        vis(m + adj[m]);
}

int main(){

    int a,t;
    scanf("%d %d", &n, &t);

    for(int i=1; i<n; i++){
        scanf("%d", &a);
        adj[i] = a;
    }

    vis(1);
    if(visited[t]==1) 
        printf("YES\n");
    else 
        printf("NO\n");

    return 0;
}