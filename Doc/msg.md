


[Detailed protocol description](https://docs.google.com/document/d/1OJOHpChSJVUFZMr3Zsq3SWzSOcW19mqUVl02Q6hT_3M/edit) 

**GET** local
**SET** local value

**SUB** topic 
**PUB** topic msg

##Responses

General success

    SET ERROR FALSE

General error

    SET ERROR TRUE

Not connected

    SET ERROR NOT_CONNECTED

Not found

    SET ERROR NOT_FOUND

Found

    SET local value

##Locals

**WIFI_CONNECT** 
    Command if true connect to wifi using WIFI_SSID and WIFI_PASSWD.
    If values not set the general failure.

**WIFI_SSID** 
    ssid default empty string.

**WIFI_PASSWD**
    Password, default empty string.

**WIFI_CONNECTED**
    Current state of WiFi, either:
>NOT_CONNECTED
    CONNECTING
    CONNECTED
   
**MQTT_CONNECT**
    Command if true connect to mqtt using MQTT_HOST and MQTT_PORT.
    If values not set general failure.

**MQTT_CONNECTED**
    Current state of MQTT, either:
>NOT_CONNECTED
CONNECTING
CONNECTED

**MQTT_HOST**
    MQTT hostname.  default "localhost".

**MQTT_PORT**
    MQTT Port, default 1883
   
**AUTO_CONNECT** 
    If true connect to WiFi, the MQTT host.  If either fails return general error.

**SLEEP**
    If no command waiting sleep for SLEEP milliseconds.
    0 means don't sleep.
    Default is 0.

CMD_WAIT
    Wait for a command for CMD_WAIT ms.
    If 0 don't wait.
    If -1 wait for ever.
    Defaul is 10.
    





