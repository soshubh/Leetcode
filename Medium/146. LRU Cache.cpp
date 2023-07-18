// https://leetcode.com/problems/lru-cache

class LRUCache
{
public:
    class node
    {
    public:
        int key, value;
        node *next, *prev;
        node(int _key, int _value)
        {
            key = _key;
            value = _value;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    unordered_map<int, node *> d;
    int cap;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {

        if (d.find(key) != d.end())
        {
            node *temp = d[key];
            int val = temp->value;

            deleteNode(temp);
            addNode(temp);

            d.erase(key);
            d[key] = head->next;
            return val;
        }
        return -1;
    }

    void put(int key, int value)
    {

        if (d.find(key) != d.end())
        {
            node *temp = d[key];
            deleteNode(temp);
            addNode(new node(key, value));

            d.erase(key);
            d[key] = head->next;
        }

        else if (cap == d.size())
        {
            d.erase(tail->prev->key);
            deleteNode(tail->prev);
            addNode(new node(key, value));
            d[key] = head->next;
        }

        else
        {
            addNode(new node(key, value));
            d[key] = head->next;
        }
    }

    void deleteNode(node *Node)
    {
        auto delPrev = Node->prev;
        auto delNext = Node->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void addNode(node *Node)
    {
        auto temp = head->next;
        Node->next = temp;
        Node->prev = head;
        head->next = Node;
        temp->prev = Node;
    }
};
