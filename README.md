# CaixaEletronicoArduino
=====================================
pt-BR

Caixa Eletrônico com Arduino, LCD I2C e Teclado Matricial
Descrição

Este projeto implementa um caixa eletrônico simples utilizando um Arduino, um display LCD I2C e um teclado matricial. O sistema permite realizar operações básicas como depósito, saque, consulta de saldo e outros serviços.

Funcionalidades

Depósito: permite depositar dinheiro na conta do usuário.
Saque: permite sacar dinheiro da conta do usuário, desde que o saldo seja suficiente.
Extrato: exibe o saldo atual da conta do usuário.
Outros:
Novo usuário: permite cadastrar um novo usuário no sistema.
Remover usuário: permite remover um usuário existente do sistema.
Empréstimo: permite solicitar um empréstimo, desde que o saldo seja suficiente para cobrir 5% do valor do empréstimo.
Componentes

Arduino Uno ou similar
Display LCD I2C (por exemplo, LCD1602)
Teclado matricial 4x4
Fios jumper
Resistores (para pull-up/down dos botões do teclado)
Bibliotecas

Wire.h
LiquidCrystal_I2C.h
Keypad.h
Montagem

Conecte o display LCD I2C ao Arduino de acordo com o esquema de fiação da biblioteca LiquidCrystal_I2C.
Conecte o teclado matricial ao Arduino de acordo com a pinagem definida no código.
Conecte os LEDs verde e vermelho aos pinos 10 e 11 do Arduino.
Uso

Carregue o código no Arduino.
Ligue o Arduino e aguarde a inicialização do sistema.
Utilize o teclado matricial para navegar pelas opções do menu e realizar as operações desejadas.
Observações

Este projeto é um exemplo básico e pode ser adaptado para atender às suas necessidades específicas.
Certifique-se de que o valor do saldo seja atualizado corretamente após cada operação.
Implemente medidas de segurança para proteger os dados dos usuários.
Melhorias

Implementar autenticação de usuário com senha.
Adicionar histórico de transações.
Permitir a impressão de recibos.
Integrar com um sistema bancário real.
Criar uma interface gráfica mais amigável.

=====================================

eu_US

ATM with Arduino, I2C LCD and Keypad
Description

This project implements a simple ATM using an Arduino, an I2C LCD display, and a keypad. The system allows users to perform basic operations such as deposit, withdraw, check balance, and other services.

Features

Deposit: allows users to deposit money into their account.
Withdraw: allows users to withdraw money from their account, as long as their balance is sufficient.
Balance: displays the user's current account balance.
Others:
New user: allows a new user to be registered in the system.
Remove user: allows an existing user to be removed from the system.
Loan: allows a loan to be requested, as long as the balance is sufficient to cover 5% of the loan amount.
Components

Arduino Uno or similar
I2C LCD display (e.g., LCD1602)
4x4 keypad
Jumper wires
Resistors (for pull-up/down of keypad buttons)
Libraries

Wire.h
LiquidCrystal_I2C.h
Keypad.h
Assembly

Connect the I2C LCD display to the Arduino according to the wiring diagram of the LiquidCrystal_I2C library.
Connect the keypad to the Arduino according to the pinout defined in the code.
Connect the green and red LEDs to pins 10 and 11 of the Arduino.
Usage

Upload the code to the Arduino.
Power on the Arduino and wait for the system to initialize.
Use the keypad to navigate through the menu options and perform the desired operations.
Notes

This project is a basic example and can be adapted to meet your specific needs.
Make sure the balance value is updated correctly after each operation.
Implement security measures to protect user data.
Improvements

Implement user authentication with password.
Add transaction history.
Allow printing of receipts.
Integrate with a real banking system.
Create a more user-friendly graphical interface.









