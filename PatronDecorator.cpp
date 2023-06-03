#include <iostream>
#include <string>

/*
*Primero, se definen las clases principales: Componente, ComponenteConcreto, Decorador y DecoradorConcreto.

*La clase Componente es una interfaz base que define la operación que se puede realizar en un componente. 
En este caso, se define un método virtual puro operacion() que devuelve una cadena de texto.

*La clase ComponenteConcreto es una implementación concreta de la interfaz Componente. 
Implementa el método operacion() y devuelve una cadena que representa la operación básica del componente.

*La clase Decorador es la clase base abstracta que también implementa la interfaz Componente. 
Esta clase tiene una referencia a un objeto de tipo Componente, que se pasa a través del constructor. 
Implementa el método operacion() delegando la llamada al objeto Componente subyacente.

*La clase DecoradorConcreto es una implementación concreta de Decorador. 
Extiende la funcionalidad del decorador base al agregar una cadena de 
texto adicional antes o después de llamar a la operación del componente subyacente.

*En la función main(), se crea un objeto de tipo ComponenteConcreto y se le asigna a un puntero de tipo Componente. 
Luego, se crea un objeto de tipo DecoradorConcreto pasando el puntero del componente como argumento en el constructor.

*Finalmente, se llama al método operacion() en el objeto decorador. La llamada a este método se propaga hacia arriba a 
través de la cadena de decoradores, ejecutando la operación del componente concreto y agregando 
la decoración adicional del decorador concreto.
*/

// Interfaz Componente base
class Componente {
	public:
    	virtual ~Componente() {}
    	virtual std::string operacion() const = 0;
};

// Clase ComponenteConcreto que implementa la interfaz Componente
class ComponenteConcreto : public Componente {
	public:
    	std::string operacion() const override {
        	return "Operacion del Componente Concreto";
    	}
};

// Clase Decorador base
class Decorador : public Componente {
	protected:
    	Componente* componente;
	public:
    	Decorador(Componente* componente) : componente(componente) {}

    	std::string operacion() const override {
        	return componente->operacion();
    	}
};

// Clase DecoradorConcreto que extiende Decorador
class DecoradorConcreto : public Decorador {
	public:
    	DecoradorConcreto(Componente* componente) : Decorador(componente) {}

    	std::string operacion() const override {
        	return "Decoracion adicional | " + Decorador::operacion();
    	}
};

int main() {
    // Crear un componente concreto
    Componente* componente = new ComponenteConcreto();

    // Aplicar decoración adicional al componente
    Componente* decorador = new DecoradorConcreto(componente);

    // Ejecutar la operación, incluyendo la decoración adicional
    std::cout << decorador->operacion() << std::endl;

    delete decorador;
    delete componente;

    return 0;
}