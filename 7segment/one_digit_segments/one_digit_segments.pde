const unsigned int A_PIN = 2;
const unsigned int B_PIN = 3;
const unsigned int C_PIN = 4;
const unsigned int D_PIN = 5;
const unsigned int E_PIN = 6;
const unsigned int F_PIN = 7;
const unsigned int G_PIN = 8;
const unsigned int DP_PIN = 12;

void setup() {
    display.setup(A_PIN, B_PIN, C_PIN, D_PIN, E_PIN, F_PIN, G_PIN, DP_PIN);
}

void loop() {
    digitalWrite(A_PIN, 1);
    delay(1000);
    digitalWrite(B_PIN, 1);
    delay(1000);
    digitalWrite(C_PIN, 1);
    delay(1000);
    digitalWrite(D_PIN, 1);
    delay(1000);
    digitalWrite(E_PIN, 1);
    delay(1000);
    digitalWrite(F_PIN, 1);
    delay(1000);
    digitalWrite(G_PIN, 1);
    delay(1000);
    digitalWrite(DP_PIN, 1);
    delay(1000);
}

