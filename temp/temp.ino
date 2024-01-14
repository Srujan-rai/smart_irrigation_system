#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET -1 // Reset pin # (or -1 if not used)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  // Initialize with the I2C address of your OLED (typically 0x3D or 0x3C)
  if(!display.begin(SSD1306_I2C_ADDRESS, OLED_RESET)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;);
  }

  // Clear the display buffer
  display.clearDisplay();

  // Set text size and color
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  // Display some text
  display.setCursor(0, 0);
  display.println(F("Hello, OLED!"));
  display.display();
}

void loop() {
  // Nothing to do here
}
