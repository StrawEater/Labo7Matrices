#include "ejercicios.h"

vector<vector<int> > productoVectorial(vector<int> u, vector<int> v){
	//COMPLETAR
	vector<vector<int> > res;
    for (int filaU = 0; filaU < u.size(); ++filaU) {
        vector<int> filaRes;
        for (int columnaV = 0; columnaV < v.size(); ++columnaV) {
            filaRes.push_back(u[filaU] * v[columnaV]);
        }
        res.push_back(filaRes);
    }
    
    
	return res;
}

void trasponer(vector<vector<int> > &m) {
	vector<vector<int>> mCopy = vector<vector<int>>(m);
    for (int fila = 0; fila < m.size() ; ++fila) {
        for (int columna = 0; columna < m[fila].size(); ++columna) {
            m[fila][columna] = mCopy[columna][fila];
        }
    }
	return;
}

vector<vector<int> > multiplicar(vector<vector<int> > m1, vector<vector<int> > m2){
	//COMPLETAR
    vector<vector<int> > res;
    for (int filaM1 = 0; filaM1 < m1.size(); ++filaM1) {
        vector<int> filaRes;
        for (int columnaM2 = 0; columnaM2 < m2[filaM1].size(); ++columnaM2) {
            int suma = 0;
            for (int filaM2 = 0; filaM2 < m2.size(); ++filaM2) {
                suma += m1[filaM1][filaM2] * m2[filaM2][columnaM2];
            }
            filaRes.push_back(suma);
        }
        res.push_back(filaRes);
    }
	return res;
}

int calcularPromedioVecinos(vector<vector<int> > m, int fila, int columna){

    int suma = 0;
    int cantidadVecinos = 0;
    for (int filaOffset = -1; filaOffset < 2; ++filaOffset) {
        int filaVecina = fila+filaOffset;
        if (filaVecina >= 0 && filaVecina < m.size()){
            for (int columnaOffset = -1; columnaOffset < 2; ++columnaOffset) {
                int columnaVecina = columna + columnaOffset;
                if (columnaVecina >= 0 && columnaVecina < m[filaVecina].size()){
                    suma += m[filaVecina][columnaVecina];
                    cantidadVecinos++;
                }
            }
        }
    }
    int dou = suma/cantidadVecinos;
    return cantidadVecinos != 0 ? dou : NULL;
}

vector<vector<int> > promediar(vector<vector<int> > m){
	//COMPLETAR
	vector<vector<int> > res;
    for (int filaM = 0; filaM < m.size(); ++filaM) {
        vector<int> filaRes;
        for (int columnaM = 0; columnaM < m[filaM].size(); ++columnaM) {
            filaRes.push_back(calcularPromedioVecinos(m,filaM,columnaM));
        }
        res.push_back(filaRes);
    }
	return res;
}

bool EsPico(vector<vector<int> > m, int fila, int columna){

    int posiblePico = m[fila][columna];
    for (int filaOffset = -1; filaOffset < 2; filaOffset++) {
        int filaVecina = fila+filaOffset;
        if (filaVecina >= 0 && filaVecina < m.size()){
            for (int columnaOffset = -1; columnaOffset < 2; columnaOffset++) {
                int columnaVecina = columna + columnaOffset;
                if (columnaVecina >= 0 && columnaVecina < m[filaVecina].size()){
                    if ((columnaVecina != columna || fila != filaVecina) && (posiblePico <= m[filaVecina][columnaVecina])) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}

int contarPicos(vector<vector<int> > m){
    int cantPicos = 0;
    for (int fila = 0; fila < m.size() ; ++fila) {
        for (int columna = 0; columna < m[fila].size(); ++columna) {
            if (EsPico(m,fila,columna)) cantPicos++;
        }
    }
    return cantPicos;
}

bool esTriangular(vector<vector<int> > m){
	//COMPLETAR
    bool triangularSuperior = false;
    bool triangularInferior = false;
    for (int fila = 0; fila < m.size() ; ++fila) {
        for (int columna = 0; columna < m[fila].size(); ++columna) {
            if(fila < columna && m[fila][columna] != 0){
                if (!triangularSuperior){
                    triangularInferior = true;
                }else{
                    return false;
                }
            } else if(fila > columna && m[fila][columna] != 0){
                if (!triangularInferior){
                    triangularSuperior = true;
                }else{
                    return false;
                }
            }
        }
    }
    return true;
}


bool reinasAmenazandose(int filaReina1, int columnaReina1, int filaReina2, int columnaReina2){
    if (filaReina1 == filaReina2) return true;
    if (columnaReina1 == columnaReina2) return true;
    if (abs(filaReina1 - columnaReina1) == abs(filaReina2 - columnaReina2)) return true;
    return false;
}

bool hayAmenaza(vector<vector<int> > m){
    vector<int> filasReinas;
    vector<int> columnasReinas;

    for (int fila = 0; fila < m.size() ; ++fila) {
        for (int columna = 0; columna < m[fila].size(); ++columna) {
            if (m[fila][columna] == 1){
                for (int indexReina = 0; indexReina < filasReinas.size(); ++indexReina) {
                    int filaReina = filasReinas[indexReina];
                    int columnaReina = columnasReinas[indexReina];
                    if (reinasAmenazandose(filaReina,columnaReina,fila,columna)) return true;
                }
                filasReinas.push_back(fila);
                columnasReinas.push_back(columna);
            }
        }
    }
	return false;
}

int diferenciaDiagonales(vector<vector<int> > m) {
    int diagonalPositiva = 0;
    int diagonalNegativa = 0;
    for (int fila = 0; fila < m.size() ; ++fila) {

            diagonalNegativa += m[m.size()-fila-1][fila];
            diagonalPositiva += m[fila][fila];

    }
    return abs(diagonalPositiva-diagonalNegativa);
}