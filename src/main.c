#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#define sudoku_size 9
#define sudoku_square_size 3
#define sudoku_empty_cell -1
/**
 * Si una celda está vácia, tiene un -1 por default
 */
struct sudoku {
    int matriz[9][9]
};

bool hayNumerosRepetidosEnFilaN(struct sudoku* sudokuResolviendo, int fila);
bool seRepitenNumerosEnColumnas(struct sudoku* sudokuResolviendo);
bool hayNumerosRepetidosEnColumnaN(struct sudoku* sudokuResolviendo, int columna);
bool seRepitenNumerosEnCuadrados(struct sudoku* sudokuResolviendo);
bool hayNumerosRepetidosEnCuadradoN(struct sudoku* sudokuResolviendo, int cuadradoAVerificar);
bool hayCeldasVacias(struct sudoku* sudokuResolviendo);
bool esSolucionParcialCorrecta(struct sudoku* sudokuResolviendo);
bool esSudokuCompletado(struct sudoku* sudokuPorResolver);
void backtrackingSudoku(struct sudoku* sudokuPorResolver, int fila, int columna);
void sudokuResuelto(struct sudoku sudokuResuelto, struct sudoku sudokuPorResolver);

int main() {

    return 0;
}

void sudokuResuelto(struct sudoku sudokuResuelto, struct sudoku sudokuPorResolver) {
    
    for(int i = 0; i < sudoku_size; i++) {
        for(int j = 0; j < sudoku_size; j++) {
            sudokuResuelto.matriz[i][j] = sudokuPorResolver.matriz[i][j];
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

void backtrackingSudoku(struct sudoku* sudokuPorResolver, int fila, int columna) {
    /**
     * 
     */
    if (fila == (sudoku_size - 1) && columna == (sudoku_size - 1) && esSudokuCompletado(sudokuPorResolver)) {
        return;
    }


}



