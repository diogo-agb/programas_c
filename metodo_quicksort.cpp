/*
 * ============================================================================
 *
 *       Filename:  quicksort.cpp
 *
 *    Description:  Implementa��o do algoritmo Quicksort
 *
 *        Version:  1.0
 *        Created:  04/21/2018 07:16:12 PM
 *       Compiler:  gcc
 *
 *         Author:  Gustavo Pantuza (gustavopantuza@gmail.com)
 *   Organization:  Computer Science Community
 *
 * ============================================================================
 */


#include <iostream>
#include <vector>
#include <stdlib.h>


using std::vector;
using std::cout;
using std::endl;


class Quicksort {
 private:

    /**
     * Vetor de inteiros a ser ordenado
     */
    vector<int>& elements;

    /**
     * Tamanho do vetor
     */
    int size;

    /**
     * M�todo de particionamento que � o n�cleo do algoritmo Quicksort.
     * � a implementa��o utilizando o paradigma dividir para conquistar
     */
    int partition (const int start, const int end)
    {
        int i = start;

        for (int j = start; j < end; j++) {

            /*  Elemento atual menor ou igual ao piv�? */
            if (elements[j] <= elements[end]) {
                swap(i++, j);
            }
        }
        swap(i, end);

        return i;
    }

    /**
     * M�todo para fazer a troca de dados entre duas posi��es no vetor
     */
    void swap (const int i, const int j)
    {
        int k = elements[i];
        elements[i] = elements[j];
        elements[j] = k;
    }

    /**
     * M�todo privado que implementa o Quicksort recursivamente
     */
    void quicksort (const int start, const int end)
    {
        snapshot();

        if (start >= end) return;

        int pivot = partition(start, end);

        quicksort(start, pivot - 1);
        quicksort(pivot + 1, end);
    }

    /**
     * M�todo utilizado para debugging. Imprime na tela uma 'foto' do vetor
     */
    void snapshot ()
    {
        cout << "[";
        for(auto i = elements.begin(); i < elements.end() - 1; i++) {
            cout << *i << ", ";
        }
        cout << elements.back() << "]" << endl;
    }

 public:
    explicit Quicksort (vector<int>& elements)
    :elements(elements),
     size(elements.size())
    {
    }

    /**
     * M�todo publico que executa a ordena��o
     */
    void Sort ()
    {
        if(size <= 1) return;

        quicksort(0, size - 1);
        snapshot();
    }
};


int
main (int argc, char* argv[])
{
    vector<int> elements = {50, 42, 8, 23, 74, 91, 13, 26, 66, 3};

    Quicksort sort(elements);
    sort.Sort();

    return EXIT_SUCCESS;
}
