#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include "./sudoku.h"



void sudokuResuelto(struct sudoku* sudokuResuelto, struct sudoku* sudokuPorResolver) {
    
    for(int i = 0; i < sudoku_size; i++) {
        for(int j = 0; j < sudoku_size; j++) {
            sudokuResuelto->matriz[i][j] = sudokuPorResolver->matriz[i][j];
        }
    }

    for(int i = 1; i <= sudoku_size; i++) {
        if(backtrackingSudoku(sudokuPorResolver, 1, 1)) {
            return;
        }
    }
}

bool seRepitenNumerosEnFilas(struct sudoku* sudokuResolviendo) {
    for(int i = 0; i < sudoku_size; i++) {
        if(hayNumerosRepetidosEnFilaN(sudokuResolviendo, i)) {
            return true;
        }
    }
    return false;
}

bool hayNumerosRepetidosEnFilaN(struct sudoku* sudokuResolviendo, int fila) {
    bool apareceValorAntes[] = {false, false, false, false, false, 
                                false, false, false, false, false};
    
    for(int i = 0; i < sudoku_size; i++) {
        int valorCelda = sudokuResolviendo->matriz[fila][i] - 1;
        if (valorCelda == sudoku_empty_cell - 1) {
            continue;
        }
        else if(apareceValorAntes[valorCelda]) {
            return true;
        } else {
            apareceValorAntes[valorCelda] = true;
        }
    }       
    return false;
}

bool seRepitenNumerosEnColumnas(struct sudoku* sudokuResolviendo) {
    for(int i = 0; i < sudoku_size; i++) {
        if(hayNumerosRepetidosEnColumnaN(sudokuResolviendo, i)) {
            return true;
        }
    }
    return false;
}

bool hayNumerosRepetidosEnColumnaN(struct sudoku* sudokuResolviendo, int columna) {
    bool apareceValorAntes[] = {false, false, false, false, false, 
                                false, false, false, false, false};
    
    for(int i = 0; i < sudoku_size; i++) {
        int valorCelda = sudokuResolviendo->matriz[i][columna] - 1;
        if (valorCelda == sudoku_empty_cell - 1) {
            continue;
        }
        else if(apareceValorAntes[valorCelda]) {
            return true;
        } else {
            apareceValorAntes[valorCelda] = true;
        }
    }       
    return false;
}

bool seRepitenNumerosEnCuadrados(struct sudoku* sudokuResolviendo) {
    for(int i = 0; i < sudoku_size; i++) {
        if(hayNumerosRepetidosEnCuadradoN(sudokuResolviendo, i)) {
            return true;
        }
    }
    return false;
}

bool hayNumerosRepetidosEnCuadradoN(struct sudoku* sudokuResolviendo, int cuadradoAVerificar) {
    int x, y;
    x = (cuadradoAVerificar / 3) * 3;
    y = (cuadradoAVerificar % 3);
    
    bool apareceValorAntes[] = {false, false, false, false, false, 
                                false, false, false, false, false};

    for(int i = 0; i < sudoku_square_size; i++) {
        for(int j = 0; j < sudoku_square_size; j++) {
            int valorCelda = sudokuResolviendo->matriz[x + i][y + j];
            if (valorCelda == sudoku_empty_cell - 1) {
                continue;
            } else if(apareceValorAntes[valorCelda]) {
                return true;
            } else {
                apareceValorAntes[valorCelda] = true;
            }
        }
    }
    
    return false;
}

bool hayCeldasVacias(struct sudoku* sudokuResolviendo) {
    for(int i = 0; i < sudoku_size; i++) {
        for(int j = 0; j < sudoku_size; j++) {
            if (sudokuResolviendo->matriz[i][j] == sudoku_empty_cell) {
                return true;
            }
        }
    }
    return false;
}

bool esSolucionParcialCorrecta(struct sudoku* sudokuResolviendo) {
    return  !seRepitenNumerosEnFilas(sudokuResolviendo) &&
            !seRepitenNumerosEnColumnas(sudokuResolviendo) &&
            !seRepitenNumerosEnCuadrados(sudokuResolviendo);
}

bool esSudokuCompletado(struct sudoku* sudokuPorResolver) {
    return esSolucionParcialCorrecta(sudokuPorResolver) && !hayCeldasVacias(sudokuPorResolver);
}

bool backtrackingSudoku(struct sudoku* sudokuPorResolver, int fila, int columna) {
    /**
     * Voy a iterar por la filas. Llego hasta el final y sumo uno a la columna
     * El numero de matriz fila, columna lo voy a tener puesto por el anterior
     * Yo pongo el siguiente
     * El llamado a la función llama en todos los estados posibles
     */
    if (fila == (sudoku_size - 1) && columna == (sudoku_size - 1) && esSudokuCompletado(sudokuPorResolver)) {
        return true;
    }
    if (fila == sudoku_size - 1) {
        columna++;
        fila = 0;
    } else {
        fila++;
    }

    //Verificar 

    //Probar con todas los numeros del 1 and 9 inclusive
    //Si alguno devuelve true, no modificar más el sudoku por resolver
    //Sino, era un camino sin fin

}



