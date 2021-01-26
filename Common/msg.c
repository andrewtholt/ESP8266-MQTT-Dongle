#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "msg.h"

void dumpStruct(struct msg *data) {

    uint8_t keyBuffer[TOPIC_LEN + 1];
    uint8_t valBuffer[MSG_LEN + 1];

    memset(keyBuffer,0, sizeof(keyBuffer));
    memset(valBuffer,0, sizeof(valBuffer));


    printf("Command : 0x%02x\t", data->cmd);
    switch(data->cmd) {
        case GET:
            printf("GET\n");
            break;
        case SET:
            printf("SET\n");
            break;
        case PUB:
            printf("PUB\n");
            break;
        case SUB:
            printf("SUB\n");
            break;
        case DBG:
            printf("DBG\n");
            break;
    }
    printf("Key len : %02d\n", data->keyLen);
    strncpy(keyBuffer, data->key, data->keyLen);
    printf("Key     : %s\n", keyBuffer);

    if (data->cmd == SET) {
        strncpy(valBuffer, data->val, data->valLen);
        printf("Val len : %02d\n", data->valLen);
        printf("Value   : %s\n", valBuffer);
    }
}

// 
// Create a debug message.
// The out buffer must be large enough to hold it.
//
void dbgMsg( char *msg, char *out) {


    uint8_t msgLen = strlen(msg);

    memset(out,0,msgLen + 5);
    out[0] = '*';
    out[1] = msgLen + 4;
    out[2] = DBG;
    out[3] = msgLen;

    strncpy(&out[4], msg, msgLen );
}

uint8_t set(char *name, char *value) {
    uint8_t status = 0;

    return status;
}


uint8_t structToMsg( struct msg *in, uint8_t *buffer) {

    memset(buffer,0,PACKET_LEN);

    uint8_t offset = 1;

    buffer[offset++] = in->cmd;
    buffer[offset++] = in->keyLen;

    memcpy( &buffer[offset], in->key, in->keyLen);
    offset += in->keyLen;

    switch(in->cmd) {
        case GET:
            break;
        case SET:
        case PUB:
            buffer[offset++] = in->valLen;
            memcpy( &buffer[offset], in->val, in->valLen);
            offset += in->valLen;
            break;
        case SUB:
            break;
        case DBG:
            break;
    }

    buffer[0] = offset;

    return(offset);

}

/** @fn struct msg *msgToStruct(char *msg, char *out)       
 *  @brief Convert an incoming message to the structure
 *  @param in: Pointer to the incoming message.    
 *  @param msg: Pointer to a pre-allocated buffer.    
 *      
 */
struct msg *msgToStruct( struct msg *in, uint8_t *msg) {
    uint8_t offset = 1;

    memset((void *)in,0,sizeof(struct msg));

    in->cmd = msg[offset++];

    in->keyLen = msg[offset++];
    memcpy( in->key, &msg[offset], in->keyLen);
    offset += in->keyLen;

    // Only SE and PUB have a value.
    //
    if (in->cmd == SET || in->cmd == PUB) {
        in->valLen = msg[offset++];
        memcpy( in->val, &msg[offset], in->valLen);
        offset += in->valLen;
    }

}

