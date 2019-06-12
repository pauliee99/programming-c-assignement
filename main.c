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
            scanf("%c", &choice);
        } while( choice < '1' || choice > '8' );

        switch( choice ) {
            case '1':
                printf("are you sure you want to load an exising list? [y/n]\n");
                scanf("%s", &ans);
                if (ans == 'y')
                    load(argv[1],studlist);

                break;

            case '2':
                printf("are you sure you want to save the list? [y/n]\n");
                scanf("%s", &ans);
                if (ans == 'y')
                    save(argv[1],studlist); 
                break;

            case '3':
                printstudents(studlist);
                break;

            case '4':
                printf("give students name:\n");
                scanf("%s", tmp.name);
                printf("give student id:\n");
                scanf("%d", &tmp.id);
                addStudent(tmp, studlist);
                printf("students added succesfully :)\n");
                break;

            case '5':
                printf("give a student's id\n");
                scanf("%d", &tmp.id);
                if (findStudent(tmp.id,studlist) != NULL){
                    printf("%s", tmp.name);
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
                scanf("%d", &tmp.id);
                updateStudent(tmp,studlist); //its either that or tmp.id ( if i do that i will have to change the updatestudent)
                break;

            case '8':
                printf("you are about to exit the progrmam make sure you saved any chances...[y/n]\n");
                scanf("%s", &ans);
                if ( ans == 'n')
                    break;
                else {
                    run=0;
                    break;
                }
            }
        }
}