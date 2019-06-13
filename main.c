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
    char ans;
    student tmp;
 
    int run = 1;
    while( run ) {
        printMenu();

        do {
            printf("choice: ");
            scanf("%c", &choice);
            printf("\n");
        } while( choice < '1' || choice > '7' );

        switch( choice ) {
            case '1':
                printf("are you sure you want to save the list? [y/n]\n");
                scanf("%s", &ans);
                if (ans == 'y')
                    save(argv[1],studlist); 
                break;

            case '2':
                printstudents(studlist);
                break;

            case '3':
                strcpy(tmp.name, "");
                tmp.id = 0;
                printf("give students name:\n");
                scanf("%s", tmp.name);
                printf("give student id:\n");
                scanf("%d", &tmp.id);
                addStudent(tmp, studlist);
                printf("students added succesfully :)\n");
                break;

            case '4':
                printf("give a student's id\n");
                scanf("%d", &tmp.id);
                if (findStudent(tmp.id,studlist) != NULL){
                    printf("%s\n", tmp.name);
                }
                else 
                    printf("student not fount :(\n");
                break;

            case '5':
                printf("give student id you want to exterminate\n");
                scanf("%d", &tmp.id);
                deleteStudent(tmp.id,studlist);
                if (deleteStudent(tmp.id,studlist) == 0){
                    printf("student could not be found\n");
                }
                else 
                    printf("student succesfully removed from the equation\n");
                break;
            
            case '6':
                printf("give the id of the student you want to change:\n");
                scanf("%d", &tmp.id);
                updateStudent(tmp,studlist); //its either that or tmp.id ( if i do that i will have to change the updatestudent)
                break;

            case '7':
                printf("you are about to exit the progrmam. Do you want to save any chances? [y/n]\n");
                scanf("%s", &ans);
                if ( ans == 'n'){
                    save(argv[1], studlist);
                    break;
                }
                else {
                    run=0;
                    break;
                }
            
            default:
                while (choice < '1' || choice > '7'){
                    printf("wrong input. try again:\n");
                    printf("choice: ");
                    scanf("%c", &choice);
                    printf("\n");
                }
            //end of case
            }
        //end of switch
        }
    return 0;
}