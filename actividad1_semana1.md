# Grupo 10

Integrantes:
- Cristhyan Manuel Perez Villegas
- Angel Navarro Ruiz

#### Bloque 1 - Núcleo conceptual de Semana1

Revisen:

* `Semana1/README.md`
* `Semana1/src/bubble_sort.cpp`
* `Semana1/src/power.cpp`
* `Semana1/src/fibonacci.cpp`
* `Semana1/src/count_ones.cpp`
* `Semana1/demos/demo_adt_secuencia.cpp`

Respondan:

1. Expliquen con sus palabras la diferencia entre **problema**, **algoritmo**, **ADT** e **implementación**.

Un problema es lo que se quiere resolver (el objetivo),
Un algoritmo es el conjunto de pasos lógicos para resolver ese problema,
Un ADT describe qué hace la estructura y qué operaciones se pueden hacer sin importar su implementación interna,
La implementación es el código concreto (C++) que lleva a la práctica ese algoritmo y ese ADT.

Una analogía perfecta sería el construir una casa en donde:
- Problema: Un lugar para vivir y protegerme de la lluvia y el frío.
- Algoritmo: el plan paso a paso: primero los cimientos, luego las paredes, luego el techo, luego las instalaciones eléctricas, etc.
- ADT: los planos arquitectónicos. Dicen que la casa tendrá puertas, ventanas y habitaciones, pero no dicen de qué material serán ni cómo exactamente se construirán
- Implementaciónla construcción real. Aquí se decide si las paredes son de ladrillo o concreto. Es el "cómo" concreto.
  
2. En `bubble_sort.cpp`, expliquen qué observable conecta correctitud y costo.

El numero de comparaciones es el observable que conecta correctitud y costo. El algoritmo sabe que el arreglo está correctamente ordenado cuando hace una pasada completa sin encontrar ningún swap, es decir, sin inversiones, lo que dispara el !changed y detiene el loop. Y ese mismo número de comparaciones define el costo: cuantas menos comparaciones se hagan, más eficiente es el algoritmo, que es exactamente lo que optimiza la versión mejorada usando lastSwapIndex para ignorar zonas donde ya no puede haber inversiones.

3. En `power.cpp`, expliquen por qué `power` mejora la idea de una versión ingenua.

Power es más eficiente porque reduce el número de multiplicaciones de O(n) a O(logn) al dividir el exponente entre 2 en cada iteración.
Un ejemplo sencillo sería 2^8, la versión ingenua podría ser 2x2x...x2 sin embargo, la versión power primero transforma (2^4)^2 luego 2^4 en (2^2)^2 y así sucesivamente reduciendo el problema, pasando de 8 multiplicaciones a 3. De esta forma se muestra por qué es más eficiente.

4. En `fibonacci.cpp`, expliquen por qué una función puede ser correcta y aun así ser una mala elección práctica.

En fibonacci.cpp se ve que una función puede ser correcta y, sin embargo, no ser la mejor opción en la práctica, porque correctitud y eficiencia no es mismo.

Desde el punto de vista conceptual, esta función está bien planteada, porque si se le da un n adecuado, devuelve el Fibonacci correcto. El problema es que esta versión recursiva hace muchísimo trabajo repetido. Para calcular fib(n), llama a fib(n-1) y fib(n-2), pero dentro de esas llamadas se vuelven a recalcular los mismos valores muchas veces. Por ejemplo, para calcular fib(6):

fib(6) necesita fib(5) y fib(4)
fib(5) necesita fib(4) y fib(3)
fib(4) vuelve a necesitar fib(3) y fib(2)

Entonces, valores como fib(4), fib(3) o fib(2) se calculan repetidamente, aunque ya habían aparecido antes. Es decir, la función es correcta, pero desperdicia tiempo repitiendo subproblemas.

Por eso, su costo temporal crece de manera exponencial, aproximadamente O(2^n)
En valores pequeños puede funcionar bien, pero cuando n aumenta, el tiempo de ejecución se dispara y deja de ser razonable. En este caso, la solución puede ser matemáticamente válida, pero computacionalmente ineficiente.

