#include<cstdio>
// Vick Ye
// 10/10
// 14:15

int milk[3];
int capacity[3];

void pour(int a, int b) {
	int pourAmt = milk[a] < capacity[b]-milk[b] ? milk[a] : capacity[b]-milk[b];
	milk[a] -= pourAmt;
	milk[b] += pourAmt;
}

int main() {
	FILE * in = fopen("mixmilk.in", "r");
	for(int i = 0; i < 3; i++) {
		fscanf(in, "%d %d", &capacity[i], &milk[i]);
	}
	fclose(in);

	for(int i = 0; i < 100; i++) {
		pour(i%3, (i+1)%3);
	}

	FILE * out = fopen("mixmilk.out", "w");
	for(int i = 0; i < 3; i++) {
		fprintf(out, "%d\n", milk[i]);
	}
	fclose(out);

	return 0;
}
