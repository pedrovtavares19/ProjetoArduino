foi utilizado o codigo por texto, um arduino uno, fios, uma placa de ensaio, 4 LEDs, 1 verde, 1 amarelo e 1 vermelho e a representação da bomba por 1 LED branco, 1 resistor para cada LED e o sensor ultrassonico HC-SR04, para melhor entendimento.
primeiro, inclui as variaveis, depois, foi criada a variavel para lembrar o estado da bomba e as definições do sensor,
foi definida a distancia por centimetros e depois as condições: se a distancia fosse igual a 0 ou maior que 400cm, a leitura seria invalida;
se a distancia fosse maior que 200cm, entao o tanque sera definido como vazio e a luz verde se acende, as demais apagadas e a "bomba" desligada;
se a distancia for menor ou igual a 200cm e maior que 50cm, o tanque sera definido como medio, a luz amarela se acende, as demais apagadas e a "bomba" desligada;
se a distancia for menor que 50cm, o tanque sera definido como cheio, a luz vermelha se acende, as demais apagadas e a "bomba" ligada, a "bomba" só será desligada novamente quando a distancia for maior que 200cm, ou seja, quando o tanque estiver vazio
