#include <stdio.h>

int conta (int n) {

    
    int cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j ++) {
            cont++;
        }
    }
    return cont;
}