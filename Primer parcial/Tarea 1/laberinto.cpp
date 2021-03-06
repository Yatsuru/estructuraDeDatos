/*
Margot Duek
25/01/15
Algoritmo de una funcion recursiva que permita salir de un laberinto en una matriz 
de N x N, donde N puede ser cualquier número.
*/

#include<iostream>
#include<string>
#include<cstdlib>
#define n 6
#define m 6
using namespace std;

void imprimeMatriz(int mat[n][m]);
int buscaCamino(int mat[n][m], int i, int j);
void buscaCamino2(int mat[n][m], int i, int j);


int main(){
   int mat[n][m];
   
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            mat[i][j] = rand() % 9;
            if(mat[i][j] < 6){
                mat[i][j] = 0;    
            }else{
                mat[i][j] = 1;
            }
            
        }
    }
    
    imprimeMatriz(mat);
    /*buscaCamino(mat, 0,0);
    imprimeMatriz(mat);*/
    buscaCamino2(mat, 0, 0);
    imprimeMatriz(mat);
    
    if (mat[n-1][m-1] == 3){
        cout << "Camino exitoso!" << endl;
    }else{
        cout << "Lo sentimos, no exite camino" << endl;
    }
    
    return 0;
}



//Funcion para imprimir matrices
//Creada por V. Cubells
void imprimeMatriz(int mat[n][m]){
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << mat[i][j] << "\t";
        }
        std::cout << std::endl;
    }
    cout << endl;
}


int buscaCamino(int mat[n][m], int i, int j){
    
    if(i < n && j < m){
        if(mat[i][j] == 0){
            mat[i][j] = 3;
            return buscaCamino(mat, i, j+1);
        }else if(mat[i][j] == 1){
            if(mat[i+1][j-1] == 0){
                return buscaCamino(mat, i+1, j-1);
            }else{
                
                return buscaCamino(mat,0,0);
            }
        }
    }else if(j < n){
        if(mat[i][j+1] == 0){
            return buscaCamino(mat, i, j+1);
        }else{
            return buscaCamino(mat, i, 0);    
        }
        
    }
 
}


void buscaCamino2(int mat[n][m], int i, int j){
    if(mat[i][j] == 0 && i < n && j < n){
        mat[i][j] = 3;
        buscaCamino2(mat, i, j+1);
        buscaCamino2(mat, i+1, j);
    }
}