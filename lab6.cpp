#include <iostream>
#include <fstream>

struct  ver
{
    int i, j;
    int mas;
    
};
int const N = 5;


bool superpoisk(int mas[][N], int dan, int need, int v[]) {
    bool q = false;

    for (int i = 0; i < N; i++) {
            if (mas[dan][i] != 0 && v[i]==0 ) {
                v[i] = 1;
                q = superpoisk(mas, i, need, v);
        }

    }

    if (v[need] == 0) {
        q = true;
    }
    if (v[need] == 1) {
        q = false;
    }


    return (q);

}




int main()
{
    int mas[N][N];
    int v[N];


    std::ifstream in("in.txt");
    if (in.is_open())
    {
        while (!in.eof()) {
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {

                    in >> mas[i][j];
                }
            }


        }


    }
    in.close();

    int cras[N][N];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            v[i] = 0;
            cras[i][j] = 0;
        }
    }
    ver pair[20];
    int w = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            bool q = false;
            if (mas[i][j] != 0) {
                for (int k = 0; k < w; k++) {
                    if (j == pair[k].i && i == pair[k].j && q == false) {
                        q = true;
                    }
                }
                if (q == false) {

                    pair[w].i = i;
                    pair[w].j = j;
                    pair[w].mas = mas[i][j];
                    w++;
                }


            }
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = i + 1; j < w; j++) {
            if (pair[i].mas > pair[j].mas) {
                ver tmp;
                tmp = pair[i];
                pair[i] = pair[j];
                pair[j] = tmp;
            }

        }
    }




    for (int i = 0; i < w; i++) {
        bool q = true;
        bool qq = true;

        for (int j = 0; j < N; j++) {
            if (cras[pair[i].i][j] != 0) {
                q = false;
            }

            if (cras[pair[i].j][j] != 0) {
                qq = false;
            }

        }

        if (q == true && qq == true) {
            cras[pair[i].i][pair[i].j] = pair[i].mas;
            cras[pair[i].j][pair[i].i] = pair[i].mas;
        }

        if (q == true && qq == false) {
            cras[pair[i].i][pair[i].j] = pair[i].mas;
            cras[pair[i].j][pair[i].i] = pair[i].mas;
        }

        if (q == false && qq == true) {
            cras[pair[i].i][pair[i].j] = pair[i].mas;
            cras[pair[i].j][pair[i].i] = pair[i].mas;
        }


        if (q == false && qq == false) {
            if (superpoisk(cras, pair[i].i, pair[i].j, v) == true) {
                cras[pair[i].i][pair[i].j] = pair[i].mas;
                cras[pair[i].j][pair[i].i] = pair[i].mas;
               
            }

            for (int j = 0; j < N; j++) {
                v[j] = 0;
            }


        }





    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << cras[i][j] << " ";

        }
        std::cout << std::endl;
    }

}
