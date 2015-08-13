#include <PololuLedStrip.h>
#include "common_defs.h"

typedef class Display_Type {
  public:
    PololuLedStrip<LED_PIN> ledStrip;
    rgb_color Screen_Colors[LED_COUNT];
    
    Display_Type(rgb_color);
    void Clear_Screen();
    void Update();
    
} Display_Type;

Display_Type::Display_Type(rgb_color a)
{
  for (byte ii = 0; ii < LED_COUNT; ii ++)
    Screen_Colors[ii] = a;
    
  ledStrip.write(Screen_Colors, LED_COUNT);
}

void Display_Type::Update()
{
  ledStrip.write(Screen_Colors, LED_COUNT);
}

void Display_Type::Clear_Screen()
{
  for (byte ii = 0; ii < LED_COUNT; ii ++)
    Screen_Colors[ii] = (rgb_color){0,0,0};
    
  ledStrip.write(Screen_Colors, LED_COUNT);
}
