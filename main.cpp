#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Definición de la estructura Producto
struct Producto {
    string codigo;
    string nombre;
    double precio;
    string proveedor;
    int existencia;
    char estado; // Cambio: estado ahora es de tipo char
    double descuento;
};

// Función para agregar un producto
void agregarProducto(vector<Producto> &productos) {
    Producto producto;

    cout << "Ingrese el código del producto: ";
    cin >> producto.codigo;

    // Verificar si el código ya existe
    auto it = find_if(productos.begin(), productos.end(),
        [producto](const Producto& p) { return p.codigo == producto.codigo; });

    if (it != productos.end()) {
        cout << "El código de producto ya existe. No se puede repetir." << endl;
        return;
    }

    cout << "Ingrese el nombre del producto: ";
    cin.ignore();
    getline(cin, producto.nombre);

    cout << "Ingrese el precio del producto: ";
    cin >> producto.precio;

    cout << "Ingrese el proveedor del producto: ";
    cin.ignore();
    getline(cin, producto.proveedor);

    cout << "Ingrese la existencia del producto: ";
    cin >> producto.existencia;

    cout << "Ingrese el estado del producto (A = Aprobado, R = Reprobado): ";
    cin >> producto.estado;

    // Validar que el estado sea 'A' (Aprobado) o 'R' (Reprobado)
    if (producto.estado != 'A' && producto.estado != 'R') {
        cout << "El estado debe ser 'A' o 'R'. No se ha agregado el producto." << endl;
        return;
    }

    cout << "Ingrese el descuento del producto: ";
    cin >> producto.descuento;

    productos.push_back(producto);

    cout << "Producto agregado con éxito." << endl;
}

// Función para buscar productos por código o nombre
void buscarProducto(const vector<Producto> &productos) {
    string consulta;
    cout << "Ingrese el código o nombre del producto a buscar: ";
    cin.ignore();
    getline(cin, consulta);

    cout << "Resultados de la búsqueda:" << endl;

    for (const Producto &producto : productos) {
        if (producto.codigo == consulta || producto.nombre.find(consulta) != string::npos) {
            cout << "Código: " << producto.codigo << endl;
            cout << "Nombre: " << producto.nombre << endl;
            cout << "Precio: " << producto.precio << endl;
            cout << "Proveedor: " << producto.proveedor << endl;
            cout << "Existencia: " << producto.existencia << endl;
            cout << "Estado: " << producto.estado << endl;
            cout << "Descuento: " << producto.descuento << endl;
            cout << "-------------------" << endl;
        }
    }
}

// Función para modificar datos de un producto
void modificarProducto(vector<Producto> &productos) {
    string codigo;
    cout << "Ingrese el código del producto que desea modificar: ";
    cin >> codigo;

    auto it = find_if(productos.begin(), productos.end(),
        [codigo](const Producto& p) { return p.codigo == codigo; });

    if (it != productos.end()) {
        cout << "Producto encontrado. Modifique los datos:" << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, it->nombre);
        cout << "Precio: ";
        cin >> it->precio;
        cout << "Proveedor: ";
        cin.ignore();
        getline(cin, it->proveedor);
        cout << "Existencia: ";
        cin >> it->existencia;

        // Cambio: Permitir modificar el estado
        cout << "Estado (A = Aprobado, R = Reprobado): ";
        cin >> it->estado;

        // Validar que el estado sea 'A' (Aprobado) o 'R' (Reprobado)
        if (it->estado != 'A' && it->estado != 'R') {
            cout << "El estado debe ser 'A' o 'R'. No se ha modificado el producto." << endl;
            return;
        }

        cout << "Descuento: ";
        cin >> it->descuento;

        cout << "Producto modificado con éxito." << endl;
    } else {
        cout << "Producto no encontrado." << endl;
    }
}

// Función principal
int main() {
    vector<Producto> productos;

    int opcion;
    do {
        cout << "Menú:" << endl;
        cout << "1. Agregar producto" << endl;
        cout << "2. Buscar producto" << endl;
        cout << "3. Modificar datos de un producto" << endl;
        cout << "4. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                agregarProducto(productos);
                break;
            case 2:
                buscarProducto(productos);
                break;
            case 3:
                modificarProducto(productos);
                break;
            case 4:
                cout << "Saliendo del programa." << endl;
                break;
            default:
                cout << "Opción no válida. Intente de nuevo." << endl;
        }
    } while (opcion != 4);

    return 0;
}