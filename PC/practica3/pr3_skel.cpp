#include <iostream>

// En C++ para poder utilizar el indexado de una matriz (bidimensional)
// mediante dos pares de corchetes el número de filas y columnas no pude cambiar,
// debe ser constante y conocido desde el principio.
//
// En esta práctica queremos cambiar el número de filas y columnas de la matriz
// considerada.
// Para poder emular en C++ lo que podemos hacer en ensamblador
// vamos a manejar la matriz como un vector.
// Para acceder al elenemto en la fila de índice `f` y columna de índice `c`
// no podemos hacer `mat[f][c]` sino que debemos hacer `mat[f*ncol+c]`

/*
f1,c1
f2,c2

int aux = mat[f1][c1];
mat[f1][c1] = mat[f2][c2];
mat[f2][c2] = aux;               f2*ncol+c2
*/

/*
for(int i = 0; i <    ; i++){
    cout << mat[i][i];
}
*/
int main(void) {

  int mat[] = {
    100, 101, 102, 103, 104, 105, 106, 107, 108, 109, 110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
    120, 121, 122, 123, 124, 125, 126, 127, 128, 129, 130, 131, 132, 133, 134, 135, 136, 137, 138, 139,
    140, 141, 142, 143, 144, 145, 146, 147, 148, 149, 150, 151, 152, 153, 154, 155, 156, 157, 158, 159,
    160, 161, 162, 163, 164, 165, 166, 167, 168, 169, 170, 171, 172, 173, 174, 175, 176, 177, 178, 179,
    180, 181, 182, 183, 184, 185, 186, 187, 188, 189, 190, 191, 192, 193, 194, 195, 196, 197, 198, 199,
    200, 201, 202, 203, 204, 205, 206, 207, 208, 209, 210, 211, 212, 213, 214, 215, 216, 217, 218, 219,
    220, 221, 222, 223, 224, 225, 226, 227, 228, 229, 230, 231, 232, 233, 234, 235, 236, 237, 238, 239,
    240, 241, 242, 243, 244, 245, 246, 247, 248, 249, 250, 251, 252, 253, 254, 255, 256, 257, 258, 259,
    260, 261, 262, 263, 264, 265, 266, 267, 268, 269, 270, 271, 272, 273, 274, 275, 276, 277, 278, 279,
    280, 281, 282, 283, 284, 285, 286, 287, 288, 289, 290, 291, 292, 293, 294, 295, 296, 297, 298, 299,
    300, 301, 302, 303, 304, 305, 306, 307, 308, 309, 310, 311, 312, 313, 314, 315, 316, 317, 318, 319,
    320, 321, 322, 323, 324, 325, 326, 327, 328, 329, 330, 331, 332, 333, 334, 335, 336, 337, 338, 339,
    340, 341, 342, 343, 344, 345, 346, 347, 348, 349, 350, 351, 352, 353, 354, 355, 356, 357, 358, 359,
    360, 361, 362, 363, 364, 365, 366, 367, 368, 369, 370, 371, 372, 373, 374, 375, 376, 377, 378, 379,
    380, 381, 382, 383, 384, 385, 386, 387, 388, 389, 390, 391, 392, 393, 394, 395, 396, 397, 398, 399,
    400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 418, 419,
    420, 421, 422, 423, 424, 425, 426, 427, 428, 429, 430, 431, 432, 433, 434, 435, 436, 437, 438, 439,
    440, 441, 442, 443, 444, 445, 446, 447, 448, 449, 450, 451, 452, 453, 454, 455, 456, 457, 458, 459,
    460, 461, 462, 463, 464, 465, 466, 467, 468, 469, 470, 471, 472, 473, 474, 475, 476, 477, 478, 479,
    480, 481, 482, 483, 484, 485, 486, 487, 488, 489, 490, 491, 492, 493, 494, 495, 496, 497, 498, 499,
  };

  const int maximoElementos=400;
  int nfil = 20;
  int ncol = 10;
  int opcion;
  do{
  // se imprimie el título
  std::cout << "\nPráctica PR3 de Principios de Computadores. Matrices.\n";

  std::cout << "\nLa matriz es " << nfil << "x" << ncol << "\n";
  for ( int f = 0; f < nfil; f++) {
    for (int c = 0; c < ncol; c++ ) {
      std::cout << mat[f*ncol+c] << "  "; // equivalente a acceso `mat[f][c]`
    }
    std::cout << "\n";
  }
  
  std::cout << "\n(1) Cambiar dimensiones";
  std::cout << "\n(2) Intercambiar dos elementos";
  std::cout << "\n(3) Suma elementos del perimetro";
  std::cout << "\n(4) Calcula max y min de la diagonal";
  std::cout << "\n(0) Salir\n\nOpcion: ";
  std::cin >> opcion;

  if(opcion == 0) break;
  if(opcion == 1) {
    do {
    std::cout << "Nuevo número de filas: ";
    std::cin >> nfil;
    std::cout << "Nuevo número de columnas: ";
    std::cin >> ncol;
    if (ncol > 20 || nfil > 20 || ncol < 0 || nfil < 0){
      std::cout << "Error: dimension incorrecta. Excede el maximo numero de elementos (400).\n";
    }
    }
    while (ncol > 20 || nfil > 20 || ncol < 0 || nfil < 0);
    for(int f = 0; f < nfil; f++) {
        for(int c = 0; c < ncol; c++) {
            std::cout << mat[f*ncol+c] << "  ";
        }
        std::cout << "\n";
    }
  }

  if(opcion == 2) {
    int f1, c1, f2, c2;
    
    std::cout << "Introduzca la fila del primer elemento a cambiar: " ;
    std::cin >> f1;
    std::cout << "Introduzca la columna del primer elemento a cambiar: ";
    std::cin >> c1;
    std::cout << "Introduzca la fila de segundo elemento a cambiar: ";
    std::cin >> f2;
    std::cout << "Introduzca la columna del segundo elemento a cambiar: ";
    std::cin >> c2;
    if(f1 > nfil || f2 > nfil) {
      std::cout << "\nError: Dimension incorrecta. Número de fila incorrecta.\n";
    }
    if(c1 > ncol || c2 > ncol) {
      std::cout << "\nError: Dimension incorrecta. Número de columnas.\n";
    }
    else {
    int aux = mat[f1*ncol+c1];
    mat[f1*ncol+c1] = mat[f2*ncol+c2];
    mat[f2*ncol+c2] = aux;

      for(int f = 0; f < nfil; f++) {
        for(int c = 0; c < ncol; c++) {
          std::cout << mat[f*ncol+c] << "  ";
        }
        std::cout << "\n";
      }
    }
  }

  if(opcion == 3) {   // arreglar fallos
    if(nfil > 2 && ncol > 2) {
      int suma = 0;
      for(int i = 0; i < ncol; i++) {
        suma += mat[0*ncol+i];
      }
      for(int i = 0; i < ncol; i++) {
        suma += mat[(nfil-1)*ncol+i];
      }
      for(int j = 1; j < nfil - 1; j++) {
        suma += mat[j*ncol+0];
      }
      for (int j = 1; j < nfil-1; j++) {
        suma += mat[j*ncol+(ncol-1)];
      }
      std::cout << "Suma de los elementos del perimetro: " << suma << std::endl;
    }
    if(nfil == 2 || ncol == 2) {
      int suma = 0;
      for (int i = 0; i < nfil; i++) {
        for (int j = 0; j < ncol; j++) {
          suma += mat[i*ncol+j];
        }
      }
      std::cout << "Suma de los elementos del perimetro: " << suma << std::endl;
    } 
    if (nfil == 1) {
      int suma = 0;
      for (int i = 0; i < ncol; i++) {
        suma += mat[0*ncol+i];
      }
      std::cout << "Suma de los elementos del perimetro: " << suma << std::endl;
    }
    if (ncol == 1) {
      int suma = 0;
      for (int i = 0; i < nfil; i++) {
        suma += mat[0*ncol+1];
      }
      std::cout << "Suma de los elementos del perimetro: " << suma << std::endl;
    }
    if(ncol == 1 && nfil == 1)
    {
      std::cout << "Suma de los elementos del perimetro: " << mat[0*ncol+0] << std::endl;
    }
  }

  if(opcion == 4) {
    if(nfil == ncol) {
      std::cout << "El máximo de la diagonal princial es " << mat[(nfil-1)*ncol+(nfil-1)];
      std::cout << " y el mínimo " << mat[0*ncol+0] << std::endl; 
    }
    if (ncol < nfil) {
      std::cout << "El máximo de la diagonal princial es " << mat[(ncol-1)*ncol+(ncol-1)];
      std::cout << " y el mínimo " << mat[0*ncol+0] << std::endl;
    }
    if (nfil < ncol) {
      std::cout << "El máximo de la diagonal princial es " << mat[(nfil-1)*ncol+(nfil-1)];
      std::cout << " y el mínimo " << mat[0*ncol+0] << std::endl; 
    }
  }

  } while(true);
}
