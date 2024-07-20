// observation
// if going to left side simply +1
// if going to right side do nothing
vector<int> diagonal(Node *root)
{
    // your code here
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    };

    // make a queue
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();

        while (temp != NULL)
        {
            ans.push_back(temp->data);
            if (temp->left)
            {
                // badme handle krege
                q.push(temp->left);
            }
            temp = temp->right;
        }
    }
    return ans;
}