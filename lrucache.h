#include<iostream>
#include<map>

using namespace std;

//节点结构
struct CacheNode{
    int k;                           //缓存块编号
    int val;                         //存储内容
    CacheNode *pre,*next;			//当前缓存前后邻居位置
    CacheNode(int k,int v)
    :k(k),val(v),pre(nullptr),next(nullptr){}
};

class LruCache{
public:
	int get(int k);                  //查找缓存函数
	void put(int k,int val);         //加载新数据进缓存函数
	void setHead(CacheNode *node);  //设置头结点函数
	void remove(CacheNode *node);    //删除节点函数
private:
	int size;                     //缓存区大小
	CacheNode *head,*tail;		  //头尾指针
	map<int , CacheNode*>mp;      //利用mp做查找
public:
	LruCache(int capacity){
        size = capacity;
        head = nullptr;
        tail = nullptr;
        }
	/*void print(){
	    for(auto &p : mp){
		cout<<p.first<<" "<<"k="<<p.second->k<<"val="<<p.second->val<<endl;	
	    }
	}*/
};

