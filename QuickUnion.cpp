/* Quick Union Algorithm */
// Cheeck two point has connected or not in very complexed graph
// It is very useful
// https://www.cs.princeton.edu/~rs/AlgsDS07/01UnionFind.pdf

#include <iostream>
using namespace std;

class QuickUnion
{
    int* id;
public:
    QuickUnion(int N) {
        id = new int[N];
        for (int i = 0; i < N; i++) id[i] = i;
    }
    int root(int i) {
        while (i != id[i]) {
            id[i] = id[id[i]]; //Keeps tree flat
            i = id[i];
        }
        return i;
    }
    void unite(int p, int q) {
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }

    bool find(int p, int q) {
        return root(p) == root(q);
    }
};

int main() {

    QuickUnion q(100);
    q.unite(2,3);
    q.unite(5,2);
    q.unite(3,1);
    q.unite(5,2);

    if( q.find(2,5) )
        cout << "Connected";

    return 1;
}