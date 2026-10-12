#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LEN 50

typedef struct Student {
    char name[MAX_NAME_LEN];
    int age;
    float gpa;
} Student;

// Function prototypes (do not change these signatures – the autograder calls them directly)
int save_student(const Student *s, const char *filename);  // 0 on success, -1 on error
int load_student(const char *filename, Student *out);      // 0 on success, -1 on error

int main(void) {
    Student s1 = {0};
    strcpy(s1.name, "Alice");
    s1.age = 21;
    s1.gpa = 3.75f;

    Student loaded = {0};
    const char *filename = "student.txt";

    printf("Saving student to file...\n");

    if (save_student(&s1, filename) == -1) {
        printf("Error saving student.\n");
        return EXIT_FAILURE;
    }

    printf("Loading student from file...\n");
    
    if (load_student(filename, &loaded) == -1) {
        printf("Error loading student.\n");
        return EXIT_FAILURE;
    }

    printf("Loaded student: %s, %d, GPA %.2f\n",
           loaded.name, loaded.age, loaded.gpa);

    return EXIT_SUCCESS;

    (void)filename; (void)loaded;  // remove this line once you use these variables
    return EXIT_SUCCESS;
}

// TODO: Implement save_student()
// Open the file for writing ("w"), return -1 if fopen() fails,
// write "name age gpa" on one line with fprintf(), close the file and return 0.
int save_student(const Student *s, const char *filename) {
    (void)s; (void)filename;  // remove this line when you implement the function
    return -1;
}

// TODO: Implement load_student()
// Open the file for reading ("r"), return -1 if fopen() fails,
// read the three fields with fscanf(fp, "%49s %d %f", ...) and check that it returned 3,
// close the file in every case, and return 0 on success / -1 on failure.
int load_student(const char *filename, Student *out) {
    (void)filename; (void)out;  // remove this line when you implement the function
    return -1;
}
