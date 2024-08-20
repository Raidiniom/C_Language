#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 5

typedef char String[30];

typedef struct {
    String fname;
    String lname;
} Name, *NameList, NameArray[MAX];

typedef struct {
    int stud_id;
    Name stud_name;
    char sex; // m or f
} Student, *StudentPtr, StudentList[MAX];

void displayName(Name n);
void displayStudent(Student s);
void changeName(Student *s, String lname);

Name createName(String fname, String lname);
Student createStudent(int id, Name name, char sex);
/**
 *   Adds a student into the student list.
**/
void addStudent(StudentList list, int *count, Student *s);

/**
 *   Return the number of female students in the list.
**/
int countFemale(StudentList list, int *count);

/**
 *   Get the name of the female students and store into names from the list of students
**/
void getFemaleNames(StudentList list, int *count);

int main() {
    int count = 0;
    Name n1 = {"Von", "Nueman"};
    Name n2 = {"Erika", "Liaken"};
    Name n3 = {"Mei", "Rousuken"};
    Name n4 = {"John", "Elden"};

    Student s1 = createStudent(100, n1,'M');
    Student s2 = createStudent(101, n2,'F');
    Student s3 = createStudent(110, n3,'F');
    Student s4 = createStudent(111, n4,'M');

    StudentList paper[MAX];

    addStudent(paper, &count, &s1);
    addStudent(paper, &count, &s2);
    addStudent(paper, &count, &s3);
    addStudent(paper, &count, &s4);

    int f = countFemale(paper, &count);

    printf("Female Student Count: %d", f);

    getFemaleNames(paper, &count);

    return 0;
}

void displayName(Name n) {
    printf("%s, %s", n.lname, n.fname);
}

void displayStudent(Student s) {
    printf("ID: %d\n", s.stud_id);
    printf("NAME: ");
    displayName(s.stud_name);
    printf("\nSEX: %c", s.sex);
}

void changeName(Student *s, String lname) {
    strcpy(s->stud_name.lname, lname);
}

Name createName(String fname, String lname) {
    Name n;

    strcpy(n.fname, fname);
    strcpy(n.lname, lname);

    return n;
}

Student createStudent(int id, Name name, char sex) {
    Student s;

    s.stud_id = id;
    s.stud_name = name;
    s.sex = sex;

    return s;
}


void addStudent(StudentList list, int *count, Student *s)
{
    if(*count < MAX)
    {
        list[(*count)++] = *s;
    }
}

int countFemale(StudentList list, int *count)
{
    int fcount = 0;
    for(int i = 0; i < *count; ++i)
    {
        if(list[i].sex == 'F')
        {
            fcount++;
        }
    }
}

void getFemaleNames(StudentList list, int *count)
{
    for(int i = 0; i < *count; ++i)
    {
        if(list[i].sex == 'F')
        {
            printf("Name: %s, %s\n", list[i].stud_name.fname, list[i].stud_name.lname);
            printf("ID: %d\n", list[i].stud_id);
            printf("\n");
        }
    }
}
