// <그림 1>과 같이 정사각형 모양의 지도가 있다. 1은 집이 있는 곳을, 0은 집이 없는 곳을 나타낸다. 철수는 이 지도를 가지고 연결된 집의 모임인 단지를 정의하고, 단지에 번호를 붙이려 한다. 여기서 연결되었다는 것은 어떤 집이 좌우, 혹은 아래위로 다른 집이 있는 경우를 말한다. 대각선상에 집이 있는 경우는 연결된 것이 아니다. <그림 2>는 <그림 1>을 단지별로 번호를 붙인 것이다. 지도를 입력하여 단지수를 출력하고, 각 단지에 속하는 집의 수를 오름차순으로 정렬하여 출력하는 프로그램을 작성하시오.



// 입력
// 첫 번째 줄에는 지도의 크기 N(정사각형이므로 가로와 세로의 크기는 같으며 5≤N≤25)이 입력되고, 그 다음 N줄에는 각각 N개의 자료(0혹은 1)가 입력된다.

// 출력
// 첫 번째 줄에는 총 단지수를 출력하시오. 그리고 각 단지내 집의 수를 오름차순으로 정렬하여 한 줄에 하나씩 출력하시오.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int w[4] = {-1, 0, 1, 0};
int h[4] = {0, 1, 0, -1};

int dan[25][25];
bool visited[25][25] = {false};
int dan_count[25*25] = {0};
int dan_num = 0;

void dfs(int x, int y){
    visited[x][y] = true;
    dan_count[dan_num]++;
    
    for(int i=0; i<4; i++){
        int nx = x + w[i];
        int ny = y + h[i];
        if(nx>=0 && nx<N && ny>=0 && ny<N){
            if(dan[nx][ny] == 1 && !visited[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    cin >> N;
    string q;
    for(int i=0; i<N; i++){
        cin >> q;
        for(int j=0; j<q.length(); j++){
            dan[i][j] = q[j] - '0';
        }
    }
    
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(dan[i][j] == 1 && !visited[i][j]){
                dfs(i, j);
                dan_num++;
            }
        }
    }
    
    sort(dan_count, dan_count + dan_num);
    
    cout << dan_num<< endl;
    for(int i=0; i< dan_num; i++){
        cout << dan_count[i] << endl;
    }
    
    
    return 0;
}