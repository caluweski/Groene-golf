// STEM@SCHOOL - Module 1 - Programma B
// indien wagentje niet in gang geraakt moet StartPB hoger gezet worden, net na void setup()
// indien wagentje te snel in gang geraakt moet StartPB lager gezet worden, net na void setup()
// indien versnelling/vertraging te klein is dan moet GrootteVersnelVertraag vergroot worden, net na void setup()
// indien startsnelheid gewenst moet na eerste alinea van void setup() de opmerking aangepast worden door /* te verwijderen

//pinnummers toewijzen
const int PWM_Pin = 9;
const int ControlPinA = 8;
const int ControlPinB = 7;

//variable declareren
float PB;
float StartPB;
float GrootteVersnelVertraag;
unsigned long StartTijd;
unsigned long VerlopenTijd;
boolean timedOut = false;
unsigned long interval = 4000;

void setup() {
  StartPB = 130;
  GrootteVersnelVertraag = 1;
  Serial.begin(9600);
  pinMode (0, INPUT_PULLUP); //uit voorzorg
  pinMode (PWM_Pin, OUTPUT);
  pinMode (ControlPinA, OUTPUT);
  pinMode (ControlPinB, OUTPUT);
  digitalWrite(PWM_Pin, LOW);
  Serial.println("Even wachten");
  delay(5000); //paar seconden wachten na opstarten

// indien startsnelheid gewenst moet bij onderstaande regels de /* en */ verwijderd worden  

/*  
  Serial.println("Startsnelheid nemen");
  analogWrite (PWM_Pin, StartPB);
  digitalWrite (ControlPinA, HIGH);
  digitalWrite (ControlPinB, LOW);  
  delay(3000);
  Serial.println("Gedaan met startsnelheid namen, programma start");
*/
  
// 4 seconden versnellen
  timedOut = false;
  Serial.print("timedOut = ");
  Serial.println(timedOut);
  StartTijd = millis();
  Serial.print("StartTijd = ");
  Serial.println(StartTijd);
  Serial.println("4s versnellen");
  VerlopenTijd = millis() - StartTijd;
    PB = StartPB;
      while(PB < 255 && ((timedOut != true) && (VerlopenTijd < interval)))
      {
        VerlopenTijd = millis() - StartTijd;
        Serial.print("Verlopen tijd = ");
        Serial.print(VerlopenTijd);
        Serial.print(" | Oude PB = ");
        Serial.print(PB);
        Serial.println(" => Verhoog PB ");
        PB = PB + GrootteVersnelVertraag;
        Serial.print("Nieuwe PB = ");
        Serial.print(PB);
        Serial.println(" | Stuur PB door naar motor");
        analogWrite (PWM_Pin, PB);
        digitalWrite (ControlPinA, HIGH);
        digitalWrite (ControlPinB, LOW);
      }
      timedOut = true;
      Serial.print("timedOut = ");
      Serial.print(timedOut);    
      Serial.println(" | PB maximaal of tijd overschreden dus stop versnellen");

// 4 seconden constante snelheid
  Serial.print("4s constante snelheid aan PB: ");
  Serial.println(PB);
  analogWrite (PWM_Pin, PB);
  delay(4000);
// 4 seconden vertragen
  timedOut = false;
  StartTijd = millis();
  VerlopenTijd = millis() - StartTijd;
  Serial.println("4s vertragen");
  while(PB > 0 && ((timedOut != true) && (VerlopenTijd < interval)))
    {
        VerlopenTijd = millis() - StartTijd;
        Serial.print("Verlopen tijd = ");
        Serial.print(VerlopenTijd);
        Serial.print(" | Oude PB = ");
        Serial.print(PB);
        Serial.println(" => Verlaag PB ");
        PB = PB - 4;
        Serial.print("Nieuwe PB = ");
        Serial.print(PB);
        Serial.println(" | Stuur PB door naar motor");
        analogWrite (PWM_Pin, PB);
        digitalWrite (ControlPinA, HIGH);
        digitalWrite (ControlPinB, LOW);
      }
    timedOut = true;
    Serial.print("timedOut = ");
    Serial.print(timedOut);    
    Serial.println(" | PB minimaal of tijd overschreden dus stop vertragen");

// stoppen
  Serial.println("Stoppen | PB op nul en motoren uit");
  analogWrite (PWM_Pin, LOW);
  digitalWrite (ControlPinA, LOW);
  digitalWrite (ControlPinB, LOW);
}

void loop() {

}
