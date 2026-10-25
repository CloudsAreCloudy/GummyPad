#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoPixel.h>
#include <RotaryEncoder.h>
#include <Wire.h>
#include <NimBleKeyboard.h>
#include <Keypad.h>

#define PIN_NEOPIXEL 10
#define NUM_NEOPIXEL 9
#define ENCODER_A 2
#define ENCODER_B 4
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define OLED_RESET -1
#define SCREEN_ADDRESS 0x3C
#define ENCODER_SW 1
#define NUM_LAYERS 4

const byte ROWS = 4;
const byte COLS = 3;
const unsigned long DOUBLE_TAP_MS = 300;
unsigned long lastLayerTap = 0;

const char* layerNames[NUM_LAYERS] = {"Multimedia", "Soundboard", "Emojis", "Applications"};
uint8_t layerMods[NUM_LAYERS] = { 0, KEY_LEFT_SHIFT, KEY_LEFT_CTRL, KEY_LEFT_ALT };
const char ids[] = "147*2580369#";

bool showingLayer = false;
unsigned long layerShownAt = 0;
unsigned long lastScrollStep = 0;
int scrollX = SCREEN_WIDTH;

char keys[COLS][ROWS] = {
  {'1', '4', '7', '*'},
  {'2', '5', '8', '0'},
  {'3', '6', '9', '#'},
};

byte rowPins[ROWS] = {3, 7, 5, 6};
byte colPins[COLS] = {21, 20, 0};
bool lastSw = HIGH;
bool encDown = false;
bool chordUsed = false;
bool brightnessMode = false;
unsigned long lastSwChange = 0;
int ledBrightness = 255;
int newBrightness = 0;

const unsigned long SOFT_SLEEP_AFTER_MIN = 3;
const unsigned long DEEP_SLEEP_AFTER_MIN = 10; // 0 is never sleep
const unsigned long BRIGHTNESS_MULT = 15;
unsigned long lastBrightnessActivity = 0;
const unsigned long BRIGHTNESS_TIMEOUT = 5000;

unsigned long lastActivity = 0;
bool softSleeping = false;

Keypad keypad = Keypad(makeKeymap(keys), colPins, rowPins, COLS, ROWS);
BleKeyboard bleKeyboard("Sulaiman Macro", "Sulaiman", 100);

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUM_NEOPIXEL, PIN_NEOPIXEL, NEO_GRB + NEO_KHZ800);
RotaryEncoder encoder(ENCODER_A, ENCODER_B, RotaryEncoder::LatchMode::FOUR3);

void setLeds() {
  pixels.setBrightness(ledBrightness);
  pixels.setPixelColor(0, pixels.Color(0,0,0));
  pixels.setPixelColor(1, pixels.Color(255,0,0));
  pixels.setPixelColor(2, pixels.Color(255,0,0));
  pixels.setPixelColor(3,pixels.Color(255,0,0));
  pixels.setPixelColor(4, pixels.Color(255,0,0));
  pixels.setPixelColor(5,pixels.Color(255,0,0));
  pixels.setPixelColor(6, pixels.Color(255,0,0));
  pixels.setPixelColor(7, pixels.Color(255,0,0));
  pixels.setPixelColor(8, pixels.Color(255,0,0));
  pixels.show();
  Serial.println("Ran setLeds!");
}

void wakeFromSoftSleep() {
  softSleeping = false;
  setCpuFrequencyMhz(160);
  display.ssd1306_command(SSD1306_DISPLAYON);
  showBitmap();
  setLeds();
}

void noteActivity() {
  lastActivity = millis();
  if (softSleeping) {
   wakeFromSoftSleep();
  }
}

void enterSoftSleep() {
  softSleeping = true;
  showingLayer = false;
  pixels.clear();
  pixels.show();
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  setCpuFrequencyMhz(80);
}

void enterDeepSleep() {
  pixels.clear();
  pixels.show();
  display.ssd1306_command(SSD1306_DISPLAYOFF);
  uint64_t mask = (1ULL << ENCODER_A) | (1ULL << ENCODER_B) | (1ULL << ENCODER_SW);
  esp_deep_sleep_enable_gpio_wakeup(mask, ESP_GPIO_WAKEUP_GPIO_LOW);
  esp_deep_sleep_start();
}

void checkPosition() { encoder.tick(); }
int encoder_pos = 0;
int currentLayer = 0;
int16_t textW = 0;

