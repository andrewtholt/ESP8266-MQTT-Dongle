#include "libser.h"
#include <termios.h>
#include <strings.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include <unistd.h>
#define SERIAL_PORT "/dev/ttyUSB1"

int main() {
    uint8_t buffer[256];
    bzero(buffer,sizeof(buffer));

    int fd = 0;

    printf("Opening port %s\n", (char *)SERIAL_PORT);

    fd = openSerialPort((char *)SERIAL_PORT, 0 );

    if(fd < 0) {
        fprintf(stderr,"Failed to open port:%s\n",SERIAL_PORT);
        exit(1);
    }

    flushSerialPort(fd);

    bool blk=true;
    int r ;
    while(true) {
        do {
            blk = wouldIblock(fd, 100) ;
            /*
            printf("would block is ");
            if( blk ) {
                printf(" TRUE\n");
            } else {
                printf(" FALSE\n");
            }
            */

        } while (blk==true) ;
        bzero(buffer,sizeof(buffer));

        uint8_t soh;
        r = read(fd, &soh, 1);
        printf("soh=0x%02x\n", soh);

        if( soh == '*') {
            uint8_t cmd;
            r = read(fd, &cmd, 1);
            printf("cmd=0x%02x\n", cmd);
            if( cmd == 0xff) {
                uint8_t len ;
                r = read(fd, &len, 1);
                printf("len=0x%02x\n", len);
                r = read(fd, buffer, len);
                printf("%s\n", buffer);
            }
        } else {
        }
    }
}

