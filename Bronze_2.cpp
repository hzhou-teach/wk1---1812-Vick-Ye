#include<cstdio>
// Vick Ye
// 10/10
// 8:49

int N;
int s[100];
int t[100];
int b[100];

int main() {
	FILE * in = fopen("blist.in", "r");
	fscanf(in, "%d", &N);
	for(int i = 0; i < N; i++) {
		fscanf(in, "%d %d %d", &s[i], &t[i], &b[i]);
	}
	fclose(in);

	int max = 0;
	for(int time = 0; time < 1000; time++) {
		int overlap = 0;
		for(int i = 0; i < N; i++) {
			if(time >= s[i] && time <= t[i]) {
				overlap += b[i];
			}
		}
		max = max > overlap ? max : overlap;
	}

	FILE * out = fopen("blist.out", "w");
	fprintf(out, "%d\n", max);
	fclose(out);

	return 0;
}
