#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>
#include <sstream>
using namespace std;

// 학생 정보를 담는 구조체
struct Student {
    string name;
    string gender;
    int age;
    vector<string> friends;
};

// 학생 데이터를 파싱하는 함수
Student parseStudentInfo(const string& info) {
    stringstream ss(info);
    string name, gender, ageStr, friendName;
    getline(ss, name, ',');
    getline(ss, gender, ',');
    getline(ss, ageStr, ',');

    vector<string> friends;
    while (getline(ss, friendName, ',')) {
        friends.push_back(friendName);
    }

    return {name, gender, stoi(ageStr), friends};
}

// BFS를 사용하여 알림을 받을 학생 수를 계산하는 함수
int calculateNotificationCount(const unordered_map<string, Student>& students, const string& aStudent) {
    unordered_set<string> notified; // 알림 받은 학생들을 저장
    queue<string> q;
    
    // 초기 친구들을 큐에 넣고, 알림 받은 학생 목록에 추가
    for (const string& friendName : students.at(aStudent).friends) {
        if (notified.find(friendName) == notified.end()) {
            q.push(friendName);
            notified.insert(friendName);
        }
    }

    // BFS를 통해 친구의 친구들까지 탐색
    while (!q.empty()) {
        string current = q.front();
        q.pop();

        for (const string& friendName : students.at(current).friends) {
            if (notified.find(friendName) == notified.end() && friendName != aStudent) {
                notified.insert(friendName);
                q.push(friendName);
            }
        }
    }

    // A 학생을 제외한 알림을 받은 학생 수 반환
    return notified.size();
}

int main() {
    int n;
    cin >> n;
    cin.ignore();

    unordered_map<string, Student> students;

    for (int i = 0; i < n; ++i) {
        string info;
        getline(cin, info);
        Student student = parseStudentInfo(info);
        students[student.name] = student;
    }

    string aStudent;
    getline(cin, aStudent);

    cout << calculateNotificationCount(students, aStudent) << endl;

    return 0;
}
