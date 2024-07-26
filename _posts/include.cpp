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

    for (int i=0l i<n; ++i) {
        string line;
        getline(cin, line);
        stringstream ss(line);

        stirng name, gender_str, age_str;
        getline(ss, name, ',');
        getline(ss, gender_str, ',');
        getline(ss, age_str, ',');

        Student student;
        student.gender = gender_str[0];

        string friend_name;
        
    }
}