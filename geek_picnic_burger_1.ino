/*
   Система отображения заказов на мониторе VGA
   Created by Rostislav Varzar
*/

#include <VGAX.h>

// Font generated from BITFONZI - by Sandro Maffiodo
#define FNT_NANOFONT_HEIGHT 6
#define FNT_NANOFONT_SYMBOLS_COUNT 95

// Data size = 570 bytes
const unsigned char fnt_nanofont_data[FNT_NANOFONT_SYMBOLS_COUNT][1 + FNT_NANOFONT_HEIGHT] PROGMEM =
{
  { 1, 128, 128, 128, 0, 128, 0, }, //glyph '!' code=0
  { 3, 160, 160, 0, 0, 0, 0, }, //glyph '"' code=1
  { 5, 80, 248, 80, 248, 80, 0, },  //glyph '#' code=2
  { 5, 120, 160, 112, 40, 240, 0, },  //glyph '$' code=3
  { 5, 136, 16, 32, 64, 136, 0, },  //glyph '%' code=4
  { 5, 96, 144, 104, 144, 104, 0, },  //glyph '&' code=5
  { 2, 128, 64, 0, 0, 0, 0, },  //glyph ''' code=6
  { 2, 64, 128, 128, 128, 64, 0, }, //glyph '(' code=7
  { 2, 128, 64, 64, 64, 128, 0, },  //glyph ')' code=8
  { 3, 0, 160, 64, 160, 0, 0, },  //glyph '*' code=9
  { 3, 0, 64, 224, 64, 0, 0, }, //glyph '+' code=10
  { 2, 0, 0, 0, 0, 128, 64, },  //glyph ',' code=11
  { 3, 0, 0, 224, 0, 0, 0, }, //glyph '-' code=12
  { 1, 0, 0, 0, 0, 128, 0, }, //glyph '.' code=13
  { 5, 8, 16, 32, 64, 128, 0, },  //glyph '/' code=14
  { 4, 96, 144, 144, 144, 96, 0, }, //glyph '0' code=15
  { 3, 64, 192, 64, 64, 224, 0, },  //glyph '1' code=16
  { 4, 224, 16, 96, 128, 240, 0, }, //glyph '2' code=17
  { 4, 224, 16, 96, 16, 224, 0, },  //glyph '3' code=18
  { 4, 144, 144, 240, 16, 16, 0, }, //glyph '4' code=19
  { 4, 240, 128, 224, 16, 224, 0, },  //glyph '5' code=20
  { 4, 96, 128, 224, 144, 96, 0, }, //glyph '6' code=21
  { 4, 240, 16, 32, 64, 64, 0, }, //glyph '7' code=22
  { 4, 96, 144, 96, 144, 96, 0, },  //glyph '8' code=23
  { 4, 96, 144, 112, 16, 96, 0, },  //glyph '9' code=24
  { 1, 0, 128, 0, 128, 0, 0, }, //glyph ':' code=25
  { 2, 0, 128, 0, 0, 128, 64, },  //glyph ';' code=26
  { 3, 32, 64, 128, 64, 32, 0, }, //glyph '<' code=27
  { 3, 0, 224, 0, 224, 0, 0, }, //glyph '=' code=28
  { 3, 128, 64, 32, 64, 128, 0, },  //glyph '>' code=29
  { 4, 224, 16, 96, 0, 64, 0, },  //glyph '?' code=30
  { 4, 96, 144, 176, 128, 112, 0, },  //glyph '@' code=31
  { 4, 96, 144, 240, 144, 144, 0, },  //glyph 'A' code=32
  { 4, 224, 144, 224, 144, 224, 0, }, //glyph 'B' code=33
  { 4, 112, 128, 128, 128, 112, 0, }, //glyph 'C' code=34
  { 4, 224, 144, 144, 144, 224, 0, }, //glyph 'D' code=35
  { 4, 240, 128, 224, 128, 240, 0, }, //glyph 'E' code=36
  { 4, 240, 128, 224, 128, 128, 0, }, //glyph 'F' code=37
  { 4, 112, 128, 176, 144, 112, 0, }, //glyph 'G' code=38
  { 4, 144, 144, 240, 144, 144, 0, }, //glyph 'H' code=39
  { 3, 224, 64, 64, 64, 224, 0, },  //glyph 'I' code=40
  { 4, 240, 16, 16, 144, 96, 0, },  //glyph 'J' code=41
  { 4, 144, 160, 192, 160, 144, 0, }, //glyph 'K' code=42
  { 4, 128, 128, 128, 128, 240, 0, }, //glyph 'L' code=43
  { 5, 136, 216, 168, 136, 136, 0, }, //glyph 'M' code=44
  { 4, 144, 208, 176, 144, 144, 0, }, //glyph 'N' code=45
  { 4, 96, 144, 144, 144, 96, 0, }, //glyph 'O' code=46
  { 4, 224, 144, 224, 128, 128, 0, }, //glyph 'P' code=47
  { 4, 96, 144, 144, 144, 96, 16, },  //glyph 'Q' code=48
  { 4, 224, 144, 224, 160, 144, 0, }, //glyph 'R' code=49
  { 4, 112, 128, 96, 16, 224, 0, }, //glyph 'S' code=50
  { 3, 224, 64, 64, 64, 64, 0, }, //glyph 'T' code=51
  { 4, 144, 144, 144, 144, 96, 0, },  //glyph 'U' code=52
  { 3, 160, 160, 160, 160, 64, 0, },  //glyph 'V' code=53
  { 5, 136, 168, 168, 168, 80, 0, },  //glyph 'W' code=54
  { 4, 144, 144, 96, 144, 144, 0, },  //glyph 'X' code=55
  { 3, 160, 160, 64, 64, 64, 0, },  //glyph 'Y' code=56
  { 4, 240, 16, 96, 128, 240, 0, }, //glyph 'Z' code=57
  { 2, 192, 128, 128, 128, 192, 0, }, //glyph '[' code=58
  { 5, 128, 64, 32, 16, 8, 0, },  //glyph '\' code=59
  { 2, 192, 64, 64, 64, 192, 0, },  //glyph ']' code=60
  { 5, 32, 80, 136, 0, 0, 0, }, //glyph '^' code=61
  { 4, 0, 0, 0, 0, 240, 0, }, //glyph '_' code=62
  { 2, 128, 64, 0, 0, 0, 0, },  //glyph '`' code=63
  { 3, 0, 224, 32, 224, 224, 0, },  //glyph 'a' code=64
  { 3, 128, 224, 160, 160, 224, 0, }, //glyph 'b' code=65
  { 3, 0, 224, 128, 128, 224, 0, }, //glyph 'c' code=66
  { 3, 32, 224, 160, 160, 224, 0, },  //glyph 'd' code=67
  { 3, 0, 224, 224, 128, 224, 0, }, //glyph 'e' code=68
  { 2, 64, 128, 192, 128, 128, 0, },  //glyph 'f' code=69
  { 3, 0, 224, 160, 224, 32, 224, },  //glyph 'g' code=70
  { 3, 128, 224, 160, 160, 160, 0, }, //glyph 'h' code=71
  { 1, 128, 0, 128, 128, 128, 0, }, //glyph 'i' code=72
  { 2, 0, 192, 64, 64, 64, 128, },  //glyph 'j' code=73
  { 3, 128, 160, 192, 160, 160, 0, }, //glyph 'k' code=74
  { 1, 128, 128, 128, 128, 128, 0, }, //glyph 'l' code=75
  { 5, 0, 248, 168, 168, 168, 0, }, //glyph 'm' code=76
  { 3, 0, 224, 160, 160, 160, 0, }, //glyph 'n' code=77
  { 3, 0, 224, 160, 160, 224, 0, }, //glyph 'o' code=78
  { 3, 0, 224, 160, 160, 224, 128, }, //glyph 'p' code=79
  { 3, 0, 224, 160, 160, 224, 32, },  //glyph 'q' code=80
  { 3, 0, 224, 128, 128, 128, 0, }, //glyph 'r' code=81
  { 2, 0, 192, 128, 64, 192, 0, },  //glyph 's' code=82
  { 3, 64, 224, 64, 64, 64, 0, }, //glyph 't' code=83
  { 3, 0, 160, 160, 160, 224, 0, }, //glyph 'u' code=84
  { 3, 0, 160, 160, 160, 64, 0, },  //glyph 'v' code=85
  { 5, 0, 168, 168, 168, 80, 0, },  //glyph 'w' code=86
  { 3, 0, 160, 64, 160, 160, 0, },  //glyph 'x' code=87
  { 3, 0, 160, 160, 224, 32, 224, },  //glyph 'y' code=88
  { 2, 0, 192, 64, 128, 192, 0, },  //glyph 'z' code=89
  { 3, 96, 64, 192, 64, 96, 0, }, //glyph '{' code=90
  { 1, 128, 128, 128, 128, 128, 0, }, //glyph '|' code=91
  { 3, 192, 64, 96, 64, 192, 0, },  //glyph '}' code=92
  { 3, 96, 192, 0, 0, 0, 0, },  //glyph '~' code=93
  { 4, 48, 64, 224, 64, 240, 0, },  //glyph '£' code=94
};

