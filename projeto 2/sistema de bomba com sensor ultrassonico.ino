const int trigPin = 9;
const int echoPin = 10;

const int ledVerde = 2;
const int ledAmarelo = 3;
const int ledVermelho = 4;
const int ledBomba = 5;

long duracao;
int distancia;

bool bombaLigada = false;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(ledBomba, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duracao = pulseIn(echoPin, HIGH);

  distancia = duracao * 0.034 / 2;

  if (distancia == 0 || distancia > 400) {
    Serial.println("Leitura inválida");
    delay(500);
    return;
  }

  Serial.print("Distancia: ");
  Serial.println(distancia);

  if(distancia > 200) {
    // tanque vazio: desliga tudo e reseta bomba
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);

    bombaLigada = false;           // reseta bomba quando tanque vazio
    digitalWrite(ledBomba, LOW);
  } else if(distancia <= 200 && distancia > 50) {
    // tanque médio
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);

    // bomba mantém estado anterior (ligada ou desligada)
    digitalWrite(ledBomba, bombaLigada ? HIGH : LOW);
  } else {
    // tanque cheio
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);

    bombaLigada = true;          // liga a bomba e mantém ligada
    digitalWrite(ledBomba, HIGH);
  }

  delay(500);
}