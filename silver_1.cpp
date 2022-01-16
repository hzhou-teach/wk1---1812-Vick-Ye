#include<cstdio>
#include<algorithm>
// Vick Ye
// 1/10
// 1:34:22
// I have no idea how to optimize the amount of cows per bus
int main() {
	int N, M, C;
	FILE * in = fopen("convention.in", "r");
	fscanf(in, "%d %d %d", &N, &M, &C);
	int t[N];
	for(int i = 0; i < N; i++) {
		fscanf(in, "%d", &t[i]);
	}
	fclose(in);

	std::sort(t, t+N);

	//I have no idea how to optimize the amount of cows per bus
	int max = 0;
	int index = C-1 < N ? C-1 : N-1;
	while(true) {
		int time = t[index] - t[index-(C-1)];
		max = max > time ? max : time;
		
		if(index == N-1) {
			break;
		}

		index += C;
		index = index < N ? index : N-1;
	}

	FILE * out = fopen("convention.out", "w");
	fprintf(out, "%d\n", max);
	fclose(out);

	return 0;
}
