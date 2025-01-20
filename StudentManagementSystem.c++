#include <iostream>
#include <string>
using namespace std;

struct student {
    string name;
    int id;
    int age;
    student* nxt;
};

student* start = NULL;

// Function to add a node at the beginning
void add_at_first() {
    student* s1 = new student;
    cout << "Please enter your name: ";
    cin >> s1->name;
    cout << "Please enter your ID: ";
    cin >> s1->id;
    cout << "Please enter your age: ";
    cin >> s1->age;
    s1->nxt = NULL;

    if (start == NULL) { // If the list is empty
        start = s1;
    } else {
        s1->nxt = start;
        start = s1;
    }
}

// Function to add a node at the end
void add_at_end() {
    student* s1 = new student;
    cout << "Please enter your name: ";
    cin >> s1->name;
    cout << "Please enter your ID: ";
    cin >> s1->id;
    cout << "Please enter your age: ";
    cin >> s1->age;
    s1->nxt = NULL;

    if (start == NULL) { // If the list is empty
        start = s1;
    } else {
        student* temp = start;
        while (temp->nxt != NULL) {
            temp = temp->nxt;
        }
        temp->nxt = s1;
    }
}



int main() {
    int ch;

    do {
        cout << "\nMenu:" << endl;
        cout << "1. Add a student at the beginning" << endl;
        cout << "2. Add a student at the end" << endl;
        cout << "3. Display all students (Forward)" << endl;
        cout << "4. Display all students (Backward)" << endl;
        cout << "0. Exit" << endl;
        cout << "Please enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                add_at_first();
                break;
            case 2:
                add_at_end();
                break;
            case 3:
                display_fwd();
                break;
            case 4:
                display_bwd();
                break;
            case 0:
                cout << "Exiting the program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (ch != 0);

    free_memory();
    return 0;
}
