#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void encryptText();
void decryptText();

int main() {
    int option;

    while (1) {
        printf("Caesar Cipher :)\n");
        printf("----------------\n");
        printf("\n1. Encrypt\n2. Decrypt\n3. Exit");
        printf("\nEnter Option: ");
        scanf("%d", &option);
        getchar(); 

        switch (option) {
            case 1:
                encryptText();
                break;
            case 2:
                decryptText();
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("Not a valid option.\n");
        }
    }
    return 0;
}

void encryptText() {
    char plainText[100], cipherText[100];
    int key, i;

    printf("\nEnter plain text: ");
    fgets(plainText, sizeof(plainText), stdin);
    plainText[strcspn(plainText, "\n")] = '\0'; 

    printf("Enter key: ");
    scanf("%d", &key);

    for (i = 0; i < strlen(plainText); i++) {
        if (plainText[i] >= 'A' && plainText[i] <= 'Z') {
            cipherText[i] = ((plainText[i] - 'A' + key) % 26 + 26) % 26 + 'A';
        } else if (plainText[i] >= 'a' && plainText[i] <= 'z') {
            cipherText[i] = ((plainText[i] - 'a' + key) % 26 + 26) % 26 + 'a';
        } else {
            cipherText[i] = plainText[i]; 
        }
    }
    cipherText[i] = '\0';

    printf("\nEncrypted Text: %s\n", cipherText);
}

void decryptText() {
    char plainText[100], cipherText[100];
    int key, i;

    printf("\nEnter cipher text: ");
    fgets(cipherText, sizeof(cipherText), stdin);
    cipherText[strcspn(cipherText, "\n")] = '\0'; 

    printf("Enter key: ");
    scanf("%d", &key);

    for (i = 0; i < strlen(cipherText); i++) {
        if (cipherText[i] >= 'A' && cipherText[i] <= 'Z') {
            plainText[i] = ((cipherText[i] - 'A' - key) % 26 + 26) % 26 + 'A';
        } else if (cipherText[i] >= 'a' && cipherText[i] <= 'z') {
            plainText[i] = ((cipherText[i] - 'a' - key) % 26 + 26) % 26 + 'a';
        } else {
            plainText[i] = cipherText[i]; 
        }
    }
    plainText[i] = '\0';

    printf("\nDecrypted Text: %s\n", plainText);
}
