/*##### PINES #####*/
    int motorDer= 3;
    int motorIzq= 6;
    int sensDer = A0;
    int sensIzq = A1;

/*##### VARIABLES ##### */
    int vIzq, vDer;
    int accion = 4;		// recto = 0, izq = 1, derecha = 2, aleatorio = 3, investigacion = 4
    int vRefOn = 511;
    int vVelOn = 90;
    int const espera = 250;
    boolean lugar = false;		// false = fuera , true = dentro

    
    void Arrancar(int PIzq, int PDer) {	
       int valIzq = analogRead(PIzq);
       int valDer = analogRead(PDer);
      
      
      if (valIzq <= vRefOn && valDer <= vRefOn && lugar == true) {			// Si NO detecta la linea
        Tope();  
      }      
      else if (valIzq > vRefOn && valDer <= vRefOn ) {	// detecta la linea con el sensor Izq
        Izq();
      }
      else if (valIzq <= vRefOn && valDer > vRefOn) {			// Si detecta la linea con el sensor Der
        Der();
      }

      else if (valIzq > vRefOn && valDer > vRefOn) {
                	// Si detecta la linea con AMBOS sensores
        Azar(2);
        
      }
      else {
        Research(PIzq,PDer);							// En cualquier otro caso "BUSCA"
      }
    }
    
    void Research (int PIzq,int PDer){
      unsigned long timer = millis();
      int valIzq,valDer;
      while(lugar == false or (millis() - timer) < 5000 ){
        Azar(0);
        valIzq = analogRead(PIzq);
        valDer = analogRead(PDer);
        if (valIzq > vRefOn or valDer > vRefOn) {		
          lugar == true;
        }     
      }
    }
    
    
void setup() {
  pinMode(motorDer,OUTPUT);
  pinMode(motorIzq,OUTPUT);
  pinMode(sensIzq,INPUT);
  pinMode(sensDer,INPUT);
  
}

void loop() {
 
  Arrancar(sensIzq,sensDer);

}

void Tope(){
    analogWrite (motorDer, vVelOn);
    analogWrite (motorIzq, vVelOn);
    }

    void Izq() {
      analogWrite (motorDer, vVelOn);
      analogWrite (motorIzq, 0);
    }

    void Der() {
      analogWrite (motorIzq, vVelOn);
      analogWrite (motorDer, 0);
    }

    void Azar(int n){
      unsigned long timer = millis();
      int action = random(0,2);
      do{
      if (action == 0){
           Tope();
      }
      else if (action == 1){
           Izq();
      }
      else {
           Der();
      }
    }while(millis() - timer < 250 * n);    
 }