const uint8_t gummyBearBitmap[512] PROGMEM = {
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x83, 0xFE, 0x0F, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x78, 0x00, 0xF7, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xE7, 0xFF, 0x19, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x87, 0xFF, 0x09, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0x00, 0x00, 0x00, 0x00, 0x02, 0x8F, 0xFF, 0xC9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x0C, 0x80, 0x00, 0x00, 0x00, 0x02, 0x9F, 0xFF, 0xE9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x08, 0x80, 0x0A, 0x14, 0x04, 0x02, 0x7C, 0xFD, 0xF1, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x08, 0x19, 0xA5, 0x4A, 0x44, 0x03, 0x7B, 0x7A, 0xF7, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x99, 0xA5, 0x4A, 0x4C, 0x03, 0x7C, 0x79, 0xF7, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x09, 0x99, 0xA5, 0x4A, 0x28, 0x03, 0x7F, 0x87, 0xF7, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x08, 0x99, 0x25, 0x4A, 0x28, 0x03, 0x7F, 0xA7, 0xF7, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x08, 0x99, 0x25, 0x4A, 0x30, 0x03, 0x7F, 0xDF, 0xF7, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x07, 0x0F, 0x25, 0x4A, 0x10, 0x03, 0x9F, 0x7B, 0xEF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x03, 0x8F, 0x87, 0xCF, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x20, 0x02, 0x67, 0xFF, 0x11, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0xF9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x1E, 0x00, 0x00, 0x00, 0x01, 0xE3, 0xFE, 0x1E, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x11, 0x00, 0x06, 0x00, 0x01, 0xFC, 0xFD, 0xFE, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x11, 0x8C, 0x1E, 0x00, 0x01, 0xFC, 0xFD, 0xFE, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x11, 0x92, 0x26, 0x00, 0x01, 0xFF, 0x7B, 0xFE, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x1F, 0x02, 0x66, 0x00, 0x02, 0xFC, 0xFD, 0xF9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x1C, 0x1F, 0x66, 0x00, 0x03, 0x18, 0xFC, 0xE7, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x23, 0x66, 0x00, 0x03, 0x03, 0xFE, 0x07, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x23, 0x26, 0x44, 0x82, 0x7F, 0xFF, 0xF1, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x10, 0x1F, 0x3E, 0x6D, 0x82, 0xF8, 0xFC, 0xF9, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x82, 0xFF, 0x7B, 0xF9, 0x40, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x28, 0x82, 0xFF, 0x7B, 0xF9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x11, 0xC2, 0xFF, 0xFF, 0xF9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xFF, 0xFF, 0xF9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xFF, 0x03, 0xF9, 0x00, 0x00, 0x00, 0x00,
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x03, 0x7C, 0x21, 0xF7, 0x00, 0x00, 0x00, 0x00
};

void showBitmap() {
  display.clearDisplay();
  display.drawBitmap(0, 0, gummyBearBitmap, 128, 32, SSD1306_WHITE);
  display.display();
}

void startLayerDisplay() {
  display.setTextSize(2);
  display.setTextWrap(false);
  display.setTextColor(SSD1306_WHITE);

  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(layerNames[currentLayer], 0, 0, &x1, &y1, &w, &h);
  textW = w;

  scrollX = SCREEN_WIDTH;
  layerShownAt = millis();
  showingLayer = true;
}

void startBrightnessDisplay() {
  display.setTextSize(3);
  display.setTextWrap(false);
  display.setTextColor(SSD1306_WHITE);

  int brightnessTextMath = ledBrightness/2.55;
  char brightnessText[4];
  sprintf(brightnessText, "%d%%", brightnessTextMath);
  Serial.println(brightnessText);
  int16_t x1, y1;
  uint16_t w, h;
  display.getTextBounds(brightnessText, 0, 0, &x1, &y1, &w, &h);
  display.setCursor((SCREEN_WIDTH - w) / 2, (SCREEN_HEIGHT - h) / 2);
  display.print(brightnessText);
}


void updateLayerDisplay() {
  if (!showingLayer) return;        // nothing to do

  // 5 seconds up? go back to the bear
  if (millis() - layerShownAt > 5000) {
    showingLayer = false;
    showBitmap();
    return;
  }

  // otherwise move the text every 30ms
  if (millis() - lastScrollStep >= 30) {
    lastScrollStep = millis();
    display.clearDisplay();
    display.setCursor(scrollX, 8);
    display.print(layerNames[currentLayer]);
    display.display();

    scrollX -= 2;
    if (scrollX < -textW) scrollX = SCREEN_WIDTH;   // fully off the left? loop around
  }
}

