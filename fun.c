#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void removeCommonCharacters(char *name1, char *name2) {
    int i, j;
    for (i = 0; name1[i] != '\0'; i++) {
        for (j = 0; name2[j] != '\0'; j++) {
            if (name1[i] == name2[j]) {
                name1[i] = name2[j] = '*';
                break;
            }
        }
    }
}

int countRemainingCharacters(char *name) {
    int count = 0, i;
    for (i = 0; name[i] != '\0'; i++) {
        if (name[i] != '*') {
            count++;
        }
    }
    return count;
}

char findFLAMES(int count) {
    char flames[] = "FLAMES";
    int length = strlen(flames);
    int pos = 0;

    while (length > 1) {
        pos = (pos + count - 1) % length;
        memmove(&flames[pos], &flames[pos + 1], length - pos - 1);
        length--;
    }
    return flames[0];
}

int main() {
    char name1[100], name2[100];
    int count1, count2, totalRemaining;

    printf("Enter the first name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = '\0'; // Remove newline character

    printf("Enter the second name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = '\0'; // Remove newline character

    removeCommonCharacters(name1, name2);

    count1 = countRemainingCharacters(name1);
    count2 = countRemainingCharacters(name2);
    totalRemaining = count1 + count2;

    char relationship = findFLAMES(totalRemaining);

    switch (relationship) {
        case 'F':
            printf("Result: Friends\n");
            break;
        case 'L':
            printf("Result: Love\n");
            break;
        case 'A':
            printf("Result: Affection\n");
            break;
        case 'M':
            printf("Result: Marriage\n");
            break;
        case 'E':
            printf("Result: Enemies\n");
            break;
        case 'S':
            printf("Result: Siblings\n");
            break;
    }

    return 0;
}
