#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>

// Configuração do display LCD I2C
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Configuração do teclado matricial
const byte ROWS = 4; // quatro linhas
const byte COLS = 4; // quatro colunas
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[ROWS] = {9, 8, 7, 6}; // conectar as linhas aos pinos do Arduino
byte colPins[COLS] = {5, 4, 3, 2}; // conectar as colunas aos pinos do Arduino

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

float saldo = 0.0; // Saldo inicial

struct Usuario {
  String nome;
  String senha;
};

Usuario usuarios[10]; // Limite de 10 usuários
int numUsuarios = 0; // Contador de usuários

const int LED_VERDE = 10;
const int LED_VERMELHO = 11;

void setup() {
  lcd.begin(16, 2); // Configurar o LCD com 16 colunas e 2 linhas
  lcd.backlight();
  pinMode(LED_VERDE, OUTPUT);
  pinMode(LED_VERMELHO, OUTPUT);
  lcd.setCursor(0, 0);
  lcd.print("Caixa Eletronico");
  delay(2000);
  mostrarMenu();
}

void loop() {
  char key = keypad.getKey();
  if (key) {
    if (key == '1') {
      deposito();
    } else if (key == '2') {
      saque();
    } else if (key == '3') {
      extrato();
    } else if (key == '4') {
      outros();
    }
  }
}

void mostrarMenu() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1) Deposito");
  lcd.setCursor(0, 1);
  lcd.print("2) Saque  3) Extrato  4) Outros");
}

void deposito() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Valor a depositar:");
  float valor = obterValor();
  saldo += valor;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Deposito feito!");
  digitalWrite(LED_VERDE, HIGH);
  delay(2000);
  digitalWrite(LED_VERDE, LOW);
  mostrarMenu();
}

void saque() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Valor a sacar:");
  float valor = obterValor();
  if (valor <= saldo) {
    saldo -= valor;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Saque realizado!");
    digitalWrite(LED_VERDE, HIGH);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Saldo insuficiente!");
    digitalWrite(LED_VERMELHO, HIGH);
  }
  delay(2000);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);
  mostrarMenu();
}

void extrato() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Seu saldo e:");
  lcd.setCursor(0, 1);
  lcd.print(saldo, 2);
  delay(3000);
  mostrarMenu();
}

void outros() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("1) Novo Usuario");
  lcd.setCursor(0, 1);
  lcd.print("2) Remover User  3) Emprestimo");
  char key = keypad.waitForKey();
  if (key == '1') {
    novoUsuario();
  } else if (key == '2') {
    removerUsuario();
  } else if (key == '3') {
    emprestimo();
  }
  mostrarMenu();
}

void novoUsuario() {
  if (numUsuarios < 10) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nome:");
    String nome = obterEntrada();
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Senha:");
    String senha = obterEntrada();
    
    usuarios[numUsuarios].nome = nome;
    usuarios[numUsuarios].senha = senha;
    numUsuarios++;

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Usuario criado!");
    digitalWrite(LED_VERDE, HIGH);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Limite atingido!");
    digitalWrite(LED_VERMELHO, HIGH);
  }
  delay(2000);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

void removerUsuario() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Nome:");
  String nome = obterEntrada();
  int indice = -1;
  for (int i = 0; i < numUsuarios; i++) {
    if (usuarios[i].nome == nome) {
      indice = i;
      break;
    }
  }
  if (indice != -1) {
    for (int i = indice; i < numUsuarios - 1; i++) {
      usuarios[i] = usuarios[i + 1];
    }
    numUsuarios--;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Usuario removido!");
    digitalWrite(LED_VERDE, HIGH);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Nao encontrado!");
    digitalWrite(LED_VERMELHO, HIGH);
  }
  delay(2000);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

void emprestimo() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Valor emprestimo:");
  float valor = obterValor();
  if (saldo >= 0.05 * valor) {
    saldo += valor;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Emprestimo aprovado!");
    digitalWrite(LED_VERDE, HIGH);
  } else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Saldo insuficiente!");
    digitalWrite(LED_VERMELHO, HIGH);
  }
  delay(2000);
  digitalWrite(LED_VERDE, LOW);
  digitalWrite(LED_VERMELHO, LOW);
}

float obterValor() {
  String valorStr = "";
  char key;
  while (true) {
    key = keypad.getKey();
    if (key) {
      if (key == '#') {
        break; // '#' para confirmar a entrada do valor
      } else {
        valorStr += key;
        lcd.setCursor(0, 1);
        lcd.print(valorStr);
      }
    }
  }
  return valorStr.toFloat();
}

String obterEntrada() {
  String entrada = "";
  char key;
  while (true) {
    key = keypad.getKey();
    if (key) {
      if (key == '#') {
        break; // '#' para confirmar a entrada
      } else {
        entrada += key;
        lcd.setCursor(0, 1);
        lcd.print(entrada);
      }
    }
  }
  return entrada;
}
