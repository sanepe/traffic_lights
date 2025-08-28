// Semáforo: verde 30s (últimos 3s parpadea), amarillo 2s, rojo 5s
// Conexiones: LED rojo en pin 8, amarillo en pin 9, verde en pin 10
// Resistencias de 220 ohm en serie con cada LED
// Autor: Santiago Lepe y compañía
// Fecha: agosto 2025
// Licencia: MIT License

const int RED = 8;
const int YEL = 9;
const int GRN = 10;

const unsigned long GREEN_TOTAL_MS       = 30000; // 30 s
const unsigned long GREEN_BLINK_BEFOREMS = 3000;  // parpadeo los últimos 3 s
const unsigned long YELLOW_MS            = 2000;  // 2 s
const unsigned long RED_MS               = 5000;  // 5 s
const unsigned long BLINK_PERIOD_MS      = 250;   // velocidad de parpadeo

void setLights(bool r, bool y, bool g) {
  digitalWrite(RED, r ? HIGH : LOW);
  digitalWrite(YEL, y ? HIGH : LOW);
  digitalWrite(GRN, g ? HIGH : LOW);
}

void setup() {
  pinMode(RED, OUTPUT);
  pinMode(YEL, OUTPUT);
  pinMode(GRN, OUTPUT);
  setLights(false, false, false);
}

void loop() {
  // VERDE fijo (30s - 3s = 27s)
  setLights(false, false, true);
  delay(GREEN_TOTAL_MS - GREEN_BLINK_BEFOREMS);

  // VERDE parpadeando los últimos 3s
  unsigned long t = 0;
  while (t < GREEN_BLINK_BEFOREMS) {
    digitalWrite(GRN, LOW);  delay(BLINK_PERIOD_MS);
    digitalWrite(GRN, HIGH); delay(BLINK_PERIOD_MS);
    t += 2 * BLINK_PERIOD_MS;
  }
  digitalWrite(GRN, LOW);

  // AMARILLO fijo 2s
  setLights(false, true, false);
  delay(YELLOW_MS);
  digitalWrite(YEL, LOW);

  // ROJO fijo 5s
  setLights(true, false, false);
  delay(RED_MS);
  digitalWrite(RED, LOW);
}
