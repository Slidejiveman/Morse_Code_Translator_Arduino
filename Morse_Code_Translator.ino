#define ledPin 13 // Preprocessor directive is like a symbol in ASM

// GLOBALS
int dotDelay = 200; // Represents the delay after a dot

/* Define two dimensional arrays to hold the strings
 * that represent each letter and number. */
char* letters[] = 
{
  ".-", "_...", "-.-.", "-..", ".", // A - E
  "..-.", "--.", "....", "..",      // F - I
  ".---", "-.-", ".-..", "--", "-.", // J - N
  "---", ".--.", "--.-", ".-.",     // O - R
  "...", "-", "..-", "...-", ".--", // S - W
  "-..-", "-.--", "--.."            // X - Z
};

char* numbers[] = 
{
  "-----", ".----", "..---", "...--", "....-", // 0 - 4
  ".....", "-....", "--...", "---..", "----."  // 5 - 9
};

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  char ch;
  if (Serial.available() > 0)
  {
    ch = Serial.read();
    if (ch >= 'a' && ch <= 'z')
    {
      flashSequence(letters[ch - 'a']);
    }
    else if (ch >= 'A' && ch <= 'Z')
    {
      flashSequence(letters[ch - 'A']);
    }
    else if (ch >= '0' && ch <= '9')
    {
      flashSequence(numbers[ch - '0']);
    }
    else if (ch == ' ')
    {
      delay(dotDelay * 4); // Handle the gap between words
    }
  }
}

/*
 * Function that determines the sequence of dots and dashes
 * to send to the flasher.
 */
void flashSequence(char* sequence)
{
  int i = 0;
  while (sequence[i] != '\0') // While we haven't found EOS
  {
    flashDotOrDash(sequence[i]);
    i++;
  }
  delay(dotDelay * 3); // Handle the gap between letters.
}

/*
 * Function that handles the actual flashing of the
 * dots and dashes.
 */
void flashDotOrDash(char dotOrDash)
{
  digitalWrite(ledPin, HIGH);
  if (dotOrDash == '.')
  {
    delay(dotDelay);
  }
  else // must be a '-'
  {
    delay(dotDelay * 3); 
  }
  digitalWrite(ledPin, LOW);
  delay(dotDelay); // gap between letters
}

