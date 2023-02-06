int const trig = 9, echo = 10;
int const in1 = 2, in2 = 3, in3 = 4, in4 = 5;

float const maxDistance = 100;
float distance;	

void setup() {
    Serial.begin (9600);
    pinMode (trig, OUTPUT);
    pinMode (echo, INPUT);
}

void loop() {
    delay(120);
    digitalWrite(trig, HIGH);
    delay(5);
    digitalWrite(trig, LOW);
    distance = pulseIn (echo, HIGH);
    distance = distance / 58;
    Serial.println (distance);
    if (distance >= maxDistance) {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, HIGH);
        delay(125);
    } else {
        digitalWrite(in1, LOW);
        digitalWrite(in2, HIGH);
        digitalWrite(in3, LOW);
        digitalWrite(in4, LOW);
        delay(125);
    }
}