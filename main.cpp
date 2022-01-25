#include <iostream>
#include <time.h>
#include <math.h>
using namespace std;
#define arraySize(a) (sizeof(a)/sizeof(*(a)))

int factorial(unsigned short int a); //Misma funcion del laboratorio 1
void printMatriz5x5(int* lista);
int convertRoman(char h);
void intArrayPrint(int size, int* array);

/*

Buenas tardes profesor, como se hizo en el anterior trabajo, los problemas
estaran en funciones main commentadas, para su revision solo basta con
descomentarlos.

Aquellos problemas pares (ya que mi cedula termina en 0) que respectan a
arduino solo se podran encontrar en el TinkerCAD; esto para que no hallan confuciones.

Muchas gracias por su tiempo.

*/


/*

int main(){

    char a[5] = {65, 66, 67, 68};


      char nombre[40];
      cout <<  "Introduce nombre y apellidos: ";
      cin.getline(nombre,40);  //lectura incluyendo espacios
      cout << "Hola " << nombre << endl;

    cout << "El size de a es: " << (sizeof(a)/sizeof(*a)) << endl;

    cout << "El size con la funcion es: " << arraySize(a) << endl;

    return 0;
}

*/

/*

//Problema #2; generar array de 200 char random entre 65 & 90, contar cuantas veces se repite cada letra.

int main(){
    char cadena[200];
    char aleatorio = 0;
    short int counter = 0;

    for(short int k = 0;k<200; k++){
        srand(time(NULL)+k);
        aleatorio = (rand() % 26)+65;
        cadena[k] = aleatorio;
    }


    cout << cadena << endl;
    for(char f = 65; f<91 ; f++){
        for(short int g = 0; g<200; g++){
            if(cadena[g]==f){counter++;}
        }
        if(counter!=0){ cout << f << ": " << counter << endl;}
        counter = 0;
    }


return 0;
}

*/

/*

//Problema #4; Convertir cadena a numero entero

int problema4(char* a; int b){

    char numeroc[40];
    short unsigned int trueSize;
    int numeroi = 0;
    cin.getline(numeroc,40);

    for(int y = 0; numeroc[y] != 0; y++){ trueSize++; }

    for(int s = 0; trueSize>0 ; s++){
        numeroi = numeroi + ( (numeroc[s]-48)*(pow(10, trueSize-1)) );
        trueSize--;
    }

return numeroi;
}

int main(){

    char cadena[] = "123456"; //REHACER CON PARAMETROS

    int retorno = problema4(cadena, arraySize(cadena));

    cout << "Numero: " << retorno << endl;
    cout << "Numero al sumarle 7: " << retorno+7 <<endl;

    return 0;
}

*/

/*

//Problema #6; Cadena de minusculas a mayusculas; RECORDAR PASAR A ARDUINO

int main(){

    char cadena[]="Manzana-698"; //Cadena de caracteres, puede cambiarla a su gusto.
    char newCadena[arraySize(cadena)];

    for(unsigned int u = 0; u<arraySize(cadena) ; u++){
        if(cadena[u]>96 && cadena[u]<123){ newCadena[u] = char(cadena[u]-32); }else{ newCadena[u] = cadena[u]; }
    }

    cout << "Original: " << cadena <<". ";
    cout << "En mayuscula: " << newCadena <<"."<< endl;

return 0;
}

*/

/*

//Problema #8; Separar numeros de letras, genera 2 cadenas

int main(){

    char ogChain[] = "cabra400loca500";
    char numberChain[arraySize(ogChain)];
    char charChain[arraySize(ogChain)];
    unsigned short int counterN = 0;
    unsigned short int counterC = 0;

    for(unsigned int h = 0; h<arraySize(ogChain) ; h++){
        if(ogChain[h]>47 && ogChain[h]<58){ numberChain[counterN] = ogChain[h]; counterN++; }
        else{ charChain[counterC] = ogChain[h]; counterC++; }
    }

    cout << "Original: " << ogChain << "." << endl;
    cout << "Texto: " << charChain << ". Numero: " << numberChain << "." <<endl;


return 0;
}

*/

/*

//Problema #10; Conversion de numero romano a arabigo (Version de arduino en TinkerCAD)

int main(){

    char roma[16];
    cin.getline(roma,16);
    int arabia = 0;

    for(short int p = arraySize(roma)-2; p >= 0 ;p--){
        int prev = convertRoman(*(roma+p-1));
        int next = convertRoman(*(roma+p));

        if(prev<next){ arabia += next-prev; p--;}
        else{ arabia += next;}
    }

    cout << "El numero ingresado fue: " << roma << endl;
    cout << "Que corresponde a: " << arabia << "." << endl;

return 0;
}

*/

