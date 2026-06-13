#include <iostream>
#include <vector>
using namespace std;
struct Student {
    int id;
    string name;
    float marks;
};
vector<Student> students;
// Add student
void addStudent() {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Marks: ";
    cin >> s.marks;
    students.push_back(s);
    cout << "Student Added Successfully!\n";
}
// View students
void viewStudents() {
    if (students.empty()) {
        cout << "No students found!\n";
        return;
    }
    for (int i = 0; i < students.size(); i++) {
        cout << "\nID: " << students[i].id;
        cout << "\nName: " << students[i].name;
        cout << "\nMarks: " << students[i].marks;
        cout << "\n---------------------\n";
    }
}
// Search student
void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;

    for (auto s : students) {
        if (s.id == id) {
            cout << "\nStudent Found!";
            cout << "\nID: " << s.id;
            cout << "\nName: " << s.name;
            cout << "\nMarks: " << s.marks << endl;
            return;
        }
    }

    cout << "Student not found!\n";
}
// Delete student
void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (int i = 0; i < students.size(); i++) {
        if (students[i].id == id) {
            students.erase(students.begin() + i);
            cout << "Student Deleted Successfully!\n";
            return;
        }
    }

    cout << "Student not found!\n";
}
int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. View Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }
    } while (choice != 5);
    return 0;
}