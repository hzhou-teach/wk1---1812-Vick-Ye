#include<cstdio>
#include<algorithm>
// Vick Ye
// incomplete
// 1:23:47
struct cowTime {
	int a;
	int t;
	int priority;
};



int main() {
	int N;
	FILE * in = fopen("convention2.in", "r");
	fscanf(in, "%d", &N);

	cowTime seniority[N];
	for(int i = 0; i < N; i++) {
		fscanf(in, "%d %d", &seniority[i].a, &seniority[i].t);
		seniority[i].priority = i;
	}

	fclose(in);

	cowTime cows[N];
	for(int i = 0; i < N; i++) {
		cows[i].a = seniority[i].a;
		cows[i].t = seniority[i].t;
		cows[i].priority = seniority[i].priority;
	}

	std::sort(cows, cows+N, [](cowTime a, cowTime b) {
		if(a.a == b.a) {
			return a.priority < b.priority;
		}
		return a.a < b.a;
	});
	
	int max = 0;
	int finish[N];
	for(int i = 0; i < N; i++) {
		finish[i] = 0;
	}

	int time = cows[0].a+cows[0].t;
	finish[0] = 1;

	//incomplete
	int index = 1;
	while(true) {
		cowTime prior;
		for(int i = 0; i < N; i++) {
			if(seniority[i].a <= time && finish[seniority[i].priority] != 1) {
				prior.a = seniority[i].a;
				prior.t = seniority[i].b;
				prior.priority = seniority[i].priority;
				index = i;
				break;
			}
		}
		max = max > time-prior.a ? max : time-prior.a;
		time += prior.t;
		finish[prior.priority] = 1;
	}


	FILE * out = fopen("convention2.out", "w");
	fprintf(out, "%d\n", max);
	fclose(out);
	
	return 0;	
}
