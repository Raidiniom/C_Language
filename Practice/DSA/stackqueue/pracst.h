#ifndef PRACST_H
#define PRACST_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

typedef char String[30];

typedef struct {
    String fname;
    String lname;
    int age;
    char sex;
} Person;

typedef struct node{
    Person data;
    struct node *link;
} NodeType, *NodePtr, *Stack;

Person createPerson(String fname, String lname, int age, char sex) {
  Person start;

  strcpy(start.fname, fname);
  strcpy(start.lname, lname);
  start.age = age;
  start.sex = sex;

  return start;
}

void initStack(Stack *s) {
  *s =(NodePtr) malloc(sizeof(NodeType));

  (*s)->link = NULL;

}
bool isEmpty(Stack s) {
  return s->link == NULL;
}

bool push(Stack *s, Person p) {
  Stack start =(NodePtr) malloc(sizeof(NodeType));

  if (start ==  NULL)
  {
    return false;
  }
  

  start->data = p;
  start->link = *s;
  *s = start;
  
  return true;
}
bool pop(Stack *s) {
  if (!isEmpty(*s))
  {
    Stack hold;

    hold = *s;
    *s = (*s)->link;

    free(hold);

    return true;
  }
  
  return false;
}
Person peek(Stack s) {
  return s->data;
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack using push, pop, and peek functions.*/
bool insertSorted1(Stack *s, Person p) {
  Stack temp;
  initStack(&temp);

  while ((*s) != NULL && strcmp((*s)->data.lname, p.lname) < 0)
  {
    push(&temp, peek(*s));
    pop(s);
  }

  push(s, p);

  while (temp != NULL)
  {
    push(s, peek(temp));
    pop(&temp);
  }
  
  return true;
}
void displayStack(Stack s) {
  if (!isEmpty(s))
  {
    printf("Person List:\n");
    while (s->link != NULL)
    {
      printf("%.30s, %.30s %d %c\n", s->data.fname, s->data.lname, s->data.age, s->data.sex);
      s = s->link;
    }
    printf("\n");
    
  }
  
}

/*Insert sorted base on lastname. Rember to use the property 
  of the stack but without using push, pop, and peek functions.*/
bool insertSorted2(Stack *s, Person p);

/*Sort the values based on name. Use flag for ascending 
  or descending. */
void sortStack(Stack *s, bool flag);

#endif