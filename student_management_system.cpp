#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student {
    int roll;
    string name;
    int age;
    string course;
};

void addStudent(Student students[], int &count);
void displayStudents(Student students[], int count);
void searchStudent(Student students[], int count, int roll);

int main() {
    Student students[MAX_STUDENTS];
    int count = 0;
    int choice;

    while (true) {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by Roll Number\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count < MAX_STUDENTS)
                addStudent(students, count);
            else
                cout << "Maximum student limit reached!\n";
        } else if (choice == 2) {
            displayStudents(students, count);
        } else if (choice == 3) {
            int roll;
            cout << "Enter roll number to search: ";
            cin >> roll;
            searchStudent(students, count, roll);
        } else if (choice == 4) {
            cout << "Exiting program. Goodbye!\n";
            break;
        } else {
            cout << "Invalid choice! Try again.\n";
        }
    }

    return 0;
}

void addStudent(Student students[], int &count) {
    Student s;
    cout << "Enter Roll Number: ";
    cin >> s.roll;
    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter Course: ";
    getline(cin, s.course);

    students[count] = s;
    count++;
    cout << "Student added successfully!\n";
}

void displayStudents(Student students[], int count) {
    if (count == 0) {
        cout << "No student records found.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < count; i++) {
        cout << "Roll: " << students[i].roll << ", Name: " << students[i].name
             << ", Age: " << students[i].age << ", Course: " << students[i].course << "\n";
    }
}

void searchStudent(Student students[], int count, int roll) {
    for (int i = 0; i < count; i++) {
        if (students[i].roll == roll) {
            cout << "Student found:\n";
            cout << "Roll: " << students[i].roll << ", Name: " << students[i].name
                 << ", Age: " << students[i].age << ", Course: " << students[i].course << "\n";
            return;
        }
    }
    cout << "Student with Roll Number " << roll << " not found.\n";
} 
