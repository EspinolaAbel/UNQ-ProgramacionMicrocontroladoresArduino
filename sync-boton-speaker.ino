#include"pitches.h"

const byte speaker = 9;

const byte btn_E = 2;
const byte btn_B = 3;
const byte btn_G = 4;
const byte btn_D = 5;
const byte btn_A = 6;
const byte btn_e = 7;

const byte out_E = A5;
const byte out_B = A4;
const byte out_G = A3;
const byte out_D = A2;
const byte out_A = A1;
const byte out_e = A0;

const byte LEDS[]    = {out_E, out_B, out_G, out_D, out_A, out_e};
const byte BUTTONS[] = {btn_E, btn_B, btn_G, btn_D, btn_A, btn_e};

// El tempo de la melodía, cuánto es el tiempo mínimo entre nota y nota
byte speed = 90;
bool demo = true;

// Si la melodía terminó de reproducirse
boolean terminado=true;

/* La melodía está representado como un array de short (16bits) donde cada short representa en binario el botón a apretar, la nota músical y la duración de la nota
(botón)3bits + (nota)8bits + (duración)5bits = 16bits

Duraciones:
20 = 2   blanca
16 = 1   negra
12 = 1/2 corchea
 8 = 1/4 semicorchea
 4 = 1/8 fusa
*/

short melody[] = {
//  ############################################
//	short,              // botón nota   duración
//  ############################################
	0b0100010011101000, // 2     39     8
	0b0010010110000100, // 1     44     4
	0b0000010101101000, // 0     43     8
	0b1000010111000100, // 4     46     4
	0b0010010110000100, // 1     44     4
	0b0010011000100100, // 1     49     4
	0b1010010111100100, // 5     47     4
	0b1000010111001100, // 4     46     12
	0b0000010101100100, // 0     43     4
	0b0010010110000100, // 1     44     4
	0b1000010111000100, // 4     46     4
	0b0000010101100100, // 0     43     4
	0b1000010100000100, // 4     40     4
	0b0100010011100100, // 2     39     4
	0b0000010010100100, // 0     37     4
	0b0100010011110000, // 2     39     16
	0b0000000000000100, // 0     0      4
	0b0100010011101000, // 2     39     8
	0b0010010110000100, // 1     44     4
	0b0000010101101000, // 0     43     8
	0b1000010111000100, // 4     46     4
	0b0010010110000100, // 1     44     4
	0b0010011000100010, // 1     49     2
	0b0110011001100001, // 3     51     1
	0b0010011000100001, // 1     49     1
	0b1010010111100010, // 5     47     2
	0b0010011000100001, // 1     49     1
	0b1010010111100001, // 5     47     1
	0b1000010111001100, // 4     46     12
	0b0000010101100100, // 0     43     4
	0b0010010110000100, // 1     44     4
	0b1000010111000100, // 4     46     4
	0b0000010101100100, // 0     43     4
	0b1000010100000100, // 4     40     4
	0b0100010011100100, // 2     39     4
	0b0000010010100100, // 0     37     4
	0b0100010011110000, // 2     39     16
	0b0000000000000100, // 0     0      4
	0b0100010011100100, // 2     39     4
	0b0000010101100100, // 0     43     4
	0b0010010110000100, // 1     44     4
	0b1000010111000100, // 4     46     4
	0b1010011010000100, // 5     52     4
	0b0110011001100100, // 3     51     4
	0b0010011000100100, // 1     49     4
	0b1010010111100100, // 5     47     4
	0b1000010111000100, // 4     46     4
	0b0010011000101100, // 1     49     12
	0b0000010010100100, // 0     37     4
	0b0100010011100100, // 2     39     4
	0b1000010100000100, // 4     40     4
	0b0000010101100100, // 0     43     4
	0b0110011001100100, // 3     51     4
	0b0010011000100100, // 1     49     4
	0b1010010111100100, // 5     47     4
	0b1000010111000100, // 4     46     4
	0b0010011000100100, // 1     49     4
	0b1010010111101100, // 5     47     12
	0b0100010011100100, // 2     39     4
	0b0000010101100100, // 0     43     4
	0b0010010110000100, // 1     44     4
	0b1000010111000100, // 4     46     4
	0b1010011010000100, // 5     52     4
	0b0110011001100100, // 3     51     4
	0b0010011000100010, // 1     49     2
	0b0110011001100001, // 3     51     1
	0b0010011000100001, // 1     49     1
	0b1010010111100010, // 5     47     2
	0b0010011000100001, // 1     49     1
	0b1010010111100001, // 5     47     1
	0b1000010111000100, // 4     46     4
	0b0010011000101000, // 1     49     8
	0b0010010110000100, // 1     44     4
	0b1000010111000010, // 4     46     2
	0b0000000000000110, // 0     0      6
	0b1010010111100100, // 5     47     4
	0b1000010111000010, // 4     46     2
	0b0000000000000110, // 0     0      6
	0b0010010110000100, // 1     44     4
	0b0010010110000010, // 1     44     2
	0b1000010111000001, // 4     46     1
	0b0010010110000001, // 1     44     1
	0b0000010101110000, // 0     43     16
	0b0000000000000100, // 0     0      4
	0b0000010010100100, // 0     37     4
	0b0100010011101000, // 2     39     8
	0b0010010110000100, // 1     44     4
	0b0000010101100100, // 0     43     4
	0b1000010100000100, // 4     40     4
	0b0000010010100100, // 0     37     4
	0b0100010011110000, // 2     39     16
	0b0000000000000100, // 0     0      4
	0b0000010010100100, // 0     37     4
	0b0100010011101000, // 2     39     8
	0b0010010110000100, // 1     44     4
	0b0000010101100100, // 0     43     4
	0b1000010100000100, // 4     40     4
	0b0000010010100100, // 0     37     4
	0b0100010011110100  // 2     39     20
};

