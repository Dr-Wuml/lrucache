#include "lrucache.h"

using namespace std;

int main(){
    LruCache *lru = new LruCache(2);
    lru->put(1,2);
    lru->put(2,1);
    //lru->print();
    cout<<lru->get(2)<<endl;
    lru->put(3,1);
    //lru->print();
    cout<<lru->get(1)<<endl;
    cout<<lru->get(3)<<endl;
    cout<<lru->get(2)<<endl;
    return 0;
}
