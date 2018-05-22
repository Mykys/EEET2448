#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[]) {

    int i = 0;
    char ch, arr[100];

    // Read from bigdata.txt
    FILE *p = fopen("smalldata.txt", "r");

    char *ptr = (char *) malloc(100 * sizeof(char));
    char *another_ptr = ptr;
    if (ptr == NULL) {
        printf("Sorry, cannot allocate that much memory");
        return 1;
    }

    if (p == NULL) {
        printf("Error. File cannot be found\n");
        return -1;
    } else {
        ch = fgetc(p);
        *another_ptr = ch;
        while (ch != EOF) {
            //ptr++;
            ch = fgetc(p);
            //arr[i] = ch;
            //strcpy(ptr, &ch);
            *another_ptr = ch;

            if (ch == '\n') {
                ptr--;
                *ptr =
                strcpy(ptr, arr);
                //strcpy(ptr, "\n");
                i = 0;
            }
        }
        //arr[i--] = '\0';
        //ptr--;
        //*ptr = '\0';
        char end = '\0';
        strcpy(ptr, end);
        printf("%s\n" ptr);
    }

    return 0;
 }
