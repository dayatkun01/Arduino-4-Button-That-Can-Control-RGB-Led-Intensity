# Arduino-RGB-LED-Control-With-Buttons

Hi, my name is Rahmat Hidayat. I code for fun and sometimes share my code here so I can reuse it later.  
Feel free to use or modify this project. If you need help setting it up, follow this tutorial.

## Requirements
- Arduino Uno / Nano / Mega
- RGB LED (common cathode)
- 3 Resistors (220Ω–330Ω recommended)
- 4 Push Buttons
- Breadboard
- ~15 Jumper Wires (Male to Male)

## Wiring

### Buttons
| Button | Arduino Pin |
|--------|-------------|
| Red    | 2           |
| Green  | 3           |
| Blue   | 4           |
| Reset  | 5           |

> All buttons use `INPUT_PULLUP`, so connect one side to GND.

### RGB LED
| LED Color | Arduino Pin | Via Resistor |
|-----------|-------------|--------------|
| Red       | 9           | 220Ω         |
| Green     | 10          | 220Ω         |
| Blue      | 11          | 220Ω         |

> Common cathode (longest leg) to GND.

## How to Use
1. Download or copy the code below.
2. Open it with Arduino IDE.
3. Select your board (`Tools -> Board -> Arduino Uno`) and port (`Tools -> Port`).
4. Upload.
5. Press the buttons:
   - Button on Pin 2 ➔ Increases RED.
   - Button on Pin 3 ➔ Increases GREEN.
   - Button on Pin 4 ➔ Increases BLUE.
   - Button on Pin 5 ➔ Resets all to 0.
6. Holding a button speeds up the increment due to streak detection.

## How it Works
- Each button press increases the brightness of its color by `+1`.
- When the value exceeds `255`, it wraps around to `0`.
- Holding a button speeds up the increment (debounce + streak logic).
- Serial Monitor prints current RGB state at `250000` baud.

## Code Highlights
- Uses `millis()` for debounce timing, with different delays for first press vs holding.
- `ledRGBaddRGB()` handles adding and wrapping the color values.
- `ledRGBresetRGB()` resets all colors to 0.

``cpp
void ledRGBaddRGB(int red, int green, int blue) { /* add & wrap values */ }
void ledRGBresetRGB() { /* reset RGB */ }``

## License
MIT

Thanks for reading!
