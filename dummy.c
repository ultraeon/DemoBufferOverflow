#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

void loadAsset(char filename[], uint8_t assetBuffer[]) { // vulnerable dummy function
    FILE *filePointer = fopen(filename, "rb");
    uint16_t size[1]; // array bc fread
    fread(size, 2, 1, filePointer); // trusts size is valid
    fread(assetBuffer, 1, *size, filePointer); // uh oh if size>200 there will be a buffer overflow
    fclose(filePointer);
}

char* getTextFromAsset(uint8_t *asset) {
    char* text = malloc(21); // bad practice yippee
    for(int i = 0; i < 20; i++) {
        text[i] = asset[i]; // thankfully chars are 1 byte as well
    }
    text[20] = 0; // so printf knows when to stop
    return text;
}

int main() {
    char filename[];
    scanf("%s", filename);
    uint8_t asset[200];
    loadAsset(filename, asset);
    char *string = getTextFromAsset(asset);
    printf(string);
    return 0;
}
