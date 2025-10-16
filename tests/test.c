#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <stdbool.h>
#include "../src/sudoku.h"

void test_seRepitenNumerosEnFilas_matrizVacia(void) {
  struct sudoku vacio;    
      
  for(int i = 0; i < sudoku_size; i++) {
    for(int j = 0; j < sudoku_size; j++) {
      vacio.matriz[i][j] = sudoku_empty_cell;
    }
  }
  bool respuesta = seRepitenNumerosEnFilas(&vacio);
  CU_ASSERT(!respuesta);
}

void test_seRepitenNumerosEnFilas_matrizIgual(void) {
  struct sudoku vacio;    
      
  for(int i = 0; i < sudoku_size; i++) {
    for(int j = 0; j < sudoku_size; j++) {
      vacio.matriz[i][j] = 1;
    }
  }
  bool respuesta = seRepitenNumerosEnFilas(&vacio);
  CU_ASSERT(respuesta);
}

int main() {
  
    CU_initialize_registry();
    CU_pSuite suite = CU_add_suite("Se repiten numeros en fila?", 0, 0);
    CU_add_test(suite, "numeros_repetidos_en_fila", test_seRepitenNumerosEnFilas_matrizVacia);
    CU_add_test(suite, "numeros_repetidos_en_fila", test_seRepitenNumerosEnFilas_matrizIgual);
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();

    return 0;
}

