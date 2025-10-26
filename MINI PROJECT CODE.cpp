#include <iostream>
using namespace std;
float calculateAverage(int marks[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += marks[i];
    }
    return static_cast<float>(sum) / n;
}
int findMax(int marks[], int n) {
    int max = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] > max) {
            max = marks[i];
        }
    }
    return max;
}
int findMin(int marks[], int n) {
    int min = marks[0];
    for (int i = 1; i < n; i++) {
        if (marks[i] < min) {
            min = marks[i];
        }
    }
    return min;
}
void sortMarks(int marks[], int n, bool ascending = true) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if ((ascending && marks[j] > marks[j + 1]) || (!ascending && marks[j] < marks[j + 1])) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp;
            }
        }
    }
}
void displayMenu() {
    cout << "1. Calculate Average\n";
    cout << "2. Find Highest Mark\n";
    cout << "3. Find Lowest Mark\n";
    cout << "4. Sort Marks Ascending\n";
    cout << "5. Sort Marks Descending\n";
    cout << "6. Exit\n";
}

int main() {
    int n;
    cout << "Enter number of students: ";
    cin >> n;
    
    int marks[n];
    cout << "Enter marks for " << n << " students:\n";
    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << ": ";
        cin >> marks[i];
    }

    int choice;
    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Average Marks: " << calculateAverage(marks, n) << endl;
                break;
            case 2:
                cout << "Highest Mark: " << findMax(marks, n) << endl;
                break;
            case 3:
                cout << "Lowest Mark: " << findMin(marks, n) << endl;
                break;
            case 4:
                sortMarks(marks, n, true);
                cout << "Marks sorted in ascending order: ";
                for (int i = 0; i < n; i++) {
                    cout << marks[i] << " ";
                }
                cout << endl;
                break;
            case 5:
                sortMarks(marks, n, false);
                cout << "Marks sorted in descending order: ";
                for (int i = 0; i < n; i++) {
                    cout << marks[i] << " ";
                }
                cout << endl;
                break;
            case 6:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Please try again.\n";
                break;
        }
    } while (choice != 6);

    return 0;
}

