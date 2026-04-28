# cotton-quiz-buzzer
Arduino-based lockout buzzer for quiz competitions. Hardware engineering: relay-based AC/DC interfacing, modular RJ11 design, acrylic enclosure. Main Engineer: Dendy Fajar Kurniawan.
# Cotton: Embedded Quiz Lockout System

> Arduino-based competitive buzzer system designed for academic training at SMA Negeri 4 Denpasar.

![Status](https://img.shields.io/badge/Status-Completed-blue)
![Role](https://img.shields.io/badge/Role-Main_Engineer-orange)
![License](https://img.shields.io/badge/License-Educational-green)

## 📖 Overview
**Cotton** (Competitive Quiz Button) is a hardware system designed to simulate a "lockout buzzer" for academic quiz competitions (*Lomba Cerdas Cermat*). It detects the first player to press their button, locks out other inputs, and provides audio-visual feedback via an LED array and an AC-powered buzzer.

This project was developed by the FCC (Foursma Computer Club) to train students for national-level quiz bowl competitions.

## 👤 My Role: Main Engineer & System Architect
**Dendy Fajar Kurniawan**

As the **Main Engineer**, I was responsible for the hardware architecture, power system integration, and defining the system workflow between hardware inputs and software logic.

### 🔧 Key Contributions:
*   **System Architecture:** Designed the modular topology (Reset Box vs. Player Boxes) to ensure scalability and ease of maintenance.
*   **Power Engineering:** Implemented a **relay-based isolation circuit** to safely drive a 220V AC buzzer using a 5V DC Arduino microcontroller.
*   **Workflow Design:** Defined the hardware-software synchronization logic, determining how physical button presses translate to system states (Polling → Locked → Reset).
*   **Component Integration:** Selected and assembled components (Relays, Transistors, RJ11 modular connectors) based on signal integrity and durability requirements.
*   **Testing & Validation:** Conducted functional testing to verify signal timing, debouncing requirements, and safety isolation.

---

## ⚡ Technical Highlight: AC-DC Power Interfacing

One of the core engineering challenges was driving a loud, industrial-grade AC buzzer using a microcontroller limited to 5V logic.

### The Solution: Relay Isolation Circuit
I designed a switching circuit to separate the low-voltage control logic from the high-voltage load.

*   **Control Logic:** Arduino GPIO (5V) triggers a transistor switch.
*   **Driver:** Transistor amplifies the current to energize the relay coil.
*   **Isolation:** The relay physically separates the AC mains (220V) from the DC logic circuit, protecting the microcontroller from voltage spikes (flyback voltage).
*   **Safety:** Flyback diode (1N4007) added across the relay coil to suppress inductive kickback.

> **Engineering Impact:** This design choice prioritized **safety** and **signal integrity**, ensuring the noisy AC load would not reset or interfere with the Arduino's logic gates.

---

## 🏗️ Hardware Specifications

| Component | Specification | Purpose |
| :--- | :--- | :--- |
| **MCU** | Arduino UNO (ATmega328P) | Central logic controller |
| **Power Interface** | 5V Relay Module | Switching 220V AC load |
| **Connectivity** | RJ11 Ports + Telephone Cable | Modular connectivity for player boxes |
| **Input** | 4x Arcade Buttons + 1x Reset | User interaction (Momentary switch) |
| **Output** | 4x LEDs + 1x Reset LED | Visual feedback |
| **Audio** | 220V AC Buzzer | Audio feedback (High volume) |
| **Enclosure** | Acrylic + Wood | Protection and aesthetics |

### 💰 Bill of Materials (BOM)
The system was designed with cost-efficiency in mind.
*   **Total Cost:** ~Rp 1.022.900 (approx. $65 USD).
*   **Optimization:** Used telephone cable and RJ11 connectors to reduce wiring complexity and cost compared to standard ribbon cables.

---

## 🔌 Hardware Schematic & Signal Flow

The system uses a **modular RJ11-based topology**. All logic operates at 5V DC, while the audio output is safely isolated via a relay for 220V AC operation.

### 📌 Pin Assignment (Arduino UNO)
| Component | Arduino Pin | Signal Type | Notes |
| :--- | :--- | :--- | :--- |
| Reset Button | D2 | Digital Input | Internal `INPUT_PULLUP` enabled |
| Reset LED | D3 | Digital Output | Active HIGH |
| Buzzer Relay Control | D4 | Digital Output | Drives NPN transistor base |
| Player 1 Button | D13 | Digital Input | Active LOW |
| Player 1 LED | D12 | Digital Output | Active HIGH |
| Player 2 Button | D11 | Digital Input | Active LOW |
| Player 2 LED | D10 | Digital Output | Active HIGH |
| Player 3 Button | D9 | Digital Input | Active LOW |
| Player 3 LED | D8 | Digital Output | Active HIGH |
| Player 4 Button | D7 | Digital Input | Active LOW |
| Player 4 LED | D6 | Digital Output | Active HIGH |
| VCC | 5V | Power | Logic supply |
| GND | GND | Power | Common ground |

### ⚡ Relay Isolation Circuit (AC-DC Interfacing)
To safely drive a 220V AC buzzer from a 5V microcontroller:
[Arduino D4] ──► [220Ω] ──► [NPN Base]
│
[5V] ──► [Relay Coil] ──► [NPN Collector]
│
[GND] ◄── [1N4007 Diode] ◄──┘ (Flyback protection)
[Relay NO Contact] ──► [220V AC Live] ──► [Buzzer] ──► [Neutral]

- **Galvanic Isolation**: Relay physically separates AC mains from DC logic
- **Signal Integrity**: No voltage spikes or noise coupling into Arduino GPIO
- **Safety Margin**: Relay rated >250V AC / 10A, derated for student use

### 🔗 Modular Connectivity
Player boxes connect to the Reset Box via **RJ11 telephone ports**, enabling:
- Plug-and-play expansion (up to 4 players)
- Easy troubleshooting & component replacement
- Clean cable management with stranded telephone wire

📄 **Full wiring diagram & assembly notes**: [`docs/Laporan_COTTON.pdf`](docs/Laporan_COTTON.pdf)

---

## 💻 Software
The firmware was developed in collaboration with the Main Programmer.
*   **Logic:** State machine implementation for "First-Press" detection.
*   **Debouncing:** Hardware and software debouncing techniques.
*   **File:** [`src/cotton_v09.ino`](src/cotton_v09.ino)

---

## 🧠 Inspiration & References

### "HARTA KARUN" Arduino Quiz Buzzer by Geo (2019)
*   **File:** [`references/Cotton_reference.pdf`](references/Cotton_reference.pdf)
*   **Used as conceptual reference for:** Lockout logic, button polling, state machine design.
*   **Cotton's Original Contributions:**
    *   Modular RJ11-based hardware topology (vs. direct wiring in reference).
    *   Relay-based AC buzzer integration for 220V audio output.
    *   Custom acrylic enclosure design with educational documentation.
    *   BOM optimization for Indonesian school context (~Rp 1.022.900).

*Note: Source of reference file unverified; included for educational transparency.*

---

## 👥 Credits

This project was a collaborative effort by the FCC Team (SMA Negeri 4 Denpasar):

| Name | Role | Contribution |
| :--- | :--- | :--- |
| **Dendy Fajar Kurniawan** | **Main Engineer** | Hardware architecture, relay circuit design, AC-DC power integration, assembly, and testing. |
| **Arasel Bezaleel Thenilo** | **Main Programmer** | Firmware development (Embedded C), algorithm logic, and debugging. |
| Nizar Heyden Susilo | Main Designer | Mechanical design and enclosure layout. |
| Nayaka Alkaesyah Suryanto | Team Leader | Project management, documentation, and planning. |
| Bijan Ramadhan Aditri | Video Editor | Documentation and video editing. |

---

*Project completed in 2024.*