/*

//Problema #12; Verificador de cuadrado magico

int main(){

    int matriz[] = {4, 9, 2, 3, 5, 7, 8, 1, 6}; //Ingrese matriz aqui
    float rootSize = sqrt(arraySize(matriz));
    int sum = 0;
    int temp = 0;
    int posMarker = 0;
    bool isMagica = true;

    if(rootSize-(int(rootSize/1)*1)){
        cout << "La matriz no es magica ya que no es cuadrada." << endl;
    }else{

        for(int j = 0; j<rootSize ; j++){
            sum += matriz[j]; //Suma de primera fila, usada para comparar.
        }
        //Revisando columnas
        for(int j = 0; j<rootSize ; j++){
            for(int u = 0; u<rootSize; u++){
            temp += matriz[j+int(u*rootSize)];
            }
            if(temp!=sum){ isMagica = false; }
            temp = 0;
        }
        //Revisando filas
        for(int d = 1; d<rootSize; d++){
            for(int p = 0; p<rootSize; p++){
            temp += matriz[p+int(d*rootSize)];
            }
            if(temp!=sum){ isMagica = false; }
            temp=0;
        }
        //Revisando diagonales
        for(int y = 0; y<rootSize;y++){
         temp += matriz[int(y*rootSize)+posMarker];
         posMarker++;
        }
        if(temp!=sum){ isMagica = false; }
        temp=0;

        posMarker = rootSize;
        for(int y = 1; y<=rootSize;y++){
         temp += matriz[int(y*rootSize)-posMarker];
         posMarker--;
        }
        if(temp!=sum){ isMagica = false; }
        temp=0;
    }if(isMagica){

        for(int t = 0; t<arraySize(matriz); t++){
            for(int n = 0; n<arraySize(matriz); n++){
                if(matriz[t] == matriz[n] && n!=t){isMagica = false;}
            }
        }
        if(isMagica){cout << "La matriz es magica." << endl;}else{cout << "La matriz no es magica ya que no todos sus elementos son unicos." <<endl;}

    }else{ cout << "La matriz no es magica ya que sus sumatorias no son iguales." << endl;}

return 0;
}

//

*/

/*

//Problema #14; matriz 5x5 aleatoria y rotada

int main(){

    int cuadrado[25];
    int cuadrado90[25];
    int cuadrado180[25];
    int cuadrado270[25];
    int posMarker = 0;

    for(int r = 0; r<25 ; r++){
        srand(time(NULL)+r);
        posMarker = (rand() % 25)+1;
        cuadrado[r] = posMarker;
    }

    posMarker = 0;
    for(int y = 5; y>0 ; y--){
        for(int g = 0; g<=24 ; g += 5){
        cuadrado90[(y+g-1)] = cuadrado[posMarker];
        posMarker++;
        }
    }

    posMarker = 24;
    for(int u = 0; u<25 ; u++){
        cuadrado180[posMarker] = cuadrado[u];
        posMarker--;
    }

    posMarker = 24;
    for(int y = 5; y>0 ; y--){
        for(int g = 0; g<=24 ; g += 5){
        cuadrado270[(y+g-1)] = cuadrado[posMarker];
        posMarker--;
        }
    }

    cout << "Matriz Original" << endl;
    printMatriz5x5(cuadrado);
    cout << "Matriz Rotada 90 grados" << endl;
    printMatriz5x5(cuadrado90);
    cout << "Matriz Rotada 180 grados" << endl;
    printMatriz5x5(cuadrado180);
    cout << "Matriz Rotada 270 grados" << endl;
    printMatriz5x5(cuadrado270);


return 0;
}

*/


/*

//Problema #16;

int main(){
    short int n = 4; //Dimensiones de la malla n*n, cambiar para otras dimensiones de malla

    int paths = double(factorial((n-1)*2)) / (factorial(n-1) * factorial(n-1)); //Dado que la malla es cuadrada y solo se puede mover hacia el punto final, los movimientos totales van siempre a ser n-1 hacia abajo y hacia la derecha, con esto se puede entonces calcular la cantidad de caminos como la combinacion de estos dos movimientos. La formula aqui es aquella utilizada para combinaciones con repeticion.

    cout << "Para una malla de " << n << "x" <<n<< " puntos hay " <<paths<< " caminos."<<endl;


return 0;
}

*/

//

//Problema #18; Permutacion lexicografica con numeros del 0 al 9.

int main(){

    char num[]="012345679";
    unsigned short int position;

    cout << "Ingrese el numero de permutaciones: ";
    cin >> position;

    if()




return 0;
}

//

void printMatriz5x5(int* lista){

    int counter = 0;

    for(int b = 0; b<5; b++){

        for(int c = 0; c<5 ; c++){
            if(*(lista+counter)<10){ cout << "[ " << *(lista+counter) << "]"; }
            else{ cout << "[" << *(lista+counter) << "]"; }


            counter++;
        }

        cout << endl;
    }

}


int factorial(unsigned short int a){ //Returna el factorial de un numero
    unsigned int fact = 1;
    for(unsigned short int b = 1; b <= a; b++ ){
        fact = fact*b;
    }
    return fact;
}

int convertRoman(char h){
    if(h == 73){ return 1; }
    if(h == 86){ return 5; }
    if(h == 88){ return 10; }
    if(h == 76){ return 50; }
    if(h == 67){ return 100; }
    if(h == 68){ return 500; }
    if(h == 77){ return 1000; }

    return 0;
    }

void intArrayPrint(int size,int* array){

    cout << "{" <<*array;

    for(unsigned short int a = 1; a < size; a++){
        cout << ", " << *(array+a);
    }

    cout << "}" <<endl;
}

void swapArray
