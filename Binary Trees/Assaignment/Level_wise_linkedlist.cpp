/**********************************************************

  Following are the Binary Tree Node class structure and
  the Node class structure

  template <typename T>
  class BinaryTreeNode {
      public:
      T data;
      BinaryTreeNode<T> *left;
      BinaryTreeNode<T> *right;

      BinaryTreeNode(T data) {
          this->data = data;
          left = NULL;
          right = NULL;
      }
  };

  template <typename T>
  class Node {
    public:
      T data;
      Node<T> *next;
      Node(T data) {
          this->data=data;
          this->next=NULL;
      }
  };

***********************************************************/

// MY FUCKING APPROACH ❤️✌️
vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
  // Write your code here
  if (root == NULL)
  {
    vector<Node<int> *> add;
    add.push_back(NULL);
    return add;
  }

  vector<Node<int> *> add;
  Node<int> *newNode = new Node<int>(root->data);
  Node<int> *head = newNode;
  add.push_back(head);

  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);

  while (!pendingNodes.empty())
  {

    Node<int> *head1 = NULL;
    Node<int> *tail = NULL;

    int len = pendingNodes.size();
    for (int i = 0; i < len; i++)
    {
      BinaryTreeNode<int> *front = pendingNodes.front();
      pendingNodes.pop();
      if (front->left != NULL)
      {
        Node<int> *newNode = new Node<int>(front->left->data);
        if (head1 == NULL)
        {
          head1 = newNode;
        }
        if (tail == NULL)
        {
          tail = newNode;
        }
        else
        {
          tail->next = newNode;
          tail = newNode;
        }
        pendingNodes.push(front->left);
      }

      if (front->right != NULL)
      {
        Node<int> *newNode = new Node<int>(front->right->data);
        if (head1 == NULL)
        {
          head1 = newNode;
        }
        if (tail == NULL)
        {
          tail = newNode;
        }
        else
        {
          tail->next = newNode;
          tail = newNode;
        }
        pendingNodes.push(front->right);
      }
    }
    add.push_back(head1);
  }
  return add;
}

// coding ninjas approach 🤪

/*
Time complexity: O(N)
Space complexity: O(H)

where N is the number of nodes in the input BST
and H is the height of the input BST
*/

vector<Node<int> *> constructLinkedListForEachLevel(BinaryTreeNode<int> *root)
{
  vector<Node<int> *> output;

  if (root == NULL)
  {
    return output;
  }

  queue<BinaryTreeNode<int> *> pendingNodes;
  pendingNodes.push(root);

  int currentLevelRemaining = 1;
  int nextLevelCount = 0;

  Node<int> *currentLevelHead = NULL;
  Node<int> *currentLevelTail = NULL;

  while (!pendingNodes.empty())
  {
    BinaryTreeNode<int> *first = pendingNodes.front();
    pendingNodes.pop();

    Node<int> *newNode = new Node<int>(first->data);

    if (currentLevelHead == NULL)
    {
      currentLevelHead = newNode;
      currentLevelTail = newNode;
    }
    else
    {
      currentLevelTail->next = newNode;
      currentLevelTail = newNode;
    }

    if (first->left != NULL)
    {
      pendingNodes.push(first->left);
      nextLevelCount++;
    }

    if (first->right != NULL)
    {
      pendingNodes.push(first->right);
      nextLevelCount++;
    }
    currentLevelRemaining--;

    if (currentLevelRemaining == 0)
    {
      output.push_back(currentLevelHead);
      currentLevelHead = NULL;
      currentLevelTail = NULL;
      currentLevelRemaining = nextLevelCount;
      nextLevelCount = 0;
    }
  }

  return output;
}
