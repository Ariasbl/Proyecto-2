class Producto:
    def __init__(self, codigo, nombre, precio, existencia, estado, descuento):
        self.codigo = codigo
        self.nombre = nombre
        self.precio = precio
        self.existencia = existencia
        self.estado = estado
        self.descuento = descuento

def agregar_producto(productos):
    codigo = input("Código: ")
    
    # Verificar si el código ya existe
    for p in productos:
        if p.codigo == codigo:
            print("El código ya existe. No se puede repetir.")
            return
    
    nombre = input("Nombre: ")
    precio = float(input("Precio: "))
    existencia = int(input("Existencia: "))
    estado = input("Estado (A = Aprobado, R = Reprobado): ")
    descuento = float(input("Descuento: "))
    producto = Producto(codigo, nombre, precio, existencia, estado, descuento)
    productos.append(producto)
    print("Producto agregado con éxito.")

def buscar_producto(productos):
    consulta = input("Ingrese el código o nombre del producto a buscar: ")
    print("Resultados de la búsqueda:")
    
    for producto in productos:
        if consulta in [producto.codigo, producto.nombre]:
            print("Código:", producto.codigo)
            print("Nombre:", producto.nombre)
            print("Precio:", producto.precio)
            print("Existencia:", producto.existencia)
            print("Estado:", producto.estado)
            print("Descuento:", producto.descuento)
            print("-------------------")

def modificar_producto(productos):
    codigo = input("Ingrese el código del producto que desea modificar: ")
    
    for producto in productos:
        if producto.codigo == codigo:
            print("Producto encontrado. Modifique los datos:")
            producto.nombre = input("Nombre: ")
            producto.precio = float(input("Precio: "))
            producto.existencia = int(input("Existencia: "))
            estado = input("Estado (A = Aprobado, R = Reprobado): ")
            
            if estado in ['A', 'R']:
                producto.estado = estado
            else:
                print("El estado debe ser 'A' o 'R'. No se ha modificado el producto.")
                return
            
            producto.descuento = float(input("Descuento: "))
            print("Producto modificado con éxito.")
            return
    
    print("Producto no encontrado.")

def guardar_productos(productos):
    with open("productos.txt", "w") as file:
        for producto in productos:
            file.write(f"{producto.codigo},{producto.nombre},{producto.precio},{producto.existencia},{producto.estado},{producto.descuento}\n")

def cargar_productos():
    productos = []
    try:
        with open("productos.txt", "r") as file:
            for line in file:
                codigo, nombre, precio, existencia, estado, descuento = line.strip().split(",")
                
                # Verificar si el código ya existe
                codigo_existente = [producto.codigo for producto in productos]
                if codigo not in codigo_existente:
                    producto = Producto(codigo, nombre, float(precio), int(existencia), estado, float(descuento))
                    productos.append(producto)
    except FileNotFoundError:
        pass
    
    return productos

def main():
    productos = cargar_productos()
    
    while True:
        print("Menú:")
        print("1. Agregar producto")
        print("2. Buscar producto")
        print("3. Modificar datos de un producto")
        print("4. Salir")
        opcion = int(input("Ingrese una opción: "))
        
        if opcion == 1:
            agregar_producto(productos)
            guardar_productos(productos)
        elif opcion == 2:
            buscar_producto(productos)
        elif opcion == 3:
            modificar_producto(productos)
            guardar_productos(productos)
        elif opcion == 4:
            print("Saliendo del programa.")
            break
        else:
            print("Opción no válida. Intente de nuevo.")

if __name__ == "__main__":
    main()
