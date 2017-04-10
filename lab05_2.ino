#include <SevSeg.h>
	#include <Keypad.h>
	
	SevSeg sevseg; 
	
	void setup() {
	Serial.begin(9600); 
	byte numDigits =1;
	
	byte digitPins[] = {A2};
	byte segmentPins[] = {A0,A1,A3,A4,2,3,4,5};
	sevseg.begin(COMMON_CATHODE, numDigits, digitPins, segmentPins);
	}
	
	const byte ROWS = 4;
	const byte COLS = 4;
	char key;
	int k;
	char keys[ROWS][COLS]={
	{'F','B','A','0'},
	{'E','3','2','1'},
	{'D','6','5','4'},
	{'C','9','8','7'}
	};
	
	byte rowPins[ROWS]={13,12,11,10};
	byte colPins[COLS]={9,8,7,6};
	Keypad keypad = Keypad(makeKeymap(keys),rowPins,colPins,ROWS,COLS);
	
	void loop() {
	key = keypad.getKey();
	
	if (key != NO_KEY)
	{
	if(key>='A' && key<='Z')
	k=key-'A'+10;
	else
	k=key-'0';
	
	Serial.println(key);
	Serial.println(k);
	sevseg.setNumber(k,1);
	//sevseg.setChars(k);
	sevseg.refreshDisplay(); 
	}
	else
	sevseg.refreshDisplay(); 
	
	
	
	
	
	}

