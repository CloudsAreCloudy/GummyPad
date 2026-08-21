# GummyPad
An ESP32 C3 SuperMini Macropad with 12 Keys, an OLED Display, Rotary Encoder, and RGB LEDs!

<img width="808" height="659" alt="Screenshot 2026-08-20 075827" src="https://github.com/user-attachments/assets/5c3d1898-fd50-4b3f-88b3-ef05b684f935" />


## Bill of Materials (BOM)
| Part | Price (USD) | Quantity | Where to find it |
| ---- | ----- | -------- | ---------------- |
| M3x4mmx4.2mm Heat Set Brass Inserts | 0.45$ | 10 | [Purchase Here](https://quartzcomponents.com/products/m3-x-4mm-brass-heat-set-threaded-round-insert-nut-10-pcs?variant=45107588169962) |
| 100nF Capacitors | 0.32$ | 9 | [Purchase Here](https://quartzcomponents.com/products/100nf-0-1uf-50v-capacitor-0805-smd-pack-of-20-piece?variant=43456389218538) |
| SSD1306 0.96 Inch OLED Display | 1.51$ | 1 | [Purchase Here](https://quartzcomponents.com/products/oled-display-0-96-inch-i2c-interface-4-pin-blue-ssd1306?variant=33049183060103) |
| 3.7V 2000mAH Li-Po Battery | 2.58$ | 1 | [Purchase Here](https://quartzcomponents.com/products/3-7v-2000mah-li-po-rechargeable-battery-523450?variant=44853322449130) |
| TP4056 Charging Module | 0.17$ | 1 | [Purchase Here](https://quartzcomponents.com/products/tp4056-battery-charging-protection-module-type-c?variant=39545849774264) |
| 1N148 High-speed Diode | 0.38$ | 12 | [Purchase Here](https://quartzcomponents.com/products/1n4148-zener-diode?variant=42817413546218) |
| KY-040 Rotary Encoder | 0.49$ | 1 | [Purchase Here](https://quartzcomponents.com/products/rotary-encoder-module-ky-040?variant=39545890963640) |
| WS2821B 5050 LED Light | 0.94$ | 9 | [Purchase Here](https://probots.co.in/ws2812b-rgb-led-chip-5050-smd-white-addressable-intelligent.html) |
| M3 x 6mm Screws | 0.13$ | 10 | [Purchase Here](https://onlyscrews.in/products/m3-x-6mm-phillips-csk-ss-304-screw-dia-3mm-length-6mm?variant=52107976802617)
| M2.5 x 4mm Screws | 0.03$ | 2 | [Purchase Here](https://onlyscrews.in/products/m2-5-x-4mm-phillips-csk-ss-304-screw-dia-2-5mm-length-4mm?variant=51156921123129) |
| Keyboard Switches | 1.57$ | 12 | [Purchase Here](https://meckeys.com/shop/accessories/keyboard-accessories/key-switches/regular-switch-3pin/?attribute_pa_key-switches=regular-black) |
| ESP32-C3 Super Mini | 2.86$ | 1 | [Purchase Here](https://quartzcomponents.com/products/esp32-c3-super-mini-development-board-with-soldered-headers-hw-466ab?variant=45727228887274)
| PCB from JLCPCB | 2.18$ | 5 (MOQ) | [Purchase Here](JLCPCB.com) |
| 3D Printing (Self) | 0$ | 1 | NA |
| Shipping | 2.83$ | NA | NA |
| **Total** | 16.44$ | | |

## How can I build it?
 **Required Libraries:**
- ADAFRUIT_SSD1306
- KMK_Firmware

All you need to do is solder the Capacitors, Display, TP4056 Module, Battery, Diodes, Switches, Rotary Encoder, and LEDs onto the PCB, 3D Print the case and use a soldering iron to push the heat set inserts into place (M2.5 screws intentionally dont have heat set inserts), flash the ESP32-C3 Super Mini with CircuitPython, Load the code.py file into the root along with the KMK files and the specified libraries, and you should be good to go!

<img width="1625" height="694" alt="Screenshot 2026-08-20 080231" src="https://github.com/user-attachments/assets/1d301e5c-39aa-4153-8918-4dd3c7c4d402" />
<img width="1097" height="563" alt="image" src="https://github.com/user-attachments/assets/09a99863-dfe0-454c-b6fd-a1035ca38944" />

