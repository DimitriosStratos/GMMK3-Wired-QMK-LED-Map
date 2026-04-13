# Glorious GMMK3 Wired - Custom QMK LED Mapping Guide (ANSI)

This repository contains the reverse-engineered LED ID mapping and a custom `keymap.c` for the **Glorious GMMK3 Wired** mechanical keyboard (**ANSI Layout**). 

Official documentation for the GMMK3 Wired LED IDs in QMK is currently limited. This guide is the result of extensive testing and reverse engineering to unlock the full potential of the keyboard's RGB matrix.

> [!IMPORTANT]  
> This mapping and code were developed and tested on the **ANSI (US) layout**. If you are using an ISO (EU) model, some LED IDs might differ.

## 🛠 The LED ID Map

| Component | LED ID Range | Orientation / Note |
| :--- | :--- | :--- |
| **Escape Key** | **0** | Requires "Override/Bombing" method (see below). |
| **Main Keys** | **1 - 104** | Standard Matrix keys. |
| **Left Side Strip** | **105 - 114** | **Top-to-Bottom** (105 is the Top-most LED). |
| **Right Side Strip** | **115 - 124** | **Bottom-to-Top** (115 is the Bottom-most LED). |
| **Rotary Knob** | **125** | Electrically follows the Right Strip. |
| **Ghost/Buffer IDs** | **126+** | Keep these **OFF** (RGB 0,0,0) to avoid artifacts. |

## ⚠️ Known Issues / Work in Progress
* **The "Rebel" LED 105:** The top-most LED of the left side strip (ID 105) consistently remains White, ignoring custom color/gradient commands. It appears this LED is hardcoded in the hardware/firmware as a status indicator that overrides QMK matrix commands.

## ✨ Keymap Features
The included `keymap.c` is pre-configured with a custom "Cockpit" setup:
* **Dual-Side Gradients:** Fire-orange to deep-red fades.
* **Telemetry Style Right Strip:** A unique Red-Yellow-Green gradient.
* **Reactive Effects:** Advanced "Capacitor" style typing effects.
* **Status Indicators:** Custom colors for Caps Lock, Num Lock, and Scroll Lock.

## ⚡ Bootloader Mode (Flashing)
To flash this custom firmware, you must first enter Bootloader mode (refer to Glorious factory instructions for the initial flash).

**Once this custom firmware is flashed**, the command to re-enter Bootloader mode for any future updates is:
* **FN + PAUSE**
* This will trigger the `QK_BOOT` command, allowing you to use QMK Toolbox or the CLI to upload a new `.bin` file.

## 💡 Key Findings

### 1. The "Bombing" Method (Priority Override)
We discovered that the **Esc key (ID 0)** and the **Rotary Knob (ID 125)** are often overwritten by internal firmware indicators. To force custom colors, use the `rgb_matrix_set_color` command **outside and after** the main LED loop.

### 2. Side Strip Asymmetry
The GMMK3 Wired uses inverted wiring for the side strips:
* **Left side** counts downwards (105 at the top).
* **Right side** counts upwards (115 at the bottom).

### 3. Ghost IDs
IDs 126 and above do not correspond to physical keys. Lighting them can cause color "bleeding" or glitches on keys like F12. Always set these to `(0,0,0)`.

## 🚀 Getting Started
1. Copy the provided `keymap.c` into your QMK environment.
2. Compile your firmware.
3. Flash your device. For all subsequent flashes, use the **FN + PAUSE** shortcut provided in this keymap.

## 🤝 Acknowledgments
Reverse-engineered by **Dimitris** with the help of **Hermes (AI Assistant)**.
