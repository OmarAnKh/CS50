#include<cs50.h>
#include<stdio.h>

void draw(int n) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j <= i; ++j) {
      printf("#");
    }
    printf("\n");
  }
}

int main(void) {
  int height = get_int("What is the height: ");
  draw(height);
}
