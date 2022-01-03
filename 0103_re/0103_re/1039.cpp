#include <iostream>
#include <string>
#include <queue>
#include <set>
using namespace std;

#define MAXN 10

int main()
{
	char S[MAXN], t;
	int K;
	string str, ans = "0";
	queue<string> q;

	scanf(" %s %d", S, &K);//char array�� �Է¹޴´�.
	str = S;//string���� ��ȯ

	q.push(str);

	for (int i = 0; i<K; i++)//layer�� �÷����鼭 K������ ����
	{
		//�� layer���� ���ڰ� �ߺ��Ȱ� ������ �ʿ䰡 ����.
		//�ߺ� ����� ���� ���� set Ȱ��
		set<string> s;
		int qSize = q.size();

		//�ϳ��� layer�� ó��
		for (int j = 0; j<qSize; j++)
		{
			str = q.front();
			q.pop();

			if (s.count(str) == 1) continue;//�̹� ó���� ���̸� ������ �ʿ����
			s.insert(str);

			for (int k = 0; k<str.size() - 1; k++)
			{
				for (int l = k + 1; l<str.size(); l++)
				{
					//ù��° ���ڿ� ��ȯ�� ��, ù��° ���ڷ� �� ���ڰ� '0'�̸� �����ϸ� �ȵ�
					if (k == 0 && str[l] == '0') continue;

					//k, l ���ڸ� ��ȯ
					t = str[k];
					str[k] = str[l];
					str[l] = t;

					q.push(str);

					//�ٽ� ����
					t = str[k];
					str[k] = str[l];
					str[l] = t;
				}
			}
		}
	}

	//queue�� ���� �ִ� ���� ���� ū���� ans�� ��´�.
	while (!q.empty())
	{
		ans = max(ans, q.front());
		q.pop();
	}

	if (ans[0] == '0') printf("-1");//������ K�� �� �� ������ -1�� ����Ѵ�
	else printf("%s", ans.c_str());

	return 0;
}