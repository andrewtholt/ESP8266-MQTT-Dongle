#include <stdint.h>

#define TOPIC_LEN 64
#define MSG_LEN 64
#define PACKET_LEN 255

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

struct dbgMsg {
    uint8_t cmd;
    uint8_t dbgLen;

    uint8_t msg[PACKET_LEN - (sizeof(uint8_t) * 2)];  // the packet len - the 2 uint8_t values.
};


uint8_t structToMsg(struct msg *in, uint8_t *buffer);
struct msg *msgToStruct( struct msg *in, uint8_t *msg);

void dumpStruct(struct msg *Data) ;

// 
// All roles will need an implementation of these
// One on the esp01 and
// One on each client.
//
/** @fn void get(char *name, char *value)
*  @brief copy the value held by 'name' into value.
*  @param name: Pointer to the values name.
*  @param value: Pointer to a preallocated memory buffer
*/
uint8_t get(char *name, char *value);   // Return status and Get local variable value into pointer.
/** @fn void set(char *name, char *value)
*  @brief set the value held by 'name' into the value associated with name.
*  @param name: Pointer to the values name.
*  @param value: Pointer to the value.
*/
uint8_t set(char *name, char *value);   // Set local value returning status.

uint8_t pub(char *topic, char *msg);
uint8_t sub(char *topic);

/** @fn void dbgMsg(char *msg, char *out)
*  @brief dbgMsg format message int out
*  @param name: Pointer to the text message.
*  @param value: Pointer to a pre-allocated buffer.
*
*/
void dbgMsg( char *msg, char *out);     // Pointer to the message you want to send,
                                        // and a buffer to put the result in

