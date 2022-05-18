#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int Random() { return rand() << 15 | rand(); }

struct item {
    int prior, value, cnt;
    item *left, *right;
    item(int val = 0): value(val), prior(Random()), cnt(0), left(nullptr), right(nullptr) {}
};

int n, m;
item *tr;

int Count(item * p) { return p? p->cnt: 0; }

void Update(item * p) { if (p) p->cnt = Count(p->left) + Count(p->right) + 1; }

void Merge(item* &p, item *l, item *r)
{
    if (!l || !r) p = l? l: r;
    else if (l->prior > r->prior) Merge(l->right, l->right, r), p = l;
    else Merge(r->left, l, r->left), p = r;
    Update(p);
}

void Split(item *p, item* &l, item* &r, int key, int add = 0)
{
    if (!p) { l = r = nullptr; return; }
    int curkey = add + Count(p->left);
    if (key <= curkey) Split(p->left, l, p->left, key, add), r = p;
    else Split(p->right, p->right, r, key, curkey + 1), l = p;
    Update(p);
}

void Print(item *tr)
{
    if (tr) {
        Print(tr->left);
        printf("%d ", tr->value);
        Print(tr->right);
    }
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        int a; scanf("%d", &a);
        Merge(tr, tr, new item(a));
    }
    while (m--) {
        int typ, l, r; scanf("%d %d %d", &typ, &l, &r); l--, r--;
        item *p1, *p2; Split(tr, tr, p2, r + 1); Split(tr, p1, tr, l);
        if (typ == 1) { Merge(tr, tr, p1); Merge(tr, tr, p2); }
        else { Merge(tr, p2, tr); Merge(tr, p1, tr); }
    }
    if (n == 1) printf("0\n");
    else {
        item *p1, *p2; Split(tr, tr, p2, n - 1); Split(tr, p1, tr, 1);
        printf("%d\n", abs(p1->value - p2->value));
        Merge(tr, p1, tr); Merge(tr, tr, p2);
    }
    Print(tr);
    return 0;
}