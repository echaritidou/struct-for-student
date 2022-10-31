#include <stdio.h>
#include <stdlib.h>

//Δημιουργώ ένα struct για τη διεύθυνση ώστε να περιλαμβάνει οδό, αριθμό και πόλη-περιοχή
struct address
{
  char street[20];
  char number[10];
  char area[20];
};

//Δημιουργώ ένα struct για το φοιτητή με όλα τα στοιχεία που ζητούνται
struct student{
    char am[10];
    char name[20];
    char surname[20];
    char fname[20];
    struct address data;
    char hmphone[15];
    char mbphone[15];
    char course[40];
};

int main()
{
    //Δημιουργώ έναν πίνακα δεικτών
    struct student *pinakas;
    int i,n;
    printf("Enter number of students:");
    scanf("%d", &n);
    //Δεσμεύω δυναμικά μνήμη για τον πίνακα τόση όση θα χρειαστεί για n εγγραφές
    pinakas=(struct student*)malloc(sizeof(struct student)*n);
    //Κάνω έλεγχο αν η δέσμευση μνήμης ήταν επιτυχής
    if (!pinakas){
                   printf("no memory");
                   exit(0);
    }
    //Επαναλαμβάνω την είσοδο στοιχείων από το χρήστη για όλους τους φοιτητές και τα αποθηκεύω στον πίνακα
    for(i=0; i<n; i++){
                   printf("Enter the name of the %d student:", i+1);
        scanf("%s", pinakas[i].name);
        printf("Enter the surname of the %d student:", i+1);
        scanf("%s", pinakas[i].surname);
        printf("Enter the father's name of the %d student :", i+1);
        scanf("%s", pinakas[i].fname);
        printf("Enter the AM of the %d student:", i+1);
        scanf("%s", pinakas[i].am);
        printf("Enter the selected course of the %d student:", i+1);
        scanf("%s", pinakas[i].course);
        printf("Enter the address of the %d student:", i+1);
        scanf("%s %s %s", pinakas[i].data.street, pinakas[i].data.number, pinakas[i].data.area);
        printf("Enter the home phone number and mobile phone number of the %d student:", i+1);
        scanf("%s %s", pinakas[i].hmphone, pinakas[i].mbphone);             
    }
    //Τυπώνω όλες τις εγγραφές των φοιτητών
    printf("\n\n STUDENTS\n************************************\n");
    for (i=0; i<n; i++){
                   printf("\nStudent %d\n Name: %s\n Surname: %s\n Father's name: %s\n AM: %s\n Selected course: %s\n Address: %s %s %s\n Phone numbers: %s %s \n ", i+1, pinakas[i].name, pinakas[i].surname, pinakas[i].fname, pinakas[i].am, pinakas[i].course, pinakas[i].data.street, pinakas[i].data.number, pinakas[i].data.area, pinakas[i].hmphone, pinakas[i].mbphone);
    }
}