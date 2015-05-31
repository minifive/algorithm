#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>
using namespace std;
#define  testNUM 10 //Ҫ�����ҳ��
#define  MaxFrame 100 //�������������ΧΪ0-9
struct LRUframe
{
	int ID;
	int count;//���ʹ��ʱ����countԽ���ʾ���ʹ��
	LRUframe()
	{
		ID = -1;
		count = 0;
	}
};
struct ARBframe 
{
	int ID;
	__int8 Regist;//8λ�Ĵ���
	int Reference;//����λ
	ARBframe()//��ʼ��
	{
		ID = -1;
		Regist = 0;
		Reference = 0;
	}
};
int counterLRU(int MaxmemoryFrame, int Testnum,int Rand);
int stackLRU(int MaxmemoryFrame, int Testnum, int Rand);
int additionalBit(int MaxmemoryFrane, int Testnum, int Rand);
int SecondChance(int MaxmemoryFrane, int Testnum, int Rand);
int main(){
	float *Error =new float[4];
	int Rand = time(0);
	int maxmemoryframe = 2;
	int testnum = 10;
	Error[0] = counterLRU(maxmemoryframe, testnum, Rand);
	Error[1] = stackLRU(maxmemoryframe, testnum, Rand);
	Error[2] = additionalBit(maxmemoryframe, testnum, Rand);
	Error[3] = SecondChance(maxmemoryframe, testnum, Rand);
	cout << "Error rate num for countLRU:" << Error[0] / testnum << endl;
	cout << "Error rate num for stackLRU:" << Error[1] / testnum << endl;
	cout << "Error rate num for additionalBit;" << Error[2] / testnum << endl;
	cout << "Error rate num for SecondChance:" << Error[3] / testnum << endl;
	return 0;
}



int counterLRU(int MaxmemoryFrame, int Testnum,int Rand){
	int CPUtime = 0;//cpuʱ�Ӽ�������
	int lastuse = 0;
	int Errornum = 0;
	srand(Rand);
	LRUframe*frames = new LRUframe[MaxmemoryFrame];
	while (Testnum--)
	{
		CPUtime++;
		LRUframe newf;
		newf.ID =rand() % MaxFrame;
		int i = 0;
		for (; i < MaxmemoryFrame; i++)
		{
			if (frames[i].ID == newf.ID)//���ڴ�֡���ҵ�
				break;
			if (frames[i].count < frames[lastuse].count)
				lastuse = i;
		}
		if (i < MaxmemoryFrame)//����֡���ڴ����ҵ�
			frames[i].count = CPUtime;//������ʹ��ʱ����Ϊ����
		else
		{
			Errornum=Errornum+1;
			frames[lastuse].ID = newf.ID;//��lastuse�滻��
			frames[lastuse].count = CPUtime;
		}
	}
	delete[]frames;
	return Errornum;
}


int stackLRU(int MaxmemoryFrame, int Testnum, int Rand){
	vector<int>buffer;
	vector<int>::iterator itr = buffer.begin();
	int Errornum = 0;
	srand(Rand);
	while (Testnum--)
	{
		int newf = rand() % MaxFrame;
		int i = 0;
		for (; i < buffer.size(); i++)
		{
			if (buffer[i] == newf)
			{
				itr = buffer.begin();
				buffer.erase(itr+i);//����ԭ�м�¼������push��ͷ��
				buffer.push_back(newf);
				if (buffer.size() > MaxmemoryFrame)//ÿ��push�µ������ж�ջ��С�Ƿ񳬳���Χ
				{
					itr = buffer.begin();
					buffer.erase(itr);//��������ɾ��ջ��Ԫ�أ�
				}
				break;
			}
		}
		if (i==buffer.size())//û�ҵ�
		{
			Errornum++;
			buffer.push_back(newf);
			if (buffer.size() > MaxmemoryFrame)//ÿ��push�µ������ж�ջ��С�Ƿ񳬳���Χ
			{
				itr = buffer.begin();
				buffer.erase(itr);//��������ɾ��ջ��Ԫ�أ�
			}
		}
	}//end while;
	return Errornum;
}


int additionalBit(int MaxmemoryFrane, int Testnum, int Rand){
	srand(Rand);
	int Errornum = 0;
	ARBframe *frames = new ARBframe[MaxmemoryFrane];
	int lastused = 0;
	int count = 0;
	while (Testnum--)
	{
		int newf = rand() % MaxFrame;
		int i = 0;
		for (; i < MaxmemoryFrane;i++)
		{
			if (frames[i].ID == newf)
				break;
			if (frames[i].Regist < frames[lastused].Regist)//8λ�Ĵ�����ֵС��ΪLRU
				lastused = i;
		}
		if (i<MaxmemoryFrane)//find
		{
			frames[i].Reference = 1;//����������λΪ1
		}
		else{
			Errornum++;
			frames[lastused].ID = newf;//�滻�����δʹ�õ�ֵ
			frames[lastused].Reference = 1;
		}
		if (count==5)//ÿ5�θ���һ��8λ�Ĵ���
		{
			count = 0;
			for (int i = 0; i < MaxmemoryFrane;i++)
			{
				frames[i].Regist = (frames[i].Regist >> 1)+ (frames[i].Reference << 7); //�Ĵ���ֵ����һλ��������λ����7λ
			}
		}
	}//end of while
	return Errornum;
}


int SecondChance(int MaxmemoryFrane, int Testnum, int Rand){
	srand(Rand);
	ARBframe *frames = new ARBframe[MaxmemoryFrane];
	int Errornum = 0;
	int lastused = 0;
	while (Testnum--)
	{
		int newf = rand() % MaxFrame;
		int i = 0;
		for (; i < MaxmemoryFrane; i++)
		{
			if (frames[i].ID == newf)
				break;
		}
		if (i < MaxmemoryFrane){
			frames[i].Reference = 1;
		}
		else{
			Errornum++;
			while (frames[lastused].Reference!=0)//�ҵ���һ������ΪΪ0ʱ����
			{
				frames[lastused].Reference = 0;//������λΪ1ʱ ���ڶ��λ���
				lastused = (lastused++) % MaxmemoryFrane;//���β���
			}
			frames[lastused].ID = newf;//�滻
		}
	}
	return Errornum;
}