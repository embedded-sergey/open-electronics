#define RELAY 5 // first, we have to include libraries (if we have)
#define LED 13 // and define pins which are used for inputs/outputs

// normally closed relay: no power - device is active
const int FLUSH = 3;       // Relay is off, flushing pump is on
const int MEASUREMENT = 7; // Relay is on, flushing pump is off

int periodIndex = 1; // this is not constant as period will be incremented

void setup(){ // the setup loop is used for configurations, as the code runs just once. 
   pinMode(RELAY, OUTPUT); // we have to define output devices (e.g. relay, LED, buzzer),
   pinMode(LED, OUTPUT);   // while inputs devices (i.e. sensors) are typically omitted
   Serial.begin(9600); // open serial com. Note, baud rate must be the same as in Serial Monitor
   Serial.println("Phase, Abs.Time"); // this line will serve as a header for data streaming 
}

void loop(){
   digitalWrite(RELAY, HIGH); // set pin 3 ON to turn on the relay, so pumps start working again.

   for(int i = 0; i < FLUSH; i++){
         Serial.println((String)"F" + periodIndex + (",") + millis());
         digitalWrite(LED, HIGH);
         delay(1000);
      }

   digitalWrite(RELAY, LOW); // set pin 3 OFF to turn off the relay,
                              // so pumps stop working

   for(int i = 0; i < MEASUREMENT; i++){
         Serial.println( (String)"M" + periodIndex + (",") + millis());
         digitalWrite(LED, HIGH);
         delay(200);
         digitalWrite(LED, LOW);
         delay(800);
      }

    periodIndex++;
}
