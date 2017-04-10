#include <Keypad.h>
const byte ROWS = 4; // 4 Rows
const byte COLS = 4; // 4 Columns
// 定義 Keypad 的按鍵
char keys[ROWS][COLS] = {
{'F', 'B', 'A', '0'}, {'E','3','2','1'},
{'D','6','5','4'}, {'C','9','8','7'}
};
// 定義 Keypad 連到 Arduino 的接腳
byte rowPins[ROWS] = {13, 12, 11, 10};// 按鍵模組，行1~4接腳。
// 連到 Keypad 的 4 個 Rows
byte colPins[COLS] = {9,8, 7,6}; // 按鍵模組，列1~4接腳。 
// 連到 Keypad 的 4 個 Columns
// 建立Keypad 物件
Keypad keypad =
Keypad( makeKeymap(keys), rowPins,
colPins, ROWS, COLS );
void setup(){
Serial.begin(9600);
}
void loop(){
char key = keypad.getKey();
// 讀取Keypad的輸入
if (key != NO_KEY){
Serial.println(key);
}
}
