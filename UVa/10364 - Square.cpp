#include <cstdio>

using namespace std;

int N, combMax;
int stick[21];
int sumLimit, tempSum;
bool ret;

bool solve(int i, int comb, int sum) {
	if (comb == combMax) {
		if (sum)
			return false;
		return true;
	}
	if (i == N)
		return false;
	if (!(comb&(1<<i))) {
		tempSum = sum + stick[i];
		if (tempSum > sumLimit) {
			ret = solve(i+1, comb, sum);
		}
		else if (tempSum < sumLimit) {
			ret = solve(i+1, comb|(1<<i), tempSum);
			if (!ret)
				ret = solve(i+1, comb, sum);
		}
		else if (tempSum == sumLimit) {
			ret = solve(0, comb|(1<<i), 0);
		}
		return ret;
	}
	return solve(i+1, comb, sum);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int T;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		combMax = (1<<N) - 1;
		sumLimit = 0;
		for (int i = 0; i < N; i++) {
			scanf("%d", stick+i);
			sumLimit += *(stick+i);
		}
		if (sumLimit%4) {
			printf("no\n");
			continue;
		}
		sumLimit /= 4;
		if (solve(0, 0, 0))
			printf("yes\n");
		else
			printf("no\n");
	}
	return 0;
}