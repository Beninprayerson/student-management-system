#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;

    void input() {
        cout << "Enter ID: ";
        cin >> id;

        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);

        cout << "Enter Age: ";
        cin >> age;

        cin.ignore();
        cout << "Enter Course: ";
        getline(cin, course);
    }

    void display() {
        cout << "\nID: " << id
             << "\nName: " << name
             << "\nAge: " << age
             << "\nCourse: " << course
             << "\n-------------------\n";
    }
};

const string FILE_NAME = "students.txt";

vector<Student> loadStudents() {
    vector<Student> students;
    ifstream file(FILE_NAME);

    string line;

    while (getline(file, line)) {
        Student s;
        stringstream ss(line);

        string temp;

        getline(ss, temp, ',');
        s.id = stoi(temp);

        getline(ss, s.name, ',');

        getline(ss, temp, ',');
        s.age = stoi(temp);

        getline(ss, s.course);

        students.push_back(s);
    }

    file.close();
    return students;
}

void saveStudents(vector<Student>& students) {
    ofstream file(FILE_NAME);

    for (auto s : students) {
        file << s.id << ","
             << s.name << ","
             << s.age << ","
             << s.course << endl;
    }

    file.close();
}

void addStudent() {
    vector<Student> students = loadStudents();

    Student s;
    s.input();

    students.push_back(s);
    saveStudents(students);

    cout << "\nStudent Added Successfully!\n";
}

void displayStudents() {
    vector<Student> students = loadStudents();

    if (students.empty()) {
        cout << "\nNo Records Found.\n";
        return;
    }

    for (auto s : students) {
        s.display();
    }
}

void deleteStudent() {
    vector<Student> students = loadStudents();

    int id;
    cout << "Enter Student ID to Delete: ";
    cin >> id;

    bool found = false;

    for (auto it = students.begin(); it != students.end(); it++) {
        if (it->id == id) {
            students.erase(it);
            found = true;
            break;
        }
    }

    saveStudents(students);

    if (found)
        cout << "\nStudent Deleted!\n";
    else
        cout << "\nStudent Not Found.\n";
}

void updateStudent() {
    vector<Student> students = loadStudents();

    int id;
    cout << "Enter Student ID to Update: ";
    cin >> id;

    bool found = false;

    for (auto& s : students) {
        if (s.id == id) {
            found = true;

            cin.ignore();

            cout << "New Name: ";
            getline(cin, s.name);

            cout << "New Age: ";
            cin >> s.age;

            cin.ignore();

            cout << "New Course: ";
            getline(cin, s.course);

            break;
        }
    }

    saveStudents(students);

    if (found)
        cout << "\nStudent Updated!\n";
    else
        cout << "\nStudent Not Found.\n";
}

int main() {
    int choice;

    do {
        cout << "\n===== STUDENT MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Update Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";

        cout << "Enter Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addStudent();
                break;

            case 2:
                displayStudents();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                deleteStudent();
                break;

            case 5:
                cout << "\nExiting...\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}