// Evan Widloski - 2018-12-25
// Chaos Generator

#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library for ST7735
#include <Adafruit_ST7789.h> // Hardware-specific library for ST7789

#define TFT_CS        2 // chip select
#define TFT_RST       6 // Display reset
#define TFT_DC        5 // Display data/command select
#define TFT_BACKLIGHT  7 // Display backlight pin


#define TFT_MOSI 4  // Data out
#define TFT_SCLK 3  // Clock out
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_MOSI, TFT_SCLK, TFT_RST);

int16_t prev_x, prev_y, x, y = 0;
int16_t count = 0;

void setup(void) {
  Serial.begin(9600);

  tft.fillScreen(ST77XX_WHITE);

  tft.initR(INITR_BLACKTAB);

  tft.setTextColor(ST77XX_BLUE);
  tft.setCursor(20, 80);
  tft.setTextWrap(true);
  tft.print("Chaos Generator");
  delay(1000);
}

void loop() {
  tft.fillScreen(ST77XX_WHITE);

  while (count < 10000){
    prev_x = x;
    prev_y = y;
    y = analogRead(1) / 6.4;
    x = analogRead(2) / 3 - 80;
    tft.drawLine(x, y, prev_x, prev_y, ST77XX_BLACK);
    count += 1;
//    Serial.print(y);
//    Serial.print('\n'); 
  }
  
  count = 0;

}



