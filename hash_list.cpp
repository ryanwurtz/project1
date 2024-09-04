#include "hash_list.h"

hash_list::hash_list() {
    head = NULL;
    size = 0;
    iter_ptr = NULL;
}

/**-----------------------------------------------------------------------------------
 * START Part 1
 *------------------------------------------------------------------------------------*/

void hash_list::insert(int key, float value) {

    node *ptr = head;
    node *oldnode = NULL;
    while (ptr != NULL) {
        if (ptr->key == key) 
        {
            ptr->value = value;
            return;
        }
        oldnode = ptr;
        ptr = ptr->next;
    }   
    node *newnode = new node();
    size++;
    newnode->key = key;
    newnode->value = value;
    newnode->next = NULL;
    if(head == NULL)
        head = newnode;
    else
        oldnode->next = newnode;
    return;
}

std::optional<float> hash_list::get_value(int key) const { 
    node *ptr = head;
    while (ptr != NULL) {
        if (ptr->key == key){
            std::optional<float> val = ptr->value;
            return val;
        } 
        ptr = ptr->next;
    }
    return std::nullopt; }

bool hash_list::remove(int key) { 
    node *ptr = head;
    node *oldnode = NULL;
    while (ptr != NULL) {
        if (ptr->key == key){
            if(head != ptr)
                oldnode->next = ptr->next;
            else
                head = ptr->next;
            delete ptr;
            size--;
            return true;
        }
        oldnode = ptr;
        ptr = ptr->next;
    }
    return false; 
    }

size_t hash_list::get_size() const { 
    return size; }

hash_list::~hash_list() {
    node *ptr = head;
    node *old = NULL;
    while(ptr != NULL)
    {
        old = ptr;
        ptr = ptr->next;
        delete old;
    }    
}

/**-----------------------------------------------------------------------------------
 * END Part 1
 *------------------------------------------------------------------------------------*/


/**-----------------------------------------------------------------------------------
 * START Part 2
 *------------------------------------------------------------------------------------*/

hash_list::hash_list(const hash_list &other) {
    size = other.size;
    head = other.head;
    iter_ptr = other.iter_ptr;
    
}

hash_list &hash_list::operator=(const hash_list &other) { 
    
    delete((*this).head);
    delete((*this).iter_ptr);
    (*this).head = new node();
    (*this).iter_ptr = new node(); 
    (*this).size = other.size;
    (*this).head = other.head;
    (*this).iter_ptr = other.iter_ptr;
     
    
    return *this;
}

void hash_list::reset_iter() {
    if (size == 0) {
        iter_ptr = NULL;
    }
    else {
        iter_ptr = head;
    }
}


void hash_list::increment_iter() {
    if (iter_ptr == NULL) {
        return;
    }
    else if (iter_ptr->next == NULL) {
        iter_ptr = NULL;
    }
    else {
        iter_ptr = iter_ptr->next;
    }
}


std::optional<std::pair<const int *, float *>> hash_list::get_iter_value() { 
    if (iter_ptr == NULL) {
        return std::nullopt;
    }
    else {
        return std::optional<std::pair<const int *, float *>>({&iter_ptr->key, &iter_ptr->value});
    } 
}


bool hash_list::iter_at_end() { 
    if (iter_ptr == NULL) {
        return true;
    }
    else {
        return false;
    }
}
/**-----------------------------------------------------------------------------------
 * END Part 2
 *------------------------------------------------------------------------------------*/
