#include <stdint.h>

#define TOPIC_LEN 64
#define MSG_LEN 64

enum command {
    NOP=0,
    GET,
    SET,
    PUB,
    SUB,
    DBG=0xff    // If first byte is this, the rest of the packet is
                // Length, then a debug message string.
};

struct msg {
    uint8_t cmd;
    uint8_t keyLen;
    char key[TOPIC_LEN];
    uint8_t valLen;
    char val[MSG_LEN];
};

/*
uint8_t structToMsg(struct msg *in, uint8_t *buffer);
struct msg *msgToStruct( struct msg *in, uint8_t *msg);
*/

// 
// All roles will need an implementation of these
// One on the esp01 and
// One on each client.
//
uint8_t get(char *name, char *value);   // Return status and Get local variable value into pointer.
uint8_t set(char *name, char *value);   // Set local value returning status.

uint8_t pub(char *topic, char *msg);
uint8_t sub(char *topic);

void dbgMsg(char *out, char *msg);
void msgToStruct( struct msg *in, uint8_t *msg);
