#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "student.h"

void printMenu()
{
    printf("Choose from 1 to 7:\n");

    printf("1. Ανάκτηση λίστας φοιτητών από αρχείο\n");
    printf("2. Αποθήκευση λίστας φοιτητών σε αρχείο\n");
    printf("3. Αναπαράσταση λίστας\n");
    printf("4. Προσθήκη νέου student\n");
    printf("5. Αναζήτηση του student από το array με βάση το id\n");
    printf("6. Διαγραφή με βάση το id\n");
    printf("7. Ανανέωση με βάση το id\n");
    printf("8. Quit\n");
}

void print(student st)
{
    printf("the student is:\n");
    printf("%d", st.id);
    printf("%s", st.name);
    
}

void printstudents(list l)
{
    node currnode = l->head;
    
    while (currnode != NULL){
        print(currnode->data);
        currnode = currnode->next;
    }
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

    int fsize, plithos, i;
    student tmp;
    node currnode = l->head;
    list_push_back(l, tmp.name, tmp.id);

    for (int i=0; i<=l->size; i++){
        tmp.id = currnode->data.id;
        strcpy(currnode->data.name, tmp.name);
        currnode = currnode->next;
        fread(&tmp, sizeof(student), 1, filest);
    }
    fclose(filest);
    return 0;
}

void save(char *filename, list l) 
{
    FILE* filest = fopen(filename, "w");
    node currnode = l->head;
    student tmp;
    
    while (currnode != NULL){
        tmp.id = currnode->data.id;
        strcpy(currnode->data.name, tmp.name);
        currnode = currnode->next;
        fwrite(&tmp, sizeof(student), 1, filest);
    }
    fclose(filest);
}

int addStudent(student st, list l)
{
    if (findStudent(st.id,l) != NULL){
        return 0;
    }else{
    list_push_back(l, st.id, st.name);
        return 0;
    }
}

student* findStudent(int id, list l)
{
    node currnode = l->head;
    while (currnode != NULL){
        if (currnode->data.id == id){
            return currnode;
        }
    }
    return -1;
}

int deleteStudent(int pid, list l){
    //Doulebei mono gia ton proto foititi
    int index = findStudent(pid, l);
    if (index == -1){
        printf("404 not found\n");
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
    int i;
    if (findStudent(st.id,l)== -1){
        printf("the student id cound not be found...");
        return 0;
    }
    else {
        printf("give new name for the student %d:", st.id);
        scanf("%s", st.name);
    }
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

void list_push_back( list l, char *name , int id){
    node currnode = l->head;
    assert(currnode);
	strcpy(currnode->data.name, currnode->next->data.name); //help

    while (currnode != l->tail){
        if (list_isempty(l)){
		    l->head = currnode;
		    l->tail = currnode;
	    }
	    else {
		    l->tail->next = currnode;
		    l->tail = currnode;
	    }
    }
}