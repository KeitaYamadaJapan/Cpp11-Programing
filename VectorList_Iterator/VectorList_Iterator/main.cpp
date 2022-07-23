//
//  main.cpp
//  VectorList_Iterator
//
//  Created by 山田啓太 on 2022/07/21.
//

#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <iterator>
using namespace std;

list<int> &FindList( vector<list<int> > &l, int idx){
    vector<list<int> >::iterator it;
    it = l.begin();
    return *(it + idx - 1);
}

/**
 Third Input用
 for Third Input
 */
struct LC{
    int id;
    list<int> *L;
};
//////////////////////////

list<int> &FindList2(vector<LC> &l, int idx){
    list<int> r;
    for(vector<LC>::iterator it=l.begin(); it != l.end(); it++){
        if((*it).id == idx) return *it->L;
    }
    r.clear();
    return r;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    cout <<"First Input" << endl;
    int n;
    string comand;
    vector<list<int> > a;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> comand;
        if(comand.compare("new")==0){
            int id;
            cin >> id;
            a.push_back(list<int>());
        }else if(comand.compare("add")==0){
            int id, item;
            cin >> id >> item;
            list<int> &l = FindList(a, id);
            l.push_back(item);
            l.sort();
        }else if(comand.compare("merge")==0){
            int id1, id2;
            cin >> id1 >> id2;
            list<int> &l1 = FindList(a, id1);
            list<int> &l2 = FindList(a, id2);
            l1.merge(l2);
            l1.sort();
        }else if(comand.compare("unique")==0){
            int id;
            cin >> id;
            list<int> &l = FindList(a,id);
            l.unique();
        }else if(comand.compare("out")==0){
            int id;
            cin >> id;
            list<int> &l = FindList(a, id);
            if(l.size()==0){
                cout << "Enpty" << endl;
            }else{
                for(list<int>::iterator it=l.begin(); it != l.end(); it++){
                    cout << *it << " ";
                }
            }
        }
        cout << endl;
    }
    //return 0;

    map<int, list<int> > b;
    a.clear();
    cout << "Second Input" << endl;
    cin >> n;
    while(n > 0){
        cin >> comand;
        if(comand.compare("new")==0){
            int id;
            cin >> id;
            b[id] = list<int>();
        }else if(comand.compare("add")==0){
            int id, item;
            cin >> id >> item;
            b[id].push_back(item);
            b[id].sort();
        }else if(comand.compare("merge")==0){
            int id1, id2;
            cin >> id1 >> id2;
            b[id1].merge(b[id2]);
            b[id1].sort();
        }else if(comand.compare("unique")==0){
            int id;
            cin >> id;
            b[id].unique();
        }else if(comand.compare("out")==0){
            int id;
            cin >> id;
            for(auto i=b.begin(); i != b.end(); i++){
                if(i->first == id){
                    a.push_back(i->second);
                    break;
                }
            }
        }else if(comand.compare("end")==0){
            for(auto it=a.begin(); it != a.end(); it++){
                if((*it).size() == 0){
                    cout << "Empty" << endl;
                }else{
                    for(auto j = (*it).begin(); j != (*it).end(); j++){
                        cout << *j << " ";
                    }
                    cout << endl;
                }
            }
            n = 0;
        }
    }
    cout << "Third Input" << endl;
    
    vector<LC> v;
    a.clear();
    cin >> n;
    while(n > 0){
        cin >> comand;
        if(comand.compare("new")==0){
            int id;
            cin >> id;
            LC s;
            s.id = id;
            s.L = new list<int>();
            v.push_back(s);
        }else if(comand.compare("add")== 0){
            int id, item;
            cin >> id >> item;
            list<int> &l = FindList2(v,id);
            l.push_back(item);
            l.sort();
        }else if(comand.compare("merge")==0){
            int id1,id2;
            cin >> id1 >> id2;
            list<int> &l1 = FindList2(v, id1);
            list<int> &l2 = FindList2(v, id2);
            l1.merge(l2);
            l1.sort();
        }else if(comand.compare("unique")==0){
            int id;
            cin >> id;
            list<int> &l = FindList2(v, id);
            l.sort();
            l.unique();
        }else if(comand.compare("out")==0){
            int id;
            cin >> id;
            list<int> &l = FindList2(v, id);
            a.push_back(l);
        }else if(comand.compare("end")==0){
            for(vector<list<int> >::iterator it = a.begin(); it != a.end(); it++){
                if(it->size()==0){
                    cout << "Empty" << endl;
                }else{
                    for(list<int>:: iterator j = it->begin(); j != it->end(); j++){
                        cout << *j << " ";
                    }
                    cout << endl;
                }
            }
            n = 0;
        }
    }

    return 0;
}
