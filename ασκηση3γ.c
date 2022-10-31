#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Δημιουργώ ένα struct για τη διεύθυνση ώστε να περιλαμβάνει οδό, αριθμό και πόλη-περιοχή
struct address{
    char street[20];
    char number[10];
    char area[20];
};

//Δημιουργώ ένα struct φοιτητή με όλα τα στοιχεία που ζητούνται
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
    //Φτιάχνω 2 πίνακες δεικτών τύπου struct student
    struct student *pinakas, *arr;
    int i,n;
    int cnt=0;
    char course[40];
    printf("Enter number of students:");
    scanf("%d", &n);
    //Ζητάω από το χρήστη το μάθημα για το οποίο θέλει να έχει πρόσβαση
    //στους φοιτητές που το επέλεξαν
    printf("Enter the selcted course: ");
    scanf("%s", course)
    //Δεσμεύω δυναμικά μνήμη για τους πίνακες όσος είναι και ο αριθμός
    //των εγγραφών των φοιτητών που εισήγαγε ο χρήστης
    pinakas=(struct student*)malloc(sizeof(struct student)*n);
    arr=(struct student*)malloc(sizeof(struct student)*n);
    //Ελέγχω αν η δέσμευση μνήμης ήταν επιτυχής
    if (!pinakas){
                   printf("no memory");
               exit(0);
    }
    if (!arr){
                   printf("no memory");
               exit(0);
    }
//Επαναλαμβάνω την είσοδο των στοιχείων των φοιτητών για όσους φοιτητές
//εισήγαγε ο χρήστης
    for(i=0; i<n; i++){
        printf("Enter the name of the %d student: ", i+1);
        scanf("%s", pinakas[i].name);
        printf("Enter the surname of the %d student: ", i+1);
        scanf("%s", pinakas[i].surname);
        printf("Enter the father's name of the %d student: ", i+1);
        scanf("%s", pinakas[i].fname);
        printf("Enter the AM of the %d student: ", i+1);
        scanf("%s", pinakas[i].am);
        printf("Enter the address of the %d student: ", i+1);
        scanf("%s %s %s", pinakas[i].data.street, pinakas[i].data.number, pinakas[i].data.area);
        printf("Enter the home phone number and mobile phone number of the %d student: ", i+1);
        scanf("%s %s", pinakas[i].hmphone, pinakas[i].mbphone);
        printf("Enter the selected course for the %d student: ", i+1);
        scanf("%s",pinakas[i].course);
        //Ελέγχω αν το επιλεγμένο μάθημα είναι αυτό που εισήγαγε ο χρήστης
        //και αποθηκεύω τους φοιτητές με το συγκεκριμένο μάθημα σε έναν
        //ξεχωριστώ πίνακα
        if (strcmp(pinakas[i].course, course) == 0){
                arr[i]=pinakas[i];
                cnt++;
            }
    }
        //Τυπώνω τους φοιτητές με το επιλεγμένο μάθημα που έδωσε ο χρήστης
        for (i=0; i<cnt; i++){
            printf("Student %d\nName: %s\nSurname: %s\nFather's name: %s\nAM: %s\nAddress: %s %s %s \nPhone numbers: %s %s \n", i+1, arr[i].name, arr[i].surname, arr[i].fname, arr[i].am, arr[i].data.street, arr[i].data.number, arr[i].data.area, arr[i].hmphone, arr[i].mbphone);
        }
}