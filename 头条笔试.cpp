//ͷ�����ԣ�����һ�������ʾ����ĸ߶ȡ�ÿ�οɴӵ�ǰλ����������ľ���λ�ã�
//ѡȡ�������뵱ǰλ�þ���ֵ������h���󾭹�k����֮����߸߶ȡ�
//˼·����̬�滮
int main(){
	int n, k, h;
	cin >> n >> k >> h;
	int *a = new int[n];
	int dp[1000] = { 0 };
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 1; i <= k; i++){
		int maxtemp = 0;
		for (int j = 0; j < n; j++){
			if (abs(dp[i - 1] - a[j]) <= h){
				if ((2 * (a[j] - dp[i - 1]) + dp[i - 1]) > maxtemp)
					maxtemp = 2 * (a[j] - dp[i - 1]) + dp[i - 1];
			}
		}

		dp[i] = max(maxtemp, dp[i]);
	}
	cout << dp[k];
	return 0;
}
//ͷ�����ԣ������ַ���s,m�����ָı����ǵķ���������1��m=s;s=s+s;����2:s=s+m
//��ʼ��s='a',m=s; �����پ������ٴα任��ʹs�Ĵ�������n
//˼·���������������80%
int test1main(){
	int n;
	cin >> n;
	int s = 1;
	int m = 1;
	queue<int>buffer;
	buffer.push(s);
	buffer.push(m);
	int count = 0;
	buffer.push(count);
	while (!buffer.empty())
	{
		int stemp = buffer.front();
		buffer.pop();
		int mtemp = buffer.front();
		buffer.pop();
		int h = buffer.front();
		buffer.pop();

		//����1
		int m1 = stemp;//m=s
		int s1 = stemp + stemp;//s=s+s
		if (s1 == n){
			cout << h + 1;
			return 0;
		}
		buffer.push(s1);
		buffer.push(m1);
		buffer.push(h + 1);//���+1
		//����2
		int s2 = stemp + mtemp;
		int m2 = mtemp;//����������m���ֲ��� m(n)=m(n-1)
		if (s2 == n){
			cout << h + 1;
			return 0;
		}
		buffer.push(s2);
		buffer.push(m2);
		buffer.push(h + 1);
	}

}

//ͷ������
//����һ������Ϊn�����飬�ж����к�Ϊk�����Ķ�����
//˼·����������鹹��map��Ȼ�����a[i]����k-a[i]�Ƿ���map����
//ʱ�临�Ӷ�nlogn,��70%
int testmain(){
	map<int, int>buffer;
	set<int>result;
	int n, k;
	cin >> n >> k;
	int *a = new int[n];
	for (int i = 0; i < n; i++){
		cin >> a[i];
		buffer.insert(pair<int, int>(a[i], 1));
	}
	for (int i = 0; i < n; i++)
	{
		if (buffer.find(a[i] + k) != buffer.end())
			result.insert(a[i]);
	}
	cout << result.size();
	return 0;
}


/*


sort(a,a+n);
int left = 0;
int right = n - 1;
while (left<=right&&right<n)
{
if (a[right] - a[left] ==k){
buffer.insert(a[left]);
left++;
right++;
}
if (a[right] - a[left] < k){
left++;
right = n - 1;
}
if (a[right] - a[left] > k){
right--;
}

}*/