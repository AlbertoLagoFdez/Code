  /*
 *  GRAFO.CPP - Plantilla para la implementaci�n de la clase GRAFOS
 *
 *
 *  Autores : Antonio Sedeno Noda, Sergio Alonso
 *  Cursos   : 2012-2021
 */

#include "grafo.h"
using namespace std;

void GRAFO :: destroy()
{
	for (unsigned i=0; i< n; i++)
    {
		LS[i].clear();
		A[i].clear();
		if (dirigido == 1)
        {
            LP[i].clear();
        };
	}
	LS.clear();
	LP.clear();
	A.clear();

}

void GRAFO :: build (char nombrefichero[85], int &errorapertura)
{
    ElementoLista     dummy;
	ifstream textfile;
	textfile.open(nombrefichero);
	if (textfile.is_open())
    {
		unsigned i, j, k;
		// leemos por conversion implicita el numero de nodos, arcos y el atributo dirigido
		textfile >> (unsigned &) n >> (unsigned &) m >> (unsigned &) dirigido;
		// los nodos internamente se numeran desde 0 a n-1
		// creamos las n listas de sucesores
		LS.resize(n);
        LP.resize(n);
        // leemos los m arcos
    for (k=0;k<m;k++) {
      textfile >> (unsigned &) i  >> (unsigned &) j >> (int &) dummy.c;
      //damos los valores a dummy.j y dummy.c
      //situamos en la posicion del nodo i a dummy mediante push_backM
      //pendiente de hacer un segundo push_back si es no dirigido. O no.
      //pendiente la construccion de LP, si es dirigido
      //pendiente del valor a devolver en errorapertura
      dummy.j = j - 1; // resto a j una unidad, para tener el nodo 1, en la posición cero, el 2 en la 1, etc...
      if(dirigido == 0) // Si es no dirigido, solo tenemos que trabajar con LS
      {
        LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1; // Asignamos el valor del nodo predecesor
        if((i-1) != (j-1)) {
          LS[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo que le precede, y el coste del camino
          // Como es un grafo no dirigido, se ponen todos los datos en LS pero reflejados con la diagonal principal
        }
      }
      if(dirigido == 1) // No pongo un else, por si hay acaso, dirigido != 0 y dirigido !=1
      {
        LS[i-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LS, el nodo al que apunta, y el coste del camino
        dummy.j = i - 1; // Asignamos el valor del nodo predecesor
        LP[j-1].emplace_back(dummy); // Colocamos en la fila del nodo que corresponda en LP, el nodo que le precede, y el coste del camino
        // Como es un grafo dirigido, usamos LP para colocar este dato
        
      }
    }

}
}
void GRAFO::ListaPredecesores(){}
GRAFO::~GRAFO()
{
	destroy();
}

GRAFO::GRAFO(char nombrefichero[85], int &errorapertura)
{
	build (nombrefichero, errorapertura);
}

void GRAFO:: actualizar (char nombrefichero[85], int &errorapertura)
{
    //Limpiamos la memoria dinamica asumida en la carga previa, como el destructor
    destroy();
    //Leemos del fichero y actualizamos G con nuevas LS y, en su caso, LP
    build(nombrefichero, errorapertura);
}

unsigned GRAFO::Es_dirigido()
{
    return (dirigido==0) ? 0 : 1;

}

void GRAFO::Info_Grafo()
{
    Es_dirigido()? cout<< "Grafo no dirigido con " << n << " nodos y con " << m <<" aristas" << endl:
    cout << "Grafo dirigido con " << n << " nodos y con " << m << " aristas" << endl;
}

void Mostrar_Lista(vector<LA_nodo> L)
{
    for(int j = 0; j < L.size(); j++)
    {
        cout << "[" << j+1 << "] :";
        for(int i = 0; i < L[j].size(); i++)
        {
            cout << "(" << L[j][i].j+1 << ", " << L[j][i].c << ")";
        }
        if(L[j].size() == 0)
            cout << "No tiene";
        cout << endl;
    }
}

void GRAFO :: Mostrar_Listas (int l)
{
    if(l == 0 || l == 1)
    Mostrar_Lista(LS);
    if(l == -1){
    Mostrar_Lista(LP);
    }
}

void GRAFO::Mostrar_Matriz() //Muestra la matriz de adyacencia, tanto los nodos adyacentes como sus costes
{

}

void GRAFO::dfs_num(unsigned i, vector<LA_nodo>  L, vector<bool> &visitado, vector<unsigned> &prenum, unsigned &prenum_ind, vector<unsigned> &postnum, unsigned &postnum_ind) //Recorrido en profundidad recursivo con recorridos enum y postnum
{
	visitado[i] = true;
    prenum[prenum_ind++]=i;//asignamos el orden de visita prenum que corresponde el nodo i
    for (unsigned j=0;j<L[i].size();j++)
             if (!visitado[L[i][j].j])
                {
                dfs_num(L[i][j].j, L, visitado, prenum, prenum_ind, postnum, postnum_ind);
                };
    postnum[postnum_ind++]=i;//asignamos el orden de visita posnum que corresponde al nodo i
}

void GRAFO::RecorridoProfundidad()
{

}

void GRAFO::bfs_num(	unsigned i, //nodo desde el que realizamos el recorrido en amplitud
				vector<LA_nodo>  L, //lista que recorremos, LS o LP; por defecto LS
				vector<unsigned> &pred, //vector de predecesores en el recorrido
				vector<unsigned> &d) //vector de distancias a nodo i+1
//Recorrido en amplitud con la construcci�n de pred y d: usamos la cola
{
    vector<bool> visitado; //creamos e iniciamos el vector visitado
    visitado.resize(n, false);
    visitado[i] = true;

    pred.resize(n, 0); //creamos e inicializamos pred y d
    d.resize(n, 0);
    pred[i] = i;
    d[i] = 0;

    queue<unsigned> cola; //creamos e inicializamos la cola
    cola.push(i);//iniciamos el recorrido desde el nodo i+1

    while (!cola.empty()) //al menos entra una vez al visitar el nodo i+1 y contin�a hasta que la cola se vac�e
    {   unsigned k = cola.front(); //cogemos el nodo k+1 de la cola
        cola.pop(); //lo sacamos de la cola
        //Hacemos el recorrido sobre L desde el nodo k+1
        for (unsigned j=0;j<L[k].size();j++)
            //Recorremos todos los nodos u adyacentes al nodo k+1
            //Si el nodo u no est� visitado
            {
                if (!visitado[L[k][j].j]){
                    visitado[L[k][j].j] = true;
                    cola.push(L[k][j].j);
                    pred[L[k][j].j] = k;
                    d[L[k][j].j] = d[k] + 1;
            //Lo visitamos
            //Lo metemos en la cola
            //le asignamos el predecesor
            //le calculamos su etiqueta distancia
            };
        //Hemos terminado pues la cola est� vac�a
    };
}
}

void GRAFO::RecorridoAmplitud() {
  vector<unsigned> pred;    // Declaramos el vector de nodos predecesores, la posición es el vector actual, y el número que contiene es su predecesor
  vector<unsigned> d;       // Declaramos el vector de etiquetas distancia, la posición es el nodo, y el número que contenga, es la distancia del nodo elegido por el usuario
  int nodo{0};
  int d_maxima{0};         // Distancia máxima entre el nodo inicial y el resto de nodos
  cout << "\nElige el nodo inicial en el rango [1 - " << n << "]: ";
  cin >> nodo;
  cout << "Nodo inicial elegido [" << nodo << "]" << endl << endl;
  nodo -= 1;
  bfs_num(nodo, LS, pred, d);
  cout << "Distancia: " << endl << endl;

  for(int i{0}; i < d.size(); ++i){ //Recorremos el vector de distancias para encontrar la máxima
    if(d[i] > d_maxima){
      d_maxima = d[i];
    }
  }
  ++d_maxima;

  for(int i{0}; i < d_maxima; ++i) { // Recorremos el vector de distancias para mostrar los nodos a distancia i
    cout << "Nodos a distancia " << i;
    if(i == 0)  {
      cout << " : " << nodo + 1;
      nodo = 0;
    } else {
      for(int j{0}; j < n; ++j) { // por cada distancia, recorremos todos los nodos
        if(d[j] == i) { // Si la distancia del nodo j es igual a i, lo mostramos
            cout << " : " << j + 1;
        }
        ++nodo; // Incrementamos el nodo inicial
      }
    nodo = 0; // Reiniciamos el nodo inicial
    }
    cout << endl;
  }
  // Mostramos los predecesores
  cout << endl << "Predecesores de cada nodo" << endl << endl;
  for(int i{0}; i < pred.size(); ++i) {
    cout << "Predecesor de " << i + 1 << " : ";
    if (pred[i] == i) {
      //cout << pred[i]+1 << endl;
      cout << "él mismo" << endl;
    } else {
      cout << pred[i] + 1 << endl;
    }

  }
  cout << endl;
}

void GRAFO::Prim(){
  std::vector<LA_nodo> P; //Usaremos la misma estructura de datos de LS para guardar P y D
  std::vector<bool> visitados; //Vector de booleanos para saber si un nodo ha sido visitado o no
  visitados.resize(n, false);
  std::vector<int> costes; //Vector de costes para saber el coste mínimo de cada nodo
  std::vector<int> predecesores; //Vector de predecesores para saber el nodo que lo precede
  costes.resize(n);
  predecesores.resize(n);
  int nodoActual{0}; //Nodo actual
  int nodoMenorCoste{0}; //Nodo con menor coste
  int costeMenor{0}; //Coste menor
  int costeTotal{0}; //Coste total del árbol

  //Inicializamos P y D en P
  //Creamos P
  P.resize(n); //Ya tenemos las posiciones P[0] a P[n-1]
  for (unsigned i{0}; i < n; ++i) P[i].resize(n); //Ya tenemos la matriz cuadrada
  for (unsigned i{0}; i < n; ++i) {
  for (unsigned j{0}; j < n; ++j) {
    if (i != j) {// Inicialización base
      P[i][j].j = -1; //en el campo .j ponemos el predecesor
      P[i][j].c = maxint; //en el campo .c ponemos el coste
    } else {// Inicializamos los bucles
      P[i][j].c = 0; //El coste en el caso de un bucle
      P[i][j].j = i; //El predecesor en el caso de un bucle
    }
  }
  }
  //Recorremos LS para inicializar P, su predecesor en .j y su distancia en .c
  for (unsigned i{0}; i < n; ++i) {
    for (unsigned j{0}; j < LS[i].size(); ++j) {
        P[i][LS[i][j].j].j = i;
        P[i][LS[i][j].j].c = LS[i][j].c;
    }
  }

  for (unsigned i{0}; i < n; ++i) {
    visitados[i] = false;
    costes[i] = maxint;
    predecesores[i] = -1;
  }

  //Inicializamos el nodo actual y el coste menor
  nodoActual = 0;
  costeMenor = 0;

  //Bucle principal
  while (nodoActual != -1) {
    //Marcamos el nodo actual como visitado
    visitados[nodoActual] = true;
    //Recorremos la fila del nodo actual
    for (unsigned i{0}; i < n; ++i) {
      //Si el nodo no ha sido visitado y el coste es menor que el coste actual
      if ((visitados[i] == false) && (P[nodoActual][i].c < costes[i])) {
        //Actualizamos el coste y el predecesor
        costes[i] = P[nodoActual][i].c;
        predecesores[i] = nodoActual;
      }
    }
    //Buscamos el nodo con menor coste
    nodoMenorCoste = -1;
    costeMenor = maxint;
    for (unsigned i{0}; i < n; ++i) {
      if ((visitados[i] == false) && (costes[i] < costeMenor)) {
        nodoMenorCoste = i;
        costeMenor = costes[i];
      }
    }
    //Actualizamos el nodo actual
    nodoActual = nodoMenorCoste;
  }

  //Mostramos el árbol por pantalla
  std::cout << "Árbol generado por el algoritmo de Prim:\n\n";
  for (unsigned i{0}; i < n; ++i) {
    if (predecesores[i] != -1) {
      std::cout << "Nodo " << predecesores[i] + 1 << " -> Nodo " << i + 1 << " | Coste: " << costes[i] << std::endl;
      costeTotal += costes[i];
    }
  }
  std::cout << "\nCoste total del árbol: " << costeTotal << std::endl;
}