void setup() {
  Serial.begin(115200);
  Serial.println("Starting BLE...");
  delay(500);

  bleKeyboard.begin();
  pixels.begin();
  setLeds();

  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }
  delay(2000);
  display.clearDisplay();
  display.display();
  display.drawBitmap(0, 0, gummyBearBitmap, 128, 32, SSD1306_WHITE);
  display.display();

  Serial.println("ESP32 C3 Mini Macropad");

  pinMode(ENCODER_A, INPUT_PULLUP);
  pinMode(ENCODER_B, INPUT_PULLUP);
  pinMode(ENCODER_SW, INPUT_PULLUP);

  attachInterrupt(digitalPinToInterrupt(ENCODER_A), checkPosition, CHANGE);
  attachInterrupt(digitalPinToInterrupt(ENCODER_B), checkPosition, CHANGE);
}


void loop() {

  // --- ROTARY ENCODER SETUP ---

  encoder.tick();
  int newPos = encoder.getPosition();

  if (encoder_pos != newPos) {
    noteActivity();
    int steps = newPos - encoder_pos;

    if (brightnessMode) {
      newBrightness = ledBrightness + steps * BRIGHTNESS_MULT;
      ledBrightness = constrain(newBrightness, 0, 255);
      lastBrightnessActivity = millis();
      display.clearDisplay();
      startBrightnessDisplay();
      display.display();
      pixels.clear();
      delay(100);
      setLeds();
    } else if (bleKeyboard.isConnected()) {
      for (int i = 0; i < abs(steps); i++) {
        bleKeyboard.write(steps > 0 ? KEY_MEDIA_VOLUME_UP : KEY_MEDIA_VOLUME_DOWN);
      }
    }
    encoder_pos = newPos;
  }

  bool sw = digitalRead(ENCODER_SW);
  if (sw != lastSw && millis() - lastSwChange > 20) {
    noteActivity();
    lastSwChange = millis();
    lastSw = sw;
    if (sw == LOW) {
      encDown = true;
      chordUsed = false;
    } else {
      encDown = false;
      if (!chordUsed && bleKeyboard.isConnected()) {
        bleKeyboard.write(KEY_MEDIA_PLAY_PAUSE);
      }
    }
  }

// --- Keypress Setup ---
  if (keypad.getKeys()) {
    for (int i = 0; i < LIST_MAX; i++) {
      if (keypad.key[i].stateChanged && keypad.key[i].kstate == PRESSED) {
        char keypress = keypad.key[i].kchar;
        noteActivity();

        if (encDown && keypress == '1') {
          currentLayer = (currentLayer + 1) % NUM_LAYERS;
          startLayerDisplay();
          Serial.print("Current Layer:");
          Serial.println(currentLayer);
          chordUsed = true;
        } else if (encDown && keypress == '2') {
            brightnessMode = true;
            chordUsed = true;
            lastBrightnessActivity = millis();
        } else {
          const char* p = strchr(ids, keypress);
          if (p != NULL && bleKeyboard.isConnected()) {
            int index = p - ids;                  // 0-11
            uint8_t mod = layerMods[currentLayer];
            if (mod) bleKeyboard.press(mod);      // modifier first (layer 0 has none)
            bleKeyboard.press(KEY_F13 + index);   // then the F-key
            delay(10);
            bleKeyboard.releaseAll();
          }
        }
      }
    }
  }

  if(brightnessMode && millis() - lastBrightnessActivity >= BRIGHTNESS_TIMEOUT) {
    brightnessMode = false;
    display.clearDisplay();
    showBitmap();
    display.display();
  }

  updateLayerDisplay();
  unsigned long idleMs = millis() - lastActivity;
  if (!softSleeping && idleMs > SOFT_SLEEP_AFTER_MIN * 60000UL) {
    enterSoftSleep();
  }
  if (softSleeping) {
    if (DEEP_SLEEP_AFTER_MIN && idleMs > DEEP_SLEEP_AFTER_MIN * 60000UL) {
      enterDeepSleep();
    }
    delay(10);                       // lets the CPU idle between scans
  }
}
