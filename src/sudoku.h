
/**
 * Si una celda está vácia, tiene un -1 por default
 */
struct sudoku {
    int matriz[9][9];
};

#define sudoku_size 9
#define sudoku_square_size 3
#define sudoku_empty_cell -1

bool seRepitenNumerosEnFilas(struct sudoku* sudokuResolviendo);
bool hayNumerosRepetidosEnFilaN(struct sudoku* sudokuResolviendo, int fila);

bool seRepitenNumerosEnColumnas(struct sudoku* sudokuResolviendo);
bool hayNumerosRepetidosEnColumnaN(struct sudoku* sudokuResolviendo, int columna);

bool seRepitenNumerosEnCuadrados(struct sudoku* sudokuResolviendo);
bool hayNumerosRepetidosEnCuadradoN(struct sudoku* sudokuResolviendo, int cuadradoAVerificar);

bool hayCeldasVacias(struct sudoku* sudokuResolviendo);

bool esSolucionParcialCorrecta(struct sudoku* sudokuResolviendo);
bool esSudokuCompletado(struct sudoku* sudokuPorResolver);

bool backtrackingSudoku(struct sudoku* sudokuPorResolver, int fila, int columna);
void sudokuResuelto(struct sudoku* sudokuResuelto, struct sudoku* sudokuPorResolver);