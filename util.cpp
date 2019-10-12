#include "header.hpp"
using namespace std;

int isPrime(unsigned n){
    // É divisível só por 1 e ele mesmo?
    int div = 0; // Quantidade de divisores desse número

    for (unsigned i=1; i<=n; i++){
        if (n%i==0){
            div++;
        }
    }
    return (div==2)? TRUE:FALSE; // Sim:Não;
}

int randRange(unsigned range, int min){
        return rand() % range + min;
}

unsigned** newMatrix(unsigned tam){
    srand(time(NULL)); // Use rand_Range(range,min)
    int status = TRUE;
    if (tam>0){
        unsigned** mat = new unsigned*[tam];
        if (mat!=NULL){
            unsigned i=0,j=0;
            for (i=0; i<tam; i++){
                mat[i] = new unsigned[tam];
                if (mat[i]!=NULL){
                    for (j=0; j<tam; j++){
                        mat[i][j] = randRange((unsigned)RND_RNG,RND_MIN);
                    }
                }else{
                   status = FALSE;
                    break;
                }
            }

            if (status){
                return mat;
            }else{
                unsigned k = 0;
                for (k=0; k<i; k++){
                    delete[] mat[k];
                }
                delete[] mat;
            }
        }
    }
    cerr << "Failed to create matrix. Bad Allocation." << endl;
    return NULL;
}

void showMatrix(unsigned**mat){
    if (mat!=NULL){
        for (unsigned i=0; i<M_SIZE; i++){
            for (unsigned j=0; j<M_SIZE; j++){
                if (mat[i][j]<10){
                    cout << 00;
                }else if (mat[i][j]>=10 && mat[i][j]<100){
                    cout << 0;
                }
                    cout << mat[i][j] << ". ";
            }
            cout << endl;
        }
        cout << endl;
    }else{
        cerr << "Failed to print matrix in '" << mat << "'." << endl;
    }
}

int delMatrix (unsigned** mat){
    if (mat!=NULL){
        for (unsigned i=0; i<M_SIZE; i++){
            delete[] mat[i];
        }
        delete[] mat;
        return TRUE;
    }else{
        cerr << "Failed to exclude matrix in '" << mat << "'." << endl;
    }
    return FALSE;
}
