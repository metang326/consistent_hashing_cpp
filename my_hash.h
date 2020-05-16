#ifndef LEETCODE_MY_HASH_H
#define LEETCODE_MY_HASH_H

#include <string>
#include <map>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;


class virtual_node {
public:
    string ip;
    unsigned int hash_value;
    map<unsigned int, string> data;

    virtual_node();

    virtual_node(string ip, unsigned int hash_value);

    ~virtual_node();
};

class real_node {
public:
    string ip;
    unsigned int virtual_node_num;
    vector<unsigned int> virtual_node_hash_list;
    unsigned int cur_max_port;

    real_node();

    real_node(string ip);

    ~real_node();
};

class consistent_hash {
public:
    unsigned int real_node_sum;
    unsigned int virtual_node_sum;
    map<string, real_node> real_node_map;
    map<unsigned int, virtual_node> virtual_node_map;
    vector<unsigned int> sorted_node_hash_list;

    consistent_hash();

    ~consistent_hash();

    unsigned int find_nearest_node(unsigned int hash_value);

    unsigned int put(string data_id);

    void add_real_node(string ip, unsigned int virtual_node_num);

    void drop_real_node(string ip);

    void print_real_node(string ip);

    void print();
};

#endif //LEETCODE_MY_HASH_H
