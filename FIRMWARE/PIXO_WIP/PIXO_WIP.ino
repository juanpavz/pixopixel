/*
   PIXO Pixel WIP Test Program
   This program is a work in progress but will let you test your LED matrix if it is working or not.
   Try out the various Demos and images in the image.h file.

   Many libraries from Adafruit are needed and can be seen below.

*/

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_DotStarMatrix.h>
#include <Adafruit_DotStar.h>
#include <Fonts/TomThumb.h>
#include "image.h"

#define DATAPIN    19
#define CLOCKPIN   18

int mario[256][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {248, 171, 0}, {248, 171, 0}, {112, 104, 0}, {248, 171, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {248, 171, 0}, {112, 104, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {112, 104, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {248, 171, 0}, {112, 104, 0}, {112, 104, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {112, 104, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {216, 0, 0}, {112, 104, 0}, {112, 104, 0}, {216, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {216, 0, 0}, {112, 104, 0}, {112, 104, 0}, {216, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {248, 171, 0}, {248, 171, 0}, {112, 104, 0}, {216, 0, 0}, {248, 171, 0}, {216, 0, 0}, {216, 0, 0}, {248, 171, 0}, {216, 0, 0}, {112, 104, 0}, {248, 171, 0}, {248, 171, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {248, 171, 0}, {248, 171, 0}, {248, 171, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {248, 171, 0}, {248, 171, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {248, 171, 0}, {248, 171, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {0, 0, 0}, {0, 0, 0}, {216, 0, 0}, {216, 0, 0}, {216, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {0, 0, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {112, 104, 0}, {0, 0, 0}, {0, 0, 0}};


#define BRIGHTNESS 30

// MATRIX DECLARATION:
Adafruit_DotStarMatrix pixo = Adafruit_DotStarMatrix(
                                  16, 16, DATAPIN, CLOCKPIN,
                                  DS_MATRIX_BOTTOM     + DS_MATRIX_LEFT +
                                  DS_MATRIX_ROWS + DS_MATRIX_PROGRESSIVE,
                                  DOTSTAR_BGR);

const uint16_t primaryColors[] = {
  pixo.Color(100, 0, 0), pixo.Color(0, 100, 0), pixo.Color(0, 0, 100)
};


void setup() {
  Serial.begin(115200);

  // uncomment to have wait
  //while (!Serial) delay(500);

  pixo.begin();
  pixo.setBrightness(BRIGHTNESS);
  for (byte i = 0; i < 3; i++) {
    pixo.fillScreen(primaryColors[i]);
    pixo.show();
    delay(500);
    pixo.fillScreen(0);
    pixo.show();
  }
}

int x = pixo.width();
int pass = 0;

void loop() {
  pixo.setBrightness(BRIGHTNESS);
  //while(1){
  //SinglePix(); 
  //  RandomPix();
  //}
  notification();

}

void SinglePix() {
  for (int x = 0; x < 256; x++) {
    pixo.setPixelColor(x, 255, 255, 255);
    delay(10);
    pixo.show();
    delay(200);
  }
}

void RandomPix() {
  randomSeed(A1);
  int x = random(0, 256);
  pixo.fillScreen(0);
  pixo.setPixelColor(x, 255, 255, 255);
  pixo.show();
  delay(50);
}

void notification() {
  for (int j = 15; j >= 0; j--) {
    pixo.fillScreen(0);
    for (int i = 0; i < 256; i++) {
      pixo.setPixelColor(i + (j * 16), mario[i][0], mario[i][1], mario[i][2]);
      //Serial.println(i);
      //delay(1);
    }
    pixo.show();
    delay(15);
  }
  delay(1000);
  for (int j = 0; j >= -16; j--) {
    pixo.fillScreen(0);
    for (int i = 0; i < 256; i++) {
      pixo.setPixelColor(i + (j * 16), mario[i][0], mario[i][1], mario[i][2]);
    }
    pixo.show();
    delay(15);
  }
  delay(1000);
  pixo.fillScreen(0);
  pixo.show();
}

float ballx = 5;
float bally = 5;
float paddle1, paddle2 = 3;
float ballvx = -0.3;
float ballvy = 0.1;


