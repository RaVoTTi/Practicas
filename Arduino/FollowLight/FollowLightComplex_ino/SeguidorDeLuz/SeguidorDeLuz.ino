/*##### PINES #####*/ 
    int motorDer= 3;
    int motorIzq= 6;
    int sensDer = A0;
    int sensIzq = A1;

/*##### VARIABLES ##### */
    int valDer = 0;
    int valIzq = 0;
    int action = 0;
    int vRefOn = 511;
    int vVelOn = 90;
    boolean lugar = false;		// false = fuera , true = dentro
    int espera = 200;
    unsigned long timer = 0;
    char first = 'N';			// Derecha = D - Izquierda = I - Nada = N

void setup() {
  pinMode(motorDer,OUTPUT);
  pinMode(motorIzq,OUTPUT);
  pinMode(sensIzq,INPUT);
  pinMode(sensDer,INPUT);
 
}

void loop() {
   valIzq = analogRead(sensIzq);
   valDer = analogRead(sensDer);

   if (valIzq > vRefOn && valDer <= vRefOn) {
      if (lugar == true) {
        Izq();   
      }
      else {
        Acoplar('I');
      }
    }
    else if (valIzq <= vRefOn && valDer > vRefOn) {
      if (lugar == true){
        Der();
      }
      else {
        Acoplar('D');
      }
    }
    elseif (valIzq <= vRefOn && valDer <= vRefOn) {
      if (lugar == true) {
        Tope();            
      }
      else {
        Research();
      }
    }
    elseif (valIzq > vRefOn && valDer > vRefOn) {
      Azar();
    }
}
 
void Izq() {
  analogWrite (motorDer, vVelOn);
  analogWrite (motorIzq, 0);
}

void Der() {
  analogWrite (motorIzq, vVelOn);
  analogWrite (motorDer, 0);
}

void Tope() {
  analogWrite (motorDer, vVelOn);
  analogWrite (motorIzq, vVelOn);
}

void Research() {
  while (valIzq <= vRefOn || valDer <= vRefOn) {	// OR ???
    for(int i; i < 5; i++) {
      Azar();
      if (valIzq <= vRefOn || valDer <= vRefOn) {	// OR ???
        break;
      }
    }
  }
}

void Azar(){
  timer = millis();
  action = random(1, 3);
  while (millis() - timer < espera) {			// Está al revés
    valIzq = analogRead(sensIzq);
    valDer = analogRead(sensDer);
    if (action == 1) {
      Izq();
    }
    elseif (action == 2) {
      Der();
    }
    else {
      Tope();
    }
    if (lugar == false && valIzq <= vRefOn || valDer <= vRefOn) {	// OR ???
      break;
    }
  }
}

void Acoplar (char direccion) {
  boolean listo = false;
  do {
    Tope();
    if (direccion == 'I') {
      valDer = analogRead(sensDer);
      if(valDer < vRefOn) {
        lugar = true;
        listo = true;
        break;
      }
      elseif (direccion == 'D') {
        valIzq = analogRead(sensIzq);
        if(valIzq > vRefOn) {
          lugar = true;
          listo = true;
          break;
        }
      }
    }
  } while (listo == false);
}

