//头条笔试，输入一个数组表示跳板的高度。每次可从当前位置跳到跳板的镜像位置，
//选取的跳板与当前位置绝对值不超过h。求经过k次跳之后最高高度。
//思路：动态规划
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
//头条笔试，对于字符串s,m有两种改变它们的方案，方案1：m=s;s=s+s;方案2:s=s+m
//初始化s='a',m=s; 求最少经过多少次变换能使s的疮毒等于n
//思路广度优先搜索，过80%
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

		//方案1
		int m1 = stemp;//m=s
		int s1 = stemp + stemp;//s=s+s
		if (s1 == n){
			cout << h + 1;
			return 0;
		}
		buffer.push(s1);
		buffer.push(m1);
		buffer.push(h + 1);//深度+1
		//方案2
		int s2 = stemp + mtemp;
		int m2 = mtemp;//隐含条件，m保持不变 m(n)=m(n-1)
		if (s2 == n){
			cout << h + 1;
			return 0;
		}
		buffer.push(s2);
		buffer.push(m2);
		buffer.push(h + 1);
	}

}

//头条笔试
//输入一个长度为n的数组，判断其中和为k的数的对数。
//思路，输入的数组构建map，然后逐个a[i]，看k-a[i]是否在map里面
//时间复杂度nlogn,过70%
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