#include <stdio.h>

#define MAX_STUDENTS 100
#define MAX_SUBJECTS 11
#define MIN_SUBJECTS 4

// Function to perform bubble sort on averages array and maintain student IDs accordingly
void bubbleSort(float avg[], int studentIDs[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (avg[j] < avg[j + 1]) {
                // Swap averages
                float tempAvg = avg[j];
                avg[j] = avg[j + 1];
                avg[j + 1] = tempAvg;
                // Swap student IDs accordingly
                int tempID = studentIDs[j];
                studentIDs[j] = studentIDs[j + 1];
                studentIDs[j + 1] = tempID;
            }
        }
    }
}

// Function to display students in tabular form with their IDs, averages, and positions
void displayStudents(int studentIDs[], float averages[], int numStudents) {
    printf("\n\nStudent ID\tAverage\t\tPosition\n");
    for (int i = 0; i < numStudents; ++i) {
        printf("%d\t\t%.2f\t\t%d\n", studentIDs[i], averages[i], i + 1);
    }
}

int main() {
    int numStudents;
    int studentIDs[MAX_STUDENTS];
    float averages[MAX_STUDENTS];
    int numSubjects[MAX_STUDENTS];

    // Input number of students
    printf("Enter the number of students in the class: ");
    scanf("%d", &numStudents);

    // Validate number of students
    if (numStudents <= 0 || numStudents > MAX_STUDENTS) {
        printf("Invalid number of students. Please enter a number from 1 to %d.\n", MAX_STUDENTS);
        return 1;
    }

    // Input marks and calculate averages for each student
    for (int i = 0; i < numStudents; ++i) {
        int totalMarks = 0;
        int marks;
        int subjects;

        printf("\nStudent %d:\n", i + 1);

        // Input number of subjects for the student
        do {
            printf("Enter the number of subjects for this student (between %d and %d): ", MIN_SUBJECTS, MAX_SUBJECTS);
            scanf("%d", &subjects);
            if (subjects < MIN_SUBJECTS || subjects > MAX_SUBJECTS) {
                printf("Invalid number of subjects. Please enter a number between %d and %d.\n", MIN_SUBJECTS, MAX_SUBJECTS);
            }
        } while (subjects < MIN_SUBJECTS || subjects > MAX_SUBJECTS);
        numSubjects[i] = subjects;

        // Input marks for Maths
        do {
            printf("Enter marks for Maths (coefficient 5, between 0 and 20): ");
            scanf("%d", &marks);
            if (marks < 0 || marks > 20) {
                printf("Invalid marks. Please enter a number between 0 and 20.\n");
            }
        } while (marks < 0 || marks > 20);
        totalMarks += (marks * 5);

        // Input marks for English
        do {
            printf("Enter marks for English (coefficient 5, between 0 and 20): ");
            scanf("%d", &marks);
            if (marks < 0 || marks > 20) {
                printf("Invalid marks. Please enter a number between 0 and 20.\n");
            }
        } while (marks < 0 || marks > 20);
        totalMarks += (marks * 5);

        // Input marks for other subjects
        for (int j = 2; j < subjects; ++j) {
            do {
                printf("Enter marks for Subject %d (coefficient 3, between 0 and 20): ", j + 1);
                scanf("%d", &marks);
                if (marks < 0 || marks > 20) {
                    printf("Invalid marks. Please enter a number between 0 and 20.\n");
                }
            } while (marks < 0 || marks > 20);
            totalMarks += (marks * 3);
        }

        // Calculate average on a 20-point scale
        float average = (float) totalMarks / ((subjects - 2) * 3 + 10); 
        averages[i] = average;
        studentIDs[i] = i + 1; // Assign student IDs starting from 1
    }

    // Sort students based on average using bubble sort
    bubbleSort(averages, studentIDs, numStudents);

    // Display students in tabular form with their IDs, averages, and positions
    displayStudents(studentIDs, averages, numStudents);

    return 0;
}
