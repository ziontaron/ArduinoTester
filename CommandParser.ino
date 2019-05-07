
#define MAX_WORLD_COUNT 5
#define MIN_WORLD_COUNT 2
char *Words[MAX_WORLD_COUNT];
char *StringToParse;


void CommandParser()
{  
  }

////////// ////////// ////////// ////////// ////////// ////////// //////////
// Split string into individual words and store each word into an array
// this function return word_count (number of words)
////////// ////////// ////////// ////////// ////////// ////////// //////////
byte split_message(char* str) {
  byte word_count = 0; //number of words
  char * item = strtok (str, " ,"); //getting first word (uses space & comma as delimeter)

  while (item != NULL) {
    if (word_count >= MAX_WORLD_COUNT) {
      break;
    }
    Words[word_count] = item;
    item = strtok (NULL, " ,"); //getting subsequence word
    word_count++;
  }
  return  word_count;
}

////////// ////////// ////////// ////////// ////////// ////////// //////////
// Send array over serial
////////// ////////// ////////// ////////// ////////// ////////// //////////
void print_message(byte word_count) {
  //if (word_count >= MIN_WORLD_COUNT) {
  //Serial.print("Word count : ");  Serial.println(word_count);
  for (byte sms_block = 0; sms_block < word_count; sms_block++) {
    Serial.print("Word "); Serial.print(sms_block + 1);  Serial.print(" : ");
    Serial.println(Words[sms_block]);
  }
  Serial.println("--------------------");
  //}
}
