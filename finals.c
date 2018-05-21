
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Struct
struct inf {
  char nam_e [30];
  int age;
  float weight;
  float income;
};
typedef struct inf inf;

//
int main(int argc, char const *argv[]) {

    int row = 0, col =0, n = 0, count_line = 0;
    char arr[10][100], ch;
    char *pch;
    char *string[20];
    char name[30];
    char space[2] = {" "};

    FILE *p = fopen("data.txt", "r");

    if (p == NULL) {
        printf("Error. File cannot be found\n");
        return -1;
    } else {

//read 10 lines into a string name: "arr[row][col]"
        ch = fgetc(p);
        while (ch >= 0 && count_line < 10 ) {
          if (ch == '\n') {
            arr[row][col] = ch;
            arr[row][col++] = '\0';
            count_line++;
            row++;
            col = 0;
            ch = fgetc(p);
        } else{
          arr[row][col] = ch;
          col++;
          ch = fgetc(p);
        }
        }
        fclose(p);
    }

    for (int row = 0; row < 10; row++) {
      for (int col = 0; col < strlen(arr[row]); col++) {
        // printf("%c", arr[row][col]);
      }
      // printf("\n");

    for (int i = 0; i < 10; i++) {
      pch = strtok (arr[i]," ");
      string[n] = pch;
      while (pch != NULL) {
          pch = strtok (NULL, " ");
          n++;
          string[n] = pch;
          // printf("%s\n", string[n]);
      }
    }

    for (int j = 0; j < (n - 3); j++) {
        strcat(name, string[j]);
        strcat(name, space);
    }

    // Put data into struct
    inf information[10];
    for (int i = 0; i < 10; i++) {
      strcpy(information[i].nam_e,name  );
      information[i].age = atof(string[n-3]);
      information[i].weight = atof(string[n-2]);
      information[i].income = atof(string[n-1]);
      // printf("%s\t%i\t%.2f\t%.2f\n",information[i].nam_e ,information[i].age,information[i].weight, information[i].income);
    }

    // for (int i = 0; i < n; i++) {
    //   printf("%c", *string[i]);
    // }
}

    return 0;
  }
    /*
    pch = strtok (arr," ,-");
    string[n] = pch;

    while (pch != NULL) {
        pch = strtok (NULL, " ,-");
        n++;
        string[n] = pch;
    }
}

for (int j = 0; j < (n - 3); j++) {
    strcat(name, string[j]);
    strcat(name, space);
}
    fclose(p);

// Put data into struct
inf information;
strcpy(information.nam_e,name);
information.age = atof(string[n-3]);
information.weight = atof(string[n-2]);
information.income = atof(string[n-1]);
printf("%s\t%i\t%.2f\t%.2f\n",information.nam_e ,information.age,information.weight, information.income);
return 0;
}*/
