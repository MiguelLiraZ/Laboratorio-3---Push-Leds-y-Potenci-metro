// Declaración de constantes
const int ledRojo = 5;
const int ledAmarillo = 6;
const int ledVerde = 7;
const int pb1 = 2;
const int pb2 = 3;
const int pb3 = 4;
const int potenciometro = A3;

// Declaración de variables
int valorPotenciometro;

void setup() {
  // Configuración de los pines
  pinMode(ledRojo, OUTPUT);
  pinMode(ledAmarillo, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(pb1, INPUT_PULLUP);
  pinMode(pb2, INPUT_PULLUP);
  pinMode(pb3, INPUT_PULLUP);
  Serial.begin(9600); // Inicia la comunicación serial
}

void loop() {
  // Lee el estado de los pushbuttons y Encender los leds correspondientes
  if (digitalRead(pb1) == HIGH) {
    digitalWrite(ledRojo, HIGH);
  } else {
    digitalWrite(ledRojo, LOW);
  }
  if (digitalRead(pb2) == HIGH) {
    digitalWrite(ledAmarillo, HIGH);
  } else {
    digitalWrite(ledAmarillo, LOW);
  }
  if (digitalRead(pb3) == HIGH) {
    digitalWrite(ledVerde, HIGH);
  } else {
    digitalWrite(ledVerde, LOW);
  }

  // Lee el valor del potenciómetro y lo envía a Processing a través del puerto serie
  valorPotenciometro = analogRead(potenciometro);
  Serial.println(valorPotenciometro);
  delay(50); // Pequeña pausa para evitar una transmisión muy rápida de datos por el puerto serie
}
