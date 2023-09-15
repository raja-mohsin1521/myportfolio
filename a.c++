#include <iostream>
#include <string>

using namespace std;

struct Student {
    string name;
    int rollNo;
    float cgpa;
    Student* next;

    Student(string n, int r, float c) : name(n), rollNo(r), cgpa(c), next(nullptr) {}
};

// Function to create a new student node
Student* CreateNode(string name, int rollNo, float cgpa) {
    return new Student(name, rollNo, cgpa);
}

// Function to insert a student at the tail of the list
void InsertionAtTail(Student*& head, string name, int rollNo, float cgpa) {
    Student* newNode = CreateNode(name, rollNo, cgpa);
    if (!head) {
        head = newNode;
    } else {
        Student* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to insert a student at the head of the list
void InsertionAtHead(Student*& head, string name, int rollNo, float cgpa) {
    Student* newNode = CreateNode(name, rollNo, cgpa);
    newNode->next = head;
    head = newNode;
}

// Function to search for a student by roll number
Student* SearchInLinkedList(Student* head, int rollNo) {
    Student* current = head;
    while (current) {
        if (current->rollNo == rollNo) {
            return current;
        }
        current = current->next;
    }
    return nullptr; // Student not found
}

// Function to display student information
void DisplayStudentInfo(Student* student) {
    if (student) {
        cout << "Name: " << student->name << endl;
        cout << "Roll No: " << student->rollNo << endl;
        cout << "CGPA: " << student->cgpa << endl;
    } else {
        cout << "Student not found." << endl;
    }
}

int main() {
    Student* head = nullptr;

    InsertionAtHead(head, "Alice", 101, 3.8);
    InsertionAtTail(head, "Bob", 102, 3.7);
    InsertionAtTail(head, "Charlie", 103, 3.9);

    // Adding "Ali" to the tail of the list
    InsertionAtTail(head, "Ali", 214056, 3.3);

    DisplayStudentInfo(SearchInLinkedList(head, 101));    // Display Alice's info
    DisplayStudentInfo(SearchInLinkedList(head, 214056)); // Display Ali's info
    DisplayStudentInfo(SearchInLinkedList(head, 104));    // Student not found

    return 0;
}
