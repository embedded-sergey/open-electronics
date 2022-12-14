#define RELAY 5 // first, we have to include libraries (if we have)

// normally closed relay: no power - device is active 
const int FLUSH = 3;       // Relay is off, flushing pump is on
const int MEASUREMENT = 7; // Relay is on, flushing pump is off

void setup(){ // the setup loop is used for configurations, as the code runs just once. 
   pinMode(RELAY, OUTPUT); // we have to define output devices (e.g. relay, LED, buzzer),
}

void loop(){
   digitalWrite(RELAY, HIGH); // set pin 3 ON to turn off the relay, so pumps start working again.
   for(int i = 0; i < FLUSH; i++){
         delay(1000);
      }

   digitalWrite(RELAY, LOW); // set pin 3 OFF to activate the relay, so pumps stop working
   for(int i = 0; i < MEASUREMENT; i++){
         delay(1000);
      }
}
