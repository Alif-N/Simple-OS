#include "../include/kernel.h"
#include "../include/std_lib.h"

int main() {
  char buf[128];
  clearScreen();
  printString("Welcome to MengOS\n");

  while (true) {
    printString("$ ");
    readString(buf);
    printString(buf);
    printString("\n");
  }
}

void printString(char* str) {
    int i = 0;
    while(*str != '\0') {
        if(*str=='\n'){
            interrupt(0x10, 0x0E * 256 + '\r', 0, 0, 0);
            interrupt(0x10, 0x0E * 256 + '\n', 0, 0, 0);
        }else interrupt(0x10, 0x0E * 256 + *str, 0, 0, 0);
        str++;
    }

}

void readString(char* buf) {
    int i = 0;
    char c;
    for(;i<128;i++) buf[i] = '\0';
    i = 0;
    while(true){
        c = interrupt(0x16,0x00,0,0,0);
        if(c == '\r') {
            buf[i] = '\0';
            printString("\r\n");
            break;
        }else if(c == '\b') {
            if (i > 0) {
                i--;
                buf[i] = '\0';
                printString("\b \b");
            }
        }else{
            buf[i] = c;
            printString(&buf[i]);
            i++;
        }
    }
}


void clearScreen() {
    int i;
    for(i = 0; i < 80 * 25; i++) {
        putInMemory(0xB000, 0x8000 + i * 2, ' ');
        putInMemory(0xB000, 0x8001 + i * 2, 0x07);
    }
    interrupt(0x10, 0x0200, 0, 0, 0);
}

