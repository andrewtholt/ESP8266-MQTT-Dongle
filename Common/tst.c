#include "msg.h"

#include <string.h>
#include <stdint.h>
#include <stdio.h>

int main() {
    struct msg tstMessage;

    uint8_t buffer[PACKET_LEN];

    memset(buffer,0,PACKET_LEN);
    memset(&tstMessage, 0, sizeof(struct msg));

    tstMessage.cmd = SET;
    tstMessage.keyLen = 5;

    strncpy((char *) &tstMessage.key, "HELLO", 5);

    tstMessage.valLen = 4;
    strncpy((char *) &tstMessage.val, "TEST", 4);

    printf("\nMessage to struct\n");
    dumpStruct(&tstMessage);

    structToMsg(&tstMessage, (uint8_t *)&buffer);

    memset(&tstMessage, 0, sizeof(struct msg));

    printf("\nStruct To Message\n");
    msgToStruct( &tstMessage, (uint8_t *)&buffer);

    dumpStruct(&tstMessage);

}