5. En `count_ones.cpp`, expliquen por qué el tamaño de entrada no siempre coincide con el valor numérico.

El tamaño de entrada es siempre fijo en 32 bits porque 'unsigned int' ocupa ese espacio en memoria sin importar nada más, mientras que el valor numérico depende de qué número estás representando. Por ejemplo, 361 ocupa los mismos 32 bits que 1 o que 4294967295, pero cada uno tiene un valor y una cantidad de unos completamente distinta. Son tres cosas independientes: el espacio que ocupa (tamaño), el número que representa (valor numérico) y cuántos bits en 1 tiene (lo que cuentan estas funciones).

6. En `demo_adt_secuencia.cpp`, expliquen por qué la misma interfaz puede convivir con representaciones distintas.

La misma interfaz puede convivir con representaciones distintas porque se utiliza una clase abstracta (IntSequence) que define las operaciones del ADT sin especificar su implementación.

Las clases FixedArraySequence y VectorSequence implementan esa misma interfaz, pero usan estructuras internas diferentes (un arreglo fijo y un std::vector, respectivamente).

Gracias al uso de métodos virtual y al polimorfismo, el código cliente (como run_scenario) puede trabajar con objetos de tipo IntSequence sin conocer su representación interna. En tiempo de ejecución, se ejecuta la implementación correspondiente según el tipo real del objeto.

(Porque la interfaz separa el “qué” del “cómo”, y gracias al polimorfismo (virtual), distintas implementaciones pueden usarse de forma transparente.)

#### Bloque 2 - Demos y trazado guiado

Revisen:

* `Semana1/demos/demo_bubblesort.cpp`
* `Semana1/demos/demo_power.cpp`
* `Semana1/demos/demo_fibonacci.cpp`
* `Semana1/demos/demo_countones.cpp`

Construyan una tabla con cuatro columnas:

* archivo,
* salida u observable importante,
* idea algorítmica,
* argumento de costo.

| archivo | salida u observable importante | idea algorítmica | argumento de costo |
|---|---|---|---|
| `demo_bubblesort.cpp` | Muestra el arreglo antes y después, con conteo de comparaciones, intercambios y posición del último swap. Entonces, la salida clave es el struct 'BubbleStats'| Bubble Sort optimizado: compara vecinos e intercambia si están en desorden, recortando la siguiente pasada al índice del último intercambio. | Peor caso cuadrático, pero la optimización evita revisar el sufijo ya ordenado y puede terminar antes. |
| `demo_power.cpp` | Compara resultados de versiones brutas (`BF`) y optimizadas de potenciación para la misma entrada. | Exponenciación binaria: en vez de multiplicar `n` veces, aprovecha los bits del exponente elevando al cuadrado sucesivamente. | Las versiones `BF` son `O(n)`; las optimizadas reducen iteraciones a `O(log n)` desplazando el exponente a la derecha. |
| `demo_fibonacci.cpp` | Muestra que `fibI`, `fib` y `fib(n, prev)` producen el mismo resultado, más los primeros 8 términos desde la clase `Fib`. | Tres estrategias para el mismo problema, iterativa, recursiva ingenua y recursiva con arrastre del término anterior. | `fibI` y `fib(n, prev)` son lineales; `fib(n)` recursiva es exponencial por recomputación de subproblemas. |
| `demo_countones.cpp` | Imprime `x`, su representación binaria y el conteo de bits en 1 con ambos métodos. | `countOnes1` elimina el bit menos significativo en 1 con `n &= (n-1)`; `countOnes2` agrupa y suma bits por bloques. | `countOnes1` cuesta proporcional al número de bits en 1; `countOnes2` hace rondas fijas, así que es `O(w)` para tipos de tamaño fijo. |

Luego respondan:

1. En `demo_bubblesort.cpp`, ¿qué salida sirve para defender costo y no solo resultado?

