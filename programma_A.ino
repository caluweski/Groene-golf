// STEM@SCHOOL - Module 1 - Programma A
// indien wagentje te snel rijdt dan moet PB lager gezet worden, of omgekeerd


//pinnummers toewijzen
const int PWM_Pin = 9;
const int ControlPinA = 8;
const int ControlPinB = 7;

//motorwaarde instellen
int PB = 110;

void setup() {
  Serial.begin(9600);
  pinMode (0, INPUT_PULLUP); //uit voorzorg
  pinMode (PWM_Pin, OUTPUT);
  pinMode (ControlPinA, OUTPUT);
  pinMode (ControlPinB, OUTPUT);
  
  digitalWrite(PWM_Pin, LOW);
  
  delay(5000); //5 seconden wachten na opstarten
// 15 seconden rijden
  Serial.println("Rijden");
  analogWrite (PWM_Pin, PB);
  digitalWrite (ControlPinA, HIGH);
  digitalWrite (ControlPinB, LOW);
  delay(15000);
// stoppen
  Serial.println("Stoppen");
  analogWrite (PWM_Pin, LOW);
  digitalWrite (ControlPinA, LOW);
  digitalWrite (ControlPinB, LOW);  
}

void loop() {
}
