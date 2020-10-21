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
    digitalWrite(LED_BUILTIN,LOW);

    Serial.println("LED Off");

    delay(500);

    Serial.println("LED On");
    digitalWrite(LED_BUILTIN,HIGH);

    delay(500);
}


