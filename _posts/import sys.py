import sys
from collections import deque

# 학생 수 입력
n = int(sys.stdin.readline().strip())

# 학생 정보를 저장할 딕셔너리
students = {}

# 학생 정보 입력
for _ in range(n):
    line = sys.stdin.readline().strip().split(',')
    name = line[0]
    gender = line[1]
    age = int(line[2])
    friends = line[3:]
    students[name] = friends

# 알림이 발생하는 학생 이름 입력
A_student = sys.stdin.readline().strip()

# BFS를 사용하여 친구와 친구의 친구 찾기
def find_notification_count(students, start):
    visited = set()
    queue = deque([start])
    visited.add(start)
    
    while queue:
        current = queue.popleft()
        for friend in students[current]:
            if friend not in visited:
                visited.add(friend)
                queue.append(friend)
    
    # 시작 학생은 제외하고 반환
    visited.remove(start)
    return len(visited)

# 결과 출력
print(find_notification_count(students, A_student))
