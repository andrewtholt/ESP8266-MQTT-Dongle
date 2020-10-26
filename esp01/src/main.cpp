#include "Arduino.h"
#include <LittleFS.h>
#include "kvs.h"
#include "msg.h"

KVSstore *store;

void setup() {
    store = kvs_create(strcmp);

    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    FS* fileSystem = &LittleFS;
    LittleFSConfig fileSystemConfig = LittleFSConfig();

    fileSystemConfig.setAutoFormat(true);

    fileSystem->setConfig(fileSystemConfig);
    fileSystem->begin();

    kvs_put(store, "abc", (KVSvalue *)"123");
    delay(5000);

    if( LittleFS.exists("/test.txt")) {
        Serial.println("File exists");
    } else {
        Serial.println("File does not exist.");
        File f = LittleFS.open("/test.txt","w");

        if(!f) {
            Serial.println("Failed to create file.");
        } else {
            f.write("Here is some data");
            f.close();
        }
    }
}

void loop() {

    uint8_t len=0;
    char buffer[255];

    digitalWrite(LED_BUILTIN,LOW);

    dbgMsg(buffer,(char *)"TESTING");

    memset((void *)buffer,0,sizeof(buffer));
    buffer[0] = '*';
    buffer[1] = 0x00; // packet length
    buffer[2] = 0xff;
    buffer[3] = 7;

    len=4;

    strcpy(&buffer[4],"LED OFF");

    len += strlen(&buffer[4]);

    buffer[1] = len;
    Serial.println( buffer );
//    Serial.println("LED Off");

    delay(500);

    digitalWrite(LED_BUILTIN,HIGH);

    memset((void *)buffer,0,sizeof(buffer));
    buffer[0] = '*';
    buffer[1] = 0x00; // packet length
    buffer[2] = 0xff;
    buffer[3] = 6;

    len=4;

    strcpy(&buffer[4],"LED ON");
    len += strlen(&buffer[4]);
    buffer[1] = len;
    Serial.println( buffer );

//    Serial.println("LED On");

    delay(500);
}


