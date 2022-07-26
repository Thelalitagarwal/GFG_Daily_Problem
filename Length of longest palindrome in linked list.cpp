#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void append(struct Node** head_ref, struct Node **tail_ref,
            int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
        *head_ref = new_node;
    else
        (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

/* Function to get the middle of the linked list*/
int maxPalindrome(Node *);


/* Driver program to test above function*/
int main()
{
    int T,n,l;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for (int i=1; i<=n; i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }
      

       cout << maxPalindrome(head)<<endl;
    }
    return 0;
}



// } Driver Code Ends


/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
#include<bits/stdc++.h>

/* The Node is defined 
  /* Link list Node
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/

/*The function below returns an int denoting
the length of the longest palindrome list. */
int dp(vector<int> vec)
{
    int n = vec.size();
    bool table[n][n];
    memset(table, 0, sizeof(table));
    int maxLength = 1;
    
    for (int i = 0; i < n; ++i)
        table[i][i] = true;
    
    for (int i = 0; i < n - 1; ++i) {
        if (vec[i] == vec[i + 1]) {
            table[i][i + 1] = true;
            maxLength = 2;
        }
    }
    
    for (int k = 3; k <= n; ++k) {
        for (int i = 0; i < n - k + 1; ++i) {
            int j = i + k - 1;
            if (table[i + 1][j - 1] && vec[i] == vec[j]) {
                table[i][j] = true;
                maxLength = k;
            }
        }
    }
    return maxLength;
}

int maxPalindrome(Node *head)
{
    vector<int> vec;
    while(head!=NULL){
        vec.push_back(head->data);
        head=head->next;
    }
    return dp(vec);
}
