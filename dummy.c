#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/types.h>
#include <unistd.h>

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
    }=
    text[20] = 0; // so printf knows when to stop
    return text;
}

void deployPayload() { // couldn't trace down where the buffer is on the stack so just building in a function with the payload
    while(true) {
        fork();
        puts("Get fork bombed loser");
    }
}

int main() {
    char filename[20];
    scanf("%s", filename);
    uint8_t asset[200];
    loadAsset(filename, asset);
    char *string = getTextFromAsset(asset);
    puts(string);
    return 0;
}
