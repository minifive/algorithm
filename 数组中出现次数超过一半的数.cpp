#include<iostream>
#include<vector>
using namespace std;
//��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ�������֡���������һ������Ϊ9������{1,2,3,2,2,2,5,4,2}����������2�������г�����5�Σ��������鳤�ȵ�һ�룬������2����������������0
//˼·һ������ȡ�м���� O(nlgn)
//˼·2����������ʱ��������ֵ��һ��������һ�����֣�һ�Ǵ�����������һ������ʱ��������֮ǰ�����������ͬ���������1�����������1��������Ϊ0���򱣴���һ�����֣�����������Ϊ1����������������������ּ�Ϊ����Ȼ�����ж����Ƿ�����������ɡ�
int MoreThanHalfNum_Solution(vector<int> numbers) {
	if (numbers.size()==0)
	{
		return 0;
	}

	int result = numbers[0];
	int times = 0;

	for (int i = 0; i < numbers.size(); i++)//˼·Ϊ��Ŀ�����滻����������
	{
		if (times == 0)//timesΪ0ʱ����ǰԪ�����ó�result�����¼���
		{
			result = numbers[i];
			times = 1;
		}
		else if (numbers[i] == result)//��ͬ�������1
		{
			times++;
		}
		else{//��ͬ�������һ
			times--;
		}
	}
	//��ʱresult��ŵļ�ΪĿ����
	times = 0;
	for (int i = 0; i < numbers.size(); i++)
	{
		if (numbers[i] == result)
			times++;
	}
	return times > numbers.size() / 2 ? result : 0;

}