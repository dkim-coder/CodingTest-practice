#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <utility>  // pair
#include <tuple>
#include <stack>
#include <map>
#include <unordered_map>
#define ll long long
#define INF 1e9
using namespace std;

int ans;
int A[101][101];
int r,c,k;
int R=3, C=3;
bool found = false;

bool compare(pair<int, int>a, pair<int, int>b) {
	if(a.second == b.second) {
		return a.first < b.first;
	} else {
		return a.second < b.second;
	}
}

void sol() {

	int B[101][101];
	memset(B, 0, sizeof(B));

	if(R >= C) {
		int maxCol = 0;
		for(int i=1;i<=R;++i) {
			unordered_map<int,int> m;
			for(int j=1;j<=C;++j) {
				if(A[i][j]) {
					int key = A[i][j];
					auto search = m.find(key);
					if(search != m.end()) {  // found
						int count = search->second;
						m.erase(key);
						m.insert(make_pair(key,count+1));
					} else {  // not found
						m.insert(make_pair(key,1));
					}
				}
			}

			vector<pair<int,int> > vec(m.begin(), m.end());
			sort(vec.begin(), vec.end(), compare);
			for(int j=0;j<vec.size();++j) {
				auto p = vec[j];
				if(2*(j+1)-1 <= 100) {
					B[i][2*(j+1)-1] = p.first;
				}
				if(2*(j+1) <= 100) {
					B[i][2*(j+1)] = p.second;
				}
			}
			
			int col = m.size() * 2;
			maxCol = max(min(col,100), maxCol);
		}

		C = maxCol;
	} else {

		int maxRow = 0;
		for(int j=1;j<=C;++j) {
			unordered_map<int,int> m;
			for(int i=1;i<=R;++i) {
				if(A[i][j]) {
					int key = A[i][j];
					auto search = m.find(key);
					if(search != m.end()) {
						int count = search->second;
						m.erase(key);
						m.insert(make_pair(key,count+1));
					} else {
						m.insert(make_pair(key,1));
					}
				}
			}

			vector<pair<int,int> > vec(m.begin(), m.end());
			sort(vec.begin(), vec.end(), compare);
			for(int i=0;i<vec.size();++i) {
				auto p = vec[i];
				if(2*(i+1)-1 <= 100) {
					B[2*(i+1)-1][j] = p.first;
				}
				if(2*(i+1) <= 100) {
					B[2*(i+1)][j] = p.second;
				}
			}

			int row = m.size() * 2;
			maxRow = max(min(row,100), maxRow);
		}

		R = maxRow;
	}

	copy(&B[0][0], &B[0][0]+10201, &A[0][0]);

	return;
}

int main(void) {
	// ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	scanf("%d%d%d", &r,&c,&k);
	for(int i=1;i<=3;++i) {
		scanf("%d%d%d", &A[i][1], &A[i][2], &A[i][3]);
	}

	for(int i=0;i<=100;++i) {
		if(A[r][c] == k) {
			found = true;
			break;
		}
		sol();
		ans++;
	}

	if(found) {
		printf("%d\n", ans);
	} else {
		ans = -1;
		printf("%d\n", ans);
	}
	
	return 0;
}