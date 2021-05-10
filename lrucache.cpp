//功能实现
#include "lrucache.h"

int LruCache::get(int k){
	auto it=mp.find(k);
    if(it!=mp.end()){
	    CacheNode *node = it->second;
	    remove(node);
            setHead(node);
            return node->val;
	} else {
	    return -1;
	}
}

 void LruCache::put(int k,int val){
 	auto it=mp.find(k);
	if( it != mp.end()){
    	    CacheNode *node = it->second;
            node->val = val;
            remove(node);
            setHead(node);
	} else {
	    CacheNode *newNode =new CacheNode(k,val);
            if(mp.size() >= size){
                auto ite = mp.find(tail->k);
                remove(tail);
                mp.erase(ite);
            }
            setHead(newNode);
            mp[k] = newNode;
        }//!!!end if...else
}

void LruCache::remove(CacheNode *node){
    if(node->pre != nullptr){
        node->pre->next=node->next;
    }else{
        head=node->next;
    }
    if(node->next != nullptr){
        node->next->pre = node->pre;
    } else {
        tail=node->pre;
    }
}

void LruCache::setHead(CacheNode *node){
        node->next = head;
        node->pre = nullptr;
        if(head != nullptr){
            head->pre = node;
        }
        head = node;
        if(tail == nullptr){
            tail = node;
        }
    }
