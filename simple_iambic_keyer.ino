// Simple Iambic Keyer v1.00
// by Ernest PA3HCM

#define P_DOT    2   // Connects to the dot lever of the paddle
#define P_DASH   3   // Connects to the dash lever of the paddle
#define P_AUDIO 12   // Audio output
#define P_CW    13   // Output of the keyer, connect to your radio
#define P_SPEED A0   // Attached to center pin of potmeter, allows you
                     // to set the keying speed.

int speed;

// Initializing the Arduino
void setup()
{
  pinMode(P_DOT, INPUT);
  pinMode(P_DASH, INPUT); 
  pinMode(P_AUDIO, OUTPUT);
  pinMode(P_CW, OUTPUT);
  digitalWrite(P_CW, LOW);      // Start with key up
}

// Main routine
void loop()
{
  speed = analogRead(P_SPEED)/2; // Read the keying speed from potmeter
  if(!digitalRead(P_DOT))        // If the dot lever is presssed..
  {
    keyAndBeep(speed);           // ... send a dot at the given speed
    delay(speed);                //     and wait before sending next
  }
  if(!digitalRead(P_DASH))       // If the dash lever is pressed...
  {
    keyAndBeep(speed*3);         // ... send a dash at the given speed
    delay(speed);                //     and wait before sending next
  }
}

// Key the transmitter and sound a beep
void keyAndBeep(int speed)
{
  digitalWrite(P_CW, HIGH);            // Key down
  for (int i=0; i < (speed/2); i++)    // Beep loop
  {
    digitalWrite(P_AUDIO, HIGH);
    delay(1);
    digitalWrite(P_AUDIO, LOW);
    delay(1);
  }
  digitalWrite(P_CW, LOW);             // Key up
}
