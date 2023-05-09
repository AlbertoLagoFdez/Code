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
    min = maxint;
    candidato = UERROR;

    for(unsigned i = 0; i < n; i++)
    {
      if (!PermanentementeEtiquetado[i] && d[i] < min)
      {
        min = d[i];
        candidato = i;
      }
    }

    if(candidato == UERROR) break;

    PermanentementeEtiquetado[candidato] == true;

    for(unsigned i = 0; i<LS[candidato].size() ; i++)
    {
      if(d[LS[candidato][i].j] > d[candidato] + LS[candidato][i].c)
      {
        d[LS[candidato][i].j] = d[candidato] + LS[candidato][i].c;
        pred[LS[candidato][i].j] = candidato;
      }
      comparaciones++;
    }
  }
  while (candidato != UERROR);
  cout << "Soluciones:" << endl;
  for( unsigned i = 0; i<n; i++)
  {
    if(d[i] != maxint)
    {
      cout << "Elcamino mínimo desde " << s+1 << " hasta " << i+1 << " es: ";
      cout << i+1 << " <- " << pred[i]+1;
      cout << " y su longitud es " << d[i] << endl;
    }
  }
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
    mejora = false;
    for(unsigned i = 0; i<n ; i++)
    {
      for (unsigned j = 0; j<LS[i].size(); j++) 
      {
        if(d[LS[i][j].j] < d[i] + LS[i][j].c)
        {
          d[LS[i][j].j] = d[i] + LS[i][j].c;
          pred[LS[i][j].j] = i;
          mejora = true;
        }
        comparaciones++;
      }
    }
    numeromejoras++;
  }
  while ((numeromejoras < n) && (mejora == true));
//para salir del bucle, si mejora es true, pues hay un ciclo, pues hemos
//realizado n+1 veces la relajacion con mejora; si mejora es false, pues
//tenemos solucion
//Mostramos los caminos mínimos que se puedan haber encontrado, o
//advertimos de la existencia de un ciclo de coste negativo.
  if(mejora == true)
  {
    cout << "Hay un ciclo de coste negativo" << endl;
  } 
  else
  {
    cout << "Soluciones: " << endl;
    for(unsigned i = 0; i < n; i++)
    {
      if(d[i] != maxint)
      {
        cout<< "Nodo " << i+1 << ": ";
        cout << i+1 << " <- ";
        cout << " | Coste Total: " << d[i] << endl;
      }
    }
  }
}











