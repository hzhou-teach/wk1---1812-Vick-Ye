#include<cstdio>
// Vick Ye
// 10/10
// 1:15:20

int buckets1[10];
int buckets2[10];

//highest possible tank = 1000-1+100-1+100 = 1198
int milk[1200];

void weekdays(int milkCount, int dayCount, int B1[10], int B2[11]) {
	if(dayCount == 4) {
		milk[milkCount] = 1;
	} else if(dayCount % 2 == 0) {
		for(int bucketInd = 0; bucketInd < 10; bucketInd++) {
			int newB1[10];
			int newB2[11];
			
			bool removed = false;
			for(int i = 0; i < 10; i++) {
				if(removed) {
					//shift down to fill erased
					newB1[i-1] = B1[i];
				} else if(bucketInd == i) {
					removed = true;
				} else {
					newB1[i] = B1[i];
				}
			}

			for(int i = 0; i < 10; i++) {
				newB2[i] = B2[i];
			}
			newB2[10] = B1[bucketInd];

			weekdays(milkCount-B1[bucketInd], dayCount+1, newB1, newB2);
		}
	} else if(dayCount % 2 == 1) {
		for(int bucketInd = 0; bucketInd < 11; bucketInd++) {
			int newB1[10];
			int newB2[11];

			bool removed = false;
			for(int i = 0; i < 11; i++) {
				if(removed) {
					newB2[i-1] = B2[i];
				} else if(bucketInd == i) {
					removed = true;
				} else {
					newB2[i] = B2[i];
				}
			}

			for(int i = 0; i < 9; i++) {
				newB1[i] = B1[i];
			}
			newB1[9] = B2[bucketInd];

			weekdays(milkCount+B2[bucketInd], dayCount+1, newB1, newB2);
		}
	}
}

int main() {
	for(int i = 0; i < 1200; i++) {
		milk[i] = 0;
	}
	FILE * in = fopen("backforth.in", "r");
	for(int i = 0; i < 10; i++) {
		fscanf(in, "%d", &buckets1[i]);
	}
	for(int i = 0; i < 10; i++) {
		fscanf(in, "%d", &buckets2[i]);
	}
	fclose(in);

	int newB2[11];
	for(int i = 0; i < 10; i++) {
		newB2[i] = buckets2[i];
	}
	newB2[10] = 0;
	weekdays(1000, 0, buckets1, newB2);

	int unique = 0;
	for(int i = 0; i < 1200; i++) {
		unique += milk[i];
	}
	printf("%d\n", unique);
	FILE * out = fopen("backforth.out", "w");
	fprintf(out, "%d\n", unique);
	fclose(out);

	return 0;
}
