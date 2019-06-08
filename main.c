#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "student.h"

#define y 1
#define n 0

int main()
{
    int run = 1;
    char choice, filename;
    list_create();
    int ans;
    student tmp;
    list studlist;
    while( run ) {
        print_menu();
    do {
        scanf("%c", &choice);
    }

    while( choice < '1' || choice > '4' );

    switch( choice ) {
        case '1':
            printf("are you sure you want to load an exising list? [y/n]\n");
            scanf("%s", &filename);
            if (ans == 1)
                load(filename,studlist);
            break;

        case '2':
            printf("are you sure you want to save the list? [y/n]\n");
            scanf("%c", ans);
            if (ans == 1)
                save(filename,studlist); 
            break;

        case '3':
            print_students(studlist);
            break;

        case '4':
            printf("give students name:\n");
            scanf("%s", &tmp.name);
            printf("give student id:\n");
            scanf("%d", &tmp.id);
            addStudent(tmp, studlist);
            printf("students added succesfully :)\n");
            break;

        case '5':
            printf("give a student's id\n");
            scanf("%d", &tmp.id);
            if (tmp.id != NULL){
                findStudent(tmp.id,studlist);
            }
            else 
                printf("student not fount :(\n");
            break;

        case '6':
            printf("give student id you want to exterminate\n");
            scanf("%d", &tmp.id);
            deleteStudent(tmp.id,studlist);
            if (deleteStudent(tmp.id,studlist) == 0){
                printf("student could not be found\n");
            }
            else 
                printf("student succesfully removed from the equation\n");
            break;
        
        case '7':
            printf("give the id of the student you want to change:\n");
            scanf("%d", tmp.id);
            updateStudent(tmp.id,studlist);
            break;

        case '8':
            printf("you are about to exit the progrmam make sure you saved any chances...[y/n]\n");
            scanf("%c", &ans);
            if ( ans == 0)
                break;
            else {
                run=0;
                break;
            }
        }
    }
}