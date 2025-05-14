int analogPin = 36;  // GPIO36 (VP)
int noiseLevel = 0;
const int smoothFactor = 10;  // Higher = Smoother changes
int smoothedNoise = 0;

void setup() {
    Serial.begin(115200);
    pinMode(analogPin, INPUT);
    analogReadResolution(12);
}

void loop() {
    noiseLevel = analogRead(analogPin);
    
    // Apply simple moving average smoothing
    smoothedNoise = (smoothedNoise * (smoothFactor - 1) + noiseLevel) / smoothFactor;

    int volume = map(smoothedNoise, 0, 4095, 10, 100); // Min volume = 10%

    Serial.print("Raw Noise Level: ");
    Serial.print(noiseLevel);
    Serial.print(" | Smoothed Noise: ");
    Serial.print(smoothedNoise);
    Serial.print(" | Mapped Volume: ");
    Serial.println(volume);

    delay(100);
}
