#include <stdio.h>

struct Student
{
    int roll;
    char name[50];
    float marks;
};

void addStudent()
{
    struct Student s;
    FILE *fp;

    fp = fopen("student.txt", "a");

    printf("\nEnter Roll Number: ");
    scanf("%d", &s.roll);

    printf("Enter Name: ");
    scanf(" %[^\n]", s.name);

    printf("Enter Marks: ");
    scanf("%f", &s.marks);

    fprintf(fp, "%d %s %.2f\n",
            s.roll, s.name, s.marks);

    fclose(fp);

    printf("\nStudent added successfully.\n");
}

void displayStudents()
{
    struct Student s;
    FILE *fp;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\n----- Student Records -----\n");

    while(fscanf(fp, "%d %s %f",
                 &s.roll, s.name, &s.marks) != EOF)
    {
        printf("\nRoll Number: %d", s.roll);
        printf("\nName: %s", s.name);
        printf("\nMarks: %.2f\n", s.marks);
    }

    fclose(fp);
}

void searchStudent()
{
    struct Student s;
    FILE *fp;
    int roll;
    int found = 0;

    fp = fopen("student.txt", "r");

    if(fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s %f",
                 &s.roll, s.name, &s.marks) != EOF)
    {
        if(s.roll == roll)
        {
            printf("\nStudent Found!");
            printf("\nRoll Number: %d", s.roll);
            printf("\nName: %s", s.name);
            printf("\nMarks: %.2f\n", s.marks);

            found = 1;
            break;
        }
    }

    fclose(fp);

    if(found == 0)
    {
        printf("\nStudent not found.\n");
    }
}

void updateStudent()
{
    struct Student s;
    FILE *fp;
    FILE *temp;

    int roll;
    int found = 0;

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nEnter Roll Number to update: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s %f",
                 &s.roll, s.name, &s.marks) != EOF)
    {
        if(s.roll == roll)
        {
            printf("Enter new name: ");
            scanf(" %[^\n]", s.name);

            printf("Enter new marks: ");
            scanf("%f", &s.marks);

            found = 1;
        }

        fprintf(temp, "%d %s %.2f\n",
                s.roll, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if(found == 1)
    {
        printf("\nStudent updated successfully.\n");
    }
    else
    {
        printf("\nStudent not found.\n");
    }
}

void deleteStudent()
{
    struct Student s;
    FILE *fp;
    FILE *temp;

    int roll;
    int found = 0;

    fp = fopen("student.txt", "r");
    temp = fopen("temp.txt", "w");

    if(fp == NULL)
    {
        printf("\nNo records found.\n");
        return;
    }

    printf("\nEnter Roll Number to delete: ");
    scanf("%d", &roll);

    while(fscanf(fp, "%d %s %f",
                 &s.roll, s.name, &s.marks) != EOF)
    {
        if(s.roll == roll)
        {
            found = 1;
            continue;
        }

        fprintf(temp, "%d %s %.2f\n",
                s.roll, s.name, s.marks);
    }

    fclose(fp);
    fclose(temp);

    remove("student.txt");
    rename("temp.txt", "student.txt");

    if(found == 1)
    {
        printf("\nStudent deleted successfully.\n");
    }
    else
    {
        printf("\nStudent not found.\n");
    }
}

int main()
{
    int choice;

    while(1)
    {
        printf("\n\n===== STUDENT MANAGEMENT =====\n");

        printf("1. Add Student\n");
        printf("2. Delete Student\n");
        printf("3. Update Student\n");
        printf("4. Search Student\n");
        printf("5. Display Students\n");
        printf("6. Exit\n");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                addStudent();
                break;

            case 2:
                deleteStudent();
                break;

            case 3:
                updateStudent();
                break;

            case 4:
                searchStudent();
                break;

            case 5:
                displayStudents();
                break;

            case 6:
                return 0;

            default:
                printf("\nInvalid choice.\n");
        }
    }
}