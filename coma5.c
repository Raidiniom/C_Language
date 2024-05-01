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



Name createName(String fname, String lname);
Student createStudent(int id, Name name, char sex);
void addStudent(StudentList list, int *count, Student *s);
void displayStud (Student s);
void displayList (StudentList list, int * count);
int getFemale (StudentList list, int*count);
void displayFemale (StudentList list, int*count);

int main() {
    int count = 0;
    Name name1 = {"Yousif", "Ceballos"};
    Student stud1 = createStudent (200, name1, 'M');

    Name name2 = {"Mark", "Gerozaga"};
    Student stud2 = createStudent (201, name2, 'M');

    Name name3 = {"Princess", "Alivine"};
    Student stud3 = createStudent (202, name3, 'F');

    Name name4 = {"Summi", "Derama"};
    Student stud4 = createStudent (203, name4, 'F');


    StudentList list[MAX];
    addStudent (list, &count, &stud1);
    addStudent (list, &count, &stud2);
    addStudent (list, &count, &stud3);
    addStudent (list, &count, &stud4);
    displayList(list, &count);

    int female = getFemale(list, &count);
   if (female == 1) {
        printf("There is %d female student\n\n", female);
   } else {
        printf("There are %d female students\n\n", female);
   }
    displayFemale (list, &count);

    return 0;
}


Name createName(String fname, String lname) {
    Name newName;

    strcpy(newName.fname, fname);
    strcpy(newName.lname, lname);

    return newName;
	}
Student createStudent(int id, Name name, char sex) {
    Student newStud;
    newStud.stud_id = id;
    newStud.stud_name = name;
    newStud.sex = sex;

    return newStud;
}

void addStudent(StudentList list, int *count, Student *s) {
     if (*count < MAX) {
             list[(*count)++] = *s;
     }
}
void displayStud (Student s) {
    printf("ID: %d", s.stud_id);
    printf("\nName: %s, %s\n", s.stud_name.lname, s.stud_name.fname);
    printf("Sex: %c\n", s.sex);
}

void displayList (StudentList list, int * count) {
    for (int i = 0; i < *count; ++i) {
        printf("Student No. %d\n", i + 1);
        printf("ID: %d\n", list[i].stud_id);
        printf("Name: %s, %s\n", list[i].stud_name.lname, list[i].stud_name.fname);
        printf("Sex: %c\n", list[i].sex);
        printf("\n\n");
    }
}

int getFemale (StudentList list, int*count) {
    int countFem = 0;
    for (int i = 0; i < *count; ++i) {
        if (list[i].sex == 'F') {
            countFem++;
        }
    }
    return countFem;
}

void displayFemale (StudentList list, int*count) {
    for (int i = 0; i < *count; ++i) {
        if (list[i].sex == 'F') {
             printf("Student No. %d\n", i + 1);
            printf("ID: %d\n", list[i].stud_id);
            printf("Name: %s, %s\n", list[i].stud_name.lname, list[i].stud_name.fname);
            printf("Sex: %c\n", list[i].sex);
            printf("\n\n");
        }
    }
}
