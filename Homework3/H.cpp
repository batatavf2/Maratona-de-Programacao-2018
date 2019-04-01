#include <bits/stdc++.h>

using namespace std;

typedef struct tape
{
	bool reach = false;
	vector<long long int> tracks;

}tape;



int main()
{
	long long int tot, n, aux;
	

	while(scanf("%lld %lld", &tot, &n) != EOF) {
		tape fita[100005];
		fita[0].reach = true;
		for(long long int i = 1; i <= n; i++) {
			scanf("%lld", &aux);
			for(long long int j = tot; j >= 0; j--) {
				if(fita[j].reach == true && j+aux <= tot) {
					fita[j+aux].reach = true;
					fita[j+aux].tracks = fita[j].tracks;
					fita[j+aux].tracks.push_back(aux);
				}
			}
		}
		for(long long int i = tot; i > 0; i--) {
			if(fita[i].reach) {
				int tam = fita[i].tracks.size();
				for(int j = 0; j < tam; j++) {
					printf("%lld ", fita[i].tracks[j]);
				}
				printf("sum:%lld\n", i);
				break;
			}
		}
	}
	return 0;
}