boolean LOGGER_ON=true;

void logger(String v) {
	if (LOGGER_ON) Serial.println("LOG: "+v);
}

int lenghtMelodia=sizeof(melody)/sizeof(short);
int tiempoParaApretarElBoton; // millis

void setup() {
	Serial.begin(9600);

	pinMode(btn_E, INPUT_PULLUP);
	pinMode(btn_B, INPUT_PULLUP);
	pinMode(btn_G, INPUT_PULLUP);
	pinMode(btn_D, INPUT_PULLUP);
	pinMode(btn_A, INPUT_PULLUP);
	pinMode(btn_e, INPUT_PULLUP);

	pinMode(out_E, OUTPUT);
	pinMode(out_B, OUTPUT);
	pinMode(out_G, OUTPUT);
	pinMode(out_D, OUTPUT);
	pinMode(out_A, OUTPUT);
	pinMode(out_e, OUTPUT);

	startDemo();
}

void readCmd() {
	if (Serial.available() == NULL) 
		return;
	String value = Serial.readString();
	if (value == NULL)
		return;
	value.trim();
	if (value.length() == 0)
		return;
	value.toUpperCase();

	     if (value.equals("HELP")) help();
	else if (value.equals("START")) start();
	else if (value.equals("STOP")) stop();
	else if (value.equals("RESTART")) { stop(); start(); }
	else if (value.equals("DEMO")) { startDemo(); }
	else if (value.equals("LOGOFF")) LOGGER_ON=false;
	else if (value.equals("LOGON")) LOGGER_ON=true;
	else if (value.equals("SPEEDUP")) { speed-=10; logger("SPEED="+String(speed)); }
	else if (value.equals("SPEEDDOWN")) { speed+=10; logger("SPEED="+String(speed)); }
}

int idxMelodia;
int resultadoBtnApretado;

boolean seAcaboLaMelodia() {
	return lenghtMelodia < idxMelodia + 1;
}

void help() {
	Serial.println("HELP: START STOP RESTART DEMO DEBUGOFF DEBUGON SPEEDUP SPEEDDOWN");
}

void start() {
	demo = false;
	initialize();
	logger("--DEMO--");
}

void startDemo() {
	demo = true;
	initialize();
	logger("--START--");
}

struct Puntaje puntaje;

/* inicia la ejecución de la canción */
void initialize() {
	tiempoParaApretarElBoton = 450; // millis
	idxMelodia = 0;
	resultadoBtnApretado = 1;
	puntaje = Puntaje();
	terminado=false;
}

/* termina la ejecución de la canción */
void stop() {
	terminado=true;
	noTone(speaker);
	logger("-- STOP --");
	logger("total notas: "+String(puntaje.totalNotas)+" | total aciertos: "+String(puntaje.totalAciertos)+" | total errores: "+String(puntaje.totalErrores)+" |efectividad: "+String(puntaje.efectividad())+"%");
}

void loop() {
	readCmd();
  
	if (terminado)
		return;

	if (seAcaboLaMelodia()) {
		stop();
		return;
	}

	//logger("idx nota actual: "+String(idxMelodia));
	struct Nota actual = Nota(melody[idxMelodia++]);

	bool botonFuePresionado = false;

	noTone(speaker);

	long duracionTono = actual.duracion*speed;

	if (demo || resultadoBtnApretado == 1)
		tone(speaker, actual.nota, actual.duracion*speed*.95);
	else if (resultadoBtnApretado == -1)
		tone(speaker, random(31,989), actual.duracion*speed*.95);

	// si entre la nota actual y la siguiente hay tiempo para apretar el botón, prendo el led de la siguiente nota
	if (duracionTono > tiempoParaApretarElBoton) {
		puntaje.totalNotas++;
		struct Nota siguiente = Nota(melody[idxMelodia]);
		byte led = LEDS[siguiente.boton];
		delay(duracionTono - tiempoParaApretarElBoton);
		digitalWrite(led, HIGH);
		delay(tiempoParaApretarElBoton);
		resultadoBtnApretado = botonCorrectoApretado(siguiente.boton);
		logger("resultadoBtnApretado="+String(resultadoBtnApretado));
		if (resultadoBtnApretado == 1)
			puntaje.totalAciertos++;
		if (resultadoBtnApretado == -1)
			puntaje.totalErrores++;
		digitalWrite(led, LOW);
	}
	else {
		delay(duracionTono);
		resultadoBtnApretado = 1;
	}

	noTone(speaker);
}

int botonCorrectoApretado(float btn) {
	int r = 0;
	for (int i=0; i<6; i++) {
		r = r | (digitalRead(BUTTONS[i]) == LOW ? roundup(pow(2,i)) : 0);
	}
	logger("btn="+String(btn)+" apretado="+String(r)+" pow(2,btn)="+String(roundup(pow(2,btn))));
	if (r == roundup(pow(2,btn)))
		return  1; // se apretó el correcto
	else if (r != 0)
		return -1; // se apretó cuelquier otro botón
	else {
		return  0; // no se apretó ninguno
	}
}

int roundup(int d) {
	return (d % 2) > 0 ? d+1 : d;
}
