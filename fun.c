#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

// Replace common characters in both names with '*'
void removeCommonChars(char *name1, char *name2) {
    for (int i = 0; name1[i] != '\0'; i++) {
        for (int j = 0; name2[j] != '\0'; j++) {
            if (name1[i] == name2[j] && name1[i] != '*') {
                name1[i] = name2[j] = '*';
                break;
            }
        }
    }
}

// Count characters that are not '*'
int countUnmatchedChars(const char *str) {
    int count = 0;
    for (int i = 0; str[i]; i++) {
        if (str[i] != '*') {
            count++;
        }
    }
    return count;
}

// FLAMES logic to find relationship type
char calculateFLAMES(int count) {
    char flames[] = "FLAMES";
    int length = strlen(flames);
    int index = 0;

    while (length > 1) {
        index = (index + count - 1) % length;

        // Remove character at index by shifting
        for (int i = index; i < length - 1; i++) {
            flames[i] = flames[i + 1];
        }
        flames[length - 1] = '\0';
        length--;
    }

    return flames[0];
}

// Match final letter to relationship
void printRelationship(char result) {
    switch (result) {
        case 'F': printf("💙 Result: Friends\n"); break;
        case 'L': printf("❤️ Result: Love\n"); break;
        case 'A': printf("💛 Result: Affection\n"); break;
        case 'M': printf("💍 Result: Marriage\n"); break;
        case 'E': printf("💢 Result: Enemies\n"); break;
        case 'S': printf("👨‍👩‍👧‍👦 Result: Siblings\n"); break;
    }
}

int main() {
    char name1[100], name2[100];

    printf("Enter the first name: ");
    fgets(name1, sizeof(name1), stdin);
    name1[strcspn(name1, "\n")] = '\0';

    printf("Enter the second name: ");
    fgets(name2, sizeof(name2), stdin);
    name2[strcspn(name2, "\n")] = '\0';

    toLowerCase(name1);
    toLowerCase(name2);

    removeCommonChars(name1, name2);

    int total = countUnmatchedChars(name1) + countUnmatchedChars(name2);

    char result = calculateFLAMES(total);

    printRelationship(result);

    return 0;
}
