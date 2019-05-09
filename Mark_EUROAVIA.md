## Programación de Altímetro para el Taller de Cohetes de EUROAVIA Sevilla 

### 1º: Realización del ensayo.

De la misma forma que en el lanzamiento, en el ensayo el dispositivo se accionará y empezará a transmitir/guardar medidas una vez que se le conecte la batería y el sensor capte una altura sobre la de inicializado de 5 metros.

Por ello, lo que verá la placa será.

*Una conexión de la batería, por lo que comenzará a sensar.*

*El primer dato de altitud que reciba, será el que tome como referencia para comparar como 5 metros.*

*No emitirá ni salvará datos hasta que no reciba una altitud incremental de 5 metros respecto a la referencia.*

*Cuando la tenga, comenzará la transmisión y el salvado de datos hasta que se pulse el botón Reset, se le extraiga la batería o se acabe la energía de la misma.*

### 2º Posición dentro del cohete.

Se pegará con cinta aislante a la pared del cono del cohete con la conexión del puerto Serial apuntando hacia abajo.

### 3º Tasa máxima para cada dato.

????

### 4º Datos a salvar y transmitir

Para ahorrar en tiempo y complejidad, sólo es completamente necesario extraer los datos del altura del BME. Si sobrara tiempo, sería interesante calibrar y tomar datos de **posición** del MPU. 
