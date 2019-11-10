#define DATA_PIN 9
#define LATCH_PIN 10
#define CLOCK_PIN 11

#define NUM_BUTTONS 8

void setup()
{
  pinMode(DATA_PIN, INPUT);
  pinMode(LATCH_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  Serial.begin(2000000);
}

void captureInput()
{
  digitalWrite(LATCH_PIN, HIGH);
  digitalWrite(LATCH_PIN, LOW);
}

void shiftButton()
{
  digitalWrite(CLOCK_PIN, HIGH);
  digitalWrite(CLOCK_PIN, LOW);
}

void loop() {
  captureInput();
  int buttonRegister = 0;
  for (int i = 0; i < NUM_BUTTONS; i++)
  {
    int state = digitalRead(DATA_PIN);
    if (!state) // Buttons are active low
      bitSet(buttonRegister, i);           
    shiftButton();
  }
  Serial.write(buttonRegister);  
}
