#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "msg.h"


uint8_t structToMsg(struct msg *in, uint8_t *buffer) {

    memset(buffer,0,256);

    uint8_t offset = 1;

    buffer[offset++] = in->cmd;
    buffer[offset++] = in->keyLen;

    memcpy( &buffer[offset], in->key, in->keyLen);
    offset += in->keyLen;

    switch(in->cmd) {
        case SET:
        case PUB:
            buffer[offset++] = in->valLen;
            memcpy( &buffer[offset], in->val, in->valLen);
            offset += in->valLen;
            break;
    }

    buffer[0] = offset;

    return(offset);

}

struct msg *msgToStruct( struct msg *in, uint8_t *msg) {
    uint8_t offset = 0;

    memset((void *)in,0,sizeof(struct msg));

    uint8_t msgLen = msg[offset++];
    in->cmd = msg[offset++];

    in->keyLen = msg[offset++];
    memcpy( in->key, &msg[offset], in->keyLen);
    offset += in->keyLen;

    in->valLen = msg[offset++];
    memcpy( in->val, &msg[offset], in->valLen);
    offset += in->valLen;

}

int main() {
    struct msg *outbound = (struct msg *)malloc(sizeof(struct msg));

    uint8_t newMsg[256];

    memset((void *)outbound,0,sizeof(struct msg));

    outbound->cmd = GET;

    outbound->keyLen = 3;
    strncpy( outbound->key, "TST", 3);

    outbound->valLen = 4;
    strncpy( outbound->val, "1234", 4);

    //    struct msg *ptr = &outbound;

    uint8_t outMsgLen = structToMsg(outbound,newMsg) ;

    struct msg *t1 = msgToStruct(outbound,newMsg);
}



