#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100
#define NAME_LEN 50
#define LINE_LEN 256
#define DATA_FILE "students.txt"

typedef struct Student {
    char name[NAME_LEN];
    int id;
    float gpa;
} Student;


int load_students(Student arr[], int max);
int save_students(const Student arr[], int count);
void add_student(Student arr[], int *count);
void list_students(const Student arr[], int count);
int read_line(const char *prompt, char *buf, size_t size);


int main(void) {

    Student students[MAX_STUDENTS];
    int count = 0;
    char input[LINE_LEN];
    int running = 1;

    count = load_students(students, MAX_STUDENTS);

    printf("Loaded %d student(s) from %s\n", count, DATA_FILE);

    while (running) {

        printf("\n=== Student Management System ===\n");
        printf("1. List students\n");
        printf("2. Add student\n");
        printf("3. Save and Exit\n");

        int choice;

        if (read_line("Select an option: ", input, sizeof input) != 0) {
            choice = 3;
        } else {

            char *end;
            long value = strtol(input, &end, 10);

            choice = (end != input && *end == '\0')
                     ? (int)value
                     : 0;
        }


        switch (choice) {

            case 1:
                list_students(students, count);
                break;

            case 2:
                add_student(students, &count);
                break;

            case 3:

                if (save_students(students, count) != 0) {
                    printf("Error saving data.\n");
                } else {
                    printf("Data saved. Goodbye!\n");
                }

                running = 0;
                break;

            default:
                printf("Invalid option. Try again.\n");
        }
    }

    return EXIT_SUCCESS;
}


int read_line(const char *prompt, char *buf, size_t size) {

    printf("%s", prompt);
    fflush(stdout);

    if (fgets(buf, (int)size, stdin) == NULL) {
        return -1;
    }

    size_t len = strcspn(buf, "\r\n");

    if (buf[len] == '\0' && len == size - 1) {

        int c;

        while ((c = getchar()) != '\n' && c != EOF) {
        }
    }

    buf[len] = '\0';

    return 0;
}


int load_students(Student arr[], int max) {

    FILE *fp = fopen(DATA_FILE, "r");

    if (fp == NULL) {
        return 0;
    }

    char line[LINE_LEN];
    int count = 0;

    while (count < max &&
           fgets(line, sizeof line, fp) != NULL) {

        char name[NAME_LEN];
        int id;
        float gpa;

        if (sscanf(line,
                   "%49[^,],%d,%f",
                   name,
                   &id,
                   &gpa) == 3) {

            strcpy(arr[count].name, name);
            arr[count].id = id;
            arr[count].gpa = gpa;

            count++;
        }
    }

    fclose(fp);

    return count;
}


int save_students(const Student arr[], int count) {

    FILE *fp = fopen(DATA_FILE, "w");

    if (fp == NULL) {
        return -1;
    }

    for (int i = 0; i < count; i++) {

        fprintf(fp,
                "%s,%d,%.2f\n",
                arr[i].name,
                arr[i].id,
                arr[i].gpa);
    }

    fclose(fp);

    return 0;
}


void add_student(Student arr[], int *count) {

    if (*count >= MAX_STUDENTS) {

        printf("Cannot add more students (limit reached).\n");
        return;
    }

    char name[NAME_LEN];
    char id_input[LINE_LEN];
    char gpa_input[LINE_LEN];

    if (read_line("Enter name: ", name, sizeof name) != 0) {
        return;
    }

    if (read_line("Enter ID: ", id_input, sizeof id_input) != 0) {
        return;
    }

    if (read_line("Enter GPA: ", gpa_input, sizeof gpa_input) != 0) {
        return;
    }

    char *id_end;
    char *gpa_end;

    long id_value = strtol(id_input, &id_end, 10);
    float gpa_value = strtof(gpa_input, &gpa_end);

    if (name[0] == '\0' ||
        strchr(name, ',') != NULL ||
        id_end == id_input ||
        *id_end != '\0' ||
        gpa_end == gpa_input ||
        *gpa_end != '\0' ||
        gpa_value < 0.0f ||
        gpa_value > 4.0f) {

        printf("Invalid input. Student not added.\n");
        return;
    }

    strcpy(arr[*count].name, name);
    arr[*count].id = (int)id_value;
    arr[*count].gpa = gpa_value;

    (*count)++;

    printf("Student added successfully!\n");
}


void list_students(const Student arr[], int count) {

    if (count == 0) {

        printf("No students found.\n");
        return;
    }

    printf("%-5s %-20s %s\n",
           "ID",
           "Name",
           "GPA");

    for (int i = 0; i < count; i++) {

        printf("%-5d %-20s %.2f\n",
               arr[i].id,
               arr[i].name,
               arr[i].gpa);
    }
}
