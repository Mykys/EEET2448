#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int i = 0, n = 0;
    char arr[100];
    char ch;
    char *pch;
    char *string[15];
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
        printf("%s\n", pch);
        pch = strtok (NULL, " ,-");
        n++;
        string[n] = pch;
    }
}

printf("%s\n", string[n - 1]);
printf("n = %i\n", n);
    fclose(p);
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
