# 🚀 Non-Gravitar

_Un videogioco arcade testuale in C++_

**Non-Gravitar** è un gioco ASCII ambientato nello spazio, dove il giocatore pilota l’astronave **Infinity** attraverso una galassia infinita composta da sistemi solari. Ogni sistema contiene due pianeti, ciascuno difeso da bunker armati.
L’obiettivo è distruggerli, raccogliere carburante e sopravvivere il più a lungo possibile.

---

## 🎮 Gameplay

### 🎯 Obiettivo
- Esplora i sistemi solari
- Entra nei pianeti
- Distruggi tutti i bunker per eliminare il pianeta
- Raccogli carburante (GPL o Benzina)
- Passa a sistemi solari adiacenti
- Evita il Game Over!

### 🕹️ Comandi principali
| Tasto | Azione                         |
|-------|--------------------------------|
| `W`   | Su                             |
| `S`   | Giù                            |
| `A`   | Sinistra                       |
| `D`   | Destra                         |
| `X`   | Attiva/disattiva raggio        |
| `I`   | Spara missile 1                |
| `O`   | Spara missile 2                |
| `P`   | Spara missile 3                |

> ℹ️ Disattiva il Bloc Maiusc: se attivo, i comandi non funzionano.

---

## 🧠 Meccaniche di gioco

- **Sistema solare infinito:** lista doppiamente collegata di sistemi generati dinamicamente
- **Due tipi di carburante:**
  - GPL → +10 movimenti
  - Benzina → +20 movimenti
- **3 missili differenti**: ognuno può essere riutilizzato solo dopo aver toccato terra
- **Raggio traente**: attivabile con `X`, serve per raccogliere carburante
- **Vite e carburante limitati**: Game Over se esauriti
- **Memorizzazione stato**: se abbandoni un pianeta, ritroverai la situazione intatta al ritorno

---

## 💻 Schermata ASCII

Simboli di gioco:
- `V` → Astronave
- `A` → Raggio traente attivo
- `S` → Pianeta 1
- `N` → Pianeta 2
- `0` → Bunker debole (2 colpi)
- `8` → Bunker forte (3 colpi)
- `I` → Missili sparati

---
