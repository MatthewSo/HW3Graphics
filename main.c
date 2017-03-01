#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "matrix.h"

int main() {

  screen s;
  clear_screen(s);
  
  struct matrix *edges;

  edges = new_matrix(4, 4);

  
  printf("Create matrix\n");  
  
  print_matrix(edges);

  printf("Identity matrix\n");  
  
  ident(edges);

  print_matrix(edges);

  printf("Scalar multiplication matrix\n");
  
  scalar_mult(3,edges);
  
  print_matrix(edges);
  

  color color;
   
  color.red = 200;
  color.green = 100;
  color.blue = 0;

  struct matrix *test1 = new_matrix(4, 4);
  add_point(test1, 10, 10, 10);
  add_point(test1, 100, 100, 100);
  add_point(test1, 40, 40, 32);
  add_point(test1, 58, 23, 98);


  struct matrix *test2 = new_matrix(4, 4);
  add_edge(test2, 14, 20, 12, 120, 130, 80);
  add_edge(test2, 22, 31, 200, 200, 100, 300);
  printf("these are two matrices multipled together: \n");
  
  printf("Test1: \n");
  print_matrix(test1);

  printf("Test2: \n");
  print_matrix(test2);
  
  printf("Combination: \n");
  matrix_mult(test1, test2);
  print_matrix(test2);


  struct matrix* drawing = new_matrix(4,4);
  add_edge(drawing, 50, 50, 50, 50, 100, 100);
  add_edge(drawing, 100, 100, 150, 100, 50, 200);
  add_point(drawing, 50,50,50);

  print_matrix(drawing);
   
  draw_lines(drawing, s, color);

  scalar_mult(3,drawing);

  draw_lines(drawing,s,color);
  
  display(s);
  
  free_matrix( edges );
}  