// VGA output object
VGAX vga;

// Temp strings
char str_temp1[32] = "";
char str_temp2[32] = "";
char str_temp3[32] = "";

// IR receiver parameters
#define IR_PIN 18
#define SAMPLE_SIZE  64
unsigned int IR_TimerValue[SAMPLE_SIZE] = {0};
char IR_direction[SAMPLE_SIZE] = {0};

// List arrays
#define MAX_ORDERS 8
int check_order_array[MAX_ORDERS] = {0};
int number_order_array[MAX_ORDERS] = {0};
int status_order_array[MAX_ORDERS] = {0};
#define ORDER_NONE 0
#define ORDER_COOKING 1
#define ORDER_READY 2

// IR key
#define KEY_NONE    -1
#define KEY_0       0
#define KEY_1       1
#define KEY_2       2
#define KEY_3       3
#define KEY_4       4
#define KEY_5       5
#define KEY_6       6
#define KEY_7       7
#define KEY_8       8
#define KEY_9       9
#define KEY_MINUS   10
#define KEY_PLUS    11
#define KEY_EQ      12
int currentKey = KEY_NONE;
int lastKey = KEY_NONE;

void setup()
{
  // Init serial port
  Serial.begin(9600);

  // Init VGA output
  vga.begin();
  vga.clear(0);

  // Print test text
  //sprintf(str_temp1, "BIAKA ZAKALIAKA");
  //sprintf(str_temp2, "%d", sensorValue);
  //vga.printSRAM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str_temp1, 0, 0, 3);

  // Init interrupt from IR receiver
  pinMode(IR_PIN, INPUT);
  attachInterrupt(digitalPinToInterrupt(IR_PIN), IR_handler, LOW);

  // Init TIMER1
  TCCR1A = 0x00;
  TCCR1B = 0x03;
  TIMSK1 = 0x00;

  // Prepare and print order list
  clearList();
  printList();
}

