#include "Arduino.h"
#include <LittleFS.h>

void setup() {
    pinMode(LED_BUILTIN, OUTPUT);
    Serial.begin(115200);

    FS* fileSystem = &LittleFS;
    LittleFSConfig fileSystemConfig = LittleFSConfig();

    fileSystemConfig.setAutoFormat(true);

    fileSystem->setConfig(fileSystemConfig);
    fileSystem->begin();

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
    char buffer[255];


    digitalWrite(LED_BUILTIN,LOW);

    memset((void *)buffer,0,sizeof(buffer));
    buffer[0] = '*';
    buffer[1] = 0xff;
    buffer[2] = 7;

    strcpy(&buffer[3],"LED OFF");

    Serial.println( buffer );
//    Serial.println("LED Off");

    delay(500);

    digitalWrite(LED_BUILTIN,HIGH);

    memset((void *)buffer,0,sizeof(buffer));
    buffer[0] = '*';
    buffer[1] = 0xff;
    buffer[2] = 6;

    strcpy(&buffer[3],"LED ON");
//    Serial.println("LED On");
    Serial.println( buffer );

    delay(500);
}


