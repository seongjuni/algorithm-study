# 상어 초등학교에는 교실이 하나 있고, 교실은 N×N 크기의 격자로 나타낼 수 있다. 
# 학교에 다니는 학생의 수는 N2명이다. 오늘은 모든 학생의 자리를 정하는 날이다. 
# 학생은 1번부터 N2번까지 번호가 매겨져 있고, (r, c)는 r행 c열을 의미한다. 교실의 가장 왼쪽 윗 칸은 (1, 1)이고, 가장 오른쪽 아랫 칸은 (N, N)이다.

# 선생님은 학생의 순서를 정했고, 각 학생이 좋아하는 학생 4명도 모두 조사했다. 이제 다음과 같은 규칙을 이용해 정해진 순서대로 학생의 자리를 정하려고 한다. 한 칸에는 학생 한 명의 자리만 있을 수 있고, |r1 - r2| + |c1 - c2| = 1을 만족하는 두 칸이 (r1, c1)과 (r2, c2)를 인접하다고 한다.

# 비어있는 칸 중에서 좋아하는 학생이 인접한 칸에 가장 많은 칸으로 자리를 정한다.
# 1을 만족하는 칸이 여러 개이면, 인접한 칸 중에서 비어있는 칸이 가장 많은 칸으로 자리를 정한다.
# 2를 만족하는 칸도 여러 개인 경우에는 행의 번호가 가장 작은 칸으로, 그러한 칸도 여러 개이면 열의 번호가 가장 작은 칸으로 자리를 정한다.
# 예를 들어, N = 3이고, 학생 N2명의 순서와 각 학생이 좋아하는 학생이 다음과 같은 경우를 생각해보자.

# 3
# 4 2 5 1 7
# 3 1 9 4 5
# 9 8 1 2 3
# 8 1 9 3 4
# 7 2 3 4 8
# 1 9 2 5 7
# 6 5 2 3 4
# 5 1 9 2 8
# 2 9 3 1 4

# 54

# 3
# 4 2 5 1 7
# 2 1 9 4 5
# 5 8 1 4 3
# 1 2 9 3 4
# 7 2 3 4 8
# 9 8 4 5 7
# 6 5 2 3 4
# 8 4 9 2 1
# 3 9 2 1 4

# 1053

# 0: 0 1: 1 2: 10 3: 100 4: 1000
score = [0, 1, 10, 100, 1000]

dr = [-1, 1, 0, 0]
dc = [0, 0, -1, 1]

n = int(input())

room = [[0]*n for _ in range(n)]
stud = []
like = [[] for _ in range(n*n + 1)]

for _ in range(n*n):
    num = list(map(int, input().split()))
    stud.append(num[0])
    like[num[0]] = num[1:]

for s in stud:
    candidates = []

    for r in range(n):
        for c in range(n):
            if room[r][c] != 0:
                continue

        like_cnt = 0
        empty_cnt = 0

        for k in range(4):
            nr = r + dr[k]
            nc = c + dc[k]

            if 0 <= nr < n and 0 <= nc < n:
                    if room[nr][nc] == 0:
                        empty_cnt += 1
                    elif room[nr][nc] in like[s]:
                        like_cnt += 1

        candidates.append((-like_cnt, -empty_cnt, r, c))

    candidates.sort()
    _, _, best_r, best_c = candidates[0]
    room[best_r][best_c] = s

res = 0

for r in range(n):
    for c in range(n):
        s = room[r][c]
        cnt = 0

        for k in range(4):
            nr = r + dr[k]
            nc = c + dc[k]

            if 0 <= nr < n and 0 <= nc < n:
                if room[nr][nc] in like[s]:
                    cnt += 1

        res += score[cnt]

print(res)