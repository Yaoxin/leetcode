#include "common/help.h"

// 采用双向链表实现
// 测试了一下，在leetcode上会超时
//网络上常规解法是hashtable + 双向链表
//由于我的sublime 路径没有配置boost和C++ 11标准库，暂时不实现了
//不过具体原理非常清楚
class LRUCache{
public:
    typedef struct _cache_elem {
        int key;
        int value;
        struct _cache_elem * prev;
        struct _cache_elem * next;
    } Node; 
private:
    Node * head;
    Node * tail;
    int m_capacity;
    int m_cur_num; 
public:
    LRUCache(int capacity) {
        head = NULL;
        tail = NULL;
        m_capacity = capacity;
        m_cur_num = 0;
    }
    
    int get(int key) {
        Node * node = get_node(key);
        if(node)
        {
            return node->value;
        } 
        else 
        {
            return -1;

        }
    }
    
    void set(int key, int value) {
        Node * node = get_node(key);
        if(!node) {
            if(m_cur_num == m_capacity) {
                tail->key = key;
                tail->value = value;
                move_to_front(tail);
                return;
            }
            Node * node = new Node;
            node->key = key;
            node->value = value;
            node->prev = NULL;
            node->next = head;
            if(head) {
                head->prev = node;
            }
            head = node;
            if(!tail){
                tail = head;
            }
            m_cur_num++;
        } else {
            node->value = value;
        }

    }
private:
    void move_to_front(Node * node) 
    {
        if(node != head)
        {
            Node * temp = node->prev;
            if(node->next){
                node->next->prev = temp;
            } else {
                tail = temp;
            }
            temp->next = node->next;
            node->prev = NULL;
            node->next = head;
            head->prev = node;
            head = node;
        }
    }

    Node * get_node(int key)
    {
        Node * node = head;
        while(node) {
            if(node->key == key) {
                move_to_front(node);
                return node;
            }
            node = node->next;
        }
        return NULL;
    }
};

int main(int argc, char const *argv[])
{
    LRUCache cache(10000);
    // cache.set(3, 33);
    // cout << cache.get(3) << endl;
    // cout << cache.get(2) << endl;
    BEGIN_PROFILE
    for (int i = 0; i < 10000; ++i)
    {
        cache.set(i, i * 2);
    }
    END_PROFILE

    // cache.cache_print();
    // cache.set(3, 15);
    // cout << "hel     "<< endl;
    // cache.cache_print();
    // cache.get(5);
    // cout << "   "<< endl;
    // cache.cache_print();

    // cache.cache_print();
    // cout << "   "<< endl;
    // for (int i = 0; i < 9; ++i)
    // {
        // cache.get(i);
        // cout << cache.get(i) << endl;
    // }
    // cout << "    "<< endl;
    // cache.get(9);
    // cache.cache_print();
    BEGIN_PROFILE
    cache.get(3567);
    END_PROFILE
    return 0;
}