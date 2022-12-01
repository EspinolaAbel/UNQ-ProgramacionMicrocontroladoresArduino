const short NOTES[] = {
  31, // B0
  33, // C1
  35, // CS1
  37, // D1
  39, // DS1
  41, // E1
  44, // F1
  46, // FS1
  49, // G1
  52, // GS1
  55, // A1
  58, // AS1
  62, // B1
  65, // C2
  69, // CS2
  73, // D2
  78, // DS2
  82, // E2
  87, // F2
  93, // FS2
  98, // G2
  104, // GS2
  110, // A2
  117, // AS2
  123, // B2
  131, // C3
  139, // CS3
  147, // D3
  156, // DS3
  165, // E3
  175, // F3
  185, // FS3
  196, // G3
  208, // GS3
  220, // A3
  233, // AS3
  247, // B3
  262, // C4
  277, // CS4
  294, // D4
  311, // DS4
  330, // E4
  349, // F4
  370, // FS4
  392, // G4
  415, // GS4
  440, // A4
  466, // AS4
  494, // B4
  523, // C5
  554, // CS5
  587, // D5
  622, // DS5
  659, // E5
  698, // F5
  740, // FS5
  784, // G5
  831, // GS5
  880, // A5
  932, // AS5
  988  // B5
};

struct Nota {
	byte boton;
	int nota;
	long duracion;
	Nota(short value) {
		boton = (value & 0b1110000000000000) >> 13;
		nota = NOTES[(value & 0b0001111111100000) >> 5];
		duracion = (value & 0b0000000000011111);
	}
};

struct Puntaje {
	byte totalNotas = 0;
	byte totalAciertos = 0;
	byte totalErrores = 0;
	byte efectividad() {
		if (totalNotas == 0)
			return 0;
		return 100*((double)totalAciertos)/((double)totalNotas);
	}
};
 CS3
  147, // D3
  156, // DS3
  165, // E3
  175, // F3
  185, // FS3
  196, // G3
  208, // GS3
  220, // A3
  233, // AS3
  247, // B3
  262, // C4
  277, // CS4
  294, // D4
  311, // DS4
  330, // E4
  349, // F4
  370, // FS4
  392, // G4
  415, // GS4
  440, // A4
  466, // AS4
  494, // B4
  523, // C5
  554, // CS5
  587, // D5
  622, // DS5
  659, // E5
  698, // F5
  740, // FS5
  784, // G5
  831, // GS5
  880, // A5
  932, // AS5
  988  // B5
};
