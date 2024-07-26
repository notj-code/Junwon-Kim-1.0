
#include <bits/stdc++.h>

using namespace std;

struct Student {
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

    int male_count = 0;
    int female_count = 0;

    if (students.find(query_name) != students.end()) {
        for (const string& friend_name : students[query_name].friends) {
            if (students.find(friend_name) != students.end()) {
                if (students[friend_name].gender == 'M') {
                    ++male_count;
                } else if (students[friend_name].gender == 'F') {
                    ++female_count;
                }
            }
        }
    }

    // 결과 출력
    cout << male_count << endl;
    cout << female_count << endl;

    return 0;
}