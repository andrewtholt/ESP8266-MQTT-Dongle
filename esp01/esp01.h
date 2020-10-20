uint8_t get(char *name, char *value);   // Return status and Get local variable value into pointer.    
uint8_t set(char *name, char *value);   // Set local value returning status.    
    
uint8_t pub(char *topic, char *msg);    
uint8_t sub(char *topic);  