La salida que sirve para defender costo y no solo resultado es el struct "BubbleStats", que registra "comparisons", "swaps" y "lastSwapIndex".
El arreglo ordenado al final solo demuestra que el algoritmo es correcto, pero no dice nada sobre cuánto trabajo costó llegar ahí. En cambio, "BubbleStats" permite cuantificar el costo real, responde a cuántas comparaciones y cuántos intercambios se hicieron, que son las operaciones elementales del algoritmo. Esto es lo que hace posible comparar "bubbleSortBasic" contra "bubbleSortOptimized" de forma concreta. Ambas producen el mismo arreglo ordenado, pero la versión optimizada, al usar "lastSwapIndex" para reducir el rango de la siguiente pasada y al detenerse temprano si no hubo cambios, puede reportar menos comparaciones y swaps en BubbleStats. Sin esos contadores, ambas versiones serían indistinguibles ya que tienen mismo input, mismo output. Es "BubbleStats" lo que permite defender que una es más eficiente que la otra.

2. En `demo_power.cpp`, ¿qué comparación concreta muestra una mejora algorítmica?

La comparación concreta que muestra una mejora algorítmica es powerBF vs power (potencia por fuerza bruta vs potencia por exponenciación rápida).

"powerBF" se multiplica "a" por sí mismo "n" veces en un bucle lineal, así que su complejidad es O(n). En cambio, power usa la técnica de exponenciación binaria (también llamada square-and-multiply): en cada iteración revisa el bit menos significativo de n, multiplica acumulando solo cuando ese bit es 1, y luego eleva al cuadrado la base mientras desplaza n a la derecha. Como el número de bits de n es log₂(n), la complejidad baja a O(log n).

Por ejemplo, para calcular a^16, powerBF hace 16 multiplicaciones, mientras que power solo necesita alrededor de 4 (los 4 pasos de bits de 16 = 10000₂). A medida que n crece, la diferencia se vuelve enorme: para n = 1 000 000, son un millón de multiplicaciones contra aproximadamente 20.

La mejora se vuelve visible cuando el exponente crece: para exp = 1000, powerBF haría 1000 multiplicaciones y power solo alrededor de 10.

3. En `demo_fibonacci.cpp`, ¿qué crecimiento se vuelve defendible?

El crecimiento que se vuelve defendible es el lineal O(n), presente en fibI y fib(n, prev).
La versión recursiva ingenua fib(n) tiene crecimiento exponencial O(2ⁿ) porque recalcula los mismos subproblemas repetidamente y aqui cada llamada genera dos llamadas más, formando un árbol de recursión que crece exponencialmente.
En cambio, "fibI" resuelve el mismo problema en O(n) con un bucle que mantiene solo dos variables (f y g), avanzando linealmente sin recalcular nada. La versión fib(n, prev) logra lo mismo recursivamente ya que al devolver el valor anterior a través del parámetro por referencia prev, cada nivel de recursión hace una sola llamada recursiva en vez de dos, resultando en una cadena lineal de n llamadas.
El salto de O(2ⁿ) a O(n) es lo que hace defendible a estas dos versiones. Para n = 50, fib(n) generaría más de 10¹⁴ llamadas, mientras que fibI y fib(n, prev) solo necesitan 50 iteraciones.

4. En `demo_countones.cpp`, ¿qué ejemplo ayuda más a distinguir valor numérico de tamaño en bits?

El ejemplo que mejor distingue valor numérico de tamaño en bits es "countOnes1". Su bucle ejecuta "n &= (n - 1)" que apaga el bit menos significativo en cada iteración, así que el número de iteraciones es igual a la cantidad de bits en 1, no al valor de n. Esto se ve claramente comparando dos casos, el número 128 (10000000₂) tiene valor grande pero solo 1 bit encendido, por lo que el bucle itera una sola vez. En cambio, 7 (111₂) tiene valor pequeño pero 3 bits encendidos, y el bucle itera tres veces. Así queda en evidencia que el costo depende del tamaño en bits (cuántos unos hay), no del valor numérico.

