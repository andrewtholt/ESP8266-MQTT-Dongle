#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

#include "msg.h"


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



