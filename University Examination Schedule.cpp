#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;


struct Examination {
    string courseCode;
    string courseTitle;
    string date;
    string time;
    string venue;
    int numberOfStudents;
};


vector<Examination> examSchedule;
queue<Examination> examQueue;


void addExamination() {
    Examination exam;

    cout << "\nEnter Course Code: ";
    cin >> exam.courseCode;

    cin.ignore();
    cout << "Enter Course Title: ";
    getline(cin, exam.courseTitle);

    cout << "Enter Examination Date: ";
    getline(cin, exam.date);

    cout << "Enter Examination Time: ";
    getline(cin, exam.time);

    cout << "Enter Venue: ";
    getline(cin, exam.venue);

    cout << "Enter Number of Students: ";
    cin >> exam.numberOfStudents;

    examSchedule.push_back(exam);
    examQueue.push(exam);

    cout << "\nExamination added successfully!\n";
}


void deleteExamination() {
    string code;
    bool found = false;

    cout << "\nEnter Course Code to delete: ";
    cin >> code;

    for (int i = 0; i < examSchedule.size(); i++) {
        if (examSchedule[i].courseCode == code) {
            examSchedule.erase(examSchedule.begin() + i);
            found = true;
            cout << "\nExamination deleted successfully!\n";
            break;
        }
    }

    if (!found) {
        cout << "\nExamination not found!\n";
    }
}


void searchExamination() {
    string code;
    bool found = false;

    cout << "\nEnter Course Code to search: ";
    cin >> code;

    for (const auto& exam : examSchedule) {
        if (exam.courseCode == code) {
            cout << "\nExamination Found:\n";
            cout << "Course Code: " << exam.courseCode << endl;
            cout << "Course Title: " << exam.courseTitle << endl;
            cout << "Date: " << exam.date << endl;
            cout << "Time: " << exam.time << endl;
            cout << "Venue: " << exam.venue << endl;
            cout << "Number of Students: " << exam.numberOfStudents << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nExamination not found!\n";
    }
}


void displaySchedule() {
    if (examSchedule.empty()) {
        cout << "\nNo examinations scheduled.\n";
        return;
    }

    cout << "\n--- Examination Schedule ---\n";

    for (const auto& exam : examSchedule) {
        cout << "\nCourse Code: " << exam.courseCode << endl;
        cout << "Course Title: " << exam.courseTitle << endl;
        cout << "Date: " << exam.date << endl;
        cout << "Time: " << exam.time << endl;
        cout << "Venue: " << exam.venue << endl;
        cout << "Number of Students: " << exam.numberOfStudents << endl;
    }
}


void allocateVenue() {
    string code;
    bool found = false;

    cout << "\nEnter Course Code to allocate/change venue: ";
    cin >> code;

    cin.ignore();

    for (auto& exam : examSchedule) {
        if (exam.courseCode == code) {
            cout << "Enter New Venue: ";
            getline(cin, exam.venue);

            cout << "\nVenue allocated successfully!\n";
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "\nExamination not found!\n";
    }
}


void manageExamQueue() {
    if (examQueue.empty()) {
        cout << "\nExamination queue is empty.\n";
        return;
    }

    cout << "\n--- Examination Queue ---\n";

    queue<Examination> tempQueue = examQueue;

    while (!tempQueue.empty()) {
        Examination exam = tempQueue.front();
        tempQueue.pop();

        cout << "\nCourse Code: " << exam.courseCode << endl;
        cout << "Course Title: " << exam.courseTitle << endl;
        cout << "Date: " << exam.date << endl;
        cout << "Time: " << exam.time << endl;
        cout << "Venue: " << exam.venue << endl;
        cout << "Number of Students: " << exam.numberOfStudents << endl;
    }
}


int main() {
    int choice;

    do {
        cout << " University Examination Scheduling System\n";
        cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n";
        cout << "1. Add Examination\n";
        cout << "2. Delete Examination\n";
        cout << "3. Search Examination\n";
        cout << "4. Display Schedule\n";
        cout << "5. Allocate Examination Venue\n";
        cout << "6. Manage Examination Queue\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExamination();
                break;

            case 2:
                deleteExamination();
                break;

            case 3:
                searchExamination();
                break;

            case 4:
                displaySchedule();
                break;

            case 5:
                allocateVenue();
                break;

            case 6:
                manageExamQueue();
                break;

            case 7:
                cout << "\nExiting system. Thank you!\n";
                break;

            default:
                cout << "\nInvalid choice! Please try again.\n";
        }

    } while (choice != 7);

    return 0;
}
