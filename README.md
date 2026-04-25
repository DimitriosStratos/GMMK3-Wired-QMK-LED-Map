GMMK3 100% ANSI Wired - Custom QMK Firmware
This repository contains a specialized QMK Firmware implementation for the Glorious GMMK3 100% ANSI (Wired). It features a complete hardware LED mapping and a custom "Capacitor Decay" reactive lighting engine.

🛠 Technical Overview
Hardware: GMMK3 100% ANSI Wired

MCU: WB32FQ

LED Driver: 2x AW20216S (Constant Current LED Controllers)

Key Features: Advanced Zonal RGB, Custom Reactive Logic, and Fixed Hardware Indicators.

I've updated the config.c with **Debounce 5ms, Polling rate 500ms,** and some other, see in the **config.h** file inside keymap/via (if you want 1000ms change the USB_POLLING_INTERVAL_MS FROM 2 TO **1**

🌟 Custom Features
1. "Capacitor Decay" Reactive Effect
Inspired by analog circuit behavior, this firmware implements a custom reactive algorithm. Each keypress "charges" the LED, which then follows a simulated discharge curve. The decay rate is tuned to provide a smooth, organic fade-out.

2. Advanced RGB Zonal Map
The layout is logically partitioned into functional zones:

Core Alpha Matrix: Hermes Green.

Esc Key: Solid Red (ID 0).

F-Keys & Numpad: Cyan with White Reactive.

Navigation Cluster: Purple with White Reactive.

Arrow Keys: Deep Yellow with White Reactive.

Win & Fn Keys: Static White with Electric Blue Reactive for high contrast.

Side Strips: 20-LED Red-to-Orange Gradient (IDs 104-123).

Glorious Logo: Deep Orange (ID 124).

3. Integrated Indicators
The Caps Lock, Num Lock, and Scroll Lock keys function as status indicators. When engaged, they override the zonal color with a Solid Red signal, ensuring the keyboard state is visible at a glance.

🔍 Hardware Mapping Discovery
This project successfully mapped the **GMMK3's internal LED daisy-chain for the first time:**

ID 0: Escape Key

IDs 104-113: Left Side Light Strip (SLED1-SLED10)

IDs 114-123: Right Side Light Strip (SLED11-SLED20)

ID 124: Logo LED (adjacent to the Knob)

🚀 Build Instructions
Compilation
Move the keymap folder to your QMK source tree: keyboards/gmmk/gmmk3/p100/ansi/keymaps/.

Run a clean build to avoid object file conflicts:

Bash
qmk clean -kb gmmk/gmmk3/p100/ansi
Compile the project:

Bash
qmk compile -kb gmmk/gmmk3/p100/ansi -km <your_keymap_name>
Flashing
Use QMK Toolbox to flash the resulting .bin file.

To enter Bootloader Mode, hold the Esc key while plugging in the USB cable.

👨‍💻 Engineering Notes
The implementation leverages rgb_matrix_indicators_advanced_user for real-time per-LED color manipulation. Special care was taken to manage the AW20216S driver limits and ensuring the WB32FQ MCU handles the matrix scans and LED updates with minimal latency. **Note :if the new code is flashed to enter bootloader press Fn+Pause**

## 🤝 Acknowledgments
Reverse-engineered by **Dimitris** with the help of **Hermes (AI Assistant)**.

⚡Or you can directry flash the **.bin file** with the **QMK Toolbox**, with the Keymap Features stated above , **which are in the BinFiles directory.**
