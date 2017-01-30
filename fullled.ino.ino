//############################################################################################################################################################
// GLEDIATOR                                                                                                                         #
//############################################################################################################################################################
//Change this to YOUR matrix size!!
#define Num_Pixels 320
//Serial Data Output (Arduino-Mega Pin 6)
#define SDO_Port          PORTH
#define SDO_DDR           DDRH
#define SDO_Pin           3
//Serial Data Clock (Arduino-Mega Pin 7)
#define CLK_Port          PORTH
#define CLK_DDR           DDRH
#define CLK_Pin           4
#define Set_CLK_Low       CLK_Port     &=     ~(1 << CLK_Pin)
#define Set_CLK_High      CLK_Port     |=      (1 << CLK_Pin)
#define Set_CLK_Output    CLK_DDR      |=      (1 << CLK_Pin)
#define Set_SDO_Low       SDO_Port     &=     ~(1 << SDO_Pin)
#define Set_SDO_High      SDO_Port     |=      (1 << SDO_Pin)
#define Set_SDO_Output    SDO_DDR      |=      (1 << SDO_Pin)
#define CMD_NEW_DATA 1
unsigned char display_buffer[Num_Pixels * 3];
static unsigned char *ptr;
static unsigned int pos = 0;
volatile boolean go = 0;
//############################################################################################################################################################
// GLEDIATOR                                                                                                                          #
//############################################################################################################################################################

//############################################################################################################################################################
// IR                                                                                                                        #
//############################################################################################################################################################
#include <IRremote.h>
//Define Receiver
IRrecv irrecv(11);
decode_results results;
//############################################################################################################################################################
// IR                                                                                                                        #
//############################################################################################################################################################

//############################################################################################################################################################
// Menu                                                                                                                       #
//############################################################################################################################################################
//define menu
long menu;
//############################################################################################################################################################
// Menu                                                                                                                       #
//############################################################################################################################################################


//############################################################################################################################################################
// FASTLED                                                                                                                     #
//############################################################################################################################################################
#include "FastLED.h"
#define NUM_LEDS 320
#define DATA_PIN 6
#define CLOCK_PIN 7
CRGB leds[NUM_LEDS];
#define COLOR_ORDER BGR
#define MAX_BRIGHTNESS 20
#define BRIGHTNESS  5  
uint8_t gHue = 0; // rotating "base color" used by many of the patterns
//Define beatsin Variables
float rsin;
float gsin;
float bsin;
//############################################################################################################################################################
// FASTLED                                                                                                                    #
//############################################################################################################################################################

//############################################################################################################################################################
// FUNKY                                                                                                                     #
//############################################################################################################################################################
// enter your custom matrix size if it is NOT a 16*16 and
// check in that case the setup part and
// RenderCustomMatrix() and
// ShowFrame() for more comments
const uint8_t CUSTOM_WIDTH  = 16;
const uint8_t CUSTOM_HEIGHT = 20;

// MSGEQ7 wiring on spectrum analyser shield
#define MSGEQ7_STROBE_PIN 4
#define MSGEQ7_RESET_PIN  5
#define AUDIO_LEFT_PIN    0
#define AUDIO_RIGHT_PIN   1


// all 2D effects will be calculated in this matrix size
// do not touch
const uint8_t WIDTH  = 16;
const uint8_t HEIGHT = 16;

// number of LEDs based on fixed calculation matrix size
// do not touch
//#define NUM_LEDS (WIDTH * HEIGHT)

// the rendering buffer (16*16)
// do not touch
//CRGB leds[NUM_LEDS];

// your display buffer for your not 16*16 setup
//CRGB leds2[CUSTOM_HEIGHT * CUSTOM_WIDTH];
CRGB leds2[320];
// noise stuff
uint16_t speed = 10;
uint16_t scale = 50;
uint16_t scale2 = 30;
const uint8_t kMatrixWidth = 16;
const uint8_t kMatrixHeight = 20;
#define MAX_DIMENSION ((kMatrixWidth>kMatrixHeight) ? kMatrixWidth : kMatrixHeight)
uint8_t noise[MAX_DIMENSION][MAX_DIMENSION];
uint8_t noise2[MAX_DIMENSION][MAX_DIMENSION];
static uint16_t x;
static uint16_t y;
static uint16_t z;
static uint16_t x2;
static uint16_t y2;
static uint16_t z2;
//palette stuff
CRGBPalette16 currentPalette;
TBlendType    currentBlending;
extern CRGBPalette16 myRedWhiteBluePalette;
extern const TProgmemPalette16 myRedWhiteBluePalette_p PROGMEM;

// the oscillators: linear ramps 0-255
// modified only by MoveOscillators()
byte osci[4]; 

// sin8(osci) swinging between 0 - 15
// modified only by MoveOscillators()
byte p[4];

// storage of the 7 10Bit (0-1023) audio band values
// modified only by AudioRead()
int left[7];    
int right[7];
//############################################################################################################################################################
// FUNKY                                                                                                                  #
//############################################################################################################################################################



