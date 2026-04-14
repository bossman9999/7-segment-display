const int segA = 7;
const int segB = 6;
const int segC = 4;
const int segD = 3;
const int segE = 2;
const int segF = 8;
const int segG = 9;
const int buttonPin = 25;

int digit = 0;
int lastButtonState = HIGH;

//         A  B  C  D  E  F  G
bool digits[10][7] = {
  {1, 1, 1, 1, 1, 1, 0}, // 0
  {0, 1, 1, 0, 0, 0, 0}, // 1
  {1, 1, 0, 1, 1, 0, 1}, // 2
  {1, 1, 1, 1, 0, 0, 1}, // 3
  {0, 1, 1, 0, 0, 1, 1}, // 4
  {1, 0, 1, 1, 0, 1, 1}, // 5
  {1, 0, 1, 1, 1, 1, 1}, // 6
  {1, 1, 1, 0, 0, 0, 0}, // 7
  {1, 1, 1, 1, 1, 1, 1}, // 8
  {1, 1, 1, 1, 0, 1, 1}, // 9
};

void displayDigit(int d) {
  digitalWrite(segA, digits[d][0]);
  digitalWrite(segB, digits[d][1]);
  digitalWrite(segC, digits[d][2]);
  digitalWrite(segD, digits[d][3]);
  digitalWrite(segE, digits[d][4]);
  digitalWrite(segF, digits[d][5]);
  digitalWrite(segG, digits[d][6]);
}

void setup() {
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);

  displayDigit(0);
}

void loop() {
  int buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    digit = (digit + 1) % 10;
    displayDigit(digit);
    delay(50);
  }

  lastButtonState = buttonState;
}
