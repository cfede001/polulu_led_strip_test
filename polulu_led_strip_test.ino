#include <PololuLedStrip.h>
#include "player_type.h"
#include "common_defs.h"
#include "display_type.h"

// Create an ledStrip object and specify the pin it will use.


// Create a buffer for holding the colors (3 bytes per color).

Display_Type Display((rgb_color){0,0,0});
Player_Type Player_1(0, (rgb_color){255, 255, 255});
Player_Type Player_2(0, (rgb_color){255, 0, 0});
Player_Type Player_3(0, (rgb_color){0, 255, 0});
Player_Type Player_4(0, (rgb_color){0, 0, 255});

void setup()
{
  randomSeed(analogRead(0));
}



void loop()
{
  // Clear Screen
  Display.Clear_Screen();
    
  // Update Player 1 position
  if ((random(50) % 2) == 1)
    Player_1.Move_Left();
  else
    Player_1.Move_Right();
    
  
  if (Player_1.Get_Pos() >= LED_COUNT)
  {
    Player_1.Set_Pos(0);
  }
  
  // Determine other player position
  Player_2.Set_Pos((Player_1.Get_Pos() + LED_COUNT / (random(50) % 2) ) % LED_COUNT);
  Player_3.Set_Pos((Player_2.Get_Pos() + LED_COUNT / (random(50) % 2) ) % LED_COUNT);
  Player_4.Set_Pos((Player_3.Get_Pos() + LED_COUNT / (random(50) % 2) ) % LED_COUNT);

  Display.Screen_Colors[Player_1.Get_Pos()] = Player_1.Get_Color();
  Display.Screen_Colors[Player_2.Get_Pos()] = Player_2.Get_Color();
  Display.Screen_Colors[Player_3.Get_Pos()] = Player_3.Get_Color();
  Display.Screen_Colors[Player_4.Get_Pos()] = Player_4.Get_Color();
  
  // Write the colors to the LED strip.
  Display.Update();
  
  delay(100);
}