La complejidad de 'countOnes1' es 'O(ones)', mientras que 'countOnes2', al usar rondas fijas de ROUND sobre el ancho de palabra de 32 bits, opera en 'O(log w)' constante, independiente tanto del valor como de los bits encendidos.

#### Bloque 3 - Pruebas públicas y preparación de sustentación

Revisen:

* `Semana1/pruebas_publicas/README.md`
* `Semana1/pruebas_publicas/test_public_week1.cpp`
* `Semana1/pruebas_publicas/test_public_week1_extra.cpp`
* `Semana1/sustentacion/preguntas_semana1.md`
* `Semana1/sustentacion/rubrica_semana1.md`

Respondan:

1. ¿Qué funciones o ideas están verificando las pruebas públicas?

Verifican que los algoritmos implementados (sumas, potencias, Fibonacci, ordenamiento, etc.) produzcan resultados correctos, incluyendo versiones iterativas y recursivas, y que cumplan el comportamiento esperado en distintos casos.

Verifican: 
- correctitud funcional
- consistencia entre versiones iterativas y recursivas
- casos básicos y algunos casos borde
  
2. ¿Qué sí demuestra una prueba pública?

Un prueba pública demuestra que las funciones funcionan correctamente ante los casos probados. Es decir evidencia correctitud parcial al verificar comportamientos esperados en entradas definidas.

3. ¿Qué no demuestra una prueba pública?

Una prueba pública no demuestra que un programa sea completamente correcto en todos los casos posibles. Solo verifica un conjunto visible y limitado de ejemplos mínimos esperados. Pasarla indica que el código funciona en esos casos concretos, pero no garantiza que maneje todos los casos borde, ni que sea robusto, ni que su costo esté bien analizado. Tampoco demuestra comprensión conceptual del algoritmo, su correctitud o su complejidad, porque eso se evalúa también en la sustentación.

4. Elijan **una** pregunta de `preguntas_semana1.md` y respóndanla bien.

Mi grupo ha elegido la pregunta 28, la cual es la siguiente:

¿Qué es complejidad temporal?

La complejidad temporal es una medida de cómo crece el número de operaciones de un algoritmo en función del tamaño de la entrada. No mide segundos exactos, sino la tasa de crecimiento del costo. Se expresa normalmente con notación asintótica, como O(n), O(logn), etc. para comparar algoritmos y entender cuáles escalan mejor cuando la entrada se vuelve grande.

5. Usen la rúbrica para autoevaluarse en:

   * comprensión conceptual:        Logrado
   * sustentación de correctitud:   Logrado
   * análisis de eficiencia:        Logrado

#### Bloque 4 - Puente corto con Proyecto0

Revisen:

* `Proyecto0/apps/demo_const_refs.cpp`
* `Proyecto0/bench/bench_vector_growth.cpp`
* `Proyecto0/bench/bench_vector_ops.cpp`
* `Proyecto0/bench/bench_cache_effects.cpp`

Respondan brevemente:

1. ¿Qué diferencia observable deja `demo_const_refs.cpp` entre lectura, modificación y copia?

La diferencia observable es que lectura no altera el vector original en absoluto, solo consume su contenido para producir un valor derivado como la suma, dejándolo exactamente igual que antes. La modificación in-place en cambio sí transforma el vector directamente, sin crear nada nuevo, porque la función recibe una referencia no-const y opera sobre el objeto original. Finalmente, la copia representa un punto medio interesante: el original se mantiene intacto, pero la función genera y devuelve un objeto completamente nuevo con el elemento extra, por lo que al final del programa conviven dos vectores distintos con contenidos diferentes, lo que deja claro que trabajaron sobre datos independientes.

2. En `bench_vector_growth.cpp`, ¿qué cambia con `reserve`?

Al llamar reserve(n), el vector pre asigna memoria contigua para n elementos de una sola vez antes del bucle. Sin reserve, cada vez que el vector agota su capacidad interna durante push_back, debe reasignar un bloque más grande y copiar todos los elementos existentes al nuevo bloque, lo cual ocurre O(log n) veces con un costo acumulado significativo.
Con reserve, se elimina por completo esas reasignaciones y copias intermedias, dado que el vector ya tiene espacio suficiente desde el inicio, así que los 300,000 push_back simplemente escriben en memoria ya asignada. El resultado es menos tiempo de ejecución y menor fragmentación de memoria, lo cual se refleja directamente en los tiempos promedio que mide el benchmark.

