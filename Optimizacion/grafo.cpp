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
		//A[i].clear();
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
            //i: de donde viene
            //j: a donde va
            //dummy.c = coste
            //dummy tiene que tener su j que es a donde va y su coste que es cuanto sale
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

void GRAFO::MostrarCamino(unsigned s, unsigned i, vector<unsigned> pred)
{
  if (i != s)
  {
    MostrarCamino(s,pred[i],pred);
    cout << pred[i]+1 << " - ";
  }
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
    Es_dirigido()? cout<< "\nGrafo no dirigido con " << n << " nodos y con " << m <<" aristas" << endl:
    cout << "\nGrafo dirigido con " << n << " nodos y con " << m << " aristas\n" << endl;
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
//T = ∅
  int T = 0;
  int u = 0;
  int sumaminimo{0};
  vector<int> coste(n, maxint);
  vector<bool> M(n, false);
  vector<int> pred(n, 0);
          //Para todo nodo i de V hacer coste[i] = ∞ 
  coste[0] = 0;
  
  
            //Mientras en T no haya n-1 aristas hacer
  while (T < n) 
  {
            //sea u el último nodo que entró en M //u va a mejorar costes
            //para todo j adyacente a u en V-M hacer
    for (int j = 0;j < LS[u].size(); ++j) 
    {
            //si coste[j] > w(u, j) entonces
      if(M[LS[u][j].j] == false && coste[LS[u][j].j] > LS[u][j].c)
      {
            //coste[j] = w(u,j) //Esta arista es menos costosa
            //pred[j] = u //cambio el nodo de conexión
        coste[LS[u][j].j] = LS[u][j].c;
        pred[LS[u][j].j] = u;
      }
    }
            //sea u = nodo con menor coste en V-M
            //M = M U {u} 
            //T = T U {(u, pred[u])}
    int min{maxint};
    for (int z = 0; z < coste.size(); ++z)
    {
      if(M[z] == false && coste[z] < min)
      {
        min = coste[z];
        u = z;
      }
    }
    M[u] = true;
    T++;
  }
  for (int i = 0; i < coste.size(); i++){
    if(coste[i] != maxint){
      sumaminimo = sumaminimo + coste[i];
    }
  }

  std::cout << "\n";
  cout << " ";

  for(int i = 0; i < n; i++ )
  {
    if(pred[i] != -1 && pred[i] != i)
    { 
      std::cout << "(" << pred[i]+1 << ", " << i+1 << ") ";
      std::cout << "[" << coste[i] << "]\n ";
    }
  }

  std::cout << "El coste del árbol de expansión mínimo es: " << sumaminimo << std::endl;
  cout << "\n";
}

void GRAFO::Dijkstra_(double &comparaciones, unsigned s)
{  
  vector<bool> PermanentementeEtiquetado;
  vector<int> d;
  vector<unsigned> pred;
  int min;
  unsigned candidato;
//Inicialmente no hay ningun nodo permanentemente etiquetado
  PermanentementeEtiquetado.resize(n,false);
//Inicialmente todas las etiquetas distancias son infinito
  d.resize(n,maxint);
//Inicialmente el pred es null
  pred.resize(n,UERROR);
//La etiqueta distancia del nodo origen es 0, y es su propio pred
  d[s]=0; pred[s]=s; comparaciones = 0;
  do
  {
  /*
- Buscamos un nodo candidato a ser permanentemente etiquetado: aquel
de entre los no permanentemente etiquetados, es decir, en el almacén con
menor etiqueta distancia no infinita.
- Si existe ese candidato, lo etiquetamos permanentemente y usamos
los arcos de la lista de sucesores para buscar atajos. Por cada
comparación realizada para buscar atajos, incrementamos el contador de
comparaciones.
- Esto lo hacemos mientras haya candidatos
*/
  }
  while (/*condición de parada*/);
  cout << "Soluciones:" << endl;
//En esta parte del código, mostramos los caminos mínimos para cada nodo si
//los hay.
}

void GRAFO::BellmanFordEnd_(double &comparaciones, unsigned s)
{
  vector<int> d;
  vector<unsigned> pred;
  unsigned numeromejoras = 0;
  bool mejora;
//Idem que en el algoritmo de Dijkstra
  d.resize(n,maxint);
  pred.resize(n,UERROR);
  d[s]=0; pred[s]=s; comparaciones = 0;
  do  
  {
// recorremos todos los arcos, y para cada (i, j), buscamos si d[j] > d[i]
//+ cij, y actualizamos d y pred, incrementando el contador comparaciones
//cuando comparamos, independientemente de si mejoramos o no.
//si al menos en una ocasion ha mejorado una etiqueta distancia, no hemos
//terminado; contabilizamos los bucles en los que ha habido mejoras
  }
  while ((numeromejoras < n) && (mejora == true));
//para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos
//realizado n+1 veces la relajacion con mejora; si mejora es false, pues
//tenemos solucion
//Mostramos los caminos mínimos que se puedan haber encontrado, o
//advertimos de la existencia de un ciclo de coste negativo.
}
