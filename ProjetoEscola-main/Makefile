# Nome do nosso programa final (sem .exe no Linux)
TARGET = projeto_escola

# Qual compilador estamos usando
CC = gcc

# O Segredo: Avisa o compilador em quais pastas ele deve procurar os arquivos .h
# Adicionado -Wall para mostrar todos os avisos e -g para permitir debug
CFLAGS = -I./model -I./view -I./controller -I./utils -Wall -g

# Capturando os arquivos C de forma segura
SRCS = escola.c $(wildcard model/*.c) $(wildcard view/*.c) $(wildcard controller/*.c) $(wildcard utils/*.c)

# A regra principal (o que acontece quando você digita 'make')
all:
	$(CC) $(SRCS) $(CFLAGS) -o $(TARGET)

# Regra para limpar o executável antigo (usando 'rm -f' do Linux)
clean:
	rm -f $(TARGET)