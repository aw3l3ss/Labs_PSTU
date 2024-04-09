#include <iostream>

using namespace std;

void init_array(int *arr, int len);
void print_array(int *arr, int len);
void format_array(int *arr, int *len);

int main() {
  srand(time(nullptr));
  
  int len = rand() % 20 + 1;

  int *arr = (int *) calloc(len, sizeof(int));

  cout << "Length of array: " << len << endl;
  init_array(arr, len);
  print_array(arr, len);
  format_array(arr, &len);
  print_array(arr, len);
  free(arr);

  return 0;

}

void init_array(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    arr[i] = rand() % 201 - 100;
  }
}

void print_array(int *arr, int len) {
  for (int i = 0; i < len; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
}

void format_array(int *arr, int *len) {
  int step = 1;

  for (int i = 1; i < *len; i++) {
    if (i % 3 == 0) {
      ++step;
    }

    else {
      arr[i - step] = arr[i];
    }
  }

  *len -= step;
  arr = (int *) realloc(arr, *len * sizeof(int));

  for (int i = 0; i < *len; i++) {
    if (arr[i] < 0) {
      ++*len;
      arr = (int *) realloc(arr, *len * sizeof(int));

      for (int j = *len - 1; j > i + 1; j--) {
        arr[j] = arr[j - 1];
      }

      arr[i + 1] = abs(arr[i] + 1);
    }
  }
}
