#include <stdio.h>
#include <stdlib.h>

//Δημιουργώ ένα struct για τη διεύθυνση ώστε να περιλαμβάνει οδό, αριθμό και πόλη-περιοχή
struct address
{
  char street[20];
  char number[10];
  char area[20];
};
//Δημιουργώ ένα struct για τον φοιτητή με όλα τα στοιχεία που ζητούνται
struct student
{
  char am[10];
  char name[20];
  char surname[20];
  char fname[20];
  struct address data;
  char hmphone[15];
  char mbphone[15];
  char course[40];
};

int main ()
{
//Φτιάχνω έναν φοιτητή d και έναν δείκτη που δείχνει στο στιγμιότυπο της δομής d
  struct student d;
  struct student *ptd;
  ptd = &d;
//Ζητάω τα στοιχεία του φοιτητή από το χρήστη και τα αποθηκεύω με τη βοήθεια του δείκτη
// με το ptd-> έχω πρόσβαση στα μέλη της δομής
  printf ("Enter student's name: \n");
  scanf ("%s", ptd->name);
  printf ("Enter student's surname: \n");
  scanf ("%s", ptd->surname);
  printf("Enter student's father's name: \n");
  scanf("%s", ptd->fname);
  printf("Enter student's AM: \n");
  scanf("%s", ptd->am);
  printf("Enter student's selected course: \n");
  scanf("%s", ptd->course);
  printf("Enter student's address: \n");
  scanf("%s %s %s", ptd->data.street, ptd->data.number, ptd->data.area);
  printf("Enter student's home phone number and mobile number: \n");
  scanf("%s %s", ptd->hmphone, ptd->mbphone);
//Τυπώνω όλα τα στοιχεία του φοιτητή
  printf("Student\n Name: %s\n Surname: %s\n Father's name: %s\n AM: %s\n Selected course: %s\n Address: %s %s %s \n Phone numbers: %s %s \n", ptd->name, ptd->surname, ptd->fname, ptd->am, ptd->course, ptd->data.street, ptd->data.number, ptd->data.area, ptd->hmphone, ptd->mbphone);
}