//author mohammad hossain janatiyan

#include<stdio.h>
#include<stdlib.h>
#include <values.h>

struct node {
    int key;
    struct node *left, *right;
};
int keys[] = {10, 12, 20};
int freq[] = {34, 8, 50};
int n = sizeof(keys) / sizeof(keys[0]);
int bestk[5][5];

struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void myorder(struct node *root) {
    if (root != NULL) {
        printf("((%d)", root->key);
        if (root->left == NULL)
            printf("(left)");
        if (root->right == NULL)
            printf("(right)");
        myorder(root->left);
        myorder(root->right);
        printf(")");
    }
}

struct node *insert(struct node *node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}


int sum(int freq[], int i, int j);

void init(int key[], int freq[], int n) {
//    bestk[n][n];
    int cost[n][n];
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            bestk[k][i] = 0;
            cost[k][i] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        cost[i][i] = freq[i];
        bestk[i][i] = i;
    }

    for (int L = 2; L <= n; L++) {
        for (int i = 0; i < n - L + 1; i++) {
            int j = i + L - 1;
            cost[i][j] = INT_MAX;

            for (int r = i; r <= j; r++) {
                int c = ((r > i) ? cost[i][r - 1] : 0) +
                        ((r < j) ? cost[r + 1][j] : 0) +
                        sum(freq, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                    bestk[i][j] = r;
                }
            }
        }
    }
}


int sum(int freq[], int i, int j) {

    int s = 0;
    for (int k = i; k <= j; ++k) {
        s += freq[k];
    }
    return s;
}


int main() {
    struct node *root = NULL;

    init(keys, freq, n);

    root = insert(root, bestk[0][n - 1]);
//    printf("(%d)",root->key);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            insert(root, bestk[i][j]);
        }
    }
    myorder(root);
    return 0;
    printf("hello world");
}