void loop()
{
  vga.delay(18);
  vga.delay(18);
  vga.delay(18);
  vga.delay(18);
}

void IR_handler()
{
  //detachInterrupt(digitalPinToInterrupt(IR_PIN));
  cli();
  long IRKey = getIRKey();
  currentKey = KEY_NONE;
  switch (IRKey)
  {
    case 0x45101044:
      currentKey = KEY_0; // 0
      break;
    case 0x41401414:
      currentKey = KEY_1; // 1
      break;
    case 0x40501504:
      currentKey = KEY_2; // 2
      break;
    case 0x45511004:
      currentKey = KEY_3; // 3
      break;
    case 0x40401514:
      currentKey = KEY_4; // 4
      break;
    case 0x41501404:
      currentKey = KEY_5; // 5
      break;
    case 0x44511104:
      currentKey = KEY_6; // 6
      break;
    case 0x44011154:
      currentKey = KEY_7; // 7
      break;
    case 0x44111144:
      currentKey = KEY_8; // 8
      break;
    case 0x44411114:
      currentKey = KEY_9; // 9
      break;
    case 0x55000054:
      currentKey = KEY_MINUS; // -
      break;
    case 0x51100444:
      currentKey = KEY_PLUS; // +
      break;
    case 0x50400514:
      currentKey = KEY_EQ; // EQ
      break;
    default:
      currentKey = KEY_NONE;
      break;
  }
  //Serial.print("Key: ");
  //Serial.println(IRKey, HEX);
  Serial.print("Key: ");
  Serial.println(currentKey);
  MAIN_handler();
  printList();
  vga.delay(250);
  sei();
  //attachInterrupt(digitalPinToInterrupt(IR_PIN), IR_handler, LOW);
}

