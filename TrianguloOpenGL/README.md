# Jose Alfonzo 17-10012
## Pasos para instalar OpenGL en Linux

Nota: Se utilizo un sistema operativo Linux con el compilador g++ ya intalado en Visual Studio Code

1) Abra la terminal
2) Instalamos las siguientes dependencias con los siguiente comandos:

``` sudo apt update ```

``` sudo apt-get install libglew-dev libsdl2-dev libsdl2-image-dev libglm-dev libfreetype6-dev```

```sudo apt install mesa-utils libglu1-mesa-dev freeglut3-dev mesa-common-dev ```

3) Luego de que el servidor de ventanas este en funcionamiento, usamos los siguientes comandos:

``` export DISPLAY=$(awk '/nameserver / {print $2; exit}' /etc/resolv.conf):0 ```

``` export LIBGL_ALWAYS_INDIRECT=0 ```

4) Probamos que se instalo correctamente OpenGL:

``` export LIBGL_ALWAYS_INDIRECT=0```

5) Con el siguiente comando se observa mas informacion de tu OpenGL instalado:

```glxinfo | grep OpenGL```

## Pasos para ejecutar openGLTriangulo en Visual Studio Code

1) Abra la terminal

2) Compile el archivo openGLTriangulo:

```g++ openGLTriangulo.cpp -o openGLTriangulo  -lglfw -lGLEW -lGL ```

3) Ejecute el archivo openGLTriangulo:

```./openGLTriangulo ```

