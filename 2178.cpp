#include <cstdio>
#include <queue>
#include <utility>
using namespace std;
char mr[100][100];
int n, m, visit[100][100] = { 0, };
int relPos[4][2] = { { -1,0 },{ 1,0 },{ 0,-1 },{ 0,1 } };
queue<pair<int, int> > q;
int search(int y, int x) {
    q.push(make_pair(y, x));
    while (!q.empty()) {
        x = q.front().second;
        y = q.front().first; q.pop();
        if (y == n - 1 && x == m - 1)
            return visit[y][x] + 1;
        for (int i = 0; i<4; ++i) {
            int nx = x + relPos[i][1], ny = y + relPos[i][0];
            if ((nx<0 || ny<0) || (nx>m - 1 || ny>n - 1))
                continue;
            else if (mr[ny][nx] == '1') {
                q.push(make_pair(ny, nx));
                mr[ny][nx] = '2';
                visit[ny][nx] = visit[y][x] + 1;
            }
        }
    }
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", mr[i]);
    printf("%d", search(0, 0));
}

