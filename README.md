# 🚗 Bluetooth Controlled RC Car (L298N + HC-05)

This project demonstrates how to build a **Bluetooth-controlled RC car** using an **Arduino Uno**, **L298N motor driver**, and an **HC-05 Bluetooth module**.  
The car can be controlled from any Android/iOS Bluetooth controller app by sending specific characters (`F`, `B`, `L`, `R`, etc.) over serial communication.

---

## 📖 Features
- Control car wirelessly via Bluetooth
- Forward, Backward, Left, Right movements
- Diagonal movements (Forward-Left, Forward-Right, Backward-Left, Backward-Right)
- Emergency Stop command
- Status LED that turns ON when the car is powered
- Adjustable motor speeds via PWM

---

## 🛠 Components Required
| Component | Quantity |
|-----------|----------|
| Arduino UNO | 1 |
| L298N Motor Driver Module | 1 |
| HC-05 Bluetooth Module | 1 |
| DC Gear Motors | 4 |
| Robot Car Wheels | 4 |
| 18650 Li-ion Battery (3.7V) | 2 |
| 18650 Battery Holder | 1 |
| Jumper Wires (M-M, M-F) | As required |
| 5mm LED (Status LED) | 1 |
| ON/OFF Switch | 1 |
| Acrylic/Plastic/Metal chassis | 1 |

---

## ⚡ Pin Connections

### 🔹 HC-05 Bluetooth Module → Arduino
| HC-05 Pin | Arduino Pin |
|-----------|-------------|
| TXD       | 9 (SoftwareSerial RX) |
| RXD       | 10 (SoftwareSerial TX) |
| VCC       | 5V |
| GND       | GND |

---

### 🔹 L298N Motor Driver → Arduino
| L298N Pin | Arduino Pin | Function |
|-----------|-------------|----------|
| ENA       | 5 | Enable Motor A (PWM Speed Control) |
| IN1       | 6 | Motor A Input 1 |
| IN2       | 7 | Motor A Input 2 |
| IN3       | 8 | Motor B Input 1 |
| IN4       | 11 | Motor B Input 2 |
| ENB       | 12 | Enable Motor B (PWM Speed Control) |
| 12V       | Battery + (7.4V) |
| GND       | Arduino GND + Battery - |

---

### 🔹 Motors
- **Motor A (Right side)** connected to `OUT1` & `OUT2` of L298N  
- **Motor B (Left side)** connected to `OUT3` & `OUT4` of L298N  

---

### 🔹 Status LED
| LED Pin | Arduino Pin |
|---------|-------------|
| + (Anode) | 13 |
| - (Cathode) | GND |

---

## 💻 Code Explanation
- `SoftwareSerial HC05(9,10)` → Creates a software serial port for Bluetooth communication  
- `#define led1 13` → Status LED pin  
- Motor driver pins (`enA, in1, in2, in3, in4, enB`) defined for controlling the L298N  
- `setup()`:
  - Initializes LED, Bluetooth, and motor pins  
  - Calls `Stop()` to ensure motors are off at startup  
- `loop()`:
  - Continuously checks if Bluetooth data is available  
  - Reads a command (`F`, `B`, `L`, `R`, etc.)  
  - Executes the respective function (`Forward()`, `Back()`, `Left()`, etc.)  
- Functions (`Forward()`, `Back()`, `Left()`, etc.):
  - Use `analogWrite()` to control motor speed  
  - Use `digitalWrite()` to set motor direction  

---

## 📱 Bluetooth Commands
| Command | Action |
|---------|--------|
| `F` | Move Forward |
| `B` | Move Backward |
| `L` | Turn Left |
| `R` | Turn Right |
| `G` | Forward Left |
| `I` | Forward Right |
| `H` | Backward Left |
| `J` | Backward Right |
| `S` | Stop |

You can use apps like **Bluetooth RC Controller** or **Arduino Bluetooth Controller** (available on Play Store).

---

## 🔋 Power Supply
- Use **2 × 18650 cells (7.4V total)**  
- Connect to **L298N 12V input**  
- L298N can also power Arduino via 5V pin (if jumper is present)  
- Status LED consumes minimal current, no extra supply required  

---

## 🚀 How to Upload & Run
1. Open Arduino IDE
2. open new file and save it as RC_car.ino in Arduino IDE
3. Select Board: Arduino Uno
4. Select correct COM Port
5. Upload the sketch
6. Pair your HC-05 with phone (1234 or 0000 default PIN)
7. Open Bluetooth controller app → Send commands (F, B, L, etc.)

---

## ⚠️ Precautions
1.Do not power HC-05 with more than 5V
2.Ensure GND is common between Arduino, Motor Driver, and Bluetooth
3.Use a proper battery holder to avoid loose connections
4.Motors may draw high current → avoid using Arduino 5V to power motors directly
5.If motors don’t spin, check L298N jumper settings and wiring


## 👨‍💻 Author
**Suman R N**  
📧 Contact: sumansurn@gmail.com  







