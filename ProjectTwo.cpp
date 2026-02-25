// ProjectTwo.cpp
// ABCU Advising Assistance Program
//By Richard Difiore

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <cctype>

using namespace std;

struct Course {
    string courseNumber;
    string title;
    vector<string> prerequisites;
};

// trim spaces
string trim(const string& s) {
    size_t start = 0;
    while (start < s.size() && isspace(s[start])) start++;
    size_t end = s.size();
    while (end > start && isspace(s[end - 1])) end--;
    return s.substr(start, end - start);
}

// uppercase conversion
string toUpperStr(string s) {
    for (char& c : s)
        c = toupper(c);
    return s;
}

// split CSV line
vector<string> splitCSVLine(const string& line) {
    vector<string> tokens;
    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        tokens.push_back(trim(token));
    }
    return tokens;
}

// validate prerequisites
bool validatePrereqsExist(const unordered_map<string, Course>& courses) {
    for (auto& pair : courses) {
        const Course& c = pair.second;
        for (string prereq : c.prerequisites) {
            if (courses.find(prereq) == courses.end()) {
                cout << "ERROR: " << prereq << " listed as prerequisite but not found in file." << endl;
                return false;
            }
        }
    }
    return true;
}

// load file
bool loadCourses(string filePath, unordered_map<string, Course>& courses) {
    ifstream file(filePath);

    if (!file.is_open()) {
        cout << "ERROR: Could not open file." << endl;
        return false;
    }

    courses.clear();
    string line;

    while (getline(file, line)) {
        if (trim(line).empty()) continue;

        vector<string> tokens = splitCSVLine(line);

        if (tokens.size() < 2) {
            cout << "ERROR: Invalid file format." << endl;
            return false;
        }

        Course c;
        c.courseNumber = toUpperStr(tokens[0]);
        c.title = tokens[1];

        // ***** FIXED PART — ignores empty prereqs *****
        for (size_t i = 2; i < tokens.size(); i++) {
            string prereq = toUpperStr(trim(tokens[i]));
            if (!prereq.empty()) {              // prevents the error you saw
                c.prerequisites.push_back(prereq);
            }
        }

        courses[c.courseNumber] = c;
    }

    if (!validatePrereqsExist(courses)) return false;

    cout << "Courses loaded successfully." << endl;
    return true;
}

// print sorted course list
void printCourseList(const unordered_map<string, Course>& courses) {
    vector<string> keys;

    for (auto& pair : courses)
        keys.push_back(pair.first);

    sort(keys.begin(), keys.end());

    for (string key : keys) {
        cout << key << ", " << courses.at(key).title << endl;
    }
}

// print one course
void printCourse(const unordered_map<string, Course>& courses) {
    cout << "Enter course number: ";
    string courseNum;
    getline(cin, courseNum);
    courseNum = toUpperStr(trim(courseNum));

    auto it = courses.find(courseNum);

    if (it == courses.end()) {
        cout << "Course not found." << endl;
        return;
    }

    const Course& c = it->second;
    cout << c.courseNumber << ", " << c.title << endl;

    if (c.prerequisites.empty()) {
        cout << "Prerequisites: None" << endl;
    } else {
        cout << "Prerequisites:" << endl;
        for (string prereq : c.prerequisites) {
            cout << "  " << prereq << ", " << courses.at(prereq).title << endl;
        }
    }
}

// menu
int main() {
    unordered_map<string, Course> courses;
    bool loaded = false;
    int choice = 0;

    cout << "ABCU Advising Assistance Program" << endl;

    while (choice != 9) {
        cout << "\nMenu:" << endl;
        cout << " 1. Load Data Structure" << endl;
        cout << " 2. Print Course List" << endl;
        cout << " 3. Print Course" << endl;
        cout << " 9. Exit" << endl;
        cout << "Enter choice: ";

        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            cout << "Enter file name: ";
            string fileName;
            getline(cin, fileName);
            loaded = loadCourses(fileName, courses);

        } else if (choice == 2) {
            if (!loaded)
                cout << "Please load data first." << endl;
            else
                printCourseList(courses);

        } else if (choice == 3) {
            if (!loaded)
                cout << "Please load data first." << endl;
            else
                printCourse(courses);

        } else if (choice == 9) {
            cout << "Goodbye." << endl;

        } else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}