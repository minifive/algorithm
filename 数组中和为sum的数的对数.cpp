#include<iostream>
using namespace std;
int myfind(int *A, int left, int right, int sum){
	int count = 0;
	if (left >=right)
		return count;
	int mid = (left + right) / 2;
	int lcount = myfind(A, left, mid, sum);
	int rcount = myfind(A, mid + 1, right, sum);
	for (int i = left; i < mid; i++){
		if (A[i] > sum)
			continue;
		for (int j = mid; j < right; j++){
			if (A[i] + A[j] == sum)
				count++;
		}
	}
	return lcount + rcount + count;
}
//int main(){
//	int n; int sum;
//	cin >> n; cin >> sum;
//	int *A = new int[n];
//	for (int i = 0; i < n; i++){
//		cin >> A[i];
//	}
//	int result = myfind(A, 0, n, sum);
//	cout << result;
//
//}