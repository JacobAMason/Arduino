#define RED_LED (9)
#define RED_ON_DELAY_MS (250)
#define RED_OFF_DELAY_MS (250)
#define RED_MESSAGE "The Red LED is blinking"

#define GREEN_LED (8)
#define GREEN_ON_DELAY_MS (250)
#define GREEN_OFF_DELAY_MS (250)
#define GREEN_MESSAGE "The Green LED is blinking"

int redNumBlinks = 5;
int greenNumBlinks = 5;

void setup()
{
    // put your setup code here, to run once:

    Serial.begin(9600);

    pinMode(RED_LED, OUTPUT);
    pinMode(GREEN_LED, OUTPUT);

    Serial.println("How many times do you want the Red LED to blink?");
    while( Serial.available() == 0 ){}
    redNumBlinks = Serial.parseInt();

    Serial.println("How many times do you want the Green LED to blink?");
    while( Serial.available() == 0 ){}
    greenNumBlinks = Serial.parseInt();
}

void loop()
{
    Serial.println(RED_MESSAGE);  
    for (int i=0; i < redNumBlinks; i++)
    {
        Serial.println(i);
        digitalWrite(RED_LED, HIGH);
        delay(RED_ON_DELAY_MS);
        digitalWrite(RED_LED, LOW);
        delay(RED_OFF_DELAY_MS);
    }
    Serial.println();
    
    Serial.println(GREEN_MESSAGE);
    
    for (int i=0; i < greenNumBlinks; i++)
    {
        Serial.println(i);
        digitalWrite(GREEN_LED, HIGH);
        delay(GREEN_ON_DELAY_MS);
        digitalWrite(GREEN_LED, LOW);
        delay(GREEN_OFF_DELAY_MS);
    }
    Serial.println();
}