3. En `bench_vector_ops.cpp`, ¿por qué `push_back`, `insert(begin())` e `insert(middle)` no cuestan lo mismo?

Los tres no cuestan lo mismo porque cada uno mueve una cantidad distinta de elementos en cada inserción: push_back simplemente coloca el elemento al final sin mover nada, siendo prácticamente instantáneo gracias al reserve; insert en el medio desplaza en promedio la mitad de los elementos existentes cada vez; e insert en begin() es el peor caso porque obliga a mover todos los elementos una posición hacia adelante en cada inserción, lo que hace que el costo total escale de forma cuadrática y el benchmark lo refleje directamente en los tiempos medidos.

4. En `bench_cache_effects.cpp`, ¿qué intuición deja sobre localidad de memoria?

La intuición es que la localidad de memoria importa tanto como la estructura de datos. El recorrido secuencial del vector es el más rápido porque accede a posiciones contiguas en memoria, permitiendo que el prefetcher de la CPU cargue los datos antes de que se necesiten. El acceso aleatorio al mismo vector es más lento porque cada salto a un índice arbitrario produce un cache miss frecuente. El recorrido de std::list es el más lento de los tres a pesar de ser secuencial en lógica, porque sus nodos están dispersos en el heap y cada next obliga a buscar una dirección distinta en memoria, anulando el beneficio del caché.

#### Bloque 5 - Extensión breve con Ejercicios0

Revisen:

* `Ejercicios0.md`
* `INSTRUCCIONES_Ejercicios0_v4.2.md`
* `stl_optimizacion_demostracion.cpp`
* `resolver_ejercicios0_v4.2.sh`

Respondan:

1. Según `Ejercicios0.md`, ¿cuál es el orden correcto antes de optimizar?

Ejercicios0.md establece un orden de cuatro pasos. Primero elegir bien el algoritmo, luego verificar que el programa sea correcto, después medir el rendimiento, y finalmente explorar optimizaciones más avanzadas del compilador. El mensaje central es que -O3 no reemplaza a nth_element, a lower_bound, a un buen reserve(), ni a una prueba bien hecha.

2. ¿Qué quiere mostrar `stl_optimizacion_demostracion.cpp` con `reserve`, `nth_element`, `partial_sort` y `lower_bound`?

El archivo demuestra que elegir el algoritmo correcto de la STL importa más que el nivel de optimización del compilador. 'reserve' elimina realocaciones evitables en push_back, bajando la constante oculta del costo amortizado. nth_element obtiene la mediana o el k-ésimo elemento en O(n) promedio, evitando el O(n log n) de un sort completo innecesario. partial_sort ordena solo los primeros K elementos para obtener un Top-K, también más barato que ordenar todo. lower_bound convierte una búsqueda lineal O(n) en una búsqueda binaria O(log n) sobre un vector ya ordenado. Cada sección imprime una tabla comparativa de tiempos para que la diferencia sea observable directamente.

3. ¿Qué tipo de evidencia puede producir `resolver_ejercicios0_v4.2.sh`?

El script genera evidencia empírica. Produce tablas comparativas de tiempo de ejecución y tamaño de binario para distintos niveles de optimización 
(experimento 1), salidas del demo STL con tiempos reales 
(experimento 2), resultados de LTO y PGO con y sin la técnica 
(experimentos 3 y 4), reportes de ASan, UBSan y TSan detectando errores concretos 
(experimento 5), porcentajes de cobertura de líneas y condiciones con gcov 
(experimentos 6 y 7), conteo de warnings por nivel de optimización 
(experimento 8), y el perfil de funciones calientes con gprof 
(experimento 9). Todo queda consolidado en reporte_ejercicios0.md.

