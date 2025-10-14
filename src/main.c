#include <stdio.h>
#include <stdint.h>


#define sudoku_height 9
#define sudoku_width  9
#define sudoku_square_height 3
#define sudoku_square_width 3
#define sudoku_empty_cell -1
/**
 * Si una celda está vácia, tiene un -1 por default
 */
struct sudoku {
    int matriz[9][9]
};



struct sudoku sudokuResuelto(struct sudoku sudokuPorResolver);
void backtrackingSudoku(struct sudoku* sudokuPorResolver);
int esSudokuCompletado(struct sudoku* sudokuPorResolver);

int noSeRepitenNumerosEnFilas(struct sudoku* sudokuResolviendo);
int noHayNumerosRepetidosEnFilaN(struct sudoku* sudokuResolviendo, int fila);

int noSeRepitenNumerosEnColumnas(struct sudoku* sudokuResolviendo);
int noHayNumerosRepetidosEnColumnaN(struct sudoku* sudokuResolviendo, int columna);

int noSeRepitenNumerosEnCuadrados(struct sudoku* sudokuResolviendo); 
int noHayNumerosRepetidosEnCuadradoN(struct sudoku* sudokuResolviendo, int cuadradoAVerificar); 
int noHayCeldasVacias(struct sudoku* sudokuResolviendo);

int invertirRespuesta(int respuesta)

int main() {

    return 0;
}

struct sudoku sudokuResuelto(struct sudoku sudokuPorResolver) {
    struct sudoku sudokuResuelto;
    
    for(int i = 0; i < sudoku_height; i++) {
        for(int j = 0; j < sudoku_width; j++) {
            sudokuResuelto.matriz[i][j] = sudokuPorResolver.matriz[i][j];
        }
    }

    return sudokuResuelto;
}

int noSeRepitenNumerosEnFilas(struct sudoku* sudokuResolviendo) {
    /* 
     * Returns 0 if it's there's no row with values repeatead. 
     * Otherwise, returns non-zero value
     */
    
    
    for(int i = 0; i < sudoku_square_height; i++) {

    }

    return 0;
}

int noHayNumerosRepetidosEnFilaN(struct sudoku* sudokuResolviendo, int fila) {
    /* 
     * Requires: 0 <= fila <= 8
     * Returns 0 if it's the nth-row have any repeatead values (except -1, it's the empty cell) 
     * Otherwise, returns non-zero value
     */
    uint8_t aparicionesNumeros[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

     for(int i = 0; i < sudoku_square_width; i++) {
        int numeroEnCelda = sudokuResolviendo->matriz[fila][i] - 1;
        if (aparicionesNumeros[numeroEnCelda] == 0) {
            aparicionesNumeros[numeroEnCelda]++;
        } else {
            return 0;
        }
    }
    return 1;
}

int noSeRepitenNumerosEnColumnas(struct sudoku* sudokuResolviendo) {
    /* 
     * Returns 0 if it's there's no column with values repeatead. 
     * Otherwise, returns non-zero value
     */
    return 0;
}

int noHayNumerosRepetidosEnColumnaN(struct sudoku* sudokuResolviendo, int columna) {
    /* 
     * Returns 0 if it's the nth-column have any repeatead values (except -1, it's the empty cell) 
     * Otherwise, returns non-zero value
     */
    uint8_t aparicionesNumeros[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

     for(int i = 0; i < sudoku_square_width; i++) {
        int numeroEnCelda = sudokuResolviendo->matriz[i][columna] - 1;
        if (aparicionesNumeros[numeroEnCelda] == 0) {
            aparicionesNumeros[numeroEnCelda]++;
        } else {
            return 0;
        }
    }
    return 0;
}

int noSeRepitenNumerosEnCuadrados(struct sudoku* sudokuResolviendo) {
    /* 
     * Returns 0 if it's the nth-square have any repeatead values (except -1, it's the empty cell) 
     * Otherwise, returns non-zero value
     */
}

int noHayNumerosRepetidosEnCuadradoN(struct sudoku* sudokuResolviendo, int cuadradoAVerificar) {
    /* 
     * Returns 0 if it's the nth-square have any repeatead values (except -1, it's the empty cell) 
     * Otherwise, returns non-zero value
     */
    return 0;
}

int hayCeldasVacias(struct sudoku* sudokuResolviendo) {
    /* 
     * Returns 0 if it's there's some cell with value empty (-1)
     * Otherwise, returns non-zero value
     */
    int thereNonEmptySquare = 0;
    for(int i = 0; i < sudoku_square_height; i++) {
        for(int j = 0; j < sudoku_square_width; j++) {
            if(sudokuResolviendo->matriz[i][j] == sudoku_empty_cell) {
                return 1;
            }
        }
    }
    return thereNonEmptySquare;
}

int invertirRespuesta(int respuesta) {
    /**
     * Returns non-zero if respuesta is zero
     * Returns zero if respuesta is non-zero
     */
    if (respuesta == 0) {
        return 1;
    }
    return 0;
}

int noHayCeldasVacias(struct sudoku* sudokuResolviendo) {
    return invertirRespuesta(hayCeldasVacias(sudokuResolviendo));
}

int esSolucionParcialCorrecta(struct sudoku* sudokuResolviendo) {
    /*
     * Returns 0 if it's not correct. 
     * Otherwise, returns non-zero value
     */
    
    // Verificar todas las condiciones
    // No se repiten numeros en las filas
    // No se repiten números en las columnas
    // No se repiten números en los cuadrados
    return 1;
}

int esSudokuCompletado(struct sudoku* sudokuPorResolver) {
    /* 
     * Returns 0 if it's not completed. 
     * Otherwise, returns non-zero value
     */

    // Verificar todas las condiciones
    // No se repiten numeros en las filas
    // No se repiten números en las columnas
    // No se repiten números en los cuadrados
    // No hay celdas vácias
    return 1;
}

void backtrackingSudoku(struct sudoku* sudokuPorResolver) {
    /**
     * 
     */
}



