// INCLUDE HEADER FILES NEEDED BY YOUR PROGRAM
// SOME LIBRARY FUNCTIONALITY MAY BE RESTRICTED
// DEFINE ANY FUNCTION NEEDED
// FUNCTION SIGNATURE BEGINS, THIS FUNCTION IS REQUIRED

#include<iostream>
#include <vector>
using namespace std;
vector<int> maxRestTime(int numCities, int numRoads, int** travelTime,
	int numDeliveries, int** timeLimit)
{
	vector<vector<pair<int, int>>> buffer(numCities + 1);

	for (int i = 0; i < numRoads; i++){
		// buffer[travelTime[i][0]][travelTime[i][1]]=travelTime[i][2];
		// buffer[travelTime[i][1]][travelTime[i][0]]=travelTime[i][2];
		buffer[travelTime[i][0]].push_back(make_pair(travelTime[i][1], travelTime[i][2]));
		buffer[travelTime[i][1]].push_back(make_pair(travelTime[i][0], travelTime[i][2]));
	}
	vector<vector<int>> mindist(numCities + 1, vector<int>(numCities + 1, 100000000));
	vector<bool> visted(numCities + 1, false);
	int cnt = 0;
	int cur = 1;
	mindist[1][1] = 0;
	while (cnt < numCities){
		visted[cur] = true; ++cnt;
		
		for (int i = 0; i<buffer[cur].size(); ++i){
			int x = buffer[cur][i].first;
			int d = buffer[cur][i].second;
			if (visted[x])
				continue;
			if (mindist[1][x]>mindist[1][cur] + d){
				mindist[1][x] = mindist[1][cur] + d;
			}

		}

		int m = 100000000;
		int minp;
		for (int i = 0; i < numCities; i++){
			if (m > mindist[1][i] && !visted[i]){
				m = mindist[1][i];
				minp = i;
			}
		}
		cur = minp;

	}
	vector<int>result(numDeliveries);
	for (int i = 0; i < numDeliveries; i++){
		if (timeLimit[i][1] >= mindist[1][timeLimit[i][0]] * 2)
			result[i] = timeLimit[i][1] - mindist[1][timeLimit[i][0]] * 2;
		else
			result[i] = 0;
	}

	return result;



}
