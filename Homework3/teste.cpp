#include<bits/stdc++.h>

using namespace std;

int main(){

    int a,b;

    scanf("%d %d", &a, &b);

    int soma=0;

    vector<int>ordem;

    for(int i=0; i<a; i++){

        int x;

        scanf("%d", &x);

        ordem.push_back(x);
    }

    while(1){

        int ok=0;

        for(int j=0; j<a-1; j++){

            if(ordem[j]<ordem[j+1]){

                swap(ordem[j], ordem[j+1]);

                ok=1;
            }
        }

        if (ok==0)break;

    }

    for(int m=0; m < a; m++){

        soma+=ordem[m];

        if(soma>=b) {

            printf("%d\n", m+1);

            break;
        }

    }

    return 0;

}