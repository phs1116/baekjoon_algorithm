#include <cstdio>
#include <algorithm>
char ch[16], pa[16];
int L, C;
void pass(int start, int len) {
	if (len == L) {
		int j = 0, m = 0;
		for (int i = 0; i < L; ++i) {
			if (pa[i] == 'a' || pa[i] == 'e' || pa[i] == 'i' || pa[i] == 'o' || pa[i] == 'u')	m += 1;
			else j += 1;
		}
		if (m >= 1 && j >= 2)
			puts(pa);
		return;
	}
	for (int i = start; i < C; ++i) {
		pa[len] = ch[i];
		pass(i + 1, len + 1);
	}
}
int main() {
	scanf("%d %d", &L, &C);
	for (int i = 0; i < C; ++i)
		scanf("%s",&ch[i]);
	std::sort(ch, ch + C);
	pass(0, 0);
}

