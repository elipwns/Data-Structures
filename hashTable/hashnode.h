#ifndef HASHNODE_H
#define HASHNODE_H

template<typename K, typename V>
class HashNode
{
	template<typename K, typename V>
	friend class HashTable;
public:
	HashNode(K key, V value);
	~HashNode();
	HashNode(const HashNode<K,V> &);
	HashNode<K,V> & operator=(const HashNode<K,V> &);

private:
	K m_key;
	V m_value;
};

template<typename K, typename V>
HashNode<K,V>::HashNode(K key, V value)
	:m_key(key), m_value(value)
{
}

template<typename K, typename V>
HashNode<K,V>::~HashNode()
{
}

template<typename K, typename V>
HashNode<K,V>::HashNode(const HashNode<K,V> & that)
{
	*this = that;
}

template<typename K, typename V>
HashNode<K,V> & HashNode<K,V>::operator=(const HashNode<K,V> & rhs)
{
	if(*this != rhs)
	{
	}
	return * this;
}

#endif