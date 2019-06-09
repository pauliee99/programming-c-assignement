#include <stdio.h>

#define MAXSTRING 80

typedef struct{
   char name[MAXSTRING];
   int id;
}student;

typedef struct nodeR* node;
struct nodeR {
    student data;
    node next;
};

typedef struct listR* list;
struct listR {
    node head, tail;
    int size;
};


void printMenu(); //τυπώνει το μενού

void print(student st);

void printstudents(list l);

student* load(char *filename, list l); //ανάκτηση λίστας φοιτητών από αρχείο

void save(char *filename, list l); //αποθήκευση λίστας φοιτητών σε αρχείο

int addStudent(student st, list l); //προσθήκη νέου student

student* findStudent(int id, list l); //αναζήτηση του student από το array με βάση το id 

int deleteStudent(int pid, list l); //διαγραφή με βάση το st.id

int updateStudent(student st, list l); //ανανέωση με βάση το st.id

list list_create(); // dimiourgia neas listas

int list_isempty( list l ); // checks if list is empty

void list_push_back( list l, int id, char *name);