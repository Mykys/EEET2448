#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant integer for array size
const int SIZE = 6;

// lower_bound, higher_bound, user_input
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

int name(char a[], char b[]) {
 if (b[0] == '*') {
   return 0;
 }

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

    // Define a person structure
    struct person {
        char name[30];
        int age;
        float weight;
        float income;
    };

    // Define a structure named file_part to store
    // each line from the data file
    struct file_part {
        char line[100];
    };

    // Define a new data type: person
    typedef struct person person;
    typedef struct file_part file_part;

    // Declare an array of person named list
    person person_list[SIZE];
    file_part file_part_list[SIZE];

    // Declare variables for reading data
    int i = 0;
    char arr[500], ch;

    // Read from smalldata.txt
    FILE *p = fopen("smalldata.txt", "r");

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
    }

    // Split each line from the file
    char *line;
    int j = 0;
    line = strtok(arr, "\n");

    while (line != NULL) {
        strcpy(file_part_list[j].line, line);
        j++;
        line = strtok(NULL, "\n");
    }

    // Combine the name into one string
    int k = 0, n = 0;
    char *line_part, *name_part[25];
    char full_name[50];

    while (k < SIZE) {
        line_part = strtok (file_part_list[i].line," ");

        while (line_part != NULL) {
            name_part[n] = line_part;
            line_part = strtok (NULL, " ");
            n++;
        }

        for (int j = 0; j < (n - 3); j++) {
            strcat(full_name, name_part[j]);
            strcat(full_name, " ");
        }

        // Create a person structure
        strcpy(person_list[k].name, full_name);
        person_list[k].age = atoi(name_part[n-3]);
        person_list[k].weight = atof(name_part[n-2]);
        person_list[k].income = atof(name_part[n-1]);
        k++;

        // Reset variables
        n = 0;
        full_name[0] = '\0';
    }

    fclose(p);

    int from_age, to_age;
    float from_weight, to_weight, from_income, to_income;

    if (argc == 8) {

        if (argv[2][0] == '*') {
            from_age = 0;
        } else {
            from_age = atoi(argv[2]);
        }

        if (argv[3][0] == '*') {
            to_age = 999;
        } else {
            to_age = atoi(argv[3]);
        }

        if (argv[4][0] == '*') {
            from_weight = 0;
        } else {
            from_weight = atof(argv[4]);
        }

        if (argv[5][0] == '*') {
            to_weight = 999;
        } else {
            to_weight = atof(argv[5]);
        }

        if (argv[6][0] == '*') {
            from_income = 0;
        } else {
            from_income = atof(argv[6]);
        }

        if (argv[7][0] == '*') {
            to_income = 999;
        } else {
            to_income = atof(argv[7]);
    }

    for (i = 0; i < SIZE; i++) {
        int pname = name(person_list[i].name, argv[1]);
        int page = age(from_age, to_age, person_list[i].age);
        int pweight = weight(from_weight, to_weight, person_list[i].weight);
        int pincome = income(from_income, to_income, person_list[i].income);


      if (pname == 0 && page == 0 && pweight == 0 && pincome == 0) {
          printf("%s  %i  %.2f  %.2f\n", person_list[i].name, person_list[i].age, person_list[i].weight, person_list[i].income);
      }
  }
}
    else {
        printf("Incorrect number of arguments");
    }




    return 0;
}
