#include "SerialCommunicator.h"

SerialCommunicator SC(9600);

void setup()
{
    pinMode(8, OUTPUT);
    pinMode(9, OUTPUT);
    pinMode(11, OUTPUT);
    SC.setup();
}

void loop()
{
    
}

/*
  SerialEvent occurs whenever a new data comes in the
 hardware serial RX.  This routine is run between each
 time loop() runs, so using delay inside loop can delay
 response.  Multiple bytes of data may be available.
 */
void serialEvent()
{
    digitalWrite(11, HIGH);
    String inputData = Serial.readString();
    bool result;
    result = SC.process_data(inputData);
    if (result)
    {
        digitalWrite(8, HIGH);
        digitalWrite(9, LOW);
    }
    else
    {
        digitalWrite(8, LOW);
        digitalWrite(9, HIGH);
    }
}