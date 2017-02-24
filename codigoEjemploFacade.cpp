// 23 de febrero del 2017
#include <math.h>
#include <iostream>

using namespace std;

/********************************************************************/
/** Componentes del susbsistema **/
class Trapecio {
    private:
        double baseMayor;
        double baseMenor;
        double altura;

    public:
        void setValores(double bsMy, double bsMe, double alt) {
            baseMayor = bsMy;
            baseMenor = bsMe;
            altura = alt;
        }

        double getArea() {
            return altura * (baseMayor + baseMenor) / 2.0;
        }
};

class Circulo {
    private:
        double radio;

    public:
        void setRadio(double rad) {
            radio = rad;
        }

        double getArea() {
            return M_PI * radio * radio;
        }
};

class Rectangulo {
    private:
        double base;
        double altura;

    public:
        void setValores(double bas, double alt) {
            base = bas;
            altura = alt;
        }

        double getArea() {
            return base * altura;
        }
};

/********************************************************************/
/** Componente fachada **/
class Fachada {
    private:
        Trapecio trap;
        Circulo cir;
        Rectangulo rec;

    public:
        void setMedidasTrapecio(double bsMy, double bsMe, double alt){
            trap.setValores(bsMy, bsMe, alt);
        }

        void setMedidasCirculo(double rad) {
            cir.setRadio(rad);
        }

        void setMedidasRectangulo(double base, double altura) {
            rec.setValores(base, altura);
        }

        double areaLampara() {
            return trap.getArea() + cir.getArea();
        }

        double areaSombrero() {
            return trap.getArea() + rec.getArea();
        }

        double areaCarrito() {
            return trap.getArea() + rec.getArea() + 2 * cir.getArea();
        }

        double areaCilindro() {
            return rec.getArea() + 2 * cir.getArea();
        }
};

/********************************************************************/
/** Componente cliente **/
int main(){
    Fachada fac;

    fac.setMedidasTrapecio(5, 3, 2.5);
    fac.setMedidasCirculo(1);
    fac.setMedidasRectangulo(8, 4);

    cout << "Area de lampara: " << fac.areaLampara() << endl;
    cout << "Area de sombrero: " << fac.areaSombrero() << endl;
    cout << "Area de carrito: " << fac.areaCarrito() << endl;
    cout << "Area de cilindro: " << fac.areaCilindro() << endl;

    return 0;
}
