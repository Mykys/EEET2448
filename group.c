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

    int i = 0, n = 0;
    char arr[100], ch;
    char *pch;
    char *string[20];
    char name[30];
    char space[2] = {" "};

    FILE *p = fopen("bigdata.txt", "r");

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
}

// #include <stdio.h>
// #include <string.h>
//
// int main ()
// {
//   char str[] ="- This, a sample string.";
//   char * pch;
//   printf ("Splitting string \"%s\" into tokens:\n",str);
//   pch = strtok (str," ,.-");
//   while (pch != NULL)
//   {
//     printf ("%s\n",pch);
//     pch = strtok (NULL, " ,.-");
//   }
//   return 0;
// }
