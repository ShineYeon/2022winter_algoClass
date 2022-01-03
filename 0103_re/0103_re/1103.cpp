/*
BFS�� Ǯ ��� �޸𸮰� ���� ���ɼ��� ����.
*/
#include <iostream>
#include <algorithm>

using namespace std;

#define MAXN 51

int N, M, Ans;
char Data[MAXN][MAXN];//�Է� ������
bool Visit[MAXN][MAXN];//�湮����
int DP[MAXN][MAXN];//�� ������ ���� �� ���� (�� ū���� ������ �������� ������)

				   //4���� ����(����, �Ʒ�, ��, ������)
int dc[] = { -1, 0, 0, 1 };
int dr[] = { 0, -1, 1, 0 };

bool dfs(int r, int c, int cnt)
{
	//���ѹ� ������ �� �ִ� ���
	if (Ans == -1) return true;

	Ans = max(Ans, cnt);

	Visit[r][c] = true;
	//DP���̺� ��� ����� update�Ͽ� �� ���� �Ѱ��� ���� ���̶�� ������� �ʵ��� �Ѵ�.
	DP[r][c] = cnt;

	for (int i = 0; i<4; i++)
	{
		int nr = r + dr[i] * (Data[r][c] - '0');//���ڿ��� �� ���ڿ��� '0' ���ڸ� ���� int�� �ȴ�.(ASCII�ڵ�)
		int nc = c + dc[i] * (Data[r][c] - '0');

		//��Ʈ���� ������ ����ų� �����ΰ��� ������ ����ǹǷ� Ž���� �������� �ʴ´�.
		if (nr<0 || nr >= N || nc<0 || nc >= M || Data[nr][nc] == 'H') continue;

		//�湮�� ���� �� �湮�Ϸ� �Ѵٸ� ���ѹ� ������ �� �ִٴ� �ǹ�
		if (Visit[nr][nc])
		{
			Ans = -1;
			return true;
		}

		//�̹� ���� ���� DP���̺� ��ϵǸ� DP�� ���� cnt���� ũ�ٸ� 
		//�̹� �� ��� �����̴� ���� ���Ǿ� �ִ�.
		if (DP[nr][nc]>0 && cnt<DP[nr][nc]) continue;

		//���ѹ� ������ �� �ִٸ� dfs���� true�� return�ȴ�
		if (dfs(nr, nc, cnt + 1)) return true;
	}

	//���ƿͼ��� Visit Flag�� false�� ����
	Visit[r][c] = false;
	return false;
}

int main()
{
	scanf("%d %d", &N, &M);

	for (int i = 0; i<N; i++) scanf("%s", Data[i]);//���ڿ��� �Է��� �޴´�.

	dfs(0, 0, 1);//0,0 ��ǥ���� ���
	printf("%d", Ans);
}