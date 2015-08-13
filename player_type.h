typedef class Player_Type {
  private:
    byte Pos;
    rgb_color Color;
    
  public:
    Player_Type(byte, rgb_color);
    void Set_Pos(byte);
    byte Get_Pos();
    
    void Set_Color(rgb_color);
    rgb_color Get_Color();
    
    void Move_Left();
    void Move_Right();
} Player_Type;

Player_Type::Player_Type(byte a, rgb_color b)
{
  Pos = a;
  Color = b;
}

void Player_Type::Set_Pos(byte a)
{
  Pos = a;
}

byte Player_Type::Get_Pos()
{
  return Pos;
}

void Player_Type::Move_Left()
{
  Pos++;
}

void Player_Type::Move_Right()
{
  Pos--;
  if (Pos < 0)
    Pos == 0;
}

void Player_Type::Set_Color(rgb_color new_color)
{
  Color = new_color;
}

rgb_color Player_Type::Get_Color()
{
  return Color;
}
