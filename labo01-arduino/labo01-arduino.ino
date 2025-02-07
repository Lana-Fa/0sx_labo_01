const int LED_PIN = 13;
const unsigned long STUDENT_ID = 2412384;

void setup() {
  // put your setup code here, to run once:
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

  // État allumé
  digitalWrite(LED_PIN, HIGH);
  Serial.println("Allume - " + String(STUDENT_ID));
  delay(2000);
  Serial.println("\n----------------------");

  //État clignotement
  int secondLastDigit = (STUDENT_ID / 10) % 10;
  int blinkCount = calculateBlinkCount(secondLastDigit);
  Serial.println("Clignotement - " + String(STUDENT_ID));

  for(int i = 0; i < blinkCount; i++){
    digitalWrite(LED_PIN, HIGH);
    delay(250);
    digitalWrite(LED_PIN, LOW);
    delay(250);
  }
  Serial.println("\n----------------------");

  //État variation d'intensité
  int lastDigit = STUDENT_ID % 10;
  Serial.println("Variation - " + String(STUDENT_ID));

  if(lastDigit % 2 == 0){
    for(int i = 0; i < 255; i++){
      digitalWrite(LED_PIN,HIGH);
      delay(8);
      digitalWrite(LED_PIN, LOW);
      delay(8);
    }
  }
  else {
    for (int i = 255; i >= 0; i--) {
      digitalWrite(LED_PIN, LOW);
      delay(8);
      digitalWrite(LED_PIN, HIGH);
      delay(8);
    }
  }
  Serial.println("\n----------------------");

  //Cycly
  digitalWrite(LED_PIN, LOW);
  Serial.println("Éteint - " + String(STUDENT_ID));
  delay(2000);
  Serial.println("\n----------------------");
}

int calculateBlinkCount(int secondLastDigit) {

  if (secondLastDigit == 0) return 10;
  return ceil(secondLastDigit / 2.0) + 1; 
}















