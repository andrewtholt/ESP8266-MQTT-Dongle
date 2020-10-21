# Callbacks

Each key/value pair has a SET and a GET callback.  The default for a simple value just access the retained dats.

This protocol has two, basic, message types.  SET and GET.

###SET
This can have one of two different callbacks:
1. The default which simply sets the retained value, and
2. A callback that triggers an action.  E.g. If you set the speed of a motor the callback will manipulate the hardware.

###GET
This can have one of two different callbacks:
1. The default which simply gets, and returns,  the retained value, and
2. A callback that triggers an action.  E.g. If you mesure the speed of a motor the callback will take a measurement.


## Set callbacks
**WIFI_CONNECTED**

If command from serial, return command error.

Places a message into the serial out queue.
On success 
```
SET WIFI_CONNECTED TRUE
```
On failure
```
SET WIFI_CONNECTED FALSE
```

**MQTT_CONNECTED**
If command from serial, return command error.

Places a message into the serial out queue.
On success 
```
SET MQTT_CONNECTED TRUE
```
On failure
```
SET MQTT_CONNECTED FALSE
```

## Get callbacks
