#include <cstdio>
#include <vector>
using namespace std;
// Lemma: All vertex can either reach a cycle or in a cycle themselves

// a is the linked list
// b is the component tag of undirected representation
int a[100100], i, j, b[100100], n;
// c checks if vertex has incoming edge
// u marks visited for dfs
// d marks component contains vertices with no incoming edge
bool c[100100], u[100100], d[100100];
vector <int> p, q;
//dfs. the vertex that end dfs is the root vertex and the whole component is named after it
void dfs(int i) {
    u[i] = true;
    if (!u[a[i]]) dfs(a[i]);
    b[i] = b[a[i]];
    if (b[i] == 0) b[i] = i;
}
int main() {
    scanf("%d", &n);
    // construct a (linked list) and mark vertices that has incoming edge
    for (i = 1; i <= n; i++) { 
        scanf("%d", &a[i]); c[a[i]] = true; 
    }
    for (i = 1; i <= n; i++) 
        if (!u[i]) 
            dfs(i);
    //for vertex without incoming edge, add it and root vertex of its component to vector and mark the whole component
    for (i = 1; i <= n; i++) 
        if (!c[i]) { 
            p.push_back(i); 
            q.push_back(b[i]); 
            d[b[i]] = true; 
        }
    j = p.size();
    // get root vertex of component that isn't in the same undirected component with a lone vertex
    // this also means there's no lone vertex that can reach root vertex
    //we'll call this strong root vertex
    for (i = 1; i <= n; i++) 
        if (b[i] == i && !d[i]) { 
            p.push_back(i); 
            q.push_back(b[i]); 
        }
    n = p.size();
    //if you have a strong root vertex and no lone vertex, there's no need to connect shit
    if (n == 1 && j == 0) 
        n = 0;
    printf("%d\n", n);
    // you need to connect strong root vertices and lone vertices with each other 
    // since lone vertex cannot reach strong root vertex (by definition of strong root vertex) and vice versa
    // and strong root vertex cannot reach each other
    // you do this by connecting strong root vertex with each other and root of lone vertex -> x -> lone vertex to create SCC
    // this allow root of lone vertex to reach lone vertex. lone vertex can already reach root of lone vertex
    // connecting 2 lone vertices will look like: root lone 1 -> lone 2, root lone 2 -> lone 1
    for (i = 0; i < n; i++) 
        printf("%d %d\n", q[i], p[(i + 1) % n]);
    return 0;
}