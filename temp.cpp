#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for course information
struct Course {
    char name[50];
    int courseId;
    float assignmentScore;
    float labScore;
    float inClassExerciseScore;
    float projectScore;
    float finalExamScore;
};

// Function declarations
void mainMenu();
void editCourseMenu();
void editGradeMenu();
void addCourse();
void deleteCourse();
void viewCourse();
void editGrade();
void calculateExpectedFinalGrade();

int main() {
    mainMenu();
    return 0;
}

// Main Menu function
void mainMenu() {
    int choice;
    do {
        printf("\n============== Main Menu ==============");
        printf("\n	1. Edit Course");
        printf("\n	2. Edit Grade");
        printf("\n	3. Expected Final Grade");
        printf("\n	4. View Course");
        printf("\n	5. Exit");
        printf("\n=======================================");
        printf("\n\nEnter a number and choose an operation: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                editCourseMenu();
                break;
            case 2:
                editGradeMenu();
                break;
            case 3:
                calculateExpectedFinalGrade();
                break;
            case 4:
                viewCourse();
                break;
            case 5:
                printf("\nExiting Program...\n");
                exit(0);
            default:
                printf("\nInvalid choice. Please try again.\n");
        }
    } while(choice != 5);
}

// Sub-menu for editing courses
void editCourseMenu() {
    // TODO: Implement this function
}

// Sub-menu for editing grades
void editGradeMenu() {
    // TODO: Implement this function
}

// Function to add a course
void addCourse() {
    // TODO: Implement this function
}

// Function to delete a course
void deleteCourse() {
    // TODO: Implement this function
}

// Function to view a course
void viewCourse() {
    // TODO: Implement this function
}

// Function to edit grade
void editGrade() {
    // TODO: Implement this function
}

// Function to calculate expected final grade
void calculateExpectedFinalGrade() {
    // TODO: Implement this function
}

    if (!found) {
        printf("\nCourse not found.\n");
    }
}

// Function to view a course
void viewCourse() {
    int courseId, found = 0;
    printf("\nEnter the course ID to view: ");
    scanf("%d", &courseId);

    for (int i = 0; i < courseCount; i++) {
        if (courses[i].courseId == courseId) {
            displayCourse(courses[i]);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nCourse not found.\n");
    }
}

// Function to edit grade
void editGrade(struct Course *course) {
    printf("\nEditing grades for course: %s\n", course->name);
    inputGrade(course);
}

// Function to calculate expected final grade
void calculateExpectedFinalGrade() {
    int courseId, targetScore, found = 0;
    printf("\nEnter the course ID for calculation: ");
    scanf("%d", &courseId);
    printf("\nEnter the target total score: ");
    scanf("%d", &targetScore);

    for (int i = 0; i < courseCount; i++) {
        if (courses[i].courseId == courseId) {
            struct Course course = courses[i];
            float totalContinuousScore = 0;
            for (int j = 0; j < course.numOfGrades; j++) {
                totalContinuousScore += course.grades[j];
            }
            float neededFinalScore = (targetScore - totalContinuousScore) / (1.0 - totalContinuousScore / 100.0);
            printf("\nTo achieve a total score of %d, you need %.2f in the final exam.\n", targetScore, neededFinalScore);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("\nCourse not found.\n");
    }
}

// Function to input grades for a course
void inputGrade(struct Course *course) {
    int numOfGrades;
    printf("\nEnter the number of grades: ");
    scanf("%d", &numOfGrades);
    course->numOfGrades = numOfGrades;

    for (int i = 0; i < numOfGrades; i++) {
        printf("\nEnter score for grade %d: ", i + 1);
        scanf("%f", &course->grades[i]);
    }
}

// Function to display course information
void displayCourse(struct Course course) {
    printf("\nCourse Name: %s", course.name);
    printf("\nCourse ID: %d", course.courseId);
    printf("\nGrades: ");
    for (int i = 0; i < course.numOfGrades; i++) {
        printf("%.2f ", course.grades[i]);
    }
    printf("\n");
}
