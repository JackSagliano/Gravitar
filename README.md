# 🚀 Non-Gravitar

_A text-based arcade game in C++_

**Non-Gravitar** is an ASCII space game where you pilot the spaceship **Infinity** through an endless galaxy made of dynamically generated solar systems.  
Each system contains two planets defended by armed bunkers. Your mission: destroy them, collect fuel, and survive as long as you can.

---

## 🎮 Gameplay

### 🎯 Objective

- Explore solar systems  
- Land on planets  
- Destroy all bunkers to eliminate a planet  
- Collect fuel (GPL or Petrol)  
- Travel to adjacent solar systems  
- Avoid Game Over!

### 🕹️ Controls

| Key | Action                     |
|-----|----------------------------|
| `W` | Move Up                   |
| `S` | Move Down                 |
| `A` | Move Left                 |
| `D` | Move Right                |
| `X` | Toggle tractor beam       |
| `I` | Fire missile 1            |
| `O` | Fire missile 2            |
| `P` | Fire missile 3            |

> ⚠️ Make sure **Caps Lock is off**, or controls won’t respond.

---

## 🧠 Mechanics

- **Infinite Galaxy:** implemented as a doubly linked list of solar systems  
- **Two types of fuel:**
  - GPL → +10 moves  
  - Petrol → +20 moves  
- **3 missiles:** each must hit the ground before being reused  
- **Tractor Beam:** toggle with `X`, used to collect fuel  
- **Limited resources:** you lose if you run out of fuel or lives  
- **State memory:** planets keep their state even when you leave and come back

---

## 💻 ASCII Symbols

| Symbol | Meaning                 |
|--------|-------------------------|
| `V`    | Spaceship               |
| `A`    | Active tractor beam     |
| `S`    | Planet 1                |
| `N`    | Planet 2                |
| `0`    | Weak bunker (2 hits)    |
| `8`    | Strong bunker (3 hits)  |
| `I`    | Missile in flight       |

---

## 🧪 Requirements

- C++ compiler (`g++`)
- Terminal or console supporting ASCII characters

---

## 🛠️ Compile and Run

```bash
g++ -I. -Iastronave -Ibunker \
  MAIN.cpp \
  astronave/astronave.cpp \
  bunker/Bunker1.cpp \
  bunker/Bunker2.cpp \
  bunker/ProiettileBunker.cpp \
  bunker/ProiettileBunker2.cpp \
  bunker/ProiettileBunker3.cpp \
  bunker/ProiettileBunker4.cpp \
  astronave/serbatoio_astronave.cpp \
  astronave/carburante.cpp \
  Pianeta.cpp \
  posizionexy.cpp \
  Proiettile.cpp \
  Sistema_Solare.cpp \
  lista_sistemi_solari.cpp \
  -o MAIN.exe
