/*  _______ ______    ____   ______ 
 * |    ___|   __ \  |_   | |__    |
 * |    ___|      <   _|  |_|    __|
 * |___|   |___|__|  |______|______|
 */

#ifndef FR12_LCD_H
#define FR12_LCD_H

#include "defs.h"

#include "../../../../libraries/LiquidCrystal/LiquidCrystal.h"

// Built-in classes
class LiquidCrystal;

// FR 12 classes
class fr12_lcd;
class fr12_config;

// Serialization structs
struct fr12_lcd_serialized;

// Pins
enum {
  fr12_lcd_red = 4,
  fr12_lcd_green = 5,
  fr12_lcd_blue = 6,
  fr12_lcd_rs = 38,
  fr12_lcd_rw = 39,
  fr12_lcd_enable = 40,
  fr12_lcd_d0 = 41,
  fr12_lcd_d1 = 42,
  fr12_lcd_d2 = 43,
  fr12_lcd_d3 = 44,
  fr12_lcd_d4 = 45,
  fr12_lcd_d5 = 46,
  fr12_lcd_d6 = 47,
  fr12_lcd_d7 = 48,
};

// Dimensions and message count
enum {
  fr12_lcd_width = 16,
  fr12_lcd_height = 2
};

// Mesages
struct fr12_lcd_message {
  uint8_t text[fr12_lcd_width * fr12_lcd_height];
  uint8_t r, g, b;
} __attribute__ ((packed));

class fr12_lcd {
public:
  // Constructor
  fr12_lcd();
  
  // Destructor
  virtual ~fr12_lcd();
  
  // Initializes the LCD
  uint8_t begin();
  
  // Configuration
  void configure(fr12_lcd_serialized *ee);
  void serialize(fr12_lcd_serialized *ee);
  
  // Setters
  void set_color(uint8_t r, uint8_t g, uint8_t b);
  void set_message(fr12_lcd_message *message);
  
  // Text wrap
  void print_wrap(char *msg);
  
  // Getters
  fr12_lcd_message *get_message();
private:
  // Puts a wrapped string to the LCD
  void puts_wrap(char *s, size_t len);
  
  // Puts a wrapped character to the LCD
  void putc_wrap(char c);
  
  // Current X and Y positions
  size_t x, y;
  
  // Message information
  uint8_t flags;
  
  // Hardware
  LiquidCrystal *hw;
  
  // Current message
  fr12_lcd_message msg;
};

#endif /* FR12_LCD_H */
