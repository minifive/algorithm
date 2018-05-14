#include<iostream>
using namespace std;

int partition(int a[], int left, int right){
	int temp = a[left];
	while (left<right)
	{
		while (left < right&&a[right] >= temp)right--;
		a[left] = a[right];
		while (left<right&&a[left]<=temp) left++;
		a[right] = a[left];
	}
	a[left] = temp;
	return left;	
}

void quicksort(int a[],int left,int right){
	if (left >= right)//一定要加递归结束条件
		return;
	int p = partition(a, left, right);
	quicksort(a, left, p - 1);
	quicksort(a, p + 1, right);
}

int main1(){
	int *a = new int[10]{8, 1, 5, 7, 6, 4, 3, 2, 0, 9};
	quicksort(a, 0, 9);

	for (int i = 0; i < 10; i++)
		cout << a[i];

	return 0;
}