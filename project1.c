#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct emp {
  char name[30];
  int age;
  float weight;
  float income;
};
typedef struct emp empl;
const int SIZE = 4;


int weight(float a, float b, float c){
  for (int i = 0; i < SIZE; i++) {
    if (a <= c && b >= c) {
      return 0;
    } else {
      return 1;
    }
  }
}
int age(int a, int b, int c){
  for (int i = 0; i < SIZE; i++) {
    if (a <= c && b >= c) {
      return 0;
    } else {
      return 1;
    }
  }
}
int income(float a, float b, float c){
  for (int i = 0; i < SIZE; i++) {
    if (a <= c && b >= c) {
      return 0;
    } else {
      return 1;
    }
  }
}

int name(char a[], char b[]){

  int i = strlen(a);
  int j = strlen(b);
  // int i = 0;
  // int j = 0;
  // while (a[i] != '\0') {
  //   i++;
  // }
  // while (b[j] != '\0') {
  //   j++;
  // }
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
  empl records[SIZE];

  if (argc == 8) {
    int from_age = atoi(argv[2]);
    int to_age = atoi(argv[3]);
    float from_weight = atof(argv[4]);
    float to_weight = atof(argv[5]);
    float from_income = atof(argv[6]);
    float to_income = atof(argv[7]);

    printf("person 1: %s  %i  %i  %.2f  %.2f  %.2f  %.2f\n", argv[1], from_age, to_age, from_weight, to_weight, from_income, to_income);

  strcpy(records[0].name, "Le Thi Minh");
  records[0].age = 25;
  records[0].weight = 60.2;
  records[0].income = 30.6;

  strcpy(records[1].name, "Le Minh Thi");
  records[1].age = 55;
  records[1].weight = 70.8;
  records[1].income = 85.7;

  strcpy(records[2].name, "Tran Thi Thu");
  records[2].age = 33;
  records[2].weight = 55.6;
  records[2].income = 45.6;

  strcpy(records[3].name, "Tran Thu Thuy");
  records[3].age = 46;
  records[3].weight = 34.7;
  records[3].income = 98.5;

  for (int i = 0; i < SIZE; i++) {
    int a = weight(from_weight, to_weight, records[i].weight);
    int b = age(from_age, to_age, records[i].age);
    int c = income(from_income, to_income, records[i].income);
    int d = name(records[i].name, argv[1]);
    if (a == 0 && b == 0 && c == 0 && d == 0) {printf("%s  %i  %.2f  %.2f\n", records[i].name, records[i].age, records[i].weight, records[i].income);}
  }
  }
  else {printf("not correct");}
  return 0;
}
