#include <iostream>
#include <vector>
#include <string>
using namespace std;

float gradeToPoint(string grade) {
    if (grade == "A+" || grade == "A") return 4.0;
    else if (grade == "A-") return 3.7;
    else if (grade == "B+") return 3.3;
    else if (grade == "B") return 3.0;
    else if (grade == "B-") return 2.7;
    else if (grade == "C+") return 2.3;
    else if (grade == "C") return 2.0;
    else if (grade == "C-") return 1.7;
    else if (grade == "D+") return 1.3;
    else if (grade == "D") return 1.0;
    else if (grade == "D-") return 0.7;
    else if (grade == "F") return 0.0;
    else return 0.0;
}

float calculateGPA(int numCourses) {
    float totalGradePoints = 0, totalCredits = 0;

    vector<string> courseNames(numCourses);
    vector<string> grades(numCourses);
    vector<int> credits(numCourses);

    for (int i = 0; i < numCourses; ++i) {
        cout << "Enter course name: ";
        cin >> courseNames[i];

        cout << "Enter grade (A+/A/A-/B+/...) for " << courseNames[i] << ": ";
        cin >> grades[i];

        cout << "Enter credit hours for " << courseNames[i] << ": ";
        cin >> credits[i];

        float gradePoints = gradeToPoint(grades[i]);
        totalGradePoints += gradePoints * credits[i];
        totalCredits += credits[i];
    }

    return totalCredits > 0 ? totalGradePoints / totalCredits : 0;
}

int main() {
    int numSemesters;

    cout << "Enter the number of semesters: ";
    cin >> numSemesters;

    vector<float> gpaList(numSemesters);

    for (int i = 0; i < numSemesters; ++i) {
        int numCourses;
        cout << "Enter the number of courses for semester " << (i + 1) << ": ";
        cin >> numCourses;

        cout << "Semester " << (i + 1) << " GPA calculation:\n";
        gpaList[i] = calculateGPA(numCourses);

        cout << "GPA for semester " << (i + 1) << ": " << gpaList[i] << endl;
    }

    // Calculate CGPA
    float totalGPA = 0;
    for (float gpa : gpaList) {
        totalGPA += gpa;
    }

    float cgpa = numSemesters > 0 ? totalGPA / numSemesters : 0;

    cout << "\nCGPA Calculation:\n";
    cout << "Total GPA for all semesters: " << totalGPA << endl;
    cout << "CGPA: " << cgpa << endl;

    return 0;
}
