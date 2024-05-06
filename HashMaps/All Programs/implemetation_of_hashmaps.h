#include<math.h>
using namespace std;

template<typename V>
class mapNode{
    public:
        string key;
        V value;
        mapNode<V>* next;
        mapNode(){}
        mapNode(string key,V value){
            this->key=key;
            this->value=value;
            next=NULL;
        }

        ~mapNode(){
            delete next;
        }
};

template<typename V>
class unorder_map{
    mapNode<V>** buckets;
    int bucket_size;
    int count;

    int getBucketIndex(string key){
        int hashcode=0;
        int n=key.size();
        int p=37,j=0;
        for(int i=n;i;i--){ 
            int s=pow(p,i-1);
            s=s % bucket_size;
            hashcode+=int(key[j])*(s);
            hashcode=hashcode % bucket_size;
            j++;
        }
        return hashcode % bucket_size;
    }

    void rehash(){
        mapNode<int>** old_Bucket=buckets;
        buckets=new mapNode<int>*[2*bucket_size];
        for(int i=0;i<2*bucket_size;i++){
            buckets[i]=NULL;
        }
        int old_Bucket_size=bucket_size;
        bucket_size*=2;
        count=0;
        for(int i=0;i<old_Bucket_size;i++){
            mapNode<int>* head=old_Bucket[i];
            while(head!=NULL){
                string key=head->key;
                V value=head->value;
                insert(key,value);
                head=head->next;
            }
        }
        
        for(int i=0;i<old_Bucket_size;i++){
            mapNode<int>* head=old_Bucket[i];
            delete head;
        }
        delete [] old_Bucket;
    }

    public:
        unorder_map(){
            bucket_size=5;
            buckets=new mapNode<V>*[bucket_size];
            count=0;
            for(int i=0;i<bucket_size;i++){
                buckets[i]=NULL;
            }
        }

        ~unorder_map(){
            for(int i=0;i<bucket_size;i++){
                delete buckets[i];
            }
            delete [] buckets;
        }

        int size(){
            return count;
        }

        bool isEmpty(){
            return size()==0;
        }

        V getValue(string key){
            int bucketIndex=getBucketIndex(key);
            mapNode<int>* head=buckets[bucketIndex];
            mapNode<int>* temp=head;
            while(temp!=NULL){
                if(temp->key==key){
                    return temp->value;
                }
                temp=temp->next;
            }
            return 0;
        }
        double loadFactor(){
            return (1.0*count/bucket_size);
        }
        void insert(string key,V value){
            if(loadFactor()>0.7){
                rehash();
            }
            int bucketIndex=getBucketIndex(key);
            mapNode<int>* head=buckets[bucketIndex];
            mapNode<int>* temp=head;
            while(temp!=NULL){
                if(temp->key==key){
                    temp->value=value;
                    return;
                }
                temp=temp->next;
            }
            mapNode<int>* newNode=new mapNode<int>(key,value);
            newNode->next=head;
            buckets[bucketIndex]=newNode;
            count++;
        }

        V remove(string key){
            int bucketIndex=getBucketIndex(key);
            mapNode<int>* head=buckets[bucketIndex];
            mapNode<int>* temp=head;
            mapNode<int>* prev=NULL;
            if(head!=NULL && head->key==key){
                V d=head->value;
                buckets[bucketIndex]=head->next;
                head->next=NULL;
                count--;
                delete head;
                delete temp;
                return d;
            }
            while(temp!=NULL){
                if(temp->key==key){
                    V d=temp->value;
                    prev->next=temp->next;
                    temp->next=NULL;
                    count--;
                    delete head;
                    delete temp;
                    delete prev;
                    return d;
                }
                prev=temp;
                temp=temp->next;
            }
            return 0;
        }
};

// int main(){
//     unorder_map<int> unormap;
//     unormap.insert("abc",1);
//     unormap.insert("def",2);
//     unormap.insert("hij",3);
//     unormap.insert("klm",4);

//     cout<<unormap.size()<<endl;
//     cout<<unormap.getValue("def")<<endl;
//     cout<<unormap.remove("def")<<endl;
//     cout<<unormap.getValue("def")<<endl;
//     cout<<unormap.size()<<endl;
//     // cout<<unormap.buckets[3]->next->key;
//     return 0;
// }