#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int SIZE = 50;

int weight(float a, float b, float c){
    if (a <= c && b >= c) {
      return 0;
    } else {
      return 1;
    }
}
int age(int a, int b, int c){
    if (a <= c && b >= c) {
      return 0;
    } else {
      return 1;
    }
}
int income(float a, float b, float c){
    if (a <= c && b >= c) {
      return 0;
    } else {
      return 1;
    }
}
int name(char a[], char b[]){
 if (b[0] == '*') {return 0;}
  int i = strlen(a);
  int j = strlen(b);
  int t;

  for (int z = 0; z <= i - j; z++) {
    for (int x = z; x < z + j; x++) {
      t = 10;
      if (a[x] != b[x - z]) {
        t = 0;
        break;
    }
}
    if (t == 10) {break;}
}
    if (t == 10) {
      return 0;
  } else {
      return 1;
  }
}


int main(int argc, char const *argv[]) {

  struct inf {
    char student[30];
    int age;
    float weight;
    float income;
  };
  typedef struct inf info;
  info information[SIZE];

  struct k {char aria[100];};
  typedef struct k ki;
  ki records[SIZE];

    int i = 0;
    char arr[500], ch;

//read bigdata.txt
    FILE *p = fopen("data.txt", "r");

    if (p == NULL) {
        printf("Error. File cannot be found\n");
        return -1;
    } else {
        ch = fgetc(p);
        arr[i] = ch;
        while (ch != EOF) {
            i++;
            ch = fgetc(p);
            arr[i] = ch;
        }
        arr[i--] = '\0';

//putting each line of data into one string
        char *rr;
        int l = 0;
        const char u[3] = "\n";
        rr = strtok(arr, u);

        while (rr != NULL) {
            strcpy(records[l].aria, rr);
            l++;
            rr = strtok(NULL, u);
        }
    }

//putting the names together into one string
  int z = 0;
  char *pch;
  char space[2] = {" "};
  char *string[25];
  char nam_e[30];
  int n = 0;
  while (z < SIZE) {

    pch = strtok (records[z].aria," ");

    while (pch != NULL) {
      string[n] = pch;
        pch = strtok (NULL, " ");
        n++;
    }

    for (int j = 0; j < (n - 3); j++) {
        strcat(nam_e, string[j]);
        strcat(nam_e, space);
    }

//putting name, age, weight, income into a structure
    strcpy(information[z].student,nam_e);
    information[z].age = atof(string[n-3]);
    information[z].weight = atof(string[n-2]);
    information[z].income = atof(string[n-1]);
    z++; n = 0; nam_e[0] = '\0';}
  fclose(p);

  int from_age;
  int to_age;
  float from_weight;
  float to_weight;
  float from_income;
  float to_income;

  if (argc == 8) {
  if (argv[2][0] == '*') {from_age = 0;} else {from_age = atoi(argv[2]);}
  if (argv[3][0] == '*') {to_age = 999;} else {to_age = atoi(argv[3]);}
  if (argv[4][0] == '*') {from_weight = 0;} else {from_weight = atof(argv[4]);}
  if (argv[5][0] == '*') {to_weight = 999;} else {to_weight = atof(argv[5]);}
  if (argv[6][0] == '*') {from_income = 0;} else {from_income = atof(argv[6]);}
  if (argv[7][0] == '*') {to_income = 999;} else {to_income = atof(argv[7]);}

  for (z = 0; z < SIZE; z++) {
    int a = weight(from_weight, to_weight, information[z].weight);
    int b = age(from_age, to_age, information[z].age);
    int c = income(from_income, to_income, information[z].income);
    int d = name(information[z].student, argv[1]);
    if (a == 0 && b == 0 && c == 0 && d == 0) {
        printf("%s  %i  %.2f  %.2f\n", information[z].student, information[z].age, information[z].weight, information[z].income);}
    }
  }
  else {printf("not correct");}
  return 0;
}
