#include <stdint.h>

enum command {
    NOP=0,
    GET,
    SET,
    PUB,
    SUB
};

struct msg {
    uint8_t cmd;
    uint8_t keyLen;
    char key[256];
    uint8_t valLen;
    char val[256];
};

uint8_t structToMsg(struct msg *in, uint8_t *buffer);
struct msg *msgToStruct( struct msg *in, uint8_t *msg);
