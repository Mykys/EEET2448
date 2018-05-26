#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a constant integer for array size
const int SIZE = 1;

// Check if weight input is within given bounds
int weight(float lower_bound, float higher_bound, float weight) {
    if (lower_bound <= weight && higher_bound >= weight) {
      return 1;
    }
    return 0;
}

// Check if age input is within given bounds
int age(int lower_bound, int higher_bound, int age) {
    if (lower_bound <= age && higher_bound >= age) {
      return 1;
    }
    return 0;
}

// Check if income input is within given bounds
int income(float lower_bound, float higher_bound, float income) {
    if (lower_bound <= income && higher_bound >= income) {
      return 1;
    }
    return 0;
}

// Check if name input contains in full name
int name(char full_name[], char input_name[]) {

    if (input_name[0] == '*') {
        return 1;
    }

    int full_length = strlen(full_name);
    int input_length = strlen(input_name);
    int t;

    for (int i = 0; i <= full_length - input_length; i++) {
        for (int j = i; j < i + input_length; j++) {
            t = 10;
            if (full_name[j] != input_name[j - i]) {
                t = 0;
                break;
            }
        }
        if (t == 10) {
            break;
        }
    }
    if (t == 10) {
      return 1;
    }
  return 0;
}

// Define a person structure
struct person {
    char name[30];
    int age;
    float weight;
    float income;
};

// Define structure to store each line from data file
struct file_line {
    char line[100];
};

// Define a new data types
typedef struct person person;
typedef struct file_line file_line;


void insert_data(file_line lines[], person list[]) {

    char *line_part, *name_part[25], full_name[30];
    int i = 0, n = 0;

    // Split line into individual parts
    while (i < SIZE) {
        line_part = strtok(lines[i].line," ");

        while (line_part != NULL) {
            name_part[n] = line_part;
            line_part = strtok (NULL, " ");
            n++;
        }

        // Combine the name into one string
        for (int j = 0; j < (n - 3); j++) {
            strcat(full_name, name_part[j]);
            strcat(full_name, " ");
        }

        // Populate data into person structure list
        strcpy(list[i].name, full_name);
        list[i].age = atoi(name_part[n-3]);
        list[i].weight = atof(name_part[n-2]);
        list[i].income = atof(name_part[n-1]);
        i++;

        // Reset variables
        n = 0;
        full_name[0] = '\0';
    }
}

// Search for people who fulfills the input requirements
void search(int argc, char *argv[], person list[]) {

    int from_age, to_age;
    float from_weight, to_weight, from_income, to_income;

    if (argc == 8) {
        from_age = (argv[2][0] == '*') ? 0 : atoi(argv[2]); // ternary operator
        to_age = (argv[3][0] == '*') ? 999 : atoi(argv[3]);

        from_weight = (argv[4][0] == '*') ? 0 : atof(argv[4]);
        to_weight = (argv[5][0] == '*') ? 999 : atof(argv[5]);

        from_income = (argv[6][0] == '*') ? 0 : atof(argv[6]);
        to_income = (argv[7][0] == '*') ? 999 : atof(argv[7]);

        for (int i = 0; i < SIZE; i++) {
            int person_name = name(list[i].name, argv[1]);
            int person_age = age(from_age, to_age, list[i].age);
            int person_weight = weight(from_weight, to_weight, list[i].weight);
            int person_income = income(from_income, to_income, list[i].income);

            if (person_name && person_age && person_weight && person_income) {
                printf("%s  %i  %.2f  %.2f\n", list[i].name, list[i].age, list[i].weight, list[i].income);
            }
        }
    } else {
        printf("Incorrect number of arguments");
    }
}

int main(int argc, char const *argv[]) {

  int i = 0;
  char arr[50], ch;

    // Declare arrays
    person person_list[SIZE];
    file_line file_line_list[SIZE];

    FILE *p = fopen("smalldata.txt", "r");
    if (p == NULL) {
        printf("Error. File cannot be found\n");
        return -1;
    } else {
      ch = fgetc(p);
      arr[i] = ch;
      while (ch != EOF) {

        while (ch != '\n') {
          i++;
          ch = fgetc(p);
          arr[i] = ch;
        }
        i++;
        arr[i] = '\0';

        strcpy(file_line_list[0].line, arr);

        insert_data(file_line_list, person_list);

        search(argc, argv, person_list);

        i = 0;
        ch = fgetc(p);
        //printf("Hello Vinh");
        //printf("%c", ch);
        arr[i] = ch;
      }

    }
    return 0;
}
