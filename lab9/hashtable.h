#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <utility>
#include <vector>
#include <map>
#include <stdexcept>
#include <utility>
#include <iostream>

template <typename K, typename V>
class HashTable {
public:
	HashTable();
	~HashTable();
	void insert(K key, V value);
	V find(K key);
	void remove(K key);
	size_t size();
	bool empty();
	
private:
	std::vector< std::map<K,V> > table;
	void resize();
	size_t size_;
	size_t alpha;
	uint64_t hash(K key);
};

template <typename K, typename V>
HashTable<K,V>::HashTable() { table.resize(1); alpha = 1; size_ = 0;}

template <typename K, typename V>
HashTable<K,V>::~HashTable() {}

template <typename K, typename V>
uint64_t HashTable<K,V>::hash(K key)
{
	std::hash<K> hasher;
	return hasher(key);
}

template <typename K, typename V>
void HashTable<K,V>::insert(K key, V value)
{
	if((size_ + 1) / table.size() > alpha){
		resize(); 
	}
	size_t idx = hash(key) % table.size(); 
	table[idx][key] = value; 
	size_++; 
}

template <typename K, typename V>
V HashTable<K,V>::find(K key)
{
	size_t idx = hash(key) % table.size();
	if(table[idx].count(key) == 1){
		return table[idx][key]; 
	}
	else{
		throw std::range_error("Key not found.");
	}

}

template <typename K, typename V>
void HashTable<K,V>::remove(K key)
{
	size_t idx = hash(key) % table.size();
	if(table[idx].count(key) == 1){
		table[idx].erase(key); 
	}
	else{
		throw std::range_error("Key not found.");
	}
}

template <typename K, typename V>
size_t HashTable<K,V>::size()
{
	return size_; 
}

template <typename K, typename V>
bool HashTable<K,V>::empty()
{
	return size_ == 0; 
}

template <typename K, typename V>
void HashTable<K,V>::resize()
{
	std::cout << "resizing " << table.size() << " -> " << table.size()*2 << std::endl;
	std::vector< std::map<K, V> > newTable(table.size() * 2);
	for (size_t i = 0; i < table.size(); ++i) {
		for (auto it = table[i].begin(); it != table[i].end(); ++it) {
//get curr 
			K currK = it->first;
			V currV = it->second;
//calc 
			size_t newIdx = hash(currK) % newTable.size();

			// Insert the key-value pair into the new table
			newTable[newIdx][currK] = currV;
		}
}
}
#endif
