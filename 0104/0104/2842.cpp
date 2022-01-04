#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define MAXN 51
#define INF 1000000000

char MapInfo[MAXN][MAXN];
int MapH[MAXN][MAXN];
int Data[MAXN*MAXN];
bool Visit[MAXN][MAXN];
int N;
int StartC, StartR;//��ü��(�����)
int HouseCnt;//������

int dc[8] = { 0,0,-1,1,-1,-1,1,1 };
int dr[8] = { -1,1,0,0,-1,1,1,-1 };

void dfs(int r, int c, int& minV, int& maxV, int& visitHcnt)
{
	//�� �ٱ��̰ų� �湮�Ͽ��ų� �������� �ƴϸ�,
	if (r<0 || r >= N || c<0 || c >= N ||
		Visit[r][c] || MapH[r][c]<minV || MapH[r][c]>maxV) return;

	//�湮 flag ����
	Visit[r][c] = true;
	//���̸�...
	if (MapInfo[r][c] == 'K') visitHcnt++;

	for (int i = 0; i<8; i++)
	{
		int nR = r + dr[i];
		int nC = c + dc[i];
		dfs(nR, nC, minV, maxV, visitHcnt);
	}

	return;
}

bool canGo(int minV, int maxV)
{
	//visit �ʱ�ȭ
	memset(Visit, 0, sizeof(Visit));

	int visitHcnt = 0;

	dfs(StartR, StartC, minV, maxV, visitHcnt);
	//�湮�� ���� ������ ��ü ���� ������ �����ϸ�
	if (visitHcnt == HouseCnt) return true;
	else return false;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			scanf(" %c", &MapInfo[i][j]);
			if (MapInfo[i][j] == 'P')
			{
				StartR = i;
				StartC = j;
			}
			else if (MapInfo[i][j] == 'K')
			{
				HouseCnt++;
			}
		}
	}

	int cnt = 0, ans = INF, uniqueCnt = 1, maxH = 0, minH = INF, maxHIdx, minHIdx;

	for (int i = 0; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{
			scanf("%d", &MapH[i][j]);
			Data[cnt++] = MapH[i][j];

			if (MapInfo[i][j] == 'P' || MapInfo[i][j] == 'K')
			{
				maxH = max(maxH, MapH[i][j]);
				minH = min(minH, MapH[i][j]);
			}
		}
	}

	sort(Data, Data + cnt);
	for (int i = 1; i<cnt; i++)
	{
		//sort�� �����͸� unique�ϰ� �����.
		if (Data[i] != Data[i - 1]) Data[uniqueCnt++] = Data[i];
	}

	for (int i = 0; i<uniqueCnt; i++)
	{
		if (Data[i] == maxH) maxHIdx = i;
		if (Data[i] == minH) minHIdx = i;
	}

	//��������
	int minIdx = 0, maxIdx = maxHIdx;//maxIdx ��ü��/�� �ִ���� Idx���� �۾��� �� ����.
	while (maxIdx<uniqueCnt)
	{
		while (minIdx <= minHIdx)
		{
			if (!canGo(Data[minIdx], Data[maxIdx])) break;
			ans = min(ans, Data[maxIdx] - Data[minIdx]);
			//�����ϸ� minIdx�� ���� ������ ������.
			minIdx++;
		}
		//������ �� ������ maxIdx�� ���� ������ �ø���.
		maxIdx++;
	}

	printf("%d", ans);

	return 0;
}