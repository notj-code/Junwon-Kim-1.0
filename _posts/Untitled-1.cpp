#include <bits/stdc++.h>

using namespace std;

class Student {
public:
    char gender;
    vector<string> friends;
};

int main() {
    int n;
    cin >> n;
    cin.ignore(); 

    unordered_map<string, Student> students;

    for (int i = 0; i < n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        string name, gender_str, age_str;
        getline(ss, name, ',');
        getline(ss, gender_str, ',');
        getline(ss, age_str, ',');

        Student student;
        student.gender = gender_str[0];

        string friend_name;
        while (getline(ss, friend_name, ',')) {
            student.friends.push_back(friend_name);
        }

        students[name] = student;
    }

    string query_name;
    getline(cin, query_name);

    unordered_set<string> notified;
    queue<string> q;

    if (students.find(query_name) != students.end()) {
        for (const string& friend_name : students[query_name].friends) {
            if (friend_name != query_name) {
                q.push(friend_name);
                notified.insert(friend_name);
            }
        }
    }

    while (!q.empty()) {
        string current = q.front();
        q.pop();

        if (students.find(current) != students.end()) {
            for (const string& friend_name : students[current].friends) {
                if (notified.find(friend_name) == notified.end() && friend_name != query_name) {
                    q.push(friend_name);
                    notified.insert(friend_name);
                }
            }
        }
    }

    cout << notified.size() << endl;

    return 0;
}