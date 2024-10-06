// Jose Alfonzo 17-10012

import * as THREE from 'three';

// Creamos la escena donde se coloca el triangulo
const escena = new THREE.Scene();
// Creamos el color de fondo de la escena
escena.background = new THREE.Color(0x1b1e2b);
// Creamos la camara para definir como se vera la escena
const camara = new THREE.PerspectiveCamera(60, window.innerWidth / window.innerHeight, 0.1, 1000);
camara.position.z = 2;

// Crear el renderizador para dibujar la escena en la pantalla
const renderizador = new THREE.WebGLRenderer();
// Le asignamos el tamano de la ventana al renderizador
renderizador.setSize(window.innerWidth, window.innerHeight);
document.body.appendChild(renderizador.domElement);

// Definimos las coordenadas de los vertices del triangulo equilatero
const vertices = new Float32Array([
    -0.5, -0.5, 0.0,  
     0.5, -0.5, 0.0,  
     0.0,  0.5 * Math.sqrt(3) - 0.5, 0.0  
]);

// Definimos los colores de los vertices Rojo, Verde y Azul
const colores = new Float32Array([
    0.0, 1.0, 0.0,
    0.0, 0.0, 1.0,  
    1.0, 0.0, 0.0   
]);

// Creamos la geometria y asignamos los vertices y colores
const geometria = new THREE.BufferGeometry();
geometria.setAttribute('position', new THREE.BufferAttribute(vertices, 3));
geometria.setAttribute('color', new THREE.BufferAttribute(colores, 3));

// Creamos el material para determinar como se vera el triangulo
const material = new THREE.MeshBasicMaterial({ vertexColors: true, side: THREE.DoubleSide });

// Creamos la malla para combinar la geometria y el material
const triangulo = new THREE.Mesh(geometria, material);
escena.add(triangulo);

// Funcion de animacion
function animar() {
    requestAnimationFrame(animar);
    renderizador.render(escena, camara);
}
animar();
