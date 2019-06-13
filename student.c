#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "student.h"

void printMenu()
{
    printf("\x1B[37m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\x1B[0m");
    printf("\n\x1B[31mChoose from 1 to 7:\n");

    printf("\x1B[36m");
    printf("1. Αποθήκευση λίστας φοιτητών σε αρχείο\n");
    printf("2. Αναπαράσταση λίστας\n");
    printf("3. Προσθήκη νέου student\n");
    printf("4. Αναζήτηση του student από το array με βάση το id\n");
    printf("5. Διαγραφή με βάση το id\n");
    printf("6. Ανανέωση με βάση το id\n");
    printf("7. Quit\n");
    printf("\x1B[0m");
    printf("\x1B[37m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\x1B[0m");
}

void print(student st)
{
    //printf("the student is:\n");
    printf("%d\t", st.id);
    printf("%s\n", st.name);
    
}

void printstudents(list l)
{
    node currnode = l->head;
    printf("total students are:\n");
    
    while (currnode != NULL){
        print(currnode->data);
        currnode = currnode->next;
    }
}

int addStudent(student st, list l)
{
    if (findStudent(st.id,l) != NULL){
        return 0;
    }
    else {
        list_push_back(l, st.id, st.name);
        return 0;
    }
}

node findStudent(int id, list l)
{
    node currnode = l->head;
    while (currnode != NULL){
        if (currnode->data.id == id){
            return currnode;
        }
        currnode = currnode->next;
    }
    return NULL;
}

student* load(char *filename, list l)
{
    FILE* filest = fopen(filename, "r");
    if (filest  == NULL){
        return NULL;
    }

    fseek (filest, 0, SEEK_END);
    int length = ftell (filest);
    fseek (filest, 0, SEEK_SET);

    int plithos = length / sizeof(student);
    student tmp;
    //node currnode = l->head;
    //list_push_back(l, tmp.id, tmp.name);

    for (int i=0; i<plithos; i++){
        fread(&tmp, sizeof(student), 1, filest);
        //tmp.id = currnode->data.id;
        //strcpy(currnode->data.name, tmp.name);
        //currnode = currnode->next;
        addStudent(tmp, l);
    }
    fclose(filest);
    return 0;
}

void save(char *filename, list l) 
{
    FILE* filest = fopen(filename, "w");

    if (filest == NULL){
        printf("failed to save any changes");
        exit(1);
    }

    node currnode = l->head;
    student tmp;
    
    while (currnode != NULL){
        tmp.id = currnode->data.id;
        strcpy(tmp.name, currnode->data.name);
        fwrite(&tmp, sizeof(student), 1, filest);
        currnode = currnode->next;
    }
    fclose(filest);
}

int deleteStudent(int pid, list l){

    if (findStudent(pid, l) == NULL){
        printf("student not found\n");
        return 0;
    }
    else {
        while (l->size != 0){
		    node secondNode = l->head->next;
		    free(l->head);
		    l->head = secondNode;
		    l->size--;
	    }
	    free(l);
    }
}

int updateStudent(student st, list l)
{
    node currnode;
    currnode = findStudent(st.id,l);

    int i;
    if (currnode == NULL){
        printf("the student id cound not be found...");
        return 0;
    }
    else {
        printf("give new name for the student %d:", st.id);
        scanf("%s", st.name);
    }
    strcpy(currnode->data.name, st.name);
}

list list_create()
{
    list l = malloc(sizeof(struct listR));
    assert(l);
    l->head = NULL;
    l->tail = NULL;
    l->size = 0;
    return l;
}

int list_isempty( list l )
{
    if (l->size == 0){
        return 1;
    }
    else 
        return 0;
}

void list_push_back( list l, int id, char *name){
    node newNode = (node)malloc(sizeof(struct nodeR));
	node tmp;
    strcpy(newNode->data.name,name);
    newNode->data.id =id;
    newNode->next = NULL;

    if (list_isempty(l)){
		l->head = newNode;
		l->tail = newNode;
	}
	else {
        l->tail->next = newNode;
		l->tail = newNode;
        /*
        tmp = l->tail;
        l->tail = currnode;
		l->tail->next = NULL;
        tmp->next = currnode;*/
    }

    l->size++;	
}
/*
void list_push_back( list l, char *name )
{
	node currnode = malloc(sizeof(struct nodeR));
	assert(currnode);
	strcpy(currnode->name, name);
	currnode->next = NULL;

	if (list_isempty(l)){
		l->head = currnode;
		l->tail = currnode;
	}
	else {
		l->tail->next = currnode;
		l->tail = currnode;
	}

	l->size++;
}*/