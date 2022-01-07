#include <iostream>
#include <algorithm>
using namespace std;

//������ ���� �˻�
//+�ణ�� ���� �ɷ�
//����, ���� ������ �� �˰�, �� ������ �ؾ� ��
#define MAXN 50
#define MAXM 13
#define INF 987654321

struct stPos
{
	int r, c;
};

int N, M, Ans;
int Top, HouseCnt, ChickenCnt;
stPos House[2 * MAXN + 1];//���� ������ 2N
stPos Chicken[MAXM + 1];//ġŲ��
int Selected[MAXM + 1];//���õ� ġŲ���� index

void calcData()
{
	int sum = 0;
	for (int i = 0; i<HouseCnt; i++)
	{
		int minDist = INF, dist;
		//i��° ������ ���õ� ġŲ���� ������ �Ÿ� �� �ּ� ġŲ�Ÿ� ���
		for (int j = 0; j<Top; j++)
		{
			dist = abs(House[i].r - Chicken[Selected[j]].r)
				+ abs(House[i].c - Chicken[Selected[j]].c);
			minDist = min(minDist, dist);
		}
		sum += minDist;//i��° ���� �ּ� ġŲ�Ÿ�
	}

	Ans = min(Ans, sum);
}

//���õ� ġŲ���� �ε����� selected �迭�� �ִ´�.
void backtracking(int start)
{
	if (Top == M)//��� �����ߴٸ�
	{
		calcData();
		return;
	}

	for (int i = start; i<ChickenCnt; i++)
	{
		if (ChickenCnt - i < M - Top) break;//����ġ��
		Selected[Top++] = i;//���õ� ġŲ��
		backtracking(i + 1);
		Top--;
	}
}

int main()
{
	scanf("%d %d", &N, &M);

	Ans = INF;

	for (int i = 0, data; i<N; i++)
	{
		for (int j = 0; j<N; j++)
		{

			//������ ġŲ�������� �޾Ƽ� ���� ����
			scanf("%d", &data);
			if (data == 1)
			{
				House[HouseCnt].r = i;
				House[HouseCnt++].c = j;
			}
			else if (data == 2)
			{
				Chicken[ChickenCnt].r = i;
				Chicken[ChickenCnt++].c = j;
			}
		}
	}

	backtracking(0);

	printf("%d", Ans);

	return 0;
}