#include <Keyboard.h>

const int pressurePin1 = A0;    // Basınç sensörü 1 (l)
const int pressurePin2 = A1;    // Basınç sensörü 2 (sağ)
const int pirPin = 2;           // PIR (/) sensörü
const int pir505Pin = 4;        // HC-SR505 (↑) sensörü
const int threshold = 100;

bool wasPressed1 = false;
bool wasPressed2 = false;
bool pirTriggered = false;
bool pir505Triggered = false;

void setup() {
  Serial.begin(9600);
  while (!Serial);
  Keyboard.begin();

  pinMode(pirPin, INPUT);
  pinMode(pir505Pin, INPUT);
}

void loop() {
  // === 1. Öncelik: Basınç1 → 'l'
  int p1 = analogRead(pressurePin1);
  if (p1 < threshold && wasPressed1) {
    Keyboard.write('l');
    Serial.println("→ 'l' gönderildi");
    wasPressed1 = false;
    return;
  } else if (p1 >= threshold) {
    wasPressed1 = true;
  }

  // === 2. Öncelik: PIR → '/'
  if (digitalRead(pirPin) == HIGH && !pirTriggered) {
    Keyboard.write('/');
    Serial.println("→ '/' gönderildi");
    pirTriggered = true;
    return;
  } else if (digitalRead(pirPin) == LOW) {
    pirTriggered = false;
  }

  // === 3. Öncelik: Basınç2 → Sağ ok
  int p2 = analogRead(pressurePin2);
  if (p2 >= threshold && !wasPressed2) {
    Keyboard.press(KEY_RIGHT_ARROW);
    delay(50);
    Keyboard.release(KEY_RIGHT_ARROW);
    Serial.println("→ Sağ ok gönderildi");
    wasPressed2 = true;
    return;
  } else if (p2 < threshold) {
    wasPressed2 = false;
  }

  // === 4. Öncelik: HC-SR505 → Yukarı ok
  if (digitalRead(pir505Pin) == HIGH && !pir505Triggered) {
    Keyboard.press(KEY_UP_ARROW);
    delay(50);
    Keyboard.release(KEY_UP_ARROW);
    Serial.println("→ Yukarı ok gönderildi");
    pir505Triggered = true;
    return;
  } else if (digitalRead(pir505Pin) == LOW) {
    pir505Triggered = false;
  }

  delay(10); // Genel debounce/gecikme
}
