#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "student.h"

int main(int argc, char **argv)
{
	if (argc != 2){
		printf("Wrong number of parameters!\n");
		printf("Example: main students.dat\n");
		printf("Program terminated...\n");
		return 0;
	}
    

    list studlist = list_create();
    load(argv[1],studlist);

    char choice;
    char ans,ans1;
    student tmp;
 
    int run = 1;
    while( run ) {
        printMenu();
        
        do{
            printf("choice: ");
            scanf("%s", &choice);
            printf("\n"); 
            if (choice < '1' || choice > '8'){
                printf("wrong input. try again...\n");
            }
        }while( choice < '1' || choice > '8' );

        switch( choice ) {
            case '1': // save list
                printf("are you sure you want to save the list? [y/n]\n");
                scanf("%s", &ans);
                if (ans == 'y'){
                    save(argv[1],studlist); 
                }
                break;

            case '2':
                printf("give student's id: ");
                scanf("%d", &tmp.id);
                print(tmp);
                break;

            case '3': // print list
                printstudents(studlist);
                break;

            case '4': // add student
                strcpy(tmp.name, "");
                tmp.id = 0;
                printf("give students name:\n");
                scanf("%s", tmp.name);
                printf("give student id:\n");
                scanf("%d", &tmp.id);
                addStudent(tmp, studlist);
                printf("students added succesfully :)\n");
                save(argv[1], studlist);
                break;

            case '5': // find student
                printf("give a student's id\n");
                scanf("%d", &tmp.id);
                if (findStudent(tmp.id,studlist) != NULL){
                    findStudent(tmp.id,studlist);
                    printf("the student with id=%d is:%s\n",tmp.id, findStudent(tmp.id,studlist)->data.name);
                }
                else 
                    printf("student not fount :(\n");
                break;

            case '6': // delete student
                printf("give student id you want to exterminate\n");
                scanf("%d", &tmp.id);
                deleteStudent(tmp.id,studlist);
                if (deleteStudent(tmp.id,studlist) == 0){
                    printf("student could not be found\n");
                }
                else 
                    printf("student succesfully removed from the equation\n");
                break;
            
            case '7': // update student
                printf("give the id of the student you want to change:\n");
                scanf("%d", &tmp.id);
                updateStudent(tmp,studlist); //its either that or tmp.id ( if i do that i will have to change the updatestudent)
                break;

            case '8': // quit
                printf("you are about to exit the progrmam. Do you want to save any chances? [y/n]\n");
                scanf("%s", &ans1);
                if ( ans1 == 'y'){
                    save(argv[1], studlist);
                    run=0;
                    break;
                }
                else {
                    break;
                }

        };//end of switch

    }//end of while
    return 0;
}