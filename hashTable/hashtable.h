#include <vector>
using std::vector;
#include <list>
using std::list;

#ifndef HASHTABLE_H
#define HASHTABLE_H

template<typename K, typename V>
class HashTable
{
public:
	HashTable(int buckets);
	~HashTable();
	HashTable(const HashTable<K,V> &);
	HashTable<K,V> & operator=(const HashTable<K,V> &);

	void Insert(K key, V value);
	void setHash(int (*hash)(K key));
	V operator [] (K key);
	void Delete(K key);
	void Traverse(void (*visit)(V value));

private:
	vector<list<HashNode<K,V>>> m_nodes;
	int (*hashfunc)(K key);
};

template<typename K, typename V>
HashTable<K,V>::HashTable(int buckets)
	:m_nodes(buckets)
{
	
}

template<typename K, typename V>
HashTable<K,V>::~HashTable()
{
}

template<typename K, typename V>
HashTable<K,V>::HashTable(const HashTable<K,V> & that)
{
	*this = that;
}

template<typename K, typename V>
HashTable<K,V> & HashTable<K,V>::operator=(const HashTable<K,V> & rhs)
{
	if(*this != rhs)
	{
		//do stuff
	}
	return * this;
}

template<typename K, typename V>
void HashTable<K,V>::Insert(K key, V value)
{
	int index = hashfunc(key);
	m_nodes[index].
}

template<typename K, typename V>
void HashTable<K,V>::setHash(int (*hash)(K key))
{
	hashfunc = hash;
}

template<typename K, typename V>
V HashTable<K,V>::operator [] (K key)
{
	
}

template<typename K, typename V>
void HashTable<K,V>::Delete(K key)
{
}

template<typename K, typename V>
void HashTable<K,V>::Traverse(void (*visit)(V value))
{
}

#endif