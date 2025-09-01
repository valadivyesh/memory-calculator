#include <iostream>
#include <vector>
using namespace std;

template <typename T>
class Student {
    T sid;
    string sname;

public:
    Student(T id, string name) {
        sid = id;
        sname = name;
    }

    void showData() {
        cout << "ID: " << sid << ", Name: " << sname << endl;
    }

    T getId() {
        return sid;
    }
};

int main() {
    vector<Student<int>> list;
    int option;

    while (1) {
        cout << "1. Add Student" << endl;
        cout << "2. Show All Students" << endl;
        cout << "3. Delete Student by ID" << endl;
        cout << "4. Find Student by ID" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter option: ";
        cin >> option;

        if (option == 1) {
            int id;
            string name;
            cout << "Enter ID: ";
            cin >> id;
            cout << "Enter Name: ";
            cin >> name;
            list.push_back(Student<int>(id, name));
            cout << "Student added." << endl;
        }

        else if (option == 2) {
            for (int i = 0; i < list.size(); i++) {
                list[i].showData();
            }
        }

        else if (option == 3) {
            int id;
            double found = 0;
            cout << "Enter ID to delete: ";
            cin >> id;
            for (auto it = list.begin(); it != list.end(); it++) {
                if (it->getId() == id) {
                    list.erase(it);
                    cout << "Student deleted." << endl;
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                cout << "ID not found." << endl;
            }
        }

        else if (option == 4) {
            int id;
            double found = 0;
            cout << "Enter ID to find: ";
            cin >> id;
            for (int i = 0; i < list.size(); i++) {
                if (list[i].getId() == id) {
                    list[i].showData();
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                cout << "ID not found." << endl;
            }
        }

        else if (option == 5) {
            cout << "Thank you." << endl;
            break;
        }

        else {
            cout << "Wrong option." << endl;
        }
    }

    return 0;
}