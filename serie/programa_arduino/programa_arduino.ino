struct {
  bool estado_led;
} datos_rx;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(13, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available() > 0) {
    Serial.readBytes((byte *) &datos_rx, sizeof(datos_rx));

    if(datos_rx.estado_led == true) {
      digitalWrite(13, HIGH);
    } else {
      digitalWrite(13, LOW);
    }
  }
}
