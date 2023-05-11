#include <math.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

double **DynaArr2D(double **a, int Dim, int Num_b) {
    a = new double *[Num_b];
    for (int i = 0; i < Num_b; i++) {
        a[i] = new double[Dim];
    }
    for (int i = 0; i < Num_b; i++) {
        for (int j = 0; j < Dim; j++) {
            a[i][j] = 0;
        }
    }
    return a;
}
double loss(int Dim, double *p, int *x, double *y, int key) {
    double sum = 0;
    for (int i = 0; i < key; i++) {
        double ts = 0;
        double m = 1;
        for (int j = 0; j < Dim; j++) {
            ts += p[j] * m;
            m *= x[i];
        }
        sum += fabs(y[i] - ts);
    }
    return sum;
}

int main(int argc, char *argv[]) {
    ifstream in, inR1, inR2, inData;
    in.open(argv[1]);
    inData.open(argv[2]);
    inR1.open(argv[3]);
    inR2.open(argv[4]);
    string input;

    int Dim = 0, Num_b = 0, Max_cycle = 0;
    int Min_boundary[Dim], Max_boundary[Dim];
    in >> input;
    if (input == "Dim") {
        in >> input;
        Dim = stoi(input);
    }

    double C1 = 0, C2 = 0;

    // initialize
    while (in >> input) {
        if (input == "Num_b") {
            in >> input;
            Num_b = stoi(input);
        } else if (input == "C1") {
            in >> input;
            C1 = stod(input);
        } else if (input == "C2") {
            in >> input;
            C2 = stod(input);
        } else if (input == "Min_boundary") {
            for (int i = 0; i < Dim; i++) {
                in >> input;
                Min_boundary[i] = stoi(input);
            }
        } else if (input == "Max_boundary") {
            for (int i = 0; i < Dim; i++) {
                in >> input;
                Max_boundary[i] = stoi(input);
            }
        } else if (input == "Max_cycle") {
            in >> input;
            Max_cycle = stoi(input);
        }
    }
    double v_max[Dim], k = 0.5;
    for (int i = 0; i < Dim; i++) {
        v_max[i] = (Max_boundary[i] - Min_boundary[i]) * k / 2.0;
    }

    double **x;
    x = DynaArr2D(x, Dim, Num_b);
    double **v;
    v = DynaArr2D(v, Dim, Num_b);

    for (int i = 0; i < Num_b; i++) {  // initialize x
        for (int j = 0; j < Dim; j++) {
            x[i][j] = Min_boundary[j] + ((Max_boundary[j] - Min_boundary[j]) * i / (Num_b - 1));
        }
    }

    double **p;
    p = DynaArr2D(p, Dim, Num_b);
    for (int i = 0; i < Num_b; i++) {
        for (int j = 0; j < Dim; j++) {
            p[i][j] = x[i][j];
        }
    }

    double *g;
    g = new double[Dim];

    inData >> input;
    int key = stoi(input);
    int *x_o = new int[key];
    double *y_o = new double[key];

    for (int i = 0; i < key; i++) {
        inData >> input;
        x_o[i] = stoi(input);
        inData >> input;
        y_o[i] = stod(input);
    }

    double R1, R2;
    double w_cycle = 0;

    for (int i = 0; i < Dim; i++) {
        g[i] = x[0][i];
    }

    for (int i = 0; i < Num_b; i++) {
        if (loss(Dim, p[i], x_o, y_o, key) < loss(Dim, g, x_o, y_o, key)) {
            for (int j = 0; j < Dim; j++) {
                g[j] = p[i][j];
            }
        }
    }

    // cycle

    for (int i = 0; i < Max_cycle; i++) {
        w_cycle = 1.15 - (1.15 - 0.85) * i / Max_cycle;
        for (int j = 0; j < Num_b; j++) {
            for (int k = 0; k < Dim; k++) {
                inR1 >> input;
                R1 = stod(input);
                inR2 >> input;
                R2 = stod(input);

                // update v
                v[j][k] = v[j][k] * w_cycle + C1 * (p[j][k] - x[j][k]) * R1 + C2 * (g[k] - x[j][k]) * R2;
                if (v[j][k] > v_max[k])
                    v[j][k] = v_max[k];
                if (v[j][k] < -v_max[k])
                    v[j][k] = -v_max[k];

                // update x
                x[j][k] += v[j][k];

                if (x[j][k] > Max_boundary[k])
                    x[j][k] = Max_boundary[k];
                if (x[j][k] < Min_boundary[k])
                    x[j][k] = Min_boundary[k];
            }

            // update p
            if (loss(Dim, x[j], x_o, y_o, key) < loss(Dim, p[j], x_o, y_o, key)) {
                for (int l = 0; l < Dim; l++) {
                    p[j][l] = x[j][l];
                }
            }

            // update g
            if (loss(Dim, p[j], x_o, y_o, key) < loss(Dim, g, x_o, y_o, key)) {
                for (int l = 0; l < Dim; l++) {
                    g[l] = p[j][l];
                }
            }
        }
        inR1 >> input;
        inR2 >> input;
    }

    bool first = false;

    // print out
    for (int i = 0; i < Dim; i++) {
        cout << g[i] << endl;
    }

    return 0;
}