4. ¿Qué limitaciones de entorno menciona `INSTRUCCIONES_Ejercicios0_v4.2.md`?

El documento advierte tres limitaciones concretas para Windows: ASan, UBSan y TSan pueden no enlazar correctamente; gcov puede requerir ajustes extra según el entorno; y gprof puede fallar o no generar perfiles útiles. Como recomendación, indica usar UCRT64 en MSYS2 para compilación normal, y WSL Ubuntu o Linux nativo para sanitizers, cobertura y profiling. El script mismo detecta estas fallas en tiempo de ejecución y reporta qué log revisar en lugar de abortar silenciosamente.

5. ¿Por qué esta parte no reemplaza la discusión de correctitud de Semana1?

Porque el Bloque 5 se enfoca en medir y comparar rendimiento bajo el supuesto de que el código ya es correcto. Los benchmarks y las flags del compilador solo tienen sentido después de garantizar que el programa hace lo que debe: un programa rápido pero incorrecto no sirve. La discusión de correctitud de Semana1 cubre el razonamiento sobre invariantes, precondiciones y postcondiciones de los algoritmos, que es anterior e independiente a cualquier medición. El propio Ejercicios0.md lo dice explícitamente: primero algoritmo correcto, luego medir, luego optimizar.

### Bloque 6 - Cierre comparativo

Respondan esta pregunta final:

**¿Qué cambia cuando pasamos de defender correctitud básica en Semana1 a comparar implementaciones con evidencia experimental?**

La respuesta debe incluir obligatoriamente:

* una afirmación de especificación,
* una afirmación de correctitud,
* una afirmación de costo,
* una afirmación de representación o memoria,
* una advertencia metodológica.

Lo que cambia es el tipo de pregunta que uno está respondiendo. En Semana 1 la pregunta era "¿esto funciona bien?"; ahora la pregunta pasa a ser "¿esto funciona mejor que la alternativa, y bajo qué condiciones?". Eso exige un marco distinto.

Antes de comparar dos implementaciones hay que fijar qué problema resuelven exactamente. Por ejemplo, 'nth_element' y 'sort' no son intercambiables porque sus contratos son distintos. 'nth_element' solo garantiza que el k-ésimo elemento quede en su posición correcta, no que el resto esté ordenado. Comparar tiempos sin verificar que ambas versiones cumplen la misma especificación es comparar cosas distintas.

Sin embargo, incluso cuando la especificación coincide, la evidencia experimental no puede reemplazar al argumento de correctitud. Que 'power(3, 5)' devuelva 243 en cinco corridas no prueba que power sea correcta para todo n, solo que no falló en ese caso. La correctitud sigue siendo una propiedad que se defiende con razonamiento sobre el algoritmo, no con observaciones empíricas.

En cuanto al costo, el tiempo observable en un benchmark es una instancia del costo teórico, no su prueba. Que 'lower_bound' sea más rápido que búsqueda lineal para n = 250000 es consistente con la diferencia entre O(log n) y O(n), pero el argumento de costo se sostiene con el análisis de complejidad, no con el número en pantalla. Los tiempos solo hacen visible lo que el análisis ya predice.

Ahora bien, el análisis de complejidad tampoco cuenta toda la historia. Cuando 'bench_cache_effects.cpp' muestra que 'std::list' es más lento que vector incluso en recorrido secuencial, lo que se revela no es una diferencia algorítmica sino una diferencia de representación en memoria. Los nodos dispersos en el heap rompen la localidad que el caché necesita. Defender una implementación requiere entonces no solo hablar del algoritmo sino de cómo los datos viven en memoria.

Finalmente, todo lo anterior pierde valor si la medición no es rigurosa. Los benchmarks mienten si no se controlan las variables. El mismo experimento ejecutado con distintos niveles de optimización del compilador, distinto tamaño de entrada o sin repeticiones suficientes puede invertir el resultado. Hay que mantener constantes el input, la máquina, el compilador y el número de repeticiones, y aun así interpretar los tiempos con cuidado, porque medir mal también engaña.
