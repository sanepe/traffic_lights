# Arduino Traffic Light — Semáforo educativo (NPN, 3 LEDs por color)

**English Description**  
Open-source educational project of a traffic light built with Arduino.  
It uses **NPN transistors (low-side switching)** to safely control **3 LEDs per color** without overloading the Arduino pins.  
Sequence: **Green 30s (last 3s blinking) → Yellow 2s → Red 5s**.  
Designed in **Tinkercad** and successfully tested on **real Arduino hardware** ✅

---

**Descripción en Español**  
Proyecto abierto para **aprendizaje y observación**: un semáforo con Arduino que usa **transistores NPN en low-side** para controlar **3 LEDs por color** sin sobrecargar los pines.

- **Pines**: Rojo **D8**, Amarillo **D9**, Verde **D10**
- **Secuencia**: Verde **30 s** (últimos **3 s** parpadea) → Amarillo **2 s** (fijo) → Rojo **5 s** (fijo)
- **Corriente segura**: cada LED tiene su **resistencia de 330 Ω** y cada color se conmuta con **1 transistor NPN**
- **Validación**: *Diseñado en **Tinkercad** y **probado en Arduino físico*** ✅

---

## 🧩 Materials / Materiales

- 1× Arduino Uno (or compatible / o compatible)
- 9× LEDs (3 red, 3 yellow, 3 green / 3 rojos, 3 amarillos, 3 verdes)
- 9× resistors **330 Ω** (one per LED / una por LED)
- 3× **NPN transistors** (2N2222 / PN2222A / 2N3904)
- 3× resistors **680 Ω–1 kΩ** (base of each transistor / base de cada transistor)
- (Optional / Opcional) 3× resistors **100 kΩ** (pull-down base→GND)
- Breadboard and jumper wires / Protoboard y jumpers

> **Why transistors? / Por qué usar transistores:**  
> 3 LEDs (~9 mA each) ≈ 27 mA per color. An Arduino pin should not source that much current directly.  
> 3 LEDs (~9 mA c/u) ≈ 27 mA por color. Un pin del Arduino no debe entregar tanta corriente directamente.

---

## 🔌 Wiring / Cableado (per color / por color)

- **Anode of each LED → 330 Ω → +5 V**
- **Cathodes of the 3 LEDs → common node → C (collector) of NPN**
- **E (emisor) → GND**
- **B (base) ← 1 kΩ ← Arduino pin**  
  - Red **D8**, Yellow **D9**, Green **D10**
- (Optional / Opcional) **100 kΩ** from **B** to **GND** (pull-down to avoid false ON at startup)

**Logic diagram / Diagrama lógico:**
```text
+5V ─ LED ─ 330Ω ─┐
+5V ─ LED ─ 330Ω ─┼── C (NPN)
+5V ─ LED ─ 330Ω ─┘
E (NPN) ─ GND
B (NPN) ─ 1kΩ ─ D8/D9/D10
```
> In Tinkercad, transistor “C B E” flat face: **left=C**, **center=B**, **right=E**.  
> En Tinkercad (transistor con cara plana y texto “C B E”): **izq=C**, **centro=B**, **der=E**.

---

## 🗂 Project Versions / Versiones del proyecto

- **v1** (`src/traffic_light/v1/traffic_light_v1.ino`): Basic traffic light (green 30s with final blink, yellow 2s, red 5s).  
- **v2** (`src/traffic_light/v2/traffic_light_v2.ino`): Future improvements (Adds 16×2 LCD with countdown and messages.)
- **v3** (`src/traffic_light/v3/traffic_light_v3.ino`): Future improvements (pedestrian button, buzzer, night mode, etc.).

---

## 🧠 Main Sketch / Sketch principal

Save code in: `src/traffic_light/v1/traffic_light_v1.ino`.  
Guarda el código en: `src/traffic_light/v1/traffic_light_v1.ino`.

Adjustable timing variables / Variables de tiempos (ajustables en el sketch):
- `GREEN_TOTAL_MS = 30000` (30 s green / verde)
- `GREEN_BLINK_BEFOREMS = 3000` (last 3 s blink / últimos 3 s parpadea)
- `YELLOW_MS = 2000` (2 s yellow / amarillo)
- `RED_MS = 5000` (5 s red / rojo)
- `BLINK_PERIOD_MS = 250` (blink speed / velocidad del parpadeo)

Low-side NPN switching ⇒ `HIGH` = ON / encendido.

---

## ▶️ Usage / Uso

1. Open `src/traffic_light/v1/traffic_light_v1.ino` in Arduino IDE.  
   Abre `src/traffic_light/v1/traffic_light_v1.ino` en Arduino IDE.
2. Select board and port.  
   Selecciona placa y puerto.
3. Upload the sketch.  
   Sube el sketch.
4. Verify sequence: **Green 27 s solid + 3 s blink → Yellow 2 s → Red 5 s**.  
   Verifica la secuencia: **Verde 27 s fijo + 3 s parpadeo → Amarillo 2 s → Rojo 5 s**.

---

## 🧪 Quick Tests / Pruebas rápidas

- If a color **doesn’t light** / Si un color **no enciende**:
  - Check LED polarity / Revisa polaridad de los LEDs
  - Confirm transistor orientation (C-B-E) / Confirma orientación del transistor (C-B-E)
  - Common ground with Arduino / Asegura GND común con Arduino
  - Check base resistor wiring / Verifica la resistencia de base
- If a color **stays always ON** / Si un color **queda siempre encendido**:
  - Add 100 kΩ pull-down base→GND / Añade resistencia pull-down de 100 kΩ de base a GND
  - Ensure base is not tied to +5V / Comprueba que la base no esté conectada directo a +5 V

---

## 👤 Author / Autor

**Santiago Lepe** — [@sanepe](https://github.com/sanepe)

---

## 🤝 Contributions / Contribuciones

Contributions welcome! / ¡Bienvenidas contribuciones!  
Ideas for improvements / Ideas para mejoras:
- Pedestrian button & configurable timer / Botón peatonal y temporizador configurable
- Buzzer for accessibility / Zumbador para cruce accesible
- LCD version with countdown / Versión con LCD (cuenta regresiva)
- Night mode with reduced times / Modo “noche” con tiempos reducidos
