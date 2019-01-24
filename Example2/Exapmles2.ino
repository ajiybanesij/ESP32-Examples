int led = 15;
int button = 23;

void setup() {

  pinMode(button, INPUT);
  pinMode(led, OUTPUT);
}

void loop() {

  if (digitalRead(button) == HIGH) {

    digitalWrite(led, HIGH);
  } else {

    digitalWrite(led, LOW);
  }

}
