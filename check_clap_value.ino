#define signalToRelayPin 13
#define sensorPin 2

int lastSoundValue;
int soundValue;
long lastNoiseTime = 0;
long currentNoiseTime = 0;
long lastLightChange = 0;
int relayStatus = HIGH;

boolean val = 0;
boolean newVal = 0;

void setup()
{
  pinMode(sensorPin, INPUT);
  pinMode(signalToRelayPin, OUTPUT);
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop()
{
  newVal = digitalRead(sensorPin);
  if (val != newVal)
  {
    val = newVal;
    if (val == 1)
    {
      Serial.println("Flick");  // wait for a second
      Serial.println(millis()); // wait for a second
    }
  }
}

// void loop()
// {
//   soundValue = digitalRead(sensorPin);
//   currentNoiseTime = millis();

//   if (soundValue == 1)
//   { // if there is currently a noise

//     if (
//         (currentNoiseTime > lastNoiseTime + 200) // to debounce a sound occurring in more than a loop cycle as a single noise
//         && (lastSoundValue == 0)                     // if it was silent before
//         // && (currentNoiseTime < lastNoiseTime + 800)  // if current clap is less than 0.8 seconds after the first clap
//         // && (currentNoiseTime > lastLightChange + 1000) // to avoid taking a third clap as part of a pattern
//     )
//     {
//       Serial.println("Yeah!");
//       relayStatus = !relayStatus;
//       digitalWrite(signalToRelayPin, relayStatus);
//       lastLightChange = currentNoiseTime;
//       delay(500);
//     }else{
//       Serial.println("Current");
//       Serial.println(currentNoiseTime);
//       Serial.println("Last");
//       Serial.println(lastNoiseTime);

//       digitalWrite(signalToRelayPin, LOW);
//     }

//     lastNoiseTime = currentNoiseTime;
//   }

//   lastSoundValue = soundValue;
// }