void MAIN_handler()
{
  // Clear check array
  for (int u = 0; u < MAX_ORDERS; u ++)
  {
    check_order_array[u] = false;
  }
  // Select one item
  if ((currentKey > 0) && (currentKey <= MAX_ORDERS))
  {
    check_order_array[currentKey - 1] = true;
  }
  // Change order status
  if ((lastKey > 0) && (lastKey <= MAX_ORDERS) && (currentKey >= KEY_MINUS) && (currentKey <= KEY_EQ))
  {
    if (currentKey == KEY_MINUS)
    {
      status_order_array[lastKey - 1] = ORDER_NONE;
    }
    else if (currentKey == KEY_PLUS)
    {
      status_order_array[lastKey - 1] = ORDER_COOKING;
    }
    else if (currentKey == KEY_EQ)
    {
      status_order_array[lastKey - 1] = ORDER_READY;
    }
    for (int u = 0; u < MAX_ORDERS; u ++)
    {
      check_order_array[u] = false;
    }
    lastKey = KEY_NONE;
  }
  lastKey = currentKey;
  currentKey = KEY_NONE;
}

long getIRKey()
{
  int change_count = 0;
  long timer_calc = 0;
  long result = 0;
  long timeout = 0;
  char c = 0;
  TCNT1 = 0;
  IR_TimerValue[change_count] = TCNT1;
  IR_direction[change_count++] = '0';
  while (change_count < SAMPLE_SIZE)
  {
    if (IR_direction[change_count - 1] == '0')
    {
      timeout = 0;
      while (digitalRead(IR_PIN) == LOW)
      {
        timeout ++;
        if (timeout > 10000)
        {
          break;
        }
      }
      IR_TimerValue[change_count] = TCNT1;
      IR_direction[change_count++] = '1';
    }
    else
    {
      timeout = 0;
      while (digitalRead(IR_PIN) == HIGH)
      {
        timeout ++;
        if (timeout > 10000)
        {
          break;
        }
      }
      IR_TimerValue[change_count] = TCNT1;
      IR_direction[change_count++] = '0';
    }
  }
  change_count = 0;
  while (change_count < SAMPLE_SIZE - 1)
  {
    timer_calc = (long) (IR_TimerValue[change_count + 1] - IR_TimerValue[change_count]) * 4;
    if (timer_calc < 800)
    {
      c = 0;
    }
    else
    {
      c = 1;
    }
    if (change_count >= 32)
    {
      result = result | c;
      result = result << 1;
    }
    change_count++;
  }
  return result;
}

void printList()
{
  vga.clear(0);
  int text_color = 0;
  for (int u = 0; u < MAX_ORDERS; u ++)
  {
    if (check_order_array[u])
    {
      text_color = 3;
      sprintf(str_temp1, "[%d]", number_order_array[u]);
      vga.printSRAM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str_temp1, 7, u * 7.5, text_color);
    }
    else
    {
      text_color = 3;
      sprintf(str_temp1, " %d ", number_order_array[u]);
      vga.printSRAM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str_temp1, 4, u * 7.5, text_color);
    }
    if (status_order_array[u] == ORDER_NONE)
    {
      text_color = 0;
      sprintf(str_temp2, "");
      //vga.printSRAM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str_temp2, 20, u * 7.5, text_color);
    }
    else if (status_order_array[u] == ORDER_COOKING)
    {
      text_color = 2;
      sprintf(str_temp2, "- COOKING...");
      vga.printSRAM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str_temp2, 20, u * 7.5, text_color);
    }
    else if (status_order_array[u] == ORDER_READY)
    {
      text_color = 1;
      sprintf(str_temp2, "- READY");
      vga.printSRAM((byte*)fnt_nanofont_data, FNT_NANOFONT_SYMBOLS_COUNT, FNT_NANOFONT_HEIGHT, 3, 1, str_temp2, 20, u * 7.5, text_color);
    }
  }
}

void clearList()
{
  for (int u = 0; u < MAX_ORDERS; u ++)
  {
    check_order_array[u] = false;
    status_order_array[u] = ORDER_NONE;
    number_order_array[u] = u + 1;
  }